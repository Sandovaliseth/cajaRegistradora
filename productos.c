#include<conio.h>
#include<stdio.h>
#include "productos.h"
int tam=0;//contador de ventas
int tam_2=3;//contador de productos

void registrar(venta *v){

        printf("Ingrese el codigo de la venta: ");
        scanf("%i", &v[tam].id);
        fflush(stdin);
        printf("Ingrese la fecha: ");
        printf("\nDia:");
        scanf("%i", &v[tam].fechaRegistro.dd);
        printf("Mes:");
        scanf("%i", &v[tam].fechaRegistro.mm);
        printf("Anio:");
        scanf("%i", &v[tam].fechaRegistro.aa);
        fflush(stdin);
        printf("Ingrese el nombre del comprador: ");
        gets(v[tam].nombreC);
        printf("-----Registro exitoso-----\n");
    tam++;
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

int inventario(){
    int opcion;
    producto *listap;
    int tamano;
    listap=malloc(tamano*sizeof(producto));

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
                registrarProducto(listap);
                break;
            case 2:
                system("cls");
                productosLista(listap);

                break;
            case 3:
                system("pause");
                system("cls");
                return main();
                break;
            default:
                printf("Opcion incorrecta ingrese una opcion valida\n");
        }
    } while(opcion!=3);
    getch();
    return 0;
}

void registrarProducto(producto *nuevo){
    printf("Ingrese los datos del producto\n");
    printf("Codigo: ");
    scanf("%i", & nuevo[tam_2].id);
    fflush(stdin);
    printf("Nombre: ");
    gets( nuevo[tam_2].nombre);
    printf("Precio:");
    scanf("%f", & nuevo[tam_2].precio);
    fflush(stdin);
    printf("Cantidad: ");
    scanf("%i", & nuevo[tam_2].cantidad);
    printf("-----Registro exitoso-----\n");
    tam_2++;
}

void productosLista(producto *p){
    for(int i=0;i<4;i++)
    {
        printf("----Inventario Productos----\n");
        printf("Codigo: %i\n", p[i].id);
        printf("Nombre: %s\n", p[i].nombre);
        printf("Precio: %0.2f\n", p[i].precio);
        printf("Cantidad: %i\n", p[i].cantidad);
        printf("\n");
    }
}

