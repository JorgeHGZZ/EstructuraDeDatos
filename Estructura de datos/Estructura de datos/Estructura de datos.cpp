#include <iostream>
#include<Windows.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include"ListasDobles.h"
#include"Pacientes.h"

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

struct paciente
{
	string nombrePaciente;
	string apellidoPaciente;
	long long telefonoPaciente;
	string referencia;
	int fechaDN;
	int edadPaciente;
	string primerMedico;
}ax;


	
int main() {
	ListaDoblementeLigada ListaP;
	int opcion;
	do{
		system("cls");
		cout << "1.- Agregar Paciente\n2.-Mostrar Pacientes\n3.-Eliminar Paciente\n4.-Salir\n==========================\n";
		cin >> opcion;
		switch (opcion)
		{
		case 1:;
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
			ListaP.agregarALista(ax.nombrePaciente, ax.apellidoPaciente, ax.telefonoPaciente, ax.referencia, 1208013, ax.edadPaciente, ax.primerMedico);
			cout << "Aniadido con exito" << endl;
			system("cls");
			break;
		case 2:
			ListaP.MostrarInicioFIN();
			system("PAUSE");
			break;
		}
	} while (opcion != 4);



}