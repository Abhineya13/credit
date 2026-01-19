#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");

    int sum = 0;
    int digit_count = 0;
    long temp = number;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (digit_count % 2 == 1)
        {
            int doubled = digit * 2;
            sum += (doubled / 10) + (doubled % 10);
        }
        else
        {
            sum += digit;
        }

        temp /= 10;
        digit_count++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long start = number;
    while (start >= 100)
    {
        start /= 10;
    }

    if (digit_count == 15 && (start == 34 || start == 37))
    {
        printf("AMEX\n");
    }
    else if (digit_count == 16 && (start >= 51 && start <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((digit_count == 13 || digit_count == 16) && start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
