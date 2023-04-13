#pragma once

#include <string>
#include <tuple>

// TODO: implement second typename
// and handle casting to different types
template <typename T> struct Vector2D {
  T m_a;
  T m_b;

  Vector2D() = default;
  Vector2D(T a, T b) : m_a(a), m_b(b) {}

  Vector2D operator+(Vector2D &other) {
    return Vector2D(m_a + other.m_a, m_b + other.m_b);
  }

  Vector2D operator-(Vector2D &other) {
    return Vector2D(m_a - other.m_a, m_b - other.m_b);
  }

  // TODO: make sure this produces correct types
  Vector2D operator*(T scalar) { return Vector2D(m_a * scalar, m_b * scalar); }

  Vector2D operator/(T scalar) { return this * (1 / scalar); }

  Vector2D &operator+=(Vector2D &other) {
    m_a += other.m_a;
    m_b += other.m_b;
    return *this;
  }

  Vector2D &operator-=(Vector2D &other) {
    m_a -= other.m_a;
    m_b -= other.m_b;
    return *this;
  }

  Vector2D &operator*=(T scalar) {
    m_a *= scalar;
    m_b *= scalar;
    return *this;
  }

  Vector2D &operator/=(T scalar) {
    m_a /= scalar;
    m_b /= scalar;
    return *this;
  }

  // TODO: check how to make LSP formatter
  // split this return nicely
  std::string to_string() {
    return std::string('(' + std::to_string(m_a) + ", " + std::to_string(m_b) +
                       ')');
  }
};

template <typename T> struct Rect {
  Vector2D<T> m_position;
  Vector2D<T> m_size;

  Rect() = default;
  Rect(Vector2D<T> &position, Vector2D<T> &size)
      : m_position(position), m_size(size) {}

  std::string to_string() {
    return std::string("pos: " + m_position.to_string() +
                       "; size: " + m_size.to_string());
  }

  std::tuple<Vector2D<T>> getCoordinates() {
    // TODO: does this need optimizing or
    // does the compiler do it automatically?
    return std::make_tuple(m_position, m_position + m_size);
  }

  bool isIntersecting(Rect &other) {
    // TODO: likewise, should I optimize this by hand?
    // this looks like an awful lot of copying that could
    // be omitted if I sacrifice readability
    Vector2D<T> aC1, aC2, bC1, bC2;

    std::tie(aC1, aC2) = getCoordinates();
    std::tie(bC1, bC2) = other.getCoordinates();

    // TODO: argh, LSP formatter, y u so ugly
    return aC1.m_a < bC2.m_a && aC2.m_a > bC1.m_a && aC1.m_b < bC2.m_b &&
           aC2.m_b > bC1.m_b;
  }
};
