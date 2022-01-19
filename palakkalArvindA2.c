/************************palakkalArvindA2.c**************
  
 Student Name: Arvind Palakkal Email Id: apalakka@uoguelph.ca
    Due Date: November 14th Course Name: CIS 1300
    I have exclusive control over this submission via my password.
    By including this statement in this header comment, I certify that:
    
    1) I have read and understood the University policy on academic
    integrity;

    2) I have completed the Computing with Integrity Tutorial on Moodle; and

    3) I have achieved at least 80% in the Computing with Integrity Self
    Test.

    I assert that this work is my own. I have appropriately acknowledged any
    and all material that I have used, whether directly quoted or
    paraphrased. Furthermore, I certify that this assignment was prepared by
    me specifically for this course.
    
 ********************************************************/
 /*********************************************************
    Compiling the program
    The program should be compiled using the following flags: -std=c99 -Wall 
    
    compiling:
    gcc -Wall -std=c99 palakkalArvindA2.c
    
    Running the Program
    Running: ./a.out
*********************************************************/
#include "givenA2.c"
#include "givenA2.h"

void createInitialBoard(char board[N][N]){
    int i;
    int j;
    
    for(i = 0; i < 3; ++i){//Add question marks to 2d Array
        for(j = 0; j < 3; ++j){
            board[i][j] = '?';
        }
    }
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("------------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("------------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

void readUserMove(int* userRow, int* userCol, int* stepsWon){
char temporaryRow[10], temporaryCol[10];//Used to prevent use of float inputs
    printf("Your move - enter numbers between 1 and 3");
    printf("\n");
    printf("\n");

    printf("Enter row number: ");
    scanf("%s", temporaryRow);
    *userRow = atoi(temporaryRow);// converts string to int 

    printf("Enter column number: ");
    scanf("%s", temporaryCol);
    *userCol = atoi(temporaryCol);

    *stepsWon = *stepsWon + 1;
     printf("\n");
}

void printCurrentBoard(char board[N][N]){
    printf("\n");
    printf("Current board now is:");
    printf("\n");
    printf("\n");
    
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("------------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("------------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

void computerPlaysRandom(int* computerRow , int* computerCol){
    *computerRow = rand() % 3;//Generates random Number for comp Columns 
    *computerCol = rand() % 3;//Generates random Number for comp Columns
}

int isInputValid(int input, int min, int max ){
    if((input >= min) && (input <= max)){
        return 1;
    }
    return 0;
}

int isBoardFull(char board[N][N]){
    int i;
    int j;
    
    for(i = 0; i < N; ++i){
        for(j = 0; j < N; ++j){
            if(board[i][j] == '?'){
                return 0;
            }
        }
    }
    return 1;
}

int gameWon(char board [N][N], char z){

    // Check rows
    if(board[0][0] == z  && board[0][1] == z  && board[0][2] == z){
        return 1;
    }
    ///*
   else if(board[1][0] == z  && board[1][1] == z  && board[1][2] == z){
        return 1;
    }
   else if(board[2][0] == z  && board[2][1] == z  && board[2][2] == z){
        return 1;
    }
    // Check columns
    if(board[0][0] == z  && board[1][0] == z  && board[2][0] == z){
        return 1;
    }
   else if(board[0][1] == z  && board[1][1] == z  && board[2][1] == z){
        return 1;
    }
    else if(board[0][2] == z  && board[1][2] == z  && board[2][2] == z){
        return 1;
    }
    // Check diagonals 
    else if(board[0][0] == z  && board[1][1] == z  && board[2][2] == z){
        return 1;
    }
    else if(board[0][2] == z  && board[1][1] == z  && board[2][0] == z){
        return 1;
    }
    //*/
    //else{

    return 0;
    //}
    

}

int computerPlaysToWin(char board[N][N], int* row , int* columns){
    int sumRow[N];
    int sumColumn[N];
    int sumLeftDiag;
    int sumRightDiag;
    int i;
    int j;
    
    all_sums(board, sumRow, sumColumn, &sumLeftDiag, &sumRightDiag);
    
    if(sumRightDiag == 8){//Checks if two consecutive O's in right Diagonal
        for(i = 0; i < 3; ++i){
            if(board[i][3-1-i] == '?'){
                *columns = i;
                *row = 3-1-i;
                return 1;
            }
        }
    }
    
    if(sumLeftDiag == 8){//Checks if two consecutive O's in left Diagonal
        for(i = 0; i < 3; ++i){
            if(board[i][i] == '?'){
                *columns = i;
                *row = i;
                return 1;
            }
        }
    }
    
    for(i = 0; i < 3; ++i){
        if(sumRow[i] == 8){
            
            for(j = 0; j < 3; ++j){//Checks two consecutive O's in Rows
                if(board[i][j] == '?'){
                    
                    *columns = j;
                    *row = i;
                    return 1;
                }
            }
        }
        
        if(sumColumn[i] == 8){//Checks two consecutive O's in Columns
            
            for(j = 0; j < 3; ++j){
                if(board[j][i] == '?'){
                    
                    *columns = i;
                    *row = j;
                    return 1;
                }
            }
            
        }
    }
    return 0;    
}

void all_sums(char board[N][N], int sumRow[N], int sumColumn[N], int* sumLeftDiag , int* sumRightDiag){
    int i;
    int j;
    
    *sumLeftDiag = 0;
    *sumRightDiag = 0;
    
    for(i = 0; i < 3; ++i){
        sumRow[i] = 0;
        sumColumn[i] = 0;
    }
    
    for(i = 0; i < 3; ++i){
        if(board[i][i] == 'X'){// If any X in left diagonal add 1 to variable
            *sumLeftDiag = *sumLeftDiag + 1;
        }
        else if(board[i][i] == 'O'){//If any O in left diagonal add 4 to var
            *sumLeftDiag = *sumLeftDiag + 4;
        }
        
        if(board[i][3-1-i] == 'X'){//If any X in right diagonal add 1 to var
            sumRightDiag = sumLeftDiag + 1;
        }
        else if(board[i][3-1-i] == 'O'){//If any O in right diagonal add 4
            sumRightDiag = sumRightDiag + 4;
        }
    }
    
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 3; ++j){
            
            if(board[i][j] == 'X'){//If any X in Rows and Columns add 1 to var 
                sumRow[i] += sumRow[i] + 1;
                sumColumn[j] += sumColumn[j] + 1;
            }
            else if(board[i][j] == 'O'){//If any O in Rows and Columns add 4
                sumRow[i] += sumRow[i] + 4;
                sumColumn[j] += sumColumn[j] + 4;
            }
        }
    }
}

int memberOf(int value, int someArray[N]){
    int i;
    
    for(i = 0; i < N; ++i){// checks if given value is in Array 
        if(value == someArray[i]){
            return 1;
        }
    }
    return 0;
}












































