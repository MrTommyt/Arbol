#include <iostream>
#include "arbol.h"

void printFull(NodoBusqueda *nodo);

int main() {
    auto *n = new NodoBusqueda(5);
    n->insertar(6);
    n->insertar(9);
    n->insertar(2);
    n->insertar(8);
    n->insertar(7);
    n->insertar(10);
    n->insertar(1);
    n->insertar(4);

    printFull(n);
    std::cout << std::endl << "Eliminando el 9!" << std::endl ;
    n->eliminar(9);
    printFull(n);
    return 0;
}

void printFull(NodoBusqueda *n) {
    std::cout << "InOrden: ";
    n->recorrer(InOrden);
    std::cout << std::endl << "PreOrden: ";
    n->recorrer(PreOrden);
    std::cout << std::endl << "PosOrden: ";
    n->recorrer(PosOrden);
    std::cout << std::endl << "Anchura: ";
    n->recorrer(Anchura);
}
