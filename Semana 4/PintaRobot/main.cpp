#include <iostream>
#define N 5

using namespace std;

void imprime(int n,int matriz[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

void pintar(int x,int y,int colini,int colfin,int n, int matriz[N][N]) {
    if (x<0 or x>n or y<0 or y>n or matriz[x][y] != colini)
        return;
    matriz[x][y] = colfin;
    pintar(x-1,y,colini,colfin,n,matriz);
    pintar(x,y+1,colini,colfin,n,matriz);
    pintar(x+1,y,colini,colfin,n,matriz);
    pintar(x,y-1,colini,colfin,n,matriz);
}


int main() {
    int matriz[N][N] {
        {1,1,2,2,3},
        {1,2,2,0,1},
        {0,2,1,3,1},
        {0,2,2,3,0},
        {0,0,1,2,3}};

    imprime(N, matriz);
    cout << endl;
    pintar(2,1,2,5,N,matriz);
    imprime(N, matriz);
    return 0;
}
