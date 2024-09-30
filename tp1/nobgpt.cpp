#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N;
vector<vector<int>> p;

//int max_subsecuencia_creciente(int i,vector<int> & caso, int ult,vector<vector<int>> & sec_cre) {  //reutilizo lo visto en clase cambiando parametros y adecuando las funciones
//	if (i >= caso.size()) return 0;
//
//	if (ult == -1 && sec_cre[i][caso.size()] != -1) return sec_cre[i][caso.size()];
//	if (ult != -1 && sec_cre[i][ult] != -1) return sec_cre[i][ult];
//
//	// Si ult es -1 no está definido su alto y decimos que es 0
//	int ult_alto = 0;
//	if (ult >= 0) ult_alto = caso[ult];
//	
//	if (ult_alto >= caso[i]) return max_subsecuencia_creciente(i+1,caso, ult,sec_cre);
//
//	int segundo_index = ult;
//	if (segundo_index == -1) segundo_index = caso.size();
//
//	sec_cre[i][segundo_index] = max(max_subsecuencia_creciente(i+1,caso, ult,sec_cre), max_subsecuencia_creciente(i+1,caso, i,sec_cre) + 1); //aca cambio de q enevs de q sume el numero y me de el "ancho" que me de la long entonces sumo 1
//	return sec_cre[i][segundo_index];
//}

//pair<int, vector<int>> max_subsecuencia_creciente(int i,vector<int> & caso, int ult,vector<vector<pair<int, vector<int>>>>& sec_cre) {  //reutilizo lo visto en clase cambiando parametros y adecuando las funciones
//	if (i >= caso.size()) return {0, {}};
//
//	if (ult == -1 && sec_cre[i][caso.size()].first != -1) return sec_cre[i][caso.size()];
//    if (ult != -1 && sec_cre[i][ult].first != -1) return sec_cre[i][ult];
//
//	// Si ult es -1 no está definido su alto y decimos que es 0
//	int ult_alto = 0;
//	if (ult >= 0) ult_alto = caso[ult];
//	
//	if (ult_alto >= caso[i]) return max_subsecuencia_creciente(i+1,caso, ult,sec_cre);
//
//	int segundo_index = ult;
//	if (segundo_index == -1) segundo_index = caso.size();
//    pair<int, vector<int>> sin_incluir = max_subsecuencia_creciente(i + 1, caso, ult, sec_cre);
//    pair<int, vector<int>>  con_incluir = max_subsecuencia_creciente(i + 1, caso, i, sec_cre);
//    con_incluir.first++; // Aumenta la longitud al incluir el elemento actual
//    con_incluir.second.push_back(caso[i]); // Almacena el elemento actual en la subsecuencia
//	sec_cre[i][segundo_index].first = max(sin_incluir.first, con_incluir.first); //aca cambio de q enevs de q sume el numero y me de el "ancho" que me de la long entonces sumo 1
//	return sec_cre[i][segundo_index];
//}
pair<int, vector<int>> max_subsecuencia_creciente(int i, vector<int>& caso, int ult, vector<vector<pair<int, vector<int>>>>& sec_cre) {
    // Caso base: si llegamos al final del vector
    if (i >= caso.size()) return {0, {}}; // No hay subsecuencia posible

    // Memoización: si ya tenemos el resultado almacenado, lo devolvemos
    if (sec_cre[i][ult + 1].first != -1) return sec_cre[i][ult + 1];

    // Caso 1: no incluir el elemento actual en la subsecuencia
    auto sin_incluir = max_subsecuencia_creciente(i + 1, caso, ult, sec_cre);

    // Caso 2: incluir el elemento actual, si es válido (mayor que el último incluido)
    auto con_incluir = sin_incluir; // Inicialmente, asumimos que no lo incluimos
    if (ult == -1 || caso[i] > caso[ult]) { // Podemos incluir si es mayor que el último
        con_incluir = max_subsecuencia_creciente(i + 1, caso, i, sec_cre);
        con_incluir.first++; // Aumentamos la longitud
        con_incluir.second.push_back(i); // Añadimos el valor actual a la subsecuencia
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
//pair<int, vector<int>> max_subsecuencia_decreciente(int i,vector<int> & caso, int ult,vector<vector<pair<int, vector<int>>>>& sec_dec) {
//	if (i >= caso.size()) return {0, {}};
//
//	if (ult == -1 && sec_dec[i][caso.size()].first != -1) return sec_dec[i][caso.size()];
//	if (ult != -1 && sec_dec[i][ult].first != -1) return sec_dec[i][ult];
//
//	// Si ult es -1 no está definido su alto y decimos que es 0
//	int ult_alto = 1000000; //esto seria el numero maximo q nos pueden pasar segun el test, entonces al ser el primer elem de la sec tengo q compararlo con lo mas grande q puedo tenr
//	if (ult >= 0) ult_alto = caso[ult];
//	//enves de > comparo por ser menor <
//	if (ult_alto <= caso[i]) return max_subsecuencia_decreciente(i+1,caso, ult,sec_dec);
//
//	int segundo_index = ult;
//	if (segundo_index == -1) segundo_index = caso.size();
//    pair<int, vector<int>> sin_incluir = max_subsecuencia_decreciente(i + 1, caso, ult, sec_dec);
//    pair<int, vector<int>>  con_incluir = max_subsecuencia_decreciente(i + 1, caso, i, sec_dec);
//    con_incluir.first++; // Aumenta la longitud al incluir el elemento actual
//    con_incluir.second.push_back(caso[i]); // Almacena el elemento actual en la subsecuencia
//	sec_dec[i][segundo_index].first = max(sin_incluir.first, con_incluir.first); //aca cambio de q enevs de q sume el numero y me de el "ancho" que me de la long entonces sumo 1
//	return sec_dec[i][segundo_index];
//	//sec_dec[i][segundo_index].first = max(max_subsecuencia_decreciente(i+1,caso, ult,sec_dec).first, max_subsecuencia_decreciente(i+1,caso, i,sec_dec).first + 1);
//	//return sec_dec[i][segundo_index];
//}
pair<int, vector<int>> max_subsecuencia_decreciente(int i, vector<int>& caso, int ult, vector<vector<pair<int, vector<int>>>>& sec_dec) {
    // Caso base: si llegamos al final del vector
    if (i >= caso.size()) return {0, {}}; // No hay subsecuencia posible

    // Memoización: si ya tenemos el resultado almacenado, lo devolvemos
    if (sec_dec[i][ult + 1].first != -1) return sec_dec[i][ult + 1];

    // Caso 1: no incluir el elemento actual en la subsecuencia
    auto sin_incluir = max_subsecuencia_decreciente(i + 1, caso, ult, sec_dec);

    // Caso 2: incluir el elemento actual, si es válido (menor que el último incluido)
    auto con_incluir = sin_incluir; // Inicialmente, asumimos que no lo incluimos
    if (ult == -1 || caso[i] < caso[ult]) { // Podemos incluir si es menor que el último
        con_incluir = max_subsecuencia_decreciente(i + 1, caso, i, sec_dec);
        con_incluir.first++; // Aumentamos la longitud
        con_incluir.second.push_back(i); // Añadimos el valor del indice a la subsecuencia
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

//pair<int, vector<int>> max_subsecuencia_decreciente(int i, vector<int>& caso, int ult, vector<vector<pair<int, vector<int>>>>& sec_dec) {
//    // Verifica si has llegado al final del vector caso
//    if (i >= caso.size()) return {0, {}}; // Devuelve longitud 0 y subsecuencia vacía
//
//    // Verifica si el resultado ya está calculado
//    if (ult == -1 && sec_dec[i][caso.size()].first != -1) return sec_dec[i][caso.size()];
//    if (ult != -1 && sec_dec[i][ult].first != -1) return sec_dec[i][ult];
//
//    // Define el último elemento considerado. Inicialmente, lo definimos como un valor muy alto para permitir que cualquier valor sea menor.
//    int ult_alto = 1000000; // Número suficientemente grande para que cualquier primer elemento sea considerado válido
//    if (ult >= 0) ult_alto = caso[ult];
//
//    // Si el último elemento es menor o igual al actual, no podemos incluirlo en la subsecuencia decreciente
//    if (ult_alto <= caso[i]) {
//        return max_subsecuencia_decreciente(i + 1, caso, ult, sec_dec);
//    }
//
//    // Almacena el índice del último elemento considerado
//    int segundo_index = (ult == -1) ? caso.size() : ult;
//
//    // Calcula las dos opciones: incluir o no incluir el elemento actual
//    auto sin_incluir = max_subsecuencia_decreciente(i + 1, caso, ult, sec_dec);
//    auto con_incluir = max_subsecuencia_decreciente(i + 1, caso, i, sec_dec);
//
//    con_incluir.first++; // Aumenta la longitud al incluir el elemento actual
//    con_incluir.second.push_back(caso[i]); // Almacena el elemento actual en la subsecuencia
//
//    // Almacena el mejor resultado en sec_dec
//    if (sin_incluir.first >= con_incluir.first) {
//        sec_dec[i][segundo_index] = sin_incluir; // Almacena la opción sin incluir
//        return sin_incluir; // Devuelve sin incluir
//    } else {
//        sec_dec[i][segundo_index] = con_incluir; // Almacena la opción incluyendo
//        return con_incluir; // Devuelve incluyendo
//    }
//}
//pair<int, vector<int>> max_subsecuencia_creciente(int i, vector<int>& caso, int ult, vector<vector<pair<int, vector<int>>>& sec_cre) {
//    // Verifica si has llegado al final del vector caso
//    if (i >= caso.size()) return {0, {}}; // Devuelve longitud 0 y subsecuencia vacía
//
//    // Verifica si el resultado ya está calculado
//    if (ult == -1 && sec_cre[i][caso.size()].first != -1) return sec_cre[i][caso.size()];
//    if (ult != -1 && sec_cre[i][ult].first != -1) return sec_cre[i][ult];
//
//    // Define el último elemento considerado
//    int ult_alto = (ult >= 0) ? caso[ult] : 0;
//
//    // Si el último elemento es mayor o igual que el actual, no podemos incluirlo en la subsecuencia creciente
//    if (ult_alto >= caso[i]) {
//        return max_subsecuencia_creciente(i + 1, caso, ult, sec_cre);
//    }
//
//    // Almacena el índice del último elemento considerado
//    int segundo_index = (ult == -1) ? caso.size() : ult;
//
//    // Calcula las dos opciones: incluir o no incluir el elemento actual
//    auto sin_incluir = max_subsecuencia_creciente(i + 1, caso, ult, sec_cre);
//    auto con_incluir = max_subsecuencia_creciente(i + 1, caso, i, sec_cre);
//    con_incluir.first++; // Aumenta la longitud al incluir el elemento actual
//    con_incluir.second.push_back(caso[i]); // Almacena el elemento actual en la subsecuencia
//
//    // Almacena el mejor resultado en sec_cre
//    if (sin_incluir.first >= con_incluir.first) {
//        sec_cre[i][segundo_index] = sin_incluir; // Almacena la opción sin incluir
//        return sin_incluir; // Devuelve sin incluir
//    } else {
//        sec_cre[i][segundo_index] = con_incluir; // Almacena la opción incluyendo
//        return con_incluir; // Devuelve incluyendo
//    }
//}

//int max_subsecuencia_decreciente(int i,vector<int> & caso, int ult,vector<vector<vector<int>>> & sec_dec) {
//	if (i >= caso.size()) return 0;
//
//	if (ult == -1 && sec_dec[i][caso.size()] != -1) return sec_dec[i][caso.size()];
//	if (ult != -1 && sec_dec[i][ult] != -1) return sec_dec[i][ult];
//
//	// Si ult es -1 no está definido su alto y decimos que es 0
//	int ult_alto = 1000000; //esto seria el numero maximo q nos pueden pasar segun el test, entonces al ser el primer elem de la sec tengo q compararlo con lo mas grande q puedo tenr
//	if (ult >= 0) ult_alto = caso[ult];
//	//enves de > comparo por ser menor <
//	if (ult_alto <= caso[i]) return max_subsecuencia_decreciente(i+1,caso, ult,sec_dec);
//
//	int segundo_index = ult;
//	if (segundo_index == -1) segundo_index = caso.size();
//
//	sec_dec[i][segundo_index] = max(max_subsecuencia_decreciente(i+1,caso, ult,sec_dec), max_subsecuencia_decreciente(i+1,caso, i,sec_dec) + 1);
//	return sec_dec[i][segundo_index];
//}

//tuple<int,int> busca_las_secuencias(int iterador,vector<int> & caso,int ult_creciente,int ult_decreciente,vector<vector<int>> & matriz_creciente,vector<vector<int>> & matriz_decreciente){
//    int longitud_creciente = 0;
//    int longitud_decreciente = 0;
//    tuple<int,int> respuesta = {longitud_creciente,longitud_decreciente};
//
//    if (iterador>=caso.size())return {0,0};
//    
//    if (ult_decreciente == -1 && matriz_decreciente[iterador][caso.size()] != -1) return matriz_decreciente[iterador][caso.size()];
//	if (ult_decreciente != -1 && matriz_decreciente[iterador][ult_decreciente] != -1) return matriz_decreciente[iterador][ult];
//    
//}

//vector<int> vector_con_rta(vector<int> & sec_cre,vector<int> & sec_dec){
//    vector<int> respuesta;
//
//    for (int i= 0; i <sec_cre.size();i++){
//        if (pertenezco(sec_dec,sec_cre[i])==false){
//            respuesta.push_back(sec_cre[i]);
//        }
//    }
//    for (int i= 0; i <sec_dec.size();i++){
//        if (pertenezco(sec_cre,sec_dec[i])==false){
//            respuesta.push_back(sec_dec[i]);
//        }
//    }
//    return respuesta;
//}

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

    // Agrega los elementos de sec_cre que no están en sec_dec
    for (int i = 0; i < sec_cre.size(); i++) {
        if (pertenezco(sec_dec, sec_cre[i])) {
            respuesta.push_back(sec_cre[i]);
        }
    }

    // Agrega los elementos de sec_dec que no están en sec_cre
    for (int i = 0; i < sec_dec.size(); i++) {
        if (pertenezco(sec_cre, sec_dec[i])) {
            respuesta.push_back(sec_dec[i]);
        }
    }

    return respuesta;
}
//int main (){
//
//    int contador= 0;
//    //el while para cortar con el -1
//    while(true){
//        cin >> T;
//        if(T==-1)   break;
//    //creo los vectores de long t y los meto en vector "grande"
//        p.push_back(vector<int>(T));
//    //meto los numeros en ese vector, uso contador ya que no se cuantos test tengo
//        for (int i=0; i<T; i++){
//            cin >> p[contador][i];
//        }
//        contador++;
//    }
//    //ahora q ya tengo los casos creo un vector creciente y uno decreciente para cada caso
//    for (int j =0; j< p.size(); j++){
//        int a=0;
//        a=p[j].size();
//        //vector<vector<vector<int>>> sec_cre(a, vector<vector<int>>(a + 1, vector<int>(-1))); 
//        //vector<vector<vector<int>>> sec_dec(a, vector<vector<int>>(a + 1, vector<int>(-1)));
//        vector<vector<pair<int, vector<int>>>> sec_dec(a, vector<pair<int, vector<int>>>(a + 1, {-1, {}}));
//        vector<vector<pair<int, vector<int>>>> sec_cre(a, vector<pair<int, vector<int>>>(a + 1, {-1, {}}));
//
//        int long_crec =max_subsecuencia_creciente(0,p[j],-1,sec_cre).first;
//        vector<int> respuesta_creciente = max_subsecuencia_creciente(0,p[j],-1,sec_cre).second;
//        int long_crec2 = max_subsecuencia_creciente(0,p[j],-1,sec_cre).second.size();
//        int long_dec =max_subsecuencia_decreciente(0,p[j],-1,sec_dec).first;
//        vector<int> respuesta_decreciente = max_subsecuencia_decreciente(0,p[j],-1,sec_cre).second;
//        int long_dec2 = max_subsecuencia_decreciente(0,p[j],-1,sec_cre).second.size();
//        int respuesta_final= vector_con_rta(respuesta_creciente ,respuesta_decreciente).size();
//        if(long_crec== p[j].size() && (long_dec)== p[j].size()){
//            long_dec =0;
//        }
//        if (long_crec == p[j].size()){
//            long_dec = 0;
//        }
//        if (long_dec == p[j].size()){
//            long_crec = 0;
//        }
//        //cout << respuesta_final <<endl;
//        //cout << p[j].size()-(long_crec+long_dec)-(respuesta_final)<<endl;
//        //cout << respuesta_final <<endl
//        //cout << "imprimo long del caso" << p[j].size() <<endl;
//        cout << "imprimo la long decreciente"<<long_dec<<endl;
//        cout << "imprimo la long decreciente version vector"<<long_dec2<<endl;
//        cout << "imprimo la long creciente"<<long_crec<<endl;
//        cout << "imprimo la long creciente version vector"<<long_crec2<<endl;
//        cout <<endl;
//        //cout << "imprimo la rta final"<<respuesta_final<<endl; //es siempre 0 no se porque
//        //cout <<"a lo bestia"<<p[j].size()-(long_crec+long_dec)<<endl;
//        //cout <<"con func:"<<p[j].size()-(respuesta_final)<<endl;
//        //cout << endl;
//    }
//        return 0;
//}   
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
        
        int respuesta_final =vector_con_rta(respuesta_creciente, respuesta_decreciente).size();
        int rta_final = p[j].size() - (long_crec + long_dec) - respuesta_final;
        // Mostrar resultados
        cout << "Longitud decreciente: " << long_dec << endl;
        cout << "Longitud creciente: " << long_crec << endl;
        cout << "Respuesta final: " << rta_final << endl;
        cout << endl;
    }
    return 0;
}

