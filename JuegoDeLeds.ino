/*
 * Nombre: Cristian Ruiz
 * Fecha:  24/10/2018
 * Tema:   Juego de leds
 */
void setup() {
  for(int i = 8; i <= 13 ; i++){
    pinMode(i,OUTPUT);
    }
}

void loop() {
  // EJERCICIO 1
  ejercicio1();// enciende los leds de los puertos 9 , 11 , 13 secuencialmente
  //EJERCICIO 2
  ejercicio2();// enciende y apaga los leds de los de los puertos 8 ,10 , 12 
  // EJERCICIO 3
  ejercicio3();// enciende y apaga de manera aleatoria 10 veces los leds de los puertos del 8-13  
}
void ejercicio1(){
  for(int i = 0 ; i <= 2; i++){
    digitalWrite(i*2+9,HIGH);
    delay(200); 
    }
  for(int i = 2 ; i >= 0; i--){
    digitalWrite(i*2+9,LOW);
    delay(200); 
    }
  }
  
void ejercicio2(){
  for(int i = 0 ; i <=2; i++){
    digitalWrite(i*2+8,HIGH);
    delay(200);
    digitalWrite(i*2+8,LOW);
    delay(200);  
    }
  }
void ejercicio3(){
  for(int i = 0 ; i <=10; i++){
    int port = random(8,13);
    digitalWrite(port,HIGH);
    delay(100);
    digitalWrite(port,LOW);
    delay(100);  
    }
  }