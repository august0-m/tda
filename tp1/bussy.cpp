#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
//int T, N, S, E;  
//vector<int,int> p;
//vector<tuple<int,int>> p;
//vector<vector<tuple<int,int>>> o;
vector<vector<tuple<int,int>>> o;
//int contador=0;

//funcion recursiva que genera el output
void lafuncioneta( vector<vector<tuple<int, int>>> o){                                   //&& (get<1>(o[i][j]) < get<1> (o[i][j]))
    for (int i = 0 ;i< o.size();i++){
        int contador = 1 ;
        int el_min = get<1>(o[i][0]);
        for (int j = 1 ; j< o[i].size();j++){
           // int contador = 1 ;
            //int el_min = get<1>(o[i][0]);
            if ( ( el_min <= get<0>(o[i][j])) ){ //&& (get<1>(o[i][j]) < get<1> (o[i][j]))   )
            contador++;
            el_min = get<1>(o[i][j]);
             //cout << el_min ;
            }
            //else{
            //cout<< endl << "soy el min y no entre en el if" << el_min ;
            //}
        }
        // cout << "Caso " << i + 1 << ": Contador = " << contador << endl;
        cout << contador << endl;
       
}
}

//funcion para comparar las tuplas
bool compararlas(tuple<int, int> a, tuple<int, int> b) {
    if (get<1>(a) != get<1>(b)) {
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

int main (){
    int T, N, S, E;
  
    cin >> T;
//creo el vector de vectores
    o.resize(T);
    for (int i=0; i<T; i++) {
//ingreso a cada caso del test
    cin >> N;
        o[i].resize(N);
        for (int j=0 ; j<N ;j++){
//creo las tuplas
    cin >> S >> E;
         o [i][j]= make_tuple(S,E);
        }
//las ordeno, con mas importancia cuanto antes terminen
        sort(o[i].begin(),o[i].end(),compararlas);
    }
//veo si estoy ordenando bien
   //cout << "\nContenido del vector:\n";
   // for (int i = 0; i < o.size(); ++i) {
   //     for (int j =0 ; j< o[i].size();j++){
   //     cout << "Tupla " << i + 1 << ": "
   //         << get<0>(o[i][j]) << ", " << get<1>(o[i][j]) << endl;
   //     }
   // }
 lafuncioneta(o);
 return 0;
    
}

