#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    //printf("get_cents is %i \n", cents);
    //if input was 30, here ans will be 30. when printed it showed 300 because the last 0 is of return 30 from the remaining funcs

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    // here quarters * 25 gets executed first, then result is subtracted from cents and new value is updated in cents

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("how much change? ");
    }
    while(cents < 1);
    return cents;
}

int calculate_quarters(int cents)
{
    return cents/25;
}

int calculate_dimes(int cents)
{
    return cents/10;
}

int calculate_nickels(int cents)
{
    return cents/5;
}

int calculate_pennies(int cents)
{
    return cents/1;
}

//WHY ANSWER IS CORRECT WHEN INPUT GIVEN IS 5. HOW DID THE quaters func did the math
