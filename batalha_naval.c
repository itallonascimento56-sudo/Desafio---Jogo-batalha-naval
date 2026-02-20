#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

int main() {

    /* =====================================================
       1. CRIAÇÃO DO TABULEIRO 10x10
       ===================================================== */

    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }

    /* =====================================================
       2. POSICIONANDO NAVIOS (exemplo simples)
       ===================================================== */

    for (int i = 2; i < 5; i++) {
        tabuleiro[2][i] = 3; // Navio horizontal
    }

    for (int i = 4; i < 7; i++) {
        tabuleiro[i][7] = 3; // Navio vertical
    }

    /* =====================================================
       3. MATRIZES DE HABILIDADE
       ===================================================== */

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2;

    /* --------- CONE ---------
       Expande para baixo
    */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    /* --------- CRUZ --------- */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    /* --------- OCTAEDRO (Losango) --------- */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    /* =====================================================
       4. SOBREPOSIÇÃO DAS HABILIDADES
       ===================================================== */

    int origemLinha = 5;
    int origemColuna = 3;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int linhaTab = origemLinha - centro + i;
            int colunaTab = origemColuna - centro + j;

            if (linhaTab >= 0 && linhaTab < TAM &&
                colunaTab >= 0 && colunaTab < TAM) {

                if (cone[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

    /* =====================================================
       5. EXIBIÇÃO DO TABULEIRO
       ===================================================== */

    printf("TABULEIRO FINAL:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0)
                printf("~ ");     // Água
            else if (tabuleiro[i][j] == 3)
                printf("N ");     // Navio
            else if (tabuleiro[i][j] == 5)
                printf("* ");     // Habilidade

        }
        printf("\n");
    }

    return 0;
}