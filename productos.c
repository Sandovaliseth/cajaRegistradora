#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include "productos.h"

void registrar(int cont, venta *v){
    printf("Ingrese el codigo de la venta: ");
    scanf("%i", &v[cont].id);
    if(v[cont].id>0){
        printf("Ingrese la fecha: ");
        printf("\nDia:");
        scanf("%i", &v[cont].fechaRegistro.dd);
        if(v[cont].fechaRegistro.dd>0 && v[cont].fechaRegistro.dd<31){
            printf("Mes:");
            scanf("%i", &v[cont].fechaRegistro.mm);
            if(v[cont].fechaRegistro.mm>0 && v[cont].fechaRegistro.mm<12){
                printf("Anio:");
                scanf("%i", &v[cont].fechaRegistro.aa);
                fflush(stdin);
                if(v[cont].fechaRegistro.aa>0){
                    printf("Ingrese el nombre del comprador: ");
                    gets(v[cont].nombreC);
                    printf("-------- Registro exitoso --------\n");
                    cont++;
                }else
                    printf("Datos invalidos\n");
            }else
                printf("Datos invalidos\n");
        } else
            printf("Datos invalidos\n");
    }else{
        printf("Debe ingresar un valor positivo o diferente de cero y es un valor existente\n");
    }
}

void imprimirVentas(int cont, venta *v){
    printf("----LISTADO VENTAS----\n");
    for(int i=0; i<cont; i++){
        printf("Codigo: %i\n", v[i].id);
        printf("Fecha: %i/%i/%i\n", v[i].fechaRegistro.dd, v[i].fechaRegistro.mm, v[i].fechaRegistro.aa);
        printf("Comprador: %s\n", v[i].nombreC);
        printf("\n");
    }
}

void salir(){
    printf("------FIN PROGRAMA------\n");
    exit(0);
}

int inventario(){
    int opcion, cont=3, sigue=1;
    producto *listap;
    int tam=100;
    listap=malloc(tam*sizeof(producto));

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
        printf("------INVENTARIO------\n");
        printf("1. Crear producto\n");
        printf("2. Listar productos\n");
        printf("3. Regresar\n");
        printf("Escoge una opcion: ");
        scanf("%i", &opcion);
        switch(opcion){
            case 1:
                system("cls");
                registrarProducto(cont, listap);
                cont++;
                break;
            case 2:
                system("cls");
                productosLista(cont, listap);
                break;
            case 3:
                system("pause");
                system("cls");
                return 0;
                break;
            default:
                printf("Opcion incorrecta ingrese una opcion valida\n");
        }
    } while(opcion!=3);
    free(listap);
    getch();
    return listap;
}

void registrarProducto(int cont, producto *nuevo){
    printf("Ingrese los datos del producto\n");
    printf("Codigo: ");
    scanf("%i", &nuevo[cont].id);
    fflush(stdin);
    if(nuevo[cont].id>0){
        printf("Nombre: ");
        gets(nuevo[cont].nombre);
        printf("Precio:");
        scanf("%f", &nuevo[cont].precio);
        if(nuevo[cont].precio>0){
            printf("Cantidad: ");
            scanf("%i", &nuevo[cont].cantidad);
            if(nuevo[cont].cantidad>0){
                printf("-----Registro exitoso-----\n");
                cont++;
            } else
                printf("Datos invalidos\n");
        }else
            printf("Datos invalidos\n");
    } else
        printf("Debe ingresar un valor positivo y diferente de cero\n");

}

void productosLista(int cont, producto *p){
    printf("----Inventario Productos----\n");
    for(int i=0;i<cont;i++){
        printf("Codigo: %i\n", p[i].id);
        printf("Nombre: %s\n", p[i].nombre);
        printf("Precio: %0.2f\n", p[i].precio);
        printf("Cantidad: %i\n", p[i].cantidad);
        printf("\n");
    }
}

