

const int bigote_a = 7;
const int bigote_b = 16; //asi el A2 trabaja como digital.
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
attachInterrupt(0, choque, LOW); 
}

void loop()
{
adiante(254);
delay(10000);
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
  parar();
  digitalWrite(freno_a, LOW);
  digitalWrite(dir_a, HIGH);
  digitalWrite(freno_b, LOW);
  digitalWrite(dir_b, HIGH);
  for(int x = 0; x <= 3; x++){
  analogWrite(vel_a, potencia/3.*x);
  analogWrite(vel_b, potencia/3.*x);
  }
 }
    
void choque()
  { /*Identificar cual es la colisin para dar tres comportamientos
    Derecha, apaga motor izquierdo y acelera el derecho.
    Izquierda, apaga el motor derecho y acelera el izquierdo.
    Ambos, invierte la marcha, se para y reanaliza el terreno.
    */
    int _bigote_a;
    int _bigote_b;
    
    _bigote_a = digitalRead(bigote_a);
    _bigote_b = digitalRead(bigote_b);
    if( _bigote_a == HIGH && _bigote_b == LOW)
      {
      atras(100);
      }
     else if( _bigote_b == HIGH && _bigote_a == LOW)
     {
       atras(100);
     }
     else // Este caso nunca se da
     
     {
       atras(100);
     }
  }
