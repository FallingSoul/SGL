#ifndef __SGL_PLATFORM_IMGUI_LAYER__
#define __SGL_PLATFORM_IMGUI_LAYER__

#include "sgl/core/event.h"
#include "sgl/core/layer.h"
#include "sgl/core/window.h"
#include "sgl/core/renderer.h"

namespace sgl
{
	struct sglImGuiLayerProperties
	{
		sglRef<sglWindow> window;
		sglRef<sglGraphicsContext> graphics_context;
	};
	class SGL_API sglImGuiLayer : public sglLayer
	{
	public:
		sglImGuiLayer(const sglImGuiLayerProperties& prop);
		virtual ~sglImGuiLayer();
		virtual void on_attach()override;
		virtual void on_detach()override;
		virtual void on_update(sglLayerTime delta_time)override;
		virtual sglAllEventCallbacks get_callbacks()override;
	private:
		bool on_key_pressed(event::sglKeyPressed& key_pressd);
		bool on_key_released(event::sglKeyReleased& key_released);
		bool on_key_typed(event::sglKeyTyped& key_typed);
		bool on_mouse_pressed(event::sglMousePressed& mouse_pressd);
		bool on_mouse_released(event::sglMouseReleased& mouse_released);
		bool on_mouse_scroll(event::sglMouseScroll& mouse_scroll);
		bool on_mouse_move(event::sglMouseMove& mouse_move);
		bool on_window_resize(event::sglWindowResize& window_resize);
	private:
		std::unique_ptr<struct sglImGuiLayerInfo> _info;

		friend bool ImGui_ImplSGL_Init(sglImGuiLayer* layer);
	};
}


#endif //!__SGL_PLATFORM_IMGUI_LAYER__