#pragma once
#include<iostream>
#include"Pacientes.h"
using namespace std;

class ListaDoblementeLigada {
private:
	Paciente* inicio;
	Paciente* fin;
public:
	ListaDoblementeLigada() {
		inicio = NULL;
		fin = NULL;
	}
	void agregarALista(string _nombre, string _apellido, int _telefono, string _referencia, int _fechaDN, int _edad, string _primermedico) {
		Paciente* NuevoP = new Paciente(_nombre,_apellido,_telefono,_referencia,_fechaDN,_edad,_primermedico);
		/*NuevoP->setNombre(p1.getNombre());
		NuevoP->setApellido(p1.getApellido());
		NuevoP->setTelefono(p1.getTelefono());
		NuevoP->setReferencia(p1.getReferencia());
		NuevoP->setNacimiento(p1.getNacimiento());
		NuevoP->setEdad(p1.getEdad());
		NuevoP->setPrimerMedico(p1.getPrimerMedico());*/
		if (inicio == NULL) {
			inicio = NuevoP;
			fin = NuevoP;
			NuevoP->Ant = NULL;
			NuevoP->Sig = NULL;
		}
		else {
			NuevoP->Ant = fin;
			fin->Sig = NuevoP;
			fin = fin->Sig;
			fin->Sig = NULL;
		}
	}
	void MostrarInicioFIN() {
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
};