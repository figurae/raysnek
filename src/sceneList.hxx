#pragma once

#include "SceneManager.hxx"
#include <array>

const std::array sceneList{std::to_array<Scene>(
    {MenuScene({.sceneName = "Main Menu"}, {.menuItems = {"Play", "Quit"}}),
     LevelScene({.sceneName = "Level"})})};
