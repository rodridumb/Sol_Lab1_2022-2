// Matrices.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
const int N = 20;
const int M = 20;

using namespace std;

void create_board(int n, int m, char board[N][M]);
void show_board(int n, int m, char board[N][M]);
void search_word(int n, int m, char board[N][M], char word[]);
bool find(int n, int m, char board[N][M], char word[], int row, int col, int dir);

int main()
{
    int n, m;
    char board[N][M];
    char word[N];
    std::cout << "CRUCIGRAMA DE LPOO" << endl << "Ingrese las dimensiones del tablero[n, m] max. 20 y 20: ";
    cin >> n >> m;
    if (n < 1 || m < 1 || n>20 || m>20) {
        cout << "El tamano del tablero no debe exceder a 20.";
        return 0;
    }

    create_board(n, m, board);
    show_board(n, m, board);

    cout << "Ingrese la palabra a buscar: ";
    cin >> word;
    search_word(n, m, board, word);
}

void create_board(int n, int m, char board[N][M]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = 'A' + rand() % ('Z' - 'A');
}

void show_board(int n, int m, char board[N][M]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

void search_word(int n, int m, char board[N][M], char word[]) {
    int dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                dir = 1;
                if (find(n, m, board, word, i, j, dir++)) {
                    cout << "La palabra está en [" << i + 1 << "][" << j + 1 << "], dirección derecha";
                    return;
                }
                if (find(n, m, board, word, i, j, dir++)) {
                    cout << "La palabra está en [" << i + 1 << "][" << j + 1 << "], dirección abajo";
                    return;
                }
                if (find(n, m, board, word, i, j, dir++)) {
                    cout << "La palabra está en [" << i + 1 << "][" << j + 1 << "], dirección izquierda";
                    return;
                }
                if (find(n, m, board, word, i, j, dir++)) {
                    cout << "La palabra está en [" << i + 1 << "][" << j + 1 << "], dirección arriba";
                    return;
                }
            }
        }
    }
}

bool find(int n, int m, char board[N][M], char word[], int row, int col, int dir) {     
    int word_size;
    for (word_size = 0; word[word_size] != '\0'; word_size++);

    switch (dir) {
        case 1:
            for (int i = 1; i < word_size; i++) {
                if (word[i] != board[row][col + i])
                    return false;
            }
            return true;
            break;
        case 2:
            for (int i = 1; i < word_size; i++) {
                if (word[i] != board[row+i][col])
                    return false;
            }
            return true;
            break;
        case 3:
            for (int i = 1; i < word_size; i++) {
                if (word[i] != board[row][col - i])
                    return false;
            }
            return true;
            break;
        case 4:
            for (int i = 1; i < word_size; i++) {
                if (word[i] != board[row-i][col])
                    return false;
            }
            return true;
            break;
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
