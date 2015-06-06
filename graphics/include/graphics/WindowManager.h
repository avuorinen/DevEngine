/**
 * @file graphics/WindowManager.h
 *
 * DevEngine
 * Copyright 2015 Eetu 'Devenec' Oinasmaa
 */

#pragma once

#include <core/Singleton.h>
#include <core/Types.h>

namespace Graphics
{
	class Window;

	class WindowManager final : public Core::Singleton<WindowManager>
	{
	public:

		WindowManager();

		WindowManager(const WindowManager& windowManager) = delete;
		WindowManager(WindowManager&& windowManager) = delete;

		~WindowManager() = default;

		Window* createWindow();

		void deinitialise();

		void initialise();

		void setCursorVisibility(const Bool value);

		WindowManager& operator =(const WindowManager& windowManager) = delete;
		WindowManager& operator =(WindowManager&& windowManager) = delete;

	private:

		class Impl;

		Impl* _impl;
		Window* _window;

		void destroyWindow();
	};
}
