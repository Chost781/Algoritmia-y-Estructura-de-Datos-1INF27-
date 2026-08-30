#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void cargabin(int num,int n,int *cromo) {
    int res,i=0;
    for (int j=0;j<n;j++)cromo[j]=0;
    while (num>0) {
        res=num%2;
        num=num/2;
        cromo[i]=res;
        i++;
    }
}

int main() {
    int peso=15,mcomb,mvalor=INT_MIN;
    int paq[]={1,2,1,12,4};
    int valor[]={100,50,60,10,100};
    int n=sizeof(paq)/sizeof(paq[0]);
    int cromo[n];
    int opcion=(int)pow(2,n);

    for (int i=0;i<opcion;i++) {
        int pparcial=0,vparcial=0;
        cargabin(i,n,cromo);
        for (int j=0;j<n;j++) {
            pparcial+=cromo[j]*paq[j];
            vparcial+=cromo[j]*valor[j];
        }
        if (pparcial<=peso and mvalor<vparcial) {
            mvalor=vparcial;
            mcomb=i;
        }
    }
    cout << "El valor es:"<< mvalor << endl;
    cargabin(mcomb,n,cromo);
    for (int j=0;j<n;j++)
        if (cromo[j]!=0)
            cout <<"peso:"<< paq[j] << " valor: "<<valor[j]<<"  ";
    return 0;
}

