#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUTOS 100
#define MAX_PLACA 10
#define MAX_NOMBRE 50
//Estructuras de datos - LIS 2032-01
//Nombres Completos: Jose Miguel Alameda Romero, Carlos Galan, Gil Andrei Sotomayor Figueroa
//El programa en C gestiona un estacionamiento de autos utilizando una pila implementada con un arreglo de estructuras.
//Permite agregar y sacar autos, además de mostrar el número total de autos, la lista de autos y las características del primer y último auto.
typedef struct {
    char nombre[MAX_NOMBRE];
    char placa[MAX_PLACA];
    int modelo;
} Auto;

typedef struct {
    Auto autos[MAX_AUTOS];
    int top;
} PilaAutos;

void inicializarPila(PilaAutos *pila) {
    pila->top = -1;
}

int estaLlena(PilaAutos *pila) {
    return pila->top == MAX_AUTOS - 1;
}

int estaVacia(PilaAutos *pila) {
    return pila->top == -1;
}

void push(PilaAutos *pila, Auto autoNuevo) {
    if (estaLlena(pila)) {
        printf("La pila está llena, no se puede agregar más autos.\n");
        return;
    }
    pila->top++;
    pila->autos[pila->top] = autoNuevo;
}

Auto pop(PilaAutos *pila) {
    Auto autoSaliente;
    if (estaVacia(pila)) {
        printf("La pila está vacía, no hay autos para sacar.\n");
        strcpy(autoSaliente.nombre, "");
        strcpy(autoSaliente.placa, "");
        autoSaliente.modelo = 0;
        return autoSaliente;
    }
    autoSaliente = pila->autos[pila->top];
    pila->top--;
    return autoSaliente;
}

void imprimirNumeroAutos(PilaAutos *pila) {
    printf("Número de autos en el estacionamiento: %d\n", pila->top + 1);
}

void imprimirListaAutos(PilaAutos *pila) {
    printf("Lista de autos en el estacionamiento:\n");
    for (int i = pila->top; i >= 0; i--) {
        printf("Nombre: %s, Placa: %s, Modelo: %d\n", pila->autos[i].nombre, pila->autos[i].placa, pila->autos[i].modelo);
    }
}

void imprimirPrimerAuto(PilaAutos *pila) {
    if (!estaVacia(pila)) {
        printf("Primer auto que entró:\n");
        printf("Nombre: %s, Placa: %s, Modelo: %d\n", pila->autos[0].nombre, pila->autos[0].placa, pila->autos[0].modelo);
    } else {
        printf("No hay autos en el estacionamiento.\n");
    }
}

void imprimirUltimoAuto(PilaAutos *pila) {
    if (!estaVacia(pila)) {
        printf("Último auto que entró:\n");
        printf("Nombre: %s, Placa: %s, Modelo: %d\n", pila->autos[pila->top].nombre, pila->autos[pila->top].placa, pila->autos[pila->top].modelo);
    } else {
        printf("No hay autos en el estacionamiento.\n");
    }
}

int main() {
    PilaAutos pila;
    inicializarPila(&pila);
    int opcion;
    
    do {
        printf("\nMenú:\n");
        printf("1. Agregar auto\n");
        printf("2. Sacar auto\n");
        printf("3. Imprimir número de autos en el estacionamiento\n");
        printf("4. Imprimir lista de autos\n");
        printf("5. Imprimir primer auto que entró\n");
        printf("6. Imprimir último auto que entró\n");
        printf("7. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                Auto nuevoAuto;
                printf("Ingrese el nombre del auto: ");
                scanf("%s", nuevoAuto.nombre);
                printf("Ingrese la placa del auto: ");
                scanf("%s", nuevoAuto.placa);
                printf("Ingrese el modelo del auto: ");
                scanf("%d", &nuevoAuto.modelo);
                push(&pila, nuevoAuto);
                break;
            }
            case 2: {
                Auto autoSaliente = pop(&pila);
                printf("Auto sacado:\n");
                printf("Nombre: %s, Placa: %s, Modelo: %d\n", autoSaliente.nombre, autoSaliente.placa, autoSaliente.modelo);
                break;
            }
            case 3:
                imprimirNumeroAutos(&pila);
                break;
            case 4:
                imprimirListaAutos(&pila);
                break;
            case 5:
                imprimirPrimerAuto(&pila);
                break;
            case 6:
                imprimirUltimoAuto(&pila);
                break;
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 7);
    
    return 0;
}
