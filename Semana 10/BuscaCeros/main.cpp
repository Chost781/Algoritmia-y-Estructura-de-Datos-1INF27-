#include <iostream>

using namespace std;
int cuentaceros(int *arr, int ini,int fin,int cont){
    if (ini>fin)return cont;
    int med=(ini+fin)/2;
    if (arr[med]==0)
        return cuentaceros(arr,ini,med-1,
            cont+fin-med+1);
    else
        return cuentaceros(arr,med+1,fin,cont);
}


int main() {
    int arr[]{1,1,1,0,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << cuentaceros(arr,0,n-1,0) << endl;
    return 0;
}
