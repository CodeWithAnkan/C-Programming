#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = (rand() % 100) + 1;
    int no_of_guesses = 0;
    int guessed;

    // Print the random number
    // printf("Random Number between 1 and 100: %d\n", randomNumber);


    do{

    printf("Guess the number between 1 and 100: ");
    scanf("%d", &guessed);

    if (guessed > randomNumber)
    {
        printf("Lower Number please\n");
    } else if (guessed < randomNumber)
    {
        printf("Higher Number please\n");
    } else
    {
        printf("Congrats you guessed it right\n");
    }
    
    no_of_guesses ++;

    } while (guessed != randomNumber);
    
    printf("You guessed the number in %d guesses", no_of_guesses);
    

    return 0;
}