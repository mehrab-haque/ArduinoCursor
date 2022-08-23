#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);

long timer = 0;
int n =0;
float x, y, z;
void setup() {
  Serial.begin(38400);
  Wire.begin();
  
  byte status = mpu.begin();
  //Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ 
    Serial.println("NOT FOUND");
    status = mpu.begin();
    } // stop everything if could not connect to MPU6050
  
  //Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(true,true); // gyro and accelero
  //Serial.println("Done!\n");
}

void loop() {
  mpu.update();
    
  x=mpu.getAccX();
  delay(10);  
  y=mpu.getAccY();
  delay(10);
  z=mpu.getAccZ();
  delay(10);
  
  Serial.print(F("ACCELERO  X: "));Serial.print(x);
  Serial.print("\tY: ");Serial.print(y);
  Serial.print("\tZ: ");Serial.println(z);
  

  
}
