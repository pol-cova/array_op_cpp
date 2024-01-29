//
// Created by Paul Contreras on 28/01/24.
//
//
// Ejercicio
/*
Un arreglo bidimensional de floats de 2x3
llenarlo de forma directa {{, ,},{, ,}} y
1.- detectar cual es el numero mayor almacenado en todo ese arreglo bidimensional (Mayor Bidimensional)
2.- Cual es el numero menor almacenado
3.- Que columna es la que suma menos
4.- que fila es la que suma mas
 */

// Importar libreria estandar
#include <iostream>
using namespace std;

// Prototipos de las funciones a usar
float array_max_val (float array[2][3]);
float array_min_val (float array[2][3]);
void display_array (float array[2][3]);
float array_min_col (float array[2][3]);
float array_max_row (float array[2][3]);




// array_max_val
//Esta funcion halla el elemento mas grande en el arreglo
float array_max_val (float array[2][3]){
    float max = array[0][0];
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
float array_min_val (float array[2][3]){
    float min = array[0][0];
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
void display_array (float array[2][3]){
    for (int i=0; i < 2; ++i){
        for (int j=0;  j<3; ++j){
            cout << "[" << array[i][j] << "]";
        }
        cout << endl;
    }
}
// Min col
// Esta funcion calcula la suma de cada columna y returna la menor
float array_min_col (float array[2][3]){
    int num_col;
    float sum, min_sum = numeric_limits<float>::max();

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

float array_max_row (float array[2][3]){
    int num_row;
    float sum, max_sum = -numeric_limits<float>::infinity();

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

int main(){
    // definimos el array bidimensional y agregamos sus valores
    float LocalArray[2][3] =
            {
                    {1,2,3},
                    {4,5,6},
            };
    // Definimos las variables para almacenar valores
    float ValMax = array_max_val(LocalArray), ValMin = array_min_val(LocalArray);
    float min_col = array_min_col(LocalArray), max_row = array_max_row(LocalArray);

    cout << "El arreglo actual es: " << endl;
    display_array(LocalArray);
    cout << "Valor Max del arreglo : " << ValMax << endl;
    cout << "Valor Min del arreglo: " << ValMin << endl;
    cout << "Columna con la suma menor: " << min_col << endl;
    cout << "Fila con la suma mayor: " << max_row << endl;



    return 0;
}