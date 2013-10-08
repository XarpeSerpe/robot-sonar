int ojo = 14;
int led = 12;
int val;

void setup()
{
 pinMode(ojo, INPUT);
 pinMode(led, OUTPUT); 
}

void loop()
{
  val = analogRead(ojo);  
  if ( val > 512)
    {
      digitalWrite(led, HIGH);
    }
  else
    {
      digitalWrite(led, LOW);
    }
    Serial.println(val);
}
