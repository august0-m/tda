#include <iostream>
#include <vector>

using namespace std;
int T;

vector<vector<int>> p;

int max_subsecuencia_creciente(int i,vector<int> & caso, int ult,vector<vector<int>> & sec_cre) {  //reutilizo lo visto en clase cambiando parametros y adecuando las funciones
	if (i >= caso.size()) return 0;

	if (ult == -1 && sec_cre[i][caso.size()] != -1) return sec_cre[i][caso.size()];
	if (ult != -1 && sec_cre[i][ult] != -1) return sec_cre[i][ult];
    //si ya lo calcule lo devuelvo sino, lo calculo
	// Si ult es -1 no está definido su alto y decimos que es 0
	int ult_alto = 0;
	if (ult >= 0) ult_alto = caso[ult]; //si ult es -1, me quedo con ult alto, sino ult_alto va a ser el indice ult de caso
	
	//if (ult_alto >= caso[i]) return max_subsecuencia_creciente(i+1,caso, ult,sec_cre); //el caso[i] no forma parte de la subseq entonces avanzo
//
    int segundo_index = ult;
	if (segundo_index == -1) segundo_index = caso.size();
//
	//sec_cre[i][segundo_index] = max(max_subsecuencia_creciente(i+1,caso, ult,sec_cre), max_subsecuencia_creciente(i+1,caso, i,sec_cre) + 1); //aca cambio de q enevs de q sume el numero y me de el "ancho" que me de la long entonces sumo 1
	//return sec_cre[i][segundo_index];
    if (ult_alto >= caso[i]) {
    return max_subsecuencia_creciente(i + 1, caso, ult, sec_cre); // No se incluye caso[i], se avanza
    }

    sec_cre[i][segundo_index] = max(max_subsecuencia_creciente(i + 1, caso, ult, sec_cre),max_subsecuencia_creciente(i + 1, caso, i, sec_cre) + 1); // Se incluye caso[i]
    return sec_cre[i][segundo_index];
    }
int max_subsecuencia_decreciente(int i,vector<int> & caso, int ult,vector<vector<int>> & sec_dec) {
	if (i >= caso.size()) return 0;

	if (ult == -1 && sec_dec[i][caso.size()] != -1) return sec_dec[i][caso.size()];
	if (ult != -1 && sec_dec[i][ult] != -1) return sec_dec[i][ult];

	// Si ult es -1 no está definido su alto y decimos que es 0
	int ult_alto = 1000000; //esto seria el numero maximo q nos pueden pasar segun el test, entonces al ser el primer elem de la sec tengo q compararlo con lo mas grande q puedo tenr
	if (ult >= 0) ult_alto = caso[ult];
	//enves de > comparo por ser menor <
	if (ult_alto <= caso[i]) return max_subsecuencia_decreciente(i+1,caso, ult,sec_dec);

	int segundo_index = ult;
	if (segundo_index == -1) segundo_index = caso.size();

	sec_dec[i][segundo_index] = max(max_subsecuencia_decreciente(i+1,caso, ult,sec_dec), max_subsecuencia_decreciente(i+1,caso, i,sec_dec) + 1);
	return sec_dec[i][segundo_index];
}
int funcion_posta(int i,vector<int> & caso, int ult_decre, int ult_cre,vector<vector<int>> & sec_dec,vector<vector<int>> & sec_cre){ //la idea era ver q si lo agregaba para crec no lo agregaba para decre
    if (i >= caso.size()) return 0;

    if (ult_decre == -1 && sec_dec[i][caso.size()] != -1) return sec_dec[i][caso.size()];  //caso dec
	if (ult_decre != -1 && sec_dec[i][ult_decre] != -1) return sec_dec[i][ult_decre];

    if (ult_cre == -1 && sec_cre[i][caso.size()] != -1) return sec_cre[i][caso.size()];  //caso cre
	if (ult_cre != -1 && sec_cre[i][ult_cre] != -1) return sec_cre[i][ult_cre];

    int ult_dec = 1000000; //esto seria el numero maximo q nos pueden pasar segun el test, entonces al ser el primer elem de la sec tengo q compararlo con lo mas grande q puedo tenr
	if (ult_decre >= 0) ult_dec = caso[ult_decre];
//enves de > comparo por ser menor <
	if (ult_dec <= caso[i]) return funcion_posta(i+1,caso, ult_decre,ult_cre,sec_dec,sec_cre);

    int segundo_index_decre = ult_dec;
	if (segundo_index_decre == -1) segundo_index_decre = caso.size();

    sec_dec[i][segundo_index_decre] = max(funcion_posta(i+1,caso, ult_decre,ult_cre,sec_dec,sec_cre), funcion_posta(i+1,caso, i,ult_cre,sec_dec,sec_cre) + 1);
	return sec_dec[i][segundo_index_decre];

}
int main (){

    int contador= 0;
    //el while para cortar con el -1
    while(true){
        cin >> T;
        if(T==-1)   break;
    //creo los vectores de long t y los meto en vector "grande"
        p.push_back(vector<int>(T));
    //meto los numeros en ese vector, uso contador ya que no se cuantos test tengo
        for (int i=0; i<T; i++){
            cin >> p[contador][i];
        }
        contador++;
    }
    //ahora q ya tengo los casos creo un vector creciente y uno decreciente para cada caso
    for (int j =0; j< p.size(); j++){
        int a=0;
        a=p[j].size();
        vector<vector<int>> sec_cre(a,vector<int>(a+1, -1)) ;  //pongo el -1 para ver si chequee
        vector<vector<int>> sec_dec(a, vector<int>(a+1, -1));
        int long_crec =max_subsecuencia_creciente(0,p[j],-1,sec_cre);
        int long_dec =max_subsecuencia_decreciente(0,p[j],-1,sec_dec);
        //int long_dec =funcion_posta(0,p[j],-1,-1,sec_dec,sec_cre);
        if(long_crec== p[j].size() && (long_dec)== p[j].size()){
            long_dec =0;
        }
        if (long_crec == p[j].size()){
            long_dec = 0;
        }
        if (long_dec == p[j].size()){
            long_crec = 0;
        }
        cout <<p[j].size()-(long_crec + long_dec )<<endl;
    }
        return 0;
}   

