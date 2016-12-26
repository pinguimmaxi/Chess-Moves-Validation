#ifndef _XADREZ_DEF_H
#define _XADREZ_DEF_H

// tipos de estruturas
typedef struct _square{
	char file;
	char rank;
}SQUARE;

typedef struct _peca{
	int state;
	int type;
	char color;
	SQUARE square;
}PIECE;


// macros do programa
#define MAXLINES 10
#define MAXCOL   10
	
#endif
