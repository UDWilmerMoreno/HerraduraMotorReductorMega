#include <Arduino.h>
#define PinInterrupcion1 2
#define M1Adelante 45
#define M2Adelante 49
#define M1Atras 47
#define M2Atras 51
#define PWM1 10
#define PWM2 9
volatile int contador1 = 0;
int NumeroDePulsosEncoder = 336;
int velocidad1 = 140;
int velocidad2 = 240;
char dato;

void interrupcion1()
{
  contador1++;
}

void setup()
{
  attachInterrupt(digitalPinToInterrupt(PinInterrupcion1), interrupcion1, RISING);
  pinMode(M1Adelante, OUTPUT);
  pinMode(M2Adelante, OUTPUT);
  pinMode(M1Atras, OUTPUT);
  pinMode(M2Atras, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  Serial.begin(115200);
}

void Adelante()
{
  digitalWrite(M1Adelante, HIGH);
  digitalWrite(M1Atras, LOW);
  digitalWrite(M2Adelante, HIGH);
  digitalWrite(M2Atras, LOW);
}

void Atras()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, HIGH);
  digitalWrite(M2Adelante, LOW);
  digitalWrite(M2Atras, HIGH);
}

void Derecha()
{
  digitalWrite(M1Adelante, HIGH);
  digitalWrite(M1Atras, LOW);
  digitalWrite(M2Adelante, LOW);
  digitalWrite(M2Atras, HIGH);
}

void Izquierda()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, HIGH);
  digitalWrite(M2Adelante, HIGH);
  digitalWrite(M2Atras, LOW);
}
void Parar()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, LOW);
  digitalWrite(M2Adelante, LOW);
  digitalWrite(M2Atras, LOW);
}

void loop()
{
  Parar();
  analogWrite(PWM1, velocidad1);
  analogWrite(PWM2, velocidad2);
  if (Serial.available() > 0)
  {
    dato = Serial.read();
    switch (dato)
    {
    case 'w':
      Serial.println("Posicion: w= Adelante");
      contador1 = 0;
      Adelante();
      while (contador1 < NumeroDePulsosEncoder)
      {
      }
      break;
    case 's':
      Serial.println("Posicion: s= Atras");
      contador1 = 0;
      Atras();
      while (contador1 < NumeroDePulsosEncoder)
      {
      }
      break;
    case 'd':
      Serial.println("Posicion: d= Derecha");
      contador1 = 0;
      Derecha();
      while (contador1 < NumeroDePulsosEncoder)
      {
      }
      break;
    case 'a':
      Serial.println("Posicion: a= Izquierda");
      contador1 = 0;
      Izquierda();
      while (contador1 < NumeroDePulsosEncoder)
      {
      }
      break;
    case 'q':
      Serial.println("Posicion: q= Parar");
      contador1 = 0;
      Parar();
      delay(200);
      break;
    case '0':
      Serial.println("Velociad: 0= 150");
      velocidad1 = 150;
      break;
    case '1':
      Serial.println("Velociad: 1= 160");
      velocidad1 = 160;
      break;
    case '2':
      Serial.println("Velociad: 2= 170");
      velocidad1 = 170;
      break;
    case '3':
      Serial.println("Velociad: 3= 180");
      velocidad1 = 180;
      break;
    case '4':
      Serial.println("Velociad: 4= 190");
      velocidad1 = 190;
      break;
    case '5':
      Serial.println("Velociad: 5= 200");
      velocidad1 = 200;
      break;
    case '6':
      Serial.println("Velociad: 6= 210");
      velocidad1 = 210;
      break;
    case '7':
      Serial.println("Velociad: 7= 220");
      velocidad1 = 220;
      break;
    case '8':
      Serial.println("Velociad: 8= 230");
      velocidad1 = 230;
      break;
    case '9':
      Serial.println("Velociad: 9= 240");
      velocidad1 = 240;
      break;
    case 'z':
      Serial.println("45º");
      NumeroDePulsosEncoder = 42;
      break;
    case 'x':
      Serial.println("90º");
      NumeroDePulsosEncoder = 84;
      break;
    case 'c':
      Serial.println("135º");
      NumeroDePulsosEncoder = 126;
      break;
    case 'v':
      Serial.println("180º");
      NumeroDePulsosEncoder = 168;
      break;
    case 'b':
      Serial.println("225º");
      NumeroDePulsosEncoder = 210;
      break;
    case 'n':
      Serial.println("270º");
      NumeroDePulsosEncoder = 252;
      break;
    case 'm':
      Serial.println("315º");
      NumeroDePulsosEncoder = 294;
      break;
    case 'l':
      Serial.println("360º");
      NumeroDePulsosEncoder = 336;
      break;
    default:
      Serial.println("Caracter no reconocido");
      break;
    }
  }
}