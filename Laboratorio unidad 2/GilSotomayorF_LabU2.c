#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100 // Tamaño máximo para los arreglos

// Prototipos de funciones
void valoresArreglo2(int arr[], int n);
void insertarInicio(int arr[], int *size, int val);
void insertarMedio(int arr[], int *size, int pos, int val);
void insertarFinal(int arr[], int *size, int val);
void eliminarInicio(int arr[], int *size);
void eliminarMedio(int arr[], int *size, int pos);
void eliminarFinal(int arr[], int *size);
void fusionarArreglos(int arr1[], int size1, int arr2[], int size2, int arrFusionado[], int n);
void eliminarInicio(int arr[], int *size) {
    if (*size == 0) {
        printf("El arreglo está vacío.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

void valoresArreglo2(int arr[], int n){
     srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100 + 1; // Números aleatorios entre 1 y 100
    }
    printf("El arreglo 2 tiene estos valores: ");
    for(int i = 0; i<n; i++){
                    printf(" %d ", arr[i]);                    
                }
}

void fusionarArreglos(int arr1[], int size1, int arr2[], int size2, int arrFusionado[], int n) {
    int i, j;
    int arreglovolteado[MAX_SIZE];
    int arreglovolteado2[MAX_SIZE];
    for (i = 0; i < size1; i++) {
        arreglovolteado[i] = arr1[i];
    }
    for (i = 0; i < size1; i++) {
        arrFusionado[i] = arreglovolteado[i];
        
    }
    for (i = 0; i < n; i++) {
        arreglovolteado2[i] = arr2[i];
        
    }
    for (j = 0; j < n; j++) {
        arrFusionado[size1 + j] = arreglovolteado2[j];
        
    }
    int arrfus = size1 + n;
     printf("El arreglo fusionado es: ");
    for(int i = 0; i < arrfus; i++) {
       
                    printf(" %d ", arrFusionado[i]);
                }
}


void eliminarMedio(int arr[], int *size, int pos) {
    if (*size == 0) {
        printf("El arreglo está vacío.\n");
        return;
    }
    if (pos < 0 || pos >= *size) {
        printf("Posición inválida.\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

void eliminarFinal(int arr[], int *size) {
    if (*size == 0) {
        printf("El arreglo está vacío.\n");
        return;
    }
    (*size)--;
}


void insertarInicio(int arr[], int *size, int val) {
    if (*size >= MAX_SIZE) {
        printf("El arreglo está lleno. No se puede insertar.\n");
        return;
    }
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = val;
    (*size)++;
}

void insertarMedio(int arr[], int *size, int pos, int val) {
    if (*size >= MAX_SIZE) {
        printf("El arreglo está lleno. No se puede insertar.\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Posición inválida.\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    (*size)++;
}

void insertarFinal(int arr[], int *size, int val) {
    if (*size >= MAX_SIZE) {
        printf("El arreglo está lleno. No se puede insertar.\n");
        return;
    }
    arr[*size] = val;
    (*size)++;
}

int main() {
    int arreglo1[MAX_SIZE];
    int arreglo2[MAX_SIZE];
    int arregloFusionado[2*MAX_SIZE];
    int size1 = 0, size2 = 0; // Tamaños actuales de los arreglos
    int opcion = 0, valor, pos;
    int n = 0;
    printf("De que tamaño quieres que sea el arreglo 2 (Menor o igual a 100)? ");
    scanf("%d", &n);
    while(n>100){
    printf("Ingrese un tamaño menor o igual a 100 ");
    scanf("%d", &n);

    }
    valoresArreglo2(arreglo2,n);

    while(opcion != 8) {
        printf("\n\n\n--- MENU ---\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar en una posición específica\n");
        printf("3. Insertar al final\n");
        printf("4. Eliminar al inicio\n");
        printf("5. Eliminar de una posición específica\n");
        printf("6. Eliminar al final\n");
        printf("7. Fusionar arreglos\n");
        printf("8. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 0:   
             printf("\n\n\n--- MENU ---\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar en una posición específica\n");
        printf("3. Insertar al final\n");
        printf("4. Eliminar al inicio\n");
        printf("5. Eliminar de una posición específica\n");
        printf("6. Eliminar al final\n");
        printf("7. Fusionar arreglos\n");
        printf("8. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                insertarInicio(arreglo1, &size1, valor);
                
                printf("\nEl valor del arreglo es: ");
        for(int i = 0; i < size1 + size2; i++) {
                    printf(" %d ", arreglo1[i]);
                }
                
                break;
            case 2:
                printf("Ingrese la posición y el valor a insertar: ");
                scanf("%d %d", &pos, &valor);
                insertarMedio(arreglo1, &size1, pos, valor);
                
                printf("\nEl valor del arreglo es: ");
        for(int i = 0; i < size1 + size2; i++) {
                    printf(" %d ", arreglo1[i]);
                }
                
                break;
            case 3:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                insertarFinal(arreglo1, &size1, valor);
                
                printf("\nEl valor del arreglo es: ");
        for(int i = 0; i < size1 + size2; i++) {
                    printf(" %d ", arreglo1[i]);
                }
                
                break;
            case 4:
                eliminarInicio(arreglo1, &size1);
                
                printf("\nEl valor del arreglo es: ");
        for(int i = 0; i < size1 + size2; i++) {
                    printf(" %d ", arreglo1[i]);
                }
                
                break;
            case 5:
                printf("\nIngrese la posición a eliminar: ");
                scanf("%d", &pos);
                eliminarMedio(arreglo1, &size1, pos);
                
                printf("El valor del arreglo es: ");
        for(int i = 0; i < size1 + size2; i++) {
                    printf(" %d ", arreglo1[i]);
                }
                //opcion = 0;
                break;
            case 6:
                eliminarFinal(arreglo1, &size1);
                
                printf("\nEl valor del arreglo es: ");
        for(int i = 0; i < size1 + size2; i++) {
                    printf(" %d ", arreglo1[i]);
                }
               
                break;
            case 7:
                
                fusionarArreglos(arreglo1, size1, arreglo2, size2, arregloFusionado, n);
                
                
                printf("\n");
              
                break;
            case 8:
                printf("Saliendo...\n");
                return 0;
            default:
                printf("Opción inválida\n");
        }
        
        
    }

    return 0;
}