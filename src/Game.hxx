#pragma once
// TODO: split into hxx/cxx

#include "Viewport.hxx"
#include "config.hxx"
#include "dbg.hxx"
#include "raylib-cpp.hpp"
#include <memory>

class Game {
  int m_screenWidth{800};
  int m_screenHeight{450};
  std::string m_titleBar{GAME_TITLE + ' ' + GAME_VERSION};
  std::unique_ptr<raylib::Window> m_window;

  Viewport m_viewport{};
  // EntityManager m_entityManager{};

  float m_dT{};

public:
  Game() = default;
  ~Game() = default;

  // TODO: maybe run() should be the only public method?
  void run() {
    initialize();

    while (!m_window->ShouldClose()) {
      update();
      draw();
    }
  }

  void initialize() {
    // TODO: is this the right place for this?
    // maybe place this in the constuctor?
    m_window->Init(m_screenWidth, 450, "aaa");

    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);
  }

  void draw() {
    BeginDrawing();

    ClearBackground(BLACK);

    EndDrawing();
  }

  void update() {}
};
