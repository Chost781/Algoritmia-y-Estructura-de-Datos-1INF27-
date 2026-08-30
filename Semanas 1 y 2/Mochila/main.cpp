#include <iostream>
#include <cmath>

using namespace std;

void cargabin(int num,int n,int *cromo) {
    int res,i=0;
    for (int j=0; j<n; j++) cromo[j]=0;
    while (num>0) {
        res=num%2;
        num=num/2;
        cromo[i]=res;
        i++;
    }
}

int main() {
    int peso=15,mpeso=0,mcomb;
    int paq[]={1,2,1,4,12};
    int n=sizeof(paq)/sizeof(paq[0]);
    int comb=(int)pow(2,n);
    int cromo[n];

    for (int i=0; i<comb; i++) {
        int pparcial=0;
        cargabin(i,n,cromo);
        for (int j=0; j<n; j++)
            pparcial+=cromo[j]*paq[j];
        if (pparcial<=peso and pparcial>mpeso) {
            mpeso=pparcial;
            mcomb=i;
        }
    }
    cout<<"El mejor peso es:"<<mpeso<<endl;
    cargabin(mcomb,n,cromo);
    cout <<"Los paquetes seleccionados son: ";
    for (int i=0; i<n; i++)
        if (cromo[i]==1)
            cout<<paq[i]<<" ";

    return 0;
}
