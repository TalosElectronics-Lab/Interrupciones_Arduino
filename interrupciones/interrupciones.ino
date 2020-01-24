const int PROCESO_1 = 1;
const int PROCESO_2 = 2;
const int PROCESO_3 = 3;
const int TIEMPO_ESPERA=1000;
const int VENTANA=1000;

const byte boton=2;
const byte led_rojo = 3;
const byte led_amarillo=4;
const byte led_verde=5;

volatile int menu=0;

long Time=0;

void setup()
{
    pinMode(boton, INPUT_PULLUP);
    pinMode(led_rojo, OUTPUT);
    pinMode(led_amarillo, OUTPUT);
    pinMode(led_verde, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(boton), interrupcion, FALLING);
}
void loop()
{
    switch (menu)
    {
    
    case PROCESO_1:
        digitalWrite(led_rojo, HIGH);
        delay(TIEMPO_ESPERA);
        digitalWrite(led_rojo, LOW);
        delay(TIEMPO_ESPERA);
        break;

    case PROCESO_2:
        digitalWrite(led_amarillo, HIGH);
        delay(TIEMPO_ESPERA);
        digitalWrite(led_amarillo, LOW);
        delay(TIEMPO_ESPERA);
        break;

    case PROCESO_3:
        digitalWrite(led_verde, HIGH);
        delay(TIEMPO_ESPERA);
        digitalWrite(led_verde, LOW);
        delay(TIEMPO_ESPERA);
        break;

    default:
      defaultAnimation();
      break;
    }
    
}
void interrupcion()
{
    if (millis() - Time > VENTANA)
    {
        menu++;
        Time = millis();
    }
}
void defaultAnimation()
{
  digitalWrite(led_verde, HIGH);
  delay(200);
  digitalWrite(led_verde, LOW);
  delay(200);

  digitalWrite(led_amarillo, HIGH);
  delay(200);
  digitalWrite(led_amarillo, LOW);
  delay(200);

  digitalWrite(led_rojo, HIGH);
  delay(200);
  digitalWrite(led_rojo, LOW);
  delay(200);
}