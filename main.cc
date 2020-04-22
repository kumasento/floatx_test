#include <iostream>
#include <chrono>
#include <floatx.hpp>
#include <Eigen/Core>
#include <Float.hpp>

typedef flx::floatx<5, 5, float> msfp11;

// https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
int main(int argc, char *argv[]) {
  typedef Eigen::Matrix<msfp11, Eigen::Dynamic, Eigen::Dynamic> Mat;

  const int sizes[5] = {8, 32, 64, 128, 256};

  for (int i = 0; i < 5; i ++) {
    auto N = sizes[i];

    Mat A, B, C;
    A = Mat::Random(N, N);
    B = Mat::Random(N, N);
    C = Mat::Zero(N, N);

    // Eigen random seems not working
    for (int j = 0; j < N; j ++)
      for (int k = 0; k < N; k ++) {
        A(j, k) = static_cast<float>(rand()) / RAND_MAX - 0.5; 
        B(j, k) = static_cast<float>(rand()) / RAND_MAX - 0.5; 
      }

    std::cout << "Running GEMM with size " << N << std::endl;

    auto start = std::chrono::steady_clock::now();
    C.noalias() = A * B;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "FloatX elapsed time: " << elapsed_seconds.count() << "s\n";

    // Reference floating point
    Eigen::MatrixXf Af(N, N), Bf(N, N), Cf(N, N);
    Af.setRandom();
    Bf.setRandom();

    start = std::chrono::steady_clock::now();
    Cf.noalias() = Af * Bf;
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "float  elapsed time: " << elapsed_seconds.count() << "s\n";
  }


  return 0;
}