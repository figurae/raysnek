#include "Game.hxx"
#include "sceneList.hxx" // for sceneList
#include <array>         // for array
#include <memory>
#include <raylib.h>    // for BeginDrawing, ClearBackground, EndDrawing
#include <type_traits> // for enable_if_t

Game::Game()
    : m_sceneManager(std::make_unique<SceneManager>()),
      m_window(std::make_unique<raylib::Window>()) {
  // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  // TODO: does this need to be handled on exit?
  m_window->Init(m_screenWidth, m_screenHeight, m_titleBar);
  SetTargetFPS(60);
}

void Game::run() const {
  m_sceneManager->loadScene(sceneList[1]);

  while (!m_window->ShouldClose()) {
    handleInput();
    update();
    draw();
  }
};

void Game::handleInput() const {}

void Game::update() const {}

void Game::draw() const {
  BeginDrawing();

  ClearBackground(BLACK);

  EndDrawing();
}
