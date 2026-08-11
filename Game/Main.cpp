#include "Engine.h"
#include "Player.h"
#include "Enemy.h" 
#include "Assets.h"
#include "SpaceGame.h"

#include <fmod.hpp>

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <random>
#include <fstream>

using namespace nu;

int main()
{
    SetWorkingDirectory("Assets");

    //{
    //    // Read file (input file)
    //    std::ifstream file ("data/text.txt");
    //    if (file.is_open()) {
    //        std::string str;
    //        while (std::getline(file, str)) {
    //            std::cout << str << std::endl;
    //        }
    //    }
    //    else {
    //        std::cout << "Could not load: data/text.txt\n";
    //    }
    //    file.close();
    //}

    //{
    //    // Write to file (output file)
    //    std::ofstream file("data/text.txt", std::ios::app);
    //    if (file.is_open()) {
    //        file << "Have a good day.\n";
    //    }
    //    else {
    //        std::cout << "Could not load: data/text.txt\n";
    //    }
    //}

    //{
    //    // Read / Write (input / output file)
    //    std::fstream file("data/text.txt", std::ios::in | std::ios::out | std::ios::app);
    //    if (file.is_open()) {
    //        // input
    //        file << "Add a line.\n";
    //        file.seekg(0);
    //        // output
    //        std::string str;
    //        while (std::getline(file, str)) {
    //            std::cout << str << std::endl;
    //        }
    //    }
    //}

    //{
    //    std::string name;
    //    int score;
    //    bool isAlive;
    //    
    //    bool save = true;
    //    if (save) {
    //        name = "Diego Corona";
    //        score = 1234;

    //        // save game data
    //        std::ofstream file("data/game.txt", std::ios::app);
    //        if (file.is_open()) {
    //            file << name << "\n";
    //            file << score << "\n";
    //            file << std::boolalpha << isAlive << "\n";
    //        }
    //    }

    //    bool load = true;
    //    // load game data
    //    if (load) {
    //        // Read file (input file)
    //        std::ifstream file("data/game.txt");
    //        if (file.is_open()) {
    //            std::getline(file, name);

    //            std::string str;
    //            std::getline(file, str);

    //            score = std::stoi(str);
    //            //file >> score;
    //            file >> std::boolalpha >> isAlive;
    //        }
    //    }

    // display game data
    //    std::cout << name << std::endl;
    //    std::cout << score << std::endl;
    //    std::cout << isAlive << std::endl;
    //}

    
    // INITIALIZATION
    Engine::Get().Initialize();
    Engine::Get().GetAudio().Initialize();

    SpaceGame game;
    game.Initialize();

    Engine::Get().GetAudio().AddSound("bgm", "audio/tech-space.wav");
    Engine::Get().GetAudio().AddSound("laser", "audio/laser.wav");
    Engine::Get().GetAudio().AddSound("explosion", "audio/explosion.wav");
    Engine::Get().GetAudio().AddSound("itemPickup", "audio/item_pickup.wav");
    Engine::Get().GetAudio().AddSound("enemyExplosion", "audio/enemy_explosion.wav");

    // MAIN LOOP
    bool quit = false;

    while (!quit) {

        // UPDATE
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE) {
                quit = true;
            }
        }

        Engine::Get().GetAudio().Update();
        
        // engine
        Engine::Get().Update();
        float dt = Engine::Get().GetTime().GetDeltaTime();

        // GAME
        game.Update(dt);

        // RENDER
        Engine::Get().GetRenderer().SetColor(0.0f, 0.0f, 0.0f);
        Engine::Get().GetRenderer().Clear();
        game.Draw(Engine::Get().GetRenderer()); 




        //auto texture = Resources().Get<Texture>("textures/chud.jpg", Engine::Get().GetRenderer());
        //Engine::Get().GetRenderer().DrawTexture(*texture, 600, 200, 0.0f, 1.0f);
        //Engine::Get().GetRenderer().DrawTexture(*Resources().Get<Texture>("textures/player.png"), 30, 30);


        

        Engine::Get().GetPS().Draw(Engine::Get().GetRenderer());
        Engine::Get().GetRenderer().Present();
    }

    // SHUTDOWN
    //Engine::Get().GetRenderer().Shutdown();
    Engine::Get().GetAudio().Shutdown();
    Engine::Get().Shutdown();
    return 0;
}
