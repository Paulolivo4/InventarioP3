#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_inventario.h"



//Función para imprimir los productos del inventario
void mostrar_inventario(int id[10], char *nombres[10], int cantidad[10], float precios[10])
{
    printf("\n----------------------------- PAPELERIA -----------------------------\n");
    printf(" CODIGO         NOMBRE                   CANTIDAD         PRECIO   \n");
    printf("---------------------------------------------------------------------\n");

    //Obtener la longitud máxima de los nombres para que se imprima correctamente
    int ancho_nombre = 0;
    for (int i = 0; i < 10; i++)
    {
        int longitud = strlen(nombres[i]);
        if (longitud > ancho_nombre)
        {
            ancho_nombre = longitud;
        }
    }

    //Impresión de todos los productos del inventario de forma que se vea todo alineado
    for (int i = 0; i < 10; i++)
    {
        //Impresión en caso de que el id y la cantidad sean números menores a 10
        if (id[i] < 10 && cantidad[i] < 10)
        {
            printf("   0%d           %-*s                0%d             $%.2f\n", id[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
        //Impresión en caso de que el id sean números menores a 10
        else if (id[i] < 10)
        {
            printf("   0%d           %-*s                %d             $%.2f\n", id[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
        //Impresión en caso de que la cantidad sean números menores a 10
        else if (cantidad[i] < 10)
        {
            printf("   %d           %-*s                0%d             $%.2f\n", id[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
        //Impresión si el id y la cantidad son mayores a 10
        else
        {
            printf("   %d           %-*s                %d             $%.2f\n", id[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
    }
    printf("---------------------------------------------------------------------\n");
}

//Función para ingresar nuevos productos (dividido en otras funciones)
void ingresar_producto(int id[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10])
{
    //Variable contador para saber si el inventario se encuentra lleno
    int contador = 0;
    for (int i = 0; i < 10; i++)
    {
        if (id[i] != 0)
        {
            contador += 1;
        }    
    }

    //En caso de que el inventario no esté lleno, se pueden agregar más productos
    if (contador < 10)
    {
        ingresar_producto_id(id);
        ingresar_producto_nombre(nombres, nuevo_nombre);
        ingresar_producto_cantidad(cantidad);
        ingresar_producto_precio(precios);
        printf("\n");
    }
    //Si el inventario está lleno, no se pueden agregar más productos
    else
    {
        printf("El inventario esta lleno.\n\n");
    }
}

//Función para ingresar ID del nuevo producto
int ingresar_producto_id(int id[10])
{
    int id_nuevo;

    do
    {
        printf("\nInserta el ID del producto: ");
        scanf("%d", &id_nuevo);

        for (int i = 0; i < 10; i++)
        {
            //Si el ID es menor o igual a cero, o es igual al ID de otro producto, su valor será 0
            if (id_nuevo == id[i] || id_nuevo <= 0)
            {
                id_nuevo = 0;
            }
            else
            {
                if (id[i] == 0)
                {
                    return id[i] = id_nuevo;
                }
            }
        }

        //Si el valor del ID es 0, se tendrá que insertar uno diferente
        if (id_nuevo == 0)
        {
            printf("Ese id ya corresponde a otro producto o es 0. Inserta uno nuevo.\n");
        }
    } while (id_nuevo == 0);
}

//Minu función para ingresar nombre del nuevo producto
char* ingresar_producto_nombre(char *nombres[10], char nuevo_nombre[50])
{
    do 
    {   
        printf("Inserta el nombre del producto: ");
        scanf("%s", nuevo_nombre);

        for (int i = 0; i < 10; i++)
        {
            //Primero se valida si el nombre que se ingresa es igual al de otro producto
            if (strcmp(nuevo_nombre, nombres[i]) == 0)
            {
                strcpy(nuevo_nombre, "------");
                break;
            }
            //En caso de que no lo sea, se retorna el nuevo nombre
            else if (strcmp(nombres[i], "------") == 0)
            {
                /*Se usa la función strdup para duplicar una cadena en memoria dinámica con eso se
                evita el uso de malloc()*/ 
                return nombres[i] = strdup(nuevo_nombre);
            }
        }

        //En caso de que el producto sea igual al de otro, se tiene que ingresar uno nuevo
        if (strcmp(nuevo_nombre, "------") == 0)
        {
            printf("Ese nombre ya corresponde a otro producto. Inserta uno nuevo.\n\n");
        }
    } while (strcmp(nuevo_nombre, "------") == 0);
}


//Minu función para ingresar la cantidad del nuevo producto
int ingresar_producto_cantidad(int cantidad[10])
{
    int cantidad_nueva;

    do
    {
        printf("Inserta la cantidad del producto: ");
        scanf("%d", &cantidad_nueva);

        //Se valida que la cantidad sea mayor a 0
        if (cantidad_nueva <= 0)
        {
            printf("La cantidad debe ser mayor a 0. Inserta otra vez.\n\n");
            continue;
        }

        for (int i = 0; i < 10; i++)
        {
            if (cantidad[i] == 0)
            {
                return cantidad[i] = cantidad_nueva;
            }
        }
    } while (cantidad_nueva == 0);
}


//Minu función para ingresar el precio del nuevo producto
float ingresar_producto_precio(float precios[10])
{
    float precio_nuevo;

    do
    {
        printf("Inserta el precio del producto: ");
        scanf("%f", &precio_nuevo);

        //Se valida que el precio del producto sea mayor a $0.00
        if (precio_nuevo <= 0)
        {
            printf("El precio debe ser mayor a 0. Inserta otra vez.\n\n");
            continue;
        }

        for (int i = 0; i < 10; i++)
        {
            if (precios[i] == 0.0)
            {
                precios[i] = precio_nuevo;
                return precios[i];
            }
        }
    } while (precio_nuevo == 0.0);
}


//Función para modificar la cantidad de un producto
int modificar_cantidad(int id[10], int cantidad[10])
{
    int id_producto;
    int posicion;
    int nueva_cantidad;

    
    printf("\nInserta el ID del producto para modificar su cantidad: ");
    scanf("%d", &id_producto);

    //Primero se valida que el ID del producto a modificar sea válido
    if (id_producto == 0)
    {
        printf("El ID 0 no es valido.\n\n");
        return 1;
    }

    //Luego que el ID sea de un producto que esté en el inventario
    for (int i = 0; i < 10; i++)
    {
        if (id_producto == id[i])
        {
            posicion = i;
            break;
        }
        else if (i == 9)
        {
            //En caso de que el ID no sea de un producto del inventario, este valdrá 0
            id_producto = 0;
        }
    }

    //Si el ID es 0, no es el ID de un producto del inventario
    if (id_producto == 0)
    {
        printf("No es el ID de un producto.\n\n");
        return 1;
    }

    //Insertar cantidad modificada del producto
    do
    {
        printf("Inserta la nueva cantidad del producto: ");
        scanf("%d", &nueva_cantidad);        
        //La cantidad no puede ser igual a la anterior
        if (nueva_cantidad == cantidad[posicion])
        {
            printf("Esa es la cantidad actual del producto. Inserta una nueva.\n\n");
        }
        else
        {
            //La cantidad no puede ser menor o igual a 0
            if (nueva_cantidad <= 0)
            {
                printf("La cantidad no puede ser 0 o menor. Inserta una nueva\n\n");
            }
            else
            {
                printf("\n");
                return cantidad[posicion] = nueva_cantidad;
            }
        }
    } while (cantidad[posicion] == nueva_cantidad || nueva_cantidad <= 0);
}


//Función para eliminar un producto del inventario
int eliminar_producto(int id[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10])
{
    int id_producto;
    int posicion;

    
    printf("\nInserta el ID del producto para eliminarlo: ");
    scanf("%d", &id_producto);

    //Se valida que el ID del producto no sea 0
    if (id_producto == 0)
    {
        printf("El ID 0 no es valido.\n\n");
        return 1;
    }

    //Se valida que el ID del producto sea de uno que se encuentre en el inventario
    for (int i = 0; i < 10; i++)
    {
        if (id_producto == id[i])
        {
            posicion = i;
            break;
        }
        else if (i == 9)
        {
            id_producto = 0;
        }
    }

    //En caso de que el ID sea 0, signfica que no es el ID de un producto del inventario
    if (id_producto == 0)
    {
        printf("No es el ID de un producto.\n\n");
        return 1;
    }

    //Se restauran todos los valores de ese producto y se elimina
    id[posicion] = 0;
    nombres[posicion] = "------";
    cantidad[posicion] = 0;
    precios[posicion] = 0;
    printf("El producto ha sido eliminado\n\n");
    return 0;
}


