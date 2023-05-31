#include <M5Core2.h>
#include <Wire.h>
#include <VL53L0X.h>
VL53L0X sensor;

void setup(){
  Serial.begin(115200);
  Wire.begin();
  sensor.setAddress(0x29);
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }
  sensor.startContinuous();
}

void loop(){
  Serial.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }
  Serial.println();
}
