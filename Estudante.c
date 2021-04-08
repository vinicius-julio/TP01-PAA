#include "Estudante.h"

void inicializarEstudante(Estudante **estudante, int linha, int coluna, int qtd_chaves_restantes){
    (*estudante) = (Estudante*) malloc(sizeof(Estudante));
    (*estudante)->linha = linha;
    (*estudante)->coluna = coluna;    
    (*estudante)->qtd_chaves_restantes = qtd_chaves_restantes;    
    inicializarListaCaminhoPercorrido(&((*estudante)->listaCaminhoPercorrido), linha, coluna);
}

int verificarPosicaoEstudante(Estudante *estudante){
    if(estudante->linha == 0) return CHEGOU_AO_OBJETIVO;
    return NAO_CHEGOU_AO_OBJETIVO;
}

void imprimirEstudante(Estudante *estudante){
    printf("\n**Impressao do Estudante**\n");
    printf("Linha: %d\nColuna: %d\n", estudante->linha, estudante->coluna);
    printf("Chaves restantes: %d\n", estudante->qtd_chaves_restantes);
    printf("Caminho percorrido:\n");
    imprimirListaCaminhoPercorrido(estudante->listaCaminhoPercorrido);
}