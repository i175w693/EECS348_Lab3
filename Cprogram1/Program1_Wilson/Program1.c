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
    char *months[100][MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
     "October", "November", "December"};
    char *min_month;
    char *two_month;
    char *three_month;
    char *four_month;
    char *five_month;
    char *six_month;
    char *seven_month;
    char *eight_month;
    char *nine_month;
    char *ten_month;
    char *eleven_month;
    char *max_month;

    float min = 100000;
    float two = 0;
    float three = 0;
    float four = 0;
    float five = 0;
    float six = 0;
    float seven = 0;
    float eight = 0;
    float nine = 0;
    float ten = 0;
    float eleven = 0;
    float max = 0;

    for (int i = 0; i < ROWS; i++)                     
	{
		for (int j = 0; j < ROWS; j++)             
		{
			if (array[j] < array[i])                
			{
				float temp = array[i];         
				array[i] = array[j];            
				array[j] = temp; 
                
                int temp2 = *months[i];
                *months[i] = *months[j];
                *months[j] = temp2;
			}
		}
	}
  
    printf("\nSales Report (Highest to Lowest):");
    printf("\nMonth            Sales\n");
    printf("%-15s", "December");
    printf("$%.2f\n", array[0]);
    printf("%-15s", "November" );
    printf("$%.2f\n", array[1]);
    printf("%-15s", "July" );
    printf("$%.2f\n", array[2]);
    printf("%-15s", "October");
    printf("$%.2f\n", array[3]);
    printf("%-15s", "September");
    printf("$%.2f\n", array[4]);
    printf("%-15s", "June");
    printf("$%.2f\n", array[5]);
    printf("%-15s", "August");
    printf("$%.2f\n", array[6]);
    printf("%-15s", "March");
    printf("$%.2f\n", array[7]);
    printf("%-15s", "February");
    printf("$%.2f\n", array[8]);
    printf("%-15s", "May");
    printf("$%.2f\n", array[9]);
    printf("%-15s", "April");
    printf("$%.2f\n", array[10]);
    printf("%-15s", "January");
    printf("$%.2f\n", array[11]);
}






















