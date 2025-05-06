#include "raylib/raylib.h"
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "raylib/clay_renderer_raylib.c"
#include<stdio.h>

float const ScreenWidth = 1408.0f;
float const ScreenHeight = 792.0f;

int main(void){
    //init raylib
    Clay_Raylib_Initialize((int)ScreenWidth, (int)ScreenHeight, "Moon Renderer", 0);

    //init clay
    uint64_t clayMemomrySize = Clay_MinMemorySize();
    Clay_Arena memoryArena = {
        .memory = malloc(clayMemomrySize),
        .capacity = clayMemomrySize
    };

    Clay_Dimensions clayDimension = {
        .width = ScreenWidth,
        .height = ScreenHeight
    };
    Clay_Initialize(memoryArena, clayDimension);
    

}