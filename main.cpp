#include <bits/stdc++.h>
//#include "Neuron.h"
#include "header/Layer.h"
using namespace std;

int main(){
    //Neuron n({1,2,3}, 2, ReLU);
    // vector<Neuron> x(5);
    // Layer l(x);

    //cout << n << '\n';
    //cout << n.evaluate({3,2,1}) << '\n';

    // Matrix a = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };

    // Matrix i = {
    //     {1, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 1}
    // };

    // Matrix b =  a;
    // cout << a << '\n' <<  i << "\n";
    // cout << a + i << '\n' << a - i << '\n' << 3*i << '\n' << i*3 << '\n' << a*i;
    
    // vstack(a, i);
    // hstack(b, i);

    // Matrix x = b*a;

    // cout << a << "\n" << b << '\n' << x << '\n';
    //cout << a - i <<'\n';
    // cout << l.getDimension() << '\n';
    // l.insertNeuron(n);
    // cout << l.getDimension() << '\n';

    // for(Neuron n : l.getNeurons()) cout << n << '\n';

    //cout << n << '\n';
    double x = 2;
    double y = 4;
    double z = 6;

    Row a = {x, y, z, 0};
    Row b = {y+1, z+2, x+3, 1};
    Row c = {z+3, x+2, y+1, 0};

    Matrix A = {a,b,c};

    cout << "A = \n" << transpose(A) << '\n';

    Row q1 = a * (double)(1/sqrt(dot(a, a)));
    cout << "q1 = " << q1 << '\n';

    Row B = b - dot(q1, b) * q1;
    Row q2 = B * (double)(1/sqrt(dot(B, B)));
    cout << "q2 = " << q2 << '\n';

    Row C = c - dot(q1, c) * q1 - dot(q2, c) * q2;
    Row q3 = C * (double)(1/sqrt(dot(C, C)));
    cout << "q3 = " << q3 << '\n';

    Matrix Q = {q1, q2, q3};

    cout << "Q = \n" << transpose(Q) << '\n';

    return 0;
}
