#include <iostream>
#include "Lista.h"

using namespace std;

template <class T>
typename Lista<T>::Iterador busca(const T &elem, const typename Lista<T>::Iterador &itInicio, const typename Lista<T>::Iterador &itFinal) {
    
    typename Lista<T>::Iterador it = itInicio;
    it.avanza();
    
    while ( it != itFinal && it.elem() != elem) {
        it.avanza();
    }
    
    return it;
}

template <class T>
typename Lista<T>::Iterador busca(const T &elem, Lista<T> &l) {
    return busca<T>(elem, l.principio(), l.final());
    
}

template<class T>
typename Lista<T>::Iterador borraIntervalo(Lista<T> &lista, typename Lista<T>::Iterador &itInicio, const typename Lista<T>::Iterador &itFinal) {
    
    while ( itInicio != itFinal) {
        try {
            itInicio = lista.borra(itInicio);
        } catch (EAccesoInvalido e) {
            cout << e.msg() << "Elemento actual del iterador nulo" << endl;
        }
    }
    
    return itInicio;
}

Lista<char> & borraOcurrenciasA(Lista<char> &lista) {
    
    Lista<char>::Iterador it = lista.principio();
    Lista<char>::Iterador itOcurrencia = busca('a', lista);;
    
    while ( it != lista.final() && it.elem() != ' ') {
        it.avanza();
    }
    
    it = borraIntervalo(lista, itOcurrencia, it);
    
    return lista;
}

int main (int argc, char** argv) {
    
    Lista<int> a;
    
    for (int i = 0; i < 11; i++) {
        a.ponDr(i);
    }
    
    Lista<int>::Iterador it = busca<int>(5, a);
    
    try {
        cout << it.elem() << endl;
    } catch (EAccesoInvalido e) {
        cout << e.msg() << "Acceso invalido" << endl;
    }
    
    it = busca<int>(11, a);
    
    try {
        cout << it.elem() << endl;
    } catch (EAccesoInvalido e) {
        cout << e.msg() << "Acceso invalido" << endl;
    }
    
    it = a.principio();
    
    // Con esto nos ponemos en el tercer elemento y el resultado de borrar será 0,1.
    it.avanza();
    it.avanza();
    
    it = borraIntervalo<int>(a, it, a.final());
    
    it = a.principio();
    
    while ( it != a.final() ) {
        try {
            std::cout << it.elem() << endl;
        } catch (EAccesoInvalido e) {
            std::cout << e.msg() << "Acceso invalido" << endl;
        }
        it.avanza();
    }
    
    Lista<char> b;
    
    char palabras[] = "Hola menda";
    int i = 0;
    
    while (i < strlen(palabras)) {
        b.ponDr(palabras[i]);
        
        i++;
    }
    
    b = borraOcurrenciasA(b);
    
    Lista<char>::Iterador itB = b.principio();
    
    while ( itB != b.final() ) {
        try {
            std::cout << itB.elem();
        } catch (EAccesoInvalido e) {
            std::cout << e.msg() << "Acceso invalido" << endl;
        }
        itB.avanza();
    }
    
    return 0;
}