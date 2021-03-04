#include <stdio.h>
#include <raylib.h>
#include "window/main.h"
#include "world/main.h"

int main(void)
{
    SetTraceLogLevel(LOG_DEBUG);
    struct World world = generateWorld(500, 500, (int64_t)0);

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    struct Rectangle windowSize = CreateWindow("procedural - zer0cell");
    RenderTexture2D canvas = LoadRenderTexture(world.xSize, world.ySize);

    while (!WindowShouldClose())
    {
        // TODO: Implement fullscreen toggling
        // May need to read about window configuration options
        // Make it borderless fullscreen by default.
        // if (IsKeyReleased(KEY_ENTER) || IsKeyReleased(KEY_KP_ENTER))
        // {
        //     ToggleFullscreen();
        // }

        float delta = GetFrameTime();

        BeginTextureMode(canvas);
        ClearBackground(RAYWHITE);

        for (int idxA = 0; idxA < world.xSize; idxA++)
        {
            for (int idxB = 0; idxB < world.xSize; idxB++)
            {
                const int currIdx = (idxA + 1) * (idxB + 1) - 1;
                const double currValue = world.data[currIdx];
                const int flippedY = world.ySize - (idxB + 1); // Used because texture buffers are added to from the other direction.
                DrawPixel(idxA, flippedY, (Color){0, 0, 0, (int)(currValue * 255)});
            }
        }

        EndTextureMode();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        const struct Rectangle canvasSrc = (Rectangle){.width = canvas.texture.width, .height = canvas.texture.height};
        const struct Rectangle canvasDest = getScaledCanvasRect(canvasSrc, windowSize);

        DrawTexturePro(canvas.texture, canvasSrc, canvasDest, (Vector2){0, 0}, 0.0F, RAYWHITE);

        RegenWorld(&world, (int64_t)(world.seed + delta * 60));

        EndDrawing();
    }

    CloseWindow();
    DeleteWorld(&world);
    return 0;
}
