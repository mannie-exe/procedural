#include <stdio.h>
#include <raylib.h>

void AdjustWindowPosition(struct Rectangle *windowDimensions, struct Rectangle monitorSize)
{
    windowDimensions->x = (int)(monitorSize.width - windowDimensions->width) / 2;
    windowDimensions->y = (int)(monitorSize.height - windowDimensions->height) / 2;
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
    printf("Scaled window: %dx%d <- %dx%d @ %d (target <- max @ fps)\n", targetWidth, targetHeight, maxWidth, maxHeight, fps);

    struct Rectangle windowDimensions = (struct Rectangle){.width = targetWidth, .height = targetHeight};
    AdjustWindowPosition(&windowDimensions, (struct Rectangle){.width = maxWidth, .height = maxHeight});
    SetWindowPosition(windowDimensions.x, windowDimensions.y);
    printf("Set window position to: %d,%d\n", windowDimensions.x, windowDimensions.y);

    return windowDimensions;
}
