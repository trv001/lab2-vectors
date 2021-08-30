#pragma once
#include <cassert>
#include <cmath>

template <class T> class Vector{

public:

    ArraySequence<T>* GetCoords() const{
        return coords;
    }

    ArraySequence<T>& GetCoordsLink() const{
        return *coords;
    }

    Vector(){
        coords = new ArraySequence<T>(3);
    }

    Vector(const ArraySequence<T>& input){
        assert(input.GetLength() == 3);
        coords = new ArraySequence<T>(input);
    }

    Vector(const Vector<T>& vec){
        coords = new ArraySequence<T>(vec.GetCoordsLink());
    }

    template <class U> auto operator+(Vector<U> vec){
        auto test = GetCoords()->GetFirst() + vec.GetCoords()->GetFirst();
        return sum(this, &vec, test);
    }

    template <class U> auto operator*(U num){
        auto test = GetCoords()->GetFirst() * num;
        return mul(num, test);
    }

    template <class U> auto operator*(Vector<U> vec){
        auto test = GetCoords()->GetFirst() * vec.GetCoords()->GetFirst();
        return scalarmul(this, &vec, test);
    }

    double Norm(){
        double res = 0;
        for(int i = 0; i < 3; i++){
            res += pow(GetCoords()->Get(i).val, 2);
        }
        return sqrt(res);
    }

private:

    ArraySequence<T>* coords;

    template <class U, class V> Vector<U> sum(Vector<T>* v1, Vector<V>* v2, U exp){
        Vector<U> res;
        for(int i = 0; i < 3; i++){
            res.GetCoords()->Append(v1->GetCoords()->Get(i) + v2->GetCoords()->Get(i));
        }
        return res;
    }

    template <class U, class V> Vector<U> sum(Vector<V>* v1, Vector<T>* v2, U exp){
        Vector<U> res;
        for(int i = 0; i < 3; i++){
            res.GetCoords()->Append(v2->GetCoords()->Get(i) + v1->GetCoords()->Get(i));
        }
        return res;
    }

    template <class U> Vector<U> sum(Vector<T>* v1, Vector<T>* v2, U exp){
        Vector<U> res;
        for(int i = 0; i < 3; i++){
            res.GetCoords()->Append(v2->GetCoords()->Get(i) + v1->GetCoords()->Get(i));
        }
        return res;
    }

    template <class U, class V> Vector<U> mul(V num, U exp){
        Vector<U> res;
        for(int i = 0; i < 3; i++){
            res.GetCoords()->Append(GetCoords()->Get(i) * num);
        }
        return res;
    }

    template <class U, class V> U scalarmul(Vector<V>* v1, Vector<T>* v2, U exp){
        U res;
        for(int i = 0; i < 3; i++){
            res = res + (v2->GetCoords()->Get(i) * v1->GetCoords()->Get(i));
        }
        return res;
    }

    template <class U, class V> U scalarmul(Vector<T>* v1, Vector<V>* v2, U exp){
        U res;
        for(int i = 0; i < 3; i++){
            res = res + (v1->GetCoords()->Get(i) * v2->GetCoords()->Get(i));
        }
        return res;
    }

    template <class U> U scalarmul(Vector<T>* v1, Vector<T>* v2, U exp){
        U res;
        for(int i = 0; i < 3; i++){
            res = res + (v1->GetCoords()->Get(i) * v2->GetCoords()->Get(i));
        }
        return res;
    }
};

template <> double Vector<Complex>::Norm(){
    double res = 0;
    for(int i = 0; i < 3; i++){
            res += pow(GetCoords()->Get(i).Re(), 2);
            res += pow(GetCoords()->Get(i).Im(), 2);
    }
    return sqrt(res);
}
