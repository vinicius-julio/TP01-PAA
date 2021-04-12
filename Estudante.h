/* 
 * File:   Estudante.h
 * Authors: Matheus Freitas Martins (3031) / Vinicius Barbosa (3495)/ Lucas Costa (3511)
 *
 */

#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include "ListaCaminhoPercorrido.h"

#define NAO_CHEGOU_AO_OBJETIVO 0
#define CHEGOU_AO_OBJETIVO 1

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Estudante{ // guarda posicao e quantidade de chaves restantes
        int linha;
        int coluna;
        int qtd_chaves_restantes;
        ListaCaminhoPercorrido *listaCaminhoPercorrido;
    } Estudante;
    
    void inicializarEstudante(Estudante **estudante, int linha, int coluna, int qtd_chaves_restantes);
    int verificarPosicaoEstudante(Estudante *estudante);
    void imprimirEstudante(Estudante *estudante);


#ifdef __cplusplus
}
#endif

#endif /* ESTUDANTE_H */

