#include <iostream>
#define N 6

using namespace std;

void merge(int *arr,int ini,int med,int fin) {
    int lizq=med-ini+1;
    int lder=fin-med;
    int izq[lizq+1],der[lder+1];
    for (int i=ini;i<=med;i++)izq[i-ini]=arr[i];
    izq[lizq]=INT_MAX;
    for (int i=med+1;i<=fin;i++)der[i-med-1]=arr[i];
    der[lder]=INT_MAX;
    int p=0,q=0;
    for (int i=ini;i<=fin;i++)
        if (izq[p]<der[q])
            arr[i]=izq[p++];
        else
            arr[i]=der[q++];

}

void mergesort(int *arr,int ini,int fin) {
    if (ini==fin)return;
    int med = (ini+fin)/2;
    mergesort(arr,ini,med);
    mergesort(arr,med+1,fin);
    merge(arr,ini,med,fin);
}

void buscasolo(int *arr,int ini,int fin) {
    if (ini>fin)return;
    if (ini==fin) {
        cout << arr[ini] << endl;
        return;
    }
    int med=(ini+fin)/2;
    if (med%2==0)
        if (arr[med]==arr[med+1])
            buscasolo(arr,med+2,fin);
        else
            buscasolo(arr,ini,med);
    else {
        if (arr[med]==arr[med+1])
            buscasolo(arr,ini,med-1);
        else
            buscasolo(arr,med+1,fin);
    }
}

void ordenamatriz(int canarios[N][N]) {
    for (int i=0;i<N;i++)
        mergesort(canarios[i],0,N-1);
}
void buscafaltante(int canarios[N][N]) {
    for (int i=0;i<N;i++)
        if (canarios[i][N-1]==INT_MAX)
            buscasolo(canarios[i],0,N-2);
        else
            cout << "Sin faltante"<<endl;
}


int main() {
    int canarios[N][N]={
        {INT_MAX,3,7,2,2,7},
        {5,INT_MAX,3,1,5,3},
        {7,7,3,6,6,3},
        {7,4,INT_MAX,7,2,4},
        {5,1,2,5,1,2},
        {6,INT_MAX,7,4,7,4}
    };
    ordenamatriz(canarios);
    buscafaltante(canarios);
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++)
            if (canarios[i][j]==INT_MAX)
                cout << "INT_MAX";
            else
                cout << canarios[i][j] << " ";
        cout << endl;
    }

    return 0;
}
