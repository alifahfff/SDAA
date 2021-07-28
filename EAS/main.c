/* PEMBUAT : 
   D31B - JTK 2020
   ALIFAH FISALSABILAWATI 201511035
   FAISHAL MUHAMMAD 	  201511039
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

#include "evaluasi.h"
#include "stack.h"
#include "tree.h"

int pilihperhitungan()
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
	menu:
	int pilihan;
	printf("\t\t\t        \xb3          ====== Menu Kalkulator ======            \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xb3             1. Masukan Perhitungan                \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xb3             2. Tampilkan Tree                     \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xb3             3. Aturan program                     \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xb3             4. Exit                               \xb3\n");
	printf("\t\t\t        \xb3                                                   \xb3\n");
	printf("\t\t\t        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
	printf("\t\t\t        Masukan pilihan : ");
	scanf("%d",&pilihan);
	switch(pilihan){
		case 1:
				char Exp[L_MAX];
                int syn, lex;
                int pil;
                Infotype t[L_MAX];
                int n;
                Stack* p;
                float result;
                Tree* a;
                char repeat;
				do
				{
					system("cls");
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
						pil = pilihperhitungan();

						/* Mengubah ekpresi menjadi array */
						ChartoFloat(Exp, t, &n);

						switch (pil)
						{
							case 1:
								initStack(&p);
								/* Buat stack */
								p = infixtoPostfix(t, n);
								result = Evaluate(&p);
								printf("\n Hasilnya adalah ini : %.3f\n", result);
								break;
							case 2:
							a = constTree(t, n);
							//Buat Tree
							printf("\n\n\t\t\t\t\t\t STRUKTUR TREE \n\n\n");
							PrintTree(a);
							printf("\n\n PostOrder :\t");
							PostOrder(a);
							printf("\n\n PreOrder  :\t");
							PreOrder(a);
							printf("\n\n InOrder   :\t");
							InOrder(a);
							result = EvaluateTree(a);
							printf("\n\n\n\t\t\t Hasilnya adalah ini : %.3f\n\n", result);
						}
					}
						puts("Ulangi Perhitungan?(y/g)");
			            printf("> ");

			            while ((repeat = getchar()) != '\n' && repeat != EOF);
			            scanf( "%c", &repeat);
			            system("cls");
			    }while((repeat == 'y')||(repeat == 'Y'));
				goto menu;
			break;
		case 2:	printf("\n \t\t\t\t\tPASTIKAN SUDAH MELAKUKAN PERHITUNGAN \n\n");
				printf("\n\n\t\t\t\t\t\t STRUKTUR TREE \n\n\n");
				PrintTree(a);
				printf("\n\n PostOrder :\t");
				PostOrder(a);
				printf("\n\n PreOrder  :\t");
				PreOrder(a);
				printf("\n\n InOrder   :\t");
		    	InOrder(a);
		    	getch();
		    	system("cls");
		    	goto menu;
			break;
		case 3:
				aturan();
				getch();
		    	system("cls");
		    	goto menu;
			break;
		case 4:
			exit(0);
			break;
			}
}

