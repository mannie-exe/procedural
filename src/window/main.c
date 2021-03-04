#include <stdio.h>
#include <raylib.h>

void AdjustWindowPosition(struct Rectangle *windowDimensions, struct Rectangle monitorSize)
{
    windowDimensions->x = (monitorSize.width - windowDimensions->width) / 2;
    windowDimensions->y = (monitorSize.height - windowDimensions->height) / 2;
}

struct Rectangle CreateWindow(char *title)
{
    const float resolutionFactor = 1.0F;
    InitWindow(0, 0, title);
    printf("Created new window: %s, %f (title, resolutionFactor)\n", title, resolutionFactor);

    const int fps = 60;
    const float windowScaleFactor = 0.7F;
    const int maxWidth = GetMonitorWidth(0);
    const int maxHeight = GetMonitorHeight(0);
    const int targetWidth = (int)(maxWidth * windowScaleFactor);
    const int targetHeight = (int)(maxHeight * windowScaleFactor);
    SetWindowSize(targetWidth, targetHeight);
    SetTargetFPS(60);
    printf("Scaled window: %dx%d <- %dx%d @ %d (target <- max @ fps)\n", targetWidth, targetHeight, maxWidth, maxHeight, fps);

    struct Rectangle windowDimensions = (struct Rectangle){.width = (float)targetWidth, .height = (float)targetHeight};
    AdjustWindowPosition(&windowDimensions, (struct Rectangle){.width = (float)maxWidth, .height = (float)maxHeight});
    SetWindowPosition((int)windowDimensions.x, (int)windowDimensions.y);
    printf("Set window position to: %d,%d\n", (int)windowDimensions.x, (int)windowDimensions.y);

    return windowDimensions;
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
