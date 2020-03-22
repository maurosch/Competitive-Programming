#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class ventana
{
    deque<int>indices;
    int A, B;
    ventana()
    {
        A = 0;
        B = 0;
    }
    void avanzarA(vector<int>& array)
    {
        if(indices.front() == A) indices.pop_front();
        A++;
    }
    void avanzarB(vector<int>& array)
    {
        if(indices.size() == 0) indices.push_back(B);
        else
        {
            while(indices.size() > 0 and array[B] <= indices.back())
            {
                indices.pop_back();
            }
            indices.push_back(B);
        }
        B++;
    }
    int minimoEnVentana(vector<int>& array)
    {
        if (A == B)
            return -1; // VENTANA VACIA!!!
        else
            return array[indices.front()]; // dominantes.front() nos dice el indice
    }
};

int main()
{

    return 0;
}
