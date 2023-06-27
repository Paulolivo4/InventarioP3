#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_inventario.h"


int main(int argc, char *argv[])
{
    
    int opcion;
    int id[10] = {1, 2, 3, 4, 0, 0, 0, 0, 0, 0};
    char *nombres[10] = {"Esfero", "Calculadora", "Sacapuntas", "Borrador", "------",
                        "------", "------", "------", "------", "------"};
    int cantidad[10] = {2, 3, 1, 4, 0, 0, 0, 0, 0, 0};
    float precios[10] = {0.50, 2.50, 0.30, 0.50, 0, 0, 0, 0, 0, 0};
    char nuevo_nombre[50];


    
    do
    {
        printf("\n-----------------MENU-------------\n");
        printf("1. Ver Inventario\n");
        printf("2. Ingresar producto\n");
        printf("3. Modificar cantidad de producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir del inventario\n");
        printf("------------------------------------\n");
        printf("Por favor seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            mostrar_inventario(id, nombres, cantidad, precios);
            break;
        case 2:
            ingresar_producto(id, nombres, nuevo_nombre, cantidad, precios);
            break;
        case 3:
            modificar_cantidad(id, cantidad);
            break;
        case 4:
            eliminar_producto(id, nombres, nuevo_nombre, cantidad, precios);
            break;
        case 5:
            printf("\nVuelve pronto!\n");
            break;
        default:
            printf("Opción no valida, intenta otra vez\n\n");
            break;
        }
    } while (opcion != 5);

    return 0;
}

