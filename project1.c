#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
int difficulty;
int n=1;
int laser_active=0;
int score=0;
int random_number_x;
int random_number_y;
int gerak=0;
int tembok=80;
char map[21][120];

int a, h, i, j, b;
int y=10,x=10;
int laser;
char player[3][6]={{' ','/' ,'\\','_' ,'_',' '},{'|',' ',' ','_','_','>'},{' ','\\','/',' ',' ',' '}};
void generate_map(){

    for(a=0; a<20; a++){
        for(b=0; b<120; b++){
            if(a==0||a==19){
                map[a][b]='_';
            }
            else{
                map[a][b]=' ';
            }
            for(i=-1; i<2; i++){
                for(j=-6; j<0; j++){
                    map[y+i][x+j]=player[i+1][j+6];
                }
            }

        }
    }
}
void generate_tembok(){
    if(gerak%(25+(difficulty-1)*-5)==0&&gerak!=0){
        tembok-=5;
    }
    for(h=2; h<19; h++){
        map[h][tembok]='|';
    }
}
void generate_laser(){
    if(laser_active==1){
        for(laser=x; laser<120; laser++){
            map[y][laser]='-';
        }
    }
}
void generate_random_number(){
    random_number_x=(rand()%(115-tembok+3))+tembok+2;
    random_number_y=(rand()%(18-2+1))+2;
}
void generate_enemy(){
    map[random_number_y][random_number_x]='0';
}
void display_map(){
    printf("\n\n");
    for(a=0; a<20; a++){
        for(b=0; b<120; b++){
                printf("%c",map[a][b]);
            }
            printf("\n");
        }
    printf("\nW: Atas \tS: Bawah \tA: Kiri \tD: Kanan \tSpace: Shoot\n\n");
    printf("Score: %d",score);
    }
void move_up(){
    if(y>1){
        y--;
    }
}
void move_down(){
    if(y<18){
        y++;
    }
}
void move_right(){
    if(x<112){
        x++;
    }
}
void move_left(){
    if(x>7){
        x--;
    }
}

int main(){
    char again[4];
    do{
        system("color 7");
        while((n==1)){
            printf("Welcome!!\n");
            do{
                printf("Select difficulty:\n(1)Easy\n(2)Normal\n(3)Hard\n(4)God Mode\nSelect with a number: ");
                scanf("%d",&difficulty);
                if((difficulty<1)||(difficulty>4)){
                    printf("Difficulty not available. Select between 1-4!\n\n");
                }
            }while((difficulty<1)||(difficulty>4));
            n=0;
        }

    char move;
    system("color 9");
    generate_random_number();
    do{
    system("cls");
    generate_map();
    generate_tembok();
    generate_laser();
    generate_enemy();
    display_map();
    move=getch();
    laser_active=0;
        switch(move){
            case 'w':
                move_up();
                break;
            case 's':
                move_down();
                break;
            case 'a':
                move_left();
                break;
            case 'd':
                move_right();
                break;
            case ' ':
                laser_active=1;
                break;


        }
        if((map[random_number_y][random_number_x-1])=='-'){
            generate_random_number();
            score++;
        }
        gerak++;

    }
    while(score<25&&(x<=tembok));
    if(score<25){
        system("cls");
        system("color 4");
        printf("Game Over\n\n");
    }
    else{
        system("color 2");
        system("cls");
        printf("Congratulation. You just winning the Game!!!!\n\n");

    }
    score=0;
    tembok=80;
    x=10;
    y=10;
    n=1;
    printf("Try again ? Yes/No\n\n");
        scanf("%sd",again);
        system("cls");
}
    while(strcasecmp(again,"yes")==0);

    printf("Thanks For Playing Our Game\n");

}

