#ifndef LISTA_H
#define LISTA_H

template<class T, class S>
struct nodo{
       T dato1;
       S dato2;
       nodo<T,S> *sig;
};

template<class T, class S>
class Lista{
      int num_elem;
      nodo<T,S> *cab;
      public:
             Lista(){
                     num_elem = 0;
                     cab=NULL;
             }
             ~Lista(){}; //destructor
             bool lista_vacia(){
                  return(cab==NULL);
                  }
            int getLongitud() const {
                 return num_elem;
             }
             nodo<T,S>* buscar_posicion(int posicion);
             void insertar_inicio(T info1, S info2);
             void insertar_final(T info1, S info2);
             void insertar_posicion(T info1, S info2, int posicion);
             bool borrar_posicion(int posicion);
             void modificar_posicion(T info1, S info2, int posicion);
};

template<class T, class S>
nodo<T,S>* Lista<T,S>::buscar_posicion(int posicion) {
    if (posicion < 0 || posicion >= num_elem)
        return NULL;
        
    nodo<T,S> *aux = cab;
    for (int i = 0; i < posicion; i++) {
        aux = aux->sig;
    }
    return aux;
}

template<class T, class S>
void Lista<T,S>::insertar_inicio(T info1, S info2){
     nodo<T,S> *Aux = new nodo<T,S>;
     Aux->dato1=info1;
     Aux->dato2=info2;
     
     Aux->sig=cab;
     
     cab = Aux;
     
     num_elem++;
}

template<class T, class S>
void Lista<T,S>::insertar_final(T info1, S info2){
     nodo<T,S> *Aux = new nodo<T,S>;
     Aux->dato1 = info1;
     Aux->dato2 = info2;
     Aux->sig = NULL;
     
     if(cab == NULL){
         cab = Aux;
     }
     else {
         nodo<T,S> *fin = cab;
         while(fin->sig != NULL){
             fin = fin->sig;
         }
         fin->sig = Aux;
     }
     num_elem++;
}

template<class T, class S>
void Lista<T,S>::insertar_posicion(T info1, S info2, int posicion) {
    if (posicion < 0 || posicion > num_elem)
        return;
        
    if (posicion == 0) {
        insertar_inicio(info1, info2);
        return;
    }
    
    if (posicion == num_elem) {
        insertar_final(info1, info2);
        return;
    }
    
    nodo<T,S> *Aux = new nodo<T,S>;
    Aux->dato1 = info1;
    Aux->dato2 = info2;
    
    nodo<T,S> *prev = buscar_posicion(posicion - 1);
    Aux->sig = prev->sig;
    prev->sig = Aux;
    
    num_elem++;
}

template<class T, class S>
bool Lista<T,S>::borrar_posicion(int posicion) {
    if (lista_vacia())
        return false;
        
    if (posicion < 0 || posicion >= num_elem)
        return false;
    
    nodo<T,S> *temp;
    
    if (posicion == 0) {
        temp = cab;
        cab = cab->sig;
    } else {
        nodo<T,S> *prev = buscar_posicion(posicion - 1);
        temp = prev->sig;
        prev->sig = temp->sig;
    }
    
    delete temp;
    num_elem--;
    
    return true;
}

template<class T, class S>
void Lista<T,S>::modificar_posicion(T info1, S info2, int posicion) {
    if (posicion < 0 || posicion >= num_elem)
        return;
        
    nodo<T,S> *temp = buscar_posicion(posicion);
    temp->dato1 = info1;
    temp->dato2 = info2;
}
         
#endif
