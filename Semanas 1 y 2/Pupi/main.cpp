#include <iostream>
#define N 6
#define M 5
#define NUMMOV 8
using namespace std;

void cargamovimientos(int mov[NUMMOV][2]) {
    mov[0][0]=-1; mov[0][1]=0;
    mov[1][0]=-1; mov[1][1]=1;
    mov[2][0]=0;  mov[2][1]=1;
    mov[3][0]=1;  mov[3][1]=1;
    mov[4][0]=1;  mov[4][1]=0;
    mov[5][0]=1;  mov[5][1]=-1;
    mov[6][0]=0;  mov[6][1]=-1;
    mov[7][0]=-1;  mov[7][1]=-1;
}

void buscaletra(char tablero[N][M],char *palabra,
    int mov[NUMMOV][2],int m,int fil,int col) {

    

}
void buscapalabras(char tablero[N][M],char *palabra,
    int mov[NUMMOV][2],int m) {

    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            buscaletra(tablero,palabra,mov,m,i,j);


}


int main() {
    char tablero[N][M]={
        {'D','I','R','O','L'},
        {'S','O','D','O','S'},
        {'I','O','A','E','R'},
        {'L','D','R','I','J'},
        {'I','O','O','K','E'},
        {'A','P','D','L','I'}
    };
    int mov[NUMMOV][2];
    char palabra[]={'D','O','L'};
    int m=sizeof(palabra)/sizeof(palabra[0]);
    cargamovimientos(mov);
    buscapalabras(tablero, palabra,mov,m);

    return 0;
}
