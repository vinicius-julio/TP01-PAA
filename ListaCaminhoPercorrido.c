#include "ListaCaminhoPercorrido.h"

void inicializarListaCaminhoPercorrido(ListaCaminhoPercorrido **lista, int linha, int coluna){
    (*lista) = (ListaCaminhoPercorrido*) malloc(sizeof(ListaCaminhoPercorrido));
    (*lista)->primeiro = (ItemListaCaminhoPercorrido*) malloc(sizeof(ItemListaCaminhoPercorrido));
    (*lista)->primeiro->linha = linha;
    (*lista)->primeiro->coluna = coluna;
    (*lista)->primeiro->prox = NULL;
    (*lista)->ultimo = (*lista)->primeiro;
}

void adicionarPosicaoListaCaminhoPercorrido(ListaCaminhoPercorrido *lista, int linha, int coluna){    
    lista->ultimo->prox = (ItemListaCaminhoPercorrido*) malloc(sizeof(ItemListaCaminhoPercorrido));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->linha = linha;
    lista->ultimo->coluna = coluna;
    lista->ultimo->prox = NULL;    
}

void imprimirListaCaminhoPercorrido(ListaCaminhoPercorrido *lista){
    ItemListaCaminhoPercorrido *item = lista->primeiro;
    while(item != NULL){
        printf("Linha: %d\tColuna: %d\n", item->linha, item->coluna);
        item = item->prox;        
    }    
    printf("\n");
}

int retornarNumeroMovimentos(ListaCaminhoPercorrido *lista){
    ItemListaCaminhoPercorrido *item = lista->primeiro;
    int num_movimentos = -1;
    while(item != NULL){
        num_movimentos++;
        item = item->prox;        
    }    
    return num_movimentos;
}

void freeListaCaminhoPercorrido(ListaCaminhoPercorrido **lista){
    if(lista == NULL || *lista == NULL) 
        return;
    ListaCaminhoPercorrido *r2 = *lista;
    ItemListaCaminhoPercorrido *item = r2->primeiro;
    ItemListaCaminhoPercorrido *r;        
    int qtd_movimentos = -1, coluna;
    while(item != NULL){
        r = item;
        item = item->prox;
        free(r);
    }  
    free(r2);
}