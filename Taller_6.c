#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cabecera.h"

int main(){
    //Declaración de variables
    char product_name[MAX_PRODUCTS][MAX_NAME], search[MAX_NAME];
    float price[MAX_PRODUCTS], prom_products;
    int option, lowest_index, highest_index;
    //Presentación del simulador
    printf("\t\x1B[34m*******************\x1B[0m\n");
    printf("\t\x1B[35mSimulador de tienda\x1B[0m\n");
    printf("\t\x1B[34m*******************\x1B[0m\n");
    printf("Ingrese la informacion de %d productos\n", MAX_PRODUCTS);
    printf("\t----------------------------------\n");
    //Ingreso de datos por parte del usuario
    for (int i = 0; i < MAX_PRODUCTS; i++){
        printf("\t\x1B[33mDatos del producto %d\x1B[0m\n\n", i + 1);
        //Llamado de la función ingreso_nombre para que el usuario puede registrar los nombres de cada producto del inventario 
        ingreso_nombre(product_name[i], i + 1); //Los parámetros de esta función es el matriz product_name y el contador i para así guardar en cada fila el nombre de cada producto
        price[i] = ingreso_precios(i + 1); //Se declara al arreglo unidimensional de precios con la función ingreso_precios, los parámetros es el contador i, al aumentar al paso del FOR se guarda un nuevo valor 
    }
    //Presentación del menú interactivo para la administración del inventario
    do{
        printf("\n\t\x1B[33mADMINISTRACION DE LA TIENDA\x1B[0m\n");
        printf("1. Mostrar el precio total del inventario\n");
        printf("2. Mostrar el producto mas caro y mas barato\n");
        printf("3. Mostrar el precio promedio del inventario\n");
        printf("4. Busqueda de productos\n");
        printf("5. SALIR\n");
        printf("Seleccione una opcion: ");
        while (scanf("%d", &option) != 1 || option < 0){ //
            printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n");
            while(getchar() != '\n');
            printf("Seleccione una opcion: ");
            continue;
        }
        getchar();
        switch (option){
        case 1:
            printf("El precio total del inventario es: $ %.2f\n", precio_total(price, MAX_PRODUCTS));
            break;
        case 2:
            lowest_index = index_min(price, MAX_PRODUCTS);
            highest_index = index_max(price, MAX_PRODUCTS);
            printf("Producto mas barato: %s -> $%.2f\n", product_name[lowest_index], price[lowest_index]);
            printf("Producto mas caro: %s -> $%.2f\n", product_name[highest_index], price[highest_index]);
            break;
        case 3:
            prom_products = precio_total(price, MAX_PRODUCTS) / MAX_PRODUCTS;
            printf("El precio promedio del inventario es: $ %.2f\n", prom_products);
            break;
        case 4:
            mostrar_productos(product_name, MAX_PRODUCTS);
            leer_buqueda(search);
            buscar_productos(product_name, price, MAX_PRODUCTS, search);
            break;
        case 5:
            printf("\x1B[33mSaliendo del programa...\x1B[0m\n");
            break;
        default:
            printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n");
            break;
        }
    } while (option != 5);
    
    return 0;
}