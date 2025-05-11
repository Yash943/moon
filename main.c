#include "raylib/raylib.h"
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "raylib/clay_renderer_raylib.c"
#include<stdio.h>

float const ScreenWidth = 1408.0f;
float const ScreenHeight = 792.0f;

void clayErrorHandler(Clay_ErrorData errorData){
    const char *errorTypeString[] = {
        "TEXT_MEASUREMENT_FUNCTION_NOT_PROVIDED",
        "ARENA_CAPACITY_EXCEEDED",
        "ELEMENTS_CAPACITY_EXCEEDED",
        "TEXT_MEASUREMENT_CAPACITY_EXCEEDED",
        "DUPLICATE_ID",
        "FLOATING_CONTAINER_PARENT_NOT_FOUND",
        "PERCENTAGE_OVER_1",
        "INTERNAL_ERROR"
    };

    fprintf(stderr, "[Clay Error] Type : %s\nMessage: %.*s\n", errorTypeString[errorData.errorType],(int)errorData.errorText.length, errorData.errorText.chars);
}

int main(void){
    //init raylib
    Clay_Raylib_Initialize((int)ScreenWidth, (int)ScreenHeight, "Moon Renderer", FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_INTERLACED_HINT | FLAG_VSYNC_HINT | FLAG_BORDERLESS_WINDOWED_MODE);

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
    Clay_ErrorHandler errorHandler = {
        .errorHandlerFunction = clayErrorHandler,
        .userData = NULL
    };

    Clay_Initialize(memoryArena, clayDimension, errorHandler);
    
    //Main Application loop
    while (!WindowShouldClose())
    {
        //logic code

        //Render
        BeginDrawing();
        ClearBackground(BLUE);
        EndDrawing();
    }
    

}