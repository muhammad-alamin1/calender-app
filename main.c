#include<stdio.h>


int get_first_day_of_the_year(int year);

int main()
{
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i, j, total_days, week_day, year, space_counter = 0;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter your favorite year:\n");
    scanf("%d", &year);
    printf("\n\n********** Welcome to %d **********\n\n", year);

    // Check if it is a leap year
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        days_in_month[1] = 29;
    }

    // get the first day of the year
    week_day = get_first_day_of_the_year(year);

    for(i = 0; i < 12; i++)
    {
        printf("\n\n\n\n----------------------- %s -----------------------\n", months[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");

        for(space_counter = 1; space_counter <= week_day; space_counter++)
        {
            printf("      ");
        }

        total_days = days_in_month[i];
        for(j = 1; j <= total_days; j++)
        {
            printf("%6d", j);
            week_day++;
            if(week_day > 6)
            {
                week_day = 0;
                printf("\n");
            }
        }
    }

    return 0;
}

// first day of the year
int get_first_day_of_the_year(int year)
{
    int day = (year*365 +((year-1)/4) - ((year-1)/100)+((year-1)/400)) % 7;

    return day;
}
