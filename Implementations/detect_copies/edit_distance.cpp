//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - /0/2018
//C++14 - Visual Studio Code - ArchLinux 
//Programa para ver cuantas diferencias tienen 2 textos.
//Objetivo: definir si 2 alumnos se copiaron.
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;
const int INF = 999999999;

int minCambios(string &primerString, string &segundoString, int maxCambios)
{
    string cortoString, largoString;
    int tamanio;

    if(primerString.size() < segundoString.size())
    {
        tamanio = int(primerString.size());
        cortoString = primerString;
        largoString = segundoString; 
    }
    else
    {
        tamanio = int(segundoString.size());
        cortoString = segundoString;
        largoString = primerString; 
    }

    vector<int>primerColumna(tamanio,0);
    vector<int>segundaColumna(tamanio,0);
    
    //-----------------Inicializo la primer columna-----------------
    if(cortoString[0] == largoString[0]) primerColumna[0] = 0;
    else primerColumna[0] = 1; 
    forsn(i,1,tamanio)
        primerColumna[i] = primerColumna[i-1]+1;
     //-------------------------------------------------------------

    bool copia = false;
    forsn(z, 1, largoString.size())
    {
        int inicio = max(0,z-maxCambios), final = min(z+maxCambios+1,tamanio);
        if(final == inicio) 
        {
            copia = true;
            break;
        }

        segundaColumna[inicio] = primerColumna[inicio]+1;
        forsn(i,inicio+1,final)
        {
            if(cortoString[i] == largoString[z]) 
                segundaColumna[i] = primerColumna[i-1];
            else
                segundaColumna[i] = min(min(segundaColumna[i-1], primerColumna[i]),primerColumna[i-1])+1;
        }
        primerColumna = segundaColumna;
    }

    if(copia) return -1;
    return segundaColumna[tamanio-1];
}


int main()
{
    //================CONFIGURACION================
    ifstream in2("config.txt");
    map<string,string>config;
    while(!in2.eof())
    {
        string key, value;
        in2 >> key;
        in2 >> value;
        config[key] = value;
    }
    in2.close();
    //=============================================

    //==============ENTRADA DE DATOS===============
    ifstream ifs("text1.txt");
    string texto1((istreambuf_iterator<char>(ifs) ),(istreambuf_iterator<char>()));
    ifs.close();
    ifs.open("text2.txt");
    string texto2((istreambuf_iterator<char>(ifs) ),(istreambuf_iterator<char>()));
    ifs.close();
    //Sacamos los espacios y enters
    texto1.erase(remove(texto1.begin(), texto1.end(), ' '), texto1.end());
    texto2.erase(remove(texto2.begin(), texto2.end(), ' '), texto2.end());
    texto1.erase(remove(texto1.begin(), texto1.end(), '\n'), texto1.end());
    texto2.erase(remove(texto2.begin(), texto2.end(), '\n'), texto2.end());
    if(config["debug"] == "true")
    {
        cout << "===============Texto 1================" << endl;
        cout << texto1 << endl << endl;
        cout << "===============Texto 2================" << endl;
        cout << texto2 << endl << endl;
    }
    
    if(texto1.size() == 0 or texto2.size() == 0)
    {
        cout << "Alguno de los 2 textos está vacío" << endl;
        return 0;
    }
    //=============================================

    int maxCambios = (int) ( (float)stoi(config["cambiosPorcentaje"]) / (float)100 * (float)max(texto1.size(),texto2.size()));

    cout << "===================INFO====================" << endl;
    cout << "Verificador de copia" << endl;
    cout << "Fecha: 08/04/2018" << endl;
    cout << "Creado por Mauro Schiavinato" << endl;

    cout << endl;
    cout << "===================DATOS===================" << endl;
    cout << "Largo texto 1:              " << texto1.size() << " caracter/es" << endl;
    cout << "Largo texto 2:              " << texto2.size() << " caracter/es" << endl;
    cout << "Máxima diferencia:          " << config["cambiosPorcentaje"] << "%" << endl;
    cout << "Máxima cantidad de cambios: " << maxCambios << " caracteres" << endl;
    cout << "===========================================" << endl;
    

    int solucion = minCambios(texto1, texto2, maxCambios);

    if(solucion == -1 or solucion > maxCambios)
    {
        cout << endl << "Cantidad de cambios: Mayor que el " << config["cambiosPorcentaje"] << "%" << endl;
        return 0;
    }
    
    cout << endl << "Cantidad de cambios: " << solucion << endl;
    cout << "Igualdad: " << 100- (float)solucion / (float)max(texto1.size(),texto2.size()) * 100 << "%" << endl;
    
    return 0;
}