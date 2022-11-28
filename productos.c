#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include "productos.h"

void registrar(int cont_inventario,int cont, venta *v, producto *listap){
    int id, mes, anio, dia, busqueda, cantidad_producto;
    id:printf("Ingrese el codigo de la venta: ");
    scanf("%i", &id);
    if(id>0 && !existe(cont, v, id)){
        v[cont].id = id;
        printf("Ingrese la fecha: ");
        dia:printf("\nDia:");
        scanf("%i", &dia);
        if(dia>0 && dia<=31){
            v[cont].fechaRegistro.dd=dia;
            mes:printf("Mes:");
            scanf("%i", &mes);
            if(mes>0 && mes<=12){
                v[cont].fechaRegistro.mm=mes;
                anio:printf("Anio:");
                scanf("%i", &anio);
                fflush(stdin);
                if(anio>0){
                    v[cont].fechaRegistro.aa=anio;
                    printf("Ingrese el nombre del comprador: ");
                    gets(v[cont].nombreC);
                    productosLista(cont_inventario,listap);
                    otro:printf("----Seleccione el id de su producto----\n");
                    scanf("%i", &busqueda);
                    int index_producto=buscar_producto(busqueda,index_producto,cont_inventario,listap);
                    if(index_producto!=-1){
                         printf("----El producto seleccionado es: ----\n");
                        printf("Nombre: %s\n", listap[index_producto].nombre);
                        printf("Precio: %0.2f\n", listap[index_producto].precio);
                        printf("\n");
                        cant:printf("----Cuanto desea de este producto: ----\n");
                        scanf("%i", &cantidad_producto);
                        if(cantidad_producto<listap[index_producto].cantidad){
                            printf("Registro exitoso\n");
                            listap=venta_producto(cantidad_producto,listap,v,index_producto, cont);
                            system("pause");
                            system("cls");
                        } else{
                            printf("No existe esa cantidad dentro del inventario, ingrese nuevamente\n");
                            goto cant;
                        }
                    }else {
                        printf("El codigo del producto no existe\n");
                        goto otro;
                    }
                } else{
                    printf("Ingrese nuevamente un valor para anio");
                    goto anio;
                }
            } else{
                printf("Ingrese nuevamente un valor para mes");
                goto mes;
            }
        } else{
            printf("Ingrese nuevamente un valor para dia");
            goto dia;
        }
    } else{
        printf("Dato invalido, ingrese nuevamente un valor\n");
        goto id;
    }
}

int existe(int cont, venta *v, int id) {
    int repetido=0;
      if(cont!=0){
      for(int j=0;j<cont;j++){
        if(v[j].id==id){
            repetido=1;
        }
      }
      return repetido;
    }
}

int venta_producto(int cantidad, producto *listap, venta *venta,int index, int cont_usos){
    listap[index].cantidad=listap[index].cantidad-cantidad;
    int total = cantidad*listap[index].precio;
    strcpy(venta[cont_usos].nombreP,listap[index].nombre);
    venta[cont_usos].cantidadP = cantidad;
    venta[cont_usos].total = total;
    return listap;
}

int buscar_producto(int busca,int index, int cont, producto *listap){
    int x=0;
    for(x=0;x<cont;x++){
        if(listap[x].id==busca){
            return index=x;
        }
    }
    return -1;
}

void imprimirVentas(int cont, venta *v){
    printf("----LISTADO VENTAS----\n");
    for(int i=0; i<cont; i++){
        printf("Codigo: %i\n", v[i].id);
        printf("Fecha: %i/%i/%i\n", v[i].fechaRegistro.dd, v[i].fechaRegistro.mm, v[i].fechaRegistro.aa);
        printf("Comprador: %s\n", v[i].nombreC);
        printf("Producto: %s\n", v[i].nombreP);
        printf("La cantidad que compro fue: %i\n", v[i].cantidadP);
        printf("El precio total es de %i\n", v[i].total);
        printf("\n");
    }
}

void salir(){
    printf("------FIN PROGRAMA------\n");
    exit(0);
}

int inventario(producto *listap, int cont){
    int opcion, tam=100;

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
                system("pause");
                system("cls");
                break;
            case 3:
                system("pause");
                system("cls");
                return;
                break;
            default:
                printf("Opcion incorrecta ingrese una opcion valida\n");
        }
    } while(opcion!=3);
}

void registrarProducto(int cont, producto *nuevo){
    int id, cantidad;
    float precio;
    printf("Ingrese los datos del producto\n");
    cod:printf("Codigo: ");
    scanf("%i", &id);
    fflush(stdin);
    if(id>0 && !existeProducto(cont, nuevo, id)){
        nuevo[cont].id=id;
        printf("Nombre: ");
        gets(nuevo[cont].nombre);
        pre:printf("Precio:");
        scanf("%f", &precio);
        if(precio>0){
            nuevo[cont].precio=precio;
            cant:printf("Cantidad: ");
            scanf("%i", &cantidad);
            if(cantidad>0){
                nuevo[cont].cantidad=cantidad;
                printf("-----Registro exitoso-----\n");
                cont++;
            } else {
                printf("Datos invalidos\n");
                goto cant;
            }
        }else {
            printf("Datos invalidos\n");
            goto pre;
        }
    } else {
        printf("Debe ingresar un valor positivo y diferente de cero o el valor ya existe\n");
        goto cod;
    }
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

int existeProducto(int cont, producto *p, int id) {
    int repetido=0;
      if(cont!=0){
      for(int j=0;j<cont;j++){
        if(p[j].id==id){
            repetido=1;
        }
      }
      return repetido;
    }
}
