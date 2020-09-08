
#define VCC0 8
#define GND0 9


#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth



void setupPins()
{
  pinMode(VCC0,OUTPUT);
  pinMode(GND0,OUTPUT);
  digitalWrite(VCC0,HIGH);
  digitalWrite(GND0,LOW);
}
 
void setup()
{
  setupPins();
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    //BT.print(BT.read());
    //BT.println(BT.readString());
    apply(BT.readString());
  }
}

void apply(String instruction){
  if (instruction.equals("test\r\n")){
    BT.print("test succesful!\n");
  }
  
}
