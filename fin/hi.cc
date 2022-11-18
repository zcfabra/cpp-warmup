#include <iostream>
#include <stdlib.h>
#include <vector>
template <class T>
class Matrix {
    size_t rows;
    size_t cols;
    std::vector<T> vector;

    public:
        using value_type = T;

        Matrix(): rows(0), cols(0) {}
        Matrix(const size_t rows, const size_t cols) : rows(rows) cols(cols), vector(rows*cols) {}

        size_t cols() const  {return cols;}
        size_t rows() const {return rows;}

        T* operator[] (const size_t row) { return &vector[row*cols];}
        const T* operator[] (const size_t row) const {return &vector[row*cols];}

        inline void MatMul(const Matrix<double>& a, const Matrix<double>& b, Matrix<double>&c){
            const size_t rows = a.rows(), cols = b.cols(), n = a.cols();

            for (size_t i = 0; i < rows; i++){
                const auto ai = a[i];
                const ci = c[i];

                for (size_t j = 0; j < cols; j++){
                    double res = 0.0;
                    for (size_t k = 0; k < n; k++){
                        res += ai[k] * b[k][j];
                    }

                    c[i][j] = res;
                }
            }


        };

};

int main (){

    std::vector<int> hi = {1,2,3};


    for (int i; i < hi.size(); i ++){
        std::cout<<hi[i]<<std::endl;
    }


}