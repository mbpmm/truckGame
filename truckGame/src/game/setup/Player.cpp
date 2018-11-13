#include "Player.h"

#include "Setup\game.h"
#include "setup/level.h"
#include "Screens\settings.h"
#include "Screens\gameplay.h"

namespace Juego
{
	cube playerhitbox;
	cube player;
	cube playerfront;
	static float playerAccelerationLeft = 0;
	static float playerAccelerationRight = 0;
	static float playerAccelerationUp = 0;
	static float playerAccelerationDown = 0;

	static int collisionFix = 0;
	static int collisionFix2 = 0;

	bool moveRight = false;
	bool moveLeft = false;
	bool moveUp = false;
	bool moveDown = false;

	namespace Gameplay_Section
	{
		void createPlayer()
		{
			if (resolutionNormal) 
			{
				player.size = { 80, 100 };
				playerhitbox.size = { 100, 100 };
				player.defaultSpeed = 500.0f;
				playerfront.size = { 80, 30 };
				collisionFix = player.size.y/2;
				collisionFix2 = 30;
			}
			else if (resolutionSmall) 
			{
				player.size = { 50 / resolutionSizeFix, 50 / resolutionSizeFix };
				player.defaultSpeed = 500.0f / resolutionSizeFix;
				player.centre = { player.size.x / 2,player.size.y / 2 };
			}
			if (currentLevel == 0)
			{
				player.position = { (float)screenWidth / 2, (float)screenHeight / 2 };
				playerfront.position = { (float)screenWidth / 2, (float)screenHeight / 2 };
				playerhitbox.position = { (float)screenWidth / 2 - playerhitbox.size.x / 2, (float)screenHeight / 2 - playerhitbox.size.y / 2 };
			}
			else if(currentLevel == 1) player.position = { (float)screenWidth / 10, obBackground.pos.y + obBackground.size.y - player.size.y};
			else if(currentLevel == 2) player.position = { (float)screenWidth / 10, obBackground.pos.y + player.size.y };
			player.isAlive = true;
			player.inputActive = false;
			player.rotation = 0;
			player.textureTint = WHITE;
			playerhitbox.isAlive = true;
			playerhitbox.inputActive = false;
			playerhitbox.rotation = 0;
			playerhitbox.textureTint = BLANK;
			playerfront.isAlive = true;
			playerfront.inputActive = false;
			playerfront.rotation = 0;
			playerfront.textureTint = SKYBLUE;
		}
		
		void playerGravityExec()
		{
		}

		void playerInput()
		{
			if (IsKeyPressed(playerKeys[GRAVITY]))
			{
					
			}

			if (IsKeyDown(playerKeys[UP]))
			{
				//player.size = { 50, 100 };
				player.rotation = 0;


				/*playerhitbox.position.y -= player.defaultSpeed * GetFrameTime();*/
					playerAccelerationUp = playerAccelerationUp + 0.25f;

					if (playerAccelerationDown <= 0) playerAccelerationDown = 0;
					else playerAccelerationDown = playerAccelerationDown - 0.25f;
					
					
					
					//
					
					//playerhitbox.position.y = player.position.y - collisionFix;
					//player.position.y = playerhitbox.position.y;
					//playerfront.position.y = player.position.y;
					
			}
			else if (IsKeyDown(playerKeys[DOWN]))
			{
				//player.size = { 50, 100 };
				player.rotation = 180;

				/*playerhitbox.position.y += player.defaultSpeed * GetFrameTime();*/

					playerAccelerationDown = playerAccelerationDown + 0.25f;

					if (playerAccelerationUp <= 0) playerAccelerationUp = 0;
					else playerAccelerationUp = playerAccelerationUp - 0.25f;


				

				//player.position.y += player.defaultSpeed * GetFrameTime();
				//playerfront.position.y = player.position.y;
				//playerhitbox.position.y += player.defaultSpeed * GetFrameTime();
				//playerfront.position.x = player.position.x;
			}
			else if (IsKeyDown(playerKeys[RIGHT]))
			{
				//player.size = { 100, 50 };

				player.rotation = 90;

				//
				//playerfront.position.x = player.position.x;
				

				playerAccelerationRight = playerAccelerationRight + 0.25f;

				if (playerAccelerationLeft <= 0) playerAccelerationLeft = 0;
				else playerAccelerationLeft = playerAccelerationLeft - 0.25f;
				

				if (playerAccelerationUp <= 0) playerAccelerationUp = 0;
				else playerAccelerationUp = playerAccelerationUp - 0.35f;
				if (playerAccelerationDown <= 0) playerAccelerationDown = 0;
				else playerAccelerationDown = playerAccelerationDown - 0.35f;
			}
			else if (IsKeyDown(playerKeys[LEFT]))
			{
				//player.size = { 100, 50 };
				player.rotation = 270;

				//player.position.x -= player.defaultSpeed * GetFrameTime();
				//playerfront.position.x = player.position.x;
				

				playerAccelerationLeft = playerAccelerationLeft + 0.25f;

				if (playerAccelerationRight <= 0) playerAccelerationRight = 0;
				else playerAccelerationRight = playerAccelerationRight - 0.25f;

				if (playerAccelerationUp <= 0) playerAccelerationUp = 0;
				else playerAccelerationUp = playerAccelerationUp - 0.35f;
				if (playerAccelerationDown <= 0) playerAccelerationDown = 0;
				else playerAccelerationDown = playerAccelerationDown - 0.35f;
			}
			else 
			{

				if(playerAccelerationLeft <= 0) playerAccelerationLeft = 0;
				else playerAccelerationLeft = playerAccelerationLeft - 0.25f;

				if (playerAccelerationRight <= 0) playerAccelerationRight = 0;
				else playerAccelerationRight = playerAccelerationRight - 0.25f;

				if (playerAccelerationUp <= 0) playerAccelerationUp = 0;
				else playerAccelerationUp = playerAccelerationUp - 0.25f;

				if (playerAccelerationDown <= 0) playerAccelerationDown = 0;
				else playerAccelerationDown = playerAccelerationDown - 0.25f;
			}
		}

		//void playerCollisions(int obstacle)
		//{
		//	player.textureTint = PURPLE;

		//	if (player.position.x <= obstacles[obstacle].pos.x + obstacles[obstacle].size.x && player.position.x > obstacles[obstacle].pos.x + obstacles[obstacle].size.x - 10)
		//	{
		//		player.isInvertedGravityX = true;
		//		player.textureTint = BLUE;
		//	}
		//	else if (player.position.x + player.size.x >= obstacles[obstacle].pos.x && player.position.x + player.size.x <= obstacles[obstacle].pos.x + 10)
		//	{
		//		player.isInvertedGravityX = false;
		//		player.textureTint = YELLOW;
		//	}

		//	if (player.position.y + player.size.y >= obstacles[obstacle].pos.y && player.position.y + player.size.y <= obstacles[obstacle].pos.y + 10)
		//	{
		//		player.isPlayerStickedOnWall = false;
		//		player.isPlayerStickedOnWall2 = true;
		//		player.activatedGravity = false;
		//		player.position.y = obstacles[obstacle].pos.y - player.size.y;
		//		//playerAccelerationUp = 0;
		//	}
		//	else if (player.position.y <= obstacles[obstacle].pos.y + obstacles[obstacle].size.y && player.position.y >= obstacles[obstacle].pos.y + obstacles[obstacle].size.y - 10)
		//	{
		//		player.isPlayerStickedOnWall = false;
		//		player.isPlayerStickedOnWall2 = true;
		//		player.activatedGravity = false;
		//		player.position.y = obstacles[obstacle].pos.y + obstacles[obstacle].size.y;
		//		
		//		//playerAccelerationDown = 0;
		//	}
		//	else if (player.position.x + player.size.x >= obstacles[obstacle].pos.x && player.position.x + player.size.x <= obstacles[obstacle].pos.x + 10 && player.position.y + player.size.y >= obstacles[obstacle].pos.y && player.position.y <= obstacles[obstacle].pos.y + obstacles[obstacle].size.y)
		//	{
		//		player.isPlayerStickedOnWall = false;
		//		player.isPlayerStickedOnWall2 = true;
		//		player.activatedGravity = false;
		//		player.position.x = obstacles[obstacle].pos.x - player.size.x;
		//		//playerAccelerationRight = 0;
		//	}
		//	else if (player.position.x <= obstacles[obstacle].pos.x + obstacles[obstacle].size.x && player.position.x > obstacles[obstacle].pos.x + obstacles[obstacle].size.x - 10 && player.position.y + player.size.y >= obstacles[obstacle].pos.y && player.position.y <= obstacles[obstacle].pos.y + obstacles[obstacle].size.y)
		//	{
		//		player.isPlayerStickedOnWall = false;
		//		player.isPlayerStickedOnWall2 = true;
		//		player.activatedGravity = false;
		//		player.position.x = obstacles[obstacle].pos.x + obstacles[obstacle].size.x - 0.1f;
		//		//playerAccelerationLeft = 0;
		//	}
		//}

		void playerUpdate()
		{
			playerhitbox.position.x += playerAccelerationRight * GetFrameTime();
			playerhitbox.position.x -= playerAccelerationLeft * GetFrameTime();
			playerhitbox.position.y += playerAccelerationDown * GetFrameTime();
			playerhitbox.position.y -= playerAccelerationUp * GetFrameTime();

			player.position.y = playerhitbox.position.y + collisionFix; //+ collisionFix;
			player.position.x = playerhitbox.position.x + collisionFix; //+ collisionFix;
			playerfront.position.y = playerhitbox.position.y + collisionFix;
			playerfront.position.x = playerhitbox.position.x + collisionFix;

			if (playerAccelerationLeft >= player.defaultSpeed) playerAccelerationLeft = player.defaultSpeed;
			if (playerAccelerationRight >= player.defaultSpeed) playerAccelerationRight = player.defaultSpeed;
			if (playerAccelerationDown >= player.defaultSpeed) playerAccelerationDown = player.defaultSpeed;
			if (playerAccelerationUp >= player.defaultSpeed) playerAccelerationUp = player.defaultSpeed;

			//////////////////////////////////--------------------------
			
			if (moveRight)
			{
				if (playerAccelerationRight <= 0)
				{
					moveRight = false;
					playerAccelerationRight = 0;
				}
				else playerAccelerationRight = playerAccelerationRight - 0.25f;
			}

			if (moveLeft)
			{
				if (playerAccelerationLeft <= 0)
				{
					moveLeft = false;
					playerAccelerationLeft = 0;
				}
				else playerAccelerationLeft = playerAccelerationLeft - 0.25f;
			}

			if (moveUp)
			{
				if (playerAccelerationUp <= 0)
				{
					moveUp = false;
					playerAccelerationUp = 0;
				}
				else playerAccelerationUp = playerAccelerationUp - 0.25f;
			}

			if (moveDown)
			{
				if (playerAccelerationDown <= 0)
				{
					moveDown = false;
					playerAccelerationDown = 0;
				}
				else playerAccelerationDown = playerAccelerationDown - 0.25f;
			}
				
			if (CheckCollisionRecs({playerhitbox.position.x,playerhitbox.position.y,playerhitbox.size.x,playerhitbox.size.y}, { obstacles[obMiddleSquare].pos.x ,obstacles[obMiddleSquare].pos.y,obstacles[obMiddleSquare].size.x,obstacles[obMiddleSquare].size.y }))
			{
				if (playerhitbox.position.y + playerhitbox.size.y > obstacles[obMiddleSquare].pos.y && playerhitbox.position.y + playerhitbox.size.y < obstacles[obMiddleSquare].pos.y + (obstacles[obMiddleSquare].pos.y / 2) && playerhitbox.position.x + playerhitbox.size.x > obstacles[obMiddleSquare].pos.x && playerhitbox.position.x + playerhitbox.size.x < obstacles[obMiddleSquare].pos.x + obstacles[obMiddleSquare].size.x)
				{
					moveUp = true;

					playerAccelerationUp = playerAccelerationDown;

					playerAccelerationDown = 0;
					player.position.y = obstacles[obMiddleSquare].pos.y - player.size.y + collisionFix;
					playerhitbox.position.y = obstacles[obMiddleSquare].pos.y - playerhitbox.size.y;
				}
				else
				{
					player.position.y += playerAccelerationDown * GetFrameTime();
				}

				if (playerhitbox.position.y < obstacles[obMiddleSquare].pos.y + obstacles[obMiddleSquare].size.y - 1 && playerhitbox.position.y > obstacles[obMiddleSquare].pos.y + (obstacles[obMiddleSquare].pos.y / 2))
				{
					moveDown = true;

					playerAccelerationDown = playerAccelerationUp;

					playerAccelerationUp = 0;
					player.position.y = obstacles[obMiddleSquare].pos.y + obstacles[obMiddleSquare].size.y + collisionFix;
					playerhitbox.position.y = obstacles[obMiddleSquare].pos.y + obstacles[obMiddleSquare].size.y;
				}
				else
				{
					player.position.y -= playerAccelerationUp * GetFrameTime();
				}

				if (playerhitbox.position.x + playerhitbox.size.x > obstacles[obMiddleSquare].pos.x && playerhitbox.position.x + playerhitbox.size.x < obstacles[obMiddleSquare].pos.x + (obstacles[obMiddleSquare].pos.x / 2) - 1 && player.position.y + player.size.y >= obstacles[obMiddleSquare].pos.y && player.position.y <= obstacles[obMiddleSquare].pos.y + obstacles[obMiddleSquare].size.y)
				{
					moveLeft = true;

					playerAccelerationLeft = playerAccelerationRight;

					playerAccelerationRight = 0;
					player.position.x = obstacles[obMiddleSquare].pos.x - player.size.x + collisionFix2;
					playerhitbox.position.x = obstacles[obMiddleSquare].pos.x  - playerhitbox.size.x;
				}
				else
				{

				}

				if (playerhitbox.position.x < obstacles[obMiddleSquare].pos.x + obstacles[obMiddleSquare].size.x && playerhitbox.position.x >= obstacles[obMiddleSquare].pos.x && player.position.y + player.size.y >= obstacles[obMiddleSquare].pos.y && player.position.y <= obstacles[obMiddleSquare].pos.y + obstacles[obMiddleSquare].size.y)
				{
					moveRight = true;

					playerAccelerationRight = playerAccelerationLeft;

					playerAccelerationLeft = 0;

					player.position.x = obstacles[obMiddleSquare].pos.x + obstacles[obMiddleSquare].size.x + collisionFix;
					playerhitbox.position.x = obstacles[obMiddleSquare].pos.x + obstacles[obMiddleSquare].size.x;
				}
				else
				{

				}

				

				player.textureTint = YELLOW;
			}
			else
			{
				player.textureTint = WHITE;
			}

			//////////////////////////////////--------------------------

			if (playerhitbox.position.y + playerhitbox.size.y > obBackground.pos.y + obBackground.size.y)
			{
				moveUp = true;

				playerAccelerationUp = playerAccelerationDown;

				playerAccelerationDown = 0;
				player.position.y = obBackground.pos.y + obBackground.size.y - player.size.y + collisionFix;
				playerhitbox.position.y = obBackground.pos.y + obBackground.size.y - playerhitbox.size.y;
			}
			else
			{
				player.position.y += playerAccelerationDown * GetFrameTime();
			}
			//asd
			if (playerhitbox.position.y < obBackground.pos.y)
			{
				moveDown = true;

				playerAccelerationDown = playerAccelerationUp;

				playerAccelerationUp = 0;
				player.position.y = obBackground.pos.y + collisionFix;
				playerhitbox.position.y = obBackground.pos.y;
			}
			else
			{
				player.position.y -= playerAccelerationUp * GetFrameTime();
			}

			if (playerhitbox.position.x + playerhitbox.size.x > obBackground.pos.x + obBackground.size.x)
			{
				moveLeft = true;

				playerAccelerationLeft = playerAccelerationRight;

				playerAccelerationRight = 0;
				player.position.x = obBackground.pos.x + obBackground.size.x - player.size.x + collisionFix2;
				playerhitbox.position.x = obBackground.pos.x + obBackground.size.x - playerhitbox.size.x;
			}
			else
			{
				
			}

			if (playerhitbox.position.x <= obBackground.pos.x)
			{
				moveRight = true;

				playerAccelerationRight = playerAccelerationLeft;

				playerAccelerationLeft = 0;

				player.position.x = obBackground.pos.x + collisionFix;
				playerhitbox.position.x = obBackground.pos.x;		
			}
			else
			{
				
			}
			
		}

		void playerDraw()
		{
			if (resolutionNormal)
			{

				//DrawRectangle(player.position.x, player.position.y, player.size.x, player.size.y, player.textureTint);
				DrawRectanglePro({ playerhitbox.position.x, playerhitbox.position.y, playerhitbox.size.x, playerhitbox.size.y }, { 0,0 },0, playerhitbox.textureTint);
				DrawRectanglePro({ player.position.x, player.position.y, player.size.x, player.size.y }, {40,50}, player.rotation, player.textureTint);
				DrawRectanglePro({ playerfront.position.x, playerfront.position.y, playerfront.size.x, playerfront.size.y }, { 40,50 }, player.rotation, playerfront.textureTint);
			}
			else if (resolutionSmall)
			{

				DrawRectangle(player.position.x, player.position.y, player.size.x, player.size.y, player.textureTint);
			}
		}
	}
}