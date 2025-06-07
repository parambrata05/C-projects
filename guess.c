#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, randomNumber;
    int score = 0;
    char playAgain = 'y';

    srand(time(0));

    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess the number between 1 and 10.\n");

    while (playAgain == 'y' || playAgain == 'Y') {
        randomNumber = rand() % 10 + 1;

        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        if (guess == randomNumber) {
            printf("Correct! You guessed the number.\n");
            score++;
            printf("Your current score: %d\n", score);
        } else {
            printf("Wrong! The correct number was %d.\n", randomNumber);
            printf("Game over. Your final score: %d\n", score);
            break;
        }
    }

    return 0;
}
