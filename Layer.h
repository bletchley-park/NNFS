#include <bits/stdc++.h>
#include "Neuron.h"
// #include "GloDec.cpp"
//using namespace std;

#ifndef _LAYER
#define _LAYER

class Layer{
public:
    int dimension;
    vector<Neuron> neurons;

    Layer() : neurons({}), dimension(0) {}
    Layer(int n) : dimension(n), neurons(vector<Neuron> (n)) {}
    Layer(vector<Neuron> neurons) : neurons(neurons), dimension(neurons.size()) {}

    friend ostream& operator << (ostream& os, const Layer layer);
};


#endif 
