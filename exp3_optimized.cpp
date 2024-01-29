//
// Created by Paul Contreras on 28/01/24.
//

#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    // Definimos un bool para un ejecutar en while la interaccion del usuario
    bool app = true;
    // Definimos el array bidimensional y agregamos sus valores
    float LocalArray[2][3] =
            {
                    {1,2,3},
                    {4,5,6},
            };
    // Variable para opcion de usuario
    char UserOpt;
    // llamamos funcion para obtener los datos del arreglo
    array_operations(LocalArray);
    // Preguntamos al user si quiere ingresar su propio arreglo
    cout << "Desea ingresar su propio arreglo y/n: ";
    // Leemos la opcion ingresada
    cin>>UserOpt;
    while (app) {
        // comparamos si es verdadera y llamamos la funcion para crear su arreglo, si no finaliza el programa
        if (UserOpt == 'y')
            user_array();
        else
            app = false;
    }


    return 0;
}
