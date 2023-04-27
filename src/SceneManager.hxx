#pragma once

#include <memory>
#include <string_view>
#include <unordered_map>
#include <vector>

enum struct SceneType { Unknown, Menu, InGame, Count };

struct Scene {
  // TODO: check the rule of six
  Scene(const char *name, const SceneType type = SceneType::Unknown)
      : sceneName(name), sceneType(type) {}

  const std::string_view sceneName{};
  const SceneType sceneType{};
};

struct MenuScene : Scene {
  MenuScene(const char *name) : Scene(name, SceneType::Menu) {}

  const std::vector<std::string_view> menuItems{};
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
  // TODO: would it be better in a constructor?
  void initialize();

private:
  std::unordered_map<SceneName, UniqueScene> m_scenes{};
  SceneName m_currentSceneName{};

  void createScene(SceneName name);
};
