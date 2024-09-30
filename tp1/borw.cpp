#include <iostream>
#include <vector>


using namespace std;
int T, N;
vector<vector<int>> p;


int max_subsecuencia_creciente(int i,vector<int> & caso, int ult,vector<vector<int>> & sec_cre) {  //reutilizo lo de la clase 
	if (i >= caso.size()) return 0;

	if (ult == -1 && sec_cre[i][caso.size()] != -1) return sec_cre[i][caso.size()];
	if (ult != -1 && sec_cre[i][ult] != -1) return sec_cre[i][ult];

	// Si ult es -1 no está definido su alto y decimos que es 0
	int ult_alto = 0;
	if (ult >= 0) ult_alto = caso[ult];
	
	if (ult_alto >= caso[i]) return max_subsecuencia_creciente(i+1,caso, ult,sec_cre);

	int segundo_index = ult;
	if (segundo_index == -1) segundo_index = caso.size();

	sec_cre[i][segundo_index] = max(max_subsecuencia_creciente(i+1,caso, ult,sec_cre), max_subsecuencia_creciente(i+1,caso, i,sec_cre) + 1); //aca cambio de q enevs de q sume el numero y me de el "ancho" que me de la long entonces sumo 1
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


segun estas instrucciones
You have a sequence of integers. You can paint each of the integers black or white, or leave it unpainted. The black integers must appear in ascending order and the white integers must appear in descending order. The ascending/descending order must be strict, that is, two integers painted with the same color cannot be equal. Paint the sequence so as to minimize the number of unpainted integers.

Input
The input contains several test cases, each one described in exactly two lines. The first line contains an integer N indicating the number of elements in the sequence (1 ≤ N ≤ 200). The second line contains N integers Xi separated by single spaces, representing the sequence to paint (1 ≤ Xi ≤ 106 for 1 ≤ i ≤ N ). The last line of the input contains a single −1 and should not be processed as a test case.
pude hacer esto:
#include <iostream>
#include <vector>


using namespace std;
int T, N;
vector<vector<int>> p;


int max_subsecuencia_creciente(int i,vector<int> & caso, int ult,vector<vector<int>> & sec_cre) {  //reutilizo lo de la clase 
	if (i >= caso.size()) return 0;

	if (ult == -1 && sec_cre[i][caso.size()] != -1) return sec_cre[i][caso.size()];
	if (ult != -1 && sec_cre[i][ult] != -1) return sec_cre[i][ult];

	// Si ult es -1 no está definido su alto y decimos que es 0
	int ult_alto = 0;
	if (ult >= 0) ult_alto = caso[ult];
	
	if (ult_alto >= caso[i]) return max_subsecuencia_creciente(i+1,caso, ult,sec_cre);

	int segundo_index = ult;
	if (segundo_index == -1) segundo_index = caso.size();

	sec_cre[i][segundo_index] = max(max_subsecuencia_creciente(i+1,caso, ult,sec_cre), max_subsecuencia_creciente(i+1,caso, i,sec_cre) + 1); //aca cambio de q enevs de q sume el numero y me de el "ancho" que me de la long entonces sumo 1
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
pero falla en algunos casos
QUIERO QUE con estos inputs:
0
1
1
4
5 5 5 5
5
1 2 3 4 5
5
5 4 3 2 1
7
1 3 2 4 6 5 7
6
1 1 2 2 3 3
8
10 5 8 3 7 9 2 6
30
128 93 113 133 37 168 176 32 57 181 49 143 43 106 56 60 91 15 161 56 25 42 63 129 39 32 1 187 57 178
30
69 84 164 36 4 7 172 189 14 135 3 54 25 69 145 79 166 176 30 104 91 45 183 109 29 98 137 120 80 18
30
80 45 50 90 199 95 43 52 35 133 182 71 194 164 26 59 111 178 75 47 58 104 23 38 18 72 138 21 2 9
30
22 118 192 54 98 148 88 170 159 184 196 127 131 45 81 54 144 170 178 75 126 180 117 153 189 113 31 42 47 198
30
9 26 129 95 39 43 191 135 119 173 127 151 102 147 19 76 81 34 93 194 98 58 171 33 102 61 119 170 47 189
30
142 39 190 62 114 77 98 134 1 73 188 155 47 174 151 14 25 25 17 45 101 200 94 173 7 26 148 51 39 142
30
131 102 75 124 182 74 86 139 18 145 32 124 52 133 77 23 137 38 123 52 42 48 93 162 195 53 30 37 168 103
30
46 119 107 119 147 112 2 137 85 79 74 149 103 117 19 162 186 81 84 41 44 33 55 168 175 69 61 172 2 21
30
23 22 12 56 56 167 52 80 34 191 46 48 35 144 82 144 200 198 183 125 199 175 162 99 157 159 190 128 35 3
30
45 14 33 97 124 31 20 172 45 199 112 149 110 96 65 115 154 142 93 155 142 184 156 43 18 98 50 153 183 100
-1
retorne esto:
 0
0
2
0
0
1
2
1
14
14
15
12
12
15
16
14
13
14
pero, retorna esto:
0
0
2
0
0
0
2
1
14
14
14
11
11
14
15
14
12
14
Es decir a veces cuenta un numero de mas en "long_dec + lond_crec"
solucionalo
tomate tu tiempo para pensarlo y no me des algo que no lo solucione, y que la solucion no rompa los casos en donde si funciona 