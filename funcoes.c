#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "funcoes.h"

#define MAX_SIZE 100
// Definição do tamanho máximo de vetores

bool mesmaOuMaiorPrecedencia(char op1, char op2) {
    if (op2 == '(' || op2 == ')') {
        // Se o segundo operador for parêntese
        return false;
    }
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
        // Se o primeiro operador for multiplicação ou divisão e o segundo for adição ou subtração
        return false;
    } else {
        return true;
    }
}

bool find(char letra, char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        // Loop pela string
        if (str[i] == letra) {
            // Se o caractere atual é igual ao caractere fornecido
            return true;
        }
    }
    return false;
}

void stringParaVetor(char *line, char vec[][20], int tamanho) {
    char trab[tamanho];
    // Buffer para construir números ou operadores temporários
    char operacoes[] = "+-*/()";
    // Lista de operadores
    char letra;
    bool numero = false;
    bool str = false;
    int vecI = 0;
    int aux = 0;
    strcpy(trab, "");
    // Inicializa o buffer vazio

    for (int i = 0; i < tamanho; i++) {
        // Loop pela expressão
        letra = line[i];
        if ((isdigit(letra) || letra == '.') && !str) {
            // Se o caractere atual é um dígito ou um ponto decimal e não estamos em uma string
            if (!numero) {
                // Se não estamos atualmente construindo um número
                if (strlen(trab) != 0) {
                    // Se o buffer contém algo
                    strcpy(vec[vecI++], trab);
                    // Copia o conteúdo do buffer para a matriz de tokens
                    strcpy(trab, "");
                    // Limpa o buffer
                }
                numero = true;
                // Indica que estamos construindo um número
                str = false;
                // Indica que não estamos em uma string
            }
            aux = strlen(trab);
            // Tamanho atual do buffer
            trab[aux] = letra;
            // Adiciona o caractere ao buffer
            trab[aux + 1] = '\0';
            // Adiciona o caractere nulo ao final do buffer
        } else if (letra == ' ') {
            // Se o caractere atual é um espaço em branco
            if (!str) {
                // Se não estamos em uma string
                if (strlen(trab) != 0) {
                    // Se o buffer contém algo
                    strcpy(vec[vecI++], trab);
                    // Copia o conteúdo do buffer para a matriz de tokens
                    strcpy(trab, "");
                    // Limpa o buffer
                    numero = false;
                    // Indica que não estamos construindo um número
                    str = false;
                    // Indica que não estamos em uma string
                }
            }
        } else if (find(letra, operacoes) != 0) {
            // Se o caractere atual é um operador
            if (strlen(trab) != 0) {
                // Se o buffer contém algo
                strcpy(vec[vecI++], trab);
                // Copia o conteúdo do buffer para a matriz de tokens
                strcpy(trab, "");
                // Limpa o buffer
            }
            aux = strlen(trab);
            // Tamanho atual do buffer
            trab[aux] = letra;
            // Adiciona o caractere ao buffer
            trab[aux + 1] = '\0';
            // Adiciona o caractere nulo ao final do buffer
            strcpy(vec[vecI++], trab);
            // Copia o conteúdo do buffer para a matriz de tokens
            strcpy(trab, "");
            // Limpa o buffer
            numero = false;
            // Indica que não estamos construindo um número
            str = false;
            // Indica que não estamos em uma string
        }
    }
    if (strlen(trab) != 0) {
        // Se o buffer contém algo após o loop
        strcpy(vec[vecI++], trab);
        // Copia o conteúdo do buffer para a matriz de tokens
    }
}

void limpaVetor(char v[][20], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        strcpy(v[i], "");
        // Copia uma string vazia para cada posição da matriz
    }
}

double calcularExpressao(double numero1, double numero2, char operacao) {

switch (operacao)
{
    case '+':
        return numero1 + numero2;
    case '-':
        return numero1 - numero2;
    case '*':
        return numero1 * numero2;
    case '/':
        return numero1 / numero2;
   default:
    return 0;
}
}
