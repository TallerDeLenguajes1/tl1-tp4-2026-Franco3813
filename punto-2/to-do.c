#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    tarea->Siguiente = *lista;
    *lista = tarea;
}

void BuscadorPorId(Nodo *lista,Nodo *lista2,int id){
    Nodo *Aux = lista;
    Nodo *Aux2 = lista2;

    while (Aux && Aux->T.TareaID != id){
        Aux = Aux->Siguiente;
    }

    while (Aux2 && Aux2->T.TareaID != id){
        Aux2 = Aux2->Siguiente;
    }
    if (Aux2 == NULL){
        printf("\nDescripcion de la tarea: %s", Aux->T.Descripcion);
        printf("\nDuracion de la tarea: %d", Aux->T.Duracion);
        printf("\nId de la tarea: %d", Aux->T.TareaID);
        printf("\nUbicacion de la tarea: Pendiente");
        printf("\n------------------------\n");
    }else{
        printf("\nDescripcion de la tarea: %s", Aux2->T.Descripcion);
        printf("\nDuracion de la tarea: %d", Aux2->T.Duracion);
        printf("\nId de la tarea: %d", Aux2->T.TareaID);
        printf("\nUbicacion de la tarea: Realizada");
        printf("\n------------------------\n");
    }
    
    
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

void mostrarLista(Nodo *lista){
    Nodo *Aux = lista;

    while (Aux != NULL){
        printf("\nDescripcion de la tarea: %s",Aux->T.Descripcion);
        printf("\nDuracion de la tarea: %d",Aux->T.Duracion);
        printf("\nId de la tarea: %d",Aux->T.TareaID);
        printf("\n------------------------");

        Aux = Aux->Siguiente;
    }
    
}

void BuscardorPorPalabra(Nodo *lista,Nodo *lista2, char *frase){
    Nodo *Aux = lista;
    Nodo *Aux2 = lista2;

    while (Aux != NULL){
        if (strstr(Aux->T.Descripcion, frase) != NULL){
            printf("\nDescripcion de la tarea: %s", Aux->T.Descripcion);
            printf("\nDuracion de la tarea: %d", Aux->T.Duracion);
            printf("\nId de la tarea: %d", Aux->T.TareaID);
            printf("\nUbicacion de la tarea: Pendiente");
            printf("\n------------------------\n");
        }
        Aux = Aux->Siguiente;
    }

    while (Aux2 != NULL){
        if (strstr(Aux2->T.Descripcion, frase) != NULL){
            printf("\nDescripcion de la tarea: %s", Aux2->T.Descripcion);
            printf("\nDuracion de la tarea: %d", Aux2->T.Duracion);
            printf("\nId de la tarea: %d", Aux2->T.TareaID);
            printf("\nUbicacion de la tarea: Realizada");
            printf("\n------------------------\n");
        }
        Aux2 = Aux2->Siguiente;
    }
    
}


int main(){
    int id = 1000,a,idbuscado,b,c;
    Nodo *pendiente, *realizada,*tarea,*buscado,*Aux;
    char frase[100];
    
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
        buscado = QuitarNodo(&pendiente,idbuscado);
        Insertar(&realizada,buscado);
        
        printf("Desea agregar otra tarea?\n1)no \n2)si \nrespuesta: ");
        scanf("%d",&a);
    } while (a == 2);
    
    printf("\nLista de las tareas pendientes");
    mostrarLista(pendiente);
    printf("\n");
    printf("\nLista de las tareas realizadas");
    mostrarLista(realizada);

    printf("\nBusqueda de tarea");
    printf("\n1)Buscar por palabra clave \n2)Buscar por id");
    printf("\nRespuesta: ");
    scanf("%d",&b);

    if (b == 1){
        printf("\nIngrese una palabra clave para buscar un nombre: ");
        scanf("%s",frase);
        BuscardorPorPalabra(pendiente,realizada,frase);
    }else{
        printf("\nIngrese el id de la tarea: ");
        scanf("%d",&c);
        BuscadorPorId(pendiente,realizada,c);
    }
    
}