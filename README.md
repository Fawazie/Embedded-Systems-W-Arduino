# Embedded Systems Project With Arduino
In this project, I developed an Arduino-based motor control system that uses CAN bus communication and Serial communication to enable real-time control and monitoring of motor operations. The system reads speed and direction data from the GUI. It transmits the controls with serial communication to adjust the motor's behavior and display vital information such as RPM and voltage. The system can then use CAN bus communication to transmit the motor controls to another Arduino motor system, allowing simultaneous control and creating an integrated ecosystem for efficient motor management.
![Capture](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/e3c2440a-fe1d-4655-a8d2-b6908e6f83f4)

![IMG_1423](https://github.com/Fawazie/Embedded-Systems-W-Arduino/assets/78445573/f1e8d3f3-aa83-4472-8df7-345adb01170e)


## How It's Made:

**Tech used:** C, Processing, CANSniff, CANape

The project involves developing an embedded system to control and monitor a motor using Serial Communication then through the use of CAN bus Communication is able to relay the motor controls to another identical motor system. The system reads speed and direction data from the GUI(Graphic User Interface) and adjusts the motor's operation accordingly. The code utilizes the MCP_CAN library to interface with the CAN bus, processing incoming messages to control the second motor's speed and direction. Additionally, the system includes functionality to monitor motor parameters such as RPM and voltage, and it can send this data back over the CAN bus for real-time monitoring and control.

## Optimizations
*(optional)*

You don't have to include this section but interviewers *love* that you can not only deliver a final product that looks great but also functions efficiently. Did you write something then refactor it later and the result was 5x faster than the original implementation? Did you cache your assets? Things that you write in this section are **GREAT** to bring up in interviews and you can use this section as reference when studying for technical interviews!

## Lessons Learned:

No matter what your experience level, being an engineer means continuously learning. Every time you build something you always have those *whoa this is awesome* or *wow I actually did it!* moments. This is where you should share those moments! Recruiters and interviewers love to see that you're self-aware and passionate about growing.

## Examples:
Take a look at these couple examples that I have in my own portfolio:

**Palettable:** https://github.com/alecortega/palettable

**Twitter Battle:** https://github.com/alecortega/twitter-battle

**Patch Panel:** https://github.com/alecortega/patch-panel



