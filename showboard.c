#include <stdio.h>
#include "xadrez_def.h"
#include "showboard.h"


int textcolorprotect=1;
/*doesn't let textcolor be the same as backgroung color if true*/

enum concol
{
	black=0,
	dark_blue=1,
	dark_green=2,
	dark_aqua,dark_cyan=3,
	dark_red=4,
	dark_purple=5,dark_pink=5,dark_magenta=5,
	dark_yellow=6,
	dark_white=7,
	gray=8,
	blue=9,
	green=10,
	aqua=11,cyan=11,
	red=12,
	purple=13,pink=13,magenta=13,
	yellow=14,
	white=15
};

int textcolor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(std_con_out,&csbi);
	int a=csbi.wAttributes;
	return a%16;
}

int backcolor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(std_con_out,&csbi);
	int a=csbi.wAttributes;
	return (a/16)%16;
}


void setcolor(int textcol,int backcol)
{
	if(textcolorprotect)
	{if((textcol%16)==(backcol%16))textcol++;}
	textcol%=16;backcol%=16;
	unsigned short wAttributes= ((unsigned)backcol<<4)|(unsigned)textcol;
	SetConsoleTextAttribute(std_con_out, wAttributes);
}


void showBoard(PIECE pieces[32]){
	char piece;
	int i, j;
	int board[MAXLINES][MAXCOL] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, -1,
	    16, 0, 0, 0, 0, 0, 0, 0, 0, 16,
	    15, 0, 0, 0, 0, 0, 0, 0, 0, 15,
	    14, 0, 0, 0, 0, 0, 0, 0, 0, 14,
	    13, 0, 0, 0, 0, 0, 0, 0, 0, 13,
	    12, 0, 0, 0, 0, 0, 0, 0, 0, 12,
	    11, 0, 0, 0, 0, 0, 0, 0, 0, 11,
	    10, 0, 0, 0, 0, 0, 0, 0, 0, 10,
	    9, 0, 0, 0, 0, 0, 0, 0, 0, 9,
	    -1, 1, 2, 3, 4, 5, 6, 7, 8, -1
	};
	int pieceIndex =  0;
	int pieceSquare[2];
	for (pieceIndex = 0; pieceIndex < 32; pieceIndex++){
		if(pieces[pieceIndex].state==1){
			pieceSquare[0] = pieces[pieceIndex].square.file - 'a' + 1;
			pieceSquare[1] = '8' - pieces[pieceIndex].square.rank  + 1;
			board[ pieceSquare[1] ][ pieceSquare[0] ] = ( pieces[pieceIndex].color == 'w' ? pieces[pieceIndex].type : -pieces[pieceIndex].type) ;
		}
	}
	    for (i = 0; i < MAXLINES; i++) {
	        printf("\n");
	        for (j = 0; j < MAXCOL; j++) {
	            switch (board[i][j]) {
	                case -1:
	                    piece = ' ';
	                    break;
	                case 0:
	                    piece = ' ';
	                    break;
	                case 1:
	                    piece = 'a';
	                    break;
	                case 2:
	                    piece = 'b';
	                    break;
	                case 3:
	                    piece = 'c';
	                    break;
	                case 4:
	                    piece = 'd';
	                    break;
	                case 5:
	                    piece = 'e';
	                    break;
	                case 6:
	                    piece = 'f';
	                    break;
	                case 7:
	                    piece = 'g';
	                    break;
	                case 8:
	                    piece = 'h';
	                    break;
	                case 9:
	                    piece = '1';
	                    break;
	                case 10:
	                    piece = '2';
	                    break;
	                case 11:
	                    piece = '3';
	                    break;
	                case 12:
	                    piece = '4';
	                    break;
	                case 13:
	                    piece = '5';
	                    break;
	                case 14:
	                    piece = '6';
	                    break;
	                case 15:
	                    piece = '7';
	                    break;
	                case 16:
	                    piece = '8';
	                    break;
	                case 100:
	                    piece = 'P';
	                    break;
	                case 300:
	                    piece = 'N';
	                    break;
	                case 305:
	                    piece = 'B';
	                    break;
	                case 500:
	                    piece = 'R';
	                    break;
	                case 900:
	                    piece = 'Q';
	                    break;
	                case 2000:
	                    piece = 'K';
	                    break;
	                case -100:
	                    piece = 'p';
	                    break;
	                case -300:
	                    piece = 'n';
	                    break;
	                case -305:
	                    piece = 'b';
	                    break;
	                case -500:
	                    piece = 'r';
	                    break;
	                case -900:
	                    piece = 'q';
	                    break;
	                case -2000:
	                    piece = 'k';
	                    break;
	            }
	            if ((i != 0 && j != 0) && (i != MAXLINES - 1 && j != MAXCOL - 1)) {
	                if (((j % 2 != 0 && i % 2 != 0) || (i % 2 == 0 && j % 2 == 0))){
						(piece<'a') ? setcolor(cyan, white) : setcolor(magenta, white);
						printf(" %c ", piece);
						setcolor(white, black);
	                    }
						//printf("%c[%d;%dm %c %c[%dm", 27, (piece<'a')?36:35, 47, piece, 27, 0); //branco
	                else{
						(piece<'a') ? setcolor(cyan, black) : setcolor(magenta, black);
						printf(" %c ", piece);
						setcolor(white, black);
						}
	                    //printf("%c[%d;%dm %c %c[%dm", 27, (piece<'a')?36:35, 40, piece, 27, 0); //preto
	            } else {
						setcolor(white, blue);
						printf(" %c ", piece);
						setcolor(white, black);
						}
	                    
				//printf("%c[%d;%dm %c %c[%dm", 27, 37, 44, piece, 27, 0); // branco

	        }
	    }
	    printf("\n\n");
}

