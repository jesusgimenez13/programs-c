#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Persona
{
    string nombre;
    int edad;
};

void agregarPersona(vector<Persona> &personas){
    Persona p;

    cout << "Nombre: ";
    getline(cin, p.nombre);

    cout << "Edad: ";
    cin >> p.edad;
    cin.ignore();

    personas.push_back(p);
}

void mostrarPersonas(vector<Persona> &personas){

    if(personas.empty()){
        cout << "No hay personas\n";
        return;
    }

    for(int i = 0; i < personas.size(); i++){
        cout << personas[i].nombre << " - " << personas[i].edad << endl;
    }
}

void mayorPersona(vector<Persona> &personas){

    if(personas.empty()){
        cout << "No hay datos\n";
        return;
    }

    int posMayor = 0;

    for(int i = 1; i < personas.size(); i++){
        if(personas[i].edad > personas[posMayor].edad){
            posMayor = i;
        }
    }

    cout << "Mayor: " 
        << personas[posMayor].nombre 
        << " (" << personas[posMayor].edad << ")" << endl;
}

void buscarPersona(vector<Persona> &personas){

    string nombre;
    cout << "Ingrese nombre a buscar: ";
    getline(cin, nombre);

    bool encontrado = false;

    for(int i = 0; i < personas.size(); i++){
        if(personas[i].nombre == nombre){
            cout << "Encontrado: "
                << personas[i].nombre << " - "
                << personas[i].edad << endl;

            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        cout << "No encontrado\n";
    }
}

void menorPersona(vector<Persona> &personas){
    if (personas.empty())
    {
        cout << "No hay datos\n";
    }

    int menor = personas[0].edad;

    for (int i = 0; i < personas.size(); i++)
    {
        if (personas[i].edad < menor)
        {
            menor = i;
        }
        
    }
    cout << "menor: " << personas[menor].nombre << " (" << personas[menor].edad << ")" <<endl;
}

void eliminarPersona(vector<Persona> &personas){
    if (personas.empty())
    {
        cout << "No hay datos\n";
        return;
    }
    string eliminar;
    cout << "Ingrese el nombre: ";
    getline(cin,eliminar);
    int Advertencia;

    bool encontrado = false;

    for (int i = 0; i < personas.size(); i++)
    {
        if (personas[i].nombre == eliminar)
        {
            cout << "Encontrado: " << personas[i].nombre << " - " << personas[i].edad <<endl;
            cout << "Seguro que quieres eliminar?\n1.Si\n2.No\n";
            cin >> Advertencia;
            cin.ignore();

            if (Advertencia == 1)
            {
                personas.erase(personas.begin() + i);
                cout << "Eliminado correctamente!!" <<endl;
                encontrado = true;
                break;
            }else
            {
                cout << "cancelando"<<endl;
                break;
            }
        }
        
        if (!encontrado)
        {
            cout << "No encontrado\n";
        }
    }
}

void modificarEdad(vector<Persona> &personas){
    if (personas.empty())
    {
        cout << "No hay datos\n";
        return;
    }
    
    string editar;
    cout << "Ingrese el nombre para editar su edad: ";
    getline(cin,editar);
    int nuevaedad;

    bool encontrado = false;

    for (int i = 0; i < personas.size(); i++)
    {
        if (personas[i].nombre == editar)
        {
            cout << "Encontrado: " << personas[i].nombre << " - " << personas[i].edad <<endl;
            cout << "Ingrese la nueva edad: ";
            cin >> nuevaedad;
            personas[i].edad = nuevaedad;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        {
            cout << "No se encontro ese nombre!!";
            return;
        }

}

int main(){

    vector<Persona> personas;
    int op;

    while(true){
        cout << "\n1. Agregar\n2. Mostrar\n3. Mayor\n4. Buscar\n5.menor\n6.eliminar\n7.editar edad\n8. Salir\n";
        cin >> op;
        cin.ignore();

        switch(op){
            case 1:
                agregarPersona(personas);
                break;
            case 2:
                mostrarPersonas(personas);
                break;
            case 3:
                mayorPersona(personas);
                break;
            case 4:
                buscarPersona(personas);
                break;
            case 5:
                menorPersona(personas);
                break;
            case 6:
                eliminarPersona(personas);
                break;
            case 7:
                modificarEdad(personas);
                break;
            case 8:
                return 0;
        }
    }
}