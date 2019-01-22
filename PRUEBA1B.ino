#include <EEPROM.h>

/**
 * SISTEMAS MICROPROCESADOS
 * PRUEBA 1B
 * NOMBRE: CRISTIAN RUIZ
 */
 int on = 0;
 String password="";
 String input_password="";
 int tries = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);// boton1 = 1
  pinMode(12,INPUT);// boton2 = 2
  pinMode(11,INPUT);// boton3 = 3
  attachInterrupt(0,on_off,LOW);//boton master
  Serial.begin(9600);
  if(EEPROM.read(0)>3){
    for(int i = 0; i < 5; i++){
      EEPROM.write(i,1);
    }
  }
  for(int j = 0; j < 5; j++)
    password+=String(EEPROM.read(j));
  Serial.println("Contrasena: "password);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(on==1){
    if(input_password.length()<5){
      if(digitalRead(13)==HIGH){
        input_password += "1";
        Serial.print("1");
      }
      if(digitalRead(12)==HIGH){
        input_password += "2";
        Serial.print("2");
      }
      if(digitalRead(11)==HIGH){
        input_password += "3";
        Serial.print("3");
      }
      if(input_password.length()==5)
        Serial.println();
      delay(180);
    }    
  }
}
void on_off(){
  //Serial.println("length: "+String(input_password.length()));
  if(input_password.length()>=5){
    if(input_password == password){
      Serial.println("CONTRASENA CORRECTA: PUEDE ENCENDER EL CARRO");
      tries = 0;
    }else{
      tries ++ ;
      if(tries==3){
        update_password();
        tries = 0;
      }else{
        Serial.println("Le quedan "+String(3-tries)+" Intentos");
      } 
    }
  }else{
    on = 1 - on;
    Serial.println(on == 1 ? "SISTEMA ENCENDIDO":"SISTEMA APAGADO"); 
  }
  //Serial.println("contrasena ingresada: "+input_password);
  input_password = "";
}
void update_password(){
  password = "";
  for(int k = 0; k < 5; k ++){
    int n = random(1,4);
    password += String(n);
  }
  for (int i = 0; i < 5; i++){
    EEPROM.update(i,password.substring(i,i+1).toInt());
  }
  Serial.println("INTENTOS AGOTADOS. LA NUEVA CONTRASENA ES: "+password);
  Serial.println("SISTEMA ENCENDIDO");
}
