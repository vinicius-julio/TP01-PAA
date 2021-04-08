/* 
 * File:   ListaCaminhoPercorrido.h
 * Authors: Matheus Freitas Martins (3031) / Vinicius Haner / Lucas Costa
 *
 */

#ifndef LISTACAMINHOPERCORRIDO_H
#define LISTACAMINHOPERCORRIDO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef struct ItemListaCaminhoPercorrido{
        int linha;
        int coluna;
        struct ItemListaCaminhoPercorrido *prox;
    } ItemListaCaminhoPercorrido;
    
    typedef struct ListaCaminhoPercorrido{
        ItemListaCaminhoPercorrido *primeiro;
        ItemListaCaminhoPercorrido *ultimo;
    } ListaCaminhoPercorrido;

    void inicializarListaCaminhoPercorrido(ListaCaminhoPercorrido **lista, int linha, int coluna);
    void adicionarPosicaoListaCaminhoPercorrido(ListaCaminhoPercorrido *lista, int linha, int coluna);
    void imprimirListaCaminhoPercorrido(ListaCaminhoPercorrido *lista);
    int retornarNumeroMovimentos(ListaCaminhoPercorrido *lista);
    void freeListaCaminhoPercorrido(ListaCaminhoPercorrido **lista);    


#ifdef __cplusplus
}
#endif

#endif /* LISTACAMINHOPERCORRIDO_H */

