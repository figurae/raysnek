#include "SceneManager.hxx"
#include "sceneList.hxx"

void SceneManager::initialize() {
  m_currentSceneName = sceneList[0].sceneName;

  for (auto& scene : sceneList) {
    m_scenes.emplace(scene.sceneName, scene);
  }
}
