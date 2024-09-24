#ifndef PILHA_OPERADORES_H
#define PILHA_OPERADORES_H

#include <stdbool.h>

#define TAMANHO_OPERADORES 100

bool pushOperadores(char dado);
bool popOperadores(char *dado);
bool estaCheiaOperadores();
bool estaVaziaOperadores();
void imprimirOperadores();
char topo_operadores();

#endif // PILHA_OPERADORES_H
