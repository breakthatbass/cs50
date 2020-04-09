#include <stdio.h>
#include <cs50.h>

int main()
{

  int i, other, leftover, count;
  long num = get_long("Number: ");
  long copy = num;
  string card = '';

  other = leftover = count = 0;

  // get amount of digits in number
  // using a copy because this will make everything a zero
  while (copy != 0) {
    copy /= 10;
    count++;
  }

  // american express length 15

  // mastercard length 16
  // visa length 13 & 16

  // starts with
  // AMEX 34 or 37
  // mastercard 51, 52, 53, 54, or 55
  // visa 4

  // check for AMEX
  if (count - 1 == 15) {
    card = "AMEX"
  }
  else if (count - 1 == 13 || count - 1 == 16) {
    card = "VISA";
  }
  else if (count - 1 == 16)

  // Luhn's algorithm
  for (i = 1; i < count; i++) {
    if (i % 2 != 0) {
      leftover = leftover + (num % 10);
    }
    else {
      other = other + ((num % 10) * 2);
    }
    num /= 10;
  }
  other = other - 1; // the other int is always one too high

  int total = leftover + other;



}
