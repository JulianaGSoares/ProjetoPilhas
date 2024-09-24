#ifndef PILHA_NUMEROS_H
#define PILHA_NUMEROS_H

#include <stdbool.h>

#define TAMANHO_NUMEROS 100

bool pushNumeros(double dado);
bool popNumeros(double *dado);
bool estaCheiaNumeros();
bool estaVaziaNumeros();
void imprimirNumeros();
float topo_numeros();

#endif // PILHA_NUMEROS_H

