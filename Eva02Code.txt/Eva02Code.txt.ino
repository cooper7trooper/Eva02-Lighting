#include <Adafruit_NeoPixel.h>

#define LED_PIN_L 4
#define LED_PIN_R 5
#define NUM_LEDS_L 16
#define NUM_LEDS_R 16

Adafruit_NeoPixel Lefteyes(NUM_LEDS_L, LED_PIN_L, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Righteyes(NUM_LEDS_R, LED_PIN_R, NEO_GRB + NEO_KHZ800);
int pos = 0;
int mode = 0;
unsigned long lastPress = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT_PULLUP);
  Lefteyes.begin();
  Righteyes.begin();
  Lefteyes.setBrightness(50);   // brightness from 0–255
  Righteyes.setBrightness(50);
  Lefteyes.show();
  Righteyes.show();
  delay(200);

}

void loop() {
  // put your main code here, to run repeatedly:
  handleButton();
  
  switch (mode) {
    case 0:
      staticGREEN();  // Green
      break;
    case 1:
      rainbow(5); // Red wipe
      break;
    case 2:
      Crosseyes();
      break;
  }
}

void handleButton() {
  static bool lastState = HIGH;
  bool currentState = digitalRead(0);

  if (lastState == HIGH && currentState == LOW && millis() - lastPress > 300) {
    mode = (mode + 1) % 3; // cycle through 3 modes
    lastPress = millis();
  }
  lastState = currentState;
}

void rainbow(int wait) {
  static uint32_t lastUpdate = 0;
  static uint16_t firstPixelHue = 0;

  if (millis() - lastUpdate < wait) return;  // only update at the set rate
  lastUpdate = millis();

  for (int i = 0; i < NUM_LEDS_L; i++) {
    int pixelHue = firstPixelHue + (i * 65536L / NUM_LEDS_L);
    uint32_t color = Lefteyes.gamma32(Lefteyes.ColorHSV(pixelHue));
    Lefteyes.setPixelColor(i, color);
    Righteyes.setPixelColor(i, color);
  }

  Lefteyes.show();
  Righteyes.show();

  firstPixelHue += 256;   // move rainbow
  if (firstPixelHue >= 5 * 65536) firstPixelHue = 0;
  handleButton();
  
}

void staticGREEN(){
  for(int i = 0; i < NUM_LEDS_L; i++) {
    Righteyes.setPixelColor(i, Righteyes.Color(0,255,0));
    Lefteyes.setPixelColor(i, Lefteyes.Color(0,255,0));
  }
    Lefteyes.show();
    Righteyes.show();
    handleButton();
}

void Crosseyes(){
  static unsigned long lastMove = 0;
  static uint32_t lastUpdate = 0;
  if (millis() - lastUpdate < 150) return;  // only update at the set rate
  lastUpdate = millis();

  if(pos>3){
    pos = 0;
  }
  for(int i = 0; i < NUM_LEDS_L; i+=1) {
        int idx = (i + pos) % NUM_LEDS_L;  // move pattern forward
    if (idx % 4 == 0) {
      Righteyes.setPixelColor(i, Righteyes.Color(0, 255, 0));
      Lefteyes.setPixelColor(i, Lefteyes.Color(0, 255, 0));
    } else {
      Righteyes.setPixelColor(i, Righteyes.Color(0, 0, 0));
      Lefteyes.setPixelColor(i, Lefteyes.Color(0, 0, 0));
    }
  }
    Lefteyes.show();
    Righteyes.show();
    handleButton();
    pos++;
    
}