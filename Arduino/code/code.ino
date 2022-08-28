#include <MPU6050_light.h>
MPU6050 mpu(Wire);

long timer = 0;
int n =0;
float x, y, z;

bool isClick=false;

int nIteration=20;

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

    pinMode(6,INPUT);
    pinMode(7,INPUT);
} 
void loop() {
      int leftClick=digitalRead(6);
      int rightClick=digitalRead(7);
      if(leftClick && !isClick){
        isClick=true;
        Serial.println("lc");
      }else if(rightClick && !isClick){
        isClick=true;
        Serial.println("rc");
      }else if(!leftClick && !rightClick){
        isClick=false;
        float xSum=0,ySum=0,zSum=0;
        for(int i=0;i<nIteration;i++){
          mpu.update();
          xSum+=mpu.getAccX();
          ySum+=mpu.getAccY();
          zSum+=mpu.getAccZ();
        }
        Serial.println("{\"x\":"+String(xSum/nIteration)+",\"y\":"+String(ySum/nIteration)+",\"z\":"+String(zSum/nIteration)+"}");
      }
    delay(30);
}
