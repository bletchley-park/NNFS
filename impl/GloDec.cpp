#include "../header/GloDec.h"

ostream& operator << (ostream& os, const Row& r){
    if(r.size() == 0){
        os << "[]";
    }else{
        os << "[" << r[0];
        for(int i = 1; i < r.size(); i++){
            os << ", " << r[i]; 
        }
        os << "]";
    }

    return os;
}

ostream& operator << (ostream& os, const Matrix& a){
    os << "[";
    if(!a.empty()){
        for(int i = 0; i < a.size() - 1; i++){
            os << a[i] << ", \n";
        }
        os << a[a.size()-1];
    }
    os << "]";

    return os;
}

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

Matrix transpose(Row a){
    return transpose({a});
}

Matrix vstack(Matrix& a, Row v){
    if(a[0].size() != v.size()){
        throw invalid_argument("Dimensional Error : Matrices not compatible!");
    }

    a.push_back(v);

    return a;
}

Matrix vstack(Matrix& a, Matrix b){
    for(int i = 0; i < b.size(); i++){
        vstack(a, b[i]);
    }

    return a;
}

Matrix hstack(Matrix& a, Matrix b){
    if(a.size() != b.size()){
        throw invalid_argument("Dimensional Error : Matrices not compatible!");
    }

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            a[i].push_back(b[i][j]);
        }
    }

    return a;
}

Row operator * (double c, Row b){
    for(int i = 0; i < b.size(); i++){
        b[i] *= c;
    }

    return b;
}

Row operator * (Row a, double c){
    return c * a;
}

Row operator + (Row a){
    return a;
}

Row operator - (Row a){
    return -1 * a;
}

Row operator + (Row a, Row b){
    if(a.size() != b.size()){
        throw invalid_argument("Dimensional Error : Vectors not compatible!");
    }

    Row c(a.size(), 0);

    for(int i = 0; i < a.size(); i++){
        c[i] += a[i]+b[i];
    }

    return c;
}

Row operator - (Row a, Row b){
    return a + (-b);
}

void operator += (Row &a, Row b){
    a = a + b;
}
void operator -= (Row &a, Row b){
    a = a - b;
}

Row operator * (Row a, Matrix b){
    Row res;

    for(int i = 0; i < a.size(); i++){
        res += a[i] * b[i];
    }

    return res;
}

Matrix operator * (Matrix a, Matrix b){
    if(a[0].size() != b.size()){
        throw invalid_argument("Dimensional Error : Matrices not compatible!");
    }

    Matrix res(a.size(), Row (b[0].size(), 0));

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < b.size(); k++){
                res[i][j] += a[i][k] * b[j][k];
            }
        }
    }

    return res;
}

Matrix operator * (double a, Matrix b){
    Matrix res(b.size(), Row (b[0].size(), 0));

    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            res[i][j] = a * b[i][j];
        }
    }

    return res;
}

Matrix operator * (Matrix b, double a){
    return a * b;
}

Matrix operator + (Matrix a){
    return a;
}

Matrix operator + (Matrix a, Matrix b){
    if(a.size() != b.size() || a[0].size() != b[0].size()){
        throw invalid_argument("Dimensional Error : Matrices not compatible!");
    }

    Matrix res(a.size(), Row (a[0].size(), 0));

    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            res[i][j] = a[i][j] + b[i][j];
        }
    }

    return res;
}

Matrix operator - (Matrix a){
    return -1 * a;
}

Matrix operator - (Matrix a, Matrix b){
    return a + (-b);
}

double ReLU(double x){
    return max(0.0, x);
}

double sigmoid(double x){
    return 1/(1-exp(-x));
}

double errFunc(Row x, Row y, Row w){
    Matrix W = transpose({w});
    Matrix X = {x};
    Matrix Y = {y};
    Matrix h = X * W - Y;
    //Matrix hT = transpose(h);
    return (0.5/x.size()) * dot(h[0], h[0]);
}

Row gradientDescent(const Row x, const Row y, Row w, double learningRate = 0.01, int epochs = 500){
    for(int i = 0; i < epochs; i++){
        
    }
}