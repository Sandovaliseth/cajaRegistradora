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

void registrar(int cont, venta *v);
void imprimirVentas(int cont,venta *v);
inventario();
void registrarProducto(int cont, producto *p);
void productosLista(int cont, producto *p);
void grabar(int cont, venta *v);
