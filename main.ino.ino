#include <Arduino.h>
#include "ServoControl.h"

// Pins for communication
#define RX 16
#define TX 17

// Initialize servo objects with different angles, speeds, and torque
ServoControl servo1(1, 360, 300, 800);  // Servo 1: 360 degrees, speed 300, torque 800
ServoControl servo2(2, 180, 5000, 1000); // Servo 2: 180 degrees, speed 5000, torque 1000
ServoControl servo3(3, 90, 2000, 500);  // Servo 3: 90 degrees, speed 2000, torque 500
ServoControl servo4(4, 270, 1500, 700); // Servo 4: 270 degrees, speed 1500, torque 700
ServoControl servo5(5, 60, 5000, 1000); // Servo 4: 60 degrees, speed 1500, torque 700
ServoControl servo6(6, 100, 5000, 1000); // Servo 4: 100 degrees, speed 1500, torque 700

void setup()
{
  Serial.begin(9600);
  
    // Initialize Serial2 for servo communication
  Serial2.begin(1000000, SERIAL_8N1, RX, TX); // UART with baud rate of 1M

  // Initialize all servos
  servo1.init();
  servo2.init();
  servo3.init();
  servo4.init();
  servo5.init();
  servo6.init();


}

void loop()
{
  // Rotate all servos independently
  servo1.rotate();
  servo2.rotate();
  servo3.rotate();
  servo4.rotate();
  servo5.rotate();
  servo6.rotate();

  delay(10); // Small delay between updates
}
