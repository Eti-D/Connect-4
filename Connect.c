#include <stdio.h>
#define Width 7
#define Height 6
#define Dimension 2
#define RED     "\x1b[31m"
#define BLUE    "\x1b[34m"

#define RESET   "\x1b[0m"


void print_game(char board[Width][Height]){
    
    for(int i = 0;i<Width;i++){
        printf("|");
        for(int j = 0;j<Height;j++){
            if(board[i][j]=='r')
            printf(RED   "%c"  RESET  "|" , board[i][j]);
            else if(board[i][j]=='b')
            printf(BLUE   "%c"  RESET  "|" , board[i][j]);
            else
            printf("%c|" , board[i][j]);
        }
        printf("\n");
    }
    printf("===========\n");
}


void populate_board(char board[Width][Height]){

    for(int i = 0;i<Width;i++){
        for(int j = 0;j<Height;j++){
            board[i][j] = '0';
        }
    }
}


void place(char colour,int column, char board[Width][Height]){

    column --;
    int i = 0;
    while(i<7){
        if(board[i][column]!='0')
            break;
        i++;
    }
    board[i-1][column] = colour;
}
int check_row_counter(int row_count[6]){
    for(int i = 0;i<7;i++){
        if(row_count[i]<7)
            return 1;
        else 
            return 0;
    }
}


int main(){

    char board[Width][Height];
    populate_board(board);


    int input;
    char col;
    int counter = 1;
    while(1){
        input = 9;
        print_game(board);
        if(counter%2==0){
            printf(BLUE"Enter your move: \n" RESET); 
            col = 'b';}
        else{
            printf(RED"Enter your move: \n" RESET); 
            col = 'r';
        }
        scanf("%d",&input);

        
        if(input<1){
            printf("enter a number between 1 and 6");
            counter--;
        }

        else if(input>7){
            break;
        }

        place(col,input,board);
        counter++;
        }
    }
