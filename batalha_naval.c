#include <stdio.h>

#define TAM 10       // tamanho do tabuleiro 10x10
#define NAVIO 3      // valor que representa navio
#define AGUA 0       // valor que representa água
#define HABILIDADE 5 // valor que representa área de habilidade
#define TAM_NAVIO 3  // tamanho fixo dos navios
#define TAM_HAB 5    // tamanho fixo da matriz de habilidade (5x5)

// Funções Auxiliares

// Verifica se é possível posicionar navio (sem sair e sem sobreposição)
int podePosicionar(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0; // inválido
        if (tabuleiro[linha[i]][coluna[i]] == NAVIO)
            return 0; // sobreposição
    }
    return 1;
}

// Posiciona navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

// Cria matriz Cone (5x5)
void criarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Forma de triângulo apontando para baixo
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i) && i <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz Cruz (5x5)
void criarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz Octaedro (losango 5x5)
void criarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica habilidade no tabuleiro, centrando a matriz no ponto (linhaOrigem, colOrigem)
void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[TAM_HAB][TAM_HAB], int linhaOrigem, int colOrigem) {
    int desloc = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (matriz[i][j] == 1) {
                int li = linhaOrigem + (i - desloc);
                int co = colOrigem + (j - desloc);
                // valida dentro dos limites
                if (li >= 0 && li < TAM && co >= 0 && co < TAM) {
                    if (tabuleiro[li][co] == AGUA) // não sobrescreve navio
                        tabuleiro[li][co] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== Tabuleiro ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf("~ ");       // água
            else if (tabuleiro[i][j] == NAVIO) printf("N "); // navio
            else if (tabuleiro[i][j] == HABILIDADE) printf("* "); // área habilidade
        }
        printf("\n");
    }
}

// Função Principal
int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionar alguns navios fixos
    int n1_linha[] = {2, 2, 2};
    int n1_coluna[] = {1, 2, 3};

    int n2_linha[] = {5, 6, 7};
    int n2_coluna[] = {7, 7, 7};

    if (podePosicionar(tabuleiro, n1_linha, n1_coluna))
        posicionarNavio(tabuleiro, n1_linha, n1_coluna);
    if (podePosicionar(tabuleiro, n2_linha, n2_coluna))
        posicionarNavio(tabuleiro, n2_linha, n2_coluna);

    // Criar matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicar habilidades em pontos do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 5);     // cone centrado em (1,5)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);     // cruz centrada em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 8, 2); // octaedro centrado em (8,2)

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
