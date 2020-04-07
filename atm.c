#include "atm.h"

int validate_money(short_cash money)
{
  return money<=LIMIT;
}

cash get_remaining_and_modify_hex_number(cash *number, cash money, int note)
{
  *number<<=4;
  *number |= money/note;
  return money%note;
}

cash get_money(unsigned short int money)
{
  cash number = ZERO_HEX;
  if(!validate_money(money)) return number;
  cash remaining = money;
  notes denominations = NOTE_LIST;
  EIGHT_TIMES
  {
    remaining = get_remaining_and_modify_hex_number(&number,remaining,denominations[i]);
  }
  return number;
}

void display_notes(cash money)
{
  notes denominations = NOTE_LIST;
  cash notes_pos = INITIAL_POS;
  cash count = 0;
  EIGHT_TIMES
  {
    count = money & notes_pos;
    count>>=((7-i)*4);
    count && printf("%d %s of Rs %d\n",count, count>1?"counts":"count",denominations[i]);
    notes_pos>>=4;
  }
  EMPTY_LINE;
}