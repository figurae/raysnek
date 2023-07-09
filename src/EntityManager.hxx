#pragma once

#include "Entity.hxx"
#include <memory>

class EntityManager {
private:
  std::vector<std::unique_ptr<Entity>> m_entities{};
  std::unique_ptr<Viewport> m_viewport{};
};
