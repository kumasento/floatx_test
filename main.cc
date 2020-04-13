#include <iostream>
#include <floatx.hpp>
#include <Eigen/Core>

int main(int argc, char *argv[]) {
  typedef Eigen::Matrix<flx::floatx<4, 5>, 4, 4> Mat;

  Mat A, B, C;
  A(0, 0) = 1.23;
  C = A + B;

  std::cout << C(0, 0) << std::endl;

  return 0;
}