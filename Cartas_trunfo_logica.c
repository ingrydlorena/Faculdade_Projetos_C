#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// Calcula densidade demográfica e PIB per capita
void calcular_dados(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Mostra os dados de uma carta
void exibir_carta(Carta c) {
    printf("Cidade: %s (%s)\n", c.cidade, c.estado);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade Demografica: %.2f hab/km²\n", c.densidade);
    printf("PIB per capita: %.2f\n", c.pib_per_capita);
}

// Compara os atributos de duas cartas
void comparar(Carta c1, Carta c2, int atributo) {
    float valor1, valor2;
    char nome_atributo[30];

    switch (atributo) {
        case 1:
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            strcpy(nome_atributo, "Populacao");
            break;
        case 2:
            valor1 = c1.area;
            valor2 = c2.area;
            strcpy(nome_atributo, "Area");
            break;
        case 3:
            valor1 = c1.pib;
            valor2 = c2.pib;
            strcpy(nome_atributo, "PIB");
            break;
        case 4:
            valor1 = c1.pontos_turisticos;
            valor2 = c2.pontos_turisticos;
            strcpy(nome_atributo, "Pontos Turisticos");
            break;
        case 5:
            valor1 = c1.densidade;
            valor2 = c2.densidade;
            strcpy(nome_atributo, "Densidade Demografica");
            break;
        case 6:
            valor1 = c1.pib_per_capita;
            valor2 = c2.pib_per_capita;
            strcpy(nome_atributo, "PIB per capita");
            break;
        default:
            printf("Opcao invalida.\n");
            return;
    }

    // Mostra os valores comparados
    printf("\nComparacao de cartas (Atributo: %s):\n", nome_atributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, valor2);

    // Define o critério de vitória
    if (atributo == 5) { // Densidade (menor vence)
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else { // Demais atributos (maior vence)
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    // Dados das cartas
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.0, 800000.0, 10};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6700000, 1182.0, 450000.0, 8};

    // Calcula os dados derivados
    calcular_dados(&carta1);
    calcular_dados(&carta2);

    // Mostra as cartas
    printf("CARTA 1:\n");
    exibir_carta(carta1);
    printf("\nCARTA 2:\n");
    exibir_carta(carta2);

    // Menu de escolha
    int opcao;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica (MENOR vence)\n");
    printf("6 - PIB per capita\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Compara as cartas
    comparar(carta1, carta2, opcao);

    return 0;
}
