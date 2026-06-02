
#include <SPI.h>
#include <SD.h>
 
#define SD_CS   4
#define SD_MOSI 5
#define SD_SCK  6
#define SD_MISO 7
 
void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Starting...");
 
  pinMode(SD_CS, OUTPUT);
  digitalWrite(SD_CS, HIGH);
  delay(100);
 
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
  delay(100);
 
  Serial.print("MISO state: ");
  Serial.println(digitalRead(SD_MISO));
 
  if (!SD.begin(SD_CS, SPI, 400000)) {
    Serial.println("SD INIT FAILED");
    return;
  }
  Serial.println("SD INIT OK");
}
 
void loop() {}
