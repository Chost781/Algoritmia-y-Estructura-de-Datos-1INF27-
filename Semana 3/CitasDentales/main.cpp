#include <iostream>
#include <cmath>
#define N 8
#define M 4
#define T 4
#define H 3
#define C 3

using namespace std;

void generaCombinacion(int *combinacion,int numero,int n,int base)
{
    int i=0;
    for (int j=0;j<n;j++)combinacion[j] = 0;
    while (numero!=0)
    {
        combinacion[i++] = numero%base;
        numero = numero/base;
    }
}

int main()
{
    int infoDientes[N][M] = {
        {1,1,1,3},
        {2,1,1,1},
        {3,1,2,0},
        {4,1,3,1},
        {5,1,3,2},
        {6,1,4,1},
        {7,1,4,2},
        {8,1,4,3},
    };
    int infoTipoDiente[T][H] = {
        {1,5,20},
        {2,7,30},
        {3,10,35},
        {4,12,42},
    };

    bool cumple;
    int tiempoCita[C] = {60,45,50};
    int n=8;
    int combinacion[N];
    int duracionCita[C];
    int ganancia, gananciaMaxima=0, gananciaCombinacion, solucion;
    int estados = 4, cita, tipoDiente, cantCaries, duracion, duracionTotalDiente;
    int maximo = pow(estados,n);
    for (int i=1; i<maximo; i++)
    {
        generaCombinacion(combinacion,i,n,estados);
        for (int j=0; j<n; j++)
            duracionCita[j] = 0;
        gananciaCombinacion = 0;
        for (int j=0; j<n; j++)
        {
            if (combinacion[j]>0)
            {
                cita = combinacion[j];
                tipoDiente = infoDientes[j][2];
                cantCaries = infoDientes[j][3];
                duracion = infoTipoDiente[tipoDiente-1][1];
                ganancia = infoTipoDiente[tipoDiente-1][2];
                duracionTotalDiente = cantCaries * duracion;
                duracionCita[cita-1] += duracionTotalDiente;
                gananciaCombinacion +=  ganancia*cantCaries;
            }
        }
        /*Validamos que no se pase el tiempo de cada cita*/
        cumple = true;
        for (int k=0; k<C; k++)
            if (duracionCita[k]>tiempoCita[k] or duracionCita[k]==0)
            {
                cumple = false;
                break;
            }

        if (cumple and gananciaCombinacion>gananciaMaxima)
        {      gananciaMaxima = gananciaCombinacion;
                cout << gananciaMaxima << endl;
                solucion = i;
        }
    }
    /*Imprimimos la soluciÃ³n*/
    generaCombinacion(combinacion,solucion,n,estados);
    for (int j=0; j<n; j++)
        if (combinacion[j]>0)
            cout << "Cita: " << combinacion[j]  << "  Diente: " << j+1 << endl;
    cout << "La ganancia maxima es: " << gananciaMaxima << endl;
    return 0;
}