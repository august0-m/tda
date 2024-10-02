#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N;
vector<vector<vector<int>>> matriz;
vector<int> caso ;
//vector<vector<int>> p;
int funcion_principal(int iterador,int itera_creciente,int itera_decrecciente){
    //si llego al final entonces doy cero
    if (iterador == caso.size()) {
        return 0;
    } 
    // si ya calcule donde estoy, uso pd y no lo calculo devuelta, sino que devuelvo su valor
    if (matriz[iterador][itera_creciente + 1 ][itera_decrecciente + 1] != -1){
        return matriz[iterador][itera_creciente+1][itera_decrecciente+1];
    }
    //opcion en la que no voy a pintar el lugar porque no combiene que pertenezca a creciente ni decreciente
    int lo_dejo_asi = funcion_principal(iterador + 1, itera_creciente, itera_decrecciente);
    //opcion que pertene a secuencia creciente
    int pintar_negro = -1;
    if (itera_creciente == -1 || caso[iterador] > caso[itera_creciente]) {
        pintar_negro = 1 + funcion_principal(iterador + 1, iterador, itera_decrecciente);
    }
    //opcion que pertenece a la sec decreciente
    int pintar_blanco = -1;
    if (itera_decrecciente == -1 || caso[iterador] <caso[itera_decrecciente]) {
        pintar_blanco = 1 + funcion_principal(iterador+ 1,itera_creciente, iterador);
    }
    //ahora voy a ver cual es el que me combiene
    int resultado = max({lo_dejo_asi, pintar_negro, pintar_blanco});
    //int resultado = pintar_negro +pintar_blanco;
    //ultimo paso, guardo lo que encontre en la posicion de la matriz
     matriz[iterador][itera_creciente + 1 ][itera_decrecciente + 1 ] =  resultado;

    return resultado;
}

int main (){

    int contador= 0;
    //el while para cortar con el -1
    while(true){
        cin >> T;
        if(T==-1)   break;
  //creo los vectores de long t y los meto en vector "grande"
        //p.push_back(vector<int>(T));
        caso.resize(T);
    //meto los numeros en ese vector, uso contador ya que no se cuantos test tengo
        for (int i=0; i<T; i++){
            cin >> caso[i];
        }
        contador++;
         matriz = vector<vector<vector<int>>>(caso.size(), vector<vector<int>>(caso.size() + 1, vector<int>(caso.size() + 1, -1)));
        int resultado =funcion_principal(0,-1,-1);
        //cout << "longitud del caso"<<caso.size()<<endl;
        //cout << "resultado"<< resultado << endl;
        cout<<caso.size()- resultado <<endl;
        //cout << endl;
    }
    //ahora q ya tengo los casos, uso un for para ir analizandolos
    //for (int j = 0; j < caso.size(); j++) {
    //    int a = caso.size();
    //    // Llamamos a la función resolver_pintar para cada caso y mostramos el resultado
    //    matriz = vector<vector<vector<int>>>(caso.size(), vector<vector<int>>(caso.size() + 1, vector<int>(caso.size() + 1, -1)));
    //    int resultado =funcion_principal(0,0,0);
    //    cout << caso.size()-resultado << endl; 
    //    //cout<<"que esogfd" <<endl;
    //}

        return 0;
}   