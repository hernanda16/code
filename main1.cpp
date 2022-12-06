#include<iostream>
using namespace std;
class daftar{
    public:
    char artis[101];
    int tahun;
    char judul[101];
};
int main(){
    daftar lagu;
    scanf("%[^\n]s", lagu.artis);
    scanf("%[^\n]s", lagu.tahun);
    scanf("%[^\n]s", lagu.judul);
    printf("%s", lagu.artis);
    printf("%s", lagu.tahun);
    printf("%s", lagu.judul);
}