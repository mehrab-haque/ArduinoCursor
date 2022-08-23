#include <MPU6050_light.h>
MPU6050 mpu(Wire);

long timer = 0;
int n =0;
float x, y, z;

void setup() {
    Serial.begin(9600); 
    Wire.begin();
    
    byte status = mpu.begin();
    Serial.println(status);
    while(status!=0){ 
      Serial.println("NOT FOUND");
      status = mpu.begin();
    }
    
    delay(1000);
    mpu.upsideDownMounting = true; 
    mpu.calcOffsets(true,true); 
} 
void loop() {
    mpu.update();
    Serial.println("{\"x\":"+String(mpu.getAccX())+",\"y\":"+String(mpu.getAccY())+",\"z\":"+String(mpu.getAccZ())+"}");
    delay(50);
}
