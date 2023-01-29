#include "raylib.h"

int main(){
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Olá, Matheus!");

    // circle dimensions
    int circle_x{width/2};
    int circle_y{height/2};
    int circle_radius{25};

    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int t_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};

    int direction{10};

    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic
        DrawCircle(circle_x, circle_y, circle_radius, BLUE);//centerX, centerY, radius, color 
        DrawRectangle(axe_x, axe_y, 25, 70, BLACK);//x, y, width, height, color

        axe_y += direction;
        if(axe_y > height - 70 || axe_y < 0){
            direction *= -1;
        }

        if((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && circle_x < width - circle_radius ){
            circle_x += 10;
        }

        if((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && circle_x > 0 + circle_radius){
            circle_x -= 10;
        }

        if((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && circle_y > 0 + circle_radius){
            circle_y -= 10;
        }
        
        if((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && circle_y < height - circle_radius){
            circle_y += 10;
        }

        EndDrawing();
    }

    return 0;
}