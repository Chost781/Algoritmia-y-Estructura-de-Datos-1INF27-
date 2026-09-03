#include <iostream>
// triangulo(3,5)
using namespace std;
void triangulo(int a, int b) {
    if (a>b)return;
    for (int i=0;i<a;i++)cout << "*"<<" ";
    cout<<endl;
    triangulo(a+1,b);
    for (int i=0;i<a;i++)cout << "*"<<" ";
    cout<<endl;
}
void forrecu(int ini, int fin,char car) {
    if (ini>=fin)return;
    cout << car <<" ";
    forrecu(ini+1,fin,car);
}
void triangulo2(int a, int b) {
    if (a>b)return;
    forrecu(0,a,'*');
    cout<<endl;
    triangulo2(a+1,b);
    forrecu(0,a,'*');
    cout<<endl;
}
int main() {
    triangulo(3,5);
    cout <<"==============================="<<endl;
    triangulo2(3,5);
    return 0;
}
