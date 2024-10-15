#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H

#include <Arduino.h>
#include <SCServo.h>

class ServoControl
{
public:
    // Constructor to initialize the servo with ID and initial parameters
    ServoControl(int id, float max_angle, int speed, int torque);

    // Method to initialize communication with the servo
    void init();

    // Method to rotate the servo to its next position
    void rotate();

    // Method to reset the servo to 0 position
    void reset();

private:
    int servo_id;          // Servo ID
    float max_angle;       // Maximum angle the servo can rotate
    float current_angle;   // Current angle of the servo
    int speed;             // Speed of rotation
    int torque;            // Torque or power setting for servo
    bool returning;        // Flag to indicate if the servo is returning to 0
    SMS_STS st;            // Servo control object

    // Conversion factor for degrees to servo position
    float angleToPosition(float angle);
};

#endif
