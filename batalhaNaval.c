#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
// Valor que representa água
#define AGUA 0
// Valor que representa parte de navio
#define NAVIO 3
// Tamanho dos navios
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios (linha e coluna)
    int linha_horizontal = 2;
    int coluna_horizontal = 1;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação: verificar se navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO) {
        // Posiciona navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já tem navio na posição
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != AGUA) {
                printf("Erro: Sobreposição detectada no navio horizontal!\n");
                return 1;
            }
            tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Validação: verificar se navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO) {
        // Posiciona navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já tem navio na posição
            if (tabuleiro[linha_vertical + i][coluna_vertical] != AGUA) {
                printf("Erro: Sobreposição detectada no navio vertical!\n");
                return 1;
            }
            tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
        }
    } else {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
