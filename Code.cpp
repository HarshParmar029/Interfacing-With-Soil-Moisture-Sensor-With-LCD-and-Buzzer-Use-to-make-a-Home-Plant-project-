#include <LiquidCrystal.h>   // LCD library

LiquidCrystal lcd(7,6,2,3,4,5);

void setup() {
  lcd.begin(16, 2);        // LCD with 16x2 size
  pinMode(8, OUTPUT);        // Buzzer connected to pin 8
  pinMode(A0,INPUT);      // Soil moisture sensor connected to A0
  Serial.begin(9600);      // Serial monitor start
}

void loop() {
 int MV = analogRead(A0);     // Read raw sensor value
 int MP = map(MV, 0, 1023, 0, 100); // Map to percentage (0–100)

  // Display on Serial Monitor
  Serial.print("Moisture Value: ");
  Serial.print(MV);
  Serial.print(" | Moisture %: ");
  Serial.println(MP);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moist:");
  lcd.print(MV);

  // Conditions
  if (MV < 100) {
    lcd.setCursor(0, 1);
    lcd.print("Very Dry");
    tone(13, 1000);   // High sound(1000)
  }      
  else if (MV >= 100 && MV < 250) {
    lcd.setCursor(0, 1);
    lcd.print("Dry");
    tone(13, 500);    // Medium sound
  }
  else if (MV >= 250 && MV < 650) {
    lcd.setCursor(0, 1);
    lcd.print("Wet || Perfect");
    noTone(13);    // Low sound
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("Very Wet");
    tone(13,100);       // Buzzer off
  }

  delay(1000);   // 1 second delay
}

