/**
 * @file graphics/GraphicsDevice.h
 *
 * DevEngine
 * Copyright 2015-2016 Eetu 'Devenec' Oinasmaa
 *
 * DevEngine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DevEngine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DevEngine. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <core/List.h>
#include <core/Types.h>

namespace Platform
{
	class GraphicsContext;
	class GraphicsDeviceFactory;
}

namespace Graphics
{
	enum class AccessMode;
	enum class BufferBinding;
	enum class BufferUsage;
	enum class IndexType;
	enum class PrimitiveType;
	enum class ShaderType;

	class Colour;
	class Effect;
	class EffectCode;
	class GraphicsBuffer;
	class GraphicsResource;
	class IndexBuffer;
	class Shader;
	class VertexBufferState;
	class Viewport;

	class GraphicsDevice final
	{
	public:

		GraphicsDevice(const GraphicsDevice& graphicsDevice) = delete;
		GraphicsDevice(GraphicsDevice&& graphicsDevice) = delete;

		void bindBufferIndexed(GraphicsBuffer* buffer, const Uint32 bindingIndex) const;

		void clear(const Colour& colour) const;

		GraphicsBuffer* createBuffer(const BufferBinding& binding, const Uint size,
			const AccessMode& accessMode, const BufferUsage& usage);

		Effect* createEffect(EffectCode* effectCode);

		IndexBuffer* createIndexBuffer(const Uint size, const IndexType& indexType,
			const AccessMode& accessMode, const BufferUsage& usage);

		VertexBufferState* createVertexBufferState();

		void debindBufferIndexed(GraphicsBuffer* buffer, const Uint32 bindingIndex) const;

		void destroyResource(GraphicsResource* resource);

		void draw(const PrimitiveType& primitiveType, const Uint32 vertexCount,
			const Uint32 vertexOffset = 0u) const;

		void drawIndexed(const PrimitiveType& primitiveType, const Uint32 indexCount,
			const Uint32 indexOffset = 0u) const;

		void setEffect(Effect* effect) const;

		void setVertexBufferState(VertexBufferState* vertexBufferState) const;

		void setViewport(const Viewport& viewport) const;

		void swapBuffers() const;

		const Viewport& viewport() const;

		GraphicsDevice& operator =(const GraphicsDevice& graphicsDevice) = delete;
		GraphicsDevice& operator =(GraphicsDevice&& graphicsDevice) = delete;

	private:

		friend class GraphicsDeviceManager;
		friend class Platform::GraphicsDeviceFactory;

		class Implementation;

		using GraphicsResourceList = Core::List<GraphicsResource*>;

		GraphicsResourceList _resources;
		Implementation* _implementation;

		explicit GraphicsDevice(Platform::GraphicsContext* graphicsContext);
		~GraphicsDevice();

		void destroyResources() const;
	};
}
