#include <iostream>
#include<Windows.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include"ListasDobles.h"
#include"Pacientes.h"
#include<string>

using namespace std;
/*HINSTANCE GINST;

INT_PTR CALLBACK InicioDeSesion(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrev, PWSTR CmdLine, int CmdShow)
{
    GINST = hInst;
    HWND VentanaMain = CreateDialog(hInst, MAKEINTRESOURCE(9), NULL, InicioDeSesion);
	ShowWindow(VentanaMain, SW_SHOW);

	MSG msg = {};
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

INT_PTR InicioDeSesion(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return FALSE;
}*/


	
int main() {
	ListaDoblementeLigadaP ListaP;
	int opcion;
	do{
		cout << "1.-Agregar Paciente\n2.-Mostrar Pacientes\n3.-Buscar Paciente\n4.-Eliminar\n5.-Modificar\n6.-Salir\n==========================\n";
		cin >> opcion;
		switch (opcion)
		{
		case 1:;
			system("cls");
			cout << "Ingresa Nombre del paciente: " << endl;
			cin >> ax.nombrePaciente;
			cout << "Ingrese apellido del paciente: " << endl;
			cin >> ax.apellidoPaciente;
			cout << "Ingrese Telefono: " << endl;
			cin >> ax.telefonoPaciente;
			cout << "Referecina: " << endl;
			cin >> ax.referencia;
			cout << "Ingrese Edad: " << endl;
			cin >> ax.edadPaciente;
			cout<<"Primer Medico que lo antendio: " << endl;
			cin >> ax.primerMedico;
			ListaP.agregarALista(ax.nombrePaciente, ax.apellidoPaciente, ax.telefonoPaciente, ax.referencia, 030702, ax.edadPaciente, ax.primerMedico);
			break;
		case 2:
			ListaP.mostrarLista();
			system("PAUSE");
			break;
		case 3 :
			cout << "Ingresa Telefno del paciente: " << endl;
			cin >> ax.telefonoPaciente;
			ListaP.buscarPaciente(ax.telefonoPaciente);
			break;
		case 4:
			cout << "Ingresa Telefno del paciente: " << endl;
			cin >> ax.telefonoPaciente;
			ListaP.eliminarPaciente(ax.telefonoPaciente);
			break;
		case 5:
			cout << "Ingresa Telefno del paciente: " << endl;
			cin >> ax.telefonoPaciente;
			ListaP.modificarPaciente(ax.telefonoPaciente);
			break;
		}
	} while (opcion != 6);
	return 0;

}