#include <SPI.h>
#include <MFRC522.h>
#include <Keypad.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

Servo miServo;
#define SERVO_PIN A0

const byte FILAS = 4;
const byte COLUMNAS = 4;
char teclas[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[FILAS] = {2,3,4,5};
byte pinesColumnas[COLUMNAS] = {6,7,8,A1};
Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

String tarjetasAutorizadas[] = {"C9A265A2","B37A5C12"};
const int numTarjetas = sizeof(tarjetasAutorizadas)/sizeof(tarjetasAutorizadas[0]);

String claveCorrecta = "1111";
String claveIngresada = "";
bool tarjetaValida = false;
unsigned long tiempoLecturaPIN = 0;
const unsigned long tiempoMaxPIN = 200000;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  miServo.attach(SERVO_PIN);
  miServo.write(0);
  Serial.println("Sistema listo");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String contenido = "";
    for (byte i=0;i<rfid.uid.size;i++){
      if (rfid.uid.uidByte[i]<0x10) contenido += "0";
      contenido += String(rfid.uid.uidByte[i],HEX);
    }
    contenido.toUpperCase();
    Serial.print("UID detectado: ");
    Serial.println(contenido);
    bool encontrada = false;
    for (int i=0;i<numTarjetas;i++){
      if (contenido == tarjetasAutorizadas[i]){
        encontrada = true;
        break;
      }
    }
    if (encontrada){
      Serial.println("Tarjeta válida. Ingrese la clave.");
      tarjetaValida = true;
      claveIngresada = "";
      tiempoLecturaPIN = millis();
    } else {
      Serial.println("Tarjeta NO autorizada.");
      tarjetaValida = false;
    }
    rfid.PICC_HaltA();
  }

  if (tarjetaValida && (millis() - tiempoLecturaPIN > tiempoMaxPIN)){
    Serial.println("Tiempo para ingresar PIN agotado. Pase tarjeta nuevamente.");
    tarjetaValida = false;
    claveIngresada = "";
  }

  char k = teclado.getKey();
  if (k && tarjetaValida){
    if (k=='*'){
      claveIngresada="";
      Serial.println("Clave borrada.");
      return;
    }
    if (k=='#') return;
    claveIngresada += k;
    Serial.print("*");
    if (claveIngresada.length()>=claveCorrecta.length()){
      Serial.println();
      if (claveIngresada.substring(0,claveCorrecta.length())==claveCorrecta){
        Serial.println("Clave correcta. Abriendo servo...");
        abrirServo();
      } else {
        Serial.println("Clave incorrecta. Acceso denegado.");
      }
      claveIngresada="";
      tarjetaValida=false;
      Serial.println("Pase una tarjeta nuevamente...");
    }
  }
}

void abrirServo(){
  miServo.write(90);
  delay(3000);
  miServo.write(0);
  Serial.println("Puerta cerrada.");
}
