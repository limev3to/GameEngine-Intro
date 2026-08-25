#pragma once
#include "Components/RendererComponent.h"
#include "Renderer/Texture.h"
#include "Serialization/Json.h"

namespace nu {
	class SpriteRendererComponent : public RendererComponent {
	public:
		CLASS_PROTOTYPE(SpriteRendererComponent)

		SpriteRendererComponent() = default;

		void Draw(const Renderer& renderer) override;

		virtual void Read(const json::value_t& value) override;

	protected:
		res_t<Texture> m_texture = nullptr;
	};
}