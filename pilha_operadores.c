#include <stdio.h>
#include <stdbool.h>

#include "pilha_operadores.h"

int pilhaOperadores[TAMANHO_OPERADORES];
int posicaoOperadores = 0;

// Variáveis
int pilhaOperadores[TAMANHO_OPERADORES];

// Funções
bool pushOperadores(char dado)
{
    if(estaCheiaOperadores())
    {
        return false;
    }
    pilhaOperadores[posicaoOperadores] = dado;
    posicaoOperadores++;

    return true;
}

bool popOperadores(char *dado)
{
    if(estaVaziaOperadores())
    {
        return false;
    }
    posicaoOperadores--;
    *dado = pilhaOperadores[posicaoOperadores];
    return true;
}

bool estaCheiaOperadores()
{
    return posicaoOperadores == TAMANHO_OPERADORES;
}

bool estaVaziaOperadores()
{
    return posicaoOperadores == 0;
}

void imprimirOperadores()
{
    for(int i = (posicaoOperadores - 1); i >= 0; i--)
    {
        printf("| %c |\n", pilhaOperadores[i]);
    }
    if(!estaVaziaOperadores())
    {
        printf("+---+\n");
    }
}
char topo_operadores(){
    // printf("\n\nPosicao: %d",posicao_val-1);
    // printf("\nPilha: %d",pilha_val[posicao_val-1]);
    return pilhaOperadores[posicaoOperadores-1];
}