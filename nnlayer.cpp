#include <bits/stdc++.h>
using namespace std;

typedef vector<double> Row;

double dot(Row u, Row v){
    if(u.size() != v.size()){
        throw invalid_argument("Dimensional Error : Vectors not compatible!");
    }

    double sum = 0;

    for(int i = 0; i < u.size(); i++){
        sum += u[i]*v[i];
    }

    return sum;
}

double ReLU(double x){
    return max(0.0, x);
}

double sigmoid(double x){
    return 1/(1-exp(-x));
}

typedef double (*afunc)(double x);

class Neuron{
public:
    Row inputs;
    Row weights;
    afunc activationFunction; 
    double bias;

    Neuron() : inputs({}), weights({}), bias(0), activationFunction(sigmoid) {}
    Neuron(double bias) : inputs({}), weights({}), bias(bias), activationFunction(sigmoid) {}
    Neuron(Row weights) : inputs({}),weights(weights), bias(0), activationFunction(sigmoid) {}
    Neuron(Row weights, double bias) : weights(weights), bias(bias), activationFunction(sigmoid) {}
    Neuron(afunc func) : weights({}), bias(0) {}
    Neuron(double bias, afunc func) : weights({}), bias(bias), activationFunction(func) {}
    Neuron(Row weights, afunc func) : weights(weights), bias(0), activationFunction(func) {}
    Neuron(Row weights, double bias, afunc func) : weights(weights), bias(bias), activationFunction(func) {}

    double output = activationFunction(dot(input, weights)) + bias;
    
    friend ostream& operator <<(ostream& os, const Neuron n){
        os << "["; 
        os << "Weights : ";

        if(n.weights.empty()){
            os << "[]" << endl;
        }else{
            cout << "[" << n.weights[0];
            for(int i = 1; i < n.weights.size(); i++){
                os << ", " << n.weights[i];
            }
            os << "], ";
        }

        os << "Bias : " << n.bias << ", Activation Function : ";

        if(n.activationFunction == sigmoid) os << "Sigmoid";
        else os << "ReLU";

        os << "]"; 

        return os;
    }
};

class Layer{
public:
    int dimension;
    vector<Neuron> neurons;

    Layer() : neurons({}), dimension(0) {}
    Layer(int n) : dimension(n), neurons(vector<Neuron> (n)) {}
    Layer(vector<Neuron> neurons) : neurons(neurons), dimension(neurons.size()) {}

    friend ostream& operator <<(ostream& os, const Layer layer){

        if(layer.neurons.empty()){
            os << "[]" << endl;
        }else{
            cout << "[" << layer.neurons[0];
            for(int i = 1; i < layer.neurons.size(); i++){
                os << ", " << layer.neurons[i];
            }
            os << "]" << endl;
        }

        return os;
    }
};



int main(){





    return 0;
}