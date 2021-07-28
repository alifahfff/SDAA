#include<stdio.h>
#include<conio.h>
#include<windows.h>

#include "evaluasi.h"
#include "stack.h"
#include "tree.h"


void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int choisireTypeEvaluation()
{
	int chois;
	do
	{
		puts("Pilih perhitungan:");
		puts("1: Perhitungan menggunakan stack.");
		puts("2: Perhitungan menggunakan tree.");
		printf("> ");
		scanf("%d", &chois);
	}while((chois != 1)&&(chois != 2));
	return chois;
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
	scanf("%d",&pilihan);
	switch(pilihan){
		case 1:
				char Exp[L_MAX];
                int syn, lex;
                int ChoisTypeEvaluation;
                Infotype t[L_MAX];
                int n;
                Stack* p;
                float resultat;
                Tree* a;
                char repeat;
				do
				{
					/* input nilai untuk evaluasi*/
					printf("MASUKIN ANGKA!:\n>");
					scanf("%s", Exp);
					/* verifikasi ekpresi leksikal dan syntax */

					syn = lex = 0;
					lex = verify(Exp);
					syn = lex? parenthesis(Exp) : 0;
					if(!lex)
						printf("Ekpresi leksikal tidak benar!.\n");
					else if(!syn)
						printf( "Syntax tidak benar! .\n");
					else
					{
						/* Memilih evaluasi menggunakan tree atau stack */
						ChoisTypeEvaluation = choisireTypeEvaluation();

						/* Mengubah ekpresi menjadi array */
						StringtoFloat(Exp, t, &n);

						switch (ChoisTypeEvaluation)
						{
							case 1:
								initStack(&p);
								/* create stack */
								p = infixtoPostfix(t, n);
								resultat = Evaluate(&p);
								printf("\n Hasilnya adalah ini : %.3f\n", resultat);
								break;
							case 2:
							a = constTree(t, n);
							//creater Tree
							PrintTree(a);
							resultat = EvaluateTree(a);
							printf("\n Hasilnya adalah ini : %.3f\n", resultat);
						}
					}
						puts("Mau ngitung lagi ga?(y/g)");
			            printf("> ");

			            while ((repeat = getchar()) != '\n' && repeat != EOF);
			            scanf( "%c", &repeat);
			    }while((repeat == 'y')||(repeat == 'Y'));
			    return 0;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			exit(0);
			break;
			}
}

