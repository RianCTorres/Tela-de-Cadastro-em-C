#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

// definição estruturas de dados
typedef struct
{
    char nome[20];
    int idade;
    float salario;
    char sexo;
} reg_dados;

// definir posição do cursor
void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// construção da tela
void tela()
{
    for (int i = 0; i < 80; i++)
    {
        gotoxy(i, 0);
        printf("=");
        gotoxy(i, 2);
        printf("=");
        gotoxy(i, 22);
        printf("=");
        gotoxy(i, 24);
        printf("=");
    }

    for (int i = 0; i < 25; i++)
    {
        gotoxy(0, i);
        printf("|");
        gotoxy(80, i);
        printf("|");
    }
}

int main() {
    reg_dados cadastro[6];
    int i = 0;
    int continuarCadastro = 0;


    while (1) {

        if (i == 6){
            break;
        }

        system("cls");
        system("color 0A");
        tela();

        //cabeçalho para recebimento dos dados cadastrais
        gotoxy(1, 1);
        printf("Exercicio utilizando Struct e TypeDef                prof: Rodis");
        gotoxy(1, 23);
        printf("SAIDA:");
        gotoxy(7, 23);
        printf("                       ");
        gotoxy(50,23);
        printf("cadastro: %d", i+1);

        gotoxy(1, 4);
        printf("Nome.......:");
        gotoxy(1, 6);
        printf("Idade......:");
        gotoxy(1, 8);
        printf("Salario....:");
        gotoxy(1, 10);
        printf("Sexo.......:");

        gotoxy(13, 4);
        scanf("%s", cadastro[i].nome);


        //condição limite para idade
        while (1) {
            gotoxy(13, 6);
            scanf("%d", &cadastro[i].idade);

            if (cadastro[i].idade < 18 || cadastro[i].idade > 100) {
                gotoxy(7, 23);
                printf("idade invalida");
                gotoxy(13, 6);
                printf("                       ");
                getch();
                gotoxy(7, 23);
                printf("                       ");
            } else {
                break;
            }
        }

        //condição minima para salario
        while (1) {
        gotoxy(13, 8);
        scanf("%f", &cadastro[i].salario);


            if (cadastro[i].salario < 0 ) {
                gotoxy(7, 23);
                printf("salario nao permitido!");
                gotoxy(13, 8);
                printf("                      ");
                getch();
                gotoxy(7, 23);
                printf("                       ");
            } else {
                break;
            }
        }

        //condição para sexo
        while (1) {
        gotoxy(13, 10);
        scanf(" %c", &cadastro[i].sexo);


            if (cadastro[i].sexo == 'f' || cadastro[i].sexo == 'F' || cadastro[i].sexo == 'm' || cadastro[i].sexo == 'M') {
                break;
            } else {
                gotoxy(7, 23);
                printf("sexo invalido!");
                gotoxy(13, 10);
                printf("                   ");
                getch();
                gotoxy(7, 23);
                printf("                       ");
            }
        }

        //continuação de cadastro
        while (1){
            gotoxy(7, 23);
            printf("Continuar cadastro: sim[1]/nao[2]:");
            scanf("%d",&continuarCadastro);

            if (continuarCadastro == 1 || continuarCadastro ==2) {
                break;
            } else {
                gotoxy(7, 23);
                printf("                        ");
                gotoxy(7, 23);
                printf("digite uma opcao valida!");

            }
        }
        if (continuarCadastro == 2) {
            break;
        }
    
        i++;
    }

    system("cls");

    tela();

    //tela de dados cadastrados
    gotoxy(3, 5);
    printf("%-20s%-10s%-15s%-5s", "Nome", "Idade", "Salario", "Sexo");

    for (int j = 0; j <= i; j++) {
        gotoxy(3, j + 7);
        printf("%-20s%-10d%-15.2f%-5c", cadastro[j].nome, cadastro[j].idade, cadastro[j].salario, cadastro[j].sexo);
    }
    getch();
    return 0;
}