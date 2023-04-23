#include "Game.hxx"

void Game::run() const {
  initialize();

  // m_sceneManager->loadScene(Scene::Level01);
  // m_entityManager->spawnViewport();
  // m_entityManager->spawnLevel();
  // m_entityManager->spawnPlayer();

  while (!m_window->ShouldClose()) {
    handleInput();
    update();
    draw();
  }
};

void Game::initialize() const {
  // TODO: handle window cleanup on exit
  // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  m_window->Init(m_screenWidth, m_screenHeight, m_titleBar);

  SetTargetFPS(60);
}

void Game::handleInput() const {}

void Game::update() const {}

void Game::draw() const {
  BeginDrawing();

  ClearBackground(BLACK);

  EndDrawing();
}
