#pragma once

#include <memory>        // for unique_ptr
#include <string_view>   // for string_view, hash, operator==
#include <unordered_map> // for unordered_map
#include <vector>        // for vector

enum struct SceneType { Unknown, Menu, InGame, Count };

struct Scene {
  const std::string_view sceneName{};
  const SceneType sceneType{};

  // TODO: check the rule of six
  Scene(const char *name, const SceneType type = SceneType::Unknown)
      : sceneName(name), sceneType(type) {}
};

struct MenuScene : Scene {
  const std::vector<std::string_view> menuItems{};

  MenuScene(const char *name) : Scene(name, SceneType::Menu) {}
};

struct InGameScene : Scene {
  InGameScene(const char *name) : Scene(name, SceneType::InGame) {}
};

using SceneName = std::string_view;
using UniqueScene = std::unique_ptr<Scene>;

class SceneManager {
public:
  SceneName getCurrentSceneName() const { return m_currentSceneName; }
  // TODO: is it fine to return a raw pointer here?
  Scene *getCurrentScene() const {
    return m_scenes.at(m_currentSceneName).get();
  }
  Scene *getScene(SceneName sceneName) const {
    return m_scenes.at(sceneName).get();
  }
  void loadScene(const Scene &scene) const {
    // TODO: implement
  }
  // TODO: would it be better in a constructor?
  void initialize();

private:
  std::unordered_map<SceneName, UniqueScene> m_scenes{};
  SceneName m_currentSceneName{};
private:
  void createScene(SceneName name);
};
