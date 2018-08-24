// include the library code:
#include <LiquidCrystal.h>
#include <BigNums2x2.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
BigNums2x2 bigNum(TREK);

uint8_t name;

//only used for printing font names
char FontStr[5] = {'\0'};
const char *FontList[NUMFONTS] = {"NASA", "TRON", "TREK", "SERF"};

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:

  // cycles through 4 LCD BigNums2x2 Fonts and displays all numbers
  uint8_t i;
  for (i = 0; i < 4; i++){
    name = i;
    bigNum.font(name);                // loads the font
    strcpy(FontStr, FontList[name]);  // loads the font name into FontStr

    lcd.clear();          // displays the font info in normal LCD font, 2x4 chars at left of display
    lcd.setCursor(0,0);
    lcd.print("FONT");
    lcd.setCursor(0,1);
    lcd.print(FontStr);

    bigNum.print(1234);   // displays the BigNums and % symbol for the font
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);

    bigNum.print(5678);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);

    bigNum.print(-90, 2, 8, '%');
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
  }
}
