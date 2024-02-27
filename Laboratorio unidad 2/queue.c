#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define tamaño 5

char nombre[tamaño][10];
char placas[tamaño][10];
int modelo[tamaño];
char *nptr[tamaño];
char *pptr[tamaño];
int *mptr[tamaño];

int atras = 0;

//Metodo para insertar
void insertarq(){
    char insertarS[10]; // Cadena de caracteres
    int insertarI;
    if(atras == tamaño - 1){
        printf("Ya no caben más coches");
    }else{
        printf("Ingresa los datos: ");
        printf("Marca: ");
        scanf("%s", insertarS);
        strcpy(nombre[atras], insertarS); // Copia el char
        nptr[atras] = nombre[atras];
        printf("Placas: ");
        scanf("%s", insertarS);
        strcpy(placas[atras], insertarS); 
        pptr[atras] = placas[atras];
        printf("Modelo (numero del 1-10): ");
        scanf("%d", &insertarI);
        modelo[atras] = insertarI;
        mptr[atras] = &modelo[atras];
        
        
        atras++;
    }
}

//Metodo para eliminar
void quitarq(){
    if(atras == 0){
        printf("No hay coches");
    }else{
        printf("Primer elemento eliminado");
        for(int i = 0; i < atras - 1; i++){
            for (int j = 0; j < 10; j++) {
                nombre[i][j] = nombre[i + 1][j];
                placas[i][j] = placas[i + 1][j];
            }
            modelo[i] = modelo[i + 1];
        }
        atras --;
    }
}


//Imprime todo
void mostrar(){
    if(atras == 0){
        printf("No hay coches");
    }else{
        for(int i = 0; i < atras; i++){ 
            printf("\nCoche %d", i + 1);
            printf("\nMarca: ");
            printf("%s", nptr[i]);
            printf("\nPlacas: ");
            printf("%s", pptr[i]);
            printf("\nModelo: ");
            printf("%d", *mptr[i]); 
        }
    }
}


// Main
int main()
{
    
    bool flag = true;
    int opcion = 0;
    while(flag == true){
        
        
        switch (opcion){
            case 0:
            printf("\n Eliga la opción:\n ");
            printf("1. Ingresar nuevo coche \n 2. Eliminar primer coche \n 3. Ver los coches almacenados \n 4. Salir \n");
            scanf("%d", &opcion);
            break;
            case 1:
            insertarq();
            opcion = 0;
            break;
            case 2:
            quitarq();
            opcion = 0;
            break;
            case 3: 
            mostrar();
            opcion = 0;
            break;
            case 4:
            flag = false;
            break;
        }
    }
    return 0;
}