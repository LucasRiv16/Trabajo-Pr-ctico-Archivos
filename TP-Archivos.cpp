#include <iostream>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "membrete.h"
using namespace std;

limpiarpantalla(){
	system("cls");
}

void agregarMensaje(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::app); // Abre el archivo en modo añadir
    if (!archivo) {
    	limpiarpantalla();
        membrete();
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    char mensaje[100];
    limpiarpantalla();
    membrete();
    cout << "Ingrese un mensaje: ";
    cin.ignore(); // Ignorar entrada previa
    cin.getline(mensaje, 100); // Leer el mensaje

    archivo << mensaje << endl; // Escribir el mensaje en el archivo
    archivo.close();
    cout << "Mensaje guardado en el archivo." << endl;
}

void mostrarMensajes(const char* nombreArchivo) {
	
    ifstream archivo(nombreArchivo); // Abre el archivo en modo lectura
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    char mensaje[100];
    limpiarpantalla();
    membrete();
    cout << "Contenido del archivo:" << endl;
    while (archivo.getline(mensaje, 100)) { // Leer cada línea del archivo
        cout << mensaje << endl;
    getch();    
    }
    archivo.close();
}

void borrarContenido(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::trunc); // Abre el archivo en modo truncar (borra todo)
    if (!archivo) {
    	limpiarpantalla();
        membrete();
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    archivo.close(); // Cierra el archivo, ahora vacío
    limpiarpantalla();
    membrete();
    cout << "Todo el contenido del archivo ha sido borrado." << endl;
    getch();
}

int main() {
    setlocale(LC_ALL, ""); // Habilitar la localización para los acentos
    system("mode con: cols=80 lines=25");
    system("COLOR F1");	
    
    const char* nombreArchivo = "mensajes.txt"; // Nombre del archivo de texto
    int opcion;

    do {
    	limpiarpantalla();
        membrete();
        cout << "--- Menú ---" << endl; // 'Menú' con acento correctamente soportado
        cout << "1. Agregar mensaje" << endl;
        cout << "2. Mostrar mensajes" << endl;
        cout << "3. Borrar todo el contenido del archivo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: "; // 'Opción' con acento
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarMensaje(nombreArchivo);
                break;
            case 2:
                mostrarMensajes(nombreArchivo);
                break;
            case 3:
                borrarContenido(nombreArchivo);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }

    } while (opcion != 0);

    return 0;
}

