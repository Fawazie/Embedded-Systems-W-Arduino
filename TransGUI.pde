import controlP5.*; 
import processing.serial.*;
//Importing controlP5 Libary & Processing Serial Library
Serial port;
ControlP5 cp5; 
//Creating Serial port & CP5 objects
float volt = 0; // Voltage 
int rpm = 0; // RPM 
int UIV = 1000; // Update Interval 
int LUT = 0; //Last Update Time
boolean override = false; //Override State
int overrideSpeed = 180; // Overide Button Speed
void setup(){ 
  size(600, 500);    //Size of GUI Window 
  port = new Serial(this, "COM3", 115200); // Defining Serial Port & baudrate 
  cp5 = new ControlP5(this); // Initilizing CP%
  cp5.addSlider("% PWR")
  .setPosition(150, 100)
  .setSize(300, 30)
  .setRange(0,255)
  .setColorBackground(color(253,225,0))
  .setColorForeground(color(71,152,41))
  .setColorActive(color(71,152,41))
  ;  
//Adding Slider for Throttle Control
   cp5.addToggle("Reverse/Forward")     
    .setPosition(80, 350)  
    .setSize(150, 100)      
    .setValue(false)
    .setMode(ControlP5.SWITCH)
    .setColorBackground(color(253,225,0))
    .setColorActive(color(71,152,41))
    .setColorLabel(color(253,225,0))
    ;  
//Adding Toggle Button for Reverse/Forward
  cp5.addToggle("Override")
  .setPosition(80,220)
  .setSize(150,100)
  .setValue(false)
  .setColorBackground(color(253,255,0))
  .setColorActive(color(71,152,41))
  .setColorLabel(color(253,255,0))
  ; 
//Adding a Toggle Button for Override Button
}

void draw(){  
  background(32, 114 , 13);//Setting Background Color
  textSize(40);
  fill(253, 225, 0);               
  text("Module Control", 165, 40);
//Adding Module Control Text
  int PWR  = (int) cp5.getController("% PWR").getValue(); // Retriving Slider Value
  boolean TGL = cp5.getController("Reverse/Forward").getValue() == 1.0; // Retriving Direction State
  boolean override = cp5.getController("Override").getValue() == 1.0; // Retriving Override State
  if(override){
   PWR = overrideSpeed;
  }
// if override state is active PWR value is set override peed
  String message = PWR + "," + (TGL ? 1:0)+"\n"; // Creating message to send
  port.write(message);  //Message is written to serial port
  
   if (millis() - LUT  > UIV){ 
   while (port.available() > 0){   
  String received = port.readStringUntil('\n');
//Incoming data will be read as long as available port data is > 0
     if (received != null && received.length() > 0){
      try{
       String[] parts = received.trim().split(",");
//Uses "," to split recieved data into half
       if(parts.length == 2){
         volt = Float.parseFloat(parts[0]);
         rpm = Integer.parseInt(parts[1]);
//Recieves voltage and rpm values and assigns them to respective variables after being parsed
       }
       } 
       catch (NumberFormatException e){
         println("Error Reciving Voltage "+ e.getMessage());
//Handles Parse Error and prevents crashing due to refresh rate of rpm & voltage data  
       }
     }
    }
    LUT = millis();
//Updates last update time
  }
  textSize(20);
  text("RPM: " + rpm, 400, 330);
  text("Voltage: " + volt + "V", 400, 370); 
//Displays Voltage & RPM values 
}


/*
The coding architecture allows for real time control and monitoring of the module through a user-friendly GUI
*/
