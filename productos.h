typedef struct {
    int id;
    char nombre[41];
    float precio;
    int cantidad;
} producto;

typedef struct {
    int dd;
    int mm;
    int aa;
} fecha;

typedef struct {
    int id;
    fecha fechaRegistro;
    char nombreC[41];
    producto productos;
    char nombreP[41];
    int cantidadP;
    int total;
} venta;

void registrar(int cont_inventario,int cont, venta *v, producto *p);
void imprimirVentas(int cont,venta *v);
int inventario(producto *p, int cont_inventario);
void registrarProducto(int cont, producto *p);
void productosLista(int cont, producto *p);
int buscar_producto(int busqueda,int index_producto,int cont, producto *listap);
int venta_producto(int cantidad_producto, producto *listap, venta *v, int index_producto, int cont_usos);

