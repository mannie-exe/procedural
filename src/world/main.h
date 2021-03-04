#pragma once

struct World;
struct World generateWorld(int xSize, int ySize, int initialSeed);
void RegenWorld(struct World *world, int newSeed);
void DeleteWorld(struct World *world);

#include "./main.c"
