int led1 = A5; 
int led2 = D7; 

int photoTrans = A0;
int analogValue;
int val = 0;
int temp = 5;


void setup(){

    Serial.begin(9600);
    
    Particle.variable("analogValue", analogValue);
  
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(photoTrans ,  INPUT);
      
}

void loop(){
    
    analogValue = analogRead(photoTrans);
    int lightValue = analogValue;

    
    if(analogValue <= 40){
        val = 0;
    } else {
        val = 1;
    }
    
    if(val != temp){
        temp = val;
        if(val == 0){
            digitalWrite(led1,HIGH);
            digitalWrite(led2, HIGH);
            Particle.publish("Light", "Sun is down", PRIVATE);
        }else{
            digitalWrite(led1 , LOW);
            digitalWrite(led2 , LOW);
            Particle.publish("Light", "Sun is up", PRIVATE);  
        }
    }
    
    String light = String(analogValue);
    Particle.publish("Light", light, PRIVATE);
    Serial.printlnf("The sunlight reading is: %d ",analogValue);
    
    delay(1000*5);
}
