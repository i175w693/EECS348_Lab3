#include <stdio.h>

void print_possible_points(int TD_two, int TD_one, int TD, int FG, int safety) 
{
    printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d FG, %d Safety\n", TD_two, TD_one, TD, FG, safety);
}

int main() 
{
    int score = -1;

    while (score > 1 || score == -1) 
    {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) 
        {
            break;
        }

        printf("Possible combinations of scoring plays:\n");

        for (int TD_two = 0; TD_two <= score/8; TD_two++) 
        {
            for (int TD_one = 0; TD_one <= score/7; TD_one++)
            {
                for (int TD = 0; TD <= 6; TD++)
                {
                    for (int FG = 0; FG <= score/3; FG++)
                    {
                        for (int safety = 0; safety <= score/2; safety++) 
                        {
                            if ((TD_two*8 + TD_one*7 + TD*6 + FG*3 + safety*2) == score) 
                            {
                                print_possible_points(TD_two, TD_one, TD, FG, safety);
                            }
                        }
                    } 
                }
            }
        }
    }

    return 0;
}
