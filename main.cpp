#include <bits/stdc++.h>
//#include "Neuron.h"
#include "Layer.cpp"
using namespace std;

int main(){
    Neuron n({1,2,3});
    Layer l;
    l.neurons.push_back(n);

    cout << n << '\n';
    cout << l << '\n';
    
    return 0;
}
