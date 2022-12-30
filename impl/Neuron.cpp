#include <bits/stdc++.h>
#include "../header/Neuron.h"
//#include "GloDec.cpp"
using namespace std;

double Neuron::evaluate(Row input){
    double ans;

    if(this->activationFunction == NULL) throw invalid_argument("Activation function uninitialised!");

    ans = this->activationFunction((dot(input, weights) + bias));

    return ans;
}

ostream& operator << (ostream& os, const Neuron& neuron){
    os << "["; 
    os << "Weights : ";

    os << neuron.weights << ", ";

    os << "Bias : " << neuron.bias << ", Activation Function : ";

    if(neuron.activationFunction == NULL) os << "NULL";
    else if(neuron.activationFunction == sigmoid) os << "Sigmoid";
    else os << "ReLU";

    os << "]"; 

    return os;
}

Neuron::~Neuron(){
    this->weights.clear();
}