#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    /* =====================================================
       1. DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO
       ===================================================== */

    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com 0 (água)
    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    /* =====================================================
       2. DECLARAÇÃO DOS NAVIOS (vetores)
       ===================================================== */

    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO]   = {3, 3, 3};

    /* =====================================================
       3. COORDENADAS INICIAIS (definidas no código)
       ===================================================== */

    int linhaH = 1;
    int colunaH = 2;

    int linhaV = 5;
    int colunaV = 7;

    /* =====================================================
       4. POSICIONAMENTO DO NAVIO HORIZONTAL
       ===================================================== */

    // Verifica se cabe no tabuleiro
    if (colunaH + TAM_NAVIO <= TAM) {

        int sobreposicao = 0;

        // Verifica se já existe algo nas posições
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                sobreposicao = 1;
            }
        }

        // Se não houver sobreposição, posiciona
        if (sobreposicao == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    /* =====================================================
       5. POSICIONAMENTO DO NAVIO VERTICAL
       ===================================================== */

    if (linhaV + TAM_NAVIO <= TAM) {

        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
            }
        }

        if (sobreposicao == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    /* =====================================================
       6. EXIBIÇÃO DO TABULEIRO
       ===================================================== */

    printf("TABULEIRO BATALHA NAVAL:\n\n");

    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}