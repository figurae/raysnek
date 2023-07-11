#pragma once

#include "Entity.hxx"        // for Entity
#include "EntityManager.hxx" // for EntityManager
#include <memory>            // for unique_ptr
#include <string_view>       // for string_view, hash, operator==
#include <unordered_map>     // for unordered_map
#include <utility>           // for move
#include <vector>            // for vector

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
using UniqueEntityVector = std::vector<UniqueEntity>;

class LevelScene : public Scene {
public:
  LevelScene(const SceneParams &params) : Scene(params, SceneType::Level) {}
  void addEntity(UniqueEntity &entity) {
    m_entities.emplace_back(std::move(entity));
  }

private:
  UniqueEntityVector m_entities{};
};

using SceneName = std::string_view;
using UniqueScene = std::unique_ptr<Scene>;

class SceneManager {
public:
  SceneManager();
  SceneName getCurrentSceneName() const { return m_currentSceneName; }
  // TODO: is it fine to return a raw pointer here?
  Scene *getCurrentScene() const {
    return m_scenes.at(m_currentSceneName).get();
  }
  Scene *getScene(SceneName sceneName) const {
    return m_scenes.at(sceneName).get();
  }
  void loadScene(const Scene &scene) const;

private:
  std::unordered_map<SceneName, UniqueScene> m_scenes{};
  SceneName m_currentSceneName{};
  std::unique_ptr<EntityManager> m_entityManager{};

private:
  void createScene(SceneName name);
};
