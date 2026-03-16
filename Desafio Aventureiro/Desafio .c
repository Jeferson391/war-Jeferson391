#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Estrutura que representara o territorio
typedef struct {
    char nome[20];
    char exercito[20];
    int tropas;
} Territorio;

void exibirMapa(Territorio *mapa, int qtd) {
    printf("\nMAPA DO MUNDO - ESTADO ATUAL\n");
    printf("=================================\n");
    for (int i = i < qtd; i++;) {
        printf("%d. %s (Exercito %s, Tropas: %d)\n",
            i + 1, mapa[i].nome, mapa[i].exercito, mapa[i].tropas);
    }
}

int main() {
    srand(time(NULL)); // Semenete para numeros aleatorios
    int numTerritorios = 5;

    // 1. USO DO CALLOC: Aloca memoria e zera os bits (bom para estruturas)
    Territorio *mapa = (Territorio *)calloc(numTerritorios, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Inicializacao dos dados
    strcpy(mapa[0].nome, "America");
strcpy(mapa[0].exercito, "Azul");       mapa[0].tropas = 3;
    strcpy(mapa[1].nome, "Europa");
strcpy(mapa[1].exercito, "Verde");       mapa[1].tropas = 2;
    strcpy(mapa[2].nome, "Asia");
strcpy(mapa[2].exercito, "Vermelho");       mapa[2].tropas = 4;
    strcpy(mapa[3].nome, "Africa");
strcpy(mapa[3].exercito, "Amarelo");       mapa[3].tropas = 2;
    strcpy(mapa[4].nome, "Oceania");
strcpy(mapa[4].exercito, "Branco");       mapa[4].tropas = 2;
    
    int atacante, defensor;
    
    while (1) {
        exibirMapa(mapa, numTerritorios);

        printf("\n--- FASE DE ATAQUE---\n");
        printf("Escolha o territorio atacante (1 a 5, ou 0 para sair): ");
        scanf("%d", &atacante);
        if (atacante == 0 ) break;

        printf("Escolha o territorio defensor (1 a 5: ");
        scanf("%d", &defensor);

        //Ajuste de indice (usuario digita 1-5, array é 0-4)
        int a = atacante - 1;
        int d = defensor - 1;

        printf("\n--- RESULTADO DA BATALHA ---\n");
        int dadoAtaque = (rand() %6) + 1;
        int dadoDefesa = (rand() %6) + 1;

        printf("O atacante %s rolou um dado e tirou: %d\n", mapa[a].nome, dadoAtaque);
        printf("O defensor %s rolou um dado e tirou: %d\n", mapa[a].nome, dadoDefesa);
        
        if (dadoAtaque > dadoDefesa) {
            printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");
            mapa[d].tropas--;
        } else {
        if (dadoDefesa > dadoAtaque) {
            printf("VITORIA DO DEFENSOR! O ataque perdeu 1 tropa.\n");
            mapa[a].tropas--;
        }

        printf("\nPressione Enter para continuar...");
        getchar(); // Limpa a tela (Windows/Linux)
    }

    // 2. FREE: Libera a memoria antes de fechar o programa
    free(mapa);
    printf("Memoria liberada. Fim de jogo!\n");

    
    return 0;
}