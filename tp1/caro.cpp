#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<vector<int>>> memo;

// Función recursiva que calcula el número mínimo de elementos a pintar
int resolver_pintar(int i, int negro, int blanco, const vector<int>& secuencia) {
    if (i == secuencia.size()) return 0; // Caso base: Si llegamos al final de la secuencia

    // Si ya hemos calculado este estado, devolvemos el valor almacenado
    if (memo[i][negro + 1][blanco + 1] != -1) return memo[i][negro + 1][blanco + 1];

    // No pintar el elemento actual
    int no_pintar = resolver_pintar(i + 1, negro, blanco, secuencia);

    // Pintar de negro si es posible
    int pintar_negro = INT_MAX;
    if (negro == -1 || secuencia[i] < secuencia[negro]) {
        pintar_negro = 1 + resolver_pintar(i + 1, i, blanco, secuencia);
    }

    // Pintar de blanco si es posible
    int pintar_blanco = INT_MAX;
    if (blanco == -1 || secuencia[i] > secuencia[blanco]) {
        pintar_blanco = 1 + resolver_pintar(i + 1, negro, i, secuencia);
    }

    // Elegimos la opción mínima entre no pintar, pintar de negro o pintar de blanco
    int resultado = min({no_pintar, pintar_negro, pintar_blanco});

    // Guardamos el resultado en el memo
    memo[i][negro + 1][blanco + 1] = resultado;

    return resultado;
}

int resolver_pintar(const vector<int>& secuencia) {
    int n = secuencia.size();
    memo = vector<vector<vector<int>>>(n, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
    return resolver_pintar(0, -1, -1, secuencia);
}

int main() {
    int contador = 0;
    vector<vector<int>> p; // Vector "grande" que contendrá los vectores de cada caso
    int T;
    
    // Bucle para leer los casos de prueba
    while (true) {
        cin >> T;
        if (T == -1) break;  // Condición para terminar la entrada de datos
        
        // Creo un vector de longitud T y lo añado a "p"
        p.push_back(vector<int>(T));
        
        // Relleno ese vector con los valores leídos desde la entrada
        for (int i = 0; i < T; i++) {
            cin >> p[contador][i];
        }
        contador++;
    }
    
    // Ahora que ya tenemos los casos, ejecutamos la función para cada caso
    for (int j = 0; j < p.size(); j++) {
        int a = p[j].size();
        
        // Llamamos a la función resolver_pintar para cada caso y mostramos el resultado
        int resultado = resolver_pintar(p[j]);
        
        // Mostramos el resultado para el caso actual
        cout << "Caso #" << j + 1 << ": " << resultado << endl;
    }

    return 0;
}
