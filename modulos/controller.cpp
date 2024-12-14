#include "controller.h"
#include <iostream>

using namespace std;

void Controller::Control_Owners(){
    Owners owners;
    int opcion;

    do{
        cout << "\nManejo de Archivos de Duenios:\n";
        cout << "1. Crear registro de duenio\n";
        cout << "2. Leer registro de duenio\n";
        cout << "3. Actualizar registro de duenio\n";
        cout << "4. Eliminar registro de duenio\n";
        cout << "5. Volver a Menu Principal\n\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:
            owners.Crear();
            break;
        case 2:
            owners.Leer();
            break;
        case 3:
            owners.Actualizar();
            break;
        case 4:
            owners.Eliminar();
            break;
        case 5:
            break;
        default:
            cout << "Opcion invalida \n";
        }
    } while (opcion != 5);
}

void Controller::Control_Pets(){
    Pets pets;
    int opcion;

    do{
        cout << "\nManejo de Archivos de Mascotas:\n";
        cout << "1. Crear registro de Mascota\n";
        cout << "2. Leer registro de Mascota\n";
        cout << "3. Actualizar registro de Mascota\n";
        cout << "4. Eliminar registro de Mascota\n";
        cout << "5. Volver a Menu Principal\n\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:
            pets.Crear();
            break;
        case 2:
            pets.Leer();
            break;
        case 3:
            pets.Actualizar();
            break;
        case 4:
            pets.Eliminar();
            break;
        case 5:
            break;
        default:
            cout << "Opcion invalida \n";
        }
    } while (opcion != 5);
}