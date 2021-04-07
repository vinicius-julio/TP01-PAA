#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MODOANALISE 0 //1 para ativado 0 para desativado

int main() {
    int opcaoMenu, valor, i, j, nRecursoes;
    opcaoMenu = 0;
    i = 0;
    j = 0;
    char arquivo[25], valorAux;
    strcpy(arquivo, ""); //inicializando arquivo como vazio
    FILE *arq;
    int nLinhaArq, nColunaArq, nChavesArq;

    while(opcaoMenu!=3){
        printf("PROGRAMA Labirinto:\n");
        printf("Opcoes do programa:\n");
        printf("1) Carregar novo arquivo de dados.\n");
        printf("2) Processar e exibir resposta.\n");
        printf("3) Sair do programa.\n");
        printf("Digite um numero:\n");
        scanf("%d", &opcaoMenu);

        switch(opcaoMenu) {
            case 1: // abre arquivo
                printf("Por favor digite o nome do arquivo:");
                scanf("%s", arquivo);
                arq = fopen(arquivo, "r");
                while (!arq){
                    printf("Erro ao ler o arquivo! \n");
                    printf("Por favor digite o nome do arquivo: ");
                    scanf("%s", arquivo);
                    arq = fopen(arquivo, "r");
                }
                fscanf(arq,"%d %d %d\n", &nLinhaArq, &nColunaArq, &nChavesArq);

                while(!feof(arq) && !ferror(arq)){// lê até fim do arquivo ou erro de leitura
                    valorAux = fgetc(arq); //valorAux lê um caracter
                    valor = valorAux-48; //o caracter é convertido para int
                    if(valor == EOF){ //se esse valor for o final da leitura, encerramos o while
                        break;
                    }
                    /*quando valorAux for uma quebra de linha, aumenta a linha e zera a coluna*/
                    if(valorAux == '\n'){
                        i++;
                        j = 0;
                    }else{
                        //insere valor na posicao i j
                        j++;
                    }
                }
                printf("Arquivo lido com sucesso!\n");
                system("read -p 'Pressione Enter para continuar...' var");
                fclose(arq);
                break;
            case 2:
                if (strcmp(arquivo,"")){
                    printf("Por favor carregue antes um arquivo de dados!\n");
                    system("read -p 'Pressione Enter para continuar...' var");
                }else {
                    if (MODOANALISE) {//conta o numero de recursoes
                        nRecursoes = -1;
                        //codigo pra movimentar o aluno
                    } else {
                        //codigo para movimentar o aluno
                    }
                }
                break;

            case 3:
                break;

        }
    }
    return 0;
}
