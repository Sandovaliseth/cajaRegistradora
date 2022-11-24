#include<conio.h>
#include<stdio.h>
#include "productos.h"

#define Tam 2

int main(){
    int opcion;
    venta v[Tam];
    /*producto p[0]={1, "carne", 9000, 10};
    producto p[1]={2, "leche", 5000, 15};
    producto p[2]={3, "arroz", 6000, 100}; */
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
                for(int f=0; f<Tam; f++){
                    v[f]= registrar();}
                break;
            case 3:
                imprimirVentas(v[Tam]);
                break;
            case 4:
                printf("------FIN PROGRAMA------\n");
                break;
        }
    } while(opcion!=4);

    getch();
    return 0;
}
