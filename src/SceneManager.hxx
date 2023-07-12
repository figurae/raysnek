#pragma once

#include "ResourceManager.hxx" // for ResourceManager
#include "Scene.hxx"           // for Scene
#include <memory>              // for unique_ptr
#include <string_view>         // for hash, operator==, string_view
#include <unordered_map>       // for unordered_map

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
  std::unique_ptr<ResourceManager> m_resourceManager{};

private:
  void createScene(SceneName name);
};
