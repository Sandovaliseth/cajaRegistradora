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
} venta;

void registrar(venta *v);
void imprimirVentas(int cont,venta *v);
inventario();
void registrarProducto(producto *p);
void productosLista(producto *p);
