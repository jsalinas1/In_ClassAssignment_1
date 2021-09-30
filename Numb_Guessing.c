/*
NUMBER GUESSING GAME
A program that allows a user to guess a number between 1-10
Outline:
- displayMenu() - This one outputs the menu of the guessing game
- inputValid() - This one make sures that the user is entering the correct input. It returns a character
that is associated with the input.
- option_1() - Lets the user choose the random number. If q is entered, the program goes back to the menu. 
It also checks and let the user know about invalid input including negative input, incorrect guessed number,
and also an overbound guessed input.
- Game() - Takes care the input choices using switch statements. This is where n number is randomized and passed to
option_1(). This function also accepts the pointer parameter of the max_value just in case it is changed.
- max_input() - This is for option 2. This changes the maximum input and it saved that value in the file called
"max_number.txt" If the file already exist, it deletes that file, create a new one where the value will be saved.
This also make sure the user does not enter a negative value or an overbound value.
- file_check() - returns a max_value from the file. If the file doesn't exist, then return the default_value
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

const int DEFAULT_VALUE = 10;
const char STOP = 'S';  /// a character used to stop the game and go back to the menu
const char CONTINUE = 'C'; /// a character used to continue the game if the input is invalid or the guess input is incorrect.
const char TERMINATE = 'T'; /// Terminates a program once done playing the game

void clear_bufferinput(){ /// This function clears all of the buffer in the input
    while(getchar() != '\n');
}
///Displays the menu
void displayMenu(){
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");
    printf("***********************************\n");
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
        if(c == 'q' || c == 'Q'){
            printf("\n\n");
            return STOP;
        }
        printf("Invalid input. Try Again.\n");
        return CONTINUE;
    }
    else{
        if(guess_n == rand_num){
            printf("Congratulation! You have guessed %d right!\n\n", guess_n);
            return STOP;
        }
        else if(guess_n > max_value)
                printf("Number entered is way too high! Must be between 1 and %d. Try again.\n", max_value);
        else if(guess_n < 1)
                printf("Invalid input! Must be between 1 and %d. Try again.\n", max_value);
        else if(guess_n > rand_num)
            printf("Number too high. Try again.\n");
        
        else
            printf("Number too low. Try again.\n");
        
        
        return CONTINUE;

    }
}




int max_input(){
    int value;
    FILE *fp;
    printf("Enter the maximum value greater than 1: ");
    fflush(stdout);
    scanf("%d", &value);
    while(value < 1 || value > INT_MAX){
        printf("Invalid. Enter the maximum value greater than 1: ");
        fflush(stdout);
        scanf("%d", &value);
    }
    fp = fopen("max_number.txt", "w+");
    fprintf(fp, "%d", value);
    fclose(fp);
    printf("\n\n");
    return value;
}
void Game(int *max_val){
    srand(time(NULL));
    int n;
    char end_program;
    do{
        displayMenu();
        
        switch(inputValid()){
            case '1' : {
                n = rand() % (*max_val) + 1;
                char t;
                do{
                    t = option_1(*max_val,n);
                }while(t == CONTINUE);
                end_program = CONTINUE;
                break;
             }
            case '2': {
                *max_val = max_input();
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

int file_Check(){
    int save = 3;
    FILE *fp;
    if(fp = fopen("max_number.txt", "r")){
        fscanf(fp, "%d", &save);
        fclose(fp);
        return save;
    }
    return DEFAULT_VALUE;
    
}


int main(){
    int maximum_val = file_Check(); /// Sets a value for maximum if it's saved in file
    Game(&maximum_val);
    return 0;
}