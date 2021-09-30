/*
RESTURAUNT BILL
A program that computes the tax and tip on a restaurant bill for a patron
Output: Displays the meal cost, tax amount, tip amount, and total bill
Input: Tax and Tip in percentages and the chosen meal
- display_menu() - Displays the menus
- display_total() - Displays a total
- random_input() - returns a random input
- inputTax() - An input for tax. Let the user know to enter again if the values are negative
- inputTip() - An input for tip. Let the user know to enter again if the values are negative
- getTotal() - returns a calculated total of the bill

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum Meal{Salad, Soup, Sandwich, Pizza}; /// A set of meals
const float mealCost[] = {9.95, 4.55, 13.25, 22.35}; // Created an array of mealCost

//Displays the menu
void display_menu(){
    printf("The menu for today is\n 1. Salad: $%.2f\n 2. Soup: $%.2f\n 3. Sandwich: $%.2f\n 4. Pizza: $%.2f\n", 
            mealCost[Salad], mealCost[Soup], mealCost[Sandwich], mealCost[Pizza]); // By default, the integer value is incremented by 1 from 0
}

// Displays the bill
void display_total(float tax, float tip, float meal_Cost, float total){
    printf("\n**************BILL*************\n");
    printf("Cost: $%2.2f\n", meal_Cost);
    printf("Tax: $%2.2f\n", meal_Cost*(tax/100));
    printf("Tip: $%2.2f\n", meal_Cost*(tip/100));
    printf("Total: $%2.2f\n", total);

}

//Input validation for choosing a meal. Returns the value of the meal
float random_input(){
    srand(time(NULL));
    return mealCost[rand() % 4];
}

//Input validation for tax input. Returns value of that tax
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

//Input validation for tip input. Returns value of that tip
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

/// Calculates the total
float getTotal(float tax, float tip, float meal_Cost){
    return meal_Cost + (tax/100)*meal_Cost + (tip/100)*meal_Cost;
}

int main(){
    display_menu();
    float meal_Cost = random_input();
    float tax = inputTax();
    float tip = inputTip();
    float total = getTotal(tax, tip, meal_Cost);
    display_total(tax, tip, meal_Cost, total);
    
    return 0;
}