/**
 * SISTEMAS MICROPROCESADOS
 * NOMBRE : CRISTIAN RUIZ
 * FECHA: 12/11/2018
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    String cedula=Serial.readString();
    if(formatoValido(cedula)){
        validarCedula(cedula) ? Serial.println("cedula valida"):Serial.println("cedula no valida");  
      }
    else{
      Serial.println("formato de cedula incorrecto");
      }
    Serial.println(cedula); 
    }
       
}
bool formatoValido(String cedula ){
    if(cedula.length()!=11)
      return false;
    for (int i = 0; i < 11; i++){
      //Serial.println(cedula.charAt(i));
      if(!isDigit(cedula.charAt(i)) && i!=9)
        return false;
      if(cedula.charAt(i)!='-' && i==9)
        return false;
      }
    return true;
  }
bool validarCedula(String cedula){
  int provincia =  cedula.substring(0,2).toInt();
  if(provincia<=0 || provincia>24)
    return false;
  int serie =  cedula.substring(2,3).toInt();
  if(serie<0 || serie>=6 )
    return false;    
  cedula.replace("-","");
  int suma=0;
  int coef[9]={2,1,2,1,2,1,2,1,2};
  for(int i = 0;  i < 9; i ++){
    int valor = coef[i]*cedula.substring(i,i+1).toInt();
    //Serial.println(valor);
    if(valor>=10){
      valor = String(valor).substring(0,1).toInt()+String(valor).substring(1,2).toInt();
      }
    //Serial.println(valor);
    suma+=valor;
    }
    int verificador = (suma%10)==0 ? (suma%10):10-(suma%10);     
    return cedula.substring(9).toInt() == verificador ? true:false;
  }  
  
