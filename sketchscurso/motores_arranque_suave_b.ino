int dir_a = 12;
int vel_a = 3;
int freno_a = 9;
int dir_b = 13;
int vel_b = 11;
int freno_b = 8;
void setup()
{
pinMode(dir_a, OUTPUT);
pinMode(vel_a, OUTPUT);
pinMode(freno_a, OUTPUT);
pinMode(dir_b, OUTPUT);
pinMode(vel_b, OUTPUT);
pinMode(freno_b, OUTPUT);

//attachInterrupt(0, choque, LOW); 
}

void loop()
{
derecha(50);
delay(1000);
parar();
delay(1000);
adiante(100);
delay(1000);
parar();
delay(1000);
izquierda(250);
delay(1000);
parar();
delay(1000);
atras(50);
delay(1000);
}


void derecha(int potencia)
{
  
  digitalWrite(freno_a, LOW);
  digitalWrite(dir_a, LOW);
 for(int x = 0; x <= 3; x++){
  analogWrite(vel_a, potencia/3.*x);
 }
}
void izquierda(int potencia)
{
  digitalWrite(freno_b, LOW);
  digitalWrite(dir_b, LOW);
  for(int x = 0; x <= 3; x++){
  analogWrite(vel_b, potencia/3.*x);
  }
}
void adiante(int potencia)
{
  derecha(potencia);
  izquierda(potencia);
}
void parar()
{
  digitalWrite(freno_a, HIGH);
  digitalWrite(freno_b, HIGH);
}

void atras(int potencia)
{
  digitalWrite(freno_a, LOW);
  digitalWrite(dir_a, HIGH);
  digitalWrite(freno_b, LOW);
  digitalWrite(dir_b, HIGH);
  for(int x = 0; x <= 3; x++){
  analogWrite(vel_a, potencia/3.*x);
  analogWrite(vel_b, potencia/3.*x);
  }
 }
    

