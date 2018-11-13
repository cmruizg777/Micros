/**
 * Sistemas Microprocesados
 * Nombre: Cristian Ruiz
 * Fecha: 12/11/2018
 * 
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    String cadena2 = Serial.readString();
    String cadena =  cadena2;
    cadena.toLowerCase();
    int vocales=0;
    String comparador = "aáàäâeéèëêiíìîïoóòöôuúùüû";
    for(int i = 0; i < cadena.length(); i++){
      char c = cadena.charAt(i);
      if(comparador.indexOf(c)>-1)
        vocales++;
      }
    Serial.println("Existen "+String(vocales)+" vocales en: '"+cadena2+"'");
    }
}
