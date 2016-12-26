#include <stdio.h>

/*
 * definicoes locais do programa
 */
#include "xadrez_def.h"
#include "xadrez_func.h"
#include "showboard.h"

int main() {
    
    char menu;
    PIECE pecas[32];
    char quem_joga;
    char nome_jogo[256];
    
    
    while(1){
        puts("********** XADREZ AFA **********");
        puts(" 1 - Novo jogo\n 2 - Carregar jogo\n 3 - Guardar jogo\n 4 - Continuar jogo\n s - Sair\n");
        puts("\n\n\n O que pretende fazer?: ");
        scanf(" %c", &menu);
        
		switch(menu){
            case'1':
                quem_joga = carregar_jogo("StartGame", pecas);
                if(quem_joga == 'e'){
                    printf("ATENCAO: o ficheiro de inicio de jogo nao existe.\n\n");
                    return 0;
                }
                showBoard(pecas);
                break;
            case'2':
                puts("Introduza o nome do jogo a carregar:\n");
                scanf(" %s", nome_jogo);
                quem_joga = carregar_jogo(nome_jogo, pecas);
                if(quem_joga == 'e'){
                    printf("ATENCAO: o ficheiro [%s] nao existe.\n\n", nome_jogo);
                    return 0;;
                }
                showBoard(pecas);
                break;
            case'3':
                quem_joga = guardar_jogo(pecas, quem_joga);
                showBoard(pecas);
                break;
            case'4':
                showBoard(pecas);
                break;
            case's':
                printf("adeus\n");
                return 0;
		
            default:
                printf("Opcao invalida\n");
                break;
        }

        if(quem_joga == 'W' || quem_joga == 'B'){
            printf("\n\n****** As %s ganharam ******\n\n",
                   quem_joga == 'W' ? "BRANCAS" : "PRETAS");
            break;
        }
    }
}
