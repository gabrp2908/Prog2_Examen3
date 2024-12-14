#include "view.h"

void View::run(){
    Controller controller;
    int choice;

    do{
        cout << "\nMenu Principal:\n";
        cout << "1. Manejo de Archivos de Duenios\n";
        cout << "2. Manejo de Archivos de Mascotas\n";
        cout << "3. Salir del programa\n\n";
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch (choice){
        case 1:
            controller.Control_Owners();
            break;
        case 2:
            controller.Control_Pets();
            break;
        case 3:
            cout << "Saliendo del programa\n";
            break;
        default:
            cout << "Opcion invalida\n";
        }
    } while (choice != 3);
}