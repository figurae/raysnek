#include "SceneManager.hxx"
#include "sceneList.hxx" // for sceneList
#include <array>         // for array
#include <type_traits>   // for enable_if_t

void SceneManager::initialize() {
  m_currentSceneName = sceneList[0].sceneName;

  for (auto& scene : sceneList) {
    m_scenes.emplace(scene.sceneName, scene);
  }
}
