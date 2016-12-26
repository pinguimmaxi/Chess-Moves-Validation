#ifndef _SHOWBOARD_H
#define _SHOWBOARD_H

#ifndef _INC_WINDOWS
#include<windows.h>
#endif /*_INC_WINDOWS*/

#define std_con_out GetStdHandle(STD_OUTPUT_HANDLE)

int textcolor();/*returns current text color*/
int backcolor();/*returns current background color*/

void setcolor(int textcolor,int backcolor);
void showBoard(PIECE pieces[32]);

#endif
