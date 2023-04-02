#include "SFML/Graphics.hpp"

#include "math.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(500,200), "TESTING MY TESTS");
    CircleShape shape(10.0f);

    float amp = 100.0f;
    float time = 0.0f;
    float dt = 0.002f;

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        shape.setRadius(amp * sin(time));
        time += dt;
        if(time > 2*M_PI)
            time -= 2*M_PI;

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
