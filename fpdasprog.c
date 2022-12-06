#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char data[3][3];
int baris,kolom;
int count=0,in;
void init(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            data[i][j]='.';
        }
    }
}

void hasil();
void print();
void menu();

void cek(){
    if(data[baris-1][kolom-1]=='.'){
        switch(count){
            case 0:
                data[baris-1][kolom-1]='O';
                break;
            case 1:
                data[baris-1][kolom-1]='X';
                break;
        }
    }else{
        if(count==0){
            count=1;
        }else{
            count=0;
        }
    }
}

void print(){
    system("clear");
    printf("TIC TAC TOE\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c ",data[i][j]);
        }printf("\n");
    }
}

void case1(){
    if(count==0){
        printf("Player 1:\ninput [baris kolom] : ");
        scanf("%d %d", &baris, &kolom);
        count=1;
        cek();
    }else if(count==1){
        printf("Player 2:\ninput [baris kolom] : ");
        scanf("%d %d", &baris, &kolom);
        count=0;
        cek();
    }
    print();
    hasil();
}

void case2(){
    if(count==0){
        printf("Player 1:\ninput [baris kolom] : ");
        scanf("%d %d", &baris, &kolom);
        count=1;
        cek();
        
    }else if(count==1){
        srand(time(0));
        baris=rand()%3;
        kolom=rand()%3;
        count=0;
        cek();
    }
    print();
    hasil();
}

void hasil(){
    char cekk; 
    if(count==0){
        cekk='O';
    }else{
        cekk='X';
    }
    if((data[1][1]==cekk&&data[0][1]==cekk&&data[2][1]==cekk)||
        (data[1][1]==cekk&&data[1][0]==cekk&&data[1][2]==cekk)||
        (data[1][1]==cekk&&data[0][0]==cekk&&data[2][2]==cekk)||
        (data[1][1]==cekk&&data[0][2]==cekk&&data[2][0]==cekk)||
        (data[0][0]==cekk&&data[0][1]==cekk&&data[0][2]==cekk)||
        (data[0][0]==cekk&&data[1][0]==cekk&&data[2][0]==cekk)||
        (data[2][0]==cekk&&data[2][1]==cekk&&data[2][2]==cekk)||
        (data[2][2]==cekk&&data[1][2]==cekk&&data[0][2]==cekk)){
            if(count==0){
                printf("PLAYER 2 WIN\n");
            }else{
                printf("PLAYER 1 WINS\n");
            }
        }else{
            if(data[0][0]=='.'||data[0][1]=='.'||data[0][2]=='.'||
                data[1][0]=='.'||data[1][1]=='.'||data[1][2]=='.'||
                data[2][0]=='.'||data[2][1]=='.'||data[2][2]=='.'){
                    switch(in){
                        case 1:case1();break;
                        case 2:case2();break;
                        default:break;
                    }
                }else{
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

void menu(){
    printf("TIC TAC TOE\n");
    printf("Menu :\n1. Player vs. Player\n2. Player vs. Ez_Bot\n3. Player vs. Hell_Bot\nInput : ");
    scanf("%d", &in);
    if(in==1){
        print();
        case1();
    }else if(in==2){
        print();
        case2();
    }
}

int main(){
    init();
    menu();
}