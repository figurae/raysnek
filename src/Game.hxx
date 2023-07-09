#pragma once

#include <memory>            // for allocator, make_unique, unique_ptr
#include <string>            // for operator+, char_traits, string
#include "SceneManager.hxx"  // for SceneManager
#include "Window.hpp"        // for Window
#include "config.hxx"        // for GAME_TITLE, GAME_VERSION

class Game {
  int m_screenWidth{800};
  int m_screenHeight{450};
  std::string m_titleBar{GAME_TITLE + ' ' + GAME_VERSION};
  const std::unique_ptr<raylib::Window> m_window{};

  const std::unique_ptr<SceneManager> m_sceneManager{};

  float m_dT{};

  void initialize() const;
  void handleInput() const;
  void update() const;
  void draw() const;

public:
  Game() : m_sceneManager(std::make_unique<SceneManager>()) {}
  void run() const;
};
