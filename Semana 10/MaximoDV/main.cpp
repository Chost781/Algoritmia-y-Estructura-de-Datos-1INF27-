#include <iostream>

using namespace std;

int buscamaximo(int *arr,int ini,int fin) {
    if (ini>=fin) return arr[ini];
    int med=(ini+fin)/2;

    if (arr[med]<arr[med+1])
        return buscamaximo(arr,med+1,fin);
    else
        return buscamaximo(arr,ini,med);
}


int main() {
    int arr[]={2,5,10,9,8,7,1};
    //int arr[]={2,5,10,15,8,3};
    //int arr[]={1,2,3,4,5};
   // int arr[]={8,6,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << buscamaximo(arr,0,n-1);
    return 0;
}
