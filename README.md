# Embedded Systems Project With Arduino
In this project, I developed an Arduino-based motor control system that uses CAN bus communication and Serial communication to enable real-time control and monitoring of motor operations. The system reads speed and direction data from the GUI. It transmits the controls with serial communication to adjust the motor's behavior and display vital information such as RPM and voltage. The system can then use CAN bus communication to transmit the motor controls to another Arduino motor system, allowing simultaneous control and creating an integrated ecosystem for efficient motor management.


## Images:

![Capture](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/e3c2440a-fe1d-4655-a8d2-b6908e6f83f4)

![IMG_1423](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/f1e8d3f3-aa83-4472-8df7-345adb01170e)


## How It's Made:

**Tech used:** C, Processing, CANSniff, CANape

The project involves developing an embedded system to control and monitor a motor using Serial Communication. Then, through the use of CAN bus, Communication is able to relay the motor controls to another identical motor system. The system reads speed and direction data from the GUI(Graphic User Interface) and adjusts the motor's operation accordingly. The code utilizes the MCP_CAN library to interface with the CAN bus, processing incoming messages to control the second motor's speed and direction. Additionally, the system includes functionality to monitor motor parameters such as RPM and voltage, and it can send this data back over the CAN bus for real-time monitoring and control.

## Optimizations


To optimize the system, various enhancements were made, particularly involving how the CAN and Serial Messages were packaged and parsed. One improvement was reducing the size of the CAN message, which allowed for minimizing the bus load and improved communication speed. Another improvement was the parsing of the Serial messages coming from the GUI. Creating a parsing method that deconstructed the incoming byte of the message into multiple bits allowed for an overall reduction in latency and allowed the Arduino to process the incoming message much faster. 


## Additional Images:

![Canape](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/24fa2525-c824-4ffc-81bb-3674c50b900e)

![Cansniff 1](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/8788176e-f375-4f55-a31c-281402476f59)

![IMG_1393](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/16676e60-12ed-4d29-8429-580d0e36148e)

![IMG_1404](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/c0051d6f-00fa-4e6e-85ea-9d886f558cef)

![IMG_1397](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/287a97f9-e455-4c08-8eff-567854a6ff6f)
