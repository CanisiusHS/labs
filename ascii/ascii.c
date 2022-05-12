#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c;
    // input from user
    do
    {
        printf("Please enter a lowercase alphabetical character: ");
        c = get_char();
    }
    // TODO: write a condition to verify the input is indeed a lowercase character
    while();  
    
    // TODO: convert the char to a capital and print

    printf("The capitalized letter is: %c\n", c);
}

