#include <stdio.h>
#include <string.h>
struct Carta {
    //Declarando as variaveis
    char Estado[50];
    char Codigo[5];
    char NomeCidade[100];
    int Populacao;
    float Area;
    float Pib;
    int NumPontosTuristicos;
};

struct Carta Baralho[2];

void LimparDados(char * str){
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void LerDados(struct Carta * carta){
    for (int i=0; i < 2; i++){
        printf("Carta %d\n", i+1);

        printf("Estado: ");
        fgets(Baralho[i].Estado,sizeof(Baralho[i].Estado), stdin);
        LimparDados(Baralho[i].Estado);

        printf("Codigo: ");
        fgets(Baralho[i].Codigo, sizeof(Baralho[i].Codigo), stdin);
        LimparDados(Baralho[i].Codigo);

        printf("Nome da cidade: ");
        fgets(Baralho[i].NomeCidade, sizeof(Baralho[i].NomeCidade), stdin);
        LimparDados(Baralho[i].NomeCidade); 
    
        printf("Populacao:");
        scanf("%d", & Baralho[i].Populacao);
        getchar();

        printf("Area: ");
        scanf("%f", & Baralho[i].Area);
        getchar();

        printf("PIB: ");
        scanf("%f", & Baralho[i].Pib);
        getchar();

        printf("Numero de pontos turisticos:");
        scanf("%d", & Baralho[i].NumPontosTuristicos);
        getchar();
    }
}

void ImprimirDados(struct Carta carta){
    printf("Carta feita!\n");
    printf("Estado: %s\nCodigo: %s\nNome da cidade: %s\nPopulacao: %d\nArea: %.3f\nPIB: %.3f\n Numero de Pontos Turisticos:%d\n", carta.Estado, carta.Codigo, carta.NomeCidade, carta.Populacao, carta.Area, carta.Pib, carta.NumPontosTuristicos);

}
int main(){
    struct Carta carta1;
    LerDados(&carta1);
    ImprimirDados(carta1);
    return 0;
}