#pragma once

#include "SceneManager.hxx"
#include <array>

const std::array sceneList{Scene("Main Menu", SceneType::Menu),
                           Scene("Level", SceneType::InGame)};
