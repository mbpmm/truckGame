#include "level.h"

#include "setup/game.h"

namespace Juego
{
	//obstacle levelBackground;
	//obstacle levelMiddleSquare;

	obstacle obBackground;
	obstacle obstacles[maxObstacles];
	obstacle spikes[maxSpikes];
	obstacle exit;

	Pendulum demo;

	int currentLevel = 0;

	namespace Gameplay_Section
	{
		void createLevelBackground()
		{
			
		}

		void createLevelObstacles()
		{
			demo.color = BLACK;
			demo.radius = 40;
			demo.pos = { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 };
			demo.angle = PI / 4;
			demo.angle2 = 7*PI/4;
			demo.length = 280;
			demo.aAcc = 0.0f;
			demo.aVel = 0.0f;

			for (int i = 0;i < maxObstacles;i++)
			{
				obstacles[i].pos.x = 0;
				obstacles[i].pos.y = 0;
				obstacles[i].size.x = 0;
				obstacles[i].size.y = 0;
				obstacles[i].speed = 0;
				obstacles[i].isAlive = false;
				obstacles[i].color = BLANK;
			}

			for (int i = 0; i < maxSpikes; i++)
			{
				spikes[i].pos.x = 0;
				spikes[i].pos.y = 0;
				spikes[i].size.x = 0;
				spikes[i].size.y = 0;
				spikes[i].speed = 0;
				spikes[i].isAlive = false;
				spikes[i].color = BLANK;
			}

			obBackground.pos.x = 0 + 50;
			obBackground.pos.y = 0 + 50;
			obBackground.size.x = screenWidth - 100;
			obBackground.size.y = screenHeight - 100;
			obBackground.speed = 0;
			obBackground.isAlive = true;
			obBackground.color = WHITE;

			exit.pos.x = 0;
			exit.pos.y = 0;
			exit.size.x = 0;
			exit.size.y = 0;
			exit.speed = 0;
			exit.isAlive = false;
			exit.color = BLANK;

			switch (currentLevel)
			{
			case 0:
			{
				obstacles[obMiddleSquare].pos.x = (float)screenWidth / 6;
				obstacles[obMiddleSquare].pos.y = screenHeight / 4;
				obstacles[obMiddleSquare].size.x = 250;
				obstacles[obMiddleSquare].size.y = 120;
				obstacles[obMiddleSquare].speed = 0;
				obstacles[obMiddleSquare].isAlive = true;
				obstacles[obMiddleSquare].color = BLACK;

				obstacles[obMiddleSquare2].pos.x = (float)screenWidth / 6;
				obstacles[obMiddleSquare2].pos.y = screenHeight / 1.6f;
				obstacles[obMiddleSquare2].size.x = 250;
				obstacles[obMiddleSquare2].size.y = 120;
				obstacles[obMiddleSquare2].speed = 0;
				obstacles[obMiddleSquare2].isAlive = true;
				obstacles[obMiddleSquare2].color = BLACK;

				obstacles[obMiddleSquare3].pos.x = (float)screenWidth / 1.55f;
				obstacles[obMiddleSquare3].pos.y = screenHeight / 4;
				obstacles[obMiddleSquare3].size.x = 250;
				obstacles[obMiddleSquare3].size.y = 120;
				obstacles[obMiddleSquare3].speed = 0;
				obstacles[obMiddleSquare3].isAlive = true;
				obstacles[obMiddleSquare3].color = BLACK;

				obstacles[obMiddleSquare4].pos.x = (float)screenWidth / 1.55f;
				obstacles[obMiddleSquare4].pos.y = screenHeight / 1.6f;
				obstacles[obMiddleSquare4].size.x = 250;
				obstacles[obMiddleSquare4].size.y = 120;
				obstacles[obMiddleSquare4].speed = 0;
				obstacles[obMiddleSquare4].isAlive = true;
				obstacles[obMiddleSquare4].color = BLACK;
			}
			break;
			case 1:
			{
				obstacles[obMiddleSquare].pos.x = (float)screenWidth / 6;
				obstacles[obMiddleSquare].pos.y = screenHeight / 2 - 100;
				obstacles[obMiddleSquare].size.x = 70;
				obstacles[obMiddleSquare].size.y = 600;
				obstacles[obMiddleSquare].speed = 0;
				obstacles[obMiddleSquare].isAlive = true;
				obstacles[obMiddleSquare].color = BLACK;

				obstacles[obMiddleSquare2].pos.x = (float)screenWidth / 2.7f;
				obstacles[obMiddleSquare2].pos.y = 0;
				obstacles[obMiddleSquare2].size.x = 70;
				obstacles[obMiddleSquare2].size.y = 500;
				obstacles[obMiddleSquare2].speed = 0;
				obstacles[obMiddleSquare2].isAlive = true;
				obstacles[obMiddleSquare2].color = BLACK;

				obstacles[obMiddleSquare3].pos.x = (float)screenWidth / 2.7f + 70;
				obstacles[obMiddleSquare3].pos.y = 0;
				obstacles[obMiddleSquare3].size.x = 300;
				obstacles[obMiddleSquare3].size.y = 300;
				obstacles[obMiddleSquare3].speed = 0;
				obstacles[obMiddleSquare3].isAlive = true;
				obstacles[obMiddleSquare3].color = BLACK;

				obstacles[obMiddleSquare4].pos.x = screenWidth / 1.9f;
				obstacles[obMiddleSquare4].pos.y = screenHeight/1.9f;
				obstacles[obMiddleSquare4].size.x = 600;
				obstacles[obMiddleSquare4].size.y = 400;
				obstacles[obMiddleSquare4].speed = 0;
				obstacles[obMiddleSquare4].isAlive = true;
				obstacles[obMiddleSquare4].color = BLACK;

				obstacles[obMiddleSquare5].pos.x = screenWidth / 1.3f;
				obstacles[obMiddleSquare5].pos.y = screenHeight / 3.1f;
				obstacles[obMiddleSquare5].size.x = 100;
				obstacles[obMiddleSquare5].size.y = 100;
				obstacles[obMiddleSquare5].speed = 0;
				obstacles[obMiddleSquare5].isAlive = true;
				obstacles[obMiddleSquare5].color = BLACK;

				obstacles[obMiddleSquare6].pos.x = screenWidth / 1.2f;
				obstacles[obMiddleSquare6].pos.y = screenHeight / 5.7f;
				obstacles[obMiddleSquare6].size.x = 300;
				obstacles[obMiddleSquare6].size.y = 50;
				obstacles[obMiddleSquare6].speed = 0;
				obstacles[obMiddleSquare6].isAlive = true;
				obstacles[obMiddleSquare6].color = BLACK;

				exit.pos.x = screenWidth / 1.11f;
				exit.pos.y = obstacles[obMiddleSquare6].pos.y - 80;
				exit.size.x = 75;
				exit.size.y = 115;
				exit.speed = 0;
				exit.isAlive = false;
				exit.color = SKYBLUE;
			}
			break;
			case 2:
			{
				obstacles[obMiddleSquare].pos.x = obBackground.pos.x;
				obstacles[obMiddleSquare].pos.y = screenHeight / 4.5f;
				obstacles[obMiddleSquare].size.x = 200;
				obstacles[obMiddleSquare].size.y = 600;
				obstacles[obMiddleSquare].speed = 0;
				obstacles[obMiddleSquare].isAlive = true;
				obstacles[obMiddleSquare].color = BLACK;

				spikes[0].pos.x = obstacles[obMiddleSquare].pos.x + obstacles[obMiddleSquare].size.x;
				spikes[0].pos.y = screenHeight / 1.23f;
				spikes[0].size.x = 230;
				spikes[0].size.y = 100;
				spikes[0].speed = 0;
				spikes[0].isAlive = false;
				spikes[0].color = RED;

				obstacles[obMiddleSquare2].pos.x = (float)screenWidth / 2.7f;
				obstacles[obMiddleSquare2].pos.y = 0;
				obstacles[obMiddleSquare2].size.x = 70;
				obstacles[obMiddleSquare2].size.y = 425;
				obstacles[obMiddleSquare2].speed = 0;
				obstacles[obMiddleSquare2].isAlive = true;
				obstacles[obMiddleSquare2].color = BLACK;

				obstacles[obMiddleSquare3].pos.x = (float)screenWidth / 2.7f;
				obstacles[obMiddleSquare3].pos.y = screenHeight/1.5f;
				obstacles[obMiddleSquare3].size.x = 70;
				obstacles[obMiddleSquare3].size.y = 225;
				obstacles[obMiddleSquare3].speed = 0;
				obstacles[obMiddleSquare3].isAlive = true;
				obstacles[obMiddleSquare3].color = BLACK;

				spikes[1].pos.x = obstacles[obMiddleSquare3].pos.x + obstacles[obMiddleSquare3].size.x;
				spikes[1].pos.y = screenHeight / 1.23f;
				spikes[1].size.x = 700;
				spikes[1].size.y = 100;
				spikes[1].speed = 0;
				spikes[1].isAlive = false;
				spikes[1].color = RED;

				obstacles[obMiddleSquare4].pos.x = obstacles[obMiddleSquare3].pos.x + 200;
				obstacles[obMiddleSquare4].pos.y = screenHeight / 1.9f - 50;
				obstacles[obMiddleSquare4].size.x = 200;
				obstacles[obMiddleSquare4].size.y = 200;
				obstacles[obMiddleSquare4].speed = 0;
				obstacles[obMiddleSquare4].isAlive = true;
				obstacles[obMiddleSquare4].color = BLACK;

				obstacles[obMiddleSquare5].pos.x = obstacles[obMiddleSquare4].pos.x + 300;
				obstacles[obMiddleSquare5].pos.y = screenHeight / 1.9f - 100;
				obstacles[obMiddleSquare5].size.x = 150;
				obstacles[obMiddleSquare5].size.y = 150;
				obstacles[obMiddleSquare5].speed = 0;
				obstacles[obMiddleSquare5].isAlive = true;
				obstacles[obMiddleSquare5].color = BLACK;

				obstacles[obMiddleSquare6].pos.x = obstacles[obMiddleSquare2].pos.x;
				obstacles[obMiddleSquare6].pos.y = obBackground.pos.y;
				obstacles[obMiddleSquare6].size.x = 400;
				obstacles[obMiddleSquare6].size.y = 175;
				obstacles[obMiddleSquare6].speed = 0;
				obstacles[obMiddleSquare6].isAlive = true;
				obstacles[obMiddleSquare6].color = BLACK;

				obstacles[obMiddleSquare7].pos.x = obstacles[obMiddleSquare6].pos.x + obstacles[obMiddleSquare6].size.x;
				obstacles[obMiddleSquare7].pos.y = obstacles[obMiddleSquare6].pos.y + obstacles[obMiddleSquare6].size.y - 50;
				obstacles[obMiddleSquare7].size.x = 250;
				obstacles[obMiddleSquare7].size.y = 50;
				obstacles[obMiddleSquare7].speed = 0;
				obstacles[obMiddleSquare7].isAlive = true;
				obstacles[obMiddleSquare7].color = BLACK;

				exit.pos.x = obstacles[obMiddleSquare7].pos.x;
				exit.pos.y = obstacles[obMiddleSquare7].pos.y - 125;
				exit.size.x = 75;
				exit.size.y = 125;
				exit.speed = 0;
				exit.isAlive = false;
				exit.color = SKYBLUE;

			}
			break;
			}

		}

		void updatePendulum() 
		{
			bool aux = false;
			demo.pos.y = (float)GetScreenHeight() / 2 + demo.length*sin(demo.angle);
			/*float aux2= cos(demo.angle)*DEG2RAD;
			demo.radius -= aux2;*/

			demo.radius = 0 + demo.length*cos(demo.angle2)*(0.2);

			demo.aAcc = -0.0002*sin(demo.angle)*GetFrameTime();
			
			demo.angle += demo.aVel;
			demo.angle2 += demo.aVel;
			demo.aVel += demo.aAcc;

			//demo.radius = 30+(demo.aVel*10046)/2;
			//demo.aVel *= 1;

		}

		void DrawLevel()
		{
			DrawRectangle(obBackground.pos.x, obBackground.pos.y, obBackground.size.x, obBackground.size.y, obBackground.color);
			DrawRectangle(exit.pos.x, exit.pos.y, exit.size.x, exit.size.y, exit.color);
			DrawCircle(demo.pos.x, demo.pos.y, demo.radius, demo.color);
			
			for (int i = 0; i < maxObstacles; i++)
			{
				DrawRectangle(obstacles[i].pos.x, obstacles[i].pos.y, obstacles[i].size.x, obstacles[i].size.y, obstacles[i].color);
			}

			for (int i = 0; i < maxSpikes; i++)
			{
				DrawRectangle(spikes[i].pos.x, spikes[i].pos.y, spikes[i].size.x, spikes[i].size.y, spikes[i].color);
			}

			if (currentLevel > 2)
			{
				DrawTextEx(mainFont, "THANKS FOR PLAYING", { screenWidth / 9.0f, screenHeight / 2.0f }, defaultFontSize / 1.2f, 1.0f, GREEN);
				DrawTextEx(mainFont, "OUR DEMO", { screenWidth / 7.0f, screenHeight / 1.5f }, defaultFontSize / 1.2f, 1.0f, GREEN);
			}
			//DrawRectangle(levelMiddleSquare.pos.x, levelMiddleSquare.pos.y, levelMiddleSquare.size.x, levelMiddleSquare.size.y, levelMiddleSquare.color);
		}
	}
}