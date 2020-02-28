    #include <iostream>
    #include <string>
    #include <cstring>
    #define forn(i, n) for(int i = 0; i < int(n); ++i)
    using namespace std;
     
    const int maxn = 1000; // maxima cantidad de nodos
     
    int proximo_libre;
    int sig[maxn][26]; // arcos (en este caso sólo letras mayusculas)
    bool final[maxn];  // ¿una palabra termina en este nodo?
     
    void agregar(const string &s, int raiz = 0){
        int actual = raiz;
        forn(i, s.size()){
            int letra = s[i] - 'A';
            if( sig[ actual ][ letra ] == -1 )
                sig[ actual ][ letra ] = proximo_libre++;
            actual = sig[ actual ][ letra ];
        }
        final[ actual ] = true;
    }
     
    int buscar(const string &s, int raiz = 0){
        int actual = raiz;
        forn(i, s.size()){
            int letra = s[i] - 'A';
            if( sig[ actual ][ letra ] == -1 )
                return -1;
            actual = sig[ actual ][ letra ];
        }
        if( final[ actual ] ) return actual;
        else                  return -1;
    }
     
    void eliminar(const string &s, int raiz = 0){
        int actual = raiz;
        forn(i, s.size()){
            int letra = s[i] - 'A';
            if( sig[ actual ][ letra ] == -1 )
                return;
            actual = sig[ actual ][ letra ];
        }
        final[ actual ] = false;
    }
     
     
    int main(){
        memset(sig, -1, sizeof(sig)); // seteamos en -1 todos los arcos para indicar que no existen
     
        agregar("CASA");
        agregar("CAMA");
        agregar("CAMARERO");
        agregar("CASERO");
     
        //int trie2 = proximo_libre++;
        //agregar("CAMA", trie2);
     
        if( buscar("CAM") != -1 ) cout<<"CAM esta"<<endl;
        else                      cout<<"CAM no esta"<<endl;
     
        if( buscar("CAMA") != -1 ) cout<<"CAMA esta"<<endl;
        else                       cout<<"CAMA no esta"<<endl;
     
        return 0;
    }

