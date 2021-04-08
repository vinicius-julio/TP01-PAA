#include "Labirinto.h"

void inicializarLabirinto(Labirinto **labirinto, int num_linhas, 
            int num_colunas, int ***matriz_labirinto, int qtd_chaves_jogador){
    int i, j;
    (*labirinto) = (Labirinto*) malloc(sizeof(Labirinto));
    (*labirinto)->num_linhas = num_linhas;
    (*labirinto)->num_colunas = num_colunas;        
    (*labirinto)->m = *matriz_labirinto;
    for(i = 0; i < num_linhas; i++){
        for(j = 0; j < num_colunas; j++){
            if((*labirinto)->m[i][j] == VERDE_JOGADOR){
                inicializarEstudante(&((*labirinto)->estudante), i, j, qtd_chaves_jogador);
                break;
            }
        }
    }    
    (*labirinto)->v = (int**) malloc(num_linhas*sizeof(int*));
    for(i = 0; i < num_linhas; i++){
        (*labirinto)->v[i] = (int*) malloc(num_colunas*sizeof(int));
        for(j = 0; j < num_colunas; j++){
            if((*labirinto)->m[i][j] == VERDE_JOGADOR)
                (*labirinto)->v[i][j] = VISITADO;
            else
                (*labirinto)->v[i][j] = NAO_VISITADO;
        }
    }
    if(MODOANALISE){
        (*labirinto)->nivel_recursividade = 0;
        (*labirinto)->max_nivel_recursividade = 0;
        (*labirinto)->num_recursoes = -1;
    }
}

void imprimirLabirinto(Labirinto *labirinto){    
    printf("\n**Impressao do Labirinto**\n");
    printf("Numero de linhas: %d\n", labirinto->num_linhas);
    printf("Numero de Colunas: %d\n", labirinto->num_colunas);    
    imprimirMatrizConfiguracaoLabirinto(labirinto);
    imprimirMatrizPosicoesVisitadasLabirinto(labirinto);
    imprimirEstudante(labirinto->estudante);
}

void imprimirMatrizConfiguracaoLabirinto(Labirinto *labirinto){
    int i, j;
    printf("\nConfiguracao do labirinto:\n");
    for(i = 0; i < labirinto->num_linhas; i++){
        for(j = 0; j < labirinto->num_colunas; j++){
            printf("%d ", labirinto->m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatrizPosicoesVisitadasLabirinto(Labirinto *labirinto){
    int i, j;
    printf("\nMatriz de posicoes visitadas:\n");
    for(i = 0; i < labirinto->num_linhas; i++){
        for(j = 0; j < labirinto->num_colunas; j++){
            printf("%d ", labirinto->v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int validarMovimentacaoParedePorta(Labirinto *labirinto, int prox_linha, int prox_coluna){    
    if(labirinto->v[prox_linha][prox_coluna] == VISITADO)
        return MOVIMENTO_PROIBIDO;
    if(labirinto->m[prox_linha][prox_coluna] == AZUL_PAREDE) 
        return MOVIMENTO_PROIBIDO;    
    if(labirinto->m[prox_linha][prox_coluna] == VERMELHO_PORTA){
        if(labirinto->estudante->qtd_chaves_restantes == 0)
            return MOVIMENTO_PROIBIDO;
        labirinto->estudante->qtd_chaves_restantes--;        
    }            
    labirinto->estudante->linha = prox_linha;
    labirinto->estudante->coluna = prox_coluna;
    return MOVIMENTO_REALIZADO;
}

int moverParaCima(Labirinto *labirinto){
    int prox_linha = labirinto->estudante->linha - 1;
    int prox_coluna = labirinto->estudante->coluna;
    if(prox_linha < 0) return MOVIMENTO_PROIBIDO;
    return validarMovimentacaoParedePorta(labirinto, prox_linha, prox_coluna);
}

int moverParaBaixo(Labirinto *labirinto){
    int prox_linha = labirinto->estudante->linha + 1;
    int prox_coluna = labirinto->estudante->coluna;
    if(prox_linha == labirinto->num_linhas) 
        return MOVIMENTO_PROIBIDO;
    return validarMovimentacaoParedePorta(labirinto, prox_linha, prox_coluna);
}

int moverParaDireita(Labirinto *labirinto){
    int prox_linha = labirinto->estudante->linha;
    int prox_coluna = labirinto->estudante->coluna + 1;
    if(prox_coluna == labirinto->num_colunas) 
        return MOVIMENTO_PROIBIDO;
    return validarMovimentacaoParedePorta(labirinto, prox_linha, prox_coluna);
}

int moverParaEsquerda(Labirinto *labirinto){
    int prox_linha = labirinto->estudante->linha;
    int prox_coluna = labirinto->estudante->coluna - 1;
    if(prox_coluna < 0) 
        return MOVIMENTO_PROIBIDO;
    return validarMovimentacaoParedePorta(labirinto, prox_linha, prox_coluna);
}

void desfazerMovimento(Labirinto *labirinto, int linha_anterior, int coluna_anterior){
    int linha = labirinto->estudante->linha;
    int coluna = labirinto->estudante->coluna;
    if(labirinto->m[linha][coluna] == VERMELHO_PORTA)
        labirinto->estudante->qtd_chaves_restantes++;
    labirinto->estudante->linha = linha_anterior;
    labirinto->estudante->coluna = coluna_anterior;
    adicionarPosicaoListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido, linha_anterior, coluna_anterior);
}

int movimenta_estudante(Labirinto *labirinto){
    int r, linha, coluna;
    linha = labirinto->estudante->linha;
    coluna = labirinto->estudante->coluna;
    labirinto->v[linha][coluna] = VISITADO;
    if(MODOANALISE){
        labirinto->num_recursoes++;        
        if(labirinto->max_nivel_recursividade < labirinto->nivel_recursividade){
            labirinto->max_nivel_recursividade = labirinto->nivel_recursividade;        
        }        
    }
    if(verificarPosicaoEstudante(labirinto->estudante) == CHEGOU_AO_OBJETIVO){
        return CHEGOU_AO_OBJETIVO;
    }        
    if(moverParaCima(labirinto) == MOVIMENTO_REALIZADO){
        adicionarPosicaoListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido, linha-1, coluna);
        if(MODOANALISE) labirinto->nivel_recursividade++;
        r = movimenta_estudante(labirinto);
        if(MODOANALISE) labirinto->nivel_recursividade--;
        if(r == CHEGOU_AO_OBJETIVO){
            return CHEGOU_AO_OBJETIVO;        
        } // else NAO_CHEGOU_AO_OBJETIVO
        desfazerMovimento(labirinto, linha, coluna); // desfazendo movimento anterior        
    }
    if(moverParaEsquerda(labirinto) == MOVIMENTO_REALIZADO){     
        adicionarPosicaoListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido, linha, coluna-1);
        if(MODOANALISE) labirinto->nivel_recursividade++;
        r = movimenta_estudante(labirinto);
        if(MODOANALISE) labirinto->nivel_recursividade--;
        if(r == CHEGOU_AO_OBJETIVO){
            return CHEGOU_AO_OBJETIVO;        
        }
        desfazerMovimento(labirinto, linha, coluna);
    }    
    if(moverParaDireita(labirinto) == MOVIMENTO_REALIZADO){
        adicionarPosicaoListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido, linha, coluna+1);
        if(MODOANALISE) labirinto->nivel_recursividade++;
        r = movimenta_estudante(labirinto);
        if(MODOANALISE) labirinto->nivel_recursividade--;
        if(r == CHEGOU_AO_OBJETIVO){
            return CHEGOU_AO_OBJETIVO;        
        }
        desfazerMovimento(labirinto, linha, coluna);
    }
    if(moverParaBaixo(labirinto) == MOVIMENTO_REALIZADO){
        adicionarPosicaoListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido, linha+1, coluna);
        if(MODOANALISE) labirinto->nivel_recursividade++;
        r = movimenta_estudante(labirinto);
        if(MODOANALISE) labirinto->nivel_recursividade--;
        if(r == CHEGOU_AO_OBJETIVO){     
            return CHEGOU_AO_OBJETIVO;        
        }
        desfazerMovimento(labirinto, linha, coluna);
    }
    return NAO_CHEGOU_AO_OBJETIVO;
}

void freeLabirinto(Labirinto **labirinto){
    int i, j, *r, **r4;
    Labirinto *r2 = *labirinto;
    Estudante *r3 = r2->estudante;
    freeListaCaminhoPercorrido(&(r3->listaCaminhoPercorrido));
    free(r3);
    for(i = 0; i < r2->num_linhas; i++){        
        r = r2->m[i];
        free(r);
        r = r2->v[i];
        free(r);        
    }
    r4 = r2->m;
    free(r4);
    r4 = r2->v;
    free(r4);
    free(r2);
}
