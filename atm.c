#include <math.h>
#include "atm.h"

typedef unsigned int num;

unsigned int get_money(unsigned short int money)
{
  num number = 0;
  if(money>31999)
  {
    return number;
  }
  num remaining = money;
  num count = 0;
  int notes[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  for(int i=0;i<8;i++)
  {
    count =floor(remaining/notes[i]);
    number+=(pow(16,7-i)*count);
    remaining = remaining%notes[i];
  }
  return number;
}
