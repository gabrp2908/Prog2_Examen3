#include "owners.h"

void Owners::Crear(){
    ofstream archivo("./bin/Owners.csv", ios::app);
    if (!archivo){
        cerr << "No se pudo abrir el archivo";
        return;
    }

    string nombre, apellido, cedula, correo, nombre_mascota, tipo_animal;
    cout << "\nIngrese Cedula: ";
    cin >> cedula;
    cout << "Ingrese Nombre del Duenio: ";
    cin >> nombre;
    cout << "Ingrese Apellido: ";
    cin >> apellido;
    cout << "Ingrese Correo: ";
    cin >> correo;
    cout << "Ingrese Nombre de Mascota: ";
    cin >> nombre_mascota;
    cout << "Ingrese Tipo de Animal: ";
    cin >> tipo_animal;

    archivo << cedula << ","<< nombre << "," << apellido << "," << correo << "," << nombre_mascota << "," << tipo_animal << "\n";
    archivo.close();
    cout << "Registro del duenio " << nombre << " " << apellido << " fue creado\n";
}

void Owners::Leer(){
    ifstream archivo("./bin/Owners.csv");
    if (!archivo){
        cerr << "No se pudo abrir el archivo";
        return;
    }

    string buscar_ci;
    cout << "\nIngrese la Cedula del registro que desea leer: ";
    cin >> buscar_ci;

    string line;
    bool found = false;
    while (getline(archivo, line)){
        size_t pos = line.find(",");
        if (line.substr(0, pos) == buscar_ci){
            found = true;
            cout << "\nRegistro encontrado: " << line << endl;
            break;
        }
    }

    if (!found){
        cout << "No se encontro el registro" << endl;
    }
    archivo.close();
}

void Owners::Actualizar(){
    ifstream archivo("./bin/Owners.csv");
    if (!archivo){
        cerr << "No se pudo abrir el archivo";
        return;
    }

    ofstream temparchivo("./bin/temp.csv");
    if (!temparchivo){
        cerr << "Error al crear archivo temporal";
        return;
    }

    string ci, buscar_ci;
    cout << "\nIngrese la cedula del registro a actualizar: ";
    cin >> buscar_ci;

    string line;
    bool found = false;
    while (getline(archivo, line)){
        size_t pos = line.find(",");
        if (line.substr(0, pos) == buscar_ci){
            found = true;
            string nombre, apellido, cedula, correo, nombre_mascota, tipo_animal;
            cout << "\nIngrese Nombre del duenio: ";
            cin >> nombre;
            cout << "Ingrese Apellido: ";
            cin >> apellido;
            cout << "Ingrese Correo: ";
            cin >> correo;
            cout << "Ingrese Nombre de Mascota: ";
            cin >> nombre_mascota;
            cout << "Ingrese Tipo de Animal: ";
            cin >> tipo_animal;

            temparchivo << buscar_ci << ","<< nombre << "," << apellido << "," << correo << "," << nombre_mascota << "," << tipo_animal << "\n";
            archivo.close();
        }
        else{
            temparchivo << line << "\n";
        }
    }

    archivo.close();
    temparchivo.close();

    if (!found){
        cout << "No se encontro el registro" << endl;
        remove("./bin/temp.csv");
        return;
    }

    remove("./bin/Owners.csv");
    rename("./bin/temp.csv", "./bin/Owners.csv");
    cout << "Registro del duenio fue actualizado" << endl;
}

void Owners::Eliminar(){
    ifstream archivo("./bin/Owners.csv");
    if (!archivo){
        cerr << "No se pudo abrir el archivo";
        return;
    }

    ofstream temparchivo("./bin/temp.csv");
    if (!temparchivo){
        cerr << "Error al crear archivo temporal";
        return;
    }

    string ci, buscar_ci;
    cout << "Ingrese la Cedula del registro a eliminar: ";
    cin >> buscar_ci;

    string line;
    bool found = false;
    while (getline(archivo, line)){
        size_t pos = line.find(",");
        if (line.substr(0, pos) == buscar_ci){
            found = true;
        }
        else{
            temparchivo << line << "\n";
        }
    }

    archivo.close();
    temparchivo.close();

    if (!found){
        cout << "No se encontro el registro" << endl;
        remove("./bin/temp.csv");
        return;
    }

    remove("./bin/Owners.csv");
    rename("./bin/temp.csv", "./bin/Owners.csv");
    cout << "Registro eliminado" << endl;
} 