#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  LoRa.setSpreadingFactor(11);
  Serial.println("LoRa Receiver");
  pinMode(LED_BUILTIN, OUTPUT);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
int a = 0;
void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");
    a = 1;
    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    float snr = LoRa.packetSnr();
    Serial.print("snr");
    Serial.print(snr);
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    
  }
  if (a == 1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    a = 0;
  }

}
