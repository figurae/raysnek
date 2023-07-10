#pragma once

#include "SceneManager.hxx"
#include <array>

const std::array sceneList{
    std::to_array<Scene>({MenuScene("Main Menu"), LevelScene("Level")})};
