/**
 * @file graphics/Window.h
 *
 * DevEngine
 * Copyright 2015 Eetu 'Devenec' Oinasmaa
 */

#pragma once

#include <core/String.h>
#include <core/Types.h>

namespace Graphics
{
	using WindowHandle = Void*;

	class Window final
	{
	public:

		Window(const Window& window) = delete;
		Window(Window&& window) = delete;

		WindowHandle handle() const;

		Bool processMessages() const;

		void setFullscreen(const Bool value) const;

		void setTitle(const Core::String8& value) const;

		void show() const;

		Window& operator =(const Window& window) = delete;
		Window& operator =(Window&& window) = delete;

	private:

		friend class WindowManager;

		class Impl;

		Impl* _impl;

		Window(WindowHandle handle);
		~Window();
	};
}
