#pragma once

#include <string>
#include <tuple>

// TODO: implement second typename
// and handle casting to different types
template <typename T> struct Vector2D {
  T m_x;
  T m_y;

  Vector2D() = default;
  Vector2D(T x, T y) : m_x(x), m_y(y) {}

  Vector2D operator+(const Vector2D &other) {
    return Vector2D(m_x + other.m_x, m_y + other.m_y);
  }

  Vector2D operator-(const Vector2D &other) {
    return Vector2D(m_x - other.m_x, m_y - other.m_y);
  }

  // TODO: make sure this produces correct types
  Vector2D operator*(T scalar) { return Vector2D(m_x * scalar, m_y * scalar); }
  Vector2D operator/(T scalar) { return this * (1 / scalar); }

  Vector2D &operator+=(const Vector2D &other) {
    m_x += other.m_x;
    m_y += other.m_y;
    return *this;
  }

  Vector2D &operator-=(const Vector2D &other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    return *this;
  }

  Vector2D &operator*=(const T scalar) {
    m_x *= scalar;
    m_y *= scalar;
    return *this;
  }

  Vector2D &operator/=(const T scalar) {
    m_x /= scalar;
    m_y /= scalar;
    return *this;
  }

  // TODO: check how to make LSP formatter
  // split this return nicely
  std::string to_string() {
    return std::string('(' + std::to_string(m_x) + ", " + std::to_string(m_y) +
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
    return aC1.m_x < bC2.m_x && aC2.m_x > bC1.m_x && aC1.m_y < bC2.m_y &&
           aC2.m_y > bC1.m_y;
  }
};
