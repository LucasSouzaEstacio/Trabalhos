#include <stdio.h>

int main() {
    //variáveis da primeira carta
    char Estado1;
    char codigoCarta1[10];  
    char nomeCidade1[50];
    unsigned long int populacao1;
    int numeroPontosTuristicos1;
    float area1, PIB1;
    float densidade1, PIBperCapita1, SuperPoder1;

    //variáveis da segunda carta
    char Estado2;
    char codigoCarta2[10];
    char nomeCidade2[50];
    unsigned long int populacao2; 
    int numeroPontosTuristicos2;
    float area2, PIB2;
    float densidade2, PIBperCapita2, SuperPoder2;

    //escaneando a carta 1
    printf("Estado 1(A-H): ");
    scanf(" %c", &Estado1);   
    
    printf("Código da Carta 1:(ex: A01): ");
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
    SuperPoder1 = (float)populacao1 + area1 + PIB1 + numeroPontosTuristicos1 + PIBperCapita1 + (1.0f / densidade1);


    // Exibindo as informações da primeira carta
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", Estado1);
    printf("Código: %s\n", codigoCarta1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", PIB1);
    printf("Número de Pontos Turísticos: %d\n", numeroPontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1 );
    printf("PIB Per Capita: %.2f reais\n", PIBperCapita1);
    printf("Super Poder: %.2f\n", SuperPoder1);
    printf("\n");

    //escaneando a carta 2
    printf("Estado 2(A-H): ");
    scanf(" %c", &Estado2);  
    
    printf("Código da Carta 2(ex: A02): ");
    scanf(" %s", codigoCarta2);

    printf("Cidade 2: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área em km²: ");
    scanf("%f", &area2);

    printf("PIB da Cidade: ");
    scanf("%f", &PIB2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &numeroPontosTuristicos2);

    //cálculo da segunda carta

    densidade2= populacao2 / area2;
    PIBperCapita2 = PIB2 / populacao2;
    SuperPoder2 = (float)populacao2 + area2 + PIB2 + numeroPontosTuristicos2 + PIBperCapita2 + (1.0f / densidade2);

    // Exibindo as informações da segunda carta
    printf("\n--- Carta 2---\n");
    printf("Estado: %c\n", Estado2);
    printf("Código: %s\n", codigoCarta2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População da Cidade: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", PIB2);
    printf("Número de Pontos Turísticos: %d\n", numeroPontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB Per Capita: %.2f reais\n", PIBperCapita2);
    printf("Super Poder: %.2f\n", SuperPoder2);
    printf("\n");


    printf("\n=== Comparação de Cartas ===\n");

    //comparação da população
if (populacao1 > populacao2) {
    printf("População: Carta 1 venceu (1)\n");
} else {
    printf("População: Carta 2 venceu (0)\n");
}
    //comparação da área
if (area1 > area2) {
    printf("Área: Carta 1 venceu (1)\n");
} else {
    printf("Área: Carta 2 venceu (0)\n");
}
    //comparação do PIB
if (PIB1 > PIB2) {
    printf("PIB: Carta 1 venceu (1)\n");
} else {
    printf("PIB: Carta 2 venceu (0)\n");
}
   //comparação dos pontos turísticos
if (numeroPontosTuristicos1 > numeroPontosTuristicos2) {
    printf("Pontos Turísticos: Carta 1 venceu (1)\n");
} else {
    printf("Pontos Turísticos: Carta 2 venceu (0)\n");
}

    //na densidade, o menor valor vence
if (densidade1 < densidade2) {
    printf("Densidade Populacional: Carta 1 venceu (1)\n");
} else {
    printf("Densidade Populacional: Carta 2 venceu (0)\n");
}
    //comparação do PIB per capita
if (PIBperCapita1 > PIBperCapita2) {
    printf("PIB per Capita: Carta 1 venceu (1)\n");
} else {
    printf("PIB per Capita: Carta 2 venceu (0)\n");
}
    //comparação do super poder
if (SuperPoder1 > SuperPoder2) {
    printf("Super Poder: Carta 1 venceu (1)\n");
} else {
    printf("Super Poder: Carta 2 venceu (0)\n");
}


   return 0;

}



    
  


    




