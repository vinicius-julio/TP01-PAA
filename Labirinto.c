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
        (*labirinto)->nivel_recursividade = -1;
        (*labirinto)->max_nivel_recursividade = 0;
        (*labirinto)->num_recursoes = -1;
    }
}

void imprimirLabirinto(Labirinto *labirinto){    
    printf("\n**Impressao do Labirinto**\n");
    printf("Numero de linhas: %d\n", labirinto->num_linhas);
    printf("Numero de Colunas: %d\n", labirinto->num_colunas);    
    imprimirMatrizConfiguracaoLabirinto(labirinto);
    //imprimirMatrizPosicoesVisitadasLabirinto(labirinto);
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

int resolverLabirinto(Labirinto *labirinto){
    if(movimenta_estudante(labirinto, labirinto->estudante->linha-1, labirinto->estudante->coluna) == CHEGOU_AO_OBJETIVO) // para cima
        return CHEGOU_AO_OBJETIVO;
    if(movimenta_estudante(labirinto, labirinto->estudante->linha, labirinto->estudante->coluna-1) == CHEGOU_AO_OBJETIVO) // para esquerda
        return CHEGOU_AO_OBJETIVO;
    if(movimenta_estudante(labirinto, labirinto->estudante->linha, labirinto->estudante->coluna+1) == CHEGOU_AO_OBJETIVO) // para direita
        return CHEGOU_AO_OBJETIVO;
    if(movimenta_estudante(labirinto, labirinto->estudante->linha+1, labirinto->estudante->coluna) == CHEGOU_AO_OBJETIVO) // para baixo
        return CHEGOU_AO_OBJETIVO;
    return NAO_CHEGOU_AO_OBJETIVO;
}

int movimenta_estudante(Labirinto *labirinto, int linha, int coluna){
    if(MODOANALISE){
        labirinto->num_recursoes++;      
        labirinto->nivel_recursividade++;
        if(labirinto->max_nivel_recursividade < labirinto->nivel_recursividade){
            labirinto->max_nivel_recursividade = labirinto->nivel_recursividade;        
        }        
    }
    if(linha == 0 
            && (labirinto->m[linha][coluna] == BRANCO_VAZIO ||
                (labirinto->m[linha][coluna] == VERMELHO_PORTA 
                && labirinto->estudante->qtd_chaves_restantes > 0))){
        labirinto->v[linha][coluna] = VISITADO;
        adicionarPosicaoListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido, linha, coluna);
        return CHEGOU_AO_OBJETIVO;
    }
    
    if(linha >= 0 && linha < labirinto->num_linhas 
            && coluna >= 0 && coluna < labirinto->num_colunas
            && (labirinto->m[linha][coluna] == BRANCO_VAZIO ||
                    (labirinto->m[linha][coluna] == VERMELHO_PORTA 
                    && labirinto->estudante->qtd_chaves_restantes > 0))                
        ){
        
        adicionarPosicaoListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido, linha, coluna);
        
        if(labirinto->v[linha][coluna] == VISITADO){
            return NAO_CHEGOU_AO_OBJETIVO;
        }
        
        labirinto->v[linha][coluna] = VISITADO;
        
        if(labirinto->m[linha][coluna] == VERMELHO_PORTA)
            labirinto->estudante->qtd_chaves_restantes--;
                
        if(movimenta_estudante(labirinto, linha-1, coluna) == CHEGOU_AO_OBJETIVO) // para cima
            return CHEGOU_AO_OBJETIVO;        
        
        if(movimenta_estudante(labirinto, linha, coluna-1) == CHEGOU_AO_OBJETIVO) // para esquerda
            return CHEGOU_AO_OBJETIVO;
        
        if(movimenta_estudante(labirinto, linha, coluna+1) == CHEGOU_AO_OBJETIVO) // para direita
            return CHEGOU_AO_OBJETIVO;
        
        if(movimenta_estudante(labirinto, linha+1, coluna) == CHEGOU_AO_OBJETIVO) // para baixo
            return CHEGOU_AO_OBJETIVO;
        
        labirinto->v[linha][coluna] = NAO_VISITADO;
        if(labirinto->m[linha][coluna] == VERMELHO_PORTA)
            labirinto->estudante->qtd_chaves_restantes++;
        if(MODOANALISE) 
            labirinto->nivel_recursividade--;
        adicionarPosicaoListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido, linha, coluna);
        return NAO_CHEGOU_AO_OBJETIVO;
    }
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
