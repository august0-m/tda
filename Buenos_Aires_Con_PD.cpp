#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> largo;
vector<int> alto;

vector<vector<int>> M;

int max_subsecuencia_creciente(int i, int ult) {
	if (i >= largo.size()) return 0;

	if (ult == -1 && M[i][largo.size()] != -1) return M[i][largo.size()];
	if (ult != -1 && M[i][ult] != -1) return M[i][ult];

	// Si ult es -1 no está definido su alto y decimos que es 0
	int ult_alto = 0;
	if (ult >= 0) ult_alto = alto[ult];
	
	if (ult_alto >= alto[i]) return max_subsecuencia_creciente(i+1, ult);

	int segundo_index = ult;
	if (segundo_index == -1) segundo_index = largo.size();
	
	M[i][segundo_index] = max(max_subsecuencia_creciente(i+1, ult), max_subsecuencia_creciente(i+1, i) + largo[i]);
	return M[i][segundo_index];
}

int main() {
	// Primero lee cuántos edificios van a haber
	int n;
	cin >> n;

	// Después lee el largo de cada edificio
	largo = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> largo[i];

	// Después lee el alto de cada edificio
	alto = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> alto[i];

	// Crea la estructura de memoización
	// Los valores para (i, -1) se van a almacenar en M[i][n]
	// M[i][j] está indefinido si es -1
	M = vector<vector<int>>(n, vector<int>(n+1, -1));

	// Imprime la respuesta
	cout << max_subsecuencia_creciente(0, -1) << endl;
}
