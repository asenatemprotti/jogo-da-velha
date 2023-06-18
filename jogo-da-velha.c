#include <stdio.h>

void exibirTabuleiro(char tabuleiro[3][3]) {
    printf ("===BEM-VINDO AO JOGO DA VELHA===\n\n");
	printf("  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

char verificarVencedor(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return tabuleiro[i][0];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return tabuleiro[0][i];
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    return ' ';
}

int main() {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int linha, coluna;
    char jogador = 'X';
    char vencedor = ' ';

    while (vencedor == ' ') {
        exibirTabuleiro(tabuleiro);

        printf("Jogador %c, eh sua vez.\n", jogador);
        printf("Digite a linha (1-3): ");
        scanf("%d", &linha);
        printf("Digite a coluna (1-3): ");
        scanf("%d", &coluna);

        linha--;
        coluna--;

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogador;
            if (jogador == 'X') {
                jogador = 'O';
            } else {
                jogador = 'X';
            }
            vencedor = verificarVencedor(tabuleiro);
        } else {
            printf("Jogada invalida. Tente novamente.\n");
        }
    }

    exibirTabuleiro(tabuleiro);

    if (vencedor == 'X' || vencedor == 'O') {
        printf("\a===Parabens! O jogador %c venceu!===\n", vencedor);
    } else {
        printf("--Empate!--\n");
    }

    return 0;
}
