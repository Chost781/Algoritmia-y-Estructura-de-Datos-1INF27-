#include <iostream>
#define N 6
#define M 6
using namespace  std;
int buscaunos(int x,int y,int x1,int y1,
    int x2,int y2,int mapa[N][M]) {
    int cont=0;
    if (x>=N or x<0 or y>=M or y<0)
        return 0;
    if (mapa[x][y]==1 and x2==0 and y2==0)
        cont++;
    if (x2==0) {
        for (int i=x+1;i<N;i++)// hacia abajo
            cont+=mapa[i][y];
        for (int i=x-1;i>=0;i--)// hacia arriba
            cont+=mapa[i][y];
    }
    if (y2==0) {
        for (int i=y+1;i<M;i++)//hacia derecha
            cont+=mapa[x][i];
        for (int i=y-1;i>=0;i--)//hacia izquierda
            cont+=mapa[x][i];
    }

    cont+=buscaunos(x+x1,y+y1,x1,y1,x1,y1,mapa);
    return cont;
}

int main() {
    int mapa[][M]={{0,0,0,1,0,1},
               {0,0,1,0,0,0},
               {0,1,0,0,0,1},
               {1,0,0,0,0,0},
               {0,1,0,0,0,0},
               {0,0,0,0,1,0}};
    cout << buscaunos(3,2,0,1,0,0,mapa);
    return 0;
}