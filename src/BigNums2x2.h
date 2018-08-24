

/************************************************

  BigNums2x2 displays a big number that spans 2x2 characters on a character LCD.
  - This library is designed to work with common 2x16 character LCDs, though may work with a variety of sizes.
  - It used in conjunction with the Arduino LiquidCrystal library.

  Four different fonts are included, they can be easily modified or deleted if unused to save memory.
  Tron and Trek seem to be the easiest to read at a glance from far away (bold style).

  Copyright 2018, by Carrie Sundra for Alpenglow Industries
  All rights reserved.
  License: MIT

  ************************************************/


#ifndef BigNums2x2_h
#define BigNums2x2_h

#include <Arduino.h>
#include <LiquidCrystal.h>

// Call your LiquidCrystal variable "lcd" to pass it into this library
extern LiquidCrystal lcd;

// Constants
#define NUMFONTS         4    // The total number of fonts
#define BIGNUMCHARS     13    // The total number of characters in each font

// Font Names
#define NASA  0
#define TRON  1
#define TREK  2
#define SERIF 3

class BigNums2x2 {
  public:

    // creates BigNums2x2 object and initializes font
    BigNums2x2(int name); // calls font
    void font(int name);  // initializes the BigNum font, call to change font

    // initializes default number of digits and start column settings for big numbers and symbols (more below)
    // allows the user to call print with just a number (and optional symbol)
    int stcolbndefault = 5;   // start column for big numbers
    int stcolbsdefault = 5;   // start column for big symbols
    int numdigbndefault = 4;  // number of digits for big numbers
    int numdigbsdefault = 3;  // number of digits for big symbols

    // (optional) allows the user to set the defaults themselves
    void defaults(int stcolbn, int numdigbn, int stcolbs, int numdigbs);

    // The following all print a Big Number with or without Symbol
    //   bignum - the number you want to print on the LCD
    //   length - the number of digits in the number only (not incl symbol)
    //   startcol - the starting column number of the leftmost digit in the number (not including '-' if negative)
    //   symbol - prints a %, can add more symbols if desired
    // Multiple versions of printBigNum allow user to fix the location and size, and just send the bignum
    // ex: print(-122, 3, 5, '%') prints -122%, with the "-" symbol at column 2 and the "1" at column 5
    void print(long number, int length, int startcol, char symbol);
    void print(long number, char symbol);     // uses big symbol defaults defined above
    void print(long number);                  // uses big number defaults defined above

  private:
    void printNum(uint8_t index, uint8_t *Number);  // prints a single digit at a location (index)
};

#endif
