#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Carta 1:
    char estado1 = 'S';    // Sigla do Estado
    char codigo1 [4] = "S01";  // Codigo junt + o nulo
    char cidade1[50] = "Sao Paulo";   // "[]" Para permitir mais letras
    int populacao1;
    float area1 = 282559;
    float PIB1;
    int pontoturistico1 = 55;
    float DensidadePopulacional1 = 2498452;
    float PIBperCapita1;
    float SuperPoder1 = 8435123;
    int menu;


    // Carta 2
    char estado2 = 'R';
    char codigo2 [4] = "R02";
    char cidade2[50] = "Rio de Janeiro";
    int populacao2;
    float area2 = 452980;
    float PIB2;    
    int pontoturistico2 = 60;
    float DensidadePopulacional2 = 2196548;
    float PIBperCapita2;
    float SuperPoder2 = 98426355;

    // Mensagens que irão aparecer diante do usuário:

    printf(" ~~~~~~ Carta 01 ~~~~~~ \n");

    printf("    Coloque os dados da primeira carta    \n");
    printf("Estado A-Z: \n");
    scanf("%c", &estado1);

    printf("Codigo da carta (ex: C01): \n");
    scanf("%s", codigo1);

    printf("Nome da cidade: \n");
    scanf(" %[^\n]", cidade1);

    printf("Populacao: \n");
    scanf("%d", &populacao1);

    printf("Area territorial(km2): \n");
    scanf("%f", &area1);

    printf("PIB: \n");
    scanf("%f", &PIB1);

    printf("Ponto Turisticos: \n");
    scanf("%d", &pontoturistico1);

    // Cálculo C01

    DensidadePopulacional1 = (float)populacao1 / area1;
    PIBperCapita1 = PIB1 / (float)populacao1;
    SuperPoder1 = (float)populacao1 + area1 + PIB1 + (float)pontoturistico1 + PIBperCapita1 + (2.f / DensidadePopulacional1);

    printf(" ~~~~~~ Carta 02 ~~~~~~ \n");

    printf("    Coloque os dados da segunda carta \n");
    printf("Estado A-Z: \n");
    scanf(" %c", &estado2);

    printf("Codigo da carta (ex: F07): \n");
    scanf(" %s", codigo2);

    printf("Nome da cidade: \n");
    scanf(" %[^\n]", cidade2);

    printf("Populacao: \n");
    scanf("%d", &populacao2);

    printf("Area territorial: \n");
    scanf("%f", &area2);

    printf("PIB: \n");
    scanf("%f", &PIB2);

    printf("Ponto Turisticos: \n");
    scanf("%d", &pontoturistico2);

    // Cálculos C02

    DensidadePopulacional2 = (float)populacao2 / area2;
    PIBperCapita2 = PIB2 / (float)populacao2;
    SuperPoder2 = (float)populacao2 + area2 + PIB2 + (float)pontoturistico2 + PIBperCapita2 + (2.f / DensidadePopulacional2);

    // Demostrativo -----

    printf("                    ");  // 
    printf("    Resultado    ");    // layout
    printf("    Carta 1     \n");  //

    printf("Estado: %c\nCodigo: %s\n", estado1, codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", PIB1);
    printf("Ponto turistico: %d\n", pontoturistico1);
    printf("Densidade Populacional: %.2f hab/km²\n", DensidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", PIBperCapita1);

    printf("                    ");  //
    printf("    Resultado    "); // Essa parte é pra dar espaço aos números para não ficar muito bagunçado !
    printf("    Carta 2     \n");  // 
    
    printf("Estado: %c\nCodigo: %s\n", estado2, codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", PIB2);
    printf("Ponto turistico: %d\n", pontoturistico2);
    printf("Densidade Populacional: %.2f hab/km²\n", DensidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", PIBperCapita2); // 2.f para pular duas casas decimais
    
    // --- Comparação ---
    printf("\nComparacao das Cartas:\n");
    printf("~~~~~~~~~~~~~~~~~~~~");

    printf("Populacao: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    printf("Area: Carta 1 venceu (%d)\n", area1 > area2);
    printf("PIB: Carta 1 venceu (%d)\n", PIB1 > PIB2);
    printf("Ponto turistico: Carta 1 venceu (%d)\n", pontoturistico1 > pontoturistico2);
    printf("Densidade: Carta 1 venceu (%d)\n", DensidadePopulacional1 < DensidadePopulacional2);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", PIBperCapita1 > PIBperCapita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", SuperPoder1 > SuperPoder2);

    // Cálculos
    float pibPerCapita1 = PIB1 / (float)populacao1;
    float pibPerCapita2 = PIB2 / (float)populacao2;
    
    
    // Exibição do resultado
    printf("\nComparação de cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1 - %s (%c): %.2f\n", cidade1, estado1, PIBperCapita1);
    printf("Carta 2 - %s (%c): %.2f\n", cidade2, estado2, PIBperCapita2);

    if (PIBperCapita1 > PIBperCapita2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (PIBperCapita2 > PIBperCapita1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Houve um empate!\n");
    }

    printf("\n--- Menu ---\n");
    printf("1. Populacao\n2. Area\n3. PIB\n");
    printf("Escolha o atributo: ");
    scanf(" %d", &menu);

    switch (menu)
    {
    case 1:{ // Caso o jogador escolha a POPULAÇÃO
        printf("Atributo escolhido: População \n");
        printf("Carta 1 (%d) vs Carta 2 (%d):\n", populacao1, populacao2);
    if (populacao1 > populacao2){
        printf("Resultado: Carta 1 (%s) Venceu!\n", cidade1);
    }   else if (populacao2 > populacao1){
        printf("Resultado: Carta 2 (%s) Venceu!\n", cidade2);
    }   else {
        printf("Resultado: Houve um empate!\n");
    }
        break;
    }
    case 2: // Caso o jogador escolha a ÁREA
        printf("Atributo escolhido:\n");
        printf("Carta 1 (%.2f km²) vs Carta 2 (%.2f km²):\n", area1, area2);
        if (area1 > area2) {
            printf("Resultado: Carta 1 (%s) Venceu!\n", cidade1);
    } else if (area2 > area1) {
            printf("Resultado: Carta 2 (%s) Venceu!\n", cidade2);
    } else {
            printf("Resultado: Houve um empate!\n");
        }
        break;
    case 3: // Caso o jogador escolha o PIB
        printf("Atributo escolhido: PIB \n");
        printf("Carta 1 (%.2f bilhões) vs Carta 2 (%.2f bilhões):\n", PIB1, PIB2);
    if (PIB1 > PIB2){
        printf("Resultado: Carta 1 (%s) Venceu!\n", cidade1);
    } else if (PIB2 > PIB1){
        printf("Resultado: Carta 2 (%s) Venceu!\n", cidade2);
    } else {
        printf("Resultado: Houve um empate!\n");
    }
    default:
        printf("Opção inválida\n");
        break;
    }
    
    return 0;
}