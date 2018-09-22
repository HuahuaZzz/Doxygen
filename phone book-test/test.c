#include <stdio.h>
#include <string.h>

#include<ctype.h>
#define CHECKNUMBER 8
#define CHECKENGLISH 3
#define PHOTONUM 10

int main2()
{
    char test[]="123456789";
    int index ;
    index =  Checked_arrary_input(test,5);
    printf("%d",index);
    return 0;
}
