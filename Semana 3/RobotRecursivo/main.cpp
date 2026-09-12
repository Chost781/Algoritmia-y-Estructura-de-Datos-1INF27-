#include <iostream>
#include <climits>
#define N 3
#define M 3

using namespace std;

int robot(int x,int y,int n,int m,int tablero[N][M]) {
    int derecha=INT_MIN,abajo=INT_MIN;
    if (x==n-1 and y==m-1) return tablero[x][y];
    if (y+1<m)  derecha=robot(x,y+1,n,m,tablero);
    if (x+1<n) abajo=robot(x+1,y,n,m,tablero);
    if (derecha>abajo) return tablero[x][y]+derecha;
    return tablero[x][y]+abajo;
}

int main() {
    int tablero[N][M]={
        {4,5,10},
        {16,2,4},
        {1,3,1}};
    cout <<"Cantidad de paquetes recogidos: "<< robot(0,0,N,M,tablero) << endl;
    return 0;
}
