#include <iostream>

using namespace std;

int crucemaximo(int *arr,int ini,int med,int fin) {

    int suma=0,maxizq=INT_MIN,maxder=INT_MIN;
    for (int i=med;i>=ini;i--) {
        suma+=arr[i];
        if (suma>maxizq)
            maxizq=suma;
    }
    suma=0;
    for (int i=med+1;i<=fin;i++) {
        suma+=arr[i];
        if (suma>maxder)
            maxder=suma;
    }
    return max(max(maxder,maxizq),maxder+maxizq);
}


int sumamaxima(int *arr,int ini,int fin) {
    if (ini==fin)return arr[ini];
    int med=(ini+fin)/2;
    int mizq=sumamaxima(arr,ini,med);
    int mder=sumamaxima(arr,med+1,fin);
    int mmed=crucemaximo(arr,ini,med,fin);

    return max(mmed,max(mizq,mder));
}



int main() {
    int arr[]={20,-5,-6,2,-3,1,50,-6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout <<"Maximo: "<< sumamaxima(arr,0,n-1);

    return 0;
}
