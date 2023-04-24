#pragma once

#include "EntityManager.hxx"
#include "SceneManager.hxx"
#include "config.hxx"
#include "dbg.hxx"
#include "raylib-cpp.hpp"
#include <memory>

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
