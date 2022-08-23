//checks if a credit card number is valid and returns which company it belongs to. usage - ./credit

#include <cs50.h>
#include <stdio.h>
//long calculate_sum1(long number);

int main(void)
{
    long number;
    number = get_long("Number: ");
    long sum1 = 0;
    long sum2 = 0;
    long starting_numbers = number;
    long starting_number = number;

//even digits sum
    for (long i = number; i>1; i = (i - i%10)/10)
    {
        long even_digits;
        even_digits = 2*(((i - i%10)/10)%10);
        long split_ed;
        split_ed = even_digits%10 + ((even_digits - (even_digits%10))/10);
        sum1 = sum1 + split_ed;
        i = (i - i%10)/10;
    }

//odd digits sum
    for (long j = number; j>1; j = (j - j%10)/10)
    {
        long odd_digits = j%10;
        long split_od = odd_digits%10 + ((odd_digits - (odd_digits%10))/10);
        sum2 = sum2 + split_od;
        j = (j - j%10)/10;
    }

//total sum
    int total_sum = sum1 + sum2;

//number of digits
    long num = number;
    int digits = 0;
    while (num>0)
    {
        num = num/10;
        digits++;
    }
//    printf("%i\n", digits);

//starting digits
    long start = number;
    while (start > 100)
    {
        start = (start - start%10)/10;
    }
//    printf("%ld\n", start);

//validation
    if ((digits != 15 && digits != 16 && digits != 13) || total_sum%10 != 0)
    {
        printf("INVALID\n");
    } else if ((start - start%10)/10 == 4)
    {
        printf("VISA\n");
    } else if (start == 34 || start == 37)
    {
        printf("AMEX\n");
    } else if ((start - start%10)/10 == 5 && (start%10 >= 1 && start%10 <= 5))
    {
        printf("MASTERCARD\n");
    } else
    {
        printf("INVALID\n");
    }
}
