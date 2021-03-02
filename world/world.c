#include <stdio.h>
#include <raylib.h>
#include "../utils/perlin.h"

struct World
{
    float *data;
    int xSize;
    int ySize;
};

struct World generateWorld(int xSize, int ySize)
{
    const int worldSize = xSize * ySize;
    const int worldDataSize = sizeof(float) * worldSize;
    float *perlinWorld = malloc(worldDataSize);

    if (!perlinWorld)
    {
        perror("Could not build world, no memory or invalid size");
        abort();
    }

    // for (int idxA = 0; idxA < xSize; idxA++)
    // {
    //     for (int idxB = 0; idxB < ySize; idxB++)
    //     {
    //         const int currIdx = (idxA + 1) * (idxB + 1) - 1;
    //         const float currPerlinValue = perlin2d((float)idxA, (float)idxB, 0.33F, 10);
    //         printf("%f: %d\n", currPerlinValue, currIdx);
    //         perlinWorld[currIdx] = currPerlinValue;
    //         printf("Assigned successfully");
    //     }
    // }

    struct World newWorld;
    newWorld.data = perlinWorld;
    newWorld.xSize = xSize;
    newWorld.ySize = ySize;

    return newWorld;
}
