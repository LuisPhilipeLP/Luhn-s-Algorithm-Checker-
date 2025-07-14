#include <cs50.h>
#include <stdio.h>

long long int r;
long long int power_of_ten(int b);

int main(void)
{

    long long int number;
    long long int div;
    long long int size_counter;

    // prompt user
    do
    {
        number = get_long("Enter card number: ");
    }
    while (number < 1);
    // end prompt user

    // check how many digits
    int n_digits = 0;
    size_counter = number;

    while (size_counter >= 1)
    {
        n_digits++;
        size_counter /= 10;
    }
    // end of check how many digits

    char str_digit[n_digits + 1];
    sprintf(str_digit, "%lld",
            number); // convert lld int to string so it can fit in str_digit array

    // get every other digit from left to right while skipping the first
    int every_other = 0;
    long long int current_other_int;
    int sum_other = 0;

    for (int i = 0; i < (n_digits / 2); i++) // loop for every other digit
    {
        every_other += 2;

        char current_other_string[2] = {str_digit[n_digits - every_other], '\0'};
        sscanf(current_other_string, "%lld", &current_other_int); // convert from string to int

        int current_sum_other = current_other_int * 2;
        if (current_sum_other > 9)
        {
            int sum = (current_sum_other % 10) + (current_sum_other / 10);
            sum_other += sum;
        }
        else
        {
            sum_other += (current_other_int * 2);
        }
    }

    // end get every other digit from left to right while skipping the first

    // check if # of digits is even or odd
    int n_digits_remain;
    int remain;
    if ((n_digits % 2) == 0)
    {
        n_digits_remain = (n_digits / 2);
        remain = 1;
    }
    else
    {
        n_digits_remain = (n_digits / 2) + 1;
        remain = 0;
    }

    long long int current_remain_int;
    int sum_remain = 0;

    for (int i = 0; i < n_digits_remain; i++)
    {
        char current_remain_string[2] = {str_digit[remain], '\0'};
        sscanf(current_remain_string, "%lld", &current_remain_int);
        remain += 2;
        sum_remain += current_remain_int;
    }

    // loop to define ndigits (the # of every other digits)
    int total = sum_other + sum_remain;
    long long int first_digits_int;

    if (total % 10 == 0)
    {
        // get first two digits of number
        char first_digits_str[3] = {str_digit[0], str_digit[1], '\0'};
        sscanf(first_digits_str, "%lld", &first_digits_int);

        if (n_digits == 15 && ((first_digits_int == 37) || (first_digits_int == 34)))
        {
            printf("AMEX\n");
        }
        else if (n_digits == 16 &&
                 ((first_digits_int == 51) || (first_digits_int == 52) ||
                  (first_digits_int == 53) || (first_digits_int == 54) || (first_digits_int == 55)))
        {
            printf("MASTERCARD\n");
        }
        else if ((first_digits_int / 10) == 4 && ((n_digits == 16) || (n_digits == 13)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
