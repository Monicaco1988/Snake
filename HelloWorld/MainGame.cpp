#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Apple.h"
#include "snake.h"
int DISPLAY_WIDTH = 640;
int DISPLAY_HEIGHT = 360;
int DISPLAY_SCALE = 2;
int frameCount = 0;
Snake snake = Snake();

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	Play::ClearDrawingBuffer(Play::cBlack);

	//for (int k = 10; k < 660; k += 20) // check to see where the apples should spawn and where the anake should move
	//{
	//	for (int i = 10; i < 380; i += 20)
	//	{
	//		Apple apple = Apple(k, i); // definiera apple som object fr�n constr.
	//		apple.Draw();
	//	};
	//};

	SpawnApple();
	snake.Draw();
	if (frameCount >= 6) {
		snake.HandleInput();
		snake.Move();
		//snake.Collide(apple);
		frameCount = 0;
	}
	Play::PresentDrawingBuffer();
	frameCount++;
	return Play::KeyDown( VK_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}
