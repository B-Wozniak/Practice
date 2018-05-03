#include <stdio.h>
#include <stdlib.h>

void reverse(char * buffer, int length)
{
  int i;
  char temp;

  for (i = 0; i < (length / 2); i++)
  {
    temp = buffer[i];
    buffer[i] = buffer[length - 1 - i];
    buffer[length - 1 - i] = temp;
  }
}

int mystrlen(char * buffer)
{
  return (*buffer != '\0' ? 1 + mystrlen(buffer + 1) : 0);
}

char * itoa(int num, char * buffer, int base)
{
  unsigned char i = 0;
  unsigned char isnegative = 0;
  char temp;

  // sprawdzamy czy liczba jest ujemna
  if (num < 0)
  {
    isnegative = 1;
    num = -num;
  }

  // jedziemy od ostatniej liczby
  while (num)
  {
    temp = num % base;
    buffer[i++] = (temp > 9 ? temp - 10 + 'a' : temp + '0');
    num /= base;
  }

  // dopisz '-' jesli liczba ujemna i podstawa = 10
  if (base == 10 && isnegative)
    buffer[i++] = '-';

  // dopisz null character na koncu
  buffer[i] = '\0';

  // odwroc string
  reverse(buffer, mystrlen(buffer));

  return buffer;
}

int main()
{
  char str[100];

  printf("%s", itoa(5, str, 2));
  return 0;
}
