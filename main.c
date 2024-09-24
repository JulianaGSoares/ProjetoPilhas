#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Para a função isdigit
#include <stdlib.h> // Para a função atof

#include "funcoes.h"
#include "funcoes.c"
#include "pilha_numeros.h"
#include "pilha_numeros.c"
#include "pilha_operadores.h"
#include "pilha_operadores.c"

int main() {
    char exp[100] = ""; // Expressão a ser calculada
    char vec[100][20] = {'\0'}; // Matriz para armazenar tokens da expressão

    limpaVetor(vec, 100); // Limpa a matriz de tokens

    strcpy(exp, "((22 + 5) * 2) / 3"); // Expressão a ser calculada

    stringParaVetor(exp, vec, 100); // Converte a expressão em uma matriz de tokens

    printf("-----\n");

    char operadores; // Pilha para armazenar os operadores
    double numero1; // Pilha para armazenar os números
    double numero2; // Inicializa o topo da pilha de operadores como -1
    double resultado; // Inicializa o topo da pilha de números como -1

    for(int i = 0; i < 100 && (strcmp(vec[i], "") !=  0); i++) {
        printf("| %s |", vec[i]);
        printf("\n-----");
        printf("\n");
    }

    // Loop para percorrer todos os tokens na expressão
    for (int i = 0; i < 100 && (strcmp(vec[i], "")); i++) {
        // Verifica se o token atual é um número
        if (isdigit(vec[i][0]) || vec[i][0] == '.') {
            // Incrementa o topo da pilha de números
            pushNumeros(atof(vec[i]));
            // Converte e armazena o número na pilha de números
        } else {
            // Se o token atual é um operador
            // Loop para lidar com operadores de maior ou igual precedência na pilha
            for (int j = 0; vec[i][j] != '\0'; j++) {
                if (vec[i][j] != ')') {
                    pushOperadores(vec[i][j]);
                } else {
                    while (topo_operadores() != '(' && mesmaOuMaiorPrecedencia(vec[i][j], topo_operadores())) {
                        numero1 = topo_numeros();
                        popNumeros(&numero1);
                        numero2 = topo_numeros();
                        popNumeros(&numero2);

                        operadores = topo_numeros();
                        popOperadores(&operadores);

                        resultado = calcularExpressao(numero2, numero1, operadores);
                        pushNumeros(resultado);
                    }
                    //pop parenteses
                    char abrirParenteses = topo_operadores();
                    popOperadores(&abrirParenteses);
                }
            }
        }
    }

    // Calcular até zerar a pilha de operadores
    while (!estaVaziaOperadores()) {
        numero1 = topo_numeros();
        popNumeros(&numero1);
        numero2 = topo_numeros();

        operadores = topo_operadores();
        popOperadores(&operadores);

        resultado = calcularExpressao(numero2, numero1, operadores);
        pushNumeros(resultado);
    }

    printf("\nResultado da expressao: %lf\n", topo_numeros());
    // Calcula e exibe o resultado da expressão
    printf("\n");

    return 0;
}
