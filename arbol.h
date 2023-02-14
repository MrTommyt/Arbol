#ifndef ARBOL_ARBOL_H
#define ARBOL_ARBOL_H

#define Recorrido void (*recorrer)(NodoBusqueda*)

class NodoBusqueda {
public:
    NodoBusqueda *izq;
    NodoBusqueda *der;
    int valor;

    NodoBusqueda(int valor);

    NodoBusqueda *izquierda();
    NodoBusqueda *derecha();
    void insertar(int valor);
    NodoBusqueda *eliminar(int valor);
    NodoBusqueda *buscar(int valor);
    NodoBusqueda *minValue();

    void recorrer(Recorrido);
};

void InOrden(NodoBusqueda *nodo);
void PreOrden(NodoBusqueda *nodo);
void PosOrden(NodoBusqueda *nodo);
void Anchura(NodoBusqueda *nodo);

#endif //ARBOL_ARBOL_H
