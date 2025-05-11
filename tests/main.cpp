#include "sgl/sgl.h"
#include "sgl/framework.h"
#include "sgl/platform/imgui_layer.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


class TestLayer : public sgl::sglLayer
{
public:
    TestLayer()
        :sglLayer("Test")
    {

    }
    bool on_keypressed(sgl::event::sglKeyPressed & kp)
    {
        SGL_LOG_I("{}",int(kp.get_key()));
        return true;
    }
    virtual void on_attach()override
    {
        SGL_LOG_I("Test on_attach");


        const char* vert_shader = R"(
            #version 330 core
            layout (location = 0) in vec3 a_Position;
            layout (location = 1) in vec2 a_TexCoord;

            layout (std140) uniform Matrices
            {
                mat4 view_mat;
                mat4 projection_mat;
            };
            out vec2 tex_coord;

            void main()
            {
                tex_coord = a_TexCoord;
                //vert_color = texture(image,a_TexCoord);
                //vert_color = vec4(1,0,1,1);
                //vert_color = vec4(a_TexCoord.x,a_TexCoord.y,a_TexCoord.x * a_TexCoord.y,1);
                gl_Position = projection_mat * view_mat * vec4(a_Position,1.0);
            }
            )";
        const char* frag_shader = R"(
            #version 330 core
            in vec2 tex_coord;
			out vec4 frag_color;
            uniform sampler2D image;
            void main()
            {
                frag_color = texture(image,tex_coord);
            }
            )";
        const float triangle_vertices[] =
        {
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f,0.0f
        };
        const unsigned triangle_indices[] =
        {
            0,1,2
        };
        const float square_vertices[] =
        {
            -0.75f,0.75f,0.0f,0.0f,1.0f,
            -0.75f,-0.75f,0.0f,0.0f,0.0f,
            0.75f,-0.75f,0.0f,1.0f,0.0f,
            0.75f,0.75f,0.0f,1.0f,1.0f
        };
        const unsigned square_indices[] =
        {
            0,1,2,
            0,2,3
        };
        this->_camera.remake(sgl::sglCameraVec({ 0,0,3 }, { 0,0,0 }));
        this->_camera->update_perspective_projection(3.1415926f / 3, 16.f / 9.f, 0.1f, 100.f);

        auto gctx = sgl::sglApplication::get_application()->get_graphics_context();

        this->_vao.remake(*gctx);
        this->_vbo.remake(*gctx);
        this->_ibo.remake(*gctx);
        this->_ubo.remake(*gctx);
        this->_vbo->set_data(square_vertices, sizeof(square_vertices));
        this->_ibo->set_data(square_indices, sizeof(square_indices));
        this->_vao->add_vertex_buffer(this->_vbo, sgl::sglGenerateVertexLayout({ sgl::sglShaderLayoutType::Float3,sgl::sglShaderLayoutType::Float2 }));
        this->_vao->set_index_buffer(this->_ibo);
        this->_ubo->set_binding(1);
        this->_shader.remake(*gctx);
        this->_shader->compile(vert_shader,frag_shader);
        this->_shader->set_uniform_binding("Matrices",1);
        this->_shader->set_uniform_sampler("image",1);

        int width, height, channel;
        stbi_set_flip_vertically_on_load(true);
        auto image = stbi_load("test.png", &width, &height, &channel, 4);

        this->_texture.remake(*gctx);
        this->_texture->image(image, width, height);

        stbi_image_free(image);

        auto matrices = this->_camera->get_matrices();
        this->_ubo->set_data(&matrices, sizeof(matrices));
        
        
    }
    virtual void on_detach()override
    {
        SGL_LOG_I("Test on_detach");
    }
    virtual void on_update(sglLayerTime delta_time)override
    {
        auto renderer = sgl::sglApplication::get_application()->get_renderer();
        renderer->begin_scene();
        this->_shader->use();
        this->_texture->upload(1);
        renderer->submit(this->_vao);
        renderer->end_scene();

        SGL_LOG_I("delta_time: {} fps: {}", delta_time.time(),1 / delta_time.time());
    }
    virtual sgl::sglAllEventCallbacks get_callbacks()override
    {
        std::function<bool (sgl::event::sglKeyPressed&)> f = std::bind(&TestLayer::on_keypressed, this, std::placeholders::_1);
        sgl::sglEventCallbacks<sgl::event::sglKeyPressed> callback(f);
        return callback;
    }

private:
    sgl::sglRef<sgl::sglVertexArray> _vao;
    sgl::sglRef<sgl::sglVertexBuffer> _vbo;
    sgl::sglRef<sgl::sglIndexBuffer> _ibo;
    sgl::sglRef<sgl::sglUniformBuffer> _ubo;
    sgl::sglRef<sgl::sglShader> _shader;
    sgl::sglRef<sgl::sglTexture2D> _texture;

    sgl::sglRef<sgl::sglCamera> _camera;
};

class Test : public sgl::sglApplication 
{
public:
public:
    Test()
    {
        this->init_window({ .name = "SGL Window",.width = 1920,.height = 1080});
        this->init_graphics_context({.window = this->get_window(),.api = sgl::sglGraphicsAPI::OpenGL});
        this->init_renderer();


        this->init_layer_stack();
        auto ls = this->get_layer_stack();

        sgl::sglImGuiLayerProperties prop =
        {
            .window = this->get_window(),
            .graphics_context = this->get_graphics_context()
        };
        this->imgui = std::make_unique<sgl::sglImGuiLayer>(prop);
        ls->push_overlay(this->imgui.get());
        ls->push(&layer);
    }
    ~Test()
    {}

private:
    TestLayer layer;
    std::unique_ptr<sgl::sglImGuiLayer> imgui;
};

sgl::sglApplication* sgl::sglCreateApplication()
{
    auto app = new Test;
    return app;
}
void sgl::sglReleaseApplication(sgl::sglApplication* app)
{
    delete app;
}

