#include <bits/stdc++.h>
#include "Layer.h"
using namespace std;

ostream& operator << (ostream& os, const Layer& layer){
    os << "[";
    if(layer.neurons.empty()){
        os << "[]" << endl;
    }else{
        os << "[" << layer.neurons[0];
        for(int i = 1; i < layer.neurons.size(); i++){
            os << ", " << layer.neurons[i];
        }
        os << "]";
    }
    os << "]";

    return os;
}