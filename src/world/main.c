#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "utils/opensimplex/main.h"

struct World
{
    double *data;
    int64_t seed;
    int xSize;
    int ySize;
};

void *FillNoisePattern(struct World *world)
{
    const struct osn_context *osnGenerator;
    open_simplex_noise((int64_t)(world->seed), &osnGenerator);
    for (int idxA = 0; idxA < world->xSize; idxA++)
    {
        for (int idxB = 0; idxB < world->ySize; idxB++)
        {
            const int currIdx = (idxA + 1) * (idxB + 1) - 1;
            const double currValue = open_simplex_noise2(osnGenerator, (double)idxA, (double)idxB);
            world->data[currIdx] = currValue;
        }
    }
    free(osnGenerator);
}

struct World generateWorld(int xSize, int ySize, int64_t initialSeed)
{
    const int worldSize = xSize * ySize;
    const int worldDataSize = sizeof(double) * worldSize;
    double *noisePattern = (double *)malloc(worldDataSize);

    if (!noisePattern)
    {
        perror("Could not build world; no memory or invalid size");
        abort();
    }

    struct World world = (struct World){.data = noisePattern, .seed = initialSeed, .xSize = xSize, .ySize = ySize};
    FillNoisePattern(&world);
    return world;
}

void RegenWorld(struct World *world, int64_t newSeed)
{
    world->seed = newSeed;
    FillNoisePattern(world);
}

void DeleteWorld(struct World *world)
{
    free(world->data);
    world = NULL;
}
