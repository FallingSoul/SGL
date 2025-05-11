#ifndef __SGL_CORE_RENDERER_BUFFER__
#define __SGL_CORE_RENDERER_BUFFER__

#include "sgl/core/renderer/graphics_context.h"
#include "sgl/core/renderer/layout.h"

namespace sgl
{
	class SGL_API sglVertexBuffer
	{
	public:
		static __sgl_Self__<sglVertexBuffer> create(sglGraphicsContext& gctx);
	public:
		sglVertexBuffer(const sglVertexBuffer&) = delete;
	public:
		sglVertexBuffer(sglGraphicsContext& gctx)
			:_self(create(gctx))
		{}
		virtual ~sglVertexBuffer() = default;
	public:
		virtual void set_data(const float* vertices,size_t size) { this->_self->set_data(vertices,size); }
		virtual void set_subdata(const void* data, size_t size, size_t offset) { this->_self->set_subdata(data, size, offset); }

		virtual uint32_t get_id()const { return this->_self->get_id(); }

		__sgl_Self__<sglVertexBuffer>& get_self() { return this->_self; }
		const __sgl_Self__<sglVertexBuffer>& get_self()const { return this->_self; }
	protected:
		sglVertexBuffer(__sglImplConstruction__) {}
	private:
		__sgl_Self__<sglVertexBuffer> _self;
	};
	class SGL_API sglIndexBuffer
	{
	public:
		static __sgl_Self__<sglIndexBuffer> create(sglGraphicsContext& gctx);
	public:
		sglIndexBuffer(const sglIndexBuffer&) = delete;
	public:
		sglIndexBuffer(sglGraphicsContext& gctx)
			:_self(create(gctx))
		{
		}
		virtual ~sglIndexBuffer() = default;
	public:
		virtual uint32_t get_count()const { return this->_self->get_count(); }
		virtual void set_data(const unsigned* indices, uint32_t count) { this->_self->set_data(indices, count); }
		virtual uint32_t get_id()const { return this->_self->get_id(); }

		__sgl_Self__<sglIndexBuffer>& get_self() { return this->_self; }
		const __sgl_Self__<sglIndexBuffer>& get_self()const { return this->_self; }
	protected:
		sglIndexBuffer(__sglImplConstruction__) {}
	private:
		__sgl_Self__<sglIndexBuffer> _self;

	};
	class SGL_API sglUniformBuffer
	{
	public:
		static __sgl_Self__<sglUniformBuffer> create(sglGraphicsContext& gctx);
	public:
		sglUniformBuffer(sglGraphicsContext& gctx)
			:_self(create(gctx))
		{ }
		virtual ~sglUniformBuffer() = default;
	public:
		virtual void set_binding(uint32_t index) { this->_self->set_binding(index); }
		virtual void set_binding_range(uint32_t index, size_t size, size_t offset) { this->_self->set_binding_range(index, size, offset); }
		virtual void set_data(const void* data, size_t size) { this->_self->set_data(data, size); }
		virtual void set_subdata(const void* data, size_t size,size_t offset) { this->_self->set_subdata(data, size, offset); }
		virtual uint32_t get_id()const { return this->_self->get_id(); }


		__sgl_Self__<sglUniformBuffer>& get_self() { return this->_self; }
		const __sgl_Self__<sglUniformBuffer>& get_self()const { return this->_self; }
	protected:
		sglUniformBuffer(__sglImplConstruction__) {}
	private:
		__sgl_Self__<sglUniformBuffer> _self;
	};
}



#endif //!__SGL_CORE_RENDERER_BUFFER__