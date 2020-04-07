#include <math.h>
#include "atm.h"

num getRemainingAndModifyHexNumber(num *number, num money, int note, int power)
{
  num count = 0;
  count =floor(money/note);
  *number+=(pow(16,power)*count);
  return money%note;
}

unsigned int get_money(unsigned short int money)
{
  num number = 0;
  if(money>limit)
  {
    return number;
  }
  num remaining = money;
  int notes[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  for(int i=0;i<8;i++)
  {
    remaining = getRemainingAndModifyHexNumber(&number,remaining,notes[i],7-i);
  }
  return number;
}
