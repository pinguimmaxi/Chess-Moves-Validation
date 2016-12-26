# Chess-Moves-Validation

White pieces are represented by capital letters with cyan colour. Black pieces are represented by non capital letters with pink colour. 
Each player makes a move that must be validated by the program. A player can't make 2 consecutives moves.

There's a menu in the beginning to choose multiple options about a game: New game, Load Game, Save Game, Continue Game, Exit

The game can be saved or loaded from a .txt file

File Structure:
  a;2;1;100;w/

  Each parameter separated by ';'
  First parameter: column letter
  Second: row number
  Third: state ('0' means inactive/eliminated)
  Forth: Piece type
  Fifth: colour ('w' means white)

Description Pieces

  Each pieces has a value accordingly with is importance.

  Pawn   - P - 100
  Night  - N - 300
  Bishop - B - 305
  Roque  - R - 500
  Queen  - Q - 900
  King   - K - 2000
  
  Files Descriptions
  
  xadrez_def.h
  
  Data structures of SQUARE and PIECE
  
  xadrez_func.h and xadrez_func.c
  
  Functions of the program, including READ and SAVE functions for the game file.
  
  showboard.h and showbord.c
  
  Functions to draw in the console the game table
  
  xadrez.c
  
  Main() function to start the program, where the MENU is including.
  
  StartGame
  
  File that contains the inicial display of the pieces in the board to start a new game
