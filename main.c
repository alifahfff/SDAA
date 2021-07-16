#include<stdio.h>
#include <conio.h>
#include <windows.h>

#include "stack.h"
#include "binarytree.h"


void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main(){
	int pilihan;
	printf("\t\t\t        \xb3          ====== Menu Kalkulator ======            \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xb3             1. Masukan Perhitungan                \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xb3             2. Tampilkan Tree                     \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xb3             3. Exit                               \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");	
	printf("\t\t\t        Masukan pilihan : ");
	scanf("&d",pilihan);
	switch(pilihan){
		case 1:		
			break;
		case 2: //evaluatePostfix();
			break;
		case 3:
			break;
	}
}
