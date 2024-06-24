//___CANBUS___
#include <SPI.h>
#include "mcp_can.h"
//Importing CAN libaries
#define CAN_INT_PIN 3 //defining CAN interrupt pin
MCP_CAN CAN(10); //Setting up CAN chip
int TGL; // Toggle
int Speed = 0; //Speed
int FWD = 5; //Power Forward pin
int REV = 6; // Power Reverse pin
volatile unsigned char control[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; // Defines CAN message
volatile unsigned char control_buf[8]; // buffer array for incoming message
volatile unsigned char len = 0;// lenght of incoming message

void setup() {
  Serial.begin(115200); //Starts Serial port at set baudrate
  pinMode(FWD,OUTPUT); //Sets Forward pin as output
  pinMode(REV,OUTPUT); // Reverse pin as output
  while(CAN_OK != CAN.begin(CAN_250KBPS, MCP_16MHz))
  {
  Serial.println("CAN Failed");
  delay(100);
  }
  Serial.println("CAN Ready!");
  //Initilizes CAN Module at set baudrate and sends Failed or Ready message to confirm status
}

void loop() {
if(CAN_MSGAVAIL == CAN.checkReceive()) // checks for available CAN messages
{CAN.readMsgBuf(&len,control_buf); // reads the CAN message
unsigned long canID = CAN.getCanId(); // Recives the CAN ID of the message
if(canID == 0x18FeFF03){ // checks to see if can ID matches the expected ID
  memcpy(control,control_buf,sizeof(control_buf)); //copies the message into the control array
  Speed = control[0]; // assigns and extract speed from the message
  TGL = control[1]; // assigns and extract Toggle from the message
  if (TGL == 0){
    analogWrite(FWD,Speed);
    analogWrite(REV,0);
  }
  else if (TGL == 1){
    analogWrite(REV,Speed);
    analogWrite(FWD,0);
  }
//Depending on Toggle State stops power to one direction and applies power to the other
} 
}
}
// The code structure allows real time motor  communitcation via CAN bus communication where speed and direction are received over the CAN network 
