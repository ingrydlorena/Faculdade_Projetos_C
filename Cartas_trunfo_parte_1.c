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

void LimparDados(char * str){
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void LerDados(struct Carta * carta){
    printf("Carta 1:\n");

    printf("Estado: ");
    fgets(carta->Estado,sizeof(carta->Estado), stdin);
    LimparDados(carta->Estado);

    printf("Codigo: ");
    fgets(carta->Codigo, sizeof(carta->Codigo), stdin);
    LimparDados(carta->Codigo);

    printf("Nome da cidade: ");
    fgets(carta->NomeCidade, sizeof(carta->NomeCidade), stdin);
    LimparDados(carta->NomeCidade); 
    
    printf("Populacao:");
    scanf("%d", &carta->Populacao);
    getchar();

    printf("Area: ");
    scanf("%f", &carta->Area);
    getchar();

    printf("PIB: ");
    scanf("%f", &carta->Pib);
    getchar();

    printf("Numero de pontos turisticos:");
    scanf("%d", &carta->NumPontosTuristicos);
    getchar();
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