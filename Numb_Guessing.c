/*
NUMBER GUESSING GAME
A program that allows a user to guess a number between 1-10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

const int DEFAULT_VALUE = 10;
const char STOP = 'S';  /// a character used to stop the game and go back to the menu
const char CONTINUE = 'C'; /// a character used to continue the game if the input is invalid or the guess input is incorrect.

///Displays the menu
void displayMenu(){
    printf("Press 1 to play a game");
    printf("Press 2 to change the max number");
    printf("Press 3 to quit");
}

//Checks for input. Returns an appropriate input
char inputValid(){
    char d;
    fflush(stdout);
    d = getchar();
    while(!(d == '1' || d == '2' || d == '3')){
        printf("Input invalid. Try again..\n");
        fflush(stdout);
        d = getchar();
    }
    return d;
}

char option_1(int max_value, int rand_num){
    
    int guess_n;
    char valid;
    printf("Enter a number(1 - %d): ", max_value);
    fflush(stdout);
    valid = scanf("%d", guess_n) ? 'Y' : 'N';
    if(valid == 'N'){
        char c = getchar();
        if(c == 'q' || c == 'Q')
            return STOP;
        printf("Invalid input");
        return CONTINUE;
    }
    else{
        if(guess_n == rand_num){
            printf("Congratulation! You have guessed %d right!", guess_n);
            return STOP;
        }
        else if(guess_n > rand_num)
            printf("Number too high. Try again.");
        else 
            printf("Number too low. Try again.");
        
        return CONTINUE;

    }
}

char option_1D(int rand_num){
    return option_1(DEFAULT_VALUE, rand_num);
}

void Game(){
    srand(time(NULL));
    int n = rand() % DEFAULT_VALUE + 1;
    option_1D(n);
}

int main(){
    Game();
    return 0;
}