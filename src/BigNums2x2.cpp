/************************************************

  BigNums2x2 displays a big number that spans 2x2 characters on a character LCD.
  - This library is designed to work with common 2x16 character LCDs, though may work with a variety of sizes.
  - It is used in conjunction with the Arduino LiquidCrystal library.

  Four different fonts are included, they can be easily modified or deleted if unused to save memory.
  Tron and Trek seem to be the easiest to read at a glance from far away (bold style).

  Copyright 2018, by Carrie Sundra for Alpenglow Industries
  All rights reserved.
  License: MIT

  ************************************************/

#include "BigNums2x2.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

//////////////////////////////////////////////////////////////////
// Creates the user-defined LCD characters.
// The below format does take up a lot of screen space,
//  but you can actually visualize the characters.
//////////////////////////////////////////////////////////////////

// 8 custom characters for Tron font
// These will be loaded into the LCD if this font is selected

uint8_t tron0[8] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

uint8_t tron1[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

uint8_t tron2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
};

uint8_t tron3[8] = {
  B11111,
  B11111,
  B00011,
  B00011,
  B00011,
  B00011,
  B11111,
  B11111,
};

uint8_t tron4[8] = {
  B11111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11111,
  B11111,
};

uint8_t tron5[8] = {
  B11111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

uint8_t tron6[8] = {
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B11111,
  B11111,
};

uint8_t tron7[8] = {
  B11111,
  B11111,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
};

// 8 custom characters for Trek font
// These will be loaded into the LCD if this font is selected

uint8_t trek0[8] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

uint8_t trek1[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

uint8_t trek2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
};

uint8_t trek3[8] = {
  B11111,
  B11111,
  B00011,
  B00011,
  B00011,
  B00011,
  B11111,
  B11111,
};

uint8_t trek4[8] = {
  B11111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11111,
  B11111,
};

uint8_t trek5[8] = {
  B11111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

uint8_t trek6[8] = {
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B11111,
  B11111,
};

uint8_t trek7[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11111,
  B11111,
};

// 8 custom characters for NASA font
// These will be loaded into the LCD if this font is selected

uint8_t nasa0[8] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

uint8_t nasa1[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

uint8_t nasa2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
};

uint8_t nasa3[8] = {
  B11100,
  B11110,
  B00111,
  B00011,
  B00011,
  B00111,
  B11110,
  B11100,
};

uint8_t nasa4[8] = {
  B00111,
  B01111,
  B11100,
  B11000,
  B11000,
  B11100,
  B01111,
  B00111,
};

uint8_t nasa5[8] = {
  B00011,
  B00011,
  B00110,
  B00110,
  B01100,
  B01100,
  B11000,
  B11000,
};

uint8_t nasa6[8] = {
  B11100,
  B11110,
  B00111,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
};

uint8_t nasa7[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11100,
  B01111,
  B00111,
};

// 8 custom characters for Serif font
// These will be loaded into the LCD if this font is selected

uint8_t serif0[8] = {
  B11111,
  B11110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

uint8_t serif1[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

uint8_t serif2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11110,
  B11111,
};

uint8_t serif3[8] = {
  B11100,
  B01110,
  B00111,
  B00011,
  B00011,
  B00111,
  B01110,
  B11100,
};

uint8_t serif4[8] = {
  B00111,
  B01110,
  B11100,
  B11000,
  B11000,
  B11100,
  B01110,
  B00111,
};

uint8_t serif5[8] = {
  B00011,
  B00011,
  B00110,
  B00110,
  B01100,
  B01100,
  B11000,
  B11000,
};

uint8_t serif6[8] = {
  B11100,
  B01110,
  B00111,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
};

uint8_t serif7[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11100,
  B01110,
  B00111,
};

/////////////////////////////////////////////////////////////////////
// Creates a Big Number - an array of the 4 LCD characters used for each number.
// The order is: (upper left, lower left, upper right, lower right)
// In the array, 0-7 are the eight custom characters, 255 is all on (full black), 32 is all off (space/blank)
// Others are special LCD characters used for the % symbol (these are pre-defined in the LCD)
// Example: Tron0 is an array of the 4 custom characters needed to create the number 0.
//
// The MegaXXXX array are pointers to the first character in each Big Number.
// (Remember your C pointer shorthand: Tron0 = &Tron0[0] = the address of the first element of Tron0)
// The MegaXXXX array is organized so that the index of the array contains the info for that number.
// Ex: MegaTron[0] = Tron0 = the 4 characters needed to print a Big Number "0"
// The MegaXXXX array makes it easy to copy the entire font into the current font variable, MegaFont.
//
// There are a dozen other ways to do this, with 2 dimensional arrays or more pointers.
// I chose the below method because:
//   - each number and font are very clearly spelled out
//   - characters should be easy to change
//   - pointer use is kept to a minimum in accordance with Arduino guidelines
//   - it's hopefully understandable for beginners and an OK intro to pointer use
/////////////////////////////////////////////////////////////////////

uint8_t Tron0[4] = {5, 255, 7, 6};
uint8_t Tron1[4] = {0, 2, 1, 255};
uint8_t Tron2[4] = {0, 255, 3, 2};
uint8_t Tron3[4] = {0, 2, 3, 255};
uint8_t Tron4[4] = {1, 0, 255, 1};
uint8_t Tron5[4] = {4, 2, 0, 255};
uint8_t Tron6[4] = {5, 4, 0, 255};
uint8_t Tron7[4] = {0, 32, 255, 1};
uint8_t Tron8[4] = {255, 4, 3, 255};
uint8_t Tron9[4] = {255, 2, 3, 6};
uint8_t Tron10[4] = {32, 32, 32, 32};     // blank numeral
uint8_t Tron11[4] = {255, 47, 47, 255};   // percent symbol
uint8_t Tron12[4] = {2, 32, 2, 32};       // negative symbol
uint8_t *MegaTron[BIGNUMCHARS] = {Tron0, Tron1, Tron2, Tron3, Tron4, Tron5, Tron6, Tron7, Tron8, Tron9, Tron10, Tron11, Tron12};

uint8_t Trek0[4] = {5, 7, 255, 6};
uint8_t Trek1[4] = {0, 2, 1, 7};
uint8_t Trek2[4] = {0, 4, 3, 2};
uint8_t Trek3[4] = {0, 2, 3, 3};
uint8_t Trek4[4] = {1, 0, 1, 5};
uint8_t Trek5[4] = {4, 2, 0, 3};
uint8_t Trek6[4] = {5, 4, 0, 3};
uint8_t Trek7[4] = {0, 32, 3, 1};
uint8_t Trek8[4] = {4, 4, 3, 3};
uint8_t Trek9[4] = {4, 2, 3, 6};
uint8_t Trek10[4] = {32, 32, 32, 32};     // blank numeral
uint8_t Trek11[4] = {219, 47, 47, 219};   // percent symbol
uint8_t Trek12[4] = {2, 32, 2, 32};       // negative symbol
uint8_t *MegaTrek[BIGNUMCHARS] = {Trek0, Trek1, Trek2, Trek3, Trek4, Trek5, Trek6, Trek7, Trek8, Trek9, Trek10, Trek11, Trek12};

uint8_t Nasa0[4] = {5, 7, 6, 5};
uint8_t Nasa1[4] = {0, 2, 1, 7};
uint8_t Nasa2[4] = {0, 4, 3, 2};
uint8_t Nasa3[4] = {0, 2, 3, 3};
uint8_t Nasa4[4] = {1, 0, 7, 1};
uint8_t Nasa5[4] = {4, 2, 0, 3};
uint8_t Nasa6[4] = {5, 4, 32, 3};
uint8_t Nasa7[4] = {0, 5, 3, 32};
uint8_t Nasa8[4] = {4, 4, 3, 3};
uint8_t Nasa9[4] = {4, 32, 3, 5};
uint8_t Nasa10[4] = {32, 32, 32, 32};       // blank numeral
uint8_t Nasa11[4] = {111, 5, 5, 111};       // percent symbol
uint8_t Nasa12[4] = {2, 32, 2, 32};         // negative symbol
uint8_t *MegaNasa[BIGNUMCHARS] = {Nasa0, Nasa1, Nasa2, Nasa3, Nasa4, Nasa5, Nasa6, Nasa7, Nasa8, Nasa9, Nasa10, Nasa11, Nasa12};

uint8_t Serif0[4] = {5, 7, 6, 5};
uint8_t Serif1[4] = {0, 2, 1, 7};
uint8_t Serif2[4] = {0, 5, 3, 2};
uint8_t Serif3[4] = {0, 2, 3, 3};
uint8_t Serif4[4] = {5, 0, 7, 1};
uint8_t Serif5[4] = {7, 2, 0, 3};
uint8_t Serif6[4] = {5, 4, 32, 3};
uint8_t Serif7[4] = {0, 5, 3, 32};
uint8_t Serif8[4] = {4, 4, 3, 3};
uint8_t Serif9[4] = {4, 32, 3, 5};
uint8_t Serif10[4] = {32, 32, 32, 32};      // blank numeral
uint8_t Serif11[4] = {242, 47, 47, 242};    // percent symbol
uint8_t Serif12[4] = {2, 32, 2, 32};        // negative symbol
uint8_t *MegaSerif[BIGNUMCHARS] = {Serif0, Serif1, Serif2, Serif3, Serif4, Serif5, Serif6, Serif7, Serif8, Serif9, Serif10, Serif11, Serif12};

uint8_t *MegaFont[BIGNUMCHARS];

//////////////////////////////////////////////
// initializes the BigNums2x2 object
// initializes the font
//////////////////////////////////////////////

BigNums2x2::BigNums2x2(int name) {
  font(name);
}

/////////////////////////////////////////////////////////////////////
// loads user-defined characters into LCD and the specified font in MegaFont array
// call if you want to change fonts
/////////////////////////////////////////////////////////////////////

void BigNums2x2::font(int name) {
  switch (name) {
    case NASA: {
      lcd.createChar(0, nasa0);
      lcd.createChar(1, nasa1);
      lcd.createChar(2, nasa2);
      lcd.createChar(3, nasa3);
      lcd.createChar(4, nasa4);
      lcd.createChar(5, nasa5);
      lcd.createChar(6, nasa6);
      lcd.createChar(7, nasa7);
      for (int i = 0; i < BIGNUMCHARS; i++) {
        MegaFont[i] = MegaNasa[i];
      }
      break;
    }
    case TRON: {
      lcd.createChar(0, tron0);
      lcd.createChar(1, tron1);
      lcd.createChar(2, tron2);
      lcd.createChar(3, tron3);
      lcd.createChar(4, tron4);
      lcd.createChar(5, tron5);
      lcd.createChar(6, tron6);
      lcd.createChar(7, tron7);
      for (int i = 0; i < BIGNUMCHARS; i++) {
        MegaFont[i] = MegaTron[i];
      }
      break;
    }
    case TREK: {
      lcd.createChar(0, trek0);
      lcd.createChar(1, trek1);
      lcd.createChar(2, trek2);
      lcd.createChar(3, trek3);
      lcd.createChar(4, trek4);
      lcd.createChar(5, trek5);
      lcd.createChar(6, trek6);
      lcd.createChar(7, trek7);
      for (int i = 0; i < BIGNUMCHARS; i++) {
        MegaFont[i] = MegaTrek[i];
      }
      break;
    }
    case SERIF: {
      lcd.createChar(0, serif0);
      lcd.createChar(1, serif1);
      lcd.createChar(2, serif2);
      lcd.createChar(3, serif3);
      lcd.createChar(4, serif4);
      lcd.createChar(5, serif5);
      lcd.createChar(6, serif6);
      lcd.createChar(7, serif7);
      for (int i = 0; i < BIGNUMCHARS; i++) {
        MegaFont[i] = MegaSerif[i];
      }
    }
  }
}

/////////////////////////////////////////////////////////////////////
// changes the default number of digits and position of big numbers and symbols
// optional, if not called uses pre-defined constants in .h file
/////////////////////////////////////////////////////////////////////

void BigNums2x2::defaults (int stcolbn, int numdigbn, int stcolbs, int numdigbs) {
  stcolbndefault = stcolbn;
  stcolbsdefault = stcolbs;
  numdigbndefault = numdigbn;
  numdigbsdefault = numdigbs;
}

/////////////////////////////////////////////////////////////////////
// prints one 2x2 Big Number to the LCD, at the "index" location
// - index location is the LCD index for the leftmost column of a 2x2 character
// - print order: top left, bottom left, top right, bottom right
/////////////////////////////////////////////////////////////////////

void BigNums2x2::printNum (uint8_t index, uint8_t *Number) {
  uint8_t i, j, k = 0;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      lcd.setCursor(index + i, 0 + j);
      lcd.write(Number[k]);
      k++;
    }
  }
}

/////////////////////////////////////////////////////////////////////
// prints a multi-digit number or percentage to the LCD, int is maximum
// - determines the sign and handles displaying (or erasing) the '-' sign
// - parses the number into individual digits
// - calls printNum to print each individual digit (blanks leading zeros)
// - prints the % symbol if it's a percentage
// - writes a 1 column blank space between each digit
/////////////////////////////////////////////////////////////////////

void BigNums2x2::print (long number, int length, int startcol, char symbol) {

  // handles negative numbers
  // looks at the previous number printed and its location
  // prints and clears '-' accordingly
  static long lastnumber = 0;
  static int lastnumstartcol = 0;

  // clears '-'
  if (lastnumber < 0 && number >= 0) {
    printNum(lastnumstartcol - 3, MegaFont[10]);
  }
  lastnumber = number;
  lastnumstartcol = startcol;

  // prints '-', turns negative number into positive
  if (number < 0) {
    number = -number;
    printNum(startcol - 3, MegaFont[12]);
  }


  // creates an array of the digits in reverse.  Ex: 3450 = {0, 5, 4, 3}
  // if more than length, truncates, throwing out the leftmost digit(s)
  uint32_t bignum = (uint32_t) number;
  uint8_t numdigits = (uint8_t) length;
  uint8_t BigNum[numdigits] = {0};
  uint8_t i;

  for (i = 0; i < numdigits; i++) {
    BigNum[i] = bignum % 10;
    bignum /= 10;
  }

  bignum = (uint32_t) number;   // resets bignum for use below

  // used for leading zero blanking, determines size according to numdigits
  uint32_t digit = 1;
  for (i = 1; i < numdigits; i++) {
    digit *= 10;
  }


  // prints the digits, includes leading zero blanking
  // starts at left, moves right
  uint8_t j, k;
  for (i = 0; i < numdigits; i++) {
    j = BigNum[numdigits-1-i];
    k = (uint8_t) startcol + i*3;

    // leading zero blanking
    if (j == 0 && bignum < digit) {
      printNum(k, MegaFont[10]);
    }
    else printNum(k, MegaFont[j]);

    // if the number is actually zero, prints it
    if (digit == 1 && bignum == 0) {
      printNum(k, MegaFont[j]);
    }
    // if you want to keep leading zeros, comment out the above if statements
    // and uncomment the below line.  Ignore digit variable.
    //printNum(k, MegaFont[j]);

    digit /= 10;
  }


  // prints the % symbol
  // if you add more custom symbols, add code to print them here
  k += 3;
  if (symbol == '%') printNum(k, MegaFont[11]);

  // clears the spaces between digits, prob not needed if you're good about using lcd.clear
  for (i = 0; i < numdigits; i++) {
    if (i == 0 && startcol == 0);
    else {
      int col = (startcol - 1) + 3*i;
      for (int row = 0; row < 2; row++){
        lcd.setCursor(col, row);
        lcd.write(32);
      }
    }
  }

}

////////////////////////////////////////////////////////////////
// uses default number of digits and position
// useful if you only need to set up your display once
// prints a Big Symbol
////////////////////////////////////////////////////////////////

void BigNums2x2::print (long number, char symbol) {
  if (symbol == '%') print(number, numdigbsdefault, stcolbsdefault, '%');
  else  print(number, numdigbsdefault, stcolbsdefault, 0);
}

////////////////////////////////////////////////////////////////
// uses default number of digits and position
// useful if you only need to set up your display once
// prints a Big Number
////////////////////////////////////////////////////////////////

void BigNums2x2::print (long number) {
  print(number, numdigbndefault, stcolbndefault, 0);
}
