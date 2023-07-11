#pragma once

#include "Math.hxx"
#include <memory>
#include <vector>

struct EntityParams {
  std::string_view entityName = "Undefined Entity";
  Vector2D<float> position{};
};

class Entity {
public:
  const std::string_view getEntityName() const { return m_entityName; }

protected:
  Entity(const EntityParams &params)
      : m_entityName(params.entityName), m_position(params.position) {}

private:
  std::string_view m_entityName{};
  Vector2D<float> m_position{};
};

struct MoveableEntityParams {
  Vector2D<float> velocity{};
};

class MoveableEntity : public Entity {
protected:
  MoveableEntity(const EntityParams &params,
                 const MoveableEntityParams &moveableParams)
      : Entity(params), m_velocity(moveableParams.velocity) {}

private:
  Vector2D<float> m_velocity{};
};

struct ViewportParams {
  Vector2D<float> target{};
  Vector2D<float> offset{};
};

class Viewport : public MoveableEntity {
public:
  Viewport(const EntityParams &params,
           const MoveableEntityParams &moveableParams,
           const ViewportParams &viewportParams)
      : MoveableEntity(params, moveableParams), m_target(viewportParams.target),
        m_offset(viewportParams.offset) {}

private:
  Vector2D<float> m_target{};
  Vector2D<float> m_offset{};
  // float m_zoom{1.0f};
  // float m_rotation{};
};

class Player : public MoveableEntity {
private:
  // std::vector<Segment> body{};
};
