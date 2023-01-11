#include <bits/stdc++.h>
#include "Neuron.h"
// #include "GloDec.cpp"
using namespace std;

#ifndef _LAYER
#define _LAYER
 

class Layer{
private:
    int dimension;
    vector<Neuron> neurons;

public:

    Layer() : neurons({}), dimension(0) {}
    Layer(int n) : dimension(n), neurons(vector<Neuron> (n)) {}
    Layer(vector<Neuron> neurons) : neurons(neurons), dimension(neurons.size()) {}

    const int& getDimension();
    const vector<Neuron>& getNeurons();

    void setDimension(int dimension);
    void setNeurons(vector<Neuron> neurons);

    void insertNeuron(Neuron neuron);

    void setActivation(afunc func);

    friend ostream& operator << (ostream& os, const Layer& layer);

    ~Layer();
};


#endif 
