#include <bits/stdc++.h>
#include "../header/Layer.h"
using namespace std;
 
int Layer::getDimension(){
    return this->dimension;
}

const vector<Neuron> Layer::getNeurons(){
    return this->neurons;
}

void Layer::insertNeuron(Neuron neuron){
    this->neurons.push_back(neuron);
    this->dimension++;
}

ostream& operator << (ostream& os, const Layer& layer){
    os << "[";
    if(!layer.neurons.empty()){
        for(int i = 0; i < layer.neurons.size() - 1; i++){
            os << layer.neurons[i] << ", \n";
        }
        os << layer.neurons[layer.neurons.size()-1];
    }
    os << "]";

    return os;
}

Layer::~Layer(){
    this->neurons.clear();
}