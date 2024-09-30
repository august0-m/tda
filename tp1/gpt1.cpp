#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N;
vector<vector<int>> p;

pair<int, vector<int>> max_subsecuencia_creciente(int i, vector<int>& caso, int ult, vector<vector<pair<int, vector<int>>>>& sec_cre) {
    // Caso base: si llegamos al final del vector
    if (i >= caso.size()) return {0, {}};  // No hay subsecuencia posible

    // Memoización: si ya tenemos el resultado almacenado, lo devolvemos
    if (sec_cre[i][ult + 1].first != -1) return sec_cre[i][ult + 1];

    // Caso 1: no incluir el elemento actual en la subsecuencia
    auto sin_incluir = max_subsecuencia_creciente(i + 1, caso, ult, sec_cre);

    // Caso 2: incluir el elemento actual, si es válido (mayor que el último incluido)
    auto con_incluir = sin_incluir;  // Inicialmente, asumimos que no lo incluimos
    if (ult == -1 || caso[i] > caso[ult]) {  // Podemos incluir si es mayor que el último
        con_incluir = max_subsecuencia_creciente(i + 1, caso, i, sec_cre);
        con_incluir.first++;  // Aumentamos la longitud
        con_incluir.second.push_back(i);  // Añadimos la posición actual a la subsecuencia
    }

    // Guardamos el mejor resultado en la tabla de memoización
    if (sin_incluir.first >= con_incluir.first) {
        sec_cre[i][ult + 1] = sin_incluir;
    } else {
        sec_cre[i][ult + 1] = con_incluir;
    }

    // Devolvemos el resultado óptimo
    return sec_cre[i][ult + 1];
}


pair<int, vector<int>> max_subsecuencia_decreciente(int i, vector<int>& caso, int ult, vector<vector<pair<int, vector<int>>>>& sec_dec) {
    // Caso base: si llegamos al final del vector
    if (i >= caso.size()) return {0, {}};  // No hay subsecuencia posible

    // Memoización: si ya tenemos el resultado almacenado, lo devolvemos
    if (sec_dec[i][ult + 1].first != -1) return sec_dec[i][ult + 1];

    // Caso 1: no incluir el elemento actual en la subsecuencia
    auto sin_incluir = max_subsecuencia_decreciente(i + 1, caso, ult, sec_dec);

    // Caso 2: incluir el elemento actual, si es válido (menor que el último incluido)
    auto con_incluir = sin_incluir;  // Inicialmente, asumimos que no lo incluimos
    if (ult == -1 || caso[i] < caso[ult]) {  // Podemos incluir si es menor que el último
        con_incluir = max_subsecuencia_decreciente(i + 1, caso, i, sec_dec);
        con_incluir.first++;  // Aumentamos la longitud
        con_incluir.second.push_back(i);  // Añadimos la posición actual a la subsecuencia
    }

    // Guardamos el mejor resultado en la tabla de memoización
    if (sin_incluir.first >= con_incluir.first) {
        sec_dec[i][ult + 1] = sin_incluir;
    } else {
        sec_dec[i][ult + 1] = con_incluir;
    }

    // Devolvemos el resultado óptimo
    return sec_dec[i][ult + 1];
}



bool pertenezco(vector<int>  lista, int numero){
    for(int i =0 ; i<lista.size();i++){
        if (lista[i]==numero){
            return true;
        }
    }
    return false;
}
// Función que retorna un vector con los elementos que no pertenecen a ambos vectores
vector<int> vector_con_rta(const vector<int>& sec_cre, const vector<int>& sec_dec) {
    vector<int> respuesta;

    // Agrega las possicones de sec_cre que no están en sec_dec
    for (int i = 0; i < sec_cre.size(); i++) {
        if (pertenezco(sec_dec, sec_cre[i])) {
            respuesta.push_back(sec_cre[i]);
        }
    }
    return respuesta;
}

int main () {
    int contador= 0;
    // El while para cortar con el -1
    while(true) {
        cin >> T;
        if (T == -1) break;
        
        // Creo los vectores de longitud T y los meto en el vector "grande"
        p.push_back(vector<int>(T));
        
        // Meto los números en ese vector
        for (int i = 0; i < T; i++) {
            cin >> p[contador][i];
        }
        contador++;
    }
    
    // Ahora que ya tengo los casos creo un vector creciente y uno decreciente para cada caso
    for (int j = 0; j < p.size(); j++) {
        int a = p[j].size();
        
        // Vectores de memoización para crecientes y decrecientes
        vector<vector<pair<int, vector<int>>>> sec_dec(a, vector<pair<int, vector<int>>>(a + 1, {-1, {}}));
        vector<vector<pair<int, vector<int>>>> sec_cre(a, vector<pair<int, vector<int>>>(a + 1, {-1, {}}));

        // Calcular subsecuencia creciente y decreciente una sola vez
        auto resultado_creciente = max_subsecuencia_creciente(0, p[j], -1, sec_cre);
        auto resultado_decreciente = max_subsecuencia_decreciente(0, p[j], -1, sec_dec);
        
        int long_crec = resultado_creciente.first;
        vector<int> respuesta_creciente = resultado_creciente.second;
        
        int long_dec = resultado_decreciente.first;
        vector<int> respuesta_decreciente = resultado_decreciente.second;
        
        // Evitar contar toda la secuencia como creciente o decreciente
        if (long_crec == p[j].size()) {
            long_dec = 0;
        }
        if (long_dec == p[j].size()) {
            long_crec = 0;
        }
        vector<int> vect_rta = vector_con_rta(respuesta_creciente, respuesta_decreciente);
        int respuesta_final =vector_con_rta(respuesta_creciente, respuesta_decreciente).size();
        int rta_final = (p[j].size() - (long_crec + long_dec) );
        //Mostrar resultados
       cout << "Longitud decreciente: " << long_dec << endl;
       cout << "Longitud creciente: " << long_crec << endl;
       cout << "Respuesta final: " << rta_final << endl;
       cout << endl;
     // Imprimir los resultados
       cout << "Subsecuencia creciente: ";
       for (int num : respuesta_creciente) {
           cout << num << " ";
       }
       cout << endl;
       cout << "Subsecuencia decreciente: ";
       for (int num : respuesta_decreciente) {
           cout << num << " ";
       }
       cout << endl;
       cout << "los q tienen superposición: ";
       for (int num : vect_rta) {
           cout << num << " ";
       }
       cout << endl;
       cout << rta_final<<endl;
      
   }
    return 0;
    }

