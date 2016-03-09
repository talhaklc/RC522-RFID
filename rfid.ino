#include <SPI.h>
#include <RFID.h>

#define SS_PIN 53
#define RST_PIN 5

RFID rfid(SS_PIN, RST_PIN); 
int dogru=7;
int yanlis=6;
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  pinMode(dogru,OUTPUT);
  pinMode(yanlis,OUTPUT);
  rfid.init();
}

void loop()
{
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      Serial.println(" ");
      Serial.println("Kart Okutuldu!");
      serNum0 = rfid.serNum[0];
      serNum1 = rfid.serNum[1];
      serNum2 = rfid.serNum[2];
      serNum3 = rfid.serNum[3];
      serNum4 = rfid.serNum[4];

     // DEC ondalık formatı ifade eder
      Serial.println("Kart No :");
      Serial.print(rfid.serNum[0],DEC);
      Serial.print(", ");
      Serial.print(rfid.serNum[1],DEC);
      Serial.print(", ");
      Serial.print(rfid.serNum[2],DEC);
      Serial.print(", ");
      Serial.print(rfid.serNum[3],DEC);
      Serial.print(", ");
      Serial.print(rfid.serNum[4],DEC);
      Serial.println(" ");
      
      if(rfid.serNum[0]==103){
       lamba_yak();
        }else{
          lamba_son();
          }
      
      delay(5000);
      digitalWrite(dogru,LOW);
        digitalWrite(yanlis,LOW);
      }
  }
  else
  {
  rfid.halt();
  Serial.println("Berivan");
  delay(500);
}}

void lamba_yak(){
   digitalWrite(dogru,HIGH);
        digitalWrite(yanlis,LOW);
  }
  void lamba_son(){
       digitalWrite(dogru,LOW);
        digitalWrite(yanlis,HIGH);
    }

