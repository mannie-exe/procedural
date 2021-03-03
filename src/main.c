#include <stdio.h>
#include <raylib.h>
#include "window/main.h"
#include "world/main.h"

struct Rectangle getScaledCanvasRect(struct Rectangle canvasSrc, struct Rectangle windowSize);

int main(void)
{
    struct World world = generateWorld(500, 500, 0);

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
                const float currPerlinValue = world.data[currIdx];
                const int flippedY = world.ySize - (idxB + 1); // Used because texture buffers are added to from the other direction.
                DrawPixel(idxA, flippedY, (Color){0, 0, 0, (int)(currPerlinValue * 255)});
            }
        }

        EndTextureMode();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        const struct Rectangle canvasSrc = (Rectangle){.width = canvas.texture.width, .height = canvas.texture.height};
        const struct Rectangle canvasDest = getScaledCanvasRect(canvasSrc, windowSize);

        DrawTexturePro(canvas.texture, canvasSrc, canvasDest, (Vector2){0, 0}, 0.0F, RAYWHITE);

        EndDrawing();

        RegenWorld(&world, world.seed + (int)(delta * 8));
    }

    CloseWindow();
    free(world.data);
    return 0;
}

struct Rectangle getScaledCanvasRect(struct Rectangle canvasSrc, struct Rectangle windowSize)
{
    float length, x, y;

    if (windowSize.height > windowSize.width)
    {
        length = windowSize.width;
        y = (windowSize.height - length) / 2;
        x = 0.0F;
    }
    else
    {
        length = windowSize.height;
        x = (windowSize.width - length) / 2;
        y = 0.0F;
    }

    return (Rectangle){.x = x, .y = y, .width = length, .height = length};
}
