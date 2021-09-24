#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

int main(){
    
    time_t t; 
    // random time 
    srand((unsigned) time(&t));
    // declare file 
    FILE *file;
    //set static maxNumber
    static int maxNumber = 10;
    // select guessNumber to be random and between highest allowed value 
    int guessNumber = rand() % maxNumber; 
    // print out choice menu for the user to choose
    printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
    // declare and intialize user input at 0 
    int userInput = 0; 
    // take in user input for the menu selection 
    scanf("%d", &userInput);
    char userGameGuess[100]; 
    int guessValue; 
    if(userInput == 1){
        // if they picked 1, begin this if statement 
        printf("Pick a number between 1 and %d. ", maxNumber); 
        scanf("%s", &userGameGuess);
        if(strcmp("q", userGameGuess) == 0){
            main(); 
        }
        else{
            guessValue = atoi(userGameGuess); 
        }
        // if the user guess is not equal to the correct answer
        while(guessValue != guessNumber){
            //if the user input is less than the guess number, request a larger number
            while(guessValue < guessNumber){
                printf("Pick a larger number!\n");
                // take user input 
                scanf("%s", &userGameGuess);
                if(strcmp("q", userGameGuess) == 0){
                    main(); 
                } 
                guessValue = atoi(userGameGuess); 
            }
            //if user guess is larger than guess number, request a smaller number 
            while(guessValue > guessNumber){
                printf("Pick a smaller Number!\n");
                // take user input as a string
                scanf("%s", &userGameGuess);
                // if user input string = "q" recursive call main()
                if(strcmp("q", userGameGuess) == 0){
                // recursive call 
                main(); 
                }   
                // String to int if "q" wasn't inputted 
                guessValue = atoi(userGameGuess);
            }
        }
        //player got the number correct
        printf("Congraulations! You got the right number!\n");
        // recursive call
        main(); 
    }
    // if user input =2, move into menu to change the max number 
    else if(userInput == 2){
        // declare new temp integer 
        int tempnumber; 
        // request a new max number 
        printf("Pick a new Max Number! ");
        // take user input for the temp integer 
        scanf("%d", &tempnumber); 
        // requires the temp integer to be positive and within int range 
        if(tempnumber>0 && tempnumber< INT_MAX){
            // replace max number with the temp integer 
            maxNumber = tempnumber; 
            // send message declaring new max number is made 
            printf("\nThe New Max Number is %d\n", maxNumber); 
            // recursive call 
            main();
        }
        else{
            // number input was not within the parameters, so it returns 
            printf("Out of Bounce! The Max Number will stay as %d",maxNumber);
            // return to menu, recursive call 
            main(); 
        }
        
    }
    // if input is 3, exit the program 
    else if(userInput == 3){
        printf("\nGood Bye!");
        return 0; 
    }
    return 0; 
}