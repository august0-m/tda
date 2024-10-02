#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
#define MAXN 60005

using namespace std;
int T, N, C;
vector<tuple<int,vector<int>>> p;
double medio_maximo;

bool puedo_ponerlas(vector<int> posiciones,int distancia,int cant_vacas){
    int vacas_q_puse=1;//empiezo con una porq siempre pongo en la 1era posicion
    int iterador = posiciones[0]; //voy iterando en las posiciones
   // int contador = 0;//lo uso para avanzar "distancia" veces
    for(int i=0;i<posiciones.size();i++){ //accedo al vector
        if( posiciones[i]-iterador >= distancia){
            vacas_q_puse++; //puedo poner una vaca
            iterador=posiciones[i];
            //contador = contador + distancia; no servia de nada
            if (vacas_q_puse == cant_vacas){
                return true;
        }
        }
    }
    return false; //si no pude doy false

}

void funcionarda(vector<tuple<int,vector<int>>> p){ 
    for(int i = 0; i<p.size();i++){
//entro a los test //high es el elmento mas grande - el mas chico
        int low = 1;
        int high =(get<1>(p[i])[(get<1>(p[i]).size())-1])-(get<1>(p[i])[0]);
//veo si puedo poner todas las vacas cada "mid" vez con ciertos casos
        while(low<=high){
            int mid =((low + high) / 2);
            if (puedo_ponerlas(get<1>(p[i]),mid,get<0>(p[i]))){
//estoy en rango y todavia tengo vacas,
                medio_maximo = mid;
                low=mid+1;
            }
            if((puedo_ponerlas(get<1>(p[i]),mid,get<0>(p[i])))== false){
//me pase de rango y tengo vacas, bajo mid
                high=mid-1;
            }
        }
        cout <<medio_maximo << endl;
   }
}


//leo los inputs y los ordeno en vectores
int main (){

    cin >> T;
    p.resize(T);
    //creo vector de largo de los test y entro
    for (int i=0; i<T; i++){
    cin >> N >> C ;
    get<1>(p[i]).resize(N);
    //le doy el largo a cada caso y entro
     for (int j=0;j<N;j++){
        get<0>(p[i])=C;
        cin >> get<1>(p[i])[j];
     }
    sort(get<1>(p[i]).begin(),get<1>(p[i]).end());
    }

    funcionarda(p);
    return 0;
  
}