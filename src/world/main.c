#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "utils/perlin/main.h"

struct World
{
    float *data;
    int seed;
    int xSize;
    int ySize;
};

float *fillPerlinWorld(float *world, int xSize, int ySize, int seed)
{
    for (int idxA = 0; idxA < xSize; idxA++)
    {
        for (int idxB = 0; idxB < ySize; idxB++)
        {
            const int currIdx = (idxA + 1) * (idxB + 1) - 1;
            const float currPerlinValue = perlin2d((float)(idxA + seed), (float)(idxB + seed), 0.33F, 10);
            world[currIdx] = currPerlinValue;
        }
    }
}

struct World generateWorld(int xSize, int ySize, int seed)
{
    const int worldSize = xSize * ySize;
    const int worldDataSize = sizeof(float) * worldSize;
    float *perlinWorld = (float *)malloc(worldDataSize);

    if (!perlinWorld)
    {
        perror("Could not build world; no memory or invalid size");
        abort();
    }

    fillPerlinWorld(perlinWorld, xSize, ySize, seed);

    return (struct World){.data = perlinWorld, .seed = seed, .xSize = xSize, .ySize = ySize};
}

void RegenWorld(struct World *world, int seed)
{
    fillPerlinWorld((*world).data, (*world).xSize, (*world).ySize, (*world).seed);
    (*world).seed = seed;
}
