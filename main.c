#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include "productos.h"

int main(){
    int opcion, cont=0, tam=100;
    int *lista;
    lista=malloc(tam*sizeof(venta));
    do {
        printf("------Menu Principal------\n");
        printf("1. Registrar venta\n");
        printf("2. Inventario\n");
        printf("3. Listar ventas\n");
        printf("4. Salir\n");
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
                printf("------FIN PROGRAMA------\n");
                exit(0);
                break;
            default:
                printf("Opcion incorrecta ingrese una opcion valida\n");
        }
    } while(opcion!=4);

    free(lista);
    getch();
    return 0;
}
