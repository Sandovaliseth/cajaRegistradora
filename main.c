#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "productos.h"

void gotoxy(int x, int y){
    HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon, dwPos);
}

int main(){
    int opcion, cont=0, tam=100;
    int *lista;
    lista=malloc(tam*sizeof(venta));
    do {
        printf("******** Menu Principal ********\n");
        gotoxy(7,1);printf("1. Registrar venta\n");
        gotoxy(7,2);printf("2. Inventario\n");
        gotoxy(7,3);printf("3. Listar ventas\n");
        gotoxy(7,4);printf("4. Salir\n");
        printf("********************************\n");
        printf("Por favor ingrese una opcion: ");
        scanf("%i", &opcion);
        switch(opcion){
            case 1:
                system("cls");
                registrar(cont, lista);
                cont++;
                break;
            case 2:
                system("cls");
                inventario();
                break;
            case 3:
                system("cls");
                if(cont!=0){
                    imprimirVentas(cont, lista);
                }
                else{
                    printf("No se encuentra ningun elemento para mostrar \n");
                }
                break;
            case 4:
                salir();
                break;
            default:
                printf("Opcion incorrecta ingrese una opcion valida\n");
        }
    } while(opcion!=4);

    free(lista);
    getch();
    return 0;
}
