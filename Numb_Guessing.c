/*
NUMBER GUESSING GAME
A program that allows a user to guess a number between 1-10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

const int DEFAULT_VALUE = 10;
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

void option_1(int max_value){
    int guess_n;
    char valid;
    printf("Enter a number(1 - %d): ", max_value);
    fflush(stdout);
    scanf("%d", &guess_n);
    printf("%c\n",getchar());
}

void option_1D(){
    option_1(DEFAULT_VALUE);
}


int main(){
    option_1D();
    return 0;
}