#include<stdio.h>
int count=0,data=2,check=2,n;
void prima(int a){
    if(data==check){
        printf("%d ",data);
        check=2;
        count++;
        if(count<n){
            prima(++data);
        }
    }else if(data%check==0){
        check=2;
        prima(++data);
    }else{
        check++;
        prima(data);

    }
}
int main(){
    scanf("%d", &n);
    prima(data);
}