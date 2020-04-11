#include <stdio.h>
#include <cs50.h>

int main()
{

  int other, leftover, count, first_num, sec_num;
  long num = get_long("Number: ");

  other = leftover = count = first_num = sec_num = 0;

  // Luhn's algorithm
  while (num > 0) {
    sec_num = first_num;
    first_num = num % 10;
   
   if (count % 2 == 0) {
     other += first_num;
   }
   else {
     int mult = first_num * 2;
     leftover += (mult / 10) + (mult % 10);
   }
   num /= 10;
   count++;
  }
  
  int total = leftover + other;


  // get the first 2 digits
  sec_num = (first_num * 10) + sec_num; 

  
  if (total % 10 != 0) {
    printf("INVALID\n");
    return 0;
  }

  // visa
  if (first_num == 4 && (count == 13 || count == 16)) {
    printf("VISA\n");
    return 0;
  }
  // american express
  else if (sec_num == 34 || sec_num == 37 && count == 15) {
    printf("AMEX\n");
    return 0;
  }
  // mastercard
  else if (sec_num == 51 || sec_num == 52 || sec_num == 53 || sec_num == 54 || sec_num == 55 & count == 16) {
    printf("MASTERCARD\n");
    return 0;
  }

  else {
    printf("INVALID\n");
    return 0;
  }
return 0;

}
