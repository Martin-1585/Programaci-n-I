#define MAX_NAME 20
#define MAX_PRODUCTS 10

//Prototipos de funciones auxiliares
void ingreso_nombre(char name[], int position);
float ingreso_precios(int position);
float precio_total(const float prices[], int size);
int index_min(const float price[], int size);
int index_max(const float price[], int size);
void mostrar_productos(const char name[][MAX_NAME], int size);
void leer_buqueda(char consult[]);
int nombre_valido(const char *name);
void buscar_productos(const char name[][MAX_NAME], const float price[], int size, const char *consult);