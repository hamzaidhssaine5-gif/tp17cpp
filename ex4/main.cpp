#include <iostream>
#include <array>
#include <stdexcept>

template<typename T, size_t N, size_t M>
class Matrix {
private:
    std::array<std::array<T, M>, N> data{};

public:
    Matrix() {
        for (auto& row : data)
            row.fill(T{});
    }

    T& at(size_t i, size_t j) {
        if (i >= N || j >= M)
            throw std::out_of_range("Index out of range");
        return data[i][j];
    }

    const T& at(size_t i, size_t j) const {
        if (i >= N || j >= M)
            throw std::out_of_range("Index out of range");
        return data[i][j];
    }

    Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result;
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < M; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    template<size_t P>
    Matrix<T, N, P> operator*(const Matrix<T, M, P>& other) const {
        Matrix<T, N, P> result;
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < P; ++j) {
                T sum = T{};
                for (size_t k = 0; k < M; ++k)
                    sum += data[i][k] * other.data[k][j];
                result.at(i, j) = sum;
            }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& mat) {
        for (size_t i = 0; i < N; ++i) {
            os << "[ ";
            for (size_t j = 0; j < M; ++j)
                os << mat.data[i][j] << ' ';
            os << "]\n";
        }
        return os;
    }
};

int main() {
    Matrix<int, 2, 2> A, B;
    A.at(0, 0) = 1; A.at(0, 1) = 2;
    A.at(1, 0) = 3; A.at(1, 1) = 4;

    B.at(0, 0) = 5; B.at(0, 1) = 6;
    B.at(1, 0) = 7; B.at(1, 1) = 8;

    auto C = A + B;
    std::cout << "A + B =\n" << C << std::endl;

    auto D = A * B;
    std::cout << "A * B =\n" << D << std::endl;

    Matrix<double, 3, 3> M1, M2;
    M1.at(0,0) = 1.1; M1.at(0,1) = 2.2; M1.at(0,2) = 3.3;
    M1.at(1,0) = 4.4; M1.at(1,1) = 5.5; M1.at(1,2) = 6.6;
    M1.at(2,0) = 7.7; M1.at(2,1) = 8.8; M1.at(2,2) = 9.9;

    M2.at(0,0) = 9.9; M2.at(0,1) = 8.8; M2.at(0,2) = 7.7;
    M2.at(1,0) = 6.6; M2.at(1,1) = 5.5; M2.at(1,2) = 4.4;
    M2.at(2,0) = 3.3; M2.at(2,1) = 2.2; M2.at(2,2) = 1.1;

    auto M3 = M1 * M2;
    std::cout << "M1 * M2 =\n" << M3 << std::endl;

    return 0;
}
