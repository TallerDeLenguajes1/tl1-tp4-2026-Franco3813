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
        
    do{
        printf("Ingrese la duracion en la tarea(10 - 100): ");
        scanf("%d",&NuevaTarea->T.Duracion);
    } while (NuevaTarea->T.Duracion < 10 || NuevaTarea->T.Duracion > 100);
    

    NuevaTarea->T.TareaID = id;
    printf("numero de id: %d\n",NuevaTarea->T.TareaID);

    NuevaTarea->Siguiente = NULL;

    return NuevaTarea;
}
void Insertar(Nodo **lista,Nodo *tarea){
    if (*lista == NULL){
        tarea->Siguiente = *lista;
        *lista = tarea;
    }else{
        printf("La tarea ya a sido eliminada o no existe\n");
    }
    
    
}

Nodo *Buscador(Nodo *pendiente,int idBuscado){
    Nodo* Aux = pendiente;
    while (Aux && Aux->T.TareaID != idBuscado){
        Aux = Aux->Siguiente;
    }
    return Aux;
}

Nodo *QuitarNodo(Nodo **lista,int id){
    Nodo *nodoAux = (*lista);
    Nodo *nodoAnt = NULL;

    while (nodoAux != NULL && nodoAux->T.TareaID != id){
        nodoAnt = nodoAux;
        nodoAux = nodoAux->Siguiente;
    }

    if (nodoAux != NULL){
        if (nodoAux == (*lista)){
            (*lista) = nodoAux->Siguiente;
        }else{
            nodoAnt->Siguiente = nodoAux->Siguiente;
        }
        nodoAux->Siguiente = NULL;
    }
    
    return nodoAux;
}


int main(){
    int id = 1000,a,idbuscado;
    Nodo *pendiente, *realizada,*tarea,*buscado;
    
    pendiente = crearListaVacia();
    realizada = crearListaVacia();
    
    do{
        tarea = crearTarea(id);
        Insertar(&pendiente,tarea);
        printf("Desea ingresar una nueva tarea?\n1)no \n2)si \nrespuesta: ");
        scanf("%d",&a);
        id = id+1;
    } while (a == 2);
    printf("\n");
    do{
        printf("Ingrese el id la tarea completada: ");
        scanf("%d",&idbuscado);
        buscado = Buscador(pendiente,idbuscado);
        Insertar(&realizada,buscado);
        QuitarNodo(&pendiente,idbuscado);
        printf("Desea agregar otra tarea?\n1)no \n2)si \nrespuesta: ");
        scanf("%d",&a);

    } while (a == 2);
    
    

}