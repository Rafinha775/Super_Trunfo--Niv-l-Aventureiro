#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct Carta {
    char codigo[10]; 
    char nome[50];
    int populacao;
    float area; 
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

// Declarações de funções
float calcularDensidade(int populacao, float area);
void exibirMenu();
void exibirCarta(Carta carta, int numero);
void compararCartas(Carta carta1, Carta carta2, int opcao);

int main() {
    // Inicialização das cartas (dados do desafio anterior)
    Carta carta1, carta2;
    int opcao;
    
    // Carta 1 - Brasil
    strcpy(carta1.codigo, "A01");
    strcpy(carta1.nome, "Arapirica");
    carta1.populacao = 234696;
    carta1.area = 345.655;
    carta1.pib = 5.9;
    carta1.pontos_turisticos = 3;
    carta1.densidade_demografica = calcularDensidade(carta1.populacao, carta1.area);
    
    // Carta 2 - Japão
    strcpy(carta2.codigo, "B01");
    strcpy(carta2.nome, "Indiara");
    carta2.populacao = 17061;
    carta2.area = 956.47;
    carta2.pib = 656.3;
    carta2.pontos_turisticos = 2;
    carta2.densidade_demografica = calcularDensidade(carta2.populacao, carta2.area);
    
    // Exibir as cartas

    printf("***BEM-VINDO AO SUPER TRUNFO!***\n");   
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Loop principal do jogo
    do {
        exibirMenu();
        scanf("%d", &opcao);
        if (opcao >= 1 && opcao <= 5) {
            compararCartas(carta1, carta2, opcao);
        } else if (opcao != 0) {
            printf("Opção Inválida!.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Função para calcular a densidade demográfica
float calcularDensidade(int populacao, float area) {
    if (area > 0) {
        return populacao / area;
    }
    return 0;
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n");
    printf("     SUPER TRUNFO - MENU     \n");
    printf("\n");
    printf("Escolha o atributo para comparação:\n");
    printf("1 -Populção\n");
    printf("2 - Área (km²)\n");
    printf("3 - PIB (bilhões)\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (hab/km²)\n");
    printf("0 - Sair\n");

}

// Função para exibir informções de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\n --- CARTA %d --- \n", numero);
    printf("Código: %s\n", carta.codigo);
    printf("País: %s\n", carta.nome);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidade_demografica);
    printf("\n     \n");

}

// Função para comparar cartas e exibir resultados
void compararCartas(Carta carta1, Carta carta2, int opcao) {
    printf("\n   \n");
    printf("     RESULTADO DA COMPARAÇÃO     \n");
    printf("\n   \n");
    switch(opcao) {
        case 1: // População
        printf("Atributo: POPULAÇÃO\n");
        printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
        printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
        printf("\n   \n");

        if (carta1.populacao > carta2.populacao) {
            printf("VENCEDOR -> : %s!\n", carta1.nome);
            printf("Diferença: %d habitantes\n", carta1.populacao - carta2.populacao);
        } else if (carta2.populacao > carta1.populacao) {
            printf("VENCEDOR -> %s!\n", carta2.nome);
            printf("Diferença: %d habitantes\n", carta2.populacao - carta1.populacao);
        } else {
            printf("---EMPATE---\n");
        }
        break;

        case 2: // Área
        printf("Atributo: Área\n");
        printf("%s: %.2f km²\n", carta1.nome, carta1.area);
        printf("%s: %.2f km²\n", carta2.nome, carta2.area);
        printf("\n   \n");

        if (carta1.area > carta2.area) {
            printf("VENCEDOR -> %s!\n", carta1.nome);
            printf("Diferença: %.2f km²\n", carta1.area - carta2.area);
        } else if (carta2.area > carta1.area) {
            printf("VENCEDOR -> %s!\n", carta2.nome);
            printf("Diferença: %.2f km²\n", carta2.area - carta1.area);
        } else {
            printf("---EMPATE---\n");
        }
        break;

        case 3: // PIB
        printf("Atributo: PIB\n");
        printf("%s: %.2f bilhões\n", carta1.nome, carta1.pib);
        printf("%s: %.2f bilhões\n", carta2.nome, carta2.pib);
        printf("\n   \n");

        if (carta1.pib > carta2.pib) {
            printf("VENCEDOR -> %s!\n", carta1.nome);
            printf("Diferença: %.2f bilhões\n", carta1.pib - carta2.pib);
        } else if (carta2.pib > carta1.pib) {
            printf("VENCEDOR -> %s!\n", carta2.nome);
            printf("Diferença: %.2f bilhões\n", carta2.pib - carta1.pib);
        } else {
            printf("---EMPATE---\n");
        }
        break;

        case 4: // Pontos Turísticos
        printf("Atributo: PONTOS TURÍSTICOS\n");
        printf("%s: %d pontos\n", carta1.nome, carta1.pontos_turisticos);
        printf("%s: %d pontos\n", carta2.nome, carta2.pontos_turisticos);
        printf("\n   \n");
    
        if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
            printf("VENCEDOR -> %s!\n", carta1.nome);
            printf("Diferença: %d pontos\n", carta1.pontos_turisticos - carta2.pontos_turisticos);
        } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
            printf("VENCEDOR -> %s!\n", carta2.nome);
            printf("Diferença: %d pontos\n", carta2.pontos_turisticos - carta1.pontos_turisticos);
        } else {
            printf("---EMPATE---\n");
        }
        break;

        case 5: // Densidade Demográfica
        printf("Atributo: DENSIDADE DEMOGRÁFICA\n");
        printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidade_demografica);
        printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidade_demografica);
        printf("\n   \n");
    
        if (carta1.densidade_demografica < carta2.densidade_demografica) {
            printf("VENCEDOR -> %s!\n", carta1.nome);
            printf("Diferença: %.2f hab/km²\n", carta2.densidade_demografica - carta1.densidade_demografica);
        } else if (carta2.densidade_demografica < carta1.densidade_demografica) {
            printf("VENCEDOR -> %s!\n", carta2.nome);
            printf("Diferença: %.2f hab/km²\n", carta1.densidade_demografica - carta2.densidade_demografica);
        } else {
            printf("---EMPATE---\n");
        }
        break;
    
        default:
        printf("Opção Inválida!.\n");
        break;
    }

    return;
}