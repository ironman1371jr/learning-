#include <stdio.h>
#include <cs50.h>

void odd(int n);
void even(int n);

int main (argc, argv[])
{
    int n = argv[2];
    int arrayy[n];

    for(int i=0; i<n; i++)
    {
        arrayy[i] = get_int("what value do you want at index %i: ",i);
    }

    for(int i=0; i<n; i++)
    {
        odd(arrayy[i]);
    }
}

void odd(int n)
{
    if(n % 2 != 0)
    {
        odd(arrayy[i]);
    }
    else
    {
        even(n)
    }
}

void even(int n)
{
    if(arrayy[i] % 2 == 0)
    {
        even(arrayy[i]);
    }
}