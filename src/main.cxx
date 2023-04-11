#include "raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int screenWidth = 800;
int screenHeight = 450;
const char* windowTitle = "raysnek 0.1"; // TODO: make it read version number from CMakeLists.txt

void Update(void) {
    // TODO: to be implemented
}

void Draw(void) {
    BeginDrawing();

        ClearBackground(BLACK);
        DrawText("Welcome to RAYSNEK", 190, 200, 20, RAYWHITE);

    EndDrawing();
}

int main()
{
    raylib::Window window(screenWidth, screenHeight, windowTitle);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        Update();
        Draw();
    }
#endif

    return 0;
}

