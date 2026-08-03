#pragma once

#include "Random.h"
#include "Vector2.h"
#include "Transform.h"
#include "MathUtils.h"
#include "File.h"

#include "Text.h"

// Systems
#include "Renderer.h"
#include "Input.h"
#include "Audio.h"
#include "GameTime.h"
#include "ParticleSystem.h"

// framework
#include "Actor.h"
#include "Scene.h"
#include "Game.h"

//#include <iostream>
//#include <vector>

namespace nu {
	class Engine {

	public:
		static Engine& Get() { static Engine engine; return engine; }

		bool Initialize();
		void Shutdown();

		void Update();

		Input& GetInput() { return m_input; }
		Renderer& GetRenderer() { return m_renderer; }
		Time& GetTime() { return m_time; }
		ParticleSystem& GetPS() { return m_particleSystem; }
		Audio& GetAudio() { return m_audio; }

	private:
		Engine() = default;

	private:
		Input m_input;
		Renderer m_renderer;
		Audio m_audio;
		ParticleSystem m_particleSystem;

		Time m_time;
	};

}