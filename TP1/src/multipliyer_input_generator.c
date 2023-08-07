#include <stdio.h>

const int INPUT = 4;

typedef struct bit {
  unsigned  six_bits: 6;
  unsigned  twl_bits: 12;
} bit;

void print_binary(unsigned n, int flag)
{
  int maximum = (flag)? (INPUT * 2) -1 : INPUT -1;
  bit aux;
  for(int i = maximum; i >= 0; i--)
  {
    aux.twl_bits = 1<<(i);
    int result = n & aux.twl_bits;
    printf("%d",!!result);
  }
}


int main()
{
    printf(".i %d\n",INPUT * 2);
    printf(".o %d\n",INPUT * 2);

    bit a,b,c;
    a.six_bits = 0;
    b.six_bits = 0;
    c.twl_bits = 0;

    int last_value = 1<<(INPUT);
    for(int i = 0; i < last_value; i++)
    {
      for(int j = 0; j < last_value; j++)
      {
        a.six_bits = i;
        b.six_bits = j;
        c.twl_bits = a.six_bits * b.six_bits;
        print_binary(a.six_bits,0);
        print_binary(b.six_bits,0);
        printf(" ");
        print_binary(c.twl_bits,1);
        printf("\n");
      }      
    }
    printf(".e \n");
}

