void mostrar_inventario(int id[10], char *nombres[10], int cantidad[10], float precios[10]);
void ingresar_producto(int id[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10]);
int ingresar_producto_id(int id[10]);
char* ingresar_producto_nombre(char *nombres[10], char nuevo_nombre[50]);
int ingresar_producto_cantidad(int cantidad[10]);
float ingresar_producto_precio(float precios[10]);
int modificar_cantidad(int id[10], int cantidad[10]);
int eliminar_producto(int id[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10]);
