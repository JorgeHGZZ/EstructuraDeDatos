#pragma once
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Medico {
public:
    string cedulaProfesional;
    string nombreCompleto;
    int numeroCincoDigitos;
    vector<string> horariosAtencion;
    string numeroTelefono;
    vector<string> diasAtencion;

    Medico(const string& cedula, const string& nombre, int numero, const vector<string>& horarios, const string& telefono, const vector<string>& dias)
        : cedulaProfesional(cedula), nombreCompleto(nombre), numeroCincoDigitos(numero), horariosAtencion(horarios), numeroTelefono(telefono), diasAtencion(dias) {
    }
};

class NodoMedico {
public:
    Medico medico;
    NodoMedico* izquierda;
    NodoMedico* derecha;

    NodoMedico(const Medico& med) : medico(med), izquierda(nullptr), derecha(nullptr) {
    }
};

class ArbolBinarioBusquedaMedicos {
private:
    NodoMedico* raiz;

    NodoMedico* insertarRecursivamente(NodoMedico* actual, const Medico& medico) {
        if (actual == nullptr) {
            return new NodoMedico(medico);
        }
        if (medico.cedulaProfesional < actual->medico.cedulaProfesional) {
            actual->izquierda = insertarRecursivamente(actual->izquierda, medico);
        }
        else {
            actual->derecha = insertarRecursivamente(actual->derecha, medico);
        }
        return actual;
    }

    NodoMedico* buscarRecursivamente(NodoMedico* actual, const std::string& cedula) {
        if (actual == nullptr || actual->medico.cedulaProfesional == cedula) {
            return actual;
        }
        if (cedula < actual->medico.cedulaProfesional) {
            return buscarRecursivamente(actual->izquierda, cedula);
        }
        return buscarRecursivamente(actual->derecha, cedula);
    }

    NodoMedico* encontrarMinimo(NodoMedico* nodo) {
        NodoMedico* actual = nodo;
        while (actual->izquierda != nullptr) {
            actual = actual->izquierda;
        }
        return actual;
    }

    NodoMedico* eliminarRecursivamente(NodoMedico* actual, const std::string& cedula) {
        if (actual == nullptr) {
            return actual;
        }
        if (cedula < actual->medico.cedulaProfesional) {
            actual->izquierda = eliminarRecursivamente(actual->izquierda, cedula);
        }
        else if (cedula > actual->medico.cedulaProfesional) {
            actual->derecha = eliminarRecursivamente(actual->derecha, cedula);
        }
        else {
            if (actual->izquierda == nullptr) {
                NodoMedico* temp = actual->derecha;
                delete actual;
                return temp;
            }
            else if (actual->derecha == nullptr) {
                NodoMedico* temp = actual->izquierda;
                delete actual;
                return temp;
            }
            NodoMedico* temp = encontrarMinimo(actual->derecha);
            actual->medico = temp->medico;
            actual->derecha = eliminarRecursivamente(actual->derecha, temp->medico.cedulaProfesional);
        }
        return actual;
    }

public:
    ArbolBinarioBusquedaMedicos() {
        raiz = nullptr;
    }

    void insertarMedico(const Medico& medico) {
        raiz = insertarRecursivamente(raiz, medico);
    }

    bool buscarMedico(const std::string& cedula) {
        return buscarRecursivamente(raiz, cedula) != nullptr;
    }

    void modificarMedico(const std::string& cedula, const Medico& nuevoMedico) {
        eliminarMedico(cedula);
        insertarMedico(nuevoMedico);
    }

    void eliminarMedico(const std::string& cedula) {
        raiz = eliminarRecursivamente(raiz, cedula);
    }
};

/*ArbolBinarioBusquedaMedicos arbolMedicos;

// Ejemplo de inserci�n de m�dicos
Medico medico1("12345", "Dr. Juan P�rez", 12345, { "Lunes 9-12", "Mi�rcoles 14-17" }, "555-12345", { "Lunes", "Mi�rcoles" });
Medico medico2("54321", "Dra. Mar�a Garc�a", 54321, { "Martes 10-13", "Jueves 15-18" }, "555-54321", { "Martes", "Jueves" });

arbolMedicos.insertarMedico(medico1);
arbolMedicos.insertarMedico(medico2);

// Ejemplo de b�squeda de un m�dico
if (arbolMedicos.buscarMedico("12345")) {
    std::cout << "El m�dico Dr. Juan P�rez se encuentra en el �rbol." << std::endl;
}
else {
    std::cout << "El m�dico Dr. Juan P�rez no se encuentra en el �rbol." << std::endl;
}

// Ejemplo de modificaci�n de un m�dico
Medico nuevoMedico1("12345", "Dr. Juan P�rez Modificado", 12345, { "Lunes 9-12", "Mi�rcoles 14-17", "Viernes 11-14" }, "555-12345", { "Lunes", "Mi�rcoles", "Viernes" });
arbolMedicos.modificarMedico("12345", nuevoMedico1);

if (arbolMedicos.buscarMedico("12345")) {
    std::cout << "El m�dico Dr. Juan P�rez se encuentra en el �rbol." << std::endl;
}
else {
    std::cout << "El m�dico Dr. Juan P�rez no se encuentra en el �rbol." << std::endl;
}

// Ejemplo de eliminaci�n de un m�dico
arbolMedicos.eliminarMedico("54321");

if (!arbolMedicos.buscarMedico("54321")) {
    std::cout << "El m�dico Dra. Mar�a Garc�a ha sido eliminado del �rbol." << std::endl;
}*/
