#include "GeraLabirinto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void DificuldadeFacil(){ // Labirintos de tamanho entre 4x4 e 10x10
    srand( (unsigned)time(NULL) );
    int linha = 0, coluna = 0, nChaves = 0, valor = 0, linhaEstudante = 0, colunaEstudante = 0;
    char arquivo[25];
    FILE *arq;
    linha = 4 + rand() % 7;
    linhaEstudante = rand() % linha; // estudante fica em uma posição aleatoria da linha
    coluna = 4 + rand() % 7;
    colunaEstudante = rand() % coluna; // estudante fica em uma posição aleatoria da coluna
    nChaves = rand() % 3; //poucas chaves
    printf("Digite o nome do novo arquivo (arquivo.txt): ");
    scanf("%s", arquivo);
    arq = fopen(arquivo, "w");
    if(arq == NULL){
        printf ("Erro ao criar o arquivo.\n");
    }
    else{
        fprintf(arq, "%d %d %d \n", linha, coluna, nChaves);
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                if( i == linhaEstudante && j == colunaEstudante){ // escreve 0 na posição onde o estudante está.
                    valor = 0;
                }
                else if (i == rand() % linha && j == rand() % coluna){ // pequena chance de ter paredes ou portas
                    valor = 2 + rand() % 2; // soma-se 1 pra nao escolher a posição inicial do estudante
                }
                else{
                    valor = 1;
                }
                fprintf(arq, "%d", valor);
            }
            fputc('\n', arq); //quebra de linha
        }
        fclose(arq);
    }
}
void DificuldadeMedia(){   // Labirintos de tamanho entre 10x10 e 30x30
    srand( (unsigned)time(NULL) );
    int linha = 0, coluna = 0, nChaves = 0, valor = 0, linhaEstudante = 0, colunaEstudante = 0;
    char arquivo[30];
    FILE *arq;
    linha = 10 + rand() % 21;
    linhaEstudante = 10 + rand() % 21; // estudante fica em uma posição aleatoria da linha
    while(linhaEstudante > linha){
        linhaEstudante = 10 + rand() % 21; // estudante fica em uma posição aleatoria da linha
    }
    coluna = 10 + rand() % 21;
    colunaEstudante = rand() % coluna; // estudante fica em uma posição aleatoria da coluna
    nChaves = (rand() % linha + rand() % coluna) * 2;
    printf("Digite o nome do novo arquivo (arquivo.txt): ");
    scanf("%s", arquivo);
    arq = fopen(arquivo, "w");
    if(arq == NULL){
        printf ("Erro ao criar o arquivo.\n");
    }
    else{
        fprintf(arq, "%d %d %d \n", linha, coluna, nChaves);
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                if(i == linhaEstudante && j == colunaEstudante){ // escreve 0 na posição onde o estudante está.
                    valor = 0;
                }
                else{
                    valor = 1 + rand() % 3;
                }
                fprintf(arq, "%d", valor);
            }
            fputc('\n', arq); //quebra de linha
        }
        fclose(arq);
    }
}
void DificuldadeDificil(){   // Labirinto de tamanho entre 30x30 e 50x50
    srand( (unsigned)time(NULL) );
    int linha = 0, coluna = 0, nChaves = 0, valor = 0, linhaEstudante = 0, colunaEstudante = 0;
    char arquivo[30];
    FILE *arq;
    linha = 30 + rand() % 21;
    linhaEstudante = linha-1; // estudante na ultima posicao da linha
    coluna = 30 + rand() % 21;
    colunaEstudante = rand() % coluna-1; // estudante em uma posição aleatoria da coluna
    nChaves = rand() % linha + rand() % coluna;
    printf("Digite o nome do novo arquivo (arquivo.txt): ");
    scanf("%s", arquivo);
    arq = fopen(arquivo, "w");
    if(arq == NULL){
        printf ("Erro ao criar o arquivo.\n");
    }
    else{
        fprintf(arq, "%d %d %d \n", linha, coluna, nChaves);
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                if( i == linhaEstudante && j == colunaEstudante){ // escreve o 0 na posição onde o estudante está.
                    valor = 0;
                }
                else{
                    valor = 1 + rand() % 3;
                }
                fprintf(arq, "%d", valor);
            }
            fputc('\n', arq); //quebra de linha
        }
        fclose(arq);
    }
}
