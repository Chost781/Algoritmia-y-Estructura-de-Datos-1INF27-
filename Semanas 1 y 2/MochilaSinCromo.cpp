#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Paquetes disponibles: 2 de 1 kg, 1 de 2 kg, 1 de 4 kg, 1 de 12 kg
    int paquetes[] = {1, 1, 2, 4, 12};
    int resultado[5];
    int maxPeso = 15;
    int mejorCombinacion = 0;
	int pesoTotal;
	
    // Hacemos iteraciones para cada cantidad posible de cada tipo de paquete.
    // Tenemos 2 paquetes de 1 kg, 1 de 2 kg, 1 de 4 kg, 1 de 12 kg
	for (int m = 0; m <= 1; m++) {  // 0 a 2 paquetes de 1 kg
	    for (int i = 0; i <= 1; i++) {  // 0 a 2 paquetes de 1 kg
	        for (int j = 0; j <= 1; j++) {  // 0 o 1 paquete de 2 kg
	            for (int k = 0; k <= 1; k++) {  // 0 o 1 paquete de 4 kg
	                for (int l = 0; l <= 1; l++) {  // 0 o 1 paquete de 12 kg
	                    pesoTotal = m * 1 + i * 1 + j * 2 + k * 4 + l * 12;
	                    // Si el peso total no excede el m?ximo, consideramos esta combinaci?n
	                    if (pesoTotal <= maxPeso) {
	                        mejorCombinacion = max(mejorCombinacion, pesoTotal);
	                        if(pesoTotal==maxPeso){
	                        	if(m)
	                        		cout << 0 <<" "; 
	                        	if(i)
	                        		cout << 1 <<" ";
	                        	if(j)
	                        		cout << 2 <<" ";
	                        	if(k)
	                        		cout << 3 <<" ";
	                        	if(l)
	                        		cout << 4 <<" ";																												                        	
	                        	cout << endl;
							}
	                    }
	                }
	            }
	        }
	    }
	}

	cout << endl;
    // Imprimimos el resultado
    cout << "El mayor peso posible que se puede llevar es: " << mejorCombinacion << " kg" << endl;

    return 0;
}

