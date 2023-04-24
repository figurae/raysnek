#pragma once

#include <memory>
#include <unordered_map>

enum struct SceneType { Menu, InGame, Count };
enum struct Scene { MainMenu, Level01, Count };

using SceneContainer = std::unordered_map<int, int>; // TODO
using SharedSceneContainer = std::shared_ptr<SceneContainer>;

class SceneManager {
  std::unordered_map<Scene, SharedSceneContainer> m_scenes{};
  Scene m_currentScene{Scene::MainMenu};

public:
  Scene getCurrentScene() const { return m_currentScene; }
  //TODO: will this be used?
  void setCurrentScene(Scene newScene) { m_currentScene = newScene; }

  SharedSceneContainer getCurrentSceneContainer() const {
    return m_scenes.at(m_currentScene);
  }
};
