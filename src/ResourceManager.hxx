#pragma once

#include "EntityManager.hxx"
#include "Scene.hxx"
#include <memory>

class ResourceManager {
public:
  ResourceManager();
  void loadResources(const Scene &scene) const;

private:
  std::unique_ptr<EntityManager> m_entityManager{};
  // std::unique_ptr<MenuManager> m_menuManager{};
};
