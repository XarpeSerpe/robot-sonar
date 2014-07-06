#include "robot_mobil.h" // Biblioteca de control de motores
#include <NewPing.h>     // Biblioteca de sonar

#define THRESHOLD 20     // Distancia a mantener
#define DEBUG 1          // 1 para robot en test, 0 para robot definitivo
#define VERSION 0.0      // Control de version
#define MOUNTH 10        // Pin usado para emitir ultrasonidos
#define EAR 5            // Pin usado para recivir ultrasonidos
#define LOST 30          // Distancia en cm máxima a ser testada
#define VEL_LEFT 120     // Potencia por defecto en rueda izquierda
#define VEL_RIGHT 120    // Potencia por defecto en rueda izquierdaRobotMovil keepDistance; // Nombre del robot
#define ACTION 0         // Microsegundos de espera antes de frenar el motor
NewPing sonar(10,5,30);  // Sonar de ultrasonidos

void setup()
{
#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("#################");
  Serial.println("# Keep Distance #);
  Serial.println("# Version: VERSION  #");
  Serial.println("#################");
#endif
}

void loop()
{
  unsigned int time = sonar.ping();
  float cm = sonar.convert_cm(time);

  if(cm <= THERSHOLD  ) keepDistance.forward(VEL_LEFT, VEL_RIGHT,ACTION);
  else keepDistance.reverse(VEL_LEFT, VEL_RIGHT, ACTION);

#ifdef DEBUG
  Serial.print(cm);
  Serial.println(" cm.");
#endif

}
