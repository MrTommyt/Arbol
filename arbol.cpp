#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

#include "arbol.h"
#include <iostream>
#include <vector>
#include <queue>

NodoBusqueda *NodoBusqueda::izquierda() {
    return izq;
}

NodoBusqueda *NodoBusqueda::derecha() {
    return der;
}

void insertar0(NodoBusqueda **n, int valor) {
    if (n == nullptr || *n == nullptr) {
        *n = new NodoBusqueda(valor);
        return;
    }

    (*n)->insertar(valor);
}


void NodoBusqueda::insertar(int valor) {
    int v = this->valor;
    if (valor == v) {
        std::cout << "No se pudo introducir " << valor << ", duplicado." << std::endl;
        return;
    }

    if (valor > v) {
        insertar0(&this->der, valor);
    } else {
        insertar0(&this->izq, valor);
    }
}

NodoBusqueda *NodoBusqueda::eliminar(int valor) {
    NodoBusqueda *root = this;
    if (root == nullptr) {
        return root;
    }

    if (valor < root->valor) {
        root->izq = root->izquierda()->eliminar(valor);
    } else if (valor > root->valor) {
        root->der = root->derecha()->eliminar(valor);
    } else {
        if (root->izquierda() == nullptr and root->derecha() == nullptr) {
            return nullptr;
        }

        else if (root->izquierda() == nullptr) {
            NodoBusqueda *temp = root->derecha();
            delete root;
            return temp;
        }
        else if (root->derecha() == nullptr) {
            NodoBusqueda *temp = root->izquierda();
            delete root;
            return temp;
        }

        NodoBusqueda *temp = root->derecha()->minValue();
        root->valor = temp->valor;
        root->der = root->derecha()->eliminar(temp->valor);
    }
    return root;
}

NodoBusqueda::NodoBusqueda(int valor) {
    this->izq = nullptr;
    this->der = nullptr;
    this->valor = valor;
}

void NodoBusqueda::recorrer(void (*recorrer)(NodoBusqueda*)) {
    recorrer(this);
}

NodoBusqueda *NodoBusqueda::buscar(int valor) {
    NodoBusqueda *n = this;
    std::queue<NodoBusqueda*> q;
    do {
        if (!q.empty()) {
            n = q.front();
            q.pop();
        }

        if (n->valor == valor) {
            return n;
        }

        std::cout << n->valor << " ";
        if (n->izquierda() != nullptr) {
            q.push(n->izquierda());
        }
        if (n->derecha() != nullptr) {
            q.push(n->derecha());
        }
    } while (!q.empty());
    return nullptr;
}

NodoBusqueda *NodoBusqueda::minValue() {
    NodoBusqueda *n = this;
    while (n != nullptr && n->izquierda() != nullptr)
        n = n->izquierda();
    return n;
}

void procesar(NodoBusqueda *nodo, Recorrido) {
    if (nodo != nullptr) {
        recorrer(nodo);
    }
}

void Anchura(NodoBusqueda *nodo) {
    NodoBusqueda *n = nodo;
    std::queue<NodoBusqueda*> q;
    do {
        if (!q.empty()) {
            n = q.front();
            q.pop();
        }

        std::cout << n->valor << " ";
        if (n->izquierda() != nullptr) {
            q.push(n->izquierda());
        }
        if (n->derecha() != nullptr) {
            q.push(n->derecha());
        }
    } while (!q.empty());
}

void InOrden(NodoBusqueda *nodo) {
    if (nodo == nullptr) {
        return;
    }

    procesar(nodo->izquierda(), InOrden);
    std::cout << nodo->valor << " ";
    procesar(nodo->derecha(), InOrden);
}

void PreOrden(NodoBusqueda *nodo) {
    if (nodo == nullptr) {
        return;
    }

    std::cout << nodo->valor << " ";
    procesar(nodo->izquierda(), PreOrden);
    procesar(nodo->derecha(), PreOrden);
}

void PosOrden(NodoBusqueda *nodo) {
    if (nodo == nullptr) {
        return;
    }

    procesar(nodo->izquierda(), PosOrden);
    procesar(nodo->derecha(), PosOrden);
    std::cout << nodo->valor << " ";
}

#pragma clang diagnostic pop