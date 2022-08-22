int i=0;
 int dir=1;

void setup() {
    pinMode(13, OUTPUT); 
    Serial.begin(9600); 
} 
void loop() {
    i+=dir;
    if(i==100 || i==0)dir*=-1;
  
    Serial.println(i);
    delay(50);
}
