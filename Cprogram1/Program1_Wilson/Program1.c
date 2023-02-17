#include <stdio.h>

#define ROWS 12
#define MONTHS 12

int main()
{
    char str[100];
    printf("Enter a file name: ");
    scanf("%s", str);

    float array[ROWS];
    FILE *file;
    file = fopen(str, "r");

    int row = 0;
    while (!feof(file))
    {
        for (int i = 0; i < 1; i++)
        {
            if (fscanf(file, "%f", &array[row]) == EOF)
            break;
        }

        row++;
        if (row == ROWS) break;
    }

    monthly(array);
    summary(array);
    moving_avg(array);
    high_to_low(array);
    
    return 0;
}

void monthly(float array[ROWS])
{
    char months[100][MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
     "October", "November", "December"};

    printf("\nMonthly Sales Report for 2022:");
    printf("\nMonth            Sales\n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("%-15s", months[i]);
        printf("$%.2f\n", array[i]);
    }

    for (int i = 0; i < 3; i++) 
    {
        printf("\n");
    }
}

void summary(float array[ROWS])
{
    char months[100][MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
     "October", "November", "December"};
    float min = 100000;
    float max = 0;
    float avg = 0;
    char *min_month;
    char *max_month;

    for (int i = 0; i < ROWS; i++)
    {
        avg = (avg + array[i]);

        if (array[i] < min)
        {
            min = array[i];
            min_month = months[i];
        }

        if (array[i] > max)
        {
            max = array[i];
            max_month = months[i];
        }
    }

    avg /= ROWS;

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f", min);
    printf("    (%s)\n", min_month);
    printf("Maximum sales: $%.2f", max);
    printf("    (%s)\n", max_month);
    printf("Average sales: $%.2f\n", avg);

    for (int i = 0; i < 3; i++) 
    {
        printf("\n");
    }
}

void moving_avg(float array[ROWS])
{
    float avg_1 = 0;
    float avg_2 = 0;
    float avg_3 = 0;
    float avg_4 = 0;
    float avg_5 = 0;
    float avg_6 = 0;
    float avg_7 = 0;

    for (int i = 0; i < 6; i++)
    {
        avg_1 = avg_1 + array[i];
    }

    for (int i = 1; i < 7; i++)
    {
        avg_2 = avg_2 + array[i];
    }

    for (int i = 2; i < 8; i++)
    {
        avg_3 = avg_3 + array[i];
    }

    for (int i = 3; i < 9; i++)
    {
        avg_4 = avg_4 + array[i];
    }

    for (int i = 4; i < 10; i++)
    {
        avg_5 = avg_5 + array[i];
    }

    for (int i = 5; i < 11; i++)
    {
        avg_6 = avg_6 + array[i];
    }

    for (int i = 6; i < 12; i++)
    {
        avg_7 = avg_7 + array[i];
    }

    avg_1 /= 6;
    avg_2 /= 6;
    avg_3 /= 6;
    avg_4 /= 6;
    avg_5 /= 6;
    avg_6 /= 6;
    avg_7 /= 6;

    printf("Six-Month Moving Average Report:\n");
    printf("January     -   June       $%.2f\n", avg_1);
    printf("February    -   July       $%.2f\n", avg_2);
    printf("March       -   August     $%.2f\n", avg_3);
    printf("April       -   September  $%.2f\n", avg_4);
    printf("May         -   October    $%.2f\n", avg_5);
    printf("June        -   November   $%.2f\n", avg_6);
    printf("July        -   December   $%.2f\n", avg_7);

    for (int i = 0; i < 3; i++) 
    {
        printf("\n");
    }
}


void high_to_low(float array[ROWS])
{
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
     "October", "November", "December"};

    for (int i=0; i<MONTHS; i++) {
        for (int j=0; j<MONTHS-i-1; j++) {
            if (array[j] < array[j+1]) {
                float swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
                char *temp = months[j];
                months[j] = months[j+1];
                months[j+1] = temp;
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n\n");
    printf("%-15s%-10s\n", "Month", "Sales");
    for (int i = 0; i < MONTHS; i++)
    {
        printf("%-15s$%-10.2f\n", months[i], array[i]);
    }
}




















