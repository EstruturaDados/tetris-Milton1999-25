#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da peça
typedef struct {
    char nome;   // Tipo da peça ('I', 'O', 'T', 'L')
    int id;      // Identificador único
} Peca;

// Parâmetros da fila
#define TAMANHO_FILA 5

// Fila circular
Peca fila[TAMANHO_FILA];
int inicio = 0;
int fim = 0;
int quantidade = 0;
int contadorID = 0; // Controla IDs gerados

// Gera uma nova peça automaticamente
Peca gerarPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca nova;
    nova.nome = tipos[rand() % 4];
    nova.id = contadorID++;
    return nova;
}

// Insere peça na fila (enqueue)
void inserirPeca() {
    if (quantidade == TAMANHO_FILA) {
        printf("\nFila cheia! Nao e possivel inserir nova peca.\n");
        return;
    }
    Peca nova = gerarPeca();
    fila[fim] = nova;
    fim = (fim + 1) % TAMANHO_FILA;
    quantidade++;
    printf("\nPeca inserida: [%c %d]\n", nova.nome, nova.id);
}

// Remove peça da fila (dequeue)
void jogarPeca() {
    if (quantidade == 0) {
        printf("\nFila vazia! Nao ha peca para jogar.\n");
        return;
    }
    Peca removida = fila[inicio];
    inicio = (inicio + 1) % TAMANHO_FILA;
    quantidade--;
    printf("\nPeca jogada: [%c %d]\n", removida.nome, removida.id);
}

// Exibe o estado atual da fila
void exibirFila() {
    printf("\n=== Fila de Pecas ===\n");
    if (quantidade == 0) {
        printf("(fila vazia)\n");
        return;
    }
    int i;
    int pos = inicio;
    for (i = 0; i < quantidade; i++) {
        printf("[%c %d] ", fila[pos].nome, fila[pos].id);
        pos = (pos + 1) % TAMANHO_FILA;
    }
    printf("\n=======================\n");
}

int main() {
    srand(time(NULL));

    // Inicializa a fila com 5 peças
    printf("Inicializando fila com 5 pecas...\n");
    while (quantidade < TAMANHO_FILA) {
        inserirPeca();
    }

    int opcao;
    do {
        exibirFila();
        printf("\nOpcoes:\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("0 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogarPeca();
                break;
            case 2:
                inserirPeca();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
