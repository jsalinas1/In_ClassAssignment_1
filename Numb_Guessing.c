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
const char TERMINATE = 'T'; /// Terminates a program once done playing the game

void clear_bufferinput(){
    while(getchar() != '\n');
}
///Displays the menu
void displayMenu(){
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");
    printf("********************************");
}

//Checks for input. Returns an appropriate input
char inputValid(){
    char d;
    fflush(stdout);
    scanf("%c", &d);
    while(!(d == '1' || d == '2' || d == '3')){
        printf("Input invalid. Try again..\n");
        fflush(stdout);
        d = getchar();
    }
    return d;
}

char option_1(int max_value, int rand_num){ ///Option 1 with customized max_value
    
    int guess_n;
    char valid;
    printf("Enter a number(1 - %d): ", max_value);
    fflush(stdout);
    valid = scanf("%d", &guess_n) ? 'Y' : 'N';
    if(valid == 'N'){
        char c = getchar();
        if(c == 'q' || c == 'Q')
            return STOP;
        printf("Invalid input\n");
        return CONTINUE;
    }
    else{
        if(guess_n == rand_num){
            printf("Congratulation! You have guessed %d right!\n\n", guess_n);
            return STOP;
        }
        else if(guess_n > max_value)
                printf("Number entered is way too high! Must be between 1 and %d. Try again.\n", max_value);
        else if(guess_n > rand_num)
            printf("Number too high. Try again.\n");
        
        else
            printf("Number too low. Try again.\n");
        
        
        return CONTINUE;

    }
}



char option_1D(int rand_num){  ///Default value to option 1
    return option_1(DEFAULT_VALUE, rand_num);
}
int max_input(){
    int value;
    printf("Enter the maximum value greater than 1: ");
    fflush(stdout);
    scanf("%d", &value);
    while(value < 1){
        printf("Invalid. Enter the maximum value greater than 1: ");
        fflush(stdout);
        scanf("%d", &value);
    }
}
void Game(){
    srand(time(NULL));
    int n;
    char end_program;
    do{
        displayMenu();
        
        switch(inputValid()){
            case '1' : {
                n = rand() % DEFAULT_VALUE + 1;
                char t;
                do{
                    t = option_1D(n);
                }while(t == CONTINUE);
                end_program = CONTINUE;
                break;
             }
            case '2': {
                char t;
                int max = max_input();
                n = rand() % max + 1;
                do{
                    t = option_1(max,n);
                }while(t == CONTINUE);
                end_program = CONTINUE;
                break;
            }
            case '3' : {
                printf("Thank you for playing!\n\n");
                end_program = TERMINATE;
                break;
            }
            default : break;
        }
        clear_bufferinput();
    }while(end_program != TERMINATE);

}



int main(){
    
    Game();
    return 0;
}