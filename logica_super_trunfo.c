#include <stdio.h>

//--- Função auxiliar: retorna valor numérico de um atributo ---
float getValor(int atributo, unsigned long int pop, float area, float pib, int pontos, float densidade, float percapita){
    switch(atributo){
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return densidade;
        case 6: return percapita;
        default: return 0; 
}

int main(){

    //variáveis da primeira carta
    char Estado1[3];
    char codigoCarta1[10];  
    char nomeCidade1[50];
    unsigned long int populacao1;
    int numeroPontosTuristicos1;
    float area1, PIB1;
    float densidade1, PIBperCapita1;

    //variáveis da segunda carta
    char Estado2[3];
    char codigoCarta2[10];
    char nomeCidade2[50];
    unsigned long int populacao2; 
    int numeroPontosTuristicos2;
    float area2, PIB2;
    float densidade2, PIBperCapita2;

    //escaneando a carta 1
    printf("Estado 1: ");
    scanf(" %s", Estado1);   
    
    printf("Código da Carta 1 (ex: A01): ");
    scanf(" %s", codigoCarta1);

    printf("Cidade 1: ");
    scanf(" %[^\n]", nomeCidade1); 

    printf("População da Cidade: ");
    scanf("%lu", &populacao1);

    printf("Área em km² da Cidade: ");
    scanf("%f", &area1);

    printf("PIB da Cidade: ");
    scanf("%f", &PIB1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &numeroPontosTuristicos1);

    //cálculo da carta 1
    densidade1= populacao1 / area1;
    PIBperCapita1 = PIB1 / populacao1;

    //escaneando a carta 2
    printf("Estado 2: ");
    scanf(" %s", Estado2);  
    
    printf("Código da Carta 2 (ex: A02): ");
    scanf(" %s", codigoCarta2);

    printf("Cidade 2: ");
    scanf(" %[^\n]", nomeCidade2);
    
    printf("População da Cidade: ");
    scanf("%lu", &populacao2);

    printf("Área em km² da Cidade: ");
    scanf("%f", &area2);

    printf("PIB da Cidade: ");
    scanf("%f", &PIB2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &numeroPontosTuristicos2);

    //cálculo da segunda carta
    densidade2= populacao2 / area2;
    PIBperCapita2 = PIB2 / populacao2;

    //--- MENU PARA ESCOLHA DOS ATRIBUTOS ---
    int atributo1, atributo2;
    printf("\n--- Escolha o PRIMEIRO atributo para comparar ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    scanf("%d", &atributo1);

    printf("\n--- Escolha o SEGUNDO atributo (diferente do primeiro) ---\n");
    for(int i=1; i<=6; i++){
        if(i != atributo1){
            switch(i){
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    scanf("%d", &atributo2);

    //--- Pegando valores para as duas cartas ---
    float v1_attr1 = getValor(atributo1, populacao1, area1, PIB1, numeroPontosTuristicos1, densidade1, PIBperCapita1);
    float v2_attr1 = getValor(atributo1, populacao2, area2, PIB2, numeroPontosTuristicos2, densidade2, PIBperCapita2);

    float v1_attr2 = getValor(atributo2, populacao1, area1, PIB1, numeroPontosTuristicos1, densidade1, PIBperCapita1);
    float v2_attr2 = getValor(atributo2, populacao2, area2, PIB2, numeroPontosTuristicos2, densidade2, PIBperCapita2);

    //--- Comparação atributo 1 ---
    int resultado1;
    if(atributo1 == 5){ //densidade (menor vence)
        resultado1 = (v1_attr1 < v2_attr1) ? 1 : (v2_attr1 < v1_attr1 ? 2 : 0);
    } else {
        resultado1 = (v1_attr1 > v2_attr1) ? 1 : (v2_attr1 > v1_attr1 ? 2 : 0);
    }

    //--- Comparação atributo 2 ---
    int resultado2;
    if(atributo2 == 5){ //densidade (menor vence)
    
    }
