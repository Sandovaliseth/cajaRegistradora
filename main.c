#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "productos.h"

int main(){
    int opcion, cont=0, tam=100, cont_inventario=3;
    venta *lista;
    lista=malloc(tam*sizeof(venta));
    producto *listap;
    listap= (producto *)calloc(tam,sizeof(producto));

    listap[0].id = 1;
    strcpy(listap[0].nombre, "Carne");
    listap[0].precio = 9000;
    listap[0].cantidad = 50;

    listap[1].id = 2;
    strcpy(listap[1].nombre, "Leche");
    listap[1].precio = 5000;
    listap[1].cantidad = 15;

    listap[2].id = 3;
    strcpy(listap[2].nombre, "Arroz");
    listap[2].precio = 6000;
    listap[2].cantidad = 100;

    do {
        printf("\n\n\t\t\t********* Menu Principal *********\n\n");
        printf("\t\t\t\t1. Registrar venta\n");
        printf("\t\t\t\t2. Inventario\n");
        printf("\t\t\t\t3. Listar ventas\n");
        printf("\t\t\t\t4. Salir\n\n");
        printf("\t\t\t**********************************\n");
        printf("\nPor favor ingrese una opcion: ");
        scanf("%i", &opcion);
        switch(opcion){
            case 1:
                system("cls");
                registrar(cont_inventario,cont, lista,listap);
                cont++;
                break;
            case 2:
                system("cls");
                inventario(listap, cont_inventario);
                cont_inventario++;
                break;
            case 3:
                system("cls");
                if(cont!=0)
                    imprimirVentas(cont, lista);
                else
                    printf("No se encuentra ningun elemento para mostrar \n");
                break;
            case 4:
                salir();
                break;
            default:
                printf("Opcion incorrecta ingrese una opcion valida\n");
        }
    } while(opcion!=4);

    free(lista);
    free(listap);
    getch();
    return 0;
}
