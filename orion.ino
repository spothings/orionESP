#include "BluetoothSerial.h" 
#include "BLEDevice.h"
BluetoothSerial ORION;
char recive;

// Pin LN Kiri
int enf_kiri = 13;
int rf_kiri = 12;
int lf_kiri = 14;
int rb_kiri = 27;
int lb_kiri = 26;
int enb_kiri = 25;

// Pin LN Kanan
int enf_kanan = 33;
int rf_kanan = 32;
int lf_kanan = 21;
int rb_kanan = 19;
int lb_kanan = 18;
int enb_kanan = 5;

void setup() {
  Serial.begin(115200);
  ORION.begin("CIPLUK");
  pinMode(rf_kiri, OUTPUT);
  pinMode(lf_kiri, OUTPUT);
  pinMode(rb_kiri, OUTPUT);
  pinMode(lb_kiri, OUTPUT);
  pinMode(rf_kanan, OUTPUT);
  pinMode(lf_kanan, OUTPUT);
  pinMode(rb_kanan, OUTPUT);
  pinMode(lb_kanan, OUTPUT);
}
void loop() {
  if (ORION.available()){
    recive = ORION.read();
    Serial.print("Received:");
    Serial.println(recive);
    if (recive == 'S'){
      digitalWrite (rf_kiri, LOW);
      digitalWrite (lf_kiri, LOW);
      digitalWrite (rb_kiri, LOW);
      digitalWrite (lb_kiri, LOW);
      digitalWrite (rf_kanan, LOW);
      digitalWrite (lf_kanan, LOW);
      digitalWrite (rb_kanan, LOW);
      digitalWrite (lb_kanan, LOW);
    }
    if (recive == 'F'){
      digitalWrite (rf_kiri, HIGH);
      digitalWrite (lf_kiri, LOW);
      digitalWrite (rb_kiri, HIGH);
      digitalWrite (lb_kiri, LOW);
      digitalWrite (rf_kanan, HIGH);
      digitalWrite (lf_kanan, LOW);
      digitalWrite (rb_kanan, HIGH);
      digitalWrite (lb_kanan, LOW);
    }
  }
}
