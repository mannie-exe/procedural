#include <stdio.h>
#include <raylib.h>
#include "window/main.h"
#include "world/main.h"

int main(void)
{
    struct World world = generateWorld(500, 500, 0);

    CreateWindow("procedural - zer0cell", 1.0F);

    // Camera3D camera = {0};
    // camera.position = (Vector3){5.0f, 2.0f, 5.0f};
    // camera.target = (Vector3){0.0f, 1.8f, 0.0f};
    // camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    // camera.fovy = 45.0f;
    // camera.type = CAMERA_PERSPECTIVE;
    // SetCameraMode(camera, CAMERA_FIRST_PERSON);

    while (!WindowShouldClose())
    {
        // TODO: Implement fullscreen toggling
        // May need to read about window configuration options
        // Make it borderless fullscreen by default.
        // if (IsKeyReleased(KEY_ENTER) || IsKeyReleased(KEY_KP_ENTER))
        // {
        //     ToggleFullscreen();
        // }

        // float delta = GetFrameTime();
        // UpdateCamera(&camera);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        const int centerOffsetX = (GetScreenWidth() - world.xSize) / 2;
        const int centerOffsetY = (GetScreenHeight() - world.ySize) / 2;

        for (int idxA = 0; idxA < world.xSize; idxA++)
        {
            for (int idxB = 0; idxB < world.xSize; idxB++)
            {
                const int currIdx = (idxA + 1) * (idxB + 1) - 1;
                const float currPerlinValue = world.data[currIdx];
                DrawPixel(idxA + centerOffsetX, idxB + centerOffsetY, (Color){0, 0, 0, (int)(currPerlinValue * 255)});
            }
        }

        EndDrawing();
        regenWorld(&world, world.seed + 4);
    }

    CloseWindow();
    free(world.data);
    return 0;
}
