#include <iostream>
#include <map>
#define N 6
#define M 11

using namespace std;

void imprime(int mapa[N][M]) {
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++)
            cout<<mapa[i][j]<<" ";
        cout << endl;
    }
}

void cavacueva(int x,int y,int mapa[N][M],int ini,int top) {
    if (x<0) return;
    mapa[x][y]=ini;
    if (y==M-1 and top) return;
    if (y==M-1 and !top) cavacueva(x-1,0,mapa,ini+1,top);
    else {
        if (x==0) top=1;
        if ((x==N-1 or mapa[x+1][y]!=0) and mapa[x][y+1]==0) cavacueva(x,y+1,mapa,ini,top);
        else
            if ((x==N-1 or mapa[x+1][y]!=0) and mapa[x][y+1]!=0)cavacueva(x-1,y,mapa,ini,top);
            else
                if ((mapa[x+1][y]==0))cavacueva(x+1,y,mapa,ini,top);
    }
}

int main() {
    int mapa[N][M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            mapa[i][j] = 0;

    mapa[N-1][5] = 9;
    mapa[N-2][5] = 9;
    mapa[N-3][5] = 9;

    cavacueva(N-1,0,mapa,1,0);
    imprime(mapa);
    return 0;
}