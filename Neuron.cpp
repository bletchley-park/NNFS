#include <bits/stdc++.h>
#include "Neuron.h"
//#include "GloDec.cpp"
//using namespace std;

ostream& operator << (ostream& os, const Neuron& neuron){
    os << "["; 
    os << "Weights : ";

    if(neuron.weights.empty()){
        os << "[]" << endl;
    }else{
        os << "[" << neuron.weights[0];
        for(int i = 1; i < neuron.weights.size(); i++){
            os << ", " << neuron.weights[i];
        }
        os << "], ";
    }

    os << "Bias : " << neuron.bias << ", Activation Function : ";

    if(neuron.activationFunction == sigmoid) os << "Sigmoid";
    else os << "ReLU";

    os << "]"; 

    return os;
}