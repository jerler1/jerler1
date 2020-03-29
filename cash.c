#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int coins=0;
    float money;
    //Determine how much change is left.
    do
    {
        money = get_float("How much change is left:\n$");
    }
    while(money <= 0.00);

    //Testing to make sure my values are converting correctly.
    int penniesleft = round(money * 100);
    
    //Value is converted correctly, and now I need to figure out the least amount of coins.
    while(penniesleft >= 25)
    {
        penniesleft = penniesleft - 25;
        coins++;
    }
    while(penniesleft >= 10)
    {
        penniesleft = penniesleft - 10;
        coins++;
    }
     while(penniesleft >= 5)
    {
        penniesleft = penniesleft - 5;
        coins++;
    }
     while(penniesleft >= 1)
    {
        penniesleft = penniesleft - 1;
        coins++;
    }
    printf("This is how many %i coins were used", coins);
}
