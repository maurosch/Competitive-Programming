#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m,a,b,d;

    cin>>n>>m;
    cin>>d;

    vector<vector <int> >graf(n);

    for(int i = 0; i < m;i++){
        cin>>a>>b;
        graf[a-1].push_back(b-1);
        graf[b-1].push_back(a-1);
    }

    vector <bool> visitado(n,false);

    queue<int>erdos;
    queue<int>darwin;

    vector<int>contadore(n,-1);
    vector<int>contadord(n,-1);
    vector<int>contadorf(n,999999999);

    contadore[0]=0;
    contadord[n-1]=0;

    erdos.push(0);
    visitado[0]=true;

    while(!erdos.empty()){
        int nodo=erdos.front();
        erdos.pop();
        for(int i=0;i<graf[nodo].size();i++){
            int nodoady=graf[nodo][i];
            if(!visitado[nodoady]){

                visitado[nodoady]=true;
                erdos.push(nodoady);
                contadore[nodoady]=contadore[nodo]+1;

            }
        }
    }
    for(int i=0;i<n;i++){
        visitado[i]=false;
    }

    darwin.push(n-1);
    visitado[n-1]=true;

    while(!darwin.empty()){
        int nodo=darwin.front();
        darwin.pop();
        for(int i=0;i<graf[nodo].size();i++){
            int nodoady=graf[nodo][i];
            if(!visitado[nodoady]){
                visitado[nodoady]=true;
                darwin.push(nodoady);
                contadord[nodoady]=contadord[nodo]+1;
            }
        }
    }

    for(int i = 0; i < contadord.size(); i++) cout << contadord[i] << " ";
    cout << endl;
    for(int i = 0; i < contadore.size(); i++) cout << contadore[i] << " ";
    cout << endl;

    
    int contf=0;
    for(int i=0;i<n;i++){
        if(contadord[i]!=-1 and contadore[i]!=-1){
            contadorf[i]=contadord[i]+contadore[i];
            if(contadorf[i]<=d){
                contf++;
            }
        }
        

    }


    cout<<contf;

    return 0;
}
