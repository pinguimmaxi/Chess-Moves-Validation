/*
 * Xadrez_func.c: este bloco de c�digo contem todas as fun��es
 * que s�o necess�rias � mecanica do jogo
 */
#include <stdio.h>

#include "xadrez_def.h"
#include "xadrez_func.h"
#include "showboard.h" 


/*
 * carregar_jogo(): carrega no array de pe�as, a situa��o actual
 *   				do jogo.
 * IN:
 *		filename: nome do ficheiro a ler
 *		pecas: vector com as pecas do jogo
 * data: Dez2012
 */
char carregar_jogo(char filename[], PIECE pecas[])
{
    FILE *fp;
    char buffer[32];
    int i;
    char coluna;
    char linha;
    int estado;
    int tipo;
    char cor[4];
    char nl;
    
    fp = fopen(filename, "rt");
    if(fp == NULL){
        printf("\n--> O ficheiro [%s] nao existe. <--\n\n", filename);
        fclose(fp);
        return 'e';
    }
    
    for(i = 0; i < 32; i++){
        //fgets(buffer, 32, fp);
        fscanf(fp, "%c;%c;%d;%d;%s%c", &linha, &coluna, &estado, &tipo, cor, &nl);
        pecas[i].state = estado;
        pecas[i].type   = tipo;
        pecas[i].color  = cor[0];
        pecas[i].square.file = linha;
        pecas[i].square.rank = coluna;
        //printf("%2d - %s", i+1, buffer);
    }
    
    fgets(buffer, 32, fp);
    fclose(fp);
    
    // vou chamar a funcao para desenhar o tabuleiro
    //showBoard(pecas);
    
    return buffer[0];
}


char guardar_jogo(PIECE pecas[], char qj){
    
    char guardar[32];
    FILE *fp;
    
    puts("Qual o nome do ficheiro a criar: ");
    scanf(" %s", guardar);
    
    if((fp = fopen(guardar, "wt")) == NULL){
        printf("Nao consegui criar o ficheiro [%s].\n", guardar);
        return qj;
    }
    
    int i;
    for(i = 0; i < 32; i++){
        fprintf(fp, "%c;%c;%d;%d;%c/\n",
                pecas[i].square.file, pecas[i].square.rank,
                pecas[i].state, pecas[i].type, pecas[i].color);
    }
    fprintf(fp, "%c\n", qj);
    
    fclose(fp);
    return qj;
}

