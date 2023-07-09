#pragma once

#include "Entity.hxx"       // for Viewport
#include "SceneManager.hxx" // for SceneManager
#include "Window.hpp"       // for Window
#include "config.hxx"       // for GAME_TITLE, GAME_VERSION
#include <memory>           // for allocator, make_unique, unique_ptr
#include <string>           // for operator+, char_traits, string

class Game {
  int m_screenWidth{800};
  int m_screenHeight{450};
  std::string m_titleBar{GAME_TITLE + ' ' + GAME_VERSION};
  const std::unique_ptr<raylib::Window> m_window{};

  const Viewport m_viewport{};
  const SceneManager m_sceneManager{};
  // EntityManager m_entityManager{};

  float m_dT{};

  void initialize() const;
  void handleInput() const;
  void update() const;
  void draw() const;

public:
  void run() const;
};
