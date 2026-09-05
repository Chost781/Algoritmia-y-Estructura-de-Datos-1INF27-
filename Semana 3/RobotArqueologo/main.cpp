#include <iostream>
#define N 10
#define M 10
using namespace std;

int buscaartefactos(int x,int y,int alcance,
    int direccion,char mapa[N][M]) {
    int cont=0;
    if (alcance<0) return 0;
    if (mapa[x][y]=='A') cont=1;
    mapa[x][y]='*';
    if (direccion<=0) {
        cont+=buscaartefactos(x-1,y-1,alcance-1,-1,mapa);
        cont+=buscaartefactos(x-1,y,alcance-1,-1,mapa);
        cont+=buscaartefactos(x-1,y+1,alcance-1,-1,mapa);
    }
    if (direccion>=0) {
        cont+=buscaartefactos(x+1,y-1,alcance-1,1,mapa);
        cont+=buscaartefactos(x+1,y,alcance-1,1,mapa);
        cont+=buscaartefactos(x+1,y+1,alcance-1,1,mapa);
    }
    return cont;
}
void muestra(char mapa[N][M]) {
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++)
            cout << mapa[i][j] << " ";
        cout << endl;
    }
}

int main() {
    char mapa[N][M]{};
    mapa[3][3]='A';
    mapa[3][4]='A';
    mapa[4][5]='A';
    mapa[5][4]='A';
    mapa[5][7]='A';
    mapa[7][5]='A';

    muestra(mapa);
    cout <<"Encontro: "<<buscaartefactos(5,5,3,0,mapa);
    muestra(mapa);
    return 0;

}
