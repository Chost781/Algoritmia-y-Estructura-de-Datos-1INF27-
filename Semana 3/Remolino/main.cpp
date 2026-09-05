#include <iostream>
#define N 5
#define M 5
using namespace std;

void recorre(int x,int y,int n,int m,
    int matriz[N][M]) {
    if (x>=n or y>=m)return;
    if (x==n-1 and y==m-1)
        cout << matriz[x][y] << " ";
    //aqui van los fors
    for (int i=y;i<m-1;i++)
        cout<<matriz[x][i]<<" ";
    for (int i=x;i<n-1;i++)
        cout<<matriz[i][m-1]<<" ";
    for (int i=m-1;i>y;i--)
        cout<<matriz[n-1][i]<<" ";
    for (int i=n-1;i>x;i--)
        cout<<matriz[i][y]<<" ";

    recorre(x+1,y+1,n-1,m-1,matriz);
}


int main() {
    int matriz[N][M];
    int cont=1;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            matriz[i][j]=cont++;

    recorre(0,0,N,M,matriz);

    return 0;
}
