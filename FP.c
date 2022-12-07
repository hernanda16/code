#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char pos[9];
int x,y,count=0,in;
void hasil();
void menu();
void mode1();
void mode2();
void init(){
    for(int i=0;i<9;i++){
        pos[i]='.';
    }
}
void print(){
    system("clear");
    printf("TIC TAC TOE\n");
    for(int i=0;i<9;i++){
        printf("%c ",pos[i]);
        if(i==2||i==5||i==8){
            printf("\n");
        }
    }
}
void cek(){
    if(pos[(x-1)*3+y-1]=='.'){
        switch(count%2){
            case 0:
                pos[(x-1)*3+y-1]='X';
                break;
            case 1:
                pos[(x-1)*3+y-1]='O';
                break;
        }
        hasil();
    }else{
        switch(in){
            case 1:mode1();break;
            default:break;
        }
    }
}
void hasil(){
    char var; 
    if(count%2==0){
        var='X';
    }else{
        var='O';
    }
    if((pos[4]==var&&pos[1]==var&&pos[7]==var)||
        (pos[4]==var&&pos[3]==var&&pos[5]==var)||
        (pos[4]==var&&pos[0]==var&&pos[8]==var)||
        (pos[4]==var&&pos[2]==var&&pos[6]==var)||
        (pos[0]==var&&pos[1]==var&&pos[2]==var)||
        (pos[0]==var&&pos[3]==var&&pos[6]==var)||
        (pos[6]==var&&pos[7]==var&&pos[8]==var)||
        (pos[8]==var&&pos[5]==var&&pos[2]==var)){
            if(count%2==0){
                print();
                printf("PLAYER 1 WIN\n");
            }else{
                print();
                printf("PLAYER 2 WIN\n");
            }
        }else{
            if(count<8){
                count++;
                switch(in){
                    case 1:mode1();break;
                    case 2:mode2();break;
                    default:break;
                }
            }else{
                print();
                printf("DRAW\n");
            }
        }
        printf("PLAY A NEW GAME !!!\n<press 1 to continue>\n");
        scanf("%d", &in);
        if(in==1){
            system("clear");
            count=0;
            init();
            menu();
        }
        
}
void mode1(){
    print();
    (count%2==0)?printf("Player 1:\ninput [baris kolom] : "):printf("Player 2:\ninput [baris kolom] : ");
    scanf("%d %d", &x, &y);
    cek();
}
void mode2(){
    int comp;
    int temp=0;
    print();
    if(count%2==0){
        printf("Player:\ninput [baris kolom] : ");
        scanf("%d %d", &x, &y);
        cek();
    }else{
        srand(time(0));
        comp=rand()%(9-count);
        for(int i=0;i<9;i++){
            if(pos[i]=='.'){
                temp++;
                if(temp==comp){
                    x=i/3+1;
                    y=i%3+1;
                    cek();
                }
            }
        }
    }
}
void menu(){
    printf("TIC TAC TOE\n");
    printf("Menu :\n1. Player vs. Player\n2. Player vs. Ez_Bot\n3. Player vs. Hell_Bot\nInput : ");
    scanf("%d", &in);
    if(in==1){
        mode1();
    }else if(in==2){
        mode2();
    }
}

int main(){
    init();
    menu();
}