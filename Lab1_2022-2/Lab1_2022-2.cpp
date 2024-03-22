// Lab1_2022-2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
const int MAX = 16;

using namespace std;

void read_data(int *ptr_n, int coded_word_numbers[], char coded_word[]);
void show_decoded_word(int n, int coded_word_numbers[], char coded_word[]);
void sort(int n, int coded_word_numbers[], char coded_word[]);

int main()
{
    int n;
    int coded_word_numbers[MAX];
    char coded_word[MAX];

    read_data(&n, coded_word_numbers, coded_word);
    sort(n, coded_word_numbers, coded_word);
    show_decoded_word(n, coded_word_numbers, coded_word);
}

void read_data(int *ptr_n, int coded_word_numbers[], char coded_word[]) {
    cout << "Ingrese la cantidad de numeros de Fibonacci a leer: ";
    cin >> *ptr_n;
    for (int i = 0; i < *ptr_n; i++) {
        cin >> coded_word_numbers[i];
    }
    cin >> coded_word;
}

void sort(int n, int coded_word_numbers[], char coded_word[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coded_word_numbers[i] > coded_word_numbers[j]) {
                int temp = coded_word_numbers[i];
                coded_word_numbers[i] = coded_word_numbers[j];
                coded_word_numbers[j] = temp;
                char char_temp = coded_word[i];
                coded_word[i] = coded_word[j];
                coded_word[j] = char_temp;
            }
        }
    }
}

void show_decoded_word(int n, int coded_word_numbers[], char coded_word[]) {
    for (int i = 0; i < n; i++) {
        cout << coded_word_numbers[i] << " ";
    }
    cout << "\n";

    int fib1 = 1, fib2 = 2, fib3;

    cout << coded_word[0] << coded_word[1];

    for (int i = 2, j=2; i < n; i++) {
        fib3 = fib1 + fib2;
        if (coded_word_numbers[j] == fib3) {
            cout << coded_word[j];
            j++;
        }
        else {
            cout << " ";
            i--;
        }
        fib1 = fib2;
        fib2 = fib3;
    }
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
