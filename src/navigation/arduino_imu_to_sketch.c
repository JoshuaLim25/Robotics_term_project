// Building an IMU broadcaster requires
// adding code to several sections of the Arduino sketch
//
// Add this to the # include section
#include <Adafruit_LSM6DS3TRC.h>

// Add this to the global definitions section
// For reference, the encoder variables and objects is already there 
// define imu variables and objects
uint8_t imu_id;
sensors_event_t accel;
sensors_event_t gyro;
sensors_event_t temperature;
Adafruit_LSM6DS3TRC imu_sensor;

// Add this to the callback section
void imu_timer_cb(rcl_timer_t * timer, int64_t last_call_time) {
  imu_sensor.getEvent(&accel, &gyro, &temperature);
  micro_ros.imu_msg[imu_id].angular_velocity.x = gyro.gyro.x;
  micro_ros.imu_msg[imu_id].angular_velocity.y = gyro.gyro.y;
  micro_ros.imu_msg[imu_id].angular_velocity.z = gyro.gyro.z;
  micro_ros.imu_msg[imu_id].linear_acceleration.x = accel.acceleration.x;
  micro_ros.imu_msg[imu_id].linear_acceleration.y = accel.acceleration.y;
  micro_ros.imu_msg[imu_id].linear_acceleration.z = accel.acceleration.z;
  micro_ros.publishImu(imu_id);
}

// Add this to the setup section
  
  // set up IMU
  imu_id = micro_ros.beginBroadcaster(MicroROSArduino::IMU, "imu", 20.0, &imu_timer_cb);
  rosidl_runtime_c__String__assignn(&micro_ros.imu_msg[imu_id].header.frame_id, "imu", 3);
  micro_ros.imu_msg[imu_id].angular_velocity_covariance[0] = 0.00005;
  micro_ros.imu_msg[imu_id].angular_velocity_covariance[4] = 0.00005;
  micro_ros.imu_msg[imu_id].angular_velocity_covariance[8] = 0.00005;
  micro_ros.imu_msg[imu_id].linear_acceleration_covariance[0] = 0.002;
  micro_ros.imu_msg[imu_id].linear_acceleration_covariance[4] = 0.002;
  micro_ros.imu_msg[imu_id].linear_acceleration_covariance[8] = 0.002;
  imu_sensor.begin_I2C();

