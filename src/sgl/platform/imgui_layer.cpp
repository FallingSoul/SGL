#include "sgl/core/keycode.h"
#include "sgl/platform/imgui.h"
#include "sgl/platform/imgui_layer.h"




namespace sgl
{
	struct sglImGuiLayerInfo
	{
		bool demo_show = true;


		ImGuiContext* ctx = nullptr;
		sglImGuiLayerProperties properties;
		sglEventCallbacks <
			event::sglKeyPressed,
			event::sglKeyReleased,
			event::sglKeyTyped,
			event::sglMouseScroll,
			event::sglMousePressed,
			event::sglMouseReleased,
			event::sglMouseMove,
			event::sglWindowResize> callbacks = {};
	};
	bool sglImGuiLayer::on_key_pressed(sgl::event::sglKeyPressed& key_pressd) 
	{
		auto& io = ImGui::GetIO();
		io.KeysDown[int(key_pressd.get_key())] = true;



		io.KeyCtrl = io.KeysDown[int(sglKeyCodeValue::left_control)] || io.KeysDown[int(sglKeyCodeValue::right_control)];
		io.KeyShift = io.KeysDown[int(sglKeyCodeValue::left_shift)] || io.KeysDown[int(sglKeyCodeValue::right_shift)];
		io.KeyAlt = io.KeysDown[int(sglKeyCodeValue::left_alt)] || io.KeysDown[int(sglKeyCodeValue::right_alt)];
		return true;
	}
	bool sglImGuiLayer::on_key_released(sgl::event::sglKeyReleased& key_released)
	{
		auto& io = ImGui::GetIO();
		io.KeysDown[int(key_released.get_key())] = false;


		io.KeyCtrl = io.KeysDown[int(sglKeyCodeValue::left_control)] || io.KeysDown[int(sglKeyCodeValue::right_control)];
		io.KeyShift = io.KeysDown[int(sglKeyCodeValue::left_shift)] || io.KeysDown[int(sglKeyCodeValue::right_shift)];
		io.KeyAlt = io.KeysDown[int(sglKeyCodeValue::left_alt)] || io.KeysDown[int(sglKeyCodeValue::right_alt)];
		return true;
	}
	bool sglImGuiLayer::on_key_typed(event::sglKeyTyped& key_typed)
	{
		auto& io = ImGui::GetIO();
		io.AddInputCharacter(key_typed.get_code());
		return true;
	}
	bool sglImGuiLayer::on_mouse_pressed(sgl::event::sglMousePressed& mouse_pressd)
	{
		auto& io = ImGui::GetIO();
		switch (mouse_pressd.get_key())
		{
		case sglMouseKeyCode::left_button:
			io.MouseDown[0] = true;
			break;
		case sglMouseKeyCode::right_button:
			io.MouseDown[1] = true;
			break;
		}
		return true;
	}
	bool sglImGuiLayer::on_mouse_released(sgl::event::sglMouseReleased& mouse_released) 
	{
		auto& io = ImGui::GetIO();
		switch (mouse_released.get_key())
		{
		case sglMouseKeyCode::left_button:
			io.MouseDown[0] = false;
			break;
		case sglMouseKeyCode::right_button:
			io.MouseDown[1] = false;
			break;
		}
		return true;
	}
	bool sglImGuiLayer::on_mouse_scroll(sgl::event::sglMouseScroll& mouse_scroll) 
	{
		auto& io = ImGui::GetIO();
		io.MouseWheelH += mouse_scroll.get_delta_x();
		io.MouseWheel += mouse_scroll.get_delta_y();
		return true;
	}
	bool sglImGuiLayer::on_mouse_move(sgl::event::sglMouseMove& mouse_move)
	{
		auto& io = ImGui::GetIO();
		io.MousePos = ImVec2{ mouse_move.get_x(), mouse_move.get_y() };
		return true;

	}
	bool sglImGuiLayer::on_window_resize(sgl::event::sglWindowResize& window_resize)
	{
		auto& io = ImGui::GetIO();
		io.DisplaySize = ImVec2{ window_resize.get_width(), window_resize.get_height() };
		return true;
	}
	bool ImGui_ImplSGL_Init(sglImGuiLayer* layer)
	{
		if (!layer)
		{
			// TODO
		}

		auto& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_Tab] = int(sglKeyCodeValue::tab);
		io.KeyMap[ImGuiKey_LeftArrow] = int(sglKeyCodeValue::left);
		io.KeyMap[ImGuiKey_RightArrow] = int(sglKeyCodeValue::right);
		io.KeyMap[ImGuiKey_UpArrow] = int(sglKeyCodeValue::up);
		io.KeyMap[ImGuiKey_DownArrow] = int(sglKeyCodeValue::down);
		io.KeyMap[ImGuiKey_PageUp] = int(sglKeyCodeValue::page_up);
		io.KeyMap[ImGuiKey_PageDown] = int(sglKeyCodeValue::page_down);
		io.KeyMap[ImGuiKey_Home] = int(sglKeyCodeValue::home);
		io.KeyMap[ImGuiKey_End] = int(sglKeyCodeValue::end);
		io.KeyMap[ImGuiKey_Insert] = int(sglKeyCodeValue::insert);
		io.KeyMap[ImGuiKey_Delete] = int(sglKeyCodeValue::del);
		io.KeyMap[ImGuiKey_Backspace] = int(sglKeyCodeValue::backspace);
		io.KeyMap[ImGuiKey_Space] = int(sglKeyCodeValue::space);
		io.KeyMap[ImGuiKey_Enter] = int(sglKeyCodeValue::enter);
		io.KeyMap[ImGuiKey_Escape] = int(sglKeyCodeValue::escape);
		io.KeyMap[ImGuiKey_KeyPadEnter] = int(sglKeyCodeValue::numpad_enter);
		io.KeyMap[ImGuiKey_A] = int(sglKeyCodeValue::A);
		io.KeyMap[ImGuiKey_C] = int(sglKeyCodeValue::C);
		io.KeyMap[ImGuiKey_V] = int(sglKeyCodeValue::V);
		io.KeyMap[ImGuiKey_X] = int(sglKeyCodeValue::X);
		io.KeyMap[ImGuiKey_Y] = int(sglKeyCodeValue::Y);
		io.KeyMap[ImGuiKey_Z] = int(sglKeyCodeValue::Z);

		auto& callbacks = layer->_info->callbacks;
		callbacks.set_event_callback(sglEventProc<event::sglMousePressed>(std::bind(&sglImGuiLayer::on_mouse_pressed, layer,std::placeholders::_1)));
		callbacks.set_event_callback(sglEventProc<event::sglMouseReleased>(std::bind(&sglImGuiLayer::on_mouse_released, layer, std::placeholders::_1)));
		callbacks.set_event_callback(sglEventProc<event::sglKeyPressed>(std::bind(&sglImGuiLayer::on_key_pressed, layer, std::placeholders::_1)));
		callbacks.set_event_callback(sglEventProc<event::sglKeyReleased>(std::bind(&sglImGuiLayer::on_key_released, layer, std::placeholders::_1)));
		callbacks.set_event_callback(sglEventProc<event::sglKeyTyped>(std::bind(&sglImGuiLayer::on_key_typed, layer, std::placeholders::_1)));
		callbacks.set_event_callback(sglEventProc<event::sglMouseScroll>(std::bind(&sglImGuiLayer::on_mouse_scroll,layer,std::placeholders::_1)));
		callbacks.set_event_callback(sglEventProc<event::sglMouseMove>(std::bind(&sglImGuiLayer::on_mouse_move, layer, std::placeholders::_1)));
		callbacks.set_event_callback(sglEventProc<event::sglWindowResize>(std::bind(&sglImGuiLayer::on_window_resize, layer, std::placeholders::_1)));

		int width, height;
		layer->_info->properties.window->get_window_size(&width,&height);
		io.DisplaySize = ImVec2{float(width),float(height)};
		return true;
	}

	sglImGuiLayer::sglImGuiLayer(const sglImGuiLayerProperties& prop)
		:sglLayer("ImGui"), _info(std::make_unique<sglImGuiLayerInfo>())
	{
		this->_info->properties = prop;
	}
	sglImGuiLayer::~sglImGuiLayer() 
	{

	}
	sglAllEventCallbacks sglImGuiLayer::get_callbacks()
	{
		return this->_info->callbacks;
	}
	void sglImGuiLayer::on_attach() 
	{
		this->_info->ctx = ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplSGL_Init(this);

		//ImGui_ImplGlfw_InitForOpenGL(reinterpret_cast<GLFWwindow *>(this->_info->properties.window->get_native_handle()),false);
		ImGui_ImplOpenGL3_Init();
	}
	void sglImGuiLayer::on_detach() 
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext(this->_info->ctx);
	}
	void sglImGuiLayer::on_update(sglLayerTime delta_time)
	{
		auto& io = ImGui::GetIO();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();




		if(this->_info->demo_show)
			ImGui::ShowDemoWindow(&this->_info->demo_show);


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

}