/**
 * @file platform/opengl/OpenGLGraphicsBuffer.cpp
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

#include <core/Memory.h>
#include <platform/opengl/OpenGLGraphicsBuffer.h>

using namespace Graphics;

// Implementation

// Public

GraphicsBuffer::Implementation::Implementation(const BufferBinding& binding, const Uint size,
	const AccessMode& accessMode, const BufferUsage& usage)
	: Base(binding, size, accessMode, usage) { }


// Graphics::GraphicsBuffer

// Public

void GraphicsBuffer::demapData() const
{
	_implementation->demapData();
}

Uint8* GraphicsBuffer::mapData() const
{
	return _implementation->mapData();
}

Uint8* GraphicsBuffer::mapData(const Uint size, const Uint bufferOffset) const
{
	return _implementation->mapData(size, bufferOffset);
}

// Private

GraphicsBuffer::GraphicsBuffer(GraphicsInterfaceHandle graphicsInterfaceHandle, const BufferBinding& binding,
	const Uint size, const AccessMode& accessMode, const BufferUsage& usage)
	: _implementation(nullptr)
{
	static_cast<Void>(graphicsInterfaceHandle);
	_implementation = DE_NEW(Implementation)(binding, size, accessMode, usage);
}

GraphicsBuffer::~GraphicsBuffer()
{
	DE_DELETE(_implementation, Implementation);
}
