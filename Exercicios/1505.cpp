#include <iostream>

using namespace std;

// Estrutura do nó da lista duplamente encadeada
struct address {
    int chave; // valor armazenado no nó

    // Ponteiro para o próximo nó
    struct address *prox;

    // Ponteiro para o nó anterior
    struct address *ant;
};

// Apelido para a estrutura address
typedef struct address no;

// Estrutura de controle da lista
typedef struct {
    no *inicio; // aponta para o primeiro nó
    no *fim;    // aponta para o último nó
    int tam;    // guarda o tamanho da lista
} LISTA;

// Inicializa a lista
void init(LISTA *l) {
    l->inicio = nullptr;
    l->fim = nullptr;
    l->tam = 0;
}

void removeFim(LISTA *l) {

    // Verifica se a lista está vazia
    if (l->fim == nullptr) {
        cout << "Lista vazia. Nao ha elementos para remover." << endl;
        return;
    }

    // Nó a ser removido (último nó)
    no *remover = l->fim;

    // Atualiza o fim da lista para o nó anterior
    l->fim = remover->ant;

    // Se a lista não ficou vazia, atualiza o próximo do novo fim
    if (l->fim != nullptr) {
        l->fim->prox = nullptr;
    } else {
        // Se a lista ficou vazia, atualiza o início também
        l->inicio = nullptr;
    }

    // Libera a memória do nó removido
    delete remover;

    // Decrementa o tamanho da lista
    l->tam--;

    cout << "Ultimo elemento removido com sucesso!" << endl;
}








// Inserção no fim da lista
void insereFim(LISTA *l, int chave) {

    // Cria um novo nó
    no *novo = new no;

    // Armazena o valor no nó
    novo->chave = chave;

    // O próximo será nulo,
    // pois ele ficará no final
    novo->prox = nullptr;

    // Verifica se a lista está vazia
    if (l->inicio == nullptr) {

        // Como é o único elemento,
        // o anterior também será nulo
        novo->ant = nullptr;

        // O início e o fim apontam para o novo nó
        l->inicio = novo;
        l->fim = novo;

    } else {

        // O anterior do novo nó
        // será o antigo fim
        novo->ant = l->fim;

        // O antigo fim aponta para o novo nó
        l->fim->prox = novo;

        // Atualiza o fim da lista
        l->fim = novo;
    }

    // Incrementa o tamanho da lista
    l->tam++;
}

// Inserção no início da lista
void insereInicio(LISTA *l, int chave) {

    // Cria um novo nó
    no *novo = new no;

    // Armazena o valor no nó
    novo->chave = chave;

    // Verifica se a lista está vazia
    if (l->inicio == nullptr) {

        // Como será o único elemento,
        // próximo e anterior serão nulos
        novo->prox = nullptr;
        novo->ant = nullptr;

        // O início e o fim apontam para o novo nó
        l->inicio = novo;
        l->fim = novo;

    } else {

        // O próximo do novo nó
        // será o antigo início
        novo->prox = l->inicio;

        // Como ficará no início,
        // o anterior será nulo
        novo->ant = nullptr;

        // O antigo início aponta
        // para o novo nó
        l->inicio->ant = novo;

        // Atualiza o início da lista
        l->inicio = novo;
    }

    // Incrementa o tamanho da lista
    l->tam++;
}

// Impressão da lista
void imprime(LISTA *l) {

    // Nó auxiliar para percorrer a lista
    no *atual = l->inicio;

    cout << "\nTAMANHO DA LISTA: " << l->tam << endl;

    // Verifica se a lista está vazia
    if (atual == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    cout << "Elementos da lista: ";

    // Percorre a lista até o final
    while (atual != nullptr) {
        cout << atual->chave << " ";
        atual = atual->prox;
    }

    cout << endl;
}

int main() {

    LISTA lista1;

    int opcao;
    int valor;

    // Inicializa a lista
    init(&lista1);

    do {

        cout << "\n======= MENU =======" << endl;
        cout << "1 - Inserir no fim" << endl;
        cout << "2 - Imprimir lista" << endl;
        cout << "3 - Inserir no inicio" << endl;
        cout << "0 - Sair" << endl;

        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1:

                cout << "Digite o valor: ";
                cin >> valor;

                insereFim(&lista1, valor);

                cout << "Valor inserido no fim com sucesso!" << endl;

                break;

            case 2:

                imprime(&lista1);

                break;

            case 3:

                cout << "Digite o valor: ";
                cin >> valor;

                insereInicio(&lista1, valor);

                cout << "Valor inserido no inicio com sucesso!" << endl;

                break;

            case 0:

                cout << "Programa encerrado." << endl;

                break;

            default:

                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);

    return 0;
}