#include "raylib.h"
#include "raymath.h"

int main(void)
{
  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "procedural - zer0cell");
  SetTargetFPS(60);

  Camera3D camera = {0};
  camera.position = (Vector3){5.0f, 2.0f, 5.0f};
  camera.target = (Vector3){0.0f, 1.8f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.type = CAMERA_PERSPECTIVE;
  SetCameraMode(camera, CAMERA_FIRST_PERSON);

  while (!WindowShouldClose())
  {
    // float delta = GetFrameTime();
    UpdateCamera(&camera);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);

    DrawGrid(10, 1.0f);

    EndMode3D();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
