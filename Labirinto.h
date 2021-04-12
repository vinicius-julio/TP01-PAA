/* 
 * File:   Labirinto.h
 * Authors: Matheus Freitas Martins (3031) / Vinicius Barbosa (3495) / Lucas Costa (3511)
 *
 */

#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "Estudante.h"

#define MODOANALISE 1 // 1 para ativado 0 para desativado
#define MOVIMENTO_PROIBIDO 0
#define MOVIMENTO_REALIZADO 1
#define VERDE_JOGADOR 0
#define BRANCO_VAZIO 1
#define AZUL_PAREDE 2
#define VERMELHO_PORTA 3
#define CIMA 0
#define ESQUERDA 1
#define DIREITA 2
#define BAIXO 3
#define NAO_VISITADO 0
#define VISITADO 1

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Labirinto{
        int num_linhas;
        int num_colunas;
        Estudante *estudante; // guarda posicao e quantidade de chaves restantes
        int **m; // matriz do labirinto
        int **v; // matriz de posicoes visitadas
        int nivel_recursividade;
        int max_nivel_recursividade;
        int num_recursoes;
    } Labirinto;
    
    void inicializarLabirinto(Labirinto **labirinto, int num_linhas, 
            int num_colunas, int ***matriz_labirinto, int qtd_chaves_jogador);
    void imprimirLabirinto(Labirinto *labirinto);
    void imprimirMatrizConfiguracaoLabirinto(Labirinto *labirinto);
    void imprimirMatrizPosicoesVisitadasLabirinto(Labirinto *labirinto);    
    void freeLabirinto(Labirinto **labirinto);
    int resolverLabirinto(Labirinto *labirinto);
    int movimenta_estudante(Labirinto *labirinto, int linha, int coluna);    
    


#ifdef __cplusplus
}
#endif

#endif /* LABIRINTO_H */

