#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
   // american express length 15

  // mastercard length 16
  // visa length 13 & 16

  // starts with
  // AMEX 34 or 37
  // mastercard 51, 52, 53, 54, or 55
  // visa 4

  int i, other, leftover, count, first_num, sec_num;
  long num = get_long("Number: ");
  long copy = num;
  bool card = false;

  other = leftover = count = first_num = sec_num = 0;


  // Luhn's algorithm
  while (num > 0) {
    sec_num = first_num;
    first_num = num % 10;
   
   if (count % 2 == 0) {
     other += first_num;
     //printf("other: %d\n", other);
   }
   else {
     int mult = first_num * 2;
     leftover += (mult / 10) + (mult % 10);
     //printf("leftover: %d\n", leftover);
   }
   num /= 10;
   count++;
  }
  //other = other - 1; // the other int is always one too high
  int total = leftover + other;


  // get the first digit to check for 4
  sec_num = (first_num * 10) + sec_num; 

  //printf("total is %d\n", total);
  
  if (total % 10 != 0) {
    printf("INVALID\n");
    return 0;
  }
  

  // american express
  if (sec_num == 34 || sec_num == 37 && count == 15) {
    printf("AMEX\n");
    return 0;
  }
  // mastercard
  else if (sec_num == 51 || sec_num == 52 || sec_num == 53 || sec_num == 54 || sec_num == 55 & count == 16) {
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
