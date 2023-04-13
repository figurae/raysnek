#pragma once

#include "Math.hxx"

class Viewport {
  Vector2D<float> m_position{};
  Vector2D<float> m_target{};
  Vector2D<float> m_offset{};
  float m_zoom{1.0f};
  float m_rotation{};
};
