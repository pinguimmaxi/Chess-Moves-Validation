#ifndef _XADREZ_FUNC_H
#define _XADREZ_FUNC_H

#include "xadrez_def.h"

char carregar_jogo(char filename[], PIECE pecas[]);
char guardar_jogo(PIECE pecas[], char qj);

void swap( char x1, char y1, char x2, char y2, PIECE pecas[]);

int verifica_xeque(PIECE pecas[]);

int verifica_xeque_mate( PIECE pecas[]);

int verifica_cor(char x, char y, PIECE pecas[]);

int verifica_dentro_tab(char x, char y);

int escolher_peca( char quem_joga, PIECE pecas[]);

int dados_inicias(PIECE pecas[]);

int seleciona_peca(char x1, char y1, char x2, char y2, PIECE pecas[]);
int identifica_peca(char x, char y, PIECE pecas[]);

int verifica_vertical_livre(char x1, char y1, char x2, char y2, PIECE pecas[]);
int verifica_horizontal_livre(char x1, char y1,char x2, char y2, PIECE pecas[]);
int verifica_diagonal_livre(char x1, char y1, char x2, char y2, PIECE pecas[]);

int verifica_mov_peao_branco(char x1, char y1, char x2, char y2, PIECE pecas[]);
int verifica_mov_peao_preto(char x1, char y1, char x2, char y2, PIECE pecas[]);
int verifica_mov_torre(char x1, char y1, char x2, char y2, PIECE pecas[]);
int verifica_mov_cavalo(char x1, char y1, char x2, char y2, PIECE pecas[]);
int verifica_mov_bispo(char x1, char y1, char x2, char y2, PIECE pecas[]);
int verifica_mov_rainha(char x1, char y1, char x2, char y2, PIECE pecas[]);
int verifica_mov_rei(char x1, char y1, char x2, char y2, PIECE pecas[]);

void verifica_roque (PIECE pecas[]);

void movimento(char x1, char y1, char x2, char y2, PIECE pecas[]);

#endif
