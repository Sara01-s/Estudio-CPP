#include <iostream>

struct Nodo {
    int dato;
    Nodo* der;    
    Nodo* izq;
    Nodo* padre;
};

// Declaración de funciones y árbol
void menu();
Nodo* crearNodo(int, Nodo*);
void insertarNodo(Nodo* &, int, Nodo*);
void mostrarArbol(Nodo*, int);
void recorrerArbolPreOrden(Nodo*);
void recorrerArbolInOrden(Nodo*);
void recorrerArbolPostOrden(Nodo*);
void buscarYEliminar(Nodo*, int);
void eliminarNodo(Nodo*);
void destruirNodo(Nodo*);
void reemplazarNodo(Nodo*, Nodo*);
bool buscarNodo(Nodo*, int);
Nodo* encontrarMinimo(Nodo*);

Nodo* arbol = NULL;

int main() {

    menu();

    delete arbol;
    return 0;
}


Nodo* crearNodo(int numero, Nodo* padre) {
    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->dato = numero;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

void insertarNodo(Nodo* &arbol, int numero, Nodo* padre) {
    if (arbol == NULL) {                                // El árbol está vacío
        Nodo* nuevo_nodo = crearNodo(numero, padre);
        arbol = nuevo_nodo;
    }
    else {                                              // El árbol tiene 1 nodo o más
        int valorRaiz = arbol->dato;                    // valor raíz

        if (numero < valorRaiz) {                       // si n es < a la raiz lo enviamos a la izq
            insertarNodo(arbol->izq, numero, arbol);
        }
        else {                                          // si es mayor lo enviamos a la derecha
            insertarNodo(arbol->der, numero, arbol);
        }
    }
}

void mostrarArbol(Nodo* arbol, int contador) {
    if (arbol == NULL) return;

    mostrarArbol(arbol->der, contador+1);

    for (int i = 0; i < contador; i++) {
        std::cout<< "   ";
    }

    std::cout<< arbol->dato << '\n';
    mostrarArbol(arbol->izq, contador+1);
}

bool buscarNodo(Nodo* arbol, int query) {
    if (arbol == NULL)                          // Si está vacío obviamente no está el nodo así que false
        return false;
    else if (arbol->dato == query)              // Si el nodo contiene el dato entonces lo encontramos, true
        return true;
    else if (query < arbol->dato)               // si la query es menor, buscará por la izquierda, pues está ordenado así.
        return buscarNodo(arbol->izq, query);
    else                                        // si aún no lo encuentra, busca por la derecha ahora :)
        return buscarNodo(arbol->der, query);
}

void recorrerArbolPreOrden(Nodo* arbol) {
    if (arbol == NULL) return;

    std::cout<< arbol->dato << " - ";

    recorrerArbolPreOrden(arbol->izq);          // Primero recorrer izquierda
    recorrerArbolPreOrden(arbol->der);          // Luego recorrer derecha
}

void recorrerArbolInOrden(Nodo* arbol) {
    if (arbol == NULL) return;

    recorrerArbolInOrden(arbol->izq);
    std::cout<< arbol->dato << " - ";
    recorrerArbolInOrden(arbol->der);
}

void recorrerArbolPostOrden(Nodo* arbol) {
    if (arbol == NULL) return;

    recorrerArbolInOrden(arbol->izq);
    recorrerArbolInOrden(arbol->der);

    std::cout<< arbol->dato << '\n';
}

void buscarYEliminar(Nodo* arbol, int numero) {
    if (arbol == NULL) 
        return;
    else if (numero < arbol->dato)
        buscarYEliminar(arbol->izq, numero);
    else if (numero > arbol->dato)
        buscarYEliminar(arbol->der, numero);
    else
        eliminarNodo(arbol);
}

void eliminarNodo(Nodo* nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der) { // si el nodo tiene parte izq y der (no son null)
        Nodo* menor = encontrarMinimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if (nodoEliminar->izq) { // tiene hijo izq almenos
        reemplazarNodo(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->der) { // tiene hijo derecho
        reemplazarNodo(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else {                        // Nodo Hoja
        reemplazarNodo(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

Nodo* encontrarMinimo(Nodo* arbol) {
    if (arbol == NULL) return NULL;
    
    if (arbol->izq) // izq no es null
        return encontrarMinimo(arbol->izq);
    else 
        return arbol;
}

void reemplazarNodo(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre) { // Si tiene padre
        if (arbol->dato == arbol->padre->izq->dato) {
            arbol->padre->izq = nuevoNodo;
        }
        else if (arbol->dato == arbol->padre->der->dato) {
            arbol->padre->der = nuevoNodo;
        }
    }

    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

void destruirNodo(Nodo* nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}

void menu() {
    float decimal;
    int dato, opcion, contador = 0;             // contador = 0 para que el árbol inicie desde la raíz

    do {
        std::cout<< "\t_.: MENU :._" << '\n';
        std::cout<< "1. Insertar nuevo nodo." << '\n';
        std::cout<< "2. Mostrar arbol." << '\n';
        std::cout<< "3. Buscar nodo." << '\n';
        std::cout<< "4. Recorrido en pre-orden." << '\n';
        std::cout<< "5. Recorrido en in-orden." << '\n';
        std::cout<< "6. Recorrido en post-orden." << '\n';
        std::cout<< "7. Eliminar nodo." << '\n';
        std::cout<< "8. Salir." << '\n';
        std::cout<< "\nOpcion: "; std::cin>> opcion;

        switch (opcion) {
            case 1: std::cout<< "\nDigite un numero para el nodo: ";
                    std::cin>> dato;
                    
                    if (arbol == NULL) 
                        std::cout<< "Raiz: " << dato << " Ingresada." << '\n';
                    else
                        std::cout<< "Nodo: " << dato << " Ingresado." << '\n';

                    decimal = dato;

                    if (decimal - dato) {
                        std::cout<< "Idiota no pongas decimales" << '\n';
                    }
                    
                    insertarNodo(arbol, dato, NULL);

                    system("pause");
                    break;
                
            case 2: std::cout<< "\nMostrando arbol completo\n\n";

                    mostrarArbol(arbol, 0);

                    std::cout<<'\n';
                    system("pause");
                    break;
            
            case 3: std::cout<< "\nDigite nodo a buscar:  "; 
                    std::cin>> dato;

                    if (buscarNodo(arbol, dato)) {
                        std::cout<< "Nodo con valor " << dato << " ha sido encontrado en el arbol!" << '\n';
                    }
                    else {
                        std::cout<< "Nodo con valor " << dato << " no existe." << '\n';
                    }

                    system("pause");
                    break;
                
            case 4: std::cout<< "Recorrido en pre-orden: ";
                    recorrerArbolPreOrden(arbol);
                    std::cout<< "\n\n";
                    system("pause");
                    break;

            case 5: std::cout<< "Recorrido en in-orden: ";
                    recorrerArbolInOrden(arbol);
                    std::cout<<"\n\n";
                    system("pause");
                    break;
            
            case 6: std::cout<< "Recorrido en post-orden:";
                    recorrerArbolPostOrden(arbol);
                    std::cout<<"\n\n";
                    system("pause");
                    break;

            case 7: std::cout<< "Digite nodo a eliminar: ";
                    std::cin>> dato;
                    buscarYEliminar(arbol, dato);
                    std::cout<<'\n';
                    system("pause");
                    break;
        }

        system("cls"); // clear stream, limpiar consola
        
    } while (opcion != 8);
}