/*
 * Xadrez_func.c: este bloco de cï¿½digo contem todas as funï¿½ï¿½es
 * que sï¿½o necessï¿½rias ï¿½ mecanica do jogo
 */
#include <stdio.h>

#include "xadrez_def.h"
#include "xadrez_func.h"
#include "showboard.h" 

char coord_ini[5] = { 0,0,0,0,0 };

char coord_fin[5] = { 0,0,0,0,0 };

int quem_jogou[2] = { 0,0 };

/*
 * carregar_jogo(): carrega no array de peças, a situaçao actual
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
        fscanf(fp, "%c;%c;%d;%d;%s%c", &coluna, &linha, &estado, &tipo, cor, &nl);
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

int verifica_xeque(PIECE pecas[])
{
	int a=0,b=0;

	for(a=0; a<32; a++)
	{
		if( pecas[a].type == 2000 )
		{
			for(b=0; b<32; b++)
			{

			if( verifica_vertical_livre(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas)==1
			 && verifica_horizontal_livre(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas)==1
			 && verifica_diagonal_livre(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas)==1 )
			{
			switch (pecas[b].type )
			{

			case -100: //peao preto
				if( verifica_mov_peao_preto(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return 1;
				break;
				}

				break;
			case -300:
				if( verifica_mov_cavalo(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return 1;
				break;
				}

				break;
			case -305:
				if( verifica_mov_bispo(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return 1;
				break;
				}

				break;
			case -500:
				if( verifica_mov_torre(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return 1;
				break;
				}

				break;
			case -900:
				if( verifica_mov_rainha(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return 1;
				break;
				}

				break;
			case -2000: //rei preto
				if( verifica_mov_rei(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return 1;
				break;
				}

				break;
			}
			}
			}
		}
		else if ( pecas[a].type == -2000)
		{
			for(b=0; b<32; b++)
			{

			if( verifica_vertical_livre(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas)==1
			&& verifica_horizontal_livre(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas)==1
			&& verifica_diagonal_livre(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas)==1 )
			{

			switch (pecas[b].type )
			{

			case 100: //peao branco
				if( verifica_mov_peao_branco(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return -1;
				break;
				}

				break;
			case 300: //cavalo branco
				if( verifica_mov_cavalo(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return -1;
				break;
				}

				break;
			case 305: //bispo branco
				if( verifica_mov_bispo(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return -1;
				break;
				}

				break;
			case 500: //torre branca
				if( verifica_mov_torre(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return -1;
				break;
				}

				break;
			case 900: //rainha branca
				if( verifica_mov_rainha(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return -1;
				break;
				}

				break;
			case 2000: //rei branco
				if( verifica_mov_rei(pecas[b].square.rank, pecas[b].square.file, pecas[a].square.rank, pecas[a].square.file, pecas) )
				{
				return -1;
				break;
				}

				break;
			}
			}
			}
		}

	}
return 0;
}

int verifica_xeque_mate( PIECE pecas[])
{
	int a=0,b=0,c=0,d=0;

	for(a=0; a<32; a++)
	{
		if( pecas[a].type == 2000 )
		{
			for(b=0; b<32; b++)
			{
				for(c='a'; c<='h'; c++) // for para colunas
				{
					for(d='1'; d<='8'; d++) // for para linhas
					{
						int tmp1 = pecas[b].square.rank; // coluna ou x
						int tmp2 = pecas[b].square.file; // linha ou y

						pecas[b].square.rank = c;
						pecas[b].square.file = d;

						int fx2 = verifica_xeque(pecas);

						pecas[b].square.rank = tmp1;
						pecas[b].square.file = tmp2;

						if( verifica_vertical_livre(tmp1, tmp2, c, d, pecas)==1
		   				 && verifica_horizontal_livre(tmp1, tmp2, c, d, pecas)==1
					     && verifica_diagonal_livre(tmp1, tmp2, c, d, pecas)==1 )
						{

						switch ( pecas[b].type )
						{

						case 100: //peao branco
						if( verifica_mov_peao_branco( tmp1, tmp2, c, d, pecas ) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}

						break;

						case 300:
						if( verifica_mov_cavalo(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}

						break;

						case 305:
						if( verifica_mov_bispo(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}

						break;

						case 500:
						if( verifica_mov_torre(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}

						break;

						case 900:
						if( verifica_mov_rainha(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}

						break;

						case 2000: //rei branco
						if( verifica_mov_rei(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}

						break;
						}
						}
					}
				}
			}
		return 1; // o rei branco esta em xeque mate
		}


		else if ( pecas[a].type == -2000)
		{
			for(b=0; b<32; b++)
			{
				for(c='a'; c<='h'; c++) // for para colunas
				{
					for(d='1'; d<='8'; d++) // for para linhas
					{
						int tmp1 = pecas[b].square.rank; // coluna ou x
						int tmp2 = pecas[b].square.file; // linha ou y

						pecas[b].square.rank = c;
						pecas[b].square.file = d;

						int fx2 = verifica_xeque(pecas);

						pecas[b].square.rank = tmp1;
						pecas[b].square.file = tmp2;

						if( verifica_vertical_livre(tmp1, tmp2, c, d, pecas)==1
						&& verifica_horizontal_livre(tmp1, tmp2, c, d, pecas)==1
						&& verifica_diagonal_livre(tmp1, tmp2, c, d, pecas)==1 )
						{

						switch( pecas[b].type )
						{
						case -100: //peao branco
						if( verifica_mov_peao_branco( tmp1, tmp2, c, d, pecas ) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}
						break;

						case -300:
						if( verifica_mov_cavalo(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}
						break;

						case -305:
						if( verifica_mov_bispo(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}
						break;

						case -500:
						if( verifica_mov_torre(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}
						break;

						case -900:
						if( verifica_mov_rainha(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}
						break;

						case -2000: //rei preto
						if( verifica_mov_rei(tmp1, tmp2, c, d, pecas) )
						{
							if( fx2 == 0)
							{
							return 0; // o rei deixou de estar em xeque com esta jogada. Nao ha xeque mate
							}
						}
						break;
						}
						}
					}
				}
			}
		return -1; // o rei preto esta em xeque mate
		}
	}
return 0;
}

int verifica_cor(char x, char y, PIECE pecas[])
{
		if( pecas[identifica_peca(x, y, pecas)].color == 'w' && pecas[identifica_peca(x, y, pecas)].state == 1 )
			return 'w';

		else if( pecas[identifica_peca(x, y, pecas)].color == 'b' && pecas[identifica_peca(x, y, pecas)].state == 1 )
			return 'b';

	return 0;
}

int verifica_vertical_livre(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	int i,j;
	if (x1==x2) //na mesma coluna
	{
		if(y1<y2) //de baixo para cima
		{
			for (i=(y1 + 1); i<y2; i++)
			{
				for(j=0; j<32; j++)
					{
						if(pecas[j].square.rank == x1 && pecas[j].square.file == i)
						{
						return 0;
						}
					}
			}
		}
		else if (y1>y2)//de cima para baixo
		{
			for (i= (y1 - 1); i>y2; i--)
			{
				for(j=0; j<32; j++)
					{
						if(pecas[j].square.rank == x1 && pecas[j].square.file == i)
						{
						return 0;
						}
					}
			}
		}
	}
	return 1;
}

int verifica_horizontal_livre (char x1, char y1, char x2, char y2, PIECE pecas[])
{
	int i,j;
		if (y1==y2) //na mesma linha
		{
			if(x1<x2) //de esq para dir
			{
				for (i=(x1 + 1); i<x2; i++)
				{
					for(j=0; j<32; j++)
					{
						if(pecas[j].square.rank == i && pecas[j].square.file == y1)
						{
						return 0;
						}
					}
				}
			}
			else if (x1>x2)//de dir para esq
			{
				for (i= (x1 - 1); i>x2; i--)
				{
					for(j=0; j<32; j++)
					{
						if(pecas[j].square.rank == i && pecas[j].square.file == y1)
						{
						return 0;
						}
					}
				}
			}
		}
		return 1;
}

int verifica_diagonal_livre(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	int i, j, k;
	if (x1>x2 && y1>y2)
	{
		for(i=(x1-1), k=(y1-1); i>x2 && k>y2; i--,k--)
		{
			for(j=0; j<32; j++)
			{
				if(pecas[j].square.rank == i && pecas[j].square.file == k)
				{
				return 0;
				}
			}
		}
	}
	else if (x1>x2 && y1<y2)
	{
		for(i=(x1-1), k=(y1+1); i>x2 && k<y2; i--,k++)
		{
			for(j=0; j<32; j++)
			{
				if(pecas[j].square.rank == i && pecas[j].square.file == k)
				{
				return 0;
				}
			}
		}
	}
	else if (x1<x2 && y1>y2)
	{
		for(i=(x1+1), k=(y1-1); i<x2 && k>y2; i++,k--)
		{
			for(j=0; j<32; j++)
			{
				if(pecas[j].square.rank == i && pecas[j].square.file == k)
				{
				return 0;
				}
			}
		}
	}
	else if (x1<x2 && y1<y2)
	{
		for(i=(x1+1), k=(y1+1); i<x2 && k<y2; i++,k++)
		{
			for(j=0; j<32; j++)
			{
				if(pecas[j].square.rank == i && pecas[j].square.file == k)
				{
				return 0;
				}
			}
		}
	}
	return 1;
}

int verifica_dentro_tab(char x, char y)
{
	if( 'a' <= x && x <= 'h' )
	{
		if( '1' <= y && y <= '8' )
		{
		return 1;
		}

		else
		{
		return 0;
		}
	}
	else
	{
	return 0;
	}
}

int identifica_peca(char x, char y, PIECE pecas[]) //Função que mete coloca em "*n_peca" o numero que corresponde ao tipo da peça que esta nas coordenadas quaisquer x,y
{
	int ps;

	for(ps=0; ps<32; ps++)
	{
		if(pecas[ps].square.rank == x && pecas[ps].square.file == y && pecas[ps].state == 1)
			{
			return ps;
			}
	}
	return -1;
}

void movimento(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	int i = identifica_peca(x1, y1, pecas);
	int f = identifica_peca(x2, y2, pecas);

	if( f == -1 && pecas[i].state == 1)//Não há nenhuma peça nas coordenadas destino
	{
		printf("Nao ha peça no destino \n");
		pecas[i].square.rank = x2;
		pecas[i].square.file = y2;
		pecas[f].square.rank = x1;
		pecas[f].square.file = y1;
		return;
	}

	if(pecas[f].color == pecas[i].color && pecas[i].state == 1)
	{
		printf("Não pode comer uma peça da mesma cor! \n");
		return;
	}

	else if(pecas[f].color != pecas[i].color && pecas[i].state == 1 && pecas[f].state == 1)
	{
		printf("Uma peça adversária foi comida! \n");
		pecas[f].state = 0;
		pecas[f].square.rank = x1;
		pecas[f].square.file = y1;
		pecas[i].square.rank = x2;
		pecas[i].square.file = y2;
		return;
	}

	else
	{
		printf("Não Fez Movimento! \n");
		return;
	}
}

int verifica_mov_peao_branco(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	if( ( x1==x2        && y1=='2'  && y2-y1==2 && pecas[ identifica_peca(x2, y2, pecas) ].state==0 ) ||
		( x1==x2        && y1>='2'  && y2==y1+1 && pecas[ identifica_peca(x2, y2, pecas) ].state==0 ) ||
		( abs(x1-x2)==1 && y1>='2'  && y2==y1+1 && pecas[ identifica_peca(x2, y2, pecas) ].state==1 ) )
		return 1;
	else
		return 0;
}

int verifica_mov_peao_preto(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	if( ( x1==x2        && y1=='7'  && y2==y1-2 && pecas[ identifica_peca(x2, y2, pecas) ].state==0) ||
		( x1==x2        && y1<='7'  && y2==y1-1 && pecas[ identifica_peca(x2, y2, pecas) ].state==0) ||
		( abs(x1-x2)==1 && y1<='7'  && y2==y1-1 && pecas[ identifica_peca(x2, y2, pecas) ].state==1 ) )
		return 1;
	else
		return 0;
}

int verifica_mov_torre(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	if ((x1==x2 && y1!=y2)
			|| (y1==y2 && x1!=x2))
	{
		return 1;
	}
	else
		return 0;
}

int verifica_mov_cavalo(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	if( abs(x1-x2) == 2 )
	{
		if( abs(y1-y2) == 1)
		{
			return 1;
		}
		else
			return 0;
	}
	else if( abs(x1-x2) == 1)
	{
		if( abs(y1-y2) == 2)
		{
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

int verifica_mov_bispo(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	if ( (abs(x1-x2)==abs(y1-y2))  && (x1!=x2))
	{
		return 1;
	}
	else
		return 0;
}

int verifica_mov_rainha(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	if (((abs(x1-x2)==abs(y1-y2)) && (x1!=x2))
			||((x1==x2 && y1!=y2)
			|| (y1==y2 && x1!=x2)))
	{
		return 1;
	}
	else
		return 0;
}

int verifica_mov_rei(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	if (( (abs(x1-x2)==1) && (abs(y1-y2)) == 1) ||
			((x1==x2 && (abs(y1-y2)==1))
						|| (y1==y2 && (abs(x1-x2)==1))))
	{
		return 1;
	}
	else
		return 0;
}

void verifica_roque (PIECE pecas[])
{
	if (pecas[identifica_peca('e', '1', pecas)].type == 2000 &&
	pecas[identifica_peca('h', '1', pecas)].type == 500 &&
	verifica_horizontal_livre ('e', '1', 'h', '1', pecas))
	{
	movimento('e', '1','g','1', pecas);
	movimento('h', '1','f','1', pecas);
	}
	else if (pecas[identifica_peca('e', '1', pecas)].type == 2000 &&
	pecas[identifica_peca('a', '1', pecas)].type == 500 &&
	verifica_horizontal_livre ('e', '1', 'a', '1', pecas))
	{
	movimento('e', '1','c','1', pecas);
	movimento('a', '1','d','1', pecas);
	}
	else if (pecas[identifica_peca('e', '8', pecas)].type == -2000 &&
	pecas[identifica_peca('h', '8', pecas)].type == -500 &&
	verifica_horizontal_livre ('e', '8', 'h', '8', pecas))
	{
	movimento('e', '8','g','8', pecas);
	movimento('h', '8','f','8', pecas);
	}
	else if (pecas[identifica_peca('e', '8', pecas)].type == 2000 &&
	pecas[identifica_peca('a', '8', pecas)].type == 500 &&
	verifica_horizontal_livre ('e', '8', 'a', '8', pecas))
	{
	movimento('e', '8','g','8', pecas);
	movimento('a', '8','d','8', pecas);
	}
}

void seleciona_peca(char x1, char y1, char x2, char y2, PIECE pecas[])
{
	int i=identifica_peca(x1, y1, pecas);

	if( i >= 0 )
		{

			if( verifica_vertical_livre(x1, y1, x2, y2, pecas)==0 )
			printf("Vertical Ocupada \n");

			else if( verifica_horizontal_livre(x1, y1, x2, y2, pecas)==0 )
			printf("Horizontal Ocupada \n");

			else if( verifica_diagonal_livre(x1, y1, x2, y2, pecas)==0 )
			printf("Diagonal Ocupada \n");

			else if(   verifica_vertical_livre(x1, y1, x2, y2, pecas)==1
				&& verifica_horizontal_livre(x1, y1, x2, y2, pecas)==1
			    && verifica_diagonal_livre(x1, y1, x2, y2, pecas)==1 )
			{

			switch (pecas[i].type)
				{
				case 100: //peao branco
					if( verifica_mov_peao_branco(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Peao Branco não são válidas \n");
					break;
				case 300: //cavalo branco
					if( verifica_mov_cavalo(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Cavalo não são válidas \n");
					break;
				case 305: //bispo branco
					if( verifica_mov_bispo(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Bispo não são válidas \n");
					break;
				case 500: //torre branca
					if( verifica_mov_torre(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Torre não são válidas \n");
					break;
				case 900: //rainha branca
					if( verifica_mov_rainha(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Rainha não são válidas \n");
					break;
				case 2000: //rei branco
					verifica_roque(pecas);
					if( verifica_mov_rei(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);

						if( verifica_xeque(pecas) == 1)
							movimento(x2, y2, x1, y1, pecas);
					else
						printf("As Coordenadas Escolhidas para o Rei não são válidas \n");
					break;
				case -100: //peao preto
					if( verifica_mov_peao_preto(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Peao Preto não são válidas \n");
					break;
				case -300:
					if( verifica_mov_cavalo(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Cavalo não são válidas \n");
					break;
				case -305:
					if( verifica_mov_bispo(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Bispo não são válidas \n");
					break;
				case -500:
					if( verifica_mov_torre(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Torre não são válidas \n");
					break;
				case -900:
					if( verifica_mov_rainha(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
					else
						printf("As Coordenadas Escolhidas para o Rainha não são válidas \n");
					break;
				case -2000: //rei preto
					verifica_roque(pecas);
					if( verifica_mov_rei(x1, y1, x2, y2, pecas) )
						movimento(x1, y1, x2, y2, pecas);
							if( verifica_xeque(pecas) == -1 )
								movimento(x2, y2, x1, y1, pecas);
					else
						printf("As Coordenadas Escolhidas para o Rei não são válidas \n");
					break;
				}
			}
		}
		else
			printf("Não encontrou a peca \n");
}

int escolher_peca( char quem_joga, PIECE pecas[])
{
	if( quem_jogou[0] == 0 )
	{
		if( quem_joga == 'w')
			quem_jogou[0] = 'b';
		if( quem_joga == 'b')
			quem_jogou[0] = 'w';
	}

	if( dados_inicias(pecas) == -1 )
		return -1;

return 1;
}

int dados_inicias(PIECE pecas[])
{
	char parar[] = "stop";
	int fx = verifica_xeque(pecas);

	int xm = verifica_xeque_mate(pecas);

	if( xm == 1)
	{
		printf("Xeque Mate ao Rei Branco. \n As pretas ganharam. \n");
		return -1;
	}

	else if( xm == -1)
	{
		printf("Xeque Mate ao Rei Preto. \n As brancas ganharam. \n");
		return -1;
	}

	if( fx == 1)
		printf("O Rei Branco está em Xeque! \n");
	else if( fx == -1)
		printf("O Rei Preto está em Xeque! \n");

	printf("Introduza as coordenadas da peça a jogar: \n");
	scanf( "%s", coord_ini); // Por um motivo que ainda nao percebi o valor coord_ini[0] altera quando se faz o scanf de coord_fin ( Qd a string coord_ini[2] )

	if( strcmp(coord_ini, parar)==0 ) return -1;

	if( quem_jogou[0] == verifica_cor(coord_ini[0], coord_ini[1], pecas) )
	{
	printf("É o adversário a jogar! \n");
	return 1;
	}

	if( verifica_dentro_tab(coord_ini[0], coord_ini[1]) == -1 )
	{
	printf("As Coordenadas Iniciais Escolhidas estão fora do Tabuleiro \n");
	coord_ini[0] = 0, coord_ini[1] = 0;
	return 1;
	}

	printf("Introduza as coordenadas de destino: \n");
	scanf( "%s", coord_fin);

	if( verifica_dentro_tab(coord_fin[0], coord_fin[1]) == -1 )
	{
	printf("As Coordenadas Finais Escolhidas estão fora do Tabuleiro \n");
	coord_fin[0] = 0, coord_fin[1] = 0;
	return 1;
	}

	seleciona_peca(coord_ini[0], coord_ini[1], coord_fin[0], coord_fin[1], pecas);

	if( fx == verifica_xeque(pecas) && fx != 0)
	{

	printf("Jogada Inválida. O rei continua em xeque! \n");
	movimento(coord_fin[0], coord_fin[1], coord_ini[0], coord_ini[1], pecas);

	return 1;
	}

	int var1 = identifica_peca(coord_fin[0], coord_fin[1], pecas);
	int var2 = identifica_peca(coord_ini[0], coord_ini[1], pecas);

	if( var1 == -1 && var2 == -1 )
		return 1;
	else if( var1 >= 0 && var2 == -1)
			quem_jogou[0] = verifica_cor(coord_fin[0], coord_fin[1], pecas);

return 1;
}

