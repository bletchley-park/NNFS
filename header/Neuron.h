#include <bits/stdc++.h>
#include "GloDec.h"
using namespace std;

#ifndef _NEURON
#define _NEURON 


class Neuron{
private:
    Row weights;
    afunc activationFunction; 
    double bias;

public:

    Neuron() : weights({}), bias(0), activationFunction(NULL) {}
    Neuron(double bias) :  weights({}), bias(bias), activationFunction(NULL) {}
    Neuron(Row weights) : weights(weights), bias(0), activationFunction(NULL) {}
    Neuron(Row weights, double bias) : weights(weights), bias(bias), activationFunction(sigmoid) {}
    Neuron(afunc func) : weights({}), bias(0) {}
    Neuron(double bias, afunc func) : weights({}), bias(bias), activationFunction(func) {}
    Neuron(Row weights, afunc func) : weights(weights), bias(0), activationFunction(func) {}
    Neuron(Row weights, double bias, afunc func) : weights(weights), bias(bias), activationFunction(func) {}

    double evaluate(Row input);

    friend ostream& operator << (ostream& os, const Neuron& neuron);

    ~Neuron();
};


#endif 