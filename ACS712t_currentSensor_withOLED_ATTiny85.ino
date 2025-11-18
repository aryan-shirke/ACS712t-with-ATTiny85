#include <TinyWireM.h>
#include <Tiny4kOLED.h>

const int nSamples = 1000;
const float vcc = 5.0;
const int adcMax = 1023;
const float sens = 0.185;   // for ACS712-5A

float avgADC() {
  float sum = 0;
  for (int i = 0; i < nSamples; i++) {
    sum += analogRead(A3);
    delay(1);
  }
  return sum / nSamples;  // average raw ADC value
}

void displayCurrent(float cur) {
  oled.clear();
  
  oled.setFontX2(FONT6X8P);
  oled.setCursor(0, 1);
  oled.print("Current");
  
  oled.setFontX2(FONT8X16P);
  oled.setCursor(0, 4);
  oled.print(cur, 2);    // 2 decimal places
  oled.print("A");
}

void setup() {
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.clear();
  oled.on();
}

void loop() {
  float adc = avgADC();
  float voltage = adc * (vcc / adcMax);

  float cur = (voltage - vcc / 2.0) / sens;

  displayCurrent(cur);

  delay(500);
}
