#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        //Asking for input of height of pyramid
        h = get_int("What is the height of the pyramid:\n");
    }
    while (h < 1 || h > 8);

    // draw the pyramid
    for (int i = 0; i < h; i++)
    {
        for (int p = 1; p < h + 1; p++)
        {
            if (p + i < h)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
