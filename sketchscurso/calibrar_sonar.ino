 
#include <NewPing.h>
NewPing sonar(10,5,50);



void setup() {
  
Serial.begin(4800);
}
  
  
void loop() {   
  
  delay(50); 
  unsigned int time = sonar.ping(); 
  float cm = sonar.convert_cm(time);
                                    
  Serial.println(cm);                                  
}

