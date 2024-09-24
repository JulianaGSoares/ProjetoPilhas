#include <stdio.h>
#include <stdbool.h>

#include "pilha_numeros.h"

int pilhaNumeros[TAMANHO_NUMEROS];
int posicaoNumeros = 0;

// Funções
bool pushNumeros(double dado)
{
    if(estaCheiaNumeros())
    {
        return false;
    }
    pilhaNumeros[posicaoNumeros] = dado;
    posicaoNumeros++;

    return true;
}

bool popNumeros(double *dado)
{
    if(estaVaziaNumeros())
    {
        return false;
    }
    posicaoNumeros--;
    *dado = pilhaNumeros[posicaoNumeros];
    return true;
}

bool estaCheiaNumeros()
{
    return posicaoNumeros == TAMANHO_NUMEROS;
}

bool estaVaziaNumeros()
{
    return posicaoNumeros == 0;
}

void imprimirNumeros()
{
    for(int i = (posicaoNumeros - 1); i >= 0; i--)
    {
        printf("| %d |\n", pilhaNumeros[i]);
    }
    if(!estaVaziaNumeros())
    {
        printf("+---+\n");
    }
}
float topo_numeros(){
    // printf("\n\nPosicao: %d",posicao_val-1);
    // printf("\nPilha: %d",pilha_val[posicao_val-1]);
    return pilhaNumeros[posicaoNumeros - 1];
}