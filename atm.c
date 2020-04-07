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
  checkLimit;
  cash remaining = money;
  notes notes = noteList;
  repeatEightTimes
  {
    remaining = getRemainingAndModifyHexNumber(&number,remaining,notes[i],7-i);
  }
  return number;
}

void display_notes(cash money)
{
  notes denominations = noteList;
  cash notes_pos = 0xf0000000;
  cash count = 0;
  repeatEightTimes
  {
    count = money & notes_pos;
    count>>=((7-i)*4);
    count && printf("%d %s of Rs %d\n",count, check_quantity,denominations[i]);
    notes_pos>>=4;
  }
  emptyLine;
}