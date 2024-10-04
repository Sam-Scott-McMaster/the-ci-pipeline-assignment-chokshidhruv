#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Dhruv Chokshi - 400507527; October 3rd 2024
// Program reads user inputted arguments using argc and argv[] to output quiz questions/answers
//
// If an invalid flag is entered, it displays the displayBadFlag() function. 
// If the --help flag is provided, it displays the displayHelpInfo() function.

//Function made to display information when an invalid flag is provided
void displayBadFlag(){
    printf("Usage: quiz [-#] [<answer>]\n");
    printf("Try 'quiz --help' for more information.\n");
}

//Function made to display the help info when '--help' flag is provided
void displayHelpInfo(){
    printf("Usage: quiz [-#]... [<answer>]...\n");
    printf("Asks quiz question or check if quiz question is right or wrong to standard output.\n");
    printf("-1, --quiz-question-1    asks quiz question 1 or checks for answer with third argument.\n");
    printf("-2, --quiz-question-2    asks quiz question 2 or checks for answer with third argument.\n");
    printf("-3, --quiz-question-3    asks quiz question 3 or checks for answer with third argument.\n");
    printf("--help,                  display this help and exit\n");
    printf("Examples:\n");
    printf("quiz -2 ls  Outputs if the answer ls is correct or incorrect to quiz question 2.\n");
    printf("quiz -1     Outputs quiz question 2 to standard output.\n");
}

//Main function that handles logic of program
int main(int argc, char *argv[]){
    //argc checks for argument count - how many aguments are provided
    //*argv[] holds command-line argument value
    
    if (argc < 2){ //Checks if there are fewer than two arguments
        displayBadFlag();
        return EXIT_FAILURE;
    }


    if (strcmp(argv[1], "--help") == 0){ //Checks if the --help flag is provided as the second argument
        displayHelpInfo();
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-1") == 0){ //Checks if -1 flag is provided and handles first question logic
        if (argc == 2){
            printf("What command is used to display the current working directory in Linux?\n");
        }
        else if (argc == 3){
            if (strcmp(argv[2], "pwd") == 0){
                printf("That is correct, pwd displays your current working directory!\n");
            }
            else{
                printf("Incorrect, try again!\n");
            }
        }
        else{
            displayBadFlag();
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-2") == 0){ //Checks if -2 flag is provided and handles second question logic
        if (argc == 2){
            printf("What is the return type for a function that does not return a value in C?\n");
        }
        else if (argc == 3){
            if (strcmp(argv[2], "void") == 0){
                printf("That is correct, void is used when a function returns nothing! \n");
            }
            else{
                printf("Incorrect, try again!\n");
            }
        }
        else {
            displayBadFlag();
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-3") == 0){ //Checks if -3 flag is provided and handles third question logic
        if (argc == 2){
            printf("What command is used to get all required updates from a remote repository? Note: Make sure to add the answer using double quotation marks! Ex. \"git status\"\n");
        }
        else if (argc == 3){
            if (strcmp(argv[2], "git pull") == 0){
                printf("That is correct! The command git pull is used to pull all changes from a remote repository into your local repository!\n");
            }
            else{
                printf("Incorrect, but that was easy! Try again!\n");
            }
        }
        else {
            displayBadFlag();
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

}
