#pragma once

struct Rectangle CreateWindow(char *title);
struct Rectangle getScaledCanvasRect(struct Rectangle canvasSrc, struct Rectangle windowSize);

#include "./main.c"
