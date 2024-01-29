//
// Created by Paul Contreras on 28/01/24.
//

#ifndef ARRAY_OP_CPP_FUNCTIONS_H
#define ARRAY_OP_CPP_FUNCTIONS_H

#include <iostream>
#include <limits>
using namespace std;
// Prototipos de las funciones a usar
float array_max_val (float (&array)[2][3]);
float array_min_val (float (&array)[2][3]);
void display_array (float (&array)[2][3]);
float array_min_col (float (&array)[2][3]);
float array_max_row (float (&array)[2][3]);
void user_array();
void array_operations(float (&array)[2][3]);

// array_max_val
//Esta funcion halla el elemento mas grande en el arreglo
float array_max_val (float (&array)[2][3]){
    // Definimos max como el primer elemento de array para compararlo
    float max = array[0][0];
    // 2 for loops para comprar cada valor con nuestro max y obtener el max
    for (int i=0; i < 2; ++i){
        for (int j=0;  j<3; ++j){
            if (array[i][j] > max)
                max = array[i][j];
        }
    }
    return max;
}
// array_min_val
// Esta funcion halla el elemento mas pequeno en el arreglo
float array_min_val (float (&array)[2][3]){
    // Definimos max como el primer elemento de array para compararlo
    float min = array[0][0];
    // 2 for loops para comprar cada valor con nuestro min y obtener el min
    for (int i=0; i < 2; ++i){
        for (int j=0;  j<3; ++j){
            if (array[i][j] < min)
                min = array[i][j];
        }
    }
    return min;
}
// Display array
// Esta funcion le muestra el arreglo al usuario
void display_array (float (&array)[2][3]){
    for (int i=0; i < 2; ++i){
        for (int j=0;  j<3; ++j){
            cout << "[" << array[i][j] << "]";
        }
        cout << endl;
    }
}
// Min col
// Esta funcion calcula la suma de cada columna y returna la menor
float array_min_col (float (&array)[2][3]){
    // Definimos una variable para almacenar el valor de la columna con la suma menor
    int num_col;
    // Definimos el acumulador de la suma, y una variable temporal con el limite max, para comparar
    /*
     * Esto para evitar errores con la suma y comparacion, es decir usar numeric_limits<float>::max(),
     * es una practica comun cuando no sabemos el valor con el que se compara
     */
    float sum, min_sum = numeric_limits<float>::max();
    /* Usamos 2 for loops anidados iniciando por las columnas, para obtener su suma almacenarla en una variable
     * temporal y en la seccion del if comparar con el valor minimo por default, is es el menor, la variable num_col
     * guardara el valor de la columna + 1 esto porque las columnas inician en 0, causando una confusion para el user
     * asi que al final la funcion returna el numero de la columna.
     */
    for (int j=0; j<3; ++j){
        sum = 0;
        for (int i=0; i<2; ++i){
            sum += array[i][j];
        }

        if (sum < min_sum){
            min_sum = sum;
            num_col = j+1;
        }
    }
    return num_col;
}
// Max row
// Esta funcion calcula la suma de cada fila y returna la mayor

float array_max_row (float (&array)[2][3]){
    // Definimos una variable para almacenar el valor de la fila con la suma mayor
    int num_row;
    // Definimos el acumulador de la suma, y una variable temporal con el limite infinit, para comparar
    /*
     * Esto para evitar errores con la suma y comparacion, es decir usar -numeric_limits<float>::infinity(,
     * Esta expresión se utiliza comúnmente para representar un valor muy
     * pequeño o un límite inferior en operaciones con números de punto flotante.
     */
    float sum, max_sum = -numeric_limits<float>::infinity();
    /* Usamos 2 for loops anidados iniciando por las columnas, para obtener su suma almacenarla en una variable
     * temporal y en la seccion del if comparar con el valor minimo por default, is es el mayor, la variable num_row
     * guardara el valor de la fila + 1 esto porque las filas inician en 0, causando una confusion para el user
     * asi que al final la funcion returna el numero de la fila.
     */
    for (int i=0; i<2; ++i){
        sum = 0;
        for (int j=0; j<3; ++j){
            sum += array[i][j];
        }

        if (max_sum < sum){
            max_sum = sum;
            num_row = i+1;
        }
    }
    return num_row;
}
// User array
/*
 * Esta funcion permite al usurio ingresar su propio arreglo 2x3 y obtener los datos antes calculados.
 */
void user_array(){
    float array[2][3];

    //Ciclo For anidado para capturar los datos
    for(int i=0; i<2; ++i){
        for(int j=0; j<3; ++j){
            // Mensaje para el usuario
            cout << "Ingresa un numero: ";
            // Leer numero
            cin >> array[i][j];
        }
    }
    // Imprimir datos resultantes
    cout << "Su arreglo es: " << endl;
    display_array(array);
    cout << endl;
    cout << "--------- Datos obtenidos del arreglo ---------" << endl;
    cout << "Valor Max del arreglo : " << array_max_val(array) << endl;
    cout << "Valor Min del arreglo: " << array_min_val(array) << endl;
    cout << "Columna con la suma menor: " << array_min_col(array) << endl;
    cout << "Fila con la suma mayor: " << array_max_row(array) << endl;
    cout << "-----------------------------------------------" << endl;

}

// array operations
/*
 * Esta funcion recibe como parametro el arreglo local y realiza todas las funciones definidas
 */
void array_operations(float (&array)[2][3]){
    // Imprimir datos resultantes
    cout << "Su arreglo es: " << endl;
    display_array(array);
    cout << endl;
    cout << "--------- Datos obtenidos del arreglo ---------" << endl;
    cout << "Valor Max del arreglo : " << array_max_val(array) << endl;
    cout << "Valor Min del arreglo: " << array_min_val(array) << endl;
    cout << "Columna con la suma menor: " << array_min_col(array) << endl;
    cout << "Fila con la suma mayor: " << array_max_row(array) << endl;
    cout << "-----------------------------------------------" << endl;
}

#endif //ARRAY_OP_CPP_FUNCTIONS_H
