cmake_minimum_required(VERSION 3.27)
project(trabalhoPilhaFinal C)

set(CMAKE_C_STANDARD 11)

# Arquivo principal e todos os arquivos de implementação
add_executable(trabalhoPilhaFinal main.c funcoes.c pilha_numeros.c pilha_operadores.c)

# Adicionando diretório com os arquivos de cabeçalho
target_include_directories(trabalhoPilhaFinal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

