#include <cs50.h>
#include <stdio.h>

        //bool prototypes
bool is_valid_amex(long credit_card, int num_digits);
bool is_valid_master(long credit_card, int num_digits);
bool is_valid_visa(long credit_card, int num_digits);

        //int prototypes
int number_of_digits(long credit_card);
int every_other_digit(long credit_card);
int multiply_and_sum(int las_digit);

int main(void)
{
    long credit_card = get_long("Number: ");
    int sum_every_other_digit = every_other_digit(credit_card);
    int num_digits = number_of_digits(credit_card);
    bool amex = is_valid_amex(credit_card, num_digits);
    bool master = is_valid_master(credit_card, num_digits);
    bool visa = is_valid_visa(credit_card, num_digits);

    if (sum_every_other_digit % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
bool is_valid_amex(long credit_card, int num_digits)
{
    int first_2_digits = credit_card / 10000000000000;
    if ((num_digits == 15) && (first_2_digits == 34 || first_2_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_valid_master(long credit_card, int num_digits)
{
    int first_2_digits = credit_card / 100000000000000;
    if ((num_digits == 16) && (first_2_digits > 50 && first_2_digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_valid_visa(long credit_card, int num_digits)
{
    if (num_digits == 13)
    {
        int first_digit = credit_card / 1000000000000;
        if (first_digit == 4)
        {
            return true;
        }
    }
    else if (num_digits == 16)
    {
        int first_digit = credit_card / 1000000000000000;
        if (first_digit == 4)
        {
            return true;
        }
    }
    return false;
}
int number_of_digits(long credit_card)
{
    int count = 0;
    while (credit_card > 0)
    {
        count = count + 1;
        credit_card = credit_card / 10;
    }
    return count;
}
int every_other_digit(long credit_card)
{
    int sum = 0;
    bool is_alternate_digit = false;
    while (credit_card > 0)
    {
        if (is_alternate_digit == true)
        {
            int last_digit = credit_card % 10;
            int product = multiply_and_sum(last_digit);
            sum = sum + product;
        }
        else
        {
            int last_digit = credit_card % 10;
            sum = sum + last_digit;
        }
        is_alternate_digit = !is_alternate_digit;
        credit_card = credit_card / 10;
    }
    return sum;
}
int multiply_and_sum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum = sum + last_digit_multiply;
        multiply = multiply / 10;
    }
    return sum;
}
