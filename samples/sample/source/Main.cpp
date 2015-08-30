/**
 * @file samples/sample/Main.cpp
 *
 * DevEngine
 * Copyright 2015 Eetu 'Devenec' Oinasmaa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <content/ContentManager.h>
#include <core/Application.h>
#include <core/Types.h>
#include <core/Vector.h>
#include <graphics/Colour.h>
#include <graphics/Effect.h>
#include <graphics/GraphicsAdapterManager.h>
#include <graphics/GraphicsBuffer.h>
#include <graphics/GraphicsContext.h>
#include <graphics/GraphicsContextManager.h>
#include <graphics/GraphicsDevice.h>
#include <graphics/Image.h>
#include <graphics/IndexBuffer.h>
#include <graphics/Shader.h>
#include <graphics/VertexBufferState.h>
#include <graphics/VertexElement.h>
#include <graphics/Viewport.h>
#include <graphics/Window.h>
#include <graphics/WindowManager.h>

using namespace Content;
using namespace Core;
using namespace Graphics;

static const Char8* VERTEX_SHADER_SOURCE
(
	"#version 450\n"
	"\n"
	"layout(location = 0) in vec4 inPosition;\n"
	"layout(location = 1) in vec3 inColour;\n"
	"\n"
	"out vec3 colour;\n"
	"\n"
	"void main()\n"
	"{\n"
	"	colour = inColour;\n"
	"	gl_Position = inPosition;\n"
	"}\n"
);

static const Char8* FRAGMENT_SHADER_SOURCE
(
	"#version 450\n"
	"\n"
	"in vec3 colour;\n"
	"out vec4 outColour;\n"
	"\n"
	"void main()\n"
	"{\n"
	"	outColour = vec4(colour, 1.0);\n"
	"}\n"
);

void devEngineMain(const StartupParameters& startupParameters)
{
	static_cast<Void>(startupParameters);

	ContentManager contentManager;
	GraphicsAdapterManager graphicsAdapterManager;
	WindowManager windowManager;
	GraphicsContextManager graphicsContextManager;

	Window* window = windowManager.createWindow();
	Image* image = contentManager.load<Image>("assets/icon.png");
	window->setIcon(image);
	window->setTitle("DevEngine - \xD0\xBA\xD0\xBE\xD1\x88\xD0\xBA\xD0\xB0");
	window->show();

	GraphicsContext* graphicsContext = graphicsContextManager.createGraphicsContext(window);
	graphicsContext->makeCurrent();
	GraphicsDevice graphicsDevice;

	Shader* vertexShader = graphicsDevice.createShader(ShaderType::Vertex, VERTEX_SHADER_SOURCE);
	Shader* fragmentShader = graphicsDevice.createShader(ShaderType::Fragment, FRAGMENT_SHADER_SOURCE);
	Effect* effect = graphicsDevice.createEffect();
	effect->attachShader(vertexShader);
	effect->attachShader(fragmentShader);
	effect->link();
	graphicsDevice.destroyResource(fragmentShader);
	graphicsDevice.destroyResource(vertexShader);

	Vector<Float32> VERTEX_DATA
	{
		 0.0f,	0.8f, 0.0f,
		 0.0f,

		-0.8f,	0.0f, 0.0f,
		 0.0f,

		 0.8f,	0.0f, 0.0f,
		 0.0f,

		 0.0f, -0.8f, 0.0f,
		 0.0f
	};

	Uint32 colour = 0x000003FF;
	VERTEX_DATA[3] = *reinterpret_cast<Float32*>(&colour);
	colour = 0x000FFC00;
	VERTEX_DATA[7] = *reinterpret_cast<Float32*>(&colour);
	colour = 0x3FF00000;
	VERTEX_DATA[11] = *reinterpret_cast<Float32*>(&colour);
	colour = 0x000FFFFF;
	VERTEX_DATA[15] = *reinterpret_cast<Float32*>(&colour);

	const Vector<Uint8> INDEX_DATA
	{
		 0u, 1u, 2u,
		 3u, 2u, 1u,
	};

	GraphicsBuffer* vertexBuffer = graphicsDevice.createBuffer(sizeof(Float32) * VERTEX_DATA.size());
	vertexBuffer->setData(reinterpret_cast<const Byte*>(VERTEX_DATA.data()), sizeof(Float32) * VERTEX_DATA.size());
	IndexBuffer* indexBuffer = graphicsDevice.createIndexBuffer(sizeof(Uint8) * INDEX_DATA.size(), IndexType::Uint8);
	indexBuffer->setData(reinterpret_cast<const Byte*>(INDEX_DATA.data()), sizeof(Uint8) * INDEX_DATA.size());
	VertexBufferState* vertexBufferState = graphicsDevice.createVertexBufferState();

	vertexBufferState->setVertexLayout
	({
		VertexElement(0u, 0u, VertexElementType::Float32Vector3),
		VertexElement(1u, 0u, VertexElementType::Uint32_R10G10B10A2)
	});

	vertexBufferState->setVertexBuffer(vertexBuffer, 0u, 4u * sizeof(Float32));
	vertexBufferState->setIndexBuffer(indexBuffer);
	graphicsDevice.setEffect(effect);
	graphicsDevice.setVertexBufferState(vertexBufferState);

	while(!window->shouldClose())
	{
		windowManager.processMessages();
		graphicsDevice.clear(Colour(0.8f, 0.0f, 1.0f));

		graphicsDevice.setViewport(Viewport(Rectangle(0, 0, 400u, 300u)));
		graphicsDevice.draw(PrimitiveType::TriangleStrip, 4u);

		graphicsDevice.setViewport(Viewport(Rectangle(400, 0, 400u, 300u)));
		graphicsDevice.drawIndexed(PrimitiveType::Triangle, 3u, 3u);

		graphicsDevice.setViewport(Viewport(Rectangle(0, 300, 400u, 300u)));
		graphicsDevice.draw(PrimitiveType::Point, 4u);

		graphicsDevice.setViewport(Viewport(Rectangle(400, 300, 400u, 300u)));
		graphicsDevice.draw(PrimitiveType::Line, 4u);
		graphicsDevice.draw(PrimitiveType::Line, 2u, 1u);

		graphicsContext->swapBuffers();
	}
}
