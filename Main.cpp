#include <iostream>
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Types.h"
#include "Vector.h"

using namespace std;

string xyz = "xyz";

int getType(){
    int type = -1;
    cout << ">>Choose the type of an operand:" << endl;
    cout << "0. int" << endl;
    cout << "1. double" << endl;
    cout << "2. complex" << endl << endl;
    while(type < 0 || type > 2){
        cin >> type;
    }
    return type;
}

int getOpType(){
    int type = -1;
    cout << ">>Choose an operation:" << endl;
    cout << "0. Vector summary" << endl;
    cout << "1. Vector multiplication" << endl;
    cout << "2. Vector scalar multiplication" << endl << endl;
    while(type < 0 || type > 2){
        cin >> type;
    }
    return type;
}

Int getInt(){
    Int input;
    cout << ">>Enter multiplier value: ";
    cin >> input.val;
    return input;
}
Double getDouble(){
    Double input;
    cout << ">>Enter multiplier value: ";
    cin >> input.val;
    return input;
}

Complex getComplex(){
    double input;
    Complex c;
    cout << ">>Enter real part of the multiplier value: ";
    cin >> input;
    c.SetRe(input);
    cout << ">>Enter imaginary part of the multiplier value: ";
    cin >> input;
    c.SetIm(input);
    cout << endl;
    return c;
}

Vector<Int> createInt(){
    Int input;
    ArraySequence<Int> seq(3);
    for(int i = 0; i < 3; i++){
        cout << ">>Enter " << xyz[i] << ": ";
        cin >> input.val;
        seq.Append(input);
    }
    cout << endl;
    return Vector<Int>(seq);
}

Vector<Double> createDouble(){
    Double input;
    ArraySequence<Double> seq(3);
    for(int i = 0; i < 3; i++){
        cout << ">>Enter " << xyz[i] << ": ";
        cin >> input.val;
        seq.Append(input);
    }
    cout << endl;
    return Vector<Double>(seq);
}

Vector<Complex> createComplex(){
    double input;
    Complex c;
    ArraySequence<Complex> seq(3);
    for(int i = 0; i < 3; i++){
        cout << ">>Enter real part of " << xyz[i] << " value: ";
        cin >> input;
        c.SetRe(input);
        cout << ">>Enter imaginary part of " << xyz[i] << " value: ";
        cin >> input;
        c.SetIm(input);
        seq.Append(c);
        cout << endl;
    }
    cout << endl;
    return Vector<Complex>(seq);
}

template <class T> void Result(Vector<T> res){
    cout << ">>Resulting coordinates: " << endl << endl;
    for(int i = 0; i < 3; i++){
        cout << xyz[i] << ": " << res.GetCoords()->Get(i).val << endl;
    }
    cout << endl;
    cout << ">>Resulting Euclidean norm: " << res.Norm() << endl << endl;
}

template <> void Result(Vector<Complex> res){
    cout << ">>Resulting coordinates: " << endl << endl;
    for(int i = 0; i < 3; i++){
        cout << xyz[i] << " real: " << res.GetCoords()->Get(i).Re() << " / ";
        cout << xyz[i] << " imaginary: " << res.GetCoords()->Get(i).Im() << endl;
    }
    cout << endl;
    cout << ">>Resulting Euclidean norm: " << res.Norm() << endl << endl;
}

template <class T> void Result(T res){
    cout << ">>Resulting value: " << res.val << endl << endl;
}

template <> void Result(Complex res){
    cout << ">>Real part of the resulting value: " << res.Re() << endl;
    cout << ">>Imaginary part of the resulting value: " << res.Im() << endl << endl;
}

void Sum(){
    int type = getType();
    if(type == 0){
        Vector<Int> v1 = createInt();
        type = getType();
        if(type == 0){
            Vector<Int> v2 = createInt();
            Result(v1 + v2);
        }
        else if(type == 1){
            Vector<Double> v2 = createDouble();
            Result(v1 + v2);
        }
        else if(type == 2){
            Vector<Complex> v2 = createComplex();
            Result(v1 + v2);
        }
    }
    else if(type == 1){
        Vector<Double> v1 = createDouble();
        type = getType();
        if(type == 0){
            Vector<Int> v2 = createInt();
            Result(v1 + v2);
        }
        else if(type == 1){
            Vector<Double> v2 = createDouble();
            Result(v1 + v2);
        }
        else if(type == 2){
            Vector<Complex> v2 = createComplex();
            Result(v1 + v2);
        }
    }
    else if(type == 2){
        Vector<Complex> v1 = createComplex();
        type = getType();
        if(type == 0){
            Vector<Int> v2 = createInt();
            Result(v1 + v2);
        }
        else if(type == 1){
            Vector<Double> v2 = createDouble();
            Result(v1 + v2);
        }
        else if(type == 2){
            Vector<Complex> v2 = createComplex();
            Result(v1 + v2);
        }
    }
}

void Mul(){
    int type = getType();
    if(type == 0){
        Vector<Int> v1 = createInt();
        type = getType();
        if(type == 0){
            Int n = getInt();
            Result(v1 * n);
        }
        else if(type == 1){
            Double n = getDouble();
            Result(v1 * n);
        }
        else if(type == 2){
            Complex n = getComplex();
            Result(v1 * n);
        }
    }
    else if(type == 1){
        Vector<Double> v1 = createDouble();
        type = getType();
        if(type == 0){
            Int n = getInt();
            Result(v1 * n);
        }
        else if(type == 1){
            Double n = getDouble();
            Result(v1 * n);
        }
        else if(type == 2){
            Complex n = getComplex();
            Result(v1 * n);
        }
    }
    else if(type == 2){
        Vector<Complex> v1 = createComplex();
        type = getType();
        if(type == 0){
            Int n = getInt();
            Result(v1 * n);
        }
        else if(type == 1){
            Double n = getDouble();
            Result(v1 * n);
        }
        else if(type == 2){
            Complex n = getComplex();
            Result(v1 * n);
        }
    }
}

void ScalarMul(){
    int type = getType();
    if(type == 0){
        Vector<Int> v1 = createInt();
        type = getType();
        if(type == 0){
            Vector<Int> v2 = createInt();
            Result(v1 * v2);
        }
        else if(type == 1){
            Vector<Double> v2 = createDouble();
            Result(v1 * v2);
        }
        else if(type == 2){
            Vector<Complex> v2 = createComplex();
            Result(v1 * v2);
        }
    }
    else if(type == 1){
        Vector<Double> v1 = createDouble();
        type = getType();
        if(type == 0){
            Vector<Int> v2 = createInt();
            Result(v1 * v2);
        }
        else if(type == 1){
            Vector<Double> v2 = createDouble();
            Result(v1 * v2);
        }
        else if(type == 2){
            Vector<Complex> v2 = createComplex();
            Result(v1 * v2);
        }
    }
    else if(type == 2){
        Vector<Complex> v1 = createComplex();
        type = getType();
        if(type == 0){
            Vector<Int> v2 = createInt();
            Result(v1 * v2);
        }
        else if(type == 1){
            Vector<Double> v2 = createDouble();
            Result(v1 * v2);
        }
        else if(type == 2){
            Vector<Complex> v2 = createComplex();
            Result(v1 * v2);
        }
    }
}



int main(){;
    cout << "---------------------------------lab2-Vectors----------------------------------" << endl << endl;
    while(1){
        int ch = getOpType();
        if(ch == 0){
            Sum();
        }
        if(ch == 1){
            Mul();
        }
        if(ch == 2){
            ScalarMul();
        }
    }
    return 0;
}
