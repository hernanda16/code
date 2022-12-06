#include <iostream>
#include <math.h>
 
using namespace std;
//konversi derajat ke radian
#define PI 3.14159265359
#define rad PI/180.0
 
void SpeedCalc(float mat[4][3], int speed_vector[3], double motor[4]){
    for(int i=0; i<4 ; i++){
        motor[i] = 0;
    }
    for(int i=0; i<4 ;i++){
        for(int j=0 ; j<3 ; j++){
            motor[i] += mat[i][j] * speed_vector[j]*sinf(45.0*rad);
        }
    }
}
int main(){
    int input[3];
    double speed_motor[4];
    float matrix[4][3] ={
                        {cosf(45.0*rad), sinf(45.0*rad), 1},
                        {cosf(135.0*rad), sinf(135.0*rad), 1},
                        {cosf(225.0*rad), sinf(225.0*rad), 1},
                        {cosf(315.0*rad), sinf(315.0*rad), 1}
                        };
    cin>>input[0];
    cin>>input[1];
    cin>>input[2];
    SpeedCalc(matrix, input, speed_motor);
    for(int i=0; i<2 ;i++){
        printf("%.2lf ", speed_motor[i]);  
    }
    for(int i=0; i<2 ;i++){
        if(speed_motor[i]!=0){
            printf("%.2lf ", -speed_motor[i]);
        }else{
            printf("%.2lf ", speed_motor[i]);
        }
    }printf("\n");
    double cek;
    cek=sqrt(pow(speed_motor[0],2)+pow(speed_motor[1],2));
    if(cek<abs(speed_motor[0]+abs(speed_motor[1]))){
        printf("%.2lf", cek/sinf(45.0*rad));
    }else{
        printf("%.2lf", cek);
    }
    return 0;
}
