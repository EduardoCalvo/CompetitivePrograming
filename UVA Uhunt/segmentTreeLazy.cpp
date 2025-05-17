//EduardoCalvoMartinez 
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

string operator* (string str, int n){ 
    string result; 
    for (int i = 0; i < n; i++) result += str; 
    return result;
}

vi cast (const string &str){
    vi result;
    for (int i = 0; i < int(str.size()); i++){
        result.push_back(int(str[i]) - 48);
    }

    return result;
}

class LazySegment {
    int n;
    vi ini;
    vector <pair<int,int> > ST; 
    
    int left(int i){return i<<1;}//Funcion para obtener el hijo izquierdo de un nodo

    int right(int i){return (i<<1) + 1;}//Funcion para obtener el hijo derecho de un nodo
    
    void build(int p, int L, int R){//Construir el segment tree
        if (L == R){
            if (ini[L] == 1) ST[p].first++;
            ST[p].second = 0;
        }  //Caso base, sumamos uno a la cantidad de unos si el valor es uno
        else {
            build(left(p), L , (L+R) >> 1);//Construimos el lado izquierdo
            build(right(p), ((L+R)>>1) + 1, R);//Construimos el lado derecho 
            int p1 = ST[left(p)].first, p2 = ST[right(p)].first;

            ST[p].first = p1 + p2; ST[p].second = 0;//Construiumos sumando la cantidad de unos en los hijos
        }

        return;
    }

    void push(int p, int L, int R){
        if (ST[p].second == 0) return;//Si no hay nada pendiente regresamos

        if (ST[p].second == 2 || ST[p].second == 3){//Si lo pendiente es asignar lo heredamos tal cual a los hijo y lo aplicamos en 
            ST[p].second == 2 ? ST[p].first = 0 : ST[p].first = (R-L) + 1;//el nodo en el que estamos

            if (L < R){
                ST[left(p)].second = ST[p].second;
                ST[right(p)].second = ST[p].second;
            } 
        } else if (ST[p].second == 1){//Si la accion que estaba es invertir heredar depende de la accion que tenga el hijo
            ST[p].first = (R-L+1) - ST[p].first;//Primero invertimos en el nodo p
            if (L < R){//Si el hijo tiene asignar a un valor solo cambiamos el valor que asigna
                if (ST[left(p)].second == 2 || ST[left(p)].second == 3) ST[left(p)].second = ((ST[left(p)].second-1) % 2) + 2;
                if (ST[right(p)].second == 2 || ST[right(p)].second == 3) ST[right(p)].second = ((ST[right(p)].second-1) % 2) + 2;
                //Si tiene un invertir la accion se convierte en hacer nada, si no tiene nada en invertir
                if (ST[left(p)].second == 0 || ST[left(p)].second == 1) ST[left(p)].second = 1 - ST[left(p)].second;
                if (ST[right(p)].second == 0 || ST[right(p)].second == 1) ST[right(p)].second = 1 - ST[right(p)].second;
            } 
        }

        ST[p].second = 0;
        return;
    }


    public: 

    LazySegment(const vi &nodes){
        n = nodes.size(); 
        ST = vector<pair<int,int>>(4*n);
        ini = nodes;
        build(1,0,n-1);    
    }//funcion O(NlogN) 

    int countOfOnes(int p, int L, int  R, int i, int j) {//Contamos los unos en el intervalo [i,j]
        push(p, L, R);
        if (i > R  || j < L) return 0; 
        if (L >= i && R <= j) return ST[p].first;//Coste O(log n)

        int p1 = countOfOnes(left(p), L, (L+R) >> 1, i, j);
        int p2 = countOfOnes(right(p), ((L+R) >> 1) + 1, R, i, j);

        return p1 + p2;
    }

    int countOfOnes(int i, int j){ return countOfOnes(1, 0, n-1, i, j); }

    void update(int p, int L, int R, int i, int j, int change){//Hacemos un actualizacion sobre [i,j]
        push(p, L, R);
        if (i > R || j < L) return;
        else if (L >= i && R <= j){
            ST[p].second = change;
            push(p, L, R);
            return;
        }
        update(left(p), L, (L+R) >> 1, i, j, change);
        update(right(p), ((L+R) >> 1) + 1, R, i, j, change);

        ST[p].first = ST[left(p)].first + ST[right(p)].first;
        return;
    }

    void update(int i, int j, int change){ return update(1, 0, n-1, i, j, change); }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int C; cin >> C;
    
    for (int i = 0; i < C; i++){
        int M, Q, rep; 
        cin >> M;
        string pivot, iniStr = "";
        vi ini;

        for (int j = 0; j < M; j++){
            cin >> rep;
            cin >> pivot;
            iniStr += pivot * rep;
        }

        ini = cast(iniStr);
        LazySegment lSt(ini);

        cin >> Q;

        for (int j = 0; j < Q; j++){
            int l,r;
            char action;
            cin >> action >> l >> r;

            if (action == 'S') cout << lSt.countOfOnes(l,r) << endl;
            else if (action == 'F') lSt.update(l, r, 3);
            else if (action == 'E') lSt.update(l, r, 2);
            else if (action == 'I') lSt.update(l, r, 1);
        }
    }

    return 0;
}