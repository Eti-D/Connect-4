#include <stdio.h>
#define Width 7
#define Height 6
#define Dimension 2
#define RED     "\x1b[31m"
#define BLUE    "\x1b[34m"

#define RESET   "\x1b[0m"

/*
int Four_in_a_row(char current_colour, int width,int height, char[width][height]){
    int Total_in_a_row =0;

    int current_position[Dimension] ={width, height};

    int next_position[Dimension];

    
    int possible_moves[2][] = {
        {-1,0},
        {-1,-1},
        {0,1},
        {-1,1},
        {0,1}
    };
    int current_movement[Dimension] = {0,0};

    int movement_counter = 0;

    while(Total_in_a_row<4 || (current_position[0] != 0 && current_position[1]!= 0)){
        if(movement_counter==5){
            movement_counter = 0;
        }
        next_position = {current_position[0] + possible_moves[movement_counter][0] , current_position[1] + possible_moves[movement_counter][1];


    }

}
*/
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
