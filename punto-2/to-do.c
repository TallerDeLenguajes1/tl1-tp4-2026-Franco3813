#include <stdlib.h>
#include <stdio.h>

typedef struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}Tarea;

typedef struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}Nodo;

Nodo *crearlista(){
    return NULL;
}

int main(){
    int repetir = 1;
    Nodo *pendiente, *realizada;
    
    pendiente = crearlista();
    realizada = crearlista();
    
    do{
        
        printf("\nIngrese una nueva tarea: ");

    } while (repetir == 2);
    
}