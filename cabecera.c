#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cabecera.h"

void ingreso_nombre(char name[], int position){
    do{
        printf("Ingrese el nombre del producto %d: ", position);
        fgets(name, MAX_NAME, stdin);
        name[strcspn(name, "\n")] = '\0';
        if (!nombre_valido(name)){
            printf("\x1B[31mNombre no valido, ingrese nuevamente\x1B[0m\n");
        }
    } while (!nombre_valido(name));
}

float ingreso_precios(int position){
    float value;
    int valido;
    do{
        printf("Ingrese el precio del producto %d: $ ", position);
        valido = scanf("%f", &value);
        while(getchar() != '\n');
        if (valido != 1 || value < 0){
            printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n");
        }
    } while (valido != 1 || value < 0);
    return value;
}

float precio_total(const float prices[], int size){
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum+=prices[i];
    }
    return sum;
}

int index_min(const float price[], int size){
    int index_min = 0;
    for (int i = 1; i < size; i++){
        if (price[i] < price[index_min]){
            index_min = i;
        }
    }
    return index_min;
}

int index_max(const float price[], int size){
    int index_max = 0;
    for (int i = 1; i < size; i++){
        if (price[i] > price[index_max]){
            index_max = i;
        }
    }
    return index_max;
}

void mostrar_productos(const char name[][MAX_NAME], int size){
    printf("\t\x1B[33mLISTA DE PRODUCTOS\x1B[0m\n");
    for (int i = 0; i < size; i++){
        printf("%d. %s\n", i + 1, name[i]);
    }
}

void leer_buqueda(char consult[]){
    do{
        printf("Ingrese el nombre del producto a buscar: ");
        fgets(consult, MAX_NAME, stdin);
        consult[strcspn(consult, "\n")] = '\0';
        if (!nombre_valido(consult)){
            printf("\x1B[31mNombre no valido, ingrese nuevamente\x1B[0m\n");
        }
    } while (!nombre_valido(consult));
}

int nombre_valido(const char *name){
    for (int i = 0; name[i] != '\0'; i++){
        if (!isalpha((unsigned char)name[i]) && name[i] != ' '){
            return 0;
        }
    }
    return 1;
}

void buscar_productos(const char name[][MAX_NAME], const float price[], int size, const char *consult){
    for (int i = 0; i < size; i++){
        if (strcasecmp(name[i], consult) == 0){
            printf("Producto \x1B[33m\"%s\"\x1B[0m encontrado\n", name[i]);
            printf("Precio: $ %.2f\n", price[i]);
            return;
        }
    }
    printf("El producto \"%s\" no se ha encontrado\n", consult);
}