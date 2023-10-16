#pragma once
#include <iostream>
#include "Pacientes.h"
#include "Usuarios.h"

using namespace std;

struct paciente {
    string nombrePaciente;
    string apellidoPaciente;
    long long telefonoPaciente;
    string referencia;
    int fechaDN;
    int edadPaciente;
    string primerMedico;
}ax;

class ListaDoblementeLigadaP {
private:
    Paciente* inicio;
    Paciente* fin;

public:
    ListaDoblementeLigadaP() { inicio = NULL; fin = NULL; }
    void agregarALista(string nombre, string apellido, long long telefono, string referencia, int fechaDN, int edad, string primerMedico) {
        Paciente* nuevoPaciente = new Paciente(nombre, apellido, telefono, referencia, fechaDN, edad, primerMedico);
        if (inicio == NULL) {
            inicio = nuevoPaciente;
            fin = nuevoPaciente;
            nuevoPaciente->Ant = NULL;
            nuevoPaciente->Sig = NULL;
            cout << "Aniadido con exito" << endl;
        }
        else {
            nuevoPaciente->Ant = fin;
            fin->Sig = nuevoPaciente;
            fin = fin->Sig;
            fin->Sig = NULL;
            cout << "Aniadido con exito" << endl;
        }
    }
    void mostrarLista() {
        int i = 1;
        Paciente* auxiliarP = inicio;
        while (auxiliarP != NULL) {
            cout << "Paciente No: " << i << endl;
            cout << auxiliarP->getNombre() << endl;
            cout << auxiliarP->getApellido() << endl;
            cout << auxiliarP->getTelefono() << endl;
            cout << auxiliarP->getReferencia() << endl;
            cout << auxiliarP->getNacimiento() << endl;
            cout << auxiliarP->getEdad() << endl;
            cout << auxiliarP->getPrimerMedico() << endl;
            cout << "=================================" << endl;

            auxiliarP = auxiliarP->Sig;
            i++;
        }
    }
    Paciente* buscarPaciente(long long telefono) {
        Paciente* auxiliarP = inicio;

        while (auxiliarP != NULL && auxiliarP->getTelefono() != telefono) {
            auxiliarP = auxiliarP->Sig;
        }
        if (auxiliarP != NULL) {
            cout << "Dato encontrado\n";
            cout << auxiliarP->getNombre() << endl;
            cout << auxiliarP->getApellido() << endl;
            cout << auxiliarP->getTelefono() << endl;
            cout << auxiliarP->getReferencia() << endl;
            cout << auxiliarP->getNacimiento() << endl;
            cout << auxiliarP->getEdad() << endl;
            cout << auxiliarP->getPrimerMedico() << endl;
        }
        else {
            cout << "NO SE ENCUENTRA EL PACIENTE\n";
        }
        return auxiliarP;
    }
    void modificarPaciente(long long telefono) {
        Paciente* auxP = inicio;
        while (auxP != NULL && auxP->getTelefono() != telefono) {
            auxP = auxP->Sig;
        }
        if (auxP != NULL) {
            string nombre, apellido, referencia, primerMedico;
            long long nuevoTelefono;
            int edad;

            cout << "Ingresa Nombre del paciente: " << endl;
            cin >> nombre;
            cout << "Ingrese apellido del paciente: " << endl;
            cin >> apellido;
            cout << "Ingrese Telefono: " << endl;
            cin >> nuevoTelefono;
            cout << "Referencia: " << endl;
            cin >> referencia;
            cout << "Ingrese Edad: " << endl;
            cin >> edad;
            cout << "Primer Medico que lo atendió: " << endl;
            cin >> primerMedico;

            auxP->setNombre(nombre);
            auxP->setApellido(apellido);
            auxP->setTelefono(nuevoTelefono);
            auxP->setReferencia(referencia);
            auxP->setEdad(edad);
            auxP->setPrimerMedico(primerMedico);
        }
    }
    void eliminarPaciente(long long telefono) {
        Paciente* auxiliarP = buscarPaciente(telefono);
        if (auxiliarP == inicio) {
            if (auxiliarP->Sig == NULL) {
                delete inicio;
                inicio = inicio->Sig;
            }
            else {
                inicio = auxiliarP->Sig;
                auxiliarP->Sig->Ant = NULL;
                delete auxiliarP;
            }
        }
        else {
            if (auxiliarP->Sig == NULL) {
                auxiliarP->Ant->Sig = NULL;
                delete auxiliarP;
            }
            else {
                auxiliarP->Ant->Sig = auxiliarP->Sig;
                auxiliarP->Sig->Ant = auxiliarP->Ant;
                delete auxiliarP;
            }
        }
    }
    Paciente* leerListaDobleDesdeArchivo(string nombreArchivo) {
        ifstream archivo(nombreArchivo);
        Paciente* cabeza = NULL;
        Paciente* prev = NULL;
        if (archivo.is_open()) {
            string nombre, apellido, referencia, medico;
            long long telefono;
            int fecha, edad;
            while (archivo >> nombre >> apellido >> telefono >> referencia >> fecha >> edad >> medico) {
                Paciente* nuevoPaciente = new Paciente(nombre, apellido, telefono, referencia, fecha, edad, medico);
                if (cabeza == NULL) {
                    cabeza = nuevoPaciente;
                }
                if (prev != NULL) {
                    prev->Sig = nuevoPaciente;
                    nuevoPaciente->Ant = prev;
                }
                prev = nuevoPaciente;
            }
            archivo.close();
            cout << "Lista de pacientes leída desde el archivo." << std::endl;
        }
        else {
            cerr << "No se pudo abrir el archivo." << std::endl;
        }
        return cabeza;
    }
    void guardarListaDobleEnArchivo(Paciente* cabeza,string nombreArchivo) {
        std::ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            Paciente* actual = cabeza;
            while (actual != NULL) {
                archivo << actual->getNombre() << " ";
                actual = actual->Sig;
            }
            archivo.close();
            cout << "Lista guardada en el archivo." << std::endl;
        }
        else {
            cerr << "No se pudo abrir el archivo." << std::endl;
        }
    }
};


class ListaDoblementeLigadaUsuarios {
private:
	User* inicio;
	User* fin;
public:
	ListaDoblementeLigadaUsuarios() {
		inicio = NULL;
		fin = NULL;
	}
	void agregarALaLista(int _Id, string _nombre, string _contra) {
		User * NuevoU = new User;
		if (inicio == NULL) {
			inicio = NuevoU;
			fin = NuevoU;
			NuevoU->ant = NULL;
			NuevoU->sig = NULL;
		}
		else {
			NuevoU->ant = fin;
			fin->sig = NuevoU;
			fin = fin->sig;
			fin->sig = NULL;
		}
	}
};