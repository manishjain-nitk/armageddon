#include<stdio.h>
int add(int x, int y)
{
    return printf("%*c%*c",  x, '\r',  y, '\r');
}
 
int main()
{
    
    printf("Sum = %d", add(3, 4));
    return 0;
}/*
int main()
{
int x = 10, y = 22;
char *p = 0;
int z = (int)&((&(p[x]))[y]);
printf("%d\n", z);
}*/
