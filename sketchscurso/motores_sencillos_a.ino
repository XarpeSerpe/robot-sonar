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
}

void loop()
{
derecha(100);
delay(1000);
izquierda(100);
delay(1000);

parar();
delay(5000);

adiante(100);
delay(1000);

parar();
delay(5000);
}

void derecha(int potencia)
{
  digitalWrite(freno_a, LOW);
  digitalWrite(dir_a, LOW);
  analogWrite(vel_a, potencia);
}
void izquierda(int potencia)
{
  digitalWrite(freno_b, LOW);
  digitalWrite(dir_b, LOW);
  analogWrite(vel_b, potencia);
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


