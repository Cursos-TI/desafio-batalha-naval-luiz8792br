#include <stdio.h>

#define TAM 10
#define TAM_HAB 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Inicializa uma matriz com zeros
void inicializar_matriz(int matriz[TAM][TAM], int valor) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = valor;
}

// Exibe o tabuleiro com representação visual
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf("0 ");
            else if (tabuleiro[i][j] == NAVIO) printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("5 ");
        }
        printf("\n");
    }
}

// Cria matriz em forma de cone (↧)
void criar_cone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz em forma de cruz (+)
void criar_cruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz em forma de octaedro (losango ◊)
void criar_octaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Sobrepõe uma matriz de habilidade no tabuleiro com valor 5
void aplicar_habilidade(int tabuleiro[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha_tab = origem_linha - TAM_HAB / 2 + i;
            int coluna_tab = origem_coluna - TAM_HAB / 2 + j;

            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM &&
                hab[i][j] == 1 &&
                tabuleiro[linha_tab][coluna_tab] == AGUA) {
                tabuleiro[linha_tab][coluna_tab] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializar_matriz(tabuleiro, AGUA);

    // Posicionamento fixo de alguns navios
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[5][5] = NAVIO;
    tabuleiro[6][5] = NAVIO;
    tabuleiro[7][5] = NAVIO;

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    criar_cone(cone);
    criar_cruz(cruz);
    criar_octaedro(octaedro);

    // Pontos de origem no tabuleiro
    aplicar_habilidade(tabuleiro, cone, 1, 2);       // Cone para baixo do topo
    aplicar_habilidade(tabuleiro, cruz, 5, 2);       // Cruz centralizada
    aplicar_habilidade(tabuleiro, octaedro, 7, 7);   // Octaedro no canto inferior direito

    // Mostrar o tabuleiro final
    exibir_tabuleiro(tabuleiro);

    return 0;
}
