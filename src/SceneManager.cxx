#include "SceneManager.hxx"
#include "sceneList.hxx" // for sceneList
#include <array>         // for array
#include <type_traits>   // for enable_if_t

void SceneManager::initialize() {
  m_currentSceneName = sceneList[0].sceneName;

  for (const auto &scene : sceneList) {
    // TODO: isn't this a bit too convoluted?
    // can't sceneList be used directly?
    m_scenes.emplace(scene.sceneName, std::make_unique<Scene>(scene));
  }
}

void SceneManager::loadScene(const Scene &scene) const {
  // TODO: implement
}
