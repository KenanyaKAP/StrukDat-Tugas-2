#include <iostream>
#include <graphics.h>

#include <include/pesawat.hpp>
#include <include/plane.hpp>
#include <include/tank.hpp>

#include <include/utils.hpp>
#include <include/lines.hpp>
#include <include/vector2.hpp>
#include <include/transform.hpp>

using namespace std;

int main()
{
    initwindow(1280, 720);
    char c;

    // Variable
    Pesawat musuh1;
    Plane enemy0;
    Plane enemy1;
    Plane enemy2;
    Plane enemy3;
    Plane enemy4;
    Tank player;

    // Start
    {
        musuh1.Transform.Position = Vector2(500, 500);
        musuh1.Velocity = Vector2(0, -20);
        musuh1.rotateSpeed = 1;

        enemy0.Transform.Position = Vector2(0, 80);
        enemy1.Transform.Position = Vector2(300, 160);
        enemy2.Transform.Position = Vector2(600, 240);
        enemy3.Transform.Position = Vector2(900, 320);
        enemy4.Transform.Position = Vector2(1200, 400);

        player.Transform.Position = Vector2(100, 700);
    }

    do
    {
        cleardevice();
        if (kbhit())
        {
            c = getch();
            if (c == 27) break;

            // cout << (int)c << endl;

            if (c == 'd')
            {
                player.Transform.Position.x += 20;
            }

            if (c == 'a')
            {
                player.Transform.Position.x -= 20;
            }

            if (c == 32)
            {
                player.Fire();
            }
        }
        
        // Update
        {
            musuh1.Update();
            enemy0.Update();
            enemy1.Update();
            enemy2.Update();
            enemy3.Update();
            enemy4.Update();

            player.Update();
        }

        delay(17);
    } while(1);

    closegraph();
    return 0;
}