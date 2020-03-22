#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

int medir(string cad);

int veces(char a, int N)
{
	int lo = 0, hi = N+1;
	while(hi-lo > 1)
	{
		int medio = lo + (hi-lo)/2;
		string aux;
		forn(i,medio) aux += a;
		//cout << aux << endl;
		if( medir(aux) == 1 )
			lo = medio;
		else
			hi = medio;
	}
	return lo;
}

string juntar(string a, string b)
{
	forn(j, a.size())
	{
		if(b.size() == 0) continue;
		
		int p;
		for(p = 1; true; p++)
		{	
			string secundaria = a;
			string auxSecundaria;
			forn(u, p)
				auxSecundaria += b[u];

			secundaria.insert(j, auxSecundaria);

			if ( medir(secundaria) == 0 )
				break;
		}
		p--;

		if(p == 0) continue;
		
		string agregar;
		forn(g, p)
			agregar += b[g];

		b.erase(0, p);
		a.insert(j, agregar);

		j+=p;
	}
	if(b.size() > 0) 
		a+=b;

	return a;
}

string secuenciar(int N, string s)
{
	string posta;

	if(s == "AC")
	{
		int cantVecesA = veces('A', N);
		int cantVecesC = N-cantVecesA;
		forn(i, cantVecesA)
			posta += 'A';
		forn(i, cantVecesC)
			posta += 'C';
		return posta;
	}

	if(s == "GT")
	{
		int cantVecesG = veces('G', N);
		int cantVecesT = N-cantVecesG;
		forn(i, cantVecesG)
			posta += 'G';
		forn(j, posta.size())
		{		
			if(cantVecesT == 0) continue;
			int p;
			for(p = 1; true; p++)
			{	
				string secundaria = posta;
				string auxSecundaria;
				forn(u, p)
					auxSecundaria += 'T';
				secundaria.insert(j, auxSecundaria);
				if ( medir(secundaria) == 0 )
					break;
			}
			p--;
			cantVecesT -= p;

			if(p == 0) continue;
			string agregar;
			forn(g, p)
				agregar += 'T';

			posta.insert(j, agregar);
			j+=p;
		}
		if(cantVecesT > 0) 
		{
			string agregar;
			forn(g, cantVecesT)
				agregar += 'T';
			posta+=agregar;
		}
		return posta;
	}


    if(N == 0) return "";
	
	int cont = N;
	vector<string>miniStrings(s.size());

    forn(i, s.size())
    {
        int aux = veces(s[i], cont);
		forn(j, aux)
			miniStrings[i] += s[i];
        cont -= aux;
    }

	while(miniStrings.size() > 1)
	{
		sort(miniStrings.begin(), miniStrings.end(),
		[] (const string &a, const string &b)
		{
			return a.size() < b.size();
		});
		miniStrings[1] = juntar(miniStrings[0], miniStrings[1]);
		miniStrings.erase(miniStrings.begin(), miniStrings.begin()+1);
	}
	return miniStrings[0];
}

