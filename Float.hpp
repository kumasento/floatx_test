#ifndef __FLOAT_HPP__
#define __FLOAT_HPP__

#define FLOAT_ATTRS
#define FLOAT_INLINE inline

namespace Float {

template <int E, int S>
class Float {
 public:
  FLOAT_ATTRS Float() noexcept {}

  template <typename T>
  FLOAT_ATTRS Float(const T& other) noexcept {}

  template <typename T>
  FLOAT_ATTRS Float& operator=(const T& other) noexcept {
    return *this = Float(other);
  }
};

}  // namespace Float

#endif
