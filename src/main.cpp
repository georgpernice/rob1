#include <SFML/Graphics.hpp>
#include <set>
#include <random>
#include <iostream>
using namespace std;
const unsigned int num_obstacles = 8;


// int divide_into_subsets(sf::CircleShape** obstacle_set)
// {
//     unsigned int len = sizeof(obstacle_set[0]) / sizeof(sf::CircleShape);
//     bool division_border_good = false;
//     while(!division_border_good)
//     {
//         for (int i = 0; i < len; i++)
//         {
//             for (int j = 0; j < len; j++)
//             {
//                 sf::Vector2f pos = obstacle_set[i][j].getPosition();
//                 // check if 

//             } 
//         }
//         division_border_good = amount_left - amount_right < amount
//     }
     
// }
int main()
{
    auto window = sf::RenderWindow({800, 600},"White Obstacles and Voronoi Diagram");
    window.setFramerateLimit(144);

    // random distr
    std::random_device dev;
    std::mt19937 rng(dev()); // random number gen
    std::uniform_int_distribution<std::mt19937::result_type> noise10(-10,10); // distribution in range [1, 6]
    std::uniform_int_distribution<std::mt19937::result_type> noise20(-20,20); // distribution in range [1, 6]

    sf::Clock clock;


    // Define what we need
    unsigned int xspace = 100;
    unsigned int yspace = 60;
    unsigned int xoffset = 50;
    unsigned int yoffset = 50;
    sf::CircleShape obstacles[num_obstacles][num_obstacles];
    for (int i = 0; i < num_obstacles; i++)
    {
        for (int j = 0; j < num_obstacles; j++)
        {
            obstacles[i][j] = sf::CircleShape(5.f);
            obstacles[i][j].setFillColor(sf::Color::White);
            obstacles[i][j].setPosition(
                xoffset + i*xspace + noise10(rng),
                yoffset + j*yspace + noise20(rng));
        }
    }
    while (window.isOpen())
    {
        while(clock.getElapsedTime().asMilliseconds() < 50)
        {}
        clock.restart();
        std::mt19937 rng(dev()); // random number gen

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);
        for(int i = 0; i < num_obstacles; i++)    
        {
            for(int j = 0; j < num_obstacles; j++)
                {
                    sf::Vector2f pos = obstacles[i][j].getPosition();
                    obstacles[i][j].setPosition(
                        pos.x + (noise10(rng) + 10)* 0.1,
                        pos.y - (noise10(rng) + 10) * 0.1
                    );
                    window.draw(obstacles[i][j]);
                }
        }
        window.display();
        cout << "(" <<obstacles[0][0].getPosition().x << "|" << obstacles[0][0].getPosition().y << ")"<< endl << endl ;
        
    }
}
