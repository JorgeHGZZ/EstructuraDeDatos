#pragma once
#include<string>

using namespace std;

class Paciente {
private:
	string nombrePaciente;
	string apellidoPaciente;
	long long telefonoPaciente;
	string referencia;
	int fechaDN;
	int edadPaciente;
	string primerMedico;
public:
	Paciente* Sig= NULL;
	Paciente* Ant = NULL;
	//Constructor
	Paciente() {}
	Paciente(string _nombre, string _apellido, long long _telefono, string _referencia, int _fechaDN, int _edad, string _primermedico) {
		nombrePaciente = _nombre;
		apellidoPaciente = _apellido;
		telefonoPaciente = _telefono;
		referencia = _referencia;
		fechaDN = _fechaDN;
		edadPaciente = _edad;
		primerMedico = _primermedico;
		//Algun Metodo como "escribir en archivo o algo asi"
	}
	string getNombre(){return nombrePaciente;}
	string getApellido(){return apellidoPaciente;}
	long long getTelefono(){return telefonoPaciente;}
	string getReferencia(){return referencia;}
	int getNacimiento() { return fechaDN; }
	int getEdad() { return edadPaciente; }
	string getPrimerMedico() { return primerMedico; }
	
	void setNombre(string _nombre) {nombrePaciente = _nombre;}
	void setApellido(string _apellido) { apellidoPaciente = _apellido; }
	void setTelefono(long long _telefono) { telefonoPaciente = _telefono; }
	void setReferencia(string _referencia) { referencia = _referencia; }
	void setNacimiento(int _nacimiento) { fechaDN = _nacimiento; }
	void setEdad(int _edad) { edadPaciente = _edad; }
	void setPrimerMedico(string _primerMedico) { primerMedico = _primerMedico; }

	 //Metodos
	
};
