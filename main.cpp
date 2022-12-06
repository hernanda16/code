#include<iostream>
using namespace std;
char arr[9][11];
char in;
int len;
int temp,y,x;
void cetak(){
    for(int i=0;i<9;i++){
        for(int j=0;j<11;j++){
            printf("%c", arr[i][j]);
        }printf("\n");
    }
}
void map(){
    for(int i=0;i<9;i++){
        for(int j=0;j<11;j++){
            arr[i][j]=' ';
        }
    }
    for(int i=0;i<11;i++){
        for(int j=0;j<9;j++){
            if(j%2==0){
                if(!(j==2&&(i==4||i==5))&&!(j==4&&(i==1||i==7||i==9))&&!(j==6&&i==4)){
                    arr[j][i]='#';
                }
            }else if(j==3&&(i==6||i==8)){
                arr[j][i]='#';
            }
        }
    }
    for(int i=0;i<9;i++){
        arr[i][0]='#';
        arr[i][10]='#';
    }
    arr[1][9]='O';
    arr[7][1]='P';
    cetak();
}
void mov(char a, int n, int p, int q){
    if(y==1&&x==9){
        arr[y][x]=arr[p][q];
        arr[p][q]=' ';
    }else{
        temp=arr[p][q];
        arr[p][q]=arr[y][x];
        arr[y][x]=temp;
        cetak();
    }
}
void pos(char a,int n,int p,int q){
    y=p,x=q;
    switch (a)
    {
    case 'd':
        x+=n;
        if(arr[y][x]!='#'){
            mov(a,n,p,q);
        }else{
            x-=n;
            cetak();
        }
        break;
    case 'a':
        x-=n;
        if(arr[y][x]!='#'){
            mov(a,n,p,q);
        }else{
            x+=n;
            cetak();
        }
        break;
    case 'w':
        y-=n;
        if(arr[y][x]!='#'){
            if(arr[y][x]!='#'){
                mov(a,n,p,q);
            }else{
                y+=n;
                cetak();
            }
        }else{
            y+=n;
            y--;
            cetak();
        }
        break;
    case 's':
        y+=n;
        if(arr[y][x]!='#'&&n<=1){
            mov(a,n,p,q);
        }else{
            y-=n;
            cetak();
        }
        break;
    default:
        cetak();
        break;
    }
    if(arr[1][9]!='P'){
        printf("in:");
        scanf("\n%c %d", &in, &len);
        pos(in,len,y,x);
    }else{
        cetak();
        printf("WIN");
    }

}
int main(){
    printf("out:\n");
    map();
    printf("in:");
    scanf("\n%c %d", &in, &len);
    printf("%c %d\n", in, len);
    pos(in,len,7,1);
}