//___CANBUS___
#include <SPI.h>
#include "mcp_can.h"
//Importing CAN libaries
MCP_CAN CAN(10); //Setting up CAN chip
//___Speed__
int16_t Speed; //Speed
//___Toggle/Direction___
int TGL; // Toggle
int FWD = 5; //  Pin Power Forward
int REV = 6; // Pin Power Reverse
//___Voltage____
const int VTG = A3; //Analog pin for Voltage
float volt ; // Voltage
//_______RPM______
#define ENCODER_PPR 224.4 // Defining Encoder PPR value
const int EN_A = 2; // Encoder A pin
int interval =1000; // Interval for Encoder
volatile long encoderValue = 0; // Inital Encoder Value
long previousMillis = 0; // Previous time passed
long currentMillis = 0; // Current Time
int rpm = 0; // RPM

void setup() {
  Serial.begin(115200); //Starts Serial port at set baudrate
  pinMode(VTG,INPUT); //Sets Voltage pin as input
  pinMode(FWD,OUTPUT); //Sets Forward pin as output
  pinMode(REV,OUTPUT); //Sets // Reverse pin as output
  attachInterrupt(digitalPinToInterrupt(EN_A),updateEncoder,RISING); //Attaches interrupt for encoder
  previousMillis = millis(); //sets previous timestamp
  while(CAN_OK != CAN.begin(CAN_250KBPS, MCP_16MHz))
  {Serial.println("CAN Failed");
  delay(100);}
  Serial.println("CAN Ready!");
  //Initilizes CAN Module at set baudrate and sends Failed or Ready message to confirm status  
}

void loop() {
 SRL(); //Calls SRL function to read Serial input
 Toggle(); // Calls TGL function to update motor direction
 Voltage(); //Calls Voltage function to read voltage
 rpmFinal();//Calls rpmFinal function to calculate RPM
 CANBUS(); //Calls CANBUS function to send data over CANBUS
 String message = String(volt) + "," + String(rpm) + "\n"; //Creates message 
 Serial.println(message); //Prints message out to Serial
}
void CANBUS(){
 unsigned char CAN_Message[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};// Defines CAN message
  int DataToSend = Speed ; // Speed data
  int DataToSend2 = TGL; // Toggle state
  int DataToSend3 = rpm; // RPM data
  float DataToSend4 = volt; //Voltage Data
  CAN_Message[0] = char(DataToSend); // Stores Speed data in CAN message
  CAN_Message[1] = char(DataToSend2); // Stores Toggle data in CAN message
  CAN_Message[2] = char(DataToSend3); //Stores RPM data in CAN message
  CAN_Message[3] = char((DataToSend4));//Stores Voltage data in CAN message
  CAN.sendMsgBuf(0x18FEFF03, 1, 8, CAN_Message); //Sends CAN message
}
int rpmFinal (){
   currentMillis = millis(); //Gets current time
   if(currentMillis - previousMillis > interval)// Checks if interval has passed
{
    previousMillis = currentMillis;//updates previous time
    rpm = float(encoderValue * 60/ ENCODER_PPR); // Calculates RPM
    encoderValue = 0;//Resets encoder
    }
}
float Voltage(){
  float AIV = analogRead(VTG); //Reads analog Voltage
  volt = AIV / 100.0; // Converts to Voltage
}
void updateEncoder()
{ encoderValue++;}
//Updates Encoder value when called
void Toggle(){
  if (TGL == 0){
    analogWrite(FWD,Speed);
    analogWrite(REV,0);}
  else if (TGL == 1){
    analogWrite(REV,Speed);
    analogWrite(FWD,0);}
}
//Depending on Toggle State stops power to one direction and applies power to the other
int SRL(){
 if(Serial.available()){
  String val = Serial.readStringUntil('\n'); // Reads Serial input
  int CMAIDX = val.indexOf(','); // Finds seperator
  if(CMAIDX > 0){
    Speed = val.substring(0,CMAIDX).toInt(); //Extracts speed value & assigns it to respective variable
    TGL = val.substring(CMAIDX + 1).toInt();} //Extracts TGL state and assigns it to repective variable
 }}

 // The code structure allows for read time control and monitoring using Serial communication, CANBUS and sensor inputs.
