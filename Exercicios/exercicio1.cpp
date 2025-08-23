#include <iostream>
#include <string>
using namespace std;

int main() {
    // Mensagem inicial
    cout << "=== Programa de Teste C++ ===" << endl;

    // Variáveis
    string nome;
    int idade;

    // Entrada de dados
    cout << "Digite seu nome: ";
    getline(cin, nome);

    cout << "Digite sua idade: ";
    cin >> idade;

    // Saída de dados
    cout << "\nOla, " << nome << "! Voce tem " << idade << " anos." << endl;

    // Estrutura condicional
    if (idade >= 18) {
        cout << "Voce e maior de idade." << endl;
    } else {
        cout << "Voce e menor de idade." << endl;
    }

    // Estrutura de repetição
    cout << "\nContagem de 1 a 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Fim do programa
    cout << "\n=== Fim do Programa ===" << endl;
    return 0;
}
