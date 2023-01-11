#include <bits/stdc++.h>
#include "../header/Neuron.h"
//#include "GloDec.cpp"
using namespace std;

const Row& Neuron::getWeights(){
    return this->weights;
}
const afunc Neuron::getActivation(){
    return this->activationFunction;
}
const double& Neuron::getBias(){
    return this->bias;
}

void Neuron::setWeights(Row weights){
    this->weights = weights;
}
void Neuron::setActivation(afunc activationFunction){
    this->activationFunction = activationFunction;
}
void Neuron::setBias(double bias){
    this->bias = bias;
}

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