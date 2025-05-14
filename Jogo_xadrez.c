#include <stdio.h>

// Função recursiva para movimento da Torre (direita)
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para movimento do Bispo (diagonal cima-direita)
void moverBispoRecursivo(int casas) {
    if (casas == 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(casas - 1);
}

// Função recursiva para movimento da Rainha (esquerda)
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Função com loops aninhados para movimentar o Cavalo (baixo + esquerda)
void moverCavaloSimples(int casasVerticais, int casasHorizontais) {
    for (int i = 0; i < casasVerticais; i++) {
        printf("Baixo\n");
        int j = 0;
        while (j < 1 && i == casasVerticais - 1) {
            printf("Esquerda\n");
            j++;
        }
    }
}

// Função com loops complexos para movimentar o Cavalo (cima + direita)
void moverCavaloAvancado(int movimentos) {
    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) printf("Cima\n");
            if (j == 1) {
                printf("Cima\n");
                break; // controla a quantidade de repetições
            }
        }
        for (int k = 0; k < 1; k++) {
            printf("Direita\n");
        }
    }
}

// Função com loops aninhados para o Bispo (diagonal usando dois loops)
void moverBispoComLoop(int casas) {
    for (int i = 0; i < casas; i++) {
        for (int j = 0; j < 1; j++) {
            printf("Cima Direita\n");
        }
    }
}

int main() {
    // Parte 1: Torre, Bispo e Rainha (recursivos)
    moverTorre(5);
    printf("\n");
    moverBispoRecursivo(5);
    printf("\n");
    moverRainha(8);
    printf("\n");

    // Parte 2: Cavalo (baixo + esquerda)
    moverCavaloSimples(2, 1);
    printf("\n");

    // Parte 3: Cavalo (cima + direita) com loops complexos
    moverCavaloAvancado(1); // faz 1 movimento em L para cima e direita
    printf("\n");

    // Parte 3: Bispo com loops aninhados
    moverBispoComLoop(5);

    return 0;
}
