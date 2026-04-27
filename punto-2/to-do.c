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

Nodo *crearListaVacia(){
    return NULL;
}

Nodo *crearTarea(int id){
    Nodo *NuevaTarea = (Nodo*)malloc(sizeof(Nodo));
    NuevaTarea->T.Descripcion = malloc(100 * sizeof(char));
    
    printf("Ingrese la descripcion de la nueva tarea: ");
    getchar();
    fgets(NuevaTarea->T.Descripcion,100,stdin);
        
    printf("Ingrese la duracion en la tarea(10 - 100): ");
    scanf("%d",&NuevaTarea->T.Duracion);

    NuevaTarea->T.TareaID = id;
    id = id+1;

    NuevaTarea->Siguiente = NULL;

    return NuevaTarea;
}
void InsertarAlFinal(Nodo *pendiente, Nodo *tarea){
    Nodo *Aux = tarea;
    while(Aux->Siguiente){
        Aux = Aux->Siguiente;
    }

    Aux->Siguiente = tarea;
}


int main(){
    int id = 1000,a;
    Nodo *pendiente, *realizada,*tarea;
    
    pendiente = crearListaVacia();
    realizada = crearListaVacia();
    
    do{
        tarea = crearTarea(id);
        InsertarAlFinal(pendiente,tarea);
        printf("Desea ingresar una nueva tarea?\n1)no \n2)si \nrespuesta: ");
        scanf("%d",&a);
    } while (a == 2);
    

}