/* 
 * File:   main.c
 * Authors: Matheus Freitas Martins (3031) / Vinicius Haner / Lucas Costa
 *
*/

#include "Labirinto.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int opcaoMenu, valor, i, j, num_movimentos;
    opcaoMenu = 1;    
    char arquivo[25], valorAux;
    strcpy(arquivo, ""); //inicializando arquivo como vazio
    FILE *arq = NULL;
    int nLinhaArq, nColunaArq, nChavesArq;
    Labirinto *labirinto;
    int **matriz_labirinto;

    while(opcaoMenu==1 || opcaoMenu ==2){
        printf("PROGRAMA Labirinto: Opcoes do programa:\n");
        //printf("Opcoes do programa:\n");
        printf("1) Carregar novo arquivo de dados.\n");
        printf("2) Processar e exibir resposta.\n");
        printf("3 ou qualquer outro caracter) Sair do programa.\n");
        printf("Digite um numero: ");
        scanf("%d", &opcaoMenu);

        switch(opcaoMenu) {
            case 1: // abre arquivo
                printf("Por favor digite o nome do arquivo: ");
                scanf("%s", arquivo);
                arq = fopen(arquivo, "r");
                while (!arq){
                    printf("Erro ao ler o arquivo! \n");
                    printf("Por favor digite o nome do arquivo: ");
                    scanf("%s", arquivo);
                    arq = fopen(arquivo, "r");
                }
                fscanf(arq,"%d %d %d\n", &nLinhaArq, &nColunaArq, &nChavesArq);
                matriz_labirinto = (int**) malloc(nLinhaArq*sizeof(int*));
                for(i = 0; i < nLinhaArq; i++){
                    matriz_labirinto[i] = (int*) malloc(nColunaArq*sizeof(int));
                }
                i = 0;
                j = 0;
                while(!feof(arq) && !ferror(arq)){// lê até fim do arquivo ou erro de leitura
                    valorAux = fgetc(arq); //valorAux lê um caracter
                    valor = valorAux-48; //o caracter é convertido para int
                    if(valorAux == EOF){ //se esse valor for o final da leitura, encerramos o while
                        break;
                    }
                    /*quando valorAux for uma quebra de linha, aumenta a linha e zera a coluna*/
                    if(valorAux == '\n'){
                        i++;
                        j = 0;
                        //printf("\n");
                    }else{
                        //insere valor na posicao i j
                        matriz_labirinto[i][j] = valor;
                        //printf("%d", valor);
                        j++;
                    }
                }
                inicializarLabirinto(&labirinto, nLinhaArq, nColunaArq, &matriz_labirinto, nChavesArq);
                fclose(arq);
                printf("Arquivo lido com sucesso!\n");
                imprimirLabirinto(labirinto);
                system("read -p 'Pressione Enter para continuar...' var");                
                break;
            case 2:
                if (strcmp(arquivo,"") == 0){
                    printf("Por favor carregue antes um arquivo de dados!\n");
                    system("read -p 'Pressione Enter para continuar...' var");
                }else {
                    //codigo para movimentar o aluno
                    movimenta_estudante(labirinto);                    
                    imprimirListaCaminhoPercorrido(labirinto->estudante->listaCaminhoPercorrido);
                    num_movimentos = retornarNumeroMovimentos(labirinto->estudante->listaCaminhoPercorrido);
                    if(labirinto->estudante->listaCaminhoPercorrido->ultimo->linha == 0)
                        printf("O estudante se movimentou %d vezes e chegou na coluna %d da primeira linha\n", num_movimentos, labirinto->estudante->listaCaminhoPercorrido->ultimo->coluna);
                    else
                        printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida.\n", num_movimentos);
                    imprimirMatrizPosicoesVisitadasLabirinto(labirinto);
                    if (MODOANALISE) {
                        printf("ANALISE:\n");
                        printf("Total de chamadas recursivas: %d\n", labirinto->num_recursoes);
                        printf("Nivel maximo de recursividade: %d\n", labirinto->max_nivel_recursividade);                        
                    }
                    freeLabirinto(&labirinto);
                    strcpy(arquivo, "");
                }
                break;

        }
    }
    return 0;
}

