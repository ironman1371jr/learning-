#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

string calculate(string pt, string key);

int main(int argc, string argv[])
{
    if(argc !=2)
    {
        printf("Not success, enter only one key\n");
        return 1;
    }
    else printf("Success!\n");

    string key = argv[1];

    for(int i=0; i<strlen(key); i++)
    {
        if(key[i] < '0' || key[i] > '9')
        {
            printf("invalid argument only numbers will be accepted\n");
            return 0;
        }
    }
    {
        printf("valid argument, it is a number\n");
    }

    string pt = get_string("enter the plain text: ");
/*
    int len = strlen(pt);
    int fkey = atoi(key);
    for(int i=0; i<len; i++)
    {
        if((pt[i] >= 'A' && pt[i] <= 'Z'))
        {
        //formula ciphertext = (plaintext + key)%26
        //convert key to integer(it is in string ascii format)  func: atoi ->stdlib.h
            printf("%c",((pt[i] +fkey -'A')%26)+'A');
        }
        else if(pt[i] >='a' && pt[i] <= 'z')
        {
            printf("%c",((pt[i] +fkey -'a')%26)+'a');
        }
        else
        {
            printf("%c",pt[i]);
        }
    }
    printf("\n");
*/
    string final = calculate(pt,key);
    printf("cipher text is %s\n", final);
}

string calculate(string pt, string key)
{
    string ffinal[50];

    int len = strlen(pt);
    int fkey = atoi(key);
    for(int i=0; i<len; i++)
    {
        if((pt[i] >= 'A' && pt[i] <= 'Z'))
        {
        //formula ciphertext = (plaintext + key)%26
        //convert key to integer(it is in string ascii format)  func: atoi ->stdlib.h
        ffinal[i] += ((pt[i] +fkey -'A')%26)+'A';
        }
        else if(pt[i] >='a' && pt[i] <= 'z')
        {
            ffinal[i] += ((pt[i] +fkey -'a')%26)+'a';
        }
        else
        {
            ffinal[i] += pt[i];
        }
    }

    return ffinal;
}
