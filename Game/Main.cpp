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

using namespace nu;

int main()
{
    SetWorkingDirectory("Assets");
    
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

    //std::shared_ptr<Texture> texture = std::make_shared<Texture>();
    //texture->Load("textures/player.png", Engine::Get().GetRenderer());

    // create audio system
//FMOD::System* audio;
//FMOD::System_Create(&audio);
//void* extradriverdata = nullptr;
//audio->init(32, FMOD_INIT_NORMAL, extradriverdata);
    // mesh / model
    //Mesh mesh{ { Vector2{ 2, 0 }, Vector2{ -2, 2 }, Vector2{ -1, 0 }, Vector2{ -2, -2 }, Vector2{ 2, 0 } }, Color{ 1.0f, 1.0f, 1.0f } };
    //Mesh mesh{ { Vector2{ 10, 0 }, Vector2{ 7, -8 }, Vector2{ -7, -8 }, Vector2{ -10, 0 }, Vector2{ -7, 8 }, Vector2 { 7 , 8 }, Vector2 { 10 , 0 } }, Color{ 0.9f, 0.8f, 1.0f } };
    //Mesh mesh2{ { Vector2{ 7, -8 }, Vector2{ 4, -13 }, Vector2{ 1, -8 } }, Color{ 1.0f, 0.0f, 0.5f } };
    //Mesh mesh3{ { Vector2{ -7, -8 }, Vector2{ -4, -13 }, Vector2{ -1, -8 } }, Color{ 1.0f, 0.0f, 0.5f } };
    //Mesh mesh4{ { Vector2{ 3, -1 }, Vector2{ 3, -4 }, Vector2{ 5, -4 }, Vector2{ 5, -1 }, Vector2{ 3, -1 } }, Color{ 0.2f, 0.2f, 0.8f } };
    //Mesh mesh5{ { Vector2{ -3, -1 }, Vector2{ -3, -4 }, Vector2{ -5, -4 }, Vector2{ -5, -1 }, Vector2{ -3, -1 } }, Color{ 0.2f, 0.2f, 0.8f } };
    //
    //Model model{ std::vector<Mesh> { mesh } };
    //model.AddMesh(mesh2);
    //model.AddMesh(mesh3);
    //model.AddMesh(mesh4);
    //model.AddMesh(mesh5);
    // test FMOD working on startup
    //FMOD::Sound* sound1 = nullptr;
    //audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound1);
    //audio->playSound(sound1, 0, false, nullptr);
    // create and store all sounds in vector
    //std::vector<FMOD::Sound*> sounds;
    //FMOD::Sound* sound = nullptr;
    //audio->createSound("audio/alert.mp3", FMOD_DEFAULT, 0, &sound);
    //sounds.push_back(sound);
    //audio->createSound("audio/duck-toy.mp3", FMOD_DEFAULT, 0, &sound);
    //sounds.push_back(sound);
    //audio->createSound("audio/error.mp3", FMOD_DEFAULT, 0, &sound);
    //sounds.push_back(sound);
    //audio->createSound("audio/mario.mp3", FMOD_DEFAULT, 0, &sound);
    //sounds.push_back(sound);
    //audio->createSound("audio/oof.mp3", FMOD_DEFAULT, 0, &sound);
    //sounds.push_back(sound);
    //audio->createSound("audio/whistle.mp3", FMOD_DEFAULT, 0, &sound);
    //sounds.push_back(sound);
    //// get current working directory
    //std::cout << "Directory Operations:\n";
    //std::cout << "Working directory: " << nu::GetWorkingDirectory() << "\n";
    //// set working directory (current working directory + "Assets")
    //std::cout << "Setting directory to 'Assets'...\n";
    //nu::SetWorkingDirectory("Assets");
    //std::cout << "New directory: " << nu::GetWorkingDirectory() << "\n\n";
    //// get filenames in the working directory
    //std::cout << "Files in Directory:\n";
    //auto filenames = nu::GetFilesInDirectory(nu::GetWorkingDirectory());
    //for (const auto& filename : filenames)
    //{
    //    std::cout << filename << "\n";
    //}
    //std::cout << "\n";
    //// get filename info
    //if (!filenames.empty())
    //{
    //    // get filename
    //    std::string str = nu::GetFilename(filenames[0]);
    //    std::cout << "Filename: " << str << "\n";
    //   // get extension
    //    str = nu::GetFileExtension(filenames[0]);
    //    std::cout << "Extension: " << str << "\n";
    //    // get filename no extension
    //    str = nu::GetFilenameNoExtension(filenames[0]);
    //    std::cout << "Filename No Extension: " << str << "\n\n";
    //}
    //// read and display text file
    //std::cout << "Text File Reading:\n";
    //std::string str;
    //if (nu::ReadTextFile("test.txt", str))
    //{
    //    std::cout << str << "\n";
    //}
    //// write to text file
    //std::cout << "Text File Writing:\n";
    //nu::WriteTextFile("test.txt", "Hello, World!", true);
    //if (nu::ReadTextFile("test.txt", str))
    //{
    //    std::cout << str << "\n";
    //}
    // create texture, using shared_ptr so texture can be shared
    //std::shared_ptr<Texture> texture = std::make_shared<Texture>();
    //texture->Load(/*TODO: texture filename, get renderer from engine*/);

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

        //if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_1)) {
        //    Engine::Get().GetAudio().PlaySound("buh");
        //}
        // Audio Keymapping
        //if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_1))
        //{
        //    audio->playSound(sounds[0], nullptr, false, nullptr);
        //}
        //if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_2))
        //{
        //    audio->playSound(sounds[1], nullptr, false, nullptr);
        //}
        //if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_3))
        //{
        //    audio->playSound(sounds[2], nullptr, false, nullptr);
        //}
        //if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_4))
        //{
        //    audio->playSound(sounds[3], nullptr, false, nullptr);
        //}
        //if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_5))
        //{
        //    audio->playSound(sounds[4], nullptr, false, nullptr);
        //}
        
        // engine
        Engine::Get().Update();
        float dt = Engine::Get().GetTime().GetDeltaTime();

        // GAME
        game.Update(dt);

        // RENDER
        Engine::Get().GetRenderer().SetColor(0.0f, 0.0f, 0.0f);
        Engine::Get().GetRenderer().Clear();
        game.Draw(Engine::Get().GetRenderer()); 




        auto texture = Resources().Get<Texture>("textures/chud.jpg", Engine::Get().GetRenderer());
        Engine::Get().GetRenderer().DrawTexture(*texture, 600, 200, 0.0f, 1.0f);
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
