#include <bits/stdc++.h>
using namespace std;

typedef vector<double> Row;
typedef vector<vector<double>> Matrix;

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

Matrix transpose(Matrix a){
    int rowSize = a.size();
    int colSize = a[0].size();

    Matrix t(colSize, Row (rowSize));

    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < colSize; j++){
            t[i][j] = a[j][i];
        }
    }

    return t;
}

double ReLU(double x){
    return max(0.0, x);
}

double sigmoid(double x){
    return 1/(1-exp(-x));
}

typedef double (*afunc)(double x);