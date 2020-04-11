#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{

  int i, other, leftover, count, first_num;
  long num = get_long("Number: ");
  long copy = num;
  bool card = false;

  other = leftover = count = first_num = 0;

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

  // Luhn's algorithm
  for (i = 1; i < count - 1; i++) {
    if (i % 2 != 0) {
      leftover = leftover + (num % 10);
    }
    else {
      other = other + ((num % 10) * 2);
    }
    num /= 10;
    //first_num = num;
  }
  other = other - 1; // the other int is always one too high

  /* 
   * get the first digit
   */

  //printf("count is %d and num is %d\n", count, num);

  first_num = num;
  while(first_num >= 10)
    {
        first_num = first_num / 10;
    }

  int total = leftover + other;

  //printf("total is %d\n", total);
  /*
  if (total % 10 != 0) {
    printf("INVALID\n");
    exit(1);
  }*/

  // american express
  if (num == 34 || num == 37 && count == 15) {
    printf("AMEX\n");
    return 0;
  }
  // mastercard
  else if (num == 51 || num == 52 || num == 53 || num == 54 || num == 55 & count == 16) {
    printf("MASTERCARD\n");
    return 0;
  }
  else if (first_num == 4 && count == 13 || count == 16) {
    printf("VISA\n");
    return 0;
  }
  else {
    printf("INVALID\n");
    return 0;
  }
return 0;

}
