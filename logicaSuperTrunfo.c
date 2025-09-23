#include <stdio.h>

// Estrutura de uma carta
typedef struct {
    char Estado[20];
    char Codigo[10];
    char Cidade[30];
    int Populacao;
    float Km2;
    float PIB;
    int PontosT;
} Carta;

int main() {
    int totalCartas;

    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &totalCartas);

    Carta baralho[50]; // até 50 cartas

    // Cadastro das cartas
    for (int i = 0; i < totalCartas; i++) {
        printf("\n=== Cadastro da Carta %d ===\n", i + 1);

        printf("Estado: ");
        scanf(" %[^\n]", baralho[i].Estado);

        printf("Código: ");
        scanf(" %s", baralho[i].Codigo);

        printf("Cidade: ");
        scanf(" %[^\n]", baralho[i].Cidade);

        printf("População: ");
        scanf("%d", &baralho[i].Populacao);

        printf("KM²: ");
        scanf("%f", &baralho[i].Km2);

        printf("PIB: ");
        scanf("%f", &baralho[i].PIB);

        printf("Pontos Turísticos: ");
        scanf("%d", &baralho[i].PontosT);
    }

    // Escolha das cartas pelos jogadores
    int carta1, carta2, atributo;

    printf("\n===== JOGO SUPER TRUNFO =====\n");
    printf("Jogador 1, escolha o número da sua carta (1 a %d): ", totalCartas);
    scanf("%d", &carta1);
    printf("Jogador 2, escolha o número da sua carta (1 a %d): ", totalCartas);
    scanf("%d", &carta2);

    carta1--; // ajustar índice
    carta2--;

    // Mostrar cartas escolhidas
    printf("\n--- Carta do Jogador 1 ---\n");
    printf("Estado: %s | Cidade: %s | População: %d | KM²: %.2f | PIB: %.2f | Pontos: %d\n",
           baralho[carta1].Estado, baralho[carta1].Cidade, baralho[carta1].Populacao,
           baralho[carta1].Km2, baralho[carta1].PIB, baralho[carta1].PontosT);

    printf("\n--- Carta do Jogador 2 ---\n");
    printf("Estado: %s | Cidade: %s | População: %d | KM²: %.2f | PIB: %.2f | Pontos: %d\n",
           baralho[carta2].Estado, baralho[carta2].Cidade, baralho[carta2].Populacao,
           baralho[carta2].Km2, baralho[carta2].PIB, baralho[carta2].PontosT);

    // Escolha do atributo
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - KM²\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("Opção: ");
    scanf("%d", &atributo);

    // Comparação
    int resultado = 0; // 0 = empate, 1 = jogador 1 vence, 2 = jogador 2 vence
    switch (atributo) {
        case 1:
            if (baralho[carta1].Populacao > baralho[carta2].Populacao) resultado = 1;
            else if (baralho[carta1].Populacao < baralho[carta2].Populacao) resultado = 2;
            break;
        case 2:
            if (baralho[carta1].Km2 > baralho[carta2].Km2) resultado = 1;
            else if (baralho[carta1].Km2 < baralho[carta2].Km2) resultado = 2;
            break;
        case 3:
            if (baralho[carta1].PIB > baralho[carta2].PIB) resultado = 1;
            else if (baralho[carta1].PIB < baralho[carta2].PIB) resultado = 2;
            break;
        case 4:
            if (baralho[carta1].PontosT > baralho[carta2].PontosT) resultado = 1;
            else if (baralho[carta1].PontosT < baralho[carta2].PontosT) resultado = 2;
            break;
        default:
            printf("Atributo inválido!\n");
            return 0;
    }

    // Resultado final
    if (resultado == 0) {
        printf("\nResultado: EMPATE!\n");
    } else {
        printf("\nResultado: Jogador %d venceu!\n", resultado);
    }

    return 0;
}
