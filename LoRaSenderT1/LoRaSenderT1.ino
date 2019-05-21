#include <SPI.h>
#include <LoRa.h>

int counter = 0;
int a = 0;
void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
pinMode(LED_BUILTIN, OUTPUT);
LoRa.setSpreadingFactor(11);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  a = 1;
  LoRa.endPacket();
  if (a == 1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    a = 0;
  }
  counter++;

  delay(1000);
}
