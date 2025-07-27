#include <stdio.h>
#include <stdlib.h> // Usada para a função abs(), que calcula o valor absoluto

int main() {
    // --- 1. DEFINIÇÃO DO TABULEIRO E DOS NAVIOS ---
    int tabuleiro[10][10] = {0}; // Tabuleiro principal 10x10, tudo é água (0)

    // Posiciona um navio para vermos a interação com as habilidades
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;

    printf("--- Tabuleiro Inicial com um Navio ---\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // --- 2. HABILIDADE CRUZ ---
    printf("--- Aplicando Habilidade CRUZ ---\n");
    int habilidade_cruz[5][5];
    int centro_cruz = 5 / 2; // O centro de uma matriz 5x5 é o índice 2
    int origem_linha_cruz = 3;
    int origem_coluna_cruz = 4;

    // Primeiro, cria o padrão da cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == centro_cruz || j == centro_cruz) {
                habilidade_cruz[i][j] = 1; // Área de efeito
            } else {
                habilidade_cruz[i][j] = 0; // Fora do efeito
            }
        }
    }

    // Agora, aplica o padrão da cruz no tabuleiro principal
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade_cruz[i][j] == 1) {
                int linha_no_tabuleiro = origem_linha_cruz - centro_cruz + i;
                int coluna_no_tabuleiro = origem_coluna_cruz - centro_cruz + j;

                // Verifica se a posição está dentro do tabuleiro 10x10
                if (linha_no_tabuleiro >= 0 && linha_no_tabuleiro < 10 &&
                    coluna_no_tabuleiro >= 0 && coluna_no_tabuleiro < 10) {
                    tabuleiro[linha_no_tabuleiro][coluna_no_tabuleiro] = 5; // Marca com 5
                }
            }
        }
    }

    // --- 3. HABILIDADE CONE ---
    printf("--- Aplicando Habilidade CONE ---\n");
    int habilidade_cone[5][5];
    int centro_cone = 5 / 2;
    int origem_linha_cone = 1;
    int origem_coluna_cone = 7;

    // Cria o padrão do cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // A condição abs(j - centro) <= i cria um triângulo/cone
            if (i < 3 && abs(j - centro_cone) <= i) {
                habilidade_cone[i][j] = 1;
            } else {
                habilidade_cone[i][j] = 0;
            }
        }
    }

    // Aplica o padrão do cone no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade_cone[i][j] == 1) {
                int linha_no_tabuleiro = origem_linha_cone - centro_cone + i;
                int coluna_no_tabuleiro = origem_coluna_cone - centro_cone + j;

                if (linha_no_tabuleiro >= 0 && linha_no_tabuleiro < 10 &&
                    coluna_no_tabuleiro >= 0 && coluna_no_tabuleiro < 10) {
                    tabuleiro[linha_no_tabuleiro][coluna_no_tabuleiro] = 5;
                }
            }
        }
    }

    // --- 4. HABILIDADE OCTAEDRO ---
    printf("--- Aplicando Habilidade OCTAEDRO ---\n");
    int habilidade_octaedro[5][5];
    int centro_octaedro = 5 / 2;
    int origem_linha_octaedro = 7;
    int origem_coluna_octaedro = 8;

    // Cria o padrão do octaedro/losango
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // A distância de Manhattan (soma das distâncias) cria o losango
            if (abs(i - centro_octaedro) + abs(j - centro_octaedro) <= 1) {
                habilidade_octaedro[i][j] = 1;
            } else {
                habilidade_octaedro[i][j] = 0;
            }
        }
    }

    // Aplica o padrão do octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade_octaedro[i][j] == 1) {
                int linha_no_tabuleiro = origem_linha_octaedro - centro_octaedro + i;
                int coluna_no_tabuleiro = origem_coluna_octaedro - centro_octaedro + j;

                if (linha_no_tabuleiro >= 0 && linha_no_tabuleiro < 10 &&
                    coluna_no_tabuleiro >= 0 && coluna_no_tabuleiro < 10) {
                    tabuleiro[linha_no_tabuleiro][coluna_no_tabuleiro] = 5;
                }
            }
        }
    }

    // --- 5. EXIBIÇÃO FINAL ---
    printf("\n--- Tabuleiro FINAL com todas as habilidades ---\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
