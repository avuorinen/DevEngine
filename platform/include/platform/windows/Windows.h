/**
 * @file platform/windows/Windows.h
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

#if !defined(WIN32_LEAN_AND_MEAN)
	#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <core/ConfigInternal.h>
#include <core/String.h>
#include <core/Types.h>
#include <core/UtilityMacros.h>

#if defined(DE_INTERNAL_BUILD_DEVELOPMENT)
	#define DE_ASSERT_WINDOWS(expression) \
		(expression) ? DE_NO_OPERATION : Platform::failWindowsAssertion(DE_FILE, DE_LINE, DE_FUNCTION)

	#define DE_ERROR_WINDOWS(errorCode) \
		Platform::failWindowsAssertion(DE_FILE, DE_LINE, DE_FUNCTION)
#else
	#define DE_ASSERT_WINDOWS(expression) \
		DE_NO_OPERATION

	#define DE_ERROR_WINDOWS(errorCode) \
		Platform::invokeWindowsError(errorCode)
#endif

namespace Core
{
	class Rectangle;
}

namespace Platform
{
	using WideString = Core::StringTemplate<wchar_t>;

	Core::Rectangle createRectangle(const RECT& rectangle);

	void failWindowsAssertion(const Char8* file, const Uint32 line, const Char8* function);

	HDC getWindowDeviceContextHandle(HWND windowHandle);

	Uint32 getWindowsErrorCode();

	void invokeWindowsError(const Uint32 errorCode);

	Core::String8 fromWideString(const WideString& string);

	WideString toWideString(const Core::String8& string);
}
