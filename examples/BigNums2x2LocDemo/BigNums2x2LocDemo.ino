// include the library code:
#include <LiquidCrystal.h>
#include <BigNums2x2.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
BigNums2x2 bigNum(TREK);

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.clear();

  // tests printing 0 with leading zero blanking
  bigNum.print(0, 4, 5, 0);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  lcd.clear();

  // tests leading zero blanking and clearing spaces between big numbers
  bigNum.print(345, 5, 0, 0);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  bigNum.print(12345, 5, 1, 0);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  lcd.clear();

  // tests the rest of the big numbers
  bigNum.print(67890, 5, 1, 0);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  lcd.clear();

  // tests a big %
  bigNum.print(69, 2, 0, '%');
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  lcd.clear();

  bigNum.print(200, '%');
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  lcd.clear();

  // tests a negative number
  bigNum.print(-999, 3, 3, '%');
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  bigNum.print(888, 3, 3, 0);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  lcd.clear();

  // tests changing the defaults, as well as truncating
  bigNum.defaults(3, 3, 3, 2);
  bigNum.print(-1234);  // should only print -234
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  lcd.clear();
  bigNum.print(6432, '%');  // should only print 32%
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  bigNum.defaults(5, 4, 5, 3);


}
