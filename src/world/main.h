#pragma once
#include "./main.c"

struct World;
struct World generateWorld(int xSize, int ySize);
void RegenWorld(struct World *world, int seed);
