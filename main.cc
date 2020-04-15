#include <iostream>
#include <floatx.hpp>
#include <Eigen/Core>

typedef flx::floatx<5, 5, float> msfp11;

// https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
int main(int argc, char *argv[]) {

  typedef Eigen::Matrix<msfp11, 4, 4> Mat;

  Mat A, B, C;
  C = A * B;

  return 0;
}