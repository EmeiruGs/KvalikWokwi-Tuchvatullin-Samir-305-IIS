#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 4);

unsigned long long fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);}

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press button!");

  pinMode(1, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(1) == LOW) {
    int randomNumber = random(5, 31);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Number: ");
    lcd.print(randomNumber);

    unsigned long startTime = millis();
    unsigned long fibResult = fibonacci(randomNumber);
    unsigned long endTime = millis();

    float duration = (endTime - startTime) / 1000000.0;

    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(duration, 5);
    lcd.print(" sec");

    lcd.setCursor(0, 2);
    lcd.print("Fib: ");
    lcd.print(fibResult);
    delay(1000);
  }
}
