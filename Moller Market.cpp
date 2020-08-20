/*
Professora Ariane Scarelli - FPD
71B - 2017
Projeto: Supermercados Moller
Integrantes:
	Felipe Silva - nº 09
	Giovanna Moeller - nº 11
	Julia Lopreto nª 18
	Maria Eduarda Garcia nº25
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <conio.c>
#include <locale.h>
FILE *fp;
float cont = 0;
struct dados
{
	char cpf[14];
	char nome[30];
	char email[30];
	char telefone[15];
	struct data
	{
		int dia;
		int mes;
		int ano;
	}nasc;
	struct endereco
	{
		char rua[30];
		char bairro[20];
		char num[5];
		char cidade[30];
	}local;
	char excluido;
}usu, usu_aux;
void abrir_arquivo (char *modo)
{
	if((fp = fopen("supermercado.bin",modo)) == NULL)
	{
		gotoxy(18,11);printf("Erro na abertura do arquivo");
		exit(1);
	}
}
void salvar_dados()
{
	textcolor(15);
	char a;
	gotoxy(15,23);printf("Deseja salvar os dados digitados? Digite S/N: ");
	gotoxy(61,23);a = getche();
	while( a != 's' && a != 'S' && a != 'n' && a != 'N' )
	{
		gotoxy(61,23);printf("  ");
		gotoxy(61,23);a = getche();
	}
		if (a == 'S' || a == 's')
		{
			if (fwrite(&usu, sizeof(usu), 1, fp) != 1)
			{
				gotoxy(15,24);printf("Erro na escrita do arquivo");
			}
			else
			{
				fflush(fp);
				gotoxy(25,24);printf("Dados salvos com sucesso!");
				getche();
				return;
			}
		}
		getche();
}
int checagem_chave ()
{
	char aux_cod [14];
	int a;
	int cont;
	do
	{
		rewind(fp);
		a = 0;
		do
		{
			cont=0;
			gotoxy(44,5);gets(aux_cod);
				if (strcmp(aux_cod,"0") == 0)
				{
					break;
				}
			for (int i = 0; i<strlen(aux_cod); i++)
			{
				if (aux_cod[i] == '-')
				{
					cont++;
				}
				if (aux_cod[i] == '.')
				{
					cont++;
				}
				if (aux_cod[i] < '0' || aux_cod[i] > '9' )
				{
					cont++;
				}
			}
			if (strlen(aux_cod) < 11)
			{
				cont++;
			}
			if (strlen(aux_cod) > 11)
			{
				cont++;
			}
			if (cont > 0)
			{
				textcolor(15);
				gotoxy(15,23);printf("CPF inválido. Redigite! Coloque apenas números.");
				gotoxy(28,24);printf("Campo Obrigatório!");
				textcolor(0);
				gotoxy(44,5);clreol();
			}
		}while (cont > 0);
		gotoxy(15,23);clreol();
		gotoxy(28,24);clreol();
		while( ( fread( &usu,sizeof(usu),1,fp) == 1))
		{
			if( strcmp(aux_cod,usu.cpf) == 0 && usu.excluido == 'n')
			{	
			fflush(stdin);
			gotoxy(23,23);printf("** CPF já cadastrado! **");
			getch();
			gotoxy(44,5);clreol();
			a = 1;
			}
		}
	}while(a == 1);
	strcpy(usu.cpf,aux_cod);
}
int caixa ()
{
	setlocale(LC_ALL,"C");
	gotoxy(5,1); printf("             _______________________________________________");
	gotoxy(5,2); printf("            /   _________________________________________   \\ ");
	gotoxy(5,3); printf("            |  |                                         |  |");
	gotoxy(5,4); printf("            |  |                                         |  |");
	gotoxy(5,5); printf("            |  |                                         |  |");
	gotoxy(5,6); printf("            |  |                                         |  |");
	gotoxy(5,7); printf("            |  |                                         |  |");
	gotoxy(5,8); printf("            |  |                                         |  |");
	gotoxy(5,9); printf("            |  |                                         |  |");
	gotoxy(5,10);printf("            |  |                                         |  |");
	gotoxy(5,11);printf("            |  |                                         |  |");
	gotoxy(5,12);printf("            |  |                                         |  |");
	gotoxy(5,13);printf("            |  |                                         |  |");
	gotoxy(5,14);printf("            |  |                                         |  |");
	gotoxy(5,15);printf("            |  |_________________________________________|  |");
	gotoxy(5,16);printf("            \\_______________________________________________/");
	gotoxy(5,17);printf("                   \\___________________________________/ ");
	gotoxy(5,18);printf("               ___________________________________________");
	gotoxy(5,19);printf("            _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_");
	gotoxy(5,20);printf("         _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_");
	gotoxy(5,21);printf("      _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_");
	gotoxy(5,22);printf("     :-------------------------------------------------------------:");
	gotoxy(5,23);printf("     `._.-------------------------------------------------------._.'");
	setlocale(LC_ALL,"Portuguese");
}
int seta2 (int x, int y, int z)
{
	char op;
	int seta = x;
	gotoxy(z,x);printf(">");
	do 
	{
		op=getch();
		switch (op)
		{
			case 119: 
			if (seta<=x)
			{
				gotoxy(z,seta);printf("  ");
				seta = y;
			}
			else 
			{
				gotoxy(z,seta);printf("  ");
				seta-=2;
			}
				gotoxy(z,seta);printf(">");
				break;
			case 115:
			if (seta >= y)
			{
				gotoxy(z,seta);printf("  ");
				seta=x;
			}
			else 
			{
				gotoxy(z,seta);printf("  ");
				seta+=2;
			}
				gotoxy(z,seta);printf(">");
				break;
		}
	}while(op!=13); // 13 é o enter na tabela ASCII
	return seta;
}
int seta (int x, int y, int z)
{
	char op;
	int seta = x;
	gotoxy(z,x);printf(">");
	do 
	{
		op=getch();
		switch (op)
		{
			case 119:
			case 72: 
			if (seta<=x)
			{
				gotoxy(z,seta);printf("  ");
				seta = y;
			}
			else 
			{
				gotoxy(z,seta);printf("  ");
				seta--;
			}
				gotoxy(z,seta);printf(">");
				break;
			case 115:
			case 80:
			if (seta >= y)
			{
				gotoxy(z,seta);printf("  ");
				seta=x;
			}
			else 
			{
				gotoxy(z,seta);printf("  ");
				seta++;
			}
				gotoxy(z,seta);printf(">");
				break;
		}
	}while(op!=13); // 13 é o enter na tabela ASCII
	return seta;
}
void higi (float x)
{
	int qnt;
	do
	{
		gotoxy(15,12);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int higiene();
	higiene();
}
void higiene ()
{
	system("cls");
	gotoxy(7,2);printf("Escova de dente - 11,00");
	gotoxy(7,3);printf("Creme dental - 3,50");
	gotoxy(7,4);printf("Fio dental - 2,00");
	gotoxy(7,5);printf("Sabonete - 1,30");
	gotoxy(7,6);printf("Desodorante - 9,00");
	gotoxy(7,7);printf("Xampu - 15,00");
	gotoxy(7,8);printf("Condicionador - 15,00");
	gotoxy(7,9);printf("Absorvente - 5,00");
	gotoxy(7,10);printf("Voltar");
	gotoxy(10,15);printf(" ____________________________________	");
	gotoxy(10,16);printf("<\\___________________________________\\_______ ");
	gotoxy(10,17);printf("<|				      |_______| ");
	gotoxy(10,18);printf("<|	      C O L G A T E	      |_______| ");
	gotoxy(10,19);printf("<|___________________________________|_______| ");
	gotoxy(10,20);printf("</____________________________________/ ");
	int op;
	int qnt;
	op = seta(2,10,5);
	setlocale(LC_ALL,"Portuguese");
		switch(op)
		{
			case 2: higi (11.00);
				break;
			case 3: higi (3.50);
				break;
			case 4: higi (2.00);
				break;
			case 5: higi (1.30);
				break;
			case 6: higi (9.00);
				break;
			case 7: higi (15.00);
				break;
			case 8: higi(15.00);
				break;
			case 9: higi (5.00);
				break;
			case 10: int comprar ();
					 comprar ();
				break;
		}
	system("cls");
}
void horti (float x)
{
	int qnt;
	do
	{
		gotoxy(15,21);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int hortifruti();
	hortifruti();
}
void hortifruti()
{
	system("cls");
	gotoxy(7,2);printf("Maçã - 0,40");
	gotoxy(7,3);printf("Banana - 0,20");
	gotoxy(7,4);printf("Pera - 0,60");
	gotoxy(7,5);printf("Limão - 0,40");
	gotoxy(7,6);printf("Laranja - 0,40");
	gotoxy(7,7);printf("Mamão - 2,00");
	gotoxy(7,8);printf("Melancia - 7,00");
	gotoxy(7,9);printf("Maracujá - 0,90");
	gotoxy(7,10);printf("Uva - 6,00");
	gotoxy(7,11);printf("Morango - 4,50");
	gotoxy(7,12);printf("Abacaxi - 7,00");
	gotoxy(7,13);printf("Goiaba - 0,90");
	gotoxy(7,14);printf("Alface - 3,00");
	gotoxy(7,15);printf("Tomate - 1,00");
	gotoxy(7,16);printf("Brócolis - 5,00");
	gotoxy(7,17);printf("Batata - 0,30");
	gotoxy(7,18);printf("Caixa de ovos - 5,00");
	gotoxy(7,19);printf("Voltar");
	gotoxy(45,3); printf("           /)          ");
	gotoxy(45,4); printf("        ,.//,          ");
	gotoxy(45,5); printf("       /` `'` `\\        ");
	gotoxy(45,6); printf("      :         :       ");
	gotoxy(45,7); printf("     :           :      ");
	gotoxy(45,8); printf("    :             :     ");
	gotoxy(45,9); printf("   :               :    ");
	gotoxy(45,10);printf("  :                 ;   ");
	gotoxy(45,11);printf(" :                   :  ");
	gotoxy(45,12);printf(" ;                   ;  ");
	gotoxy(45,13);printf(" ;                   ;  ");
	gotoxy(45,14);printf(" :                   :  ");
	gotoxy(45,15);printf(" :                   :  ");
	gotoxy(45,16);printf(" :                   :  ");
	gotoxy(45,17);printf("  \\                 /  ");
	gotoxy(45,18);printf("   `.             .`   ");
	gotoxy(45,19);printf("     '-._     _.-'      ");
	gotoxy(45,20);printf("         `'''`          ");
	int op;
	int qnt;
	op = seta(2,19,5);
	setlocale(LC_ALL,"Portuguese");
		switch(op)
		{
			case 2: horti(0.40);	
				break;
			case 3: horti(0.20);
				break;
			case 4: horti (0.60);
				break;
			case 5: horti(0.40);
				break;
			case 6: horti(0.40);
				break;
			case 7: horti (2.00);
				break;
			case 8: horti (7.00);
				break;
			case 9: horti(0.90);
				break;
			case 10: horti (6.00);
				break;
			case 11: horti (4.50);
				break;
			case 12: horti(7.00);
				break;
			case 13: horti (0.90);
				break;
			case 14: horti (3.00);
				break;
			case 15: horti(1.00);
				break;
			case 16: horti (5.00);
				break;
			case 17: horti (0.30);
				break;
			case 18: horti (5.00);
				break;
			case 19: int comprar ();
					 comprar();	
				break;
		}
	system("cls");
}
void doce (float x)
{
	int qnt;
	do
	{
		gotoxy(15,9);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int doces();
	doces();
}
void doces()
{
	system("cls");
	gotoxy(7,2);printf("M&M - 2,00");
	gotoxy(7,3);printf("Chocolate em barra - 5,00");
	gotoxy(7,4);printf("Chocolate em pó - 4,00");
	gotoxy(7,5);printf("Nutella - 10,00");
	gotoxy(7,6);printf("Paçoca - 2,00");
	gotoxy(7,7);printf("Voltar");
	gotoxy(20,15);printf("    __________________,............., ");
	gotoxy(20,16);printf("   /_/_/_/_/_/_/_/_/,-',  ,. -,-,--/| ");
	gotoxy(20,17);printf("  /_/_/_/_/_/_/_/,-' //  /-| / /--/ / ");
	gotoxy(20,18);printf(" /_/_/_/_/_/_/,-' `-''--'  `' '--/ / ");
	gotoxy(20,19);printf("/_/_/_/_/_/_,:................../ / ");
	gotoxy(20,20);printf("|________,'_____________________|/ ");
	int op;
	int qnt;
	op = seta(2,7,5);
	setlocale(LC_ALL,"Portuguese");
		switch(op)
		{
			case 2: doce (2.00);
				break;
			case 3: doce (5.00);
				break;
			case 4: doce (4.00);
				break;
			case 5: doce (10.00);
				break;
			case 6: doce (2.00);
				break;
			case 7: int comprar ();
					comprar();
				break;
		}
	system("cls");
}
int limpe (float x)
{
	int qnt;
	do
	{
		gotoxy(15,11);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int limpeza();
	limpeza();
}
int limpeza ()
{
	system("cls");
	gotoxy(7,2);printf("Amaciante - 12,00");
	gotoxy(7,3);printf("Detergente - 4,00");
	gotoxy(7,4);printf("Sabão em pó - 6,00");
	gotoxy(7,5);printf("Sabão em pedra - 3,50");
	gotoxy(7,6);printf("Desinfetante - 8,00");
	gotoxy(7,7);printf("Água sanitária - 8,00");
	gotoxy(7,8);printf("Palha de aço - 2,00");
	gotoxy(7,9);printf("Voltar");
	gotoxy(10,16);printf("                                   _ _ _ _ _ _ ");
	gotoxy(10,17);printf("                                 /|_ _ _ _ _ _| ");
	gotoxy(10,18);printf(" _______________________________/ |_ _ _ _ _ _| ");
	gotoxy(10,19);printf("|_______________________________| |_ _ _ _ _ _| ");
	gotoxy(10,20);printf("                                \\ |_ _ _ _ _ _| ");
	gotoxy(10,21);printf("                                 \\|_ _ _ _ _ _| ");
	int op;
	op = seta (2,9,5);
	setlocale(LC_ALL,"Portuguese");
	switch (op)
	{
		case 2: limpe(12.00);
			break;
		case 3: limpe(4.00);
			break;
		case 4: limpe(6.00);
			break;
		case 5: limpe(3.50);
			break;
		case 6: limpe(8.00);
			break;
		case 7: limpe(8.00);
			break;
		case 8: limpe (2.00);
			break;
		case 9: int comprar ();
				comprar();
			break;
	}
	
}
int bebi (float x)
{
	int qnt;
	do
	{
		gotoxy(15,9);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int bebidas();
	bebidas();
}
int bebidas ()
{
	system("cls");
	gotoxy(7,2);printf("Água (garrafa 500 mL) - 2,00");
	gotoxy(7,3);printf("Suco - 4,00");
	gotoxy(7,4);printf("Refrigerante - 2,50");
	gotoxy(7,5);printf("Vinho - 30,00");
	gotoxy(7,6);printf("Cerveja - 4,00");
	gotoxy(7,7);printf("Voltar");
	gotoxy(10,10);printf("                                                 ,--,");
	gotoxy(10,11);printf("                                                 )''( ");
	gotoxy(10,12);printf("                   _                            /    \\  ");
	gotoxy(10,13);printf("                  {_}                          /      \\   ");
	gotoxy(10,14);printf("                  |(|                         .        .  ");
	gotoxy(10,15);printf("                  |=|                         |`-....-'|   ");
	gotoxy(10,16);printf(" .~~~~.          /   \\                        |  ÁGUA  |   ");
	gotoxy(10,17);printf(" i====i          |.--|          \\~~~/         | MINERAL|   ");
	gotoxy(10,18);printf(" |cccc|_         ||  |   \\~~~/   \\_/          |`-....-'|   ");
	gotoxy(10,19);printf(" |cccc|_)        ||  |    \\_/     |           |        |    ");
	gotoxy(10,20);printf(" |cccc|          |'--|     |     _|_          |        |    ");
	gotoxy(10,21);printf(" `-==-'          '-=-'    _|_                  `-....-'   ");
	int op;
	op = seta (2,7,5);
	setlocale(LC_ALL,"Portuguese");
	switch (op)
	{
		case 2: bebi (2.00);
			break;
		case 3: bebi (4.00);
			break;
		case 4: bebi (2.50);
			break;
		case 5: bebi (30.00);
			break;
		case 6: bebi (4.00);
			break;
		case 7: int comprar ();
				comprar ();
	}
}
int latc (float x)
{
	int qnt;
	do
	{
		gotoxy(4,7);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int laticinios();
	laticinios();
}
int laticinios ()
{
	system("cls");
	gotoxy(7,2);printf("Leite 1L - 3,00");
	gotoxy(7,3);printf("Iogurte - 4,00");
	gotoxy(7,4);printf("Requeijão - 4,50");
	gotoxy(7,5);printf("Voltar");
	gotoxy(40,6); printf("   _________");
	gotoxy(40,7); printf("  | _______ | ");
	gotoxy(40,8); printf(" / \\         \\ ");
	gotoxy(40,9); printf("/___\\_________\\ ");
	gotoxy(40,10);printf("|   | \\       |");
	gotoxy(40,11);printf("|   |  \\      |");
	gotoxy(40,12);printf("|   |   \\     |");
	gotoxy(40,13);printf("|   | M  \\    |");
	gotoxy(40,14);printf("|   |     \\   |");
	gotoxy(40,15);printf("|   |\\  I  \\  |");
	gotoxy(40,16);printf("|   | \\     \\ |");
	gotoxy(40,17);printf("|   |  \\  L  \\|");
	gotoxy(40,18);printf("|   |   \\     |");
	gotoxy(40,19);printf("|   |    \\  K |");
	gotoxy(40,20);printf("|   |     \\   |");
	gotoxy(40,21);printf("|   |      \\  |");
	gotoxy(40,22);printf("|___|_______\\_|");
	int op;
	op = seta(2,5,5);
	setlocale(LC_ALL,"Portuguese");
	switch (op)
	{
		case 2: latc(3.00);
			break;
		case 3: latc (4.00);
			break;
		case 4: latc (4.50);
			break;
		case 5: int comprar ();
				comprar();
	}
}
int merc (float x)
{
	int qnt;
	do
	{
		gotoxy(15,17);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int mercearia();
	mercearia();
}
int mercearia ()
{
	system("cls");
	gotoxy(7,2);printf("Macarrão - 3,00");
	gotoxy(7,3);printf("Feijão - 3,00");
	gotoxy(7,4);printf("Arroz - 2,50");
	gotoxy(7,5);printf("Farinha de trigo - 3,00");
	gotoxy(7,6);printf("Óleo - 5,00");
	gotoxy(7,7);printf("Açúcar - 2,50");
	gotoxy(7,8);printf("Sal - 2,00");
	gotoxy(7,9);printf("Pipoca - 5,00");
	gotoxy(7,10);printf("Café - 7,00");
	gotoxy(7,11);printf("Molho de tomate - 4,00");
	gotoxy(7,12);printf("Azeite - 10,00");
	gotoxy(7,13);printf("Bolacha recheada - 4,00");
	gotoxy(7,14);printf("Barrinha de cereal - 1,00");
	gotoxy(7,15);printf("Voltar");
	gotoxy(45,3); printf("     @@@@@@@@");
	gotoxy(45,4); printf("   @@@@@@@@@@@");
	gotoxy(45,5); printf("  @@@@@@@@@@@@/|");
	gotoxy(45,6); printf(" @@@@@@@@@@@@/ |");
	gotoxy(45,7); printf("|\\/\\/\\/\\/\\/\\/| |");
	gotoxy(45,8); printf("|          | |/|");
	gotoxy(45,9); printf("|==========|/| |");
	gotoxy(45,10); printf("|          | | |");
	gotoxy(45,11); printf("|  PIPOCA  | | |");
	gotoxy(45,12); printf("|          | |/|");
	gotoxy(45,13); printf("|==========|/|/");
	gotoxy(45,14); printf("|__________|/");
	int op;
	op = seta (2,15,5);
	setlocale(LC_ALL,"Portuguese");
	switch (op)
	{
		case 2: merc (3.00);
			break;
		case 3: merc (3.00);
			break;
		case 4: merc (2.50);
			break;
		case 5: merc (3.00);
			break;
		case 6: merc (5.00);
			break;
		case 7: merc (2.50);
			break;
		case 8: merc (2.00);
			break;
		case 9: merc (5.00);
			break;
		case 10: merc (7.00);
			break;
		case 11: merc (4.00);
			break;
		case 12: merc (10.00);
			break;
		case 13: merc (4.00);
			break;
		case 14: merc (1.00);
			break;
		case 15: int comprar ();
				 comprar ();
			break;
	}
}
int pad (float x)
{
	int qnt;
	do
	{
		gotoxy(13,9);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int padaria();
	padaria();
}
int padaria ()
{
	system("cls");
	gotoxy(7,2);printf("Pão francês (kg) - 8,00");
	gotoxy(7,3);printf("Pão de forma - 5,00");
	gotoxy(7,4);printf("Pão de queijo - 3,00");
	gotoxy(7,5);printf("Bolo - 20,00");
	gotoxy(7,6);printf("Torrada - 6,00");
	gotoxy(7,7);printf("Voltar");
	gotoxy(35,10); printf("        ,a@@@@@@@@@@@@@@@a,");
	gotoxy(35,11); printf("      ,a@@@@@@@@@.@@@@@@@@@a,  ");
	gotoxy(35,12); printf("     ,a@@@@@@@@@' '@@@@@@@@@a,");
	gotoxy(35,13); printf("    a@@@@@@@@@'     '@@@@@@@@@a");
	gotoxy(35,14); printf("    @@'@@@@@@'   -   '@@@@@@'@@");
	gotoxy(35,15); printf("    @@;aaaaa     -     aaaaa;@@");
	gotoxy(35,16); printf("    @;;;;;;;     -     ;;;;;;;@");
	gotoxy(35,17); printf("    ;;;;;;;;     -     ;;;;;;;;");
	gotoxy(35,18); printf("    ;;;;;;;;   ,%%%%%%,   ;;;;;;;;");
	gotoxy(35,19); printf("  %%%%;;;;;;;;  ,%%%%%%%%%%,  ;;;;;;;;%%%%");
	gotoxy(35,20); printf(" %%%%%%%% ;;;;;; ,%%%%%%%%%%%%%%, ;;;;;;; %%%%%%%");
	gotoxy(35,21); printf("%%%%%%%%%%%% ;;;;;,%%%%%%%%%%%%%%%%%%,;;;;; %%%%%%%%%%%%");
	gotoxy(35,22); printf(" %%%%%%%%%%%%%%,,,,%%%%%%%%%%%%%%%%%%%%%%,,,,%%%%%%%%%%%%%%");
	gotoxy(35,23); printf("  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
	int op;
	op = seta(2,7,5);
	setlocale(LC_ALL,"Portuguese");
	switch (op)
	{
		case 2: pad (8.00);
			break;
		case 3: pad (5.00);
			break;
		case 4: pad (3.00);
			break;
		case 5: pad (20.00);
			break;
		case 6: pad (6.00);
			break;
		case 7: int comprar ();
				comprar ();
			break;
	}
}
void acoug (float x)
{
	int qnt;
	do
	{
		gotoxy(15,8);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int acougue();
	acougue();
}
void acougue()
{
	system ("cls");
	gotoxy(7,2);printf("Carne (kg) - 19,00");
	gotoxy(7,3);printf("Frango (kg) - 9,00");
	gotoxy(7,4);printf("Peixe (kg) - 25,00");
	gotoxy(7,5);printf("Quibe (kg) - 14,00");
	gotoxy(7,6);printf("Linguiça (kg) - 12,00");
	gotoxy(7,7);printf("Voltar");
	gotoxy(20,9); printf("                       ,. ");
	gotoxy(20,10);printf("                    ,-'.:\\ ");
	gotoxy(20,11);printf("                 _/'.:'_:'`._    .-._ ");
	gotoxy(20,12);printf("            _.-''        ```-`.,'.::.`-._ ");
	gotoxy(20,13);printf("         _.'                    ``-..:.:.`-. ");
	gotoxy(20,14);printf("       ,'          ____               `-:.:,'      _..-| ");
	gotoxy(20,15);printf("    ,',.      ),''    ```--...___        `-.__..'':..  | ");
	gotoxy(20,16);printf("   / (O )   \\  `.  ___....-----..``-...___      \\::.   | ");
	gotoxy(20,17);printf("  /_' `'  /  )  /,'::::::._:.-'           ````-.-'- .-'| ");
	gotoxy(20,18);printf("  ,-`'. ,' ,'  /  ):::._,'             __...--../::.   | ");
	gotoxy(20,19);printf("  `.        _,'   `--''            _.''           `-.._| ");
	gotoxy(20,20);printf("    `''-..''_                   _.'.:`. ");
	gotoxy(20,21);printf("             ``.  ..--....___.-' `:_.::/ ");
	gotoxy(20,22);printf("                \\ .:`.              `-.\\ ");
	gotoxy(20,23);printf("                  \\:::| ");
	gotoxy(20,24);printf("                   \\_,' ");
	int op;
	op = seta (2,7,5);
	setlocale(LC_ALL,"Portuguese");
	switch (op)
	{
		case 2: acoug (19.00);
			break;
		case 3: acoug (9.00);
			break;
		case 4: acoug (25.00);
			break;
		case 5: acoug (14.00);
			break;
		case 6: acoug (12.00);
			break;
		case 7: int comprar ();
				comprar();
			break;
	}
}
int frio (float x)
{
	int qnt;
	do
	{
		gotoxy(4,10);printf("Digite a quantidade do produto: ");
		scanf("%d",&qnt);
		cont += qnt*x;
	}while (qnt < 0);
	int frios();
	frios();
}
int frios ()
{
	system("cls");
	gotoxy(7,2);printf("Presunto (100 g) - 3,00");
	gotoxy(7,3);printf("Salame (100 g) - 5,00");
	gotoxy(7,4);printf("Mortadela (100 g) - 2,50");
	gotoxy(7,5);printf("Salsicha (100 g) - 4,00");
	gotoxy(7,6);printf("Peito de peru (100 g) - 6,00");
	gotoxy(7,7);printf("Queijo mussarela (100 g) - 6,00");
	gotoxy(7,8);printf("Voltar");
	gotoxy(40,6); printf("       _''_       ");
	gotoxy(40,7); printf("     _' .  ''_               ");
	gotoxy(40,8); printf("   _' .  .  . ''_          ");
	gotoxy(40,9); printf(" .' .  .  .    . ''_         ");
	gotoxy(40,10);printf("|''--.. .    .   .  ''_     ");
	gotoxy(40,11);printf("| . .  ''--..  .   .  .''_      ");
	gotoxy(40,12);printf("|  .   .   . ''--..  .  . ''_            ");
	gotoxy(40,13);printf("| .  .    . __  .  ''--.. . .''_        ");
	gotoxy(40,14);printf("|  __   .  /  \\   .  .   ''--.. ''_     ");
	gotoxy(40,15);printf("| /  \\ .   \\__/ .      .  __   ''--''.  ");
	gotoxy(40,16);printf("| \\__/   .  .    .  .    /  \\ .   .  |   ");
	gotoxy(40,17);printf("| .   .      .  __ .  .  \\__/   .   .|   ");
	gotoxy(40,18);printf("|   .   .  .   /  \\    .  .   .    . |   ");
	gotoxy(40,19);printf(" ''--..   .  . \\__/  .    __ .  .  __|        ");
	gotoxy(40,20);printf("       ''--..   .   .  . /  \\  .  /           ");
	gotoxy(40,21);printf("             ''--..   .  \\__/ . . \\__.          ");
	gotoxy(40,22);printf("                   ''--..   .  .   . |         ");
	gotoxy(40,23);printf("                         ''--..  .   |       ");
	gotoxy(40,24);printf("                               ''--..'     ");
	int op;
	op = seta (2,8,5);
	setlocale(LC_ALL,"Portuguese");
	switch (op)
	{
		case 2: frio (3.00);
			break;
		case 3: frio (5.00);
			break;
		case 4: frio (2.50);
			break;
		case 5: frio (4.00);
			break;
		case 6: frio (6.00);
			break;
		case 7: frio (6.00);
			break;
		case 8: int comprar ();
				comprar ();
			break;
	}
}
int dinheiro ()
{
	system("cls");
	caixa();
	gotoxy(35,4);printf("C A I X A");
	gotoxy(30,6);printf("Valor a pagar = %0.2f",cont);
	float p;
	gotoxy(26,8);printf("Digite o valor depositado: ");
	scanf("%f", &p);
	while (p < cont)
	{
		gotoxy(23,10);printf ("Valor inferior ao da compra. Redigite!");
		gotoxy(52,8);clreol();
		gotoxy(52,8);scanf("%f", &p);
	}
	gotoxy(23,10);clreol();
	gotoxy(5,10); printf("            |  |                                         |  |");
	gotoxy(30,10);printf("PAGAMENTO APROVADO!!");
	if (p > cont)
	{
		float t = p-cont;
		gotoxy(33,12);printf("Troco: %.2f", t);
	}
	gotoxy(5,14);getch();
	cont = 0;
	int menu();
	menu();
}
int cartao ()
{
	system("cls");
	caixa();
	gotoxy(35,3);printf("C A I X A");
	gotoxy(30,5);printf("Valor a pagar = %0.2f",cont);
	char c;
	int par;
	int senha;
	do
	{
		gotoxy(22,7);printf("Deseja parcelar o valor da compra? S/N: ");
		gotoxy(61,7);c = getche();
	}while (c!='s' && c!='n' && c!='S' && c!= 'N');
	if (c =='s' || c == 'S')
	{
		do
		{
			gotoxy(21,8);printf("Digite o número de parcelas (Máximo 4): ");
			scanf("%d", &par);
		}while (par > 4 || par < 1);
		gotoxy(28,9);printf("Valor de cada parcela: %0.2f", cont/par);
	}
	gotoxy(27,11);printf("Digite a senha do cartão: ");
	gotoxy(53,11);scanf("%d", &senha);
	while (senha < 999 || senha > 10000)
	{
		gotoxy(22,13);printf("Digite uma senha válida de 4 dígitos! ");
		gotoxy(53,11);clreol();
		gotoxy(53,11);scanf("%d", &senha);
	}
	gotoxy(22,13);clreol();
	gotoxy(5,13); printf("            |  |                                         |  |");
	gotoxy(30,13);printf("PAGAMENTO APROVADO!!");
	gotoxy(5,16);getch();
	cont = 0;
	int menu ();
	menu();
}
int cheque ()
{
	system ("cls");
	caixa();
	gotoxy(35,4);printf("C A I X A");
	gotoxy(30,6);printf("Valor a pagar = %0.2f",cont);
	char c;
	int par;
	do
	{
		gotoxy(22,8);printf("Deseja parcelar o valor da compra? S/N: ");
		gotoxy(61,8);c = getche();
	}while (c!='s' && c!='n' && c!='S' && c!= 'N');
	if (c =='s' || c == 'S')
	{
		do
		{
			gotoxy(21,10);printf("Digite o número de parcelas (Máximo 4): ");
			scanf("%d", &par);
		}while (par > 4 || par < 1);
		gotoxy(28,12);printf("Valor de cada parcela: %0.2f", cont/par);
	}
	gotoxy(30,14);printf("PAGAMENTO APROVADO!!");
	gotoxy(5,16);getch();
	cont = 0;
	int menu();
	menu();
}
int pagamento()
{
	system("cls");
	caixa();
	gotoxy(35,3);printf("C A I X A");
	gotoxy(30,5);printf("Valor a pagar = %0.2f",cont);
	int op;
	gotoxy(32,8);printf("FORMA DE PAGAMENTO");
	gotoxy(28,10);printf("Dinheiro");
	gotoxy(28,12);printf("Cartão");
	gotoxy(28,14);printf("Cheque");
	op = seta2(10,14,26);
	system ("cls");
	switch (op)
	{
		case 10: dinheiro();
			break;
		case 12: cartao();
			break;
		case 14: cheque();
			break;
	}	
}
int comprar()
{
	system("cls");
	setlocale(LC_ALL,"C");
	gotoxy(52,4); printf("%c%c",219,219);
	gotoxy(52,5); printf("%c%c",219,219);
	gotoxy(45,6); printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(45,7); printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(45,8); printf("%c%c%c%c   %c%c",219,219,219,219,219);
	gotoxy(45,9); printf("%c%c%c%c   %c%c",219,219,219,219,219);
	gotoxy(45,10);printf("%c%c%c%c   %c%c",219,219,219,219,219,219);
	gotoxy(45,11);printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(45,12);printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(45,13);printf("       %c%c   %c%c%c%c",219,219,219,219,219,219);
	gotoxy(45,14);printf("       %c%c   %c%c%c%c",219,219,219,219,219,219);
	gotoxy(45,15);printf("       %c%c   %c%c%c%c",219,219,219,219,219,219);
	gotoxy(45,16);printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(45,17);printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(52,18);printf("%c%c",219,219);
	gotoxy(52,19);printf("%c%c",219,219);
	setlocale(LC_ALL,"Portuguese");
	int op;
	gotoxy(15,4);printf("C O M P R A S");
	gotoxy(7,7);printf("Hortifruti");
	gotoxy(7,8);printf("Doces");
	gotoxy(7,9);printf("Higiene");
	gotoxy(7,10);printf("Limpeza");
	gotoxy(7,11);printf("Bebidas");
	gotoxy(7,12);printf("Laticinios");
	gotoxy(7,13);printf("Mercearia");
	gotoxy(7,14);printf("Padaria");
	gotoxy(7,15);printf("Açougue");
	gotoxy(7,16);printf("Frios/Rotisserie");
	gotoxy(7,17);printf("Finalizar a compra");
	op = seta(7,17,5);
	system("cls");
	switch (op)
		{
			case 7: hortifruti();
				break;
			case 8: doces();
				break;
			case 9: higiene();
				break;
			case 10: limpeza();
				break;
			case 11: bebidas();
				break;
			case 12: laticinios();
				break;
			case 13: mercearia();
				break;
			case 14: padaria();
				break;
			case 15: acougue();
				break;
			case 16: frios();
				break;
			case 17: pagamento();
				break;
		}
}
void cadastro()
{
	setlocale(LC_ALL,"C");
	system("cls");
	for(int i=0; i<2; i++)
	{
	gotoxy(2,5); printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(2,6); printf(" %c%c",219,219);
	gotoxy(2,7); printf("%c%c",219,219);
	gotoxy(2,8); printf("%c%c",219,219);
	gotoxy(2,9); printf("%c%c",219,219);
	gotoxy(2,10);printf(" %c%c",219,219);
	gotoxy(2,11);printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(12,5); printf("  %c%c%c%c",219,219,219,219);
	gotoxy(12,6); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(12,7); printf("%c%c%c  %c%c%c",219,219,219,219,219,219);
	gotoxy(12,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(12,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(12,10);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(12,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(22,5); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(22,6); printf("%c%c   %c%c",219,219,219,219);
	gotoxy(22,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(22,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(22,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(22,10);printf("%c%c   %c%c",219,219,219,219);
	gotoxy(22,11);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(32,5); printf("  %c%c%c%c",219,219,219,219);
	gotoxy(32,6); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(32,7); printf("%c%c%c  %c%c%c",219,219,219,219,219,219);
	gotoxy(32,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(32,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(32,10);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(32,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(42,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(42,6); printf("%c%c",219,219);
	gotoxy(42,7); printf("%c%c",219,219);
	gotoxy(42,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(42,9); printf("     %c%c",219,219);
	gotoxy(42,10);printf("     %c%c",219,219);
	gotoxy(42,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(51,5); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(51,6); printf("   %c%c",219,219);
	gotoxy(51,7); printf("   %c%c",219,219);
	gotoxy(51,8); printf("   %c%c",219,219);
	gotoxy(51,9); printf("   %c%c",219,219);
	gotoxy(51,10);printf("   %c%c",219,219);
	gotoxy(51,11);printf("   %c%c",219,219);
	
	gotoxy(61,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(61,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(61,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(61,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(61,9); printf("%c%c  %c%c",219,219,219,219);
	gotoxy(61,10);printf("%c%c   %c%c",219,219,219,219);
	gotoxy(61,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(71,5); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(71,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,10);printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	
	Sleep(500);
	system("cls");
	Sleep(500);
	}
	do
	{
		system("cls");
		setlocale(LC_ALL,"Portuguese");
		textcolor(15);
		gotoxy(28,2);printf("CADASTRO DE CLIENTES");
		gotoxy(5,5);printf("CPF (Digite 0 para encerrar cadastro):  ");
		gotoxy(5,7);printf("Nome: ");
		gotoxy(5,9);printf("E-mail: ");
		gotoxy(5,11);printf("Telefone: ");
		gotoxy(45,11);printf("Data de nascimento:   /  /   ");
		gotoxy(8,14);printf("ENDEREÇO");
		gotoxy(5,17);printf("Rua: ");
		gotoxy(45,17);printf("Número: ");
		gotoxy(5,20);printf("Bairro: ");
		gotoxy(45,20);printf("Cidade: ");
		textcolor(0);
		checagem_chave();
		if (strcmp(usu.cpf,"0") == 0)
		{
			int menu();
			menu();
		}
		fflush(stdin);
		int cont;
			do 
	   		{
	   			cont = 0;
				gotoxy(11,7);gets(usu.nome);
				if (strlen (usu.nome) < 3 || usu.nome[0] == ' ' || strlen (usu.nome) > 16)
				{
					cont++;
				}	
				if (cont > 0)
				{
					textcolor(15);
					gotoxy(18,23);printf("Nome inválido! <Mín: 3 / Máx: 16 dígitos>");
					gotoxy(11,7);clreol();	
					textcolor(0);
				}
			}while(cont > 0);
			gotoxy(18,23);clreol();
		//------------------------------------------------------------------
			int cont1,cont2;
			do 
	   		{
	   			cont1 = 0; cont2 = 0;
				gotoxy(13,9);gets(usu.email);
				for (int i = 0; i<strlen(usu.email); i++)
				{
					if (usu.email[i] == '@')
					{
						cont1++;
					}
					if (usu.email[i] == '.')
					{
						cont2++;
					}
				}
				if (cont1 != 1 || cont2 < 1 || strlen(usu.email) < 6 || usu.email[0] == ' ')
				{
					textcolor(15);
					gotoxy(17,23);printf("E-mail inválido. Redigite!");
					gotoxy(13,9);clreol();
					textcolor(0);
				}
			}while(strlen(usu.email) < 6 || usu.email[0] == ' ' || cont1 != 1 || cont2 < 1);
			gotoxy(17,23);clreol();
			//-----------------------------------------------------------------------------------------
			do 
	   		{
	   			cont = 0;
				gotoxy(15,11);gets(usu.telefone);
				if (strlen (usu.telefone) < 8 || usu.telefone[0] == ' ')
					{
						cont++;
					}
				for (int i = 0; i<strlen(usu.telefone); i++)
				{
					if (usu.telefone[i] < '0' || usu.telefone[i] > '9' )
					{
						cont++;
					}
				}
				if (cont > 0)
				{
					textcolor(15);
					gotoxy(18,23);printf("Telefone inválido! Redigite.");
					gotoxy(15,11);clreol();
					gotoxy(45,11);printf("Data de nascimento:   /  /   ");
					textcolor(0);
				}
			}while(cont > 0);
			gotoxy(18,23);clreol();
			//---------------------------------------------------------------------------------------
			textcolor(15);
			gotoxy(19,25);printf("Tecle ENTER para prosseguir entre dia-mês-ano");
			textcolor(0);
			do 
	   		{
	   			cont = 0;
	   			textcolor(0);
				gotoxy(65,11);scanf("%d",&usu.nasc.dia);
				if (usu.nasc.dia <= 0 || usu.nasc.dia > 31)
				{
					cont++;
				}
				if (cont > 0)
				{
					textcolor(15);
					gotoxy(30,23);printf("Dia inválido. Redigite! ");
					textcolor(0);
				}
			}while(cont > 0);
			gotoxy(30,23);clreol();	
			//--------------------------------------------------------------------------------
			do 
	   		{
	   			cont = 0;
	   			textcolor(0);
				gotoxy(68,11);scanf("%d",&usu.nasc.mes);
				if (usu.nasc.mes < 0 || usu.nasc.mes > 12)
				{
					cont++;
				}
				if (usu.nasc.dia == 31 && (usu.nasc.mes == 2 || usu.nasc.mes == 4 || usu.nasc.mes == 6 || usu.nasc.mes == 9 || usu.nasc.mes == 11))
				{
					cont++;
				}
				if (usu.nasc.mes == 2 && (usu.nasc.dia == 31 || usu.nasc.dia == 30))
				{
					cont++;
				}
				if (cont > 0)
				{
					textcolor(15);
					gotoxy(30,23);printf("Mês inválido. Redigite! ");
					textcolor(0);
				}
			}while(cont > 0);
			gotoxy(30,23);clreol();	
			//-----------------------------------------------------------------------------------
			do 
	   		{
	   			cont = 0;
	   			textcolor(0);
				gotoxy(71,11);scanf("%d",&usu.nasc.ano);
				if (usu.nasc.ano < 1915 || usu.nasc.ano > 2010)
				{
					cont++;
				}
				if (cont > 0)
				{
					textcolor(15);
					gotoxy(30,23);printf("Ano inválido. Redigite!");
					textcolor(0);
				}
			}while(cont > 0);
			fflush(stdin);
			gotoxy(30,23);clreol();
			gotoxy(19,25);clreol();
			//--------------------------------------------------------------------------------------
			do 
	   		{
	   			cont = 0;
				gotoxy(10,17);gets(usu.local.rua);
					if (strlen (usu.local.rua) < 5 || usu.local.rua[0] == ' ')
					{
						cont++;
					}
					if (cont > 0)
					{
						textcolor(15);
						gotoxy(23,23);printf("Rua inválida! <Mín: 5 dígitos>");
						gotoxy(10,17);clreol();
						gotoxy(45,17);printf("Número: ");
						textcolor(0);
					}
			}while(cont > 0);
			gotoxy(23,23);clreol();
			//----------------------------------------------------------------------------------------
			do 
	   		{
	   			cont = 0;
				gotoxy(53,17);gets(usu.local.num);
				if (usu.local.num[0] == ' ') 
				{
					cont++;
				}
				if (cont > 0)
				{
					textcolor(15);
					gotoxy(23,23);printf("Número inválido!");
					gotoxy(53,17);clreol();
					textcolor(0);
				}
			}while(cont > 0);
			gotoxy(23,23);clreol();
			//---------------------------------------------------------------------------------------
			do 
	   		{
	   			cont = 0;
				gotoxy(13,20);gets(usu.local.bairro);
					if (strlen (usu.local.bairro) < 5 || usu.local.bairro[0] == ' ')
					{
						cont++;
					}
					if (cont > 0)
					{
						textcolor(15);
						gotoxy(23,23);printf("Bairro inválido! <Mín: 5 dígitos>");
						gotoxy(13,20);clreol();
						gotoxy(45,20);printf("Cidade: ");
						textcolor(0);
					}
			}while(cont > 0);
			gotoxy(23,23);clreol();
			//--------------------------------------------------------------------------------------
			do 
	   		{
	   			cont = 0;
				gotoxy(53,20);gets(usu.local.cidade);
				if (strlen (usu.local.cidade) < 3 || usu.local.cidade[0] == ' ')
				{
					cont++;
				}
				if (cont > 0)
				{
					textcolor(15);
					gotoxy(23,23);printf("Cidade inválida. Redigite!");
					gotoxy(53,20);clreol();
					textcolor(0);
				}
			}while(cont > 0);
			usu.excluido='n';
			gotoxy(23,23);clreol();
			fflush(stdin);
			salvar_dados();
	}while(strcmp(usu.cpf,"0") != 0);
	system("cls");
}
void carregando ()
{
	int time = 400;
	for (int x=29; x<=51; x++)	
		{
			gotoxy(x,13); printf("%c",205);
		}
	gotoxy(33,12);printf("...CARREGANDO...");
	for (int x=29; x<=51; x++)	
		{
			gotoxy(x,15); printf("%c",205);
		}
	for (int i = 0; i<23; i+=2)
	{
			Sleep(time);
			textcolor(10);
		    gotoxy(29+i,14);printf("%c",219);
		    time-=35;
	}
	Sleep(90);
	textcolor(15);
	Sleep(2000);
	system("cls");
}
void titulo()
{
	setlocale(LC_ALL,"C");
	for (int i=0; i<3; i++)
	{
		gotoxy(28,5);printf("S U P E R M E R C A D O S");
		gotoxy(9,8); printf("%c%c%c%c    %c%c%c%c     %c%c%c%c%c%c%c     %c%c       %c%c       %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); //1
		gotoxy(9,9); printf("%c%c%c%c    %c%c%c%c    %c%c     %c%c    %c%c       %c%c       %c%c%c%c%c%c%c%c %c%c    %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  //2
		gotoxy(9,10);printf("%c%c %c%c  %c%c %c%c   %c%c       %c%c   %c%c       %c%c       %c%c       %c%c    %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);   //3
		gotoxy(9,11);printf("%c%c %c%c  %c%c %c%c  %c%c         %c%c  %c%c       %c%c       %c%c       %c%c    %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);    //4
		gotoxy(9,12);printf("%c%c  %c%c%c%c  %c%c %c%c           %c%c %c%c       %c%c       %c%c%c%c%c%c   %c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);     //5 -- 
		gotoxy(9,13);printf("%c%c        %c%c %c%c           %c%c %c%c       %c%c       %c%c%c%c%c%c   %c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);                 //6 --
		gotoxy(9,14);printf("%c%c        %c%c  %c%c         %c%c  %c%c       %c%c       %c%c       %c%c  %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);                        //7
		gotoxy(9,15);printf("%c%c        %c%c   %c%c       %c%c   %c%c       %c%c       %c%c       %c%c   %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);                       //8
		gotoxy(9,16);printf("%c%c        %c%c    %c%c     %c%c    %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c    %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);             //9
		gotoxy(9,17);printf("%c%c        %c%c     %c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c     %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);         //10
		Sleep(500);
		system("cls");
		Sleep(500);
		
	}
	system("cls");
}
void desenho ()
{
		setlocale(LC_ALL,"Portuguese");
		for (int i = 0; i<=2; i++)
		{
		textcolor(10);
		gotoxy(45,2);printf("        _ ");
		gotoxy(45,3);printf("        \\\\       ___ ");
		gotoxy(45,4);printf("         \\\\    /   /");
		gotoxy(45,5);printf("          \\\\  /___/");
		gotoxy(45,6);printf("      		\\\\");
		textcolor(10);
		gotoxy(45,6);printf("      ________________");
		gotoxy(45,7);printf("     /                \\ ");
		gotoxy(45,8);printf("    /                  \\ ");
		gotoxy(45,9);printf("   /                    \\ ");
		gotoxy(45,10);printf("  /                      \\ ");
		gotoxy(45,11);printf(" |                        |");
		gotoxy(45,12);printf(" |                        |");
		gotoxy(45,13);printf(" |                        |");
		textcolor(15);
		gotoxy(54,11);printf("Hora: %s",__TIME__);
		textcolor(10);
		gotoxy(45,13);printf(" |                        |");
		textcolor(15);
		gotoxy(52,12);printf("Data: %s",__DATE__);
		textcolor(10);
		gotoxy(45,13);printf(" |                        |");
		gotoxy(45,14);printf(" |                        |");
		gotoxy(45,15);printf("  \\                      /");
		gotoxy(45,16);printf("   \\                    /");
		gotoxy(45,17);printf("    \\                  /");
		gotoxy(45,18);printf("     \\________________/");
		textcolor(0);
		Sleep(400);
		textcolor(10);
		gotoxy(45,2);printf("        _ ");
		gotoxy(45,3);printf("        \\\\       ___ ");
		gotoxy(45,4);printf("         \\\\    /   /");
		gotoxy(45,5);printf("          \\\\  /___/");
		gotoxy(45,6);printf("      		\\\\");
		textcolor(10);
		gotoxy(45,6);printf("      ________________");
		gotoxy(45,7);printf("     /                \\ ");
		gotoxy(45,8);printf("    /                  \\ ");
		gotoxy(45,9);printf("   /                    \\ ");
		gotoxy(45,10);printf("  /                      \\ ");
		gotoxy(45,11);printf("   \\                      |");
		gotoxy(45,12);printf("    \\                     |");
		textcolor(15);
		gotoxy(54,11);printf("Hora: %s",__TIME__);
		textcolor(10);
		gotoxy(45,13);printf("     |                    |");
		gotoxy(45,13);printf("    |                    |");
		gotoxy(45,13);printf("     |                    |");
		textcolor(15);
		gotoxy(52,12);printf("Data: %s",__DATE__);
		textcolor(10);
		gotoxy(45,14);printf("    /                     |");
		gotoxy(45,15);printf("   /                     /");
		gotoxy(45,16);printf("   \\                    /");
		gotoxy(45,17);printf("    \\                  /");
		gotoxy(45,18);printf("     \\________________/");
		textcolor(0);
		Sleep(400);
	}
}
void comp()
{
	system("cls");
	setlocale(LC_ALL,"C");
	for(int i=0;i<2;i++)
	{
	gotoxy(7,5); printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(7,6); printf(" %c%c",219,219);
	gotoxy(7,7); printf("%c%c",219,219);
	gotoxy(7,8); printf("%c%c",219,219);
	gotoxy(7,9); printf("%c%c",219,219);
	gotoxy(7,10);printf(" %c%c",219,219);
	gotoxy(7,11);printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(17,5); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(17,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(17,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(17,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(17,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(17,10);printf("%c%c    %c%c",219,219,219,219);
	gotoxy(17,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(27,5); printf("%c%c     %c%c",219,219,219,219);
	gotoxy(27,6); printf("%c%c%c   %c%c%c",219,219,219,219,219,219);
	gotoxy(27,7); printf("%c%c%c%c %c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(27,8); printf("%c%c %c%c%c %c%c",219,219,219,219,219,219,219);
	gotoxy(27,9); printf("%c%c  %c  %c%c",219,219,219,219,219);
	gotoxy(27,10);printf("%c%c     %c%c",219,219,219,219);
	gotoxy(27,11);printf("%c%c     %c%c",219,219,219,219);
	
	gotoxy(38,5); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(38,6); printf("%c%c   %c%c",219,219,219,219);
	gotoxy(38,7); printf("%c%c   %c%c",219,219,219,219);
	gotoxy(38,8); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(38,9); printf("%c%c",219,219);
	gotoxy(38,10);printf("%c%c",219,219);
	gotoxy(38,11);printf("%c%c",219,219);
	
	gotoxy(47,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(47,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(47,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(47,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(47,9); printf("%c%c  %c%c",219,219,219,219);
	gotoxy(47,10);printf("%c%c   %c%c",219,219,219,219);
	gotoxy(47,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(57,5); printf("  %c%c%c%c",219,219,219,219);
	gotoxy(57,6); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(57,7); printf("%c%c%c  %c%c%c",219,219,219,219,219,219);
	gotoxy(57,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(57,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(57,10);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(57,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(67,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(67,6); printf("%c%c",219,219);
	gotoxy(67,7); printf("%c%c",219,219);
	gotoxy(67,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(67,9); printf("     %c%c",219,219);
	gotoxy(67,10);printf("     %c%c",219,219);
	gotoxy(67,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	Sleep(500);
	system("cls");
	Sleep(500);
	}
}
void desenho2 ()
{
		textcolor(0);
		textcolor(10);
		gotoxy(45,2);printf("        _ ");
		gotoxy(45,3);printf("        \\\\       ___ ");
		gotoxy(45,4);printf("         \\\\    /   /");
		gotoxy(45,5);printf("          \\\\  /___/");
		gotoxy(45,6);printf("      		\\\\");
		textcolor(10);
		gotoxy(45,6);printf("      ________________");
		gotoxy(45,7);printf("     /                \\ ");
		gotoxy(45,8);printf("    /                  \\ ");
		gotoxy(45,9);printf("   /                    \\ ");
		gotoxy(45,10);printf("  /                      \\ ");
		gotoxy(45,11);printf(" |                        |");
		gotoxy(45,12);printf(" |                        |");
		gotoxy(45,13);printf(" |                        |");
		textcolor(15);
		gotoxy(54,11);printf("Hora: %s",__TIME__);
		textcolor(10);
		gotoxy(45,13);printf(" |                        |");
		textcolor(15);
		gotoxy(52,12);printf("Data: %s",__DATE__);
		textcolor(10);
		gotoxy(45,13);printf(" |                        |");
		gotoxy(45,14);printf(" |                        |");
		gotoxy(45,15);printf("  \\                      /");
		gotoxy(45,16);printf("   \\                    /");
		gotoxy(45,17);printf("    \\                  /");
		gotoxy(45,18);printf("     \\________________/");
}
void tabela()
{
	setlocale(LC_ALL,"C");
	gotoxy(2,1);printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(2,2);printf ("%c       NOME       %c      CPF      %c  NASCIMENTO  %c    TELEFONE    %c      CIDADE      %c ",186,186,186,186,186,186);
 	gotoxy(2,3);printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,4);printf ("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,5);printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,6);printf ("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,7);printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,8);printf ("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,9);printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,10);printf("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,11);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,12);printf("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,13);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,14);printf("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,15);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,16);printf("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,17);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,18);printf("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,19);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
 	gotoxy(2,20);printf("%c                  %c               %c              %c                %c                  %c ",186,186,186,186,186,186);
 	gotoxy(2,21);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}
void mostra_dados()
{
	textcolor(15);
	gotoxy(8,4);printf("CPF: ");	
	textcolor(0);
	gotoxy(13,4);puts(usu.cpf);
	textcolor(15);
	gotoxy(8,6);printf("Nome: ");
	textcolor(0);
	gotoxy(14,6);puts(usu.nome);
	textcolor(15);
	gotoxy(8,8);printf("E-mail: ");
	textcolor(0);
	gotoxy(16,8);puts(usu.email);
	textcolor(15);
	gotoxy(8,10);printf("Telefone: ");
	textcolor(0);
	gotoxy(18,10);puts(usu.telefone);
	textcolor(15);
	gotoxy(48,10);printf("Data de nascimento: ");
	textcolor(0);
	if (usu.nasc.mes >= 1 && usu.nasc.mes <= 9)
	{
		gotoxy(68,10);printf("%d/0%d/%d",usu.nasc.dia, usu.nasc.mes, usu.nasc.ano);
	}
	else
	{
		gotoxy(68,10);printf("%d/%d/%d",usu.nasc.dia, usu.nasc.mes, usu.nasc.ano);
	}
	textcolor(15);
	gotoxy(12,12);printf("ENDEREÇO");
	textcolor(15);
	gotoxy(8,14);printf("Rua: ");
	textcolor(0);
	gotoxy(13,14);puts(usu.local.rua);
	textcolor(15);
	gotoxy(53,14);printf("Número: ");
	textcolor(0);
	gotoxy(61,14);puts(usu.local.num);
	textcolor(15);
	gotoxy(8,16);printf("Bairro: ");
	textcolor(0);
	gotoxy(16,16);puts(usu.local.bairro);
	textcolor(15);
	gotoxy(53,16);printf("Cidade: ");
	textcolor(0);
	gotoxy(61,16);puts(usu.local.cidade);
	textcolor(15);
}
void checar_cadastro ()
{
	fflush(stdin);
	system("cls");
	char ch;
	char aux2 [14];
	int x, op;	
	gotoxy(28,2);printf("EFETUAR COMPRA");
	gotoxy(10,7);printf("Digite o CPF <digite 0 para voltar ao menu>: ");
	textcolor(0);
	gotoxy(55,7);gets(aux2);
	textcolor(15);
		if (strcmp(aux2,"0") == 0)
		{
			system("cls");
			int menu();
			menu();
		}
		else
		{
			rewind(fp);
			while( !feof(fp) )
			{
				x = 0;
				if(fread(&usu, sizeof(usu), 1, fp) == 1 && usu.excluido == 'n')
				{						
					if (strcmp(usu.cpf,aux2) == 0)
					{	
			 			x = 1;
			 			gotoxy(25,11);printf("Bem - Vindo(a), %s!",usu.nome);
			 			getche();
			 			comp();
						comprar();
					}
				}
			}
			if (x == 0)
			{
				int op;
				gotoxy(14,12);printf("CPF não encontrado!");
				gotoxy(16,13);printf("Cadastrar CPF");
				gotoxy(16,15);printf("Voltar ao menu");
				gotoxy(16,14);printf("Digitar outro CPF");
				op = seta(13,15,14);
				switch (op)
				{
					case 13: cadastro();
						break;
					case 14: checar_cadastro();
						break;
					case 15: int menu();
							 menu();
				}
			}
		}
}
void checagem_simples ()
{
	tabela();
	abrir_arquivo("rb+");
	int cod=4,nome=4,tel=4,nasc=4,cid=4;
	while(!feof(fp)) 
	{	
 		if(fread(&usu,sizeof(usu),1,fp) == 1 && usu.excluido == 'n')
 		{
 					gotoxy(4,nome);puts(usu.nome);
						nome+=2;
						
  	   			  	gotoxy(23,cod);puts(usu.cpf);
  	   			  		cod+=2;
  	   			  		
    	 		  	gotoxy(40,nasc);printf("%d/%d/%d",usu.nasc.dia, usu.nasc.mes, usu.nasc.ano);
    	 		  		nasc+=2;
    	 		  		
					gotoxy(55,tel);puts(usu.telefone);
						tel+=2;
						
					gotoxy(71,cid);puts(usu.local.cidade);
						cid+=2;
 			if(cod>20 && nome>20 && tel>20 && nasc>20 && cid>20)
 			{
 				char x;
 				gotoxy(2,25);printf("Pressione qualquer tecla para continuar ou 's' para voltar ao menu");
 				x = getch();
 					if (x == 115 || x == 83)
 					{
 						system("cls");
 						int menu();
 						menu();
					}
 				system("cls");
 				tabela();
 				cod=4;
 				nome=4;
 				tel=4;
 			    nasc=4;
				cid=4;
			}   
		}
}
	gotoxy(20,23);system("pause");
	system("cls");
	int consulta_dados();
	consulta_dados();
}
void checagem_cpf()
{
	system("cls");
	gotoxy(28,3);printf("CONSULTA POR CPF");
	char aux [14];
	int x;	
		gotoxy(10,7);printf("Digite o CPF <digite 0 para voltar ao menu>: ");
		textcolor(0);
		gotoxy(55,7);gets(aux);
		textcolor(15);
		if (strcmp(aux,"0") == 0)
		{
			system("cls");
			int menu();
			menu();
		}
		else
		{
			rewind(fp);
			while( !feof(fp) )
			{
				x = 0;
				if(fread(&usu, sizeof(usu), 1, fp) == 1 && usu.excluido == 'n')
				{						
					if (strcmp(usu.cpf,aux) == 0)
					{	
					 	x = 1;
					 	system("cls");
					 	gotoxy(28,2);printf("CONSULTA POR CPF");
						mostra_dados();
						gotoxy(23,23);printf("Deseja digitar outro CPF? S/N: ");
						char ch;
						do
						{
							ch = getche();
						}while (ch != 's' && ch!= 'S' && ch != 'n' && ch != 'N');
						gotoxy(22,25);clreol();
						if (ch == 'N' || ch == 'n')
						{
							system("cls");
							int consulta_dados();
							consulta_dados();
						}
						if (ch == 'S' || ch == 's')
						{
							system("cls");
							checagem_cpf();
						}
					}
				}
			}
			if (x == 0)
			{
				int op;
				gotoxy(14,12);printf("CPF não encontrado!");
				gotoxy(16,13);printf("Cadastrar CPF");
				gotoxy(16,15);printf("Voltar ao menu");
				gotoxy(16,14);printf("Digitar outro CPF");
				op = seta(13,15,14);
				switch (op)
				{
					case 13: cadastro();
						break;
					case 14: checagem_cpf();
						break;
					case 15: int menu();
							 menu();
				}
			}
		}
		system("cls");
		int consulta_dados();
		consulta_dados();
}
void checagem_nome ()
{
	int c=4;
	int ope;
	char op;
	char pesquisa[30];
	char *str;
 	system("cls");
	fflush(stdin);
	abrir_arquivo("rb+");
	char x;
	do
	{
		gotoxy(15,8);printf("Digite o nome para pesquisa: ");
		textcolor(0);
		gotoxy(44,8);gets(pesquisa);
		textcolor(15);
		strupr(pesquisa);
		rewind(fp);
		tabela();
		c=4;
		while(!feof(fp)){
			if(fread(&usu, sizeof(usu), 1, fp) ==1 && usu.excluido == 'n')
			{
				strupr(usu.nome);
				if(strstr(usu.nome,pesquisa) != NULL)
			  	{
					gotoxy(23,c);puts(usu.cpf);
    				gotoxy(4,c);puts(usu.nome);
    				gotoxy(40,c);printf("%d/%d/%d", usu.nasc.dia, usu.nasc.mes, usu.nasc.ano);
   					gotoxy(55,c);puts(usu.telefone);
   					gotoxy(71,c);puts(usu.local.cidade);
   					c+=2;
	    		}
				if(c>20)
				{
					gotoxy (2,24);printf("Pressione qualquer tecla para continuar ou 's' para voltar ao menu");
					gotoxy(80,24);x=getch();
					//setlocale(LC_ALL,"C");
					if (x == 115 || x == 83)
					{
						system("cls");
						int menu();
						menu();
					}
					//setlocale(LC_ALL, "Portuguese");
					system("cls");
					tabela();
					c=4;  
				}
			}
			else
			{
				//fclose(fp);
				getch;
				//system("cls");
			}
		}
		if (feof(fp))
		{
			gotoxy(2,24);printf("Aperte qualquer tecla para realizar nova pesquisa ou 's' para voltar ao menu");
			gotoxy(78,24);op=getch();
			//setlocale(LC_ALL, "C");
			if (op == 115 || op == 83)
			{
				system("cls");
				int menu();
				menu();
			}
		}
		system("cls");
	}while(op!=115 || op!= 83);
	system("cls");
	int consulta_dados();
	consulta_dados();
}
void miniborda()
{
	setlocale(LC_ALL,"C");
	for (int x = 15; x <= 38; x++)
		{
 			gotoxy(x,16); printf("%c",205);
			gotoxy(x,22); printf("%c",205);
		}
	gotoxy(38,16); printf("%c",187);
	gotoxy(14,16); printf("%c",201);
	for (int y = 17; y < 22; y++)
		{
	 		gotoxy(38,y); printf("%c",186);
	 		gotoxy(14,y); printf("%c",186);
		}
	gotoxy(14,22); printf("%c",200);
	gotoxy(38,22); printf("%c",188);
	gotoxy(17,18);printf("Tecle 'w' para cima");
	gotoxy(17,20);printf("Tecle 's' para baixo");
}
void consulta()
{
	setlocale(LC_ALL,"C");
	system("cls");
	for (int i=0; i<2; i++)
	{
	gotoxy(3,5); printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(3,6); printf(" %c%c",219,219);
	gotoxy(3,7); printf("%c%c",219,219);
	gotoxy(3,8); printf("%c%c",219,219);
	gotoxy(3,9); printf("%c%c",219,219);
	gotoxy(3,10);printf(" %c%c",219,219);
	gotoxy(3,11);printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(13,5); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(13,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(13,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(13,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(13,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(13,10);printf("%c%c    %c%c",219,219,219,219);
	gotoxy(13,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(23,5); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(23,6); printf("%c%c%c   %c%c",219,219,219,219,219);
	gotoxy(23,7); printf("%c%c%c%c  %c%c",219,219,219,219,219,219);
	gotoxy(23,8); printf("%c%c %c%c %c%c",219,219,219,219,219,219);
	gotoxy(23,9); printf("%c%c  %c%c%c%c",219,219,219,219,219,219);
	gotoxy(23,10);printf("%c%c   %c%c%c",219,219,219,219,219);
	gotoxy(23,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(33,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(33,6); printf("%c%c",219,219);
	gotoxy(33,7); printf("%c%c",219,219);
	gotoxy(33,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(33,9); printf("     %c%c",219,219);
	gotoxy(33,10);printf("     %c%c",219,219);
	gotoxy(33,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(42,5); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(42,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(42,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(42,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(42,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(42,10);printf("%c%c    %c%c",219,219,219,219);
	gotoxy(42,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(52,5); printf("%c%c",219,219);
	gotoxy(52,6); printf("%c%c",219,219);
	gotoxy(52,7); printf("%c%c",219,219);
	gotoxy(52,8); printf("%c%c",219,219);
	gotoxy(52,9); printf("%c%c",219,219);
	gotoxy(52,10);printf("%c%c",219,219);
	gotoxy(52,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(60,5); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(60,6); printf("   %c%c",219,219);
	gotoxy(60,7); printf("   %c%c",219,219);
	gotoxy(60,8); printf("   %c%c",219,219);
	gotoxy(60,9); printf("   %c%c",219,219);
	gotoxy(60,10);printf("   %c%c",219,219);
	gotoxy(60,11);printf("   %c%c",219,219);
	
	gotoxy(70,5); printf("  %c%c%c%c",219,219,219,219);
	gotoxy(70,6); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(70,7); printf("%c%c%c  %c%c%c",219,219,219,219,219,219);
	gotoxy(70,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(70,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(70,10);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(70,11);printf("%c%c    %c%c",219,219,219,219);
	
	Sleep(500);
	system("cls");
	Sleep(500);
	}
	setlocale(LC_ALL,"Portuguese");
}
void consulta_dados()
{
	gotoxy(10,4);printf("Selecione a opção de consulta abaixo:");
	gotoxy(15,7);printf("Consulta por CPF");
	gotoxy(15,9);printf("Consulta por nome");
	gotoxy(15,11);printf("Consulta geral");
	gotoxy(15,13);printf("Voltar para o menu");
	int op;
	op = seta2(7,13,13);
			switch(op)
			{
				case 7: checagem_cpf();
					break;
				case 9: checagem_nome();
					break;
				case 11: checagem_simples();
					break;
				case 13: int menu();
						 menu();
					break;
			}
}
void sobre ()
{
	system("cls");
	setlocale(LC_ALL,"C");
	for(int i=0; i<5; i++);
	{
	gotoxy(18,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(18,6); printf("%c%c",219,219);
	gotoxy(18,7); printf("%c%c",219,219);
	gotoxy(18,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(18,9); printf("     %c%c",219,219);
	gotoxy(18,10);printf("     %c%c",219,219);
	gotoxy(18,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(27,5); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(27,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(27,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(27,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(27,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(27,10);printf("%c%c    %c%c",219,219,219,219);
	gotoxy(27,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(37,5); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(37,6); printf("%c%c   %c%c",219,219,219,219);
	gotoxy(37,7); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(37,8); printf("%c%c   %c%c",219,219,219,219);
	gotoxy(37,9); printf("%c%c   %c%c",219,219,219,219);
	gotoxy(37,10);printf("%c%c   %c%c",219,219,219,219);
	gotoxy(37,11);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(46,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(46,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(46,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(46,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(46,9); printf("%c%c  %c%c",219,219,219,219);
	gotoxy(46,10);printf("%c%c   %c%c",219,219,219,219);
	gotoxy(46,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(56,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(56,6); printf("%c%c",219,219);
	gotoxy(56,7); printf("%c%c",219,219);
	gotoxy(56,8); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(56,9); printf("%c%c",219,219);
	gotoxy(56,10);printf("%c%c",219,219);
	gotoxy(56,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	Sleep(500);
	system("cls");
	Sleep(500);
	}
	setlocale(LC_ALL,"Portuguese");
	gotoxy(10,4); printf(" Em nossa rede de supermercados 'Moller', temos o objetivo de");
	gotoxy(10,5); printf("trazer tudo o que há de melhor para satisfazer ao máximo seus");
	gotoxy(10,6); printf("desejos e de sua família.");
	gotoxy(10,7); printf(" Aqui você encontra produtos de hortifruti, laticínios, limpe-");
	gotoxy(10,8); printf("za, mercearia, padaria, higiene, frios, doces, bebidas e açou-");
	gotoxy(10,9); printf("gue. Possuímos três opções de pagamento para que você possa es-");
	gotoxy(10,10);printf("colher a que mais lhe atrair, disponibilizando também políticas");
	gotoxy(10,11);printf("de parcelamento. Nosso funcionamento com relação aos dados do");
	gotoxy(10,12);printf("cliente e suas escolhas com relação a seu cadastro foi realizado");
	gotoxy(10,13);printf("pensando no que deixaria nosso consumidor mais confortável.");
	gotoxy(10,14);printf("Com os preços mais atrativos da região e com o melhor atendi-");
	gotoxy(10,15);printf("mento desta, convidamos você a conhecer nossa rede de supermer-");
	gotoxy(10,16);printf("cados e se deliciar nela!");
	gotoxy(45,18);printf("Bem-Vindo!");
	getch();
	system("cls");
	gotoxy(10,4);printf("Trabalho desenvolvido pelos alunos:");
	gotoxy(10,5);printf("Felipe Piccaluga Gomes da Silva - Nª 09");
	gotoxy(10,6);printf("Giovanna Gimenes Moeller - Nº 11");
	gotoxy(10,7);printf("Julia Paschoal Lopreto - Nº 18");
	gotoxy(10,8);printf("Maria Eduarda Rodrigues Garcia - Nº 25");
	gotoxy(10,10);printf("71B/81B - Informática");
	gotoxy(10,11);printf("Disciplina: Fundamentos de Processamento de Dados");
	gotoxy(10,12);printf("Professora: Ariane Scarelli");
	gotoxy(10,13);printf("Colégio Técnico Industrial - Professor Isaac Portal Roldán.");
	getch();
	system("cls");
}
void digita_dados()
{
	textcolor(0);
	int cont;
	do 
 	{
  		cont = 0;
		gotoxy(14,6);gets(usu.nome);
		if (strlen (usu.nome) > 16 || usu.nome[0] == ' ')
		{
			cont++;
		}
		if (usu.nome[0] == ' ')
		{
			cont++;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(23,23);printf("Nome inválido! <Máx: 16 dígitos>");
			gotoxy(14,6);clreol();
			textcolor(0);	
		}
	}while(cont > 0);
	gotoxy(23,23);clreol();
	int cont1,cont2;
	do 
	{
	   	cont1 = 0; cont2 = 0;
		gotoxy(16,8);gets(usu.email);
		for (int i = 0; i<strlen(usu.email); i++)
		{
			if (usu.email[i] == '@' && strlen(usu.email) != 0) 
			{
				cont1++;
			}
			if (usu.email[i] == '.' && strlen(usu.email) != 0)
			{
				cont2++;
			}
		}
		if (strlen(usu.email) == 0)
		{
			cont1 = 1;
			cont2 = 1;
		}
		if (cont1 == 0 || cont2 == 0)
		{
			textcolor(15);
			gotoxy(23,23);printf("E-mail inválido! (use . e @)");
			gotoxy(13,9);clreol();
			textcolor(0);
		}
	}while(cont1 == 0 || cont2 == 0 && strlen(usu.email) != 0);
	gotoxy(23,23);clreol();
	do 
	{
	   	cont = 0;
		gotoxy(18,10);gets(usu.telefone);
		for (int i = 0; i<strlen(usu.telefone); i++)
		{
			if (usu.telefone[i] > '9' )
			{
				cont++;
			}
		}
		if (usu.telefone[0] == ' ')
		{
			cont=0;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(23,23);printf("Telefone inválido! Redigite. (Coloque apenas números)");
			gotoxy(15,11);clreol();
			gotoxy(48,11);printf("Data de nascimento:   /  /   ");
			textcolor(0);
		}
	}while(cont > 0);
	gotoxy(23,23);clreol();
	textcolor(15);
	gotoxy(19,25);printf("Tecle ENTER para prosseguir entre dia-mês-ano");
	textcolor(0);
	char aux_dia[3], aux_mes[3], aux_ano[5];
	do 
	{
	   	cont = 0;
		gotoxy(68,10);gets(aux_dia);
		usu.nasc.dia = atoi(aux_dia);
		if (usu.nasc.dia < 0 || usu.nasc.dia > 31)
		{
			cont++;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(30,23);printf("Dia inválido. Redigite! ");
			textcolor(0);
		}
	}while(cont > 0);
	gotoxy(30,23);clreol();	
	do 
	{
	 	cont = 0;
		gotoxy(71,10);gets(aux_mes);
		usu.nasc.mes = atoi(aux_mes);
		if (usu.nasc.mes < 0 || usu.nasc.mes > 12)
		{
			cont++;
		}
		if (usu.nasc.dia == 31 && (usu.nasc.mes == 2 || usu.nasc.mes == 4 || usu.nasc.mes == 6 || usu.nasc.mes == 9 || usu.nasc.mes == 11))
		{
			cont++;
		}
		if (usu.nasc.mes == 2 && (usu.nasc.dia == 31 || usu.nasc.dia == 30))
		{
			cont++;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(30,23);printf("Mês inválido. Redigite! ");
			textcolor(0);
		}
	}while(cont > 0);
	gotoxy(30,23);clreol();
	do
	{
	   	cont = 0;
		gotoxy(74,10);gets(aux_ano);
		usu.nasc.ano = atoi(aux_ano);
		if (usu.nasc.ano < 0 || usu.nasc.ano > 2010)
		{
			cont++;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(30,23);printf("Ano inválido. Redigite!");
			textcolor(0);
		}
	}while(cont > 0);
	fflush(stdin);
	gotoxy(30,23);clreol();
	gotoxy(19,25);clreol();
	do 
	{
	   	cont = 0;
		gotoxy(13,14);gets(usu.local.rua);
		if (usu.local.rua[0] == ' ')
		{
			cont++;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(23,23);printf("Rua inválida!");
			gotoxy(10,17);clreol();
			gotoxy(45,17);printf("Número: ");
			textcolor(0);
		}
	}while(cont > 0);
	gotoxy(23,23);clreol();
	do 
	{
	   	cont = 0;
		gotoxy(61,14);gets(usu.local.num);
		if (strlen(usu.local.num) > 5 || usu.local.num[0] == ' ') 
		{
			cont++;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(23,23);printf("Número inválido!");
			gotoxy(61,14);clreol();
			textcolor(0);
		}
	}while(cont > 0);
	gotoxy(23,23);clreol();
	do 
	{
	   	cont = 0;
		gotoxy(16,16);gets(usu.local.bairro);
		if (usu.local.bairro[0] == ' ')
		{
			cont++;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(23,23);printf("Bairro inválido!");
			gotoxy(13,20);clreol();
			gotoxy(50,20);printf("Cidade: ");
			textcolor(0);
		}
	}while(cont > 0);
	gotoxy(23,23);clreol();
	do 
	{
	   	cont = 0;
		gotoxy(61,16);gets(usu.local.cidade);
		if (usu.local.cidade[0] == ' ')
		{
			cont++;
		}
		if (cont > 0)
		{
			textcolor(15);
			gotoxy(23,23);printf("Cidade inválida!");
			gotoxy(53,20);clreol();
			textcolor(0);
		}
	}while(cont > 0);
	gotoxy(23,23);clreol();
	textcolor(15);
}
void altera ()
{
	
	setlocale(LC_ALL,"C");
	system("cls");
	for(int i=0; i<2; i++)
	{
	gotoxy(3,5); printf("  %c%c%c%c",219,219,219,219);
	gotoxy(3,6); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(3,7); printf("%c%c%c  %c%c%c",219,219,219,219,219,219);
	gotoxy(3,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(3,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(3,10);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(3,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(12,5); printf("%c%c",219,219);
	gotoxy(12,6); printf("%c%c",219,219);
	gotoxy(12,7); printf("%c%c",219,219);
	gotoxy(12,8); printf("%c%c",219,219);
	gotoxy(12,9); printf("%c%c",219,219);
	gotoxy(12,10);printf("%c%c",219,219);
	gotoxy(12,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(18,5); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(18,6); printf("   %c%c",219,219);
	gotoxy(18,7); printf("   %c%c",219,219);
	gotoxy(18,8); printf("   %c%c",219,219);
	gotoxy(18,9); printf("   %c%c",219,219);
	gotoxy(18,10);printf("   %c%c",219,219);
	gotoxy(18,11);printf("   %c%c",219,219);
	
	gotoxy(27,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(27,6); printf("%c%c",219,219);
	gotoxy(27,7); printf("%c%c",219,219);
	gotoxy(27,8); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(27,9); printf("%c%c",219,219);
	gotoxy(27,10);printf("%c%c",219,219);
	gotoxy(27,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(35,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(35,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(35,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(35,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(35,9); printf("%c%c  %c%c",219,219,219,219);
	gotoxy(35,10);printf("%c%c   %c%c",219,219,219,219);
	gotoxy(35,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(44,5); printf("  %c%c%c%c",219,219,219,219);
	gotoxy(44,6); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(44,7); printf("%c%c%c  %c%c%c",219,219,219,219,219,219);
	gotoxy(44,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(44,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(44,10);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(44,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(53,5); printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(53,6); printf(" %c%c",219,219);
	gotoxy(53,7); printf("%c%c",219,219);
	gotoxy(53,8); printf("%c%c",219,219);
	gotoxy(53,9); printf("%c%c",219,219);
	gotoxy(53,10);printf(" %c%c",219,219);
	gotoxy(53,11);printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(53,12);printf("    %c%c",219,219);
	gotoxy(53,13);printf("   %c%c",219,219);
	
	gotoxy(62,5); printf("  %c%c%c%c",219,219,219,219);
	gotoxy(62,6); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(62,7); printf("%c%c%c  %c%c%c",219,219,219,219,219,219);
	gotoxy(62,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(62,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(62,10);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(62,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(71,5); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(71,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,10);printf("%c%c    %c%c",219,219,219,219);
	gotoxy(71,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(63,2);printf(" %c%c%c %c%c",219,219,219,219,219);
	gotoxy(63,3);printf("%c%c %c%c%c",219,219,219,219,219);
	Sleep(500);
	system("cls");
	Sleep(500);
	}
	setlocale(LC_ALL,"Portuguese");
}
void atualizar ()
{
	fflush(fp);
	system("cls");
	char aux_cod[14];
	int F;
	long fposicao;
	char conf;
	gotoxy(28,2);printf("ALTERAÇÃO DE DADOS");
	gotoxy(10,7);printf("Digite o CPF <digite 0 para voltar ao menu>: ");
	textcolor(0);
	gets(aux_cod);
	textcolor(15);
	rewind(fp);
	F = 0;
	abrir_arquivo("rb+");
		if (strcmp(aux_cod,"0") == 0)
		{
			system("cls");
			int menu ();
			menu();
		}
		else
	do
	{
		fread(&usu,sizeof(usu),1,fp);
		if (strcmp(usu.cpf,aux_cod) == 0 && usu.excluido == 'n')
		{
			system("cls");
			F = 1;
			fposicao = ftell(fp); //guarda a posição do registro atual do arquivo
			mostra_dados();
			gotoxy(28,2);printf("ALTERAÇÃO DE DADOS");
			usu_aux = usu;//salva os dados do registro atual numa estrutura auxiliar
			digita_dados();
			// ******> VERIFICA SE HOUVE ALTERACAO EM CADA UM DOS CAMPOS
			if (usu.nome[0] == '\x0')//checa se cada campo está vazio
				strcpy(usu.nome, usu_aux.nome);
			if (usu.email[0] == '\0')//pode usar '\0' ou '\x0'
				strcpy(usu.email, usu_aux.email);
			if (usu.telefone[0] == '\0')//pode usar '\0' ou '\x0'
				strcpy(usu.telefone, usu_aux.telefone);
			if (usu.nasc.dia == 0)
				usu.nasc.dia = usu_aux.nasc.dia;
			if (usu.nasc.mes == 0)
				usu.nasc.mes = usu_aux.nasc.mes;
			if (usu.nasc.ano == 0)
				usu.nasc.ano = usu_aux.nasc.ano;
			if (usu.local.bairro[0] == '\0')//pode usar '\0' ou '\x0'
				strcpy(usu.local.bairro, usu_aux.local.bairro);
			if (usu.local.cidade[0] == '\0')//pode usar '\0' ou '\x0'
				strcpy(usu.local.cidade, usu_aux.local.cidade);
			if (usu.local.num[0] == '\0')//pode usar '\0' ou '\x0'
				strcpy(usu.local.num, usu_aux.local.num);
			if (usu.local.rua[0] == '\0')//pode usar '\0' ou '\x0'
				strcpy(usu.local.rua, usu_aux.local.rua);
			gotoxy(25,23); printf("Confirmar alteração? (S/N): ");
			do
			{
				conf = getche();
			}while( conf != 's' && conf != 'S' && conf != 'n' && conf != 'N' );
			if( conf == 's' || conf == 'S' )
			{
				fseek(fp,fposicao-(sizeof(usu)),SEEK_SET);//em stdio.h //SEEK_SET indica o início do arquivo
				fwrite(&usu,sizeof(usu),1,fp);
				fflush(fp);
				system("cls");
				atualizar();
			}
			else
			{
				int menu();
				menu();
			}
		}
	}while ((!F) && (!feof(fp)));
	if (F==0)
	{
		int op;
		gotoxy(14,12);printf("CPF não encontrado!");
		gotoxy(16,13);printf("Cadastrar CPF");
		gotoxy(16,15);printf("Voltar ao menu");
		gotoxy(16,14);printf("Digitar outro CPF");
		op = seta(13,15,14);
		switch (op)
		{
			case 13: cadastro();
				break;
			case 14: atualizar();
				break;
			case 15: int menu();
					 menu();
		}
	}
}
void exclu()
{
	system("cls");
	setlocale(LC_ALL,"C");
	for(int i=0; i<2; i++)
	{
	gotoxy(2,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(2,6); printf("%c%c",219,219);
	gotoxy(2,7); printf("%c%c",219,219);
	gotoxy(2,8); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(2,9); printf("%c%c",219,219);
	gotoxy(2,10);printf("%c%c",219,219);
	gotoxy(2,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(11,5); printf("%c%c     %c%c",219,219,219,219);
	gotoxy(11,6); printf(" %c%c   %c%c",219,219,219,219);
	gotoxy(11,7); printf("  %c%c %c%c",219,219,219,219);
	gotoxy(11,8); printf("   %c%c%c",219,219,219);
	gotoxy(11,9); printf("  %c%c %c%c",219,219,219,219);
	gotoxy(11,10);printf(" %c%c   %c%c",219,219,219,219);
	gotoxy(11,11);printf("%c%c     %c%c",219,219,219,219);
	
	gotoxy(22,5); printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(22,6); printf(" %c%c",219,219);
	gotoxy(22,7); printf("%c%c",219,219);
	gotoxy(22,8); printf("%c%c",219,219);
	gotoxy(22,9); printf("%c%c",219,219);
	gotoxy(22,10);printf(" %c%c",219,219);
	gotoxy(22,11);printf("  %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(32,5); printf("%c%c",219,219);
	gotoxy(32,6); printf("%c%c",219,219);
	gotoxy(32,7); printf("%c%c",219,219);
	gotoxy(32,8); printf("%c%c",219,219);
	gotoxy(32,9); printf("%c%c",219,219);
	gotoxy(32,10);printf("%c%c",219,219);
	gotoxy(32,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(41,5); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(41,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(41,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(41,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(41,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(41,10);printf("%c%c    %c%c",219,219,219,219);
	gotoxy(41,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(51,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(51,6); printf("%c%c",219,219);
	gotoxy(51,7); printf("%c%c",219,219);
	gotoxy(51,8); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(51,9); printf("     %c%c",219,219);
	gotoxy(51,10);printf("     %c%c",219,219);
	gotoxy(51,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	
	gotoxy(60,5); printf("  %c%c%c%c",219,219,219,219);
	gotoxy(60,6); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(60,7); printf("%c%c%c  %c%c%c",219,219,219,219,219,219);
	gotoxy(60,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(60,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(60,10);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(60,11);printf("%c%c    %c%c",219,219,219,219);
	
	gotoxy(70,5); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(70,6); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(70,7); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(70,8); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(70,9); printf("%c%c    %c%c",219,219,219,219);
	gotoxy(70,10);printf("%c%c    %c%c",219,219,219,219);
	gotoxy(70,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
	
	gotoxy(61,2);printf(" %c%c%c %c%c",219,219,219,219,219);
	gotoxy(61,3);printf("%c%c %c%c%c",219,219,219,219,219);
	
	Sleep(500);
	system("cls");
	Sleep(500);
	}
	setlocale(LC_ALL,"Portuguese");
}
void excluir ()
{
	system("cls");
	long fposicao;
	gotoxy(28,2);printf("EXCLUSÃO DE DADOS");
	char t;
	int x;
	char aux3 [14];
	abrir_arquivo("rb+");
	gotoxy(10,7);printf("Digite seu CPF <digite 0 para voltar>: ");
	textcolor(0);
	gets(aux3);
	textcolor(15);
	if (strcmp(aux3,"0") == 0)
	{
		system("cls");
		int menu();
		menu();
	}
	else
	{
		rewind(fp);
		do
		{
			x = 0;
			if(fread(&usu, sizeof(usu), 1, fp) == 1 && usu.excluido == 'n' && strcmp(aux3,usu.cpf) == 0)
			{
				x=1;
				fposicao=ftell(fp);
				system("cls");
				gotoxy(28,2);printf("EXCLUSÃO DE DADOS");
				mostra_dados();	
				gotoxy(25,22);printf("Confirmar exclusão? (S/N): ");
				do
				{
					t = getche();
					
				}while(t!='s' && t!='S' && t!='n' && t!='N');
				system("cls");
				if (t=='s' || t=='S')
				{
					fseek(fp, fposicao-(sizeof(usu)), SEEK_SET);
					usu.excluido='s';
					fwrite(&usu, sizeof(usu), 1, fp);
					fflush(fp);
					system("cls");
					int excluir();
					excluir();
				}
				else
				{
					int excluir();
					excluir();
				}
			}
		}while(!feof(fp) && (!x));
		if(x==0)
		{
			int op;
			gotoxy(14,12);printf("CPF não encontrado!");
			gotoxy(16,13);printf("Cadastrar CPF");
			gotoxy(16,15);printf("Voltar ao menu");
			gotoxy(16,14);printf("Digitar outro CPF");
			op = seta(13,15,14);
			switch (op)
			{
				case 13: cadastro();
					break;
				case 14: excluir();
					break;
				case 15: int menu();
						 menu();
			}
		}
	}while (strcmp(aux3,"0") != 0);
}
int menu()
{
	system("cls");
	int op;
	do
	{
		desenho2();
		textcolor(15);
		miniborda();
		setlocale(LC_ALL,"Portuguese");
		gotoxy(30,3);printf("SEJA BEM VINDO");
		gotoxy(15,6);printf("M E N U");
		gotoxy(10,8);printf(" Cadastro");
		gotoxy(10,9);printf(" Efetuar compra");
		gotoxy(10,10);printf(" Consulta de clientes");
		gotoxy(10,11);printf(" Sobre");
		gotoxy(10,12);printf(" Alteração de dados");
		gotoxy(10,13);printf(" Exclusão de dados");
		gotoxy(10,14);printf(" Finalizar");
		op=seta(8,14,8);
		setlocale(LC_ALL,"Portuguese");
			switch(op)
			{
				case 8: cadastro();
					break;
				case 9: checar_cadastro();
					break;
				case 10: consulta();
				consulta_dados();
					break;
				case 11: sobre();
					break;
				case 12: altera();
					atualizar();
					break;
				case 13: exclu();
				excluir ();
					break;
			}
	}while(op != 14);
	if (op == 14)
	{
		system("cls");	
		
		setlocale(LC_ALL,"Portuguese");
		gotoxy(36,5);printf("O B R I G A D O   P O R");	
		gotoxy(36,7);printf("U T I L I Z A R   N O S S O   S I S T E M A !");
		
		setlocale(LC_ALL,"C");
		
		gotoxy(28,2); printf("%c%c%c%c",219,219,219,219);
		
		gotoxy(32,3); printf("%c%c",219,219);
		gotoxy(32,4); printf("%c%c",219,219);
		gotoxy(32,5); printf("%c%c",219,219);
		gotoxy(32,6); printf("%c%c",219,219);
		gotoxy(32,7); printf("%c%c",219,219);
		gotoxy(32,8); printf("%c%c",219,219);
		gotoxy(32,9); printf("%c%c",219,219);
		gotoxy(32,10); printf("%c%c",219,219);
		
		gotoxy(34,11); printf("%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219);
		gotoxy(34,12); printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
		
		gotoxy(44,13); printf("%c%c",219,219);
		gotoxy(44,14); printf("%c%c",219,219);
		
		gotoxy(44,15); printf("%c%c",219,219);
		gotoxy(44,16); printf("%c%c",219,219);
		
		gotoxy(44,17); printf("%c%c",219,219);
		gotoxy(44,18); printf("%c%c",219,219);
		
		gotoxy(44,19); printf("%c%c",219,219);
		gotoxy(44,20); printf("%c%c",219,219);
		
		gotoxy(42,21); printf("%c%c",219,219);
		gotoxy(42,22); printf("%c%c",219,219);
		
		gotoxy(26,3); printf("%c%c",219,219);
		gotoxy(26,4); printf("%c%c",219,219);
		gotoxy(26,5); printf("%c%c",219,219);
		gotoxy(26,6); printf("%c%c",219,219);
		
		gotoxy(24,7); printf("%c%c",219,219);
		gotoxy(24,8); printf("%c%c",219,219);
		
		gotoxy(22,9); printf("%c%c",219,219);
		gotoxy(22,10); printf("%c%c",219,219);
		
		gotoxy(22,11); printf("%c%c",219,219);
		gotoxy(4,11);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		gotoxy(4,12);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		
		gotoxy(4,13); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		gotoxy(4,14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		
		gotoxy(4,15);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		gotoxy(4,16);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		
		gotoxy(4,17); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		gotoxy(4,18); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		
		gotoxy(4,19); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		gotoxy(4,20); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		
		gotoxy(4,21); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		gotoxy(4,22); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,219,219);
		
		gotoxy(18,21); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
		gotoxy(18,22); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
		
		gotoxy(26,23); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		gotoxy(30,24); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
		
		gotoxy(4,23); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		gotoxy(4,24); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);			
			
		sleep(3);
		
		system("cls");
		
		gotoxy(2,5); printf("%c%c     %c%c",219,219,219,219);
		gotoxy(2,6); printf("%c%c     %c%c",219,219,219,219);
		gotoxy(2,7); printf(" %c%c   %c%c",219,219,219,219);
		gotoxy(2,8); printf(" %c%c   %c%c",219,219,219,219);
		gotoxy(2,9); printf("  %c%c %c%c",219,219,219,219);
		gotoxy(2,10);printf("  %c%c%c%c%c",219,219,219,219,219);
		gotoxy(2,11);printf("   %c%c%c%",219,219,219,219,219,219);

		gotoxy(12,5); printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
		gotoxy(12,6); printf("%c%c    %c%c",219,219,219,219);
		gotoxy(12,7); printf("%c%c    %c%c",219,219,219,219);
		gotoxy(12,8); printf("%c%c    %c%c",219,219,219,219);
		gotoxy(12,9); printf("%c%c    %c%c",219,219,219,219);
		gotoxy(12,10);printf("%c%c    %c%c",219,219,219,219);
		gotoxy(12,11);printf(" %c%c%c%c%c%c",219,219,219,219,219,219);
		
		gotoxy(23,5); printf("%c%c",219,219);
		gotoxy(23,6); printf("%c%c",219,219);
		gotoxy(23,7); printf("%c%c",219,219);
		gotoxy(23,8); printf("%c%c",219,219);
		gotoxy(23,9); printf("%c%c",219,219);
		gotoxy(23,10);printf("%c%c",219,219);
		gotoxy(23,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		
		gotoxy(31,5); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
		gotoxy(31,6); printf("   %c%c",219,219);
		gotoxy(31,7); printf("   %c%c",219,219);
		gotoxy(31,8); printf("   %c%c",219,219);
		gotoxy(31,9); printf("   %c%c",219,219);
		gotoxy(31,10);printf("   %c%c",219,219);
		gotoxy(31,11);printf("   %c%c",219,219);
		
		gotoxy(40,5); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		gotoxy(40,6); printf("%c%c",219,219);
		gotoxy(40,7); printf("%c%c",219,219);
		gotoxy(40,8); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
		gotoxy(40,9); printf("%c%c",219,219);
		gotoxy(40,10);printf("%c%c",219,219);
		gotoxy(40,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		
		gotoxy(2,14); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		gotoxy(2,15); printf("%c%c",219,219);
		gotoxy(2,16); printf("%c%c",219,219);
		gotoxy(2,17); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		gotoxy(2,18); printf("     %c%c",219,219);
		gotoxy(2,19); printf("     %c%c",219,219);
		gotoxy(2,20); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		
		gotoxy(12,14); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		gotoxy(12,15); printf("%c%c",219,219);
		gotoxy(12,16); printf("%c%c",219,219);
		gotoxy(12,17); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
		gotoxy(12,18); printf("%c%c",219,219);
		gotoxy(12,19); printf("%c%c",219,219);
		gotoxy(12,20); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);	
		
		gotoxy(23,14); printf("%c%c     %c%c",219,219,219,219);
		gotoxy(23,15); printf("%c%c%c   %c%c%c",219,219,219,219,219,219);
		gotoxy(23,16); printf("%c%c%c%c %c%c%c%c",219,219,219,219,219,219,219,219);
		gotoxy(23,17); printf("%c%c %c%c%c %c%c",219,219,219,219,219,219,219);
		gotoxy(23,18); printf("%c%c  %c  %c%c",219,219,219,219,219);
		gotoxy(23,19);printf("%c%c     %c%c",219,219,219,219);
		gotoxy(23,20);printf("%c%c     %c%c",219,219,219,219);
		
		gotoxy(34,14); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
		gotoxy(34,15); printf("%c%c   %c%c",219,219,219,219);
		gotoxy(34,16); printf("%c%c   %c%c",219,219,219,219);
		gotoxy(34,17); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
		gotoxy(34,18); printf("%c%c",219,219);
		gotoxy(34,19); printf("%c%c",219,219);
		gotoxy(34,20); printf("%c%c",219,219);

		gotoxy(43,14); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		gotoxy(43,15); printf("%c%c    %c%c",219,219,219,219);
		gotoxy(43,16); printf("%c%c    %c%c",219,219,219,219);
		gotoxy(43,17); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		gotoxy(43,18); printf("%c%c  %c%c",219,219,219,219);
		gotoxy(43,19); printf("%c%c   %c%c",219,219,219,219);
		gotoxy(43,20); printf("%c%c    %c%c",219,219,219,219);
		
		gotoxy(54,14); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		gotoxy(54,15); printf("%c%c",219,219);
		gotoxy(54,16); printf("%c%c",219,219);
		gotoxy(54,17); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
		gotoxy(54,18); printf("%c%c",219,219);
		gotoxy(54,19); printf("%c%c",219,219);
		gotoxy(54,20); printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
		
		gotoxy(64,14); printf("%c%c",219,219);
		gotoxy(64,15); printf("%c%c",219,219);
		gotoxy(64,16); printf("%c%c",219,219);
		gotoxy(64,17); printf("%c%c",219,219);
		gotoxy(64,18); printf("%c%c",219,219);
		gotoxy(64,20); printf("%c%c",219,219);
		sleep(3);
		system("cls");
		setlocale(LC_ALL,"Portuguese");
		exit(1);
	}
}
main()
{
	abrir_arquivo("ab+");
	system("color 3F");	
	carregando();
	titulo();
	desenho();
	desenho2();
	menu();
	fclose(fp);
}
