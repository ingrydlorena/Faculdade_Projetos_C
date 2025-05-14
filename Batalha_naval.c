#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar um navio vertical
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para verificar se o navio pode ser posicionado
int verificarPosicionamento(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 0) { // Horizontal
            if (coluna + i >= TAMANHO_TABULEIRO || tabuleiro[linha][coluna + i] != 0) {
                return 0;
            }
        } else { // Vertical
            if (linha + i >= TAMANHO_TABULEIRO || tabuleiro[linha + i][coluna] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com água (0)
    
    // Definir coordenadas dos navios
    int navio1Linha = 2, navio1Coluna = 3; // Horizontal
    int navio2Linha = 5, navio2Coluna = 1; // Vertical

    // Posicionar os navios no tabuleiro
    if (verificarPosicionamento(tabuleiro, navio1Linha, navio1Coluna, 0)) {
        posicionarNavioHorizontal(tabuleiro, navio1Linha, navio1Coluna);
    }
    if (verificarPosicionamento(tabuleiro, navio2Linha, navio2Coluna, 1)) {
        posicionarNavioVertical(tabuleiro, navio2Linha, navio2Coluna);
    }

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
