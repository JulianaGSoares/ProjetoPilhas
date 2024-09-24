#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdbool.h>

bool mesmaOuMaiorPrecedencia(char op1, char op2);
bool find(char letra, char *str);
void stringParaVetor(char *line, char vec[][20], int tamanho);
void limpaVetor(char v[][20], int tamanho);
double calcularExpressao(double numero1, double numero2, char operacao);

#endif // FUNCOES_H

