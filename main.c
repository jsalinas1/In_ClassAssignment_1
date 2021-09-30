/*
RESTURAUNT BILL
A program that computes the tax and tip on a restaurant bill for a patron
Output: Displays the meal cost, tax amount, tip amount, and total bill
Input: Tax and Tip in percentages and the chosen meal
*/

#include <stdio.h>
enum Meal{Salad, Soup, Sandwich, Pizza}; // Enumrated a set of meals

const float mealCost[] = {9.95, 4.55, 13.25, 22.35}; // Created an array of mealCost

//Displays the menu
void display_menu(){
    printf("The menu for today is\n 1. Salad: $%.2f\n 2. Soup: $%.2f\n 3. Sandwich: $%.2f\n 4. Pizza: $%.2f\n", 
            mealCost[Salad], mealCost[Soup], mealCost[Sandwich], mealCost[Pizza]); // By default, the integer value is incremented by 1 from 0
}

// Displays the bill
void display_total(){

}

//
float inputmeal_Valid(enum Meal *my_meal){
    int i;
    printf("Enter the meal to get(1 - 4): ");
    fflush(stdout);
    scanf("%d", &i);
    while(i < Salad + 1 || i > Pizza + 1){
        printf("Invalid input: Enter the meal to get(1 - 4): ");
        fflush(stdout);
        scanf("%d", &i);
    }
    *my_meal = i - 1;
    return mealCost[*my_meal];
}

float inputTax(){
    float tax;
    printf("Enter Tax Percent: ");
    fflush(stdout);
    scanf("%f", &tax);
    while(tax < 0){
        printf("Invalid input: Enter Tax Percent: ");
        fflush(stdout);
        scanf("%f", &tax);
    }
    return tax;
}

float inputTip(){
    float tip;
    printf("Enter Tip Percent: ");
    fflush(stdout);
    scanf("%f", &tip);
    while(tip < 0){
        printf("Invalid input: Enter tip Percent: ");
        fflush(stdout);
        scanf("%f", &tip);
    }
    return tip;
}

int main(){
    display_menu();
    enum Meal my_meal;
    float meal_Cost = inputmeal_Valid(&my_meal);
    float tax = inputTax();
    float tip = inputTip();


    printf("%.2f\n%.2f\n%.2f", meal_Cost, tax, tip);
    return 0;
}