#include "SceneManager.hxx"
#include "sceneList.hxx" // for sceneList
#include <array>         // for array

SceneManager::SceneManager() : m_currentSceneName(sceneList[0].sceneName) {
  for (const auto &scene : sceneList) {
    m_scenes.emplace(scene.sceneName, std::make_unique<Scene>(scene));
  }
}

void SceneManager::loadScene(const Scene &scene) const {
  // TODO: implement
}
