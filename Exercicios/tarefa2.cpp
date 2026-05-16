#include <iostream>
#include <string.h>

using namespace std;

void troca(int *x, int *y){
    int temp;
    temp = *x; 
    *x = *y;     
    *y = temp;   
}

int main(){
    int a, b; 
    int *ptr; 
    
    a = 10; 
    b = 50; 
    
    cout << "Endereco variavel a: " << &a << endl;
    cout << "Endereco variavel b: " << &b << endl;

    ptr = &a; 
    cout << "Endereco armazenado pelo ptr: " << ptr << endl;
    cout << "Valor armazenado pelo ptr: " << *ptr << endl;

    *ptr = 80;
    cout << "Novo valor da variavel a: " << a << endl;

    cout << "antes:" << endl;
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;

   
    troca(&a, &b);

    cout << "depois:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}