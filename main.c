#include <stdio.h>
#include <raylib.h>
#include "world/world.h"

int main(void)
{
    struct World world = generateWorld(200, 200);

    const int screenWidth = 200;
    const int screenHeight = 200;
    InitWindow(screenWidth, screenHeight, "procedural - zer0cell");
    SetTargetFPS(60);

    // Camera3D camera = {0};
    // camera.position = (Vector3){5.0f, 2.0f, 5.0f};
    // camera.target = (Vector3){0.0f, 1.8f, 0.0f};
    // camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    // camera.fovy = 45.0f;
    // camera.type = CAMERA_PERSPECTIVE;
    // SetCameraMode(camera, CAMERA_FIRST_PERSON);

    while (!WindowShouldClose())
    {
        // float delta = GetFrameTime();
        // UpdateCamera(&camera);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        // BeginMode3D(camera);
        // DrawGrid(10, 1.0f);
        // EndMode3D();
        // for (int idxA = 0; idxA < world.xSize; idxA++)
        // {
        //     for (int idxB = 0; idxB < world.xSize; idxB++)
        //     {
        //         const int currIdx = (idxA + 1) * (idxB + 1) - 1;
        //         const float currPerlinValue = world.data[currIdx];
        //         printf("%d", currPerlinValue);
        //         // DrawPixel(idxA, idxB, (Color){0, 0, 0, (int)currPerlinValue * 255});
        //     }
        // }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
