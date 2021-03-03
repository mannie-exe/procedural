#include <stdio.h>
#include <raylib.h>

struct IntVector2
{
    int x;
    int y;
};

struct IntVector2 FindCenterOffset(struct IntVector2 windowSize, struct IntVector2 monitorSize)
{
    const int newX = (monitorSize.x - windowSize.x) / 2;
    const int newY = (monitorSize.y - windowSize.y) / 2;
    return (struct IntVector2){.x = newX, .y = newY};
}

void CreateWindow(char *title, float resolutionFactor)
{
    if (!resolutionFactor)
    {
        resolutionFactor = 1.0F;
    }

    printf("Creating new window");
    printf("%s, %f (title, resolutionFactor)\n", title, resolutionFactor);
    InitWindow(0, 0, title);

    const int maxWidth = GetMonitorWidth(0);
    const int maxHeight = GetMonitorHeight(0);
    const int targetWidth = (int)(maxWidth * 0.7F);
    const int targetHeight = (int)(maxHeight * 0.7F);
    printf("%dx%d <- %dx%d (target <- max)\n", targetWidth, targetHeight, maxWidth, maxHeight);
    SetWindowSize(targetWidth, targetHeight);
    SetTargetFPS(60);

    const struct IntVector2 windowPosition = FindCenterOffset((struct IntVector2){.x = targetWidth, .y = targetHeight}, (struct IntVector2){.x = maxWidth, .y = maxHeight});
    printf("Setting position to: %d,%d\n", windowPosition.x, windowPosition.y);
    SetWindowPosition(windowPosition.x, windowPosition.y);
}
