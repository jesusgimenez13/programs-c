#include <iostream>
#include <vector>
using namespace std;

void menu(){
    cout << "1. Agregar nota"<<endl;
    cout << "2. Mostrar notas"<<endl;
    cout << "3. Mostrar promedio"<<endl;
    cout << "4. Mostrar mayor y menor"<<endl;
    cout << "5. Buscar nota"<<endl;
    cout << "6. Salir"<<endl;
}

void agnota(vector<int> &notas){
    int num;
    cout << "Ingrese la nota: "<<endl;
    cin >> num;
    notas.push_back(num);
}

void mosnota(vector<int> &notas){
    if(notas.empty()){
        cout << "No hay notas cargadas\n";
        return;
    }
    for (int i = 0; i < notas.size(); i++)
    {
        cout << notas[i] <<endl;
    }
    
}

void pronota(vector<int> &notas){
    if(notas.empty()){
        cout << "No hay notas cargadas\n";
        return;
    }
    float prom;
    int sum = 0;
    for (int i = 0; i < notas.size(); i++)
    {
        sum += notas[i];
    }

    prom = (float)sum / notas.size();

    cout << "El promedio de las notas es: "<< prom <<endl;
}

void mayme(vector<int> &notas){

    if(notas.empty()){
        cout << "No hay notas cargadas\n";
        return;
    }

    int mayor = notas[0];

    for (int i = 0; i < notas.size(); i++)
    {
        if (mayor < notas[i])
        {
            mayor = notas[i];
        }
    }
    int menor = mayor;
    
    for (int i = 0; i < notas.size(); i++)
    {
        if (menor > notas[i])
        {
            menor = notas[i];
        }
    }
    
    cout << "La nota mayor obtenida es: "<< mayor <<endl;
    cout << "La nota menor obtenida es: "<< menor <<endl;
}

void bunota(vector<int> &notas){
    if(notas.empty()){
        cout << "No hay notas cargadas\n";
        return;
    }
    int buscar;
    cout << "Que nota desea buscar: "<<endl;
    cin >> buscar;

    bool encontrado = false;

    for (int i = 0; i < notas.size(); i++)
    {
        if (buscar == notas[i])
        {
            cout << buscar << " Si se encontro en la lista!!" <<endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << buscar << " No se encontro en la lista!!" <<endl;
    }
}

int main(){

    vector<int> notas;
    int op;

cout << ".....Gestor de Notas....."<<endl;

while (1)
{
    menu();
    cout << "Ingrese una opcion: "<<endl;
    cin >> op;

    switch (op)
    {
    case 1:
        agnota(notas);
        break;
    case 2:
        mosnota(notas);
        break;
    case 3:
        pronota(notas);
        break;
    case 4:
        mayme(notas);
        break;
    case 5:
        bunota(notas);
        break;
    case 6:
        cout << "Saliendo, Gracias por usar :)" <<endl;
        return 0;
    default:
        cout << "Ingrese una opcion valida por favor!!" <<endl;
        break;
    }
}
    return 0;
}