#include <stdio.h>

#define TAMANHO 10       // Tamanho do tabuleiro 10x10
#define NAVIO 3          // Valor que representa parte de navio
#define AGUA 0           // Valor que representa água
#define TAM_NAVIO 3      // Tamanho fixo dos navios

// Função auxiliar para verificar se uma posição está livre
int pode_posicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == AGUA;
}

// Função para posicionar um navio horizontal
int posicionar_horizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAMANHO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        if (!pode_posicionar(tabuleiro, linha, coluna + i)) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha][coluna + i] = NAVIO;

    return 1;
}

// Função para posicionar um navio vertical
int posicionar_vertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAMANHO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        if (!pode_posicionar(tabuleiro, linha + i, coluna)) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha + i][coluna] = NAVIO;

    return 1;
}

// Função para posicionar um navio em diagonal principal (↘)
int posicionar_diagonal_principal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAMANHO || coluna + TAM_NAVIO > TAMANHO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        if (!pode_posicionar(tabuleiro, linha + i, coluna + i)) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha + i][coluna + i] = NAVIO;

    return 1;
}

// Função para posicionar um navio em diagonal secundária (↙)
int posicionar_diagonal_secundaria(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAMANHO || coluna - (TAM_NAVIO - 1) < 0) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        if (!pode_posicionar(tabuleiro, linha + i, coluna - i)) return 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha + i][coluna - i] = NAVIO;

    return 1;
}

// Função para imprimir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = AGUA;

    // Posicionar navios com coordenadas fixas e validação
    if (!posicionar_horizontal(tabuleiro, 1, 1))
        printf("Erro ao posicionar navio horizontal.\n");

    if (!posicionar_vertical(tabuleiro, 4, 5))
        printf("Erro ao posicionar navio vertical.\n");

    if (!posicionar_diagonal_principal(tabuleiro, 0, 7))
        printf("Erro ao posicionar navio diagonal principal.\n");

    if (!posicionar_diagonal_secundaria(tabuleiro, 6, 9))
        printf("Erro ao posicionar navio diagonal secundária.\n");

    // Exibir o tabuleiro
    exibir_tabuleiro(tabuleiro);

    return 0;
}
