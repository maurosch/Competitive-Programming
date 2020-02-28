#include "bubblesort2.h"
#include <algorithm>
#include <math.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)

std::vector<int> countScans(std::vector<int> A,std::vector<int> X,std::vector<int> V){
	int Q=X.size();
	std::vector<int> answer(Q);
	
	forn(i, Q)
	{
		A[X[i]] = V[i];

		int count = 0;
		//vector<int> auxA = A;
		//sort(auxA.begin(),auxA.end());
		auto it = upper_bound(A.begin(),A.end(), V[i]);
		int pos = it-A.begin();

		answer[i] = abs(X[i]-pos);
	}
	
	return answer;
}
