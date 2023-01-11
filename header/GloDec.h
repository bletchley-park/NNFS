#include <bits/stdc++.h>
using namespace std;

typedef vector<double> Row;
typedef vector<vector<double>> Matrix;

ostream& operator << (ostream& os, const Row& r);
ostream& operator << (ostream& os, const Matrix& a);

double dot(Row u, Row v);

Matrix transpose(Matrix a);
Matrix transpose(Row a);

Matrix vstack(Matrix& a, Row v);
Matrix vstack(Matrix& a, Matrix b);

Matrix hstack(Matrix& a, Matrix b);

Row operator * (double c, Row b);
Row operator * (Row a, double c);
Row operator + (Row a);
Row operator - (Row a);
Row operator + (Row a, Row b);
Row operator - (Row a, Row b);
void operator += (Row &a, Row b);
void operator -= (Row &a, Row b);
Row operator * (Row a, Matrix b);

Matrix operator * (Matrix a, Matrix b);
Matrix operator * (double a, Matrix b);
Matrix operator * (Matrix b, double a);
Matrix operator + (Matrix a);
Matrix operator + (Matrix a, Matrix b);
Matrix operator - (Matrix a);
Matrix operator - (Matrix a, Matrix b);

double ReLU(double x);

double sigmoid(double x);

double deltaSigmoid(double x);

typedef double (*afunc)(double x);

double errFunc(const Row x, const Row y, Row w);

Row gradientDescent(const Row x, const Row y, Row w, double learningRate, int epochs);