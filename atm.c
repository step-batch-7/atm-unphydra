#include <math.h>
#include "atm.h"

cash getRemainingAndModifyHexNumber(cash *number, cash money, int note, int power)
{
  cash count = floor(money/note);
  *number<<=4;
  *number+=count;
  return money%note;
}

cash get_money(unsigned short int money)
{
  cash number = 0x0;
  if(money>limit)
  {
    return number;
  }
  cash remaining = money;
  notes notes = {2000, 500, 100, 50, 20, 10, 5, 1};
  for(int i=0;i<8;i++)
  {
    remaining = getRemainingAndModifyHexNumber(&number,remaining,notes[i],7-i);
  }
  return number;
}
