#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> largo;
vector<int> alto;

int max_subsecuencia_creciente(int i, int ult) {
	if (i >= largo.size()) return 0;
	// Si ult es -1 no está definido su alto y decimos que es 0
	int ult_alto = 0;
	if (ult >= 0) ult_alto = alto[ult];
	
	if (ult_alto >= alto[i]) return max_subsecuencia_creciente(i+1, ult);

	return max(max_subsecuencia_creciente(i+1, ult), max_subsecuencia_creciente(i+1, i) + largo[i]);
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

	// Imprime la respuesta
	cout << max_subsecuencia_creciente(0, -1) << endl;
}
