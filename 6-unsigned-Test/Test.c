#include <stdio.h>

int main(void)
{
    unsigned char a = 45;
    unsigned char b = 250;
    unsigned char c = 0;

    c = a - b;
    printf("unsigned version: %d - %d = %d\n", a, b, c);
    
    return 0; 
}
