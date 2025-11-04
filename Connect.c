#include <stdio.h>
#define Width 6
#define Height 6
#define Dimension 2
#define RED     "\x1b[31m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"


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


int possible_next_move(int current_position[Dimension], int move[Dimension]){
    for(int i=0; i<Dimension;i++){
        if(current_position[i] + move[i]<0 || current_position[i] + move[i]){
            return 0;
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

int check_row_counter(int row_count[Width]){
    int overloadedRow = -1;
    for(int i = 0;i<Dimension;i++){
        if(row_count[i]>=7){
            overloadedRow = row_count[i];
            break;
        }
        }
    return overloadedRow;

}


int main(){

    char board[Width][Height];
    int board_tracker[6] = {0,0,0,0,0,0};
    int row_inputed = 9;
    int player = 0;
    char col;
    populate_board(board);

    while(1){
        print_game(board);
        
        if(player%2==0){
            printf(RED"Enter your move: \n" RESET);
            col = 'r';
        }
        else{
            col = 'b';
            printf(BLUE"Enter your move: \n" RESET);
        }
        scanf("%d",&row_inputed);

        if(row_inputed>0 && row_inputed<=7 && board_tracker[row_inputed-1]<=6){
            board_tracker[row_inputed-1] ++;
            place(col,row_inputed,board);
        }
        else{
            player --;
            printf("\nEnter another number\n");
        }
        player++;
        printf("\n player: %d \n",player);
    }
}

