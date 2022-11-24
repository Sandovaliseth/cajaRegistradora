#include<conio.h>
#include<stdio.h>
#include "productos.h"

int mainInventario(){
    int opcion;
    int cont=0;
    do {
        printf("------INVENTARIO------\n");
        printf("1. Crear producto\n");
        printf("2. Listar productos\n");
        printf("4. Regresar\n");
        printf("Escoge una opcion: ");
        scanf("%i", &opcion);
        switch(opcion){
            case 1:
                system("cls");
                cont++;
                break;
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                break;
            case 4:

                break;
            default:
                printf("Opcion incorrecta ingrese una opcion valida\n");
        }
    } while(opcion!=4);

    getch();
    return 0;
}
