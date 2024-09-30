#include <iostream>
#include <vector>
//#include <algorithm>
#include <tuple>
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

tuple<int, vector<int>> max_subsecuencia_creciente(int i, vector<int>& caso, int ult, vector<vector<tuple<int, vector<int>>>>& sec_cre) {
    if (i >= caso.size()) return {0, {}}; 

    if (get<0>(sec_cre[i][ult + 1]) != -1) return sec_cre[i][ult + 1];
    tuple<int, vector<int>> sin_ult = max_subsecuencia_creciente(i + 1, caso, ult, sec_cre);

    tuple<int, vector<int>> con_ult = sin_ult; 
    if (ult == -1 || caso[i] > caso[ult]) { 
        con_ult = max_subsecuencia_creciente(i + 1, caso, i, sec_cre);
        get<0>(con_ult)++; //sumo long
        get<1>(con_ult).push_back(i); //agg la pos a la rta
    }

    if (get<0>(sin_ult) >= get<0>(con_ult)) {//en la matriz voy a guardar el mejor caso
        sec_cre[i][ult + 1] = sin_ult;
    } else {
        sec_cre[i][ult + 1] = con_ult;
    }
    return sec_cre[i][ult + 1];
}


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

//analogo para decreciente
tuple<int, vector<int>> max_subsecuencia_decreciente(int i, vector<int>& caso, int ult, vector<vector<tuple<int, vector<int>>>>& sec_dec) {
    if (i >= caso.size()) return {0, {}}; 
    if (get<0>(sec_dec[i][ult + 1]) != -1) return sec_dec[i][ult + 1];


   tuple<int, vector<int>> sin_ult = max_subsecuencia_decreciente(i + 1, caso, ult, sec_dec);

    tuple<int, vector<int>> con_ult = sin_ult; 
    if (ult == -1 || caso[i] < caso[ult]) { 
        con_ult = max_subsecuencia_decreciente(i + 1, caso, i, sec_dec);
        get<0>(con_ult)++; 
        get<1>(con_ult).push_back(i); 
    }

    if (get<0>(sin_ult)>= get<0>(con_ult)) {
        sec_dec[i][ult + 1] = sin_ult;
    } else {
        sec_dec[i][ult + 1] = con_ult;
    }
    return sec_dec[i][ult + 1];
}


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


bool pertenezco(vector<int> & lista, int numero){
    for(int i =0 ; i<lista.size();i++){
        if (lista[i]==numero){
            return true;
        }
    }
    return false;
}
int longitud_de_los_repetidos(vector<int> & sec_cre,vector<int> & sec_dec){
    int contador=0;

    for (int i= 0; i <sec_cre.size();i++){//voy a chequear si pertence a ambos la posicion
        if ((pertenezco(sec_dec,sec_cre[i]))==true){
            contador++;
        }
    }
    return contador;
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
        //vector<vector<vector<int>>> sec_cre(a, vector<vector<int>>(a + 1, vector<int>(-1))); 
        //vector<vector<vector<int>>> sec_dec(a, vector<vector<int>>(a + 1, vector<int>(-1)));
         vector<vector<tuple<int, vector<int>>>> sec_dec(a, vector<tuple<int, vector<int>>>(a + 1,make_tuple(-1, vector<int>())));
        vector<vector<tuple<int, vector<int>>>> sec_cre(a, vector<tuple<int, vector<int>>>(a + 1,make_tuple(-1, vector<int>())));

        int long_crec =get<0>(max_subsecuencia_creciente(0,p[j],-1,sec_cre));
        vector<int> respuesta_creciente = get<1>(max_subsecuencia_creciente(0,p[j],-1,sec_cre));
        int long_crec2 = get<1>(max_subsecuencia_creciente(0,p[j],-1,sec_cre)).size();
        int long_dec =get<0>(max_subsecuencia_decreciente(0,p[j],-1,sec_dec));
        vector<int> respuesta_decreciente = get<1>(max_subsecuencia_decreciente(0,p[j],-1,sec_cre));
        int long_dec2 = get<1>(max_subsecuencia_decreciente(0,p[j],-1,sec_cre)).size();
        int long_repetida= longitud_de_los_repetidos(respuesta_creciente ,respuesta_decreciente);
        if(long_crec== p[j].size() && (long_dec)== p[j].size()){
            long_dec =0;
        }
        if (long_crec == p[j].size()){
            long_dec = 0;
        }
        if (long_dec == p[j].size()){
            long_crec = 0;
        }
        //cout << p[j].size()-(long_crec+long_dec)-long_repetida<<endl;
        cout << "imprimo long del caso" << p[j].size() <<endl;
        cout << "imprimo la long decreciente"<<long_dec<<endl;
        cout << "imprimo la long decreciente version vector"<<long_dec2<<endl;
        cout << "imprimo la long creciente"<<long_crec<<endl;
        cout << "imprimo la long creciente version vector"<<long_crec2<<endl;
        cout << "imprimo long de rep"<<long_repetida<<endl; //es siempre 0 no se porque
        cout <<"a lo bestia"<<p[j].size()-(long_crec+long_dec)<<endl;
        cout <<"long de caso - longitud de los rep"<<p[j].size()-(long_repetida)<<endl;
        cout << endl;
       
}   
return 0;
}
         //    //para cada caso, busco la subseq mas larga, si es mas grande, actualizo su valor, sino no
        //    if(max_long_cre <= busco_sec_cre(l,p[j],sec_cre)){
        //        max_long_cre=busco_sec_cre(l,p[j],sec_cre);
        //    }
        //    if(max_long_dec <= busco_sec_dec(l,p[j],sec_dec)){
        //        max_long_dec= busco_sec_dec(l,p[j], sec_dec)
        //    }
//
        //}
       // cout << p.size()-(busco_sec_cre(0,p[j],sec_cre)-busco_sec_dec(0,p[j],sec_dec)) << endl;
       //if(((max_subsecuencia_creciente(0,p[j],-1,sec_cre))== p[j].size()) ||(max_subsecuencia_decreciente(0,p[j],-1,sec_dec) == p[j].size() )){
       //     return 0;
       //  }
//        cout <<p[j].size()-((max_subsecuencia_creciente(0,p[j],-1,sec_cre))+(max_subsecuencia_decreciente(0,p[j],-1,sec_dec)) )<<endl;
//       // cout<< max_subsecuencia_decreciente(0,p[j],-1,sec_dec)<<endl;
//    }
//        return 0;
//}   

