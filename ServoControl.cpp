#include "ServoControl.h"

// Constructor to initialize servo with ID, max angle, speed, and torque
ServoControl::ServoControl(int id, float max_angle, int speed, int torque)
    : servo_id(id), max_angle(max_angle), current_angle(0), speed(speed), torque(torque), returning(false)
{
}

void ServoControl::init()
{
    // Assign Serial2 for communication (using Serial2 directly like your original code)
    st.pSerial = &Serial2;

    // Move servo to its initial position (0 degrees)
    st.WritePosEx(servo_id, 0, speed, torque);
    delay(1000); // Give some time for the servo to move
}

void ServoControl::rotate()
{
    float max_servo_pos = angleToPosition(max_angle);

    if (!returning && current_angle <= max_angle)
    {
        // Rotate to the next angle
        st.WritePosEx(servo_id, angleToPosition(current_angle), speed, torque);
        current_angle += 1; // Increment the angle
    }
    else if (!returning)
    {
        // Once max angle is reached, start returning
        returning = true;
    }
    else
    {
        // Returning to 0 position
        reset();
    }
}

void ServoControl::reset()
{
    st.WritePosEx(servo_id, 0, speed, torque);
    returning = false;
    current_angle = 0;
}

float ServoControl::angleToPosition(float angle)
{
    return (4096.0 / 360.0) * angle; // Convert angle to servo position
}
