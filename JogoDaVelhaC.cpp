#include <iostream>
using namespace std;

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

// Função para verificar se há um vencedor
char verificarVencedor(char tabuleiro[3][3]) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return tabuleiro[i][0];
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return tabuleiro[0][i];
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return tabuleiro[0][2];
    }

    // Se não houver vencedor
    return ' ';
}

int main() {
    char tabuleiro[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char jogadorAtual = 'X';
    int linha, coluna;
    char vencedor = ' ';

    cout << "Bem-vindo ao Jogo da Velha!" << endl;

    while (vencedor == ' ' && jogadorAtual != 'T') {
        imprimirTabuleiro(tabuleiro);

        // Solicitar a jogada do jogador
        cout << "Jogador " << jogadorAtual << ", insira a linha (1, 2 ou 3) e coluna (1, 2 ou 3) da sua jogada: ";
        cin >> linha >> coluna;

        // Verificar se a jogada é válida
        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ') {
            cout << "Jogada inválida. Tente novamente." << endl;
            continue;
        }

        // Registrar a jogada
        tabuleiro[linha - 1][coluna - 1] = jogadorAtual;

        // Verificar se há um vencedor
        vencedor = verificarVencedor(tabuleiro);

        // Alternar para o próximo jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    imprimirTabuleiro(tabuleiro);

    // Exibir resultado do jogo
    if (vencedor == 'X' || vencedor == 'O') {
        cout << "Jogador " << vencedor << " venceu!" << endl;
    } else {
        cout << "O jogo terminou em empate." << endl;
    }

    return 0;
}

