#include "Game.hxx"
#include <memory>

/* #if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif */

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
