
/* #if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif */
#include "Game.hxx" // for Game
#include <memory>   // for make_unique, unique_ptr

int main() {
  auto game = std::make_unique<Game>();
  game->run();

  /* #if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
  #else
    // non-web stuff goes here
  #endif */

  return 0;
}
