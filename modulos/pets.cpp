#include "pets.h"

void Pets::Crear(){
    ofstream archivo("./bin/Pets.csv", ios::app);
    if (!archivo){
        cerr << "No se pudo abrir el archivo";
        return;
    }

    string id, nombre_mascota, tipo_animal, raza_animal, sexo;
    cout << "\nIngrese el ID de registro: ";
    cin >> id;
    cout << "Ingrese el Nombre de la Mascota: ";
    cin >> nombre_mascota;
    cout << "Ingrese el Tipo de Animal: ";
    cin >> tipo_animal;
    cout << "Ingrese la Raza del Animal: ";
    cin >> raza_animal;
    cout << "Ingrese Sexo (M/F): ";
    cin >> sexo;

    archivo << id << "," << nombre_mascota << "," << tipo_animal << "," << raza_animal << "," << sexo << "\n";
    archivo.close();
    cout << "Registro creado\n";
}

void Pets::Leer(){
    ifstream archivo("./bin/Pets.csv");

    if (!archivo){
        cerr << "No se pudo abrir el archivo";
        return;
    }

    string buscar_id;
    cout << "\nIngrese el ID del registro que desea leer: ";
    cin >> buscar_id;

    string line;
    bool found = false;
    while (getline(archivo, line)){
        size_t pos = line.find(",");
        if (line.substr(0, pos) == buscar_id) {
            found = true;
            cout << "\nRegistro encontrado: " << line << endl;
            break;
        cout << line << "\n";
        }
    }

    if(!found){
        cout << "No se encontro el registro" << endl;
    }
    archivo.close();

}

void Pets::Actualizar(){
    ifstream archivo("./bin/Pets.csv");
    if (!archivo){
        cerr << "No se pudo abrir el archivo";
        return;
    }

    ofstream temparchivo("temp.csv");
    if (!temparchivo){
        cerr << "Error al crear archivo temporal";
        return;
    }
    
    string id, buscar_id;
    cout << "\nIngrese el ID del registro que desea actualizar: ";
    cin >> buscar_id;

    string line;
    bool found = false;
    while (getline(archivo, line)){
        size_t pos = line.find(",");
        if (line.substr(0, pos) == buscar_id){
            found = true;
            string nombre_mascota, tipo_animal, raza_animal, sexo;
            cout << "\nIngrese el Nombre de la Mascota: ";
            cin >> nombre_mascota;
            cout << "Ingrese el Tipo de Animal: ";
            cin >> tipo_animal;
            cout << "Ingrese la Raza del Animal: ";
            cin >> raza_animal;
            cout << "Ingrese Sexo (M/F): ";
            cin >> sexo;
            temparchivo << buscar_id << "," << nombre_mascota << "," << tipo_animal << "," << raza_animal << "," << sexo << "\n";
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

    remove("./bin/Pets.csv");
    rename("temp.csv", "./bin/Pets.csv");
    cout << "Registro actualizado" << endl;
}

void Pets::Eliminar(){
    ifstream archivo("./bin/Pets.csv");
    if (!archivo){
        cerr << "No se pudo abrir el archivo";
        return;
    }

    ofstream temparchivo("temp.csv");
    if (!temparchivo){
        cerr << "Error al crear archivo temporal";
        return;
    }

    string id, buscar_id;
    cout << "\nIngrese el ID del registro que desea eliminar: ";
    cin >> buscar_id;

    string line;
    bool found = false;
    while (getline(archivo, line)){
        size_t pos = line.find(",");
        if (line.substr(0, pos) == buscar_id){
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
        remove("temp.csv");
        return;
    }

    remove("./bin/Pets.csv");
    rename("temp.csv", "./bin/Pets.csv");
    cout << "Registro eliminado" << endl;
}
