#pragma once
 #include <iostream>

using namespace std;

class User {
private:
	int Id;
	string Nombre;
	string contrasenia;
public:
	User* ant;
	User* sig;
	User() {}
	int getId() { return Id; }
	void setId(int _ID) {Id = _ID;}
	string getNombre() { return Nombre; }
	void setNombre(string _nombre) { Nombre = _nombre;}
	string getContra() { return contrasenia; }
	void setContra(string _Contra) { contrasenia = _Contra; }
};