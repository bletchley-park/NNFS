#include <bits/stdc++.h>
#include "GloDec.cpp"
using namespace std;

#ifndef _NEURON
#define _NEURON


class Neuron{
public:
    Row inputs;
    Row weights;
    afunc activationFunction; 
    double bias;
    double output;

    Neuron() : weights({}), bias(0), activationFunction(sigmoid) {}
    Neuron(double bias) :  weights({}), bias(bias), activationFunction(sigmoid) {}
    Neuron(Row weights) : weights(weights), bias(0), activationFunction(sigmoid) {}
    Neuron(Row weights, double bias) : weights(weights), bias(bias), activationFunction(sigmoid) {}
    Neuron(afunc func) : weights({}), bias(0) {}
    Neuron(double bias, afunc func) : weights({}), bias(bias), activationFunction(func) {}
    Neuron(Row weights, afunc func) : weights(weights), bias(0), activationFunction(func) {}
    Neuron(Row weights, double bias, afunc func) : weights(weights), bias(bias), activationFunction(func) {}

    
    friend ostream& operator << (ostream& os, const Neuron& neuron);
};


#endif 