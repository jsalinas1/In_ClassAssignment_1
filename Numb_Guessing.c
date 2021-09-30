/*
NUMBER GUESSING GAME
A program that allows a user to guess a number between 1-10
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    d = getchar()
    while(!(d == '1' || d == '2' || d == '3')){
        printf("Input invalid. Try again..\n");
        fflush(stdout);
        d = getchar();
    }
    return d;
}

void option_1(){
    int guess_number = ;
    printf("Enter a number between 1 and 10: ");
    fflush(stdout);
    scanf("%d", guess_number);
    while(guess_number < 1 || guess_number > 10){
        printf("Input invalid. Try again..\n");
        fflush(stdout);
        scanf("%d", guess_number);
    }
}
int main(){
    return 0;
}