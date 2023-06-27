#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_inventario.h"




void mostrar_inventario(int id[10], char *nombres[10], int cantidad[10], float precios[10])
{
    printf("\n----------------------------- PAPELERIA -----------------------------\n");
    printf(" CODIGO         NOMBRE                   CANTIDAD         PRECIO   \n");
    printf("---------------------------------------------------------------------\n");

    
    int ancho_nombre = 0;
    for (int i = 0; i < 10; i++)
    {
        int longitud = strlen(nombres[i]);
        if (longitud > ancho_nombre)
        {
            ancho_nombre = longitud;
        }
    }

    
    for (int i = 0; i < 10; i++)
    {
        
        if (id[i] < 10 && cantidad[i] < 10)
        {
            printf("   0%d           %-*s                0%d             $%.2f\n", id[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
        
        else if (id[i] < 10)
        {
            printf("   0%d           %-*s                %d             $%.2f\n", id[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
        
        else if (cantidad[i] < 10)
        {
            printf("   %d           %-*s                0%d             $%.2f\n", id[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
        
        else
        {
            printf("   %d           %-*s                %d             $%.2f\n", id[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
    }
    printf("---------------------------------------------------------------------\n");
}


void ingresar_producto(int id[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10])
{
    
    int contador = 0;
    for (int i = 0; i < 10; i++)
    {
        if (id[i] != 0)
        {
            contador += 1;
        }    
    }

    
    if (contador < 10)
    {
        ingresar_producto_id(id);
        ingresar_producto_nombre(nombres, nuevo_nombre);
        ingresar_producto_cantidad(cantidad);
        ingresar_producto_precio(precios);
        printf("\n");
    }
    
    else
    {
        printf("El inventario esta lleno.\n\n");
    }
}


int ingresar_producto_id(int id[10])
{
    int id_nuevo;

    do
    {
        printf("\nInserta el ID del producto: ");
        scanf("%d", &id_nuevo);

        for (int i = 0; i < 10; i++)
        {
            
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

        
        if (id_nuevo == 0)
        {
            printf("Ese id ya corresponde a otro producto o es 0. Inserta uno nuevo.\n");
        }
    } while (id_nuevo == 0);
}


char* ingresar_producto_nombre(char *nombres[10], char nuevo_nombre[50])
{
    do 
    {   
        printf("Inserta el nombre del producto: ");
        scanf("%s", nuevo_nombre);

        for (int i = 0; i < 10; i++)
        {
            
            if (strcmp(nuevo_nombre, nombres[i]) == 0)
            {
                strcpy(nuevo_nombre, "------");
                break;
            }
            
            else if (strcmp(nombres[i], "------") == 0)
            {
                
                
                return nombres[i] = strdup(nuevo_nombre);
            }
        }

        
        if (strcmp(nuevo_nombre, "------") == 0)
        {
            printf("Ese nombre ya corresponde a otro producto. Inserta uno nuevo.\n\n");
        }
    } while (strcmp(nuevo_nombre, "------") == 0);
}



int ingresar_producto_cantidad(int cantidad[10])
{
    int cantidad_nueva;

    do
    {
        printf("Inserta la cantidad del producto: ");
        scanf("%d", &cantidad_nueva);

        
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



float ingresar_producto_precio(float precios[10])
{
    float precio_nuevo;

    do
    {
        printf("Inserta el precio del producto: ");
        scanf("%f", &precio_nuevo);

       
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



int modificar_cantidad(int id[10], int cantidad[10])
{
    int id_producto;
    int posicion;
    int nueva_cantidad;

    
    printf("\nInserta el ID del producto para modificar su cantidad: ");
    scanf("%d", &id_producto);

    
    if (id_producto == 0)
    {
        printf("El ID 0 no es valido.\n\n");
        return 1;
    }

    
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

    
    if (id_producto == 0)
    {
        printf("No es el ID de un producto.\n\n");
        return 1;
    }

   
    do
    {
        printf("Inserta la nueva cantidad del producto: ");
        scanf("%d", &nueva_cantidad);        
        
        if (nueva_cantidad == cantidad[posicion])
        {
            printf("Esa es la cantidad actual del producto. Inserta una nueva.\n\n");
        }
        else
        {
            
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



int eliminar_producto(int id[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10])
{
    int id_producto;
    int posicion;

    
    printf("\nInserta el ID del producto para eliminarlo: ");
    scanf("%d", &id_producto);

    
    if (id_producto == 0)
    {
        printf("El ID 0 no es valido.\n\n");
        return 1;
    }

    
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

    
    if (id_producto == 0)
    {
        printf("No es el ID de un producto.\n\n");
        return 1;
    }

    
    id[posicion] = 0;
    nombres[posicion] = "------";
    cantidad[posicion] = 0;
    precios[posicion] = 0;
    printf("El producto ha sido eliminado\n\n");
    return 0;
}


