#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Carta 1:
    char estado1;    
    char codigo1 [4];  
    char cidade1[50];   
    int populacao1;
    float area1;
    float PIB1;
    int pontoturistico1;
    float DensidadePopulacional1;
    float PIBperCapita1;
    float SuperPoder1;  
    
    // Carta 2
    char estado2;
    char codigo2 [4];
    char cidade2[50];
    int populacao2;
    float area2;
    float PIB2;    
    int pontoturistico2;
    float DensidadePopulacional2;
    float PIBperCapita2;
    float SuperPoder2;

    // Ajuste de variáveis para a comparação real das cartas
    char primeiroAtributo, segundoAtributo;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    int controleLoop = 0;

    // --- CADASTRO DA CARTA 1 ---
    printf(" ~~~~~~ Carta 01 ~~~~~~ \n");
    printf("    Coloque os dados da primeira carta    \n");
    printf("Estado A-Z: \n");
    scanf(" %c", &estado1); // Adicionado espaço antes do %c para limpar buffer

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

    // --- CADASTRO DA CARTA 2 ---
    printf("\n ~~~~~~ Carta 02 ~~~~~~ \n");
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

    // Menu 1
    while (controleLoop == 0) {
        printf("\n---- Itens ----\n");
        printf("Selecione o PRIMEIRO Item para comparacao:\n");
        printf("P. Populacao\n");
        printf("A. Area\n");
        printf("I. PIB\n");
        printf("D. Densidade Demografica\n");
        printf("Escolha: ");
        scanf(" %c", &primeiroAtributo);

        switch (primeiroAtributo) {
            case 'P': case 'p':
                valor1_carta1 = (float)populacao1;
                valor1_carta2 = (float)populacao2;
                controleLoop = 1; break;
            case 'A': case 'a':
                valor1_carta1 = area1;
                valor1_carta2 = area2;
                controleLoop = 1; break;
            case 'I': case 'i':
                valor1_carta1 = PIB1;
                valor1_carta2 = PIB2;
                controleLoop = 1; break;
            case 'D': case 'd':
                // Exceção: Como menor densidade vence, guardamos invertido para a soma fazer sentido
                valor1_carta1 = DensidadePopulacional2; 
                valor1_carta2 = DensidadePopulacional1; 
                controleLoop = 1; break;
            default:
                printf("Alternativa incorreta! Tente novamente.\n");
                break;
        }
    }

    controleLoop = 0; // Reseta para o segundo menu


    // MENU 2: MENU DINÂMICO (Esconde o primeiro)
    while (controleLoop == 0) {
        printf("\nSelecione o SEGUNDO Item (Diferente do primeiro):\n");
        
        // Só exibe na tela o que NÃO foi escolhido no menu 1
        if (primeiroAtributo != 'P' && primeiroAtributo != 'p')
         printf("P. Populacao\n");
        if (primeiroAtributo != 'A' && primeiroAtributo != 'a') 
        printf("A. Area\n");
        if (primeiroAtributo != 'I' && primeiroAtributo != 'i')
         printf("I. PIB\n");
        if (primeiroAtributo != 'D' && primeiroAtributo != 'd')
         printf("D. Densidade Demografica\n");
        
        printf("Selecione: ");
        scanf(" %c", &segundoAtributo);

        switch (segundoAtributo) {
            case 'P': 
            case 'p':
                valor2_carta1 = (float)populacao1;
                valor2_carta2 = (float)populacao2;
                controleLoop = 1; 
             break;
            case 'A': 
            case 'a':
                valor2_carta1 = area1;
                valor2_carta2 = area2;
                controleLoop = 1;
             break;
            case 'I':
            case 'i':
                valor2_carta1 = PIB1;
                valor2_carta2 = PIB2;
                controleLoop = 1;
             break;
            case 'D': 
            case 'd':
                // Exceção da densidade replicada 
                valor2_carta1 = DensidadePopulacional2;
                valor2_carta2 = DensidadePopulacional1;
                controleLoop = 1;
             break;
            default:
                printf("Alternativa errada! Escolha outra.\n");
                break;
        }
    }

    // Soma dos atributos + soma dos valores
    float somaCarta1 = valor1_carta1 + valor2_carta1;
    float somaCarta2 = valor1_carta2 + valor2_carta2;

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("            RESULTADO DO GAME            \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Carta 1 - %s:\n", cidade1);
    printf("  Soma dos Itens Escolhidos: %.2f\n\n", somaCarta1);

    printf("Carta 2 - %s:\n", cidade2);
    printf("  Soma dos Itens Escolhidos: %.2f\n", somaCarta2);
    printf("-----------------------------------------\n");

    // Condicional de vitória por soma e tratamento de empates
    if (somaCarta1 > somaCarta2) {
        printf("Vencedor: Carta 1 (%s)!\n", cidade1);
    } else if (somaCarta2 > somaCarta1) {
        printf("Vencedor: Carta 2 (%s)!\n", cidade2);
    } else {
        printf("Empate!\n");
    }
    printf("=========================================\n");

    return 0;
}