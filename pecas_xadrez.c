#include <stdio.h>

// Funções recursivas

// Torre: anda N casas para a direita
void moverTorre(int casas, int atual) {
    if (atual > casas) return; // condição de parada
    printf("Direita (%d)\n", atual);
    moverTorre(casas, atual + 1); // chamada recursiva
}

// Rainha: anda N casas para a esquerda
void moverRainha(int casas, int atual) {
    if (atual > casas) return;
    printf("Esquerda (%d)\n", atual);
    moverRainha(casas, atual + 1);
}

// Bispo: recursivo + loops aninhados
// externo: vertical (cima), interno: horizontal (direita)
void moverBispo(int casas, int atual) {
    if (atual > casas) return;

    // loop interno horizontal
    for (int h = 1; h <= 1; h++) { // sempre 1 passo à direita para cada passo vertical
        printf("Cima, Direita (%d)\n", atual);
    }

    moverBispo(casas, atual + 1); // chamada recursiva
}

// Cavalo com loops complexos

void moverCavalo() {
    int passosCima = 2;
    int passosDireita = 1;

    printf("Movimento do Cavalo:\n");

    // loop externo para cima
    for (int i = 1; i <= passosCima; i++) {
        printf("Cima (%d)\n", i);

        // quando chegar no último movimento "Cima", faz a curva para direita
        if (i == passosCima) {
            for (int j = 1; j <= passosDireita; j++) {
                // condição complexa com break/continue
                if (j == 0) continue; // nunca entra, apenas para ilustrar uso de continue
                if (j > passosDireita) break;

                printf("Direita (%d)\n", j);
            }
        }
    }
}

// Função principal

int main() {
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // Movimento da Torre (recursão)

    printf("Movimento da Torre:\n");
    moverTorre(casasTorre, 1);
    printf("\n");

    // Movimento do Bispo (recursão + loop interno)

    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo, 1);
    printf("\n");

    // Movimento da Rainha (recursão)
  
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha, 1);
    printf("\n");

    // Movimento do Cavalo (loops complexos)

    moverCavalo();

    return 0;
}
