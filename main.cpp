#include <bits/stdc++.h>
//#include "Neuron.h"
#include "header/Layer.h"
using namespace std;

int main(){
    //Neuron n({1,2,3}, 2, ReLU);
    // vector<Neuron> x(5);
    // Layer l(x);

    //cout << n << '\n';
    //cout << n.evaluate({3,2,1}) << '\n';

    Matrix a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix i = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    Matrix b =  a;
    // cout << a << '\n' <<  i << "\n";
    // cout << a + i << '\n' << a - i << '\n' << 3*i << '\n' << i*3 << '\n' << a*i;
    
    vstack(a, i);
    hstack(b, i);

    Matrix x = b*a;

    cout << a << "\n" << b << '\n' << x << '\n';
    //cout << a - i <<'\n';
    // cout << l.getDimension() << '\n';
    // l.insertNeuron(n);
    // cout << l.getDimension() << '\n';

    // for(Neuron n : l.getNeurons()) cout << n << '\n';

    //cout << n << '\n';
    

    return 0;
}
