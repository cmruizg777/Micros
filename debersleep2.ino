/**
 * Nombre: Cristian Ruiz
 * Fecha: 05/02/2019
 * Estimados estudiantes: Realizar un programa que permita poner al sistema 
 * 19 segundos en modo sleep, se despierte, realice un lectura del conversor análogo digital, lo 
 * imprima por comunicación serial y vuelva a dormir 19 segundos.
 */

#include <TimerOne.h>
#include <avr/sleep.h>
#include <avr/power.h>
const int sensor1= A0;  
float value_CAD = 0.00;
int data;
int i=0;
int power_on;


void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(counter);
  set_sleep_mode (SLEEP_MODE_PWR_DOWN); 
  sleep_enable();
  attachInterrupt(1, up,LOW);

}

void loop() {
  if (i==19){
    value_CAD=(analogRead(sensor1)*99.00)/1023.0;
    data = int(value_CAD);
  }
  

}

void up(){
  power_on=1-power_on;
}

void counter(){
  i++;
}
