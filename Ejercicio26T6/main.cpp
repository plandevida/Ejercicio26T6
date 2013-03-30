#include <iostream>
#include "Lista.h"

using namespace std;

template <class T>
typename Lista<T>::Iterador busca(const T &elem, Lista<T> &l) {
    return busca<T>(elem, l.principio(), l.final());
    
}

template <class T>
typename Lista<T>::Iterador busca(const T &elem, typename Lista<T>::Iterador &itInicio, typename Lista<T>::Iterador &itFinal) {
    
    itInicio.avanza();
    
    while ( itInicio != itFinal && itInicio.elem() != elem) {
        itInicio.avanza();
    }
    
    return itInicio;
}

template<class T>
typename Lista<T>::Iterador borraIntervalo(Lista<T> &lista, typename Lista<T>::Iterador &itInicio, typename Lista<T>::Iterador &itFinal) {
    
    while ( itInicio != itFinal) {
        lista.borra(itInicio);
        itInicio.avanza();
    }
    
    return itInicio;
}

Lista<char> & borraOcurrenciasA(Lista<char> &lista) {
    
    typename Lista<char>::Iterador it = lista.principio();
    
    
    while ( it != lista.final() && it.elem() != ' ') {
    
        it = busca('a', lista);
        
        it.avanza();
        
        it = borraIntervalo(lista, it, it);
    }
    
    return lista;
}

int main (int argc, char** argv) {
    
    Lista<int> a;
    
    for (int i = 0; i < 11; i++) {
        a.ponDr(i);
    }
    
    Lista<int>::Iterador it = busca<int>(a, 5);
    
    try {
        cout << it.elem() << endl;
    } catch (EAccesoInvalido e) {
        cout << e.msg() << "Acceso invalido" << endl;
    }
    
    it = busca<int>(a, 11);
    
    try {
        cout << it.elem() << endl;
    } catch (EAccesoInvalido e) {
        cout << e.msg() << "Acceso invalido" << endl;
    }
    
    it = a.principio();
    
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
    
    return 0;
}