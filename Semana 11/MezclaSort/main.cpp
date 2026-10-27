#include <iostream>

using namespace std;

void merge(int *arr,int ini,int med,int fin) {
    int lizq=med-ini+1;
    int lder=fin-med;

    int izq[lizq+1];
    int der[lder+1];

    for(int i=ini;i<=med;i++)
        izq[i-ini]=arr[i];
    izq[lizq]=INT_MAX;
    for (int i=med+1;i<=fin;i++)
        der[i-med-1]=arr[i];
    der[lder]=INT_MAX;
    int p=0,q=0;
    for (int i=ini;i<=fin;i++) {
        if(izq[p]<der[q]) {
            arr[i]=izq[p];
            p++;
        }
        else {
            arr[i]=der[q];
            q++;
        }
    }
}

void mergesort(int *arr,int ini,int fin) {
    if (ini==fin)return;
    int med=(ini+fin)/2;
    mergesort(arr,ini,med);
    mergesort(arr,med+1,fin);
    merge(arr,ini,med,fin);

}

int main() {
    int arr[]={8,2,12,6,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout << endl;
    mergesort(arr,0,n-1);
    for (int i=0;i<n;i++)cout<<arr[i]<<" ";

    return 0;
}
