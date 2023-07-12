#pragma once

#include "Entity.hxx"
#include <memory>
#include <string_view> // for string_view, hash, operator==
#include <vector>      // for vector

enum struct SceneType { Undefined, Menu, Level, Count };

struct SceneParams {
  const std::string_view sceneName{"Undefined Scene"};
};

class Scene {
public:
  const std::string_view getSceneName() const { return m_sceneName; }
  const SceneType getSceneType() const { return m_sceneType; }

protected:
  Scene(const SceneParams &params, const SceneType type)
      : m_sceneName(params.sceneName), m_sceneType(type) {}

private:
  const std::string_view m_sceneName{};
  const SceneType m_sceneType{SceneType::Undefined};
};

struct MenuSceneParams {
  const std::vector<std::string_view> menuItems{"Undefined Menu Item"};
};

class MenuScene : public Scene {
public:
  MenuScene(const SceneParams &params, const MenuSceneParams &menuParams)
      : Scene(params, SceneType::Menu), m_menuItems(menuParams.menuItems) {}
  const std::vector<std::string_view> &getMenuItems() const {
    return m_menuItems;
  }

private:
  const std::vector<std::string_view> m_menuItems{};
};

using UniqueEntity = std::unique_ptr<Entity>;
using UniqueEntityVector = std::unique_ptr<std::vector<UniqueEntity>>;

class LevelScene : public Scene {
public:
  LevelScene(const SceneParams &params) : Scene(params, SceneType::Level) {}
  void addEntity(UniqueEntity &entity) {
    m_entities->emplace_back(std::move(entity));
  }

private:
  UniqueEntityVector m_entities{};
};
