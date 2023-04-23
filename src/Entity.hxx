#pragma once

#include "Math.hxx"
#include <vector>

class Entity {
  Vector2D<float> m_position{};
};

class MoveableEntity : public Entity {
  Vector2D<float> m_velocity{};
};

class Viewport : public MoveableEntity {
  Vector2D<float> m_target{};
  Vector2D<float> m_offset{};
  // float m_zoom{1.0f};
  // float m_rotation{};
};

class Player : public MoveableEntity {
  // std::vector<Segment> body{};
};
