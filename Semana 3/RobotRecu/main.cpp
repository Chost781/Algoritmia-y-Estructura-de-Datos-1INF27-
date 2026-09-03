#include <iostream>
#include <climits>
#define COL 4

using namespace std;

int robot(int x, int y,int n,int m,
    int tablero[][COL]) {
    int der=INT_MIN,aba=INT_MIN;
    cout <<x<<" "<<y <<endl;
    if (x==n-1 and y==m-1) return tablero[x][y];
    if (y+1<m) der=robot(x,y+1,n,m,tablero);
    if (x+1<n) aba=robot(x+1,y,n,m,tablero);
    cout <<x<<" "<<y <<endl;
    if (der>aba) return tablero[x][y]+der;
    return tablero[x][y]+aba;
}

int main() {
    int n=3;
    int m=4;

    int tablero[][COL]={
        {2,5,10,3},
        {3,6,2,1},
        {4,2,5,2}
    };
    cout << robot(0,0,n,m,tablero);

    return 0;
}
