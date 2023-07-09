#include "Game.hxx" // for Game
#include <memory>   // for make_unique, unique_ptr

int main() {
  auto game = std::make_unique<Game>();
  game->run();

  return 0;
}
