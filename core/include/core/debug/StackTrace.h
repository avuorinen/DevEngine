/**
 * @file core/debug/StackTrace.h
 *
 * DevEngine
 * Copyright 2015 Eetu 'Devenec' Oinasmaa
 */

#pragma once

#include <core/String.h>
#include <core/Types.h>
#include <core/Vector.h>

namespace Debug
{
	struct StackEntry final
	{
		Core::String filepath;
		Core::String functionName;
		Uint64 address;
		Uint32 fileLine;
	};

	using StackEntries = Core::Vector<StackEntry>;

	class StackTrace final
	{
	public:

		StackTrace(const Uint32 maxEntryCount);

		~StackTrace();

		StackEntries generate() const;

	private:

		template<typename T>
		class Impl;

		Impl<Char>* _impl;

		StackTrace(const StackTrace& stackTrace) = delete;
		StackTrace(StackTrace&& stackTrace) = delete;

		StackTrace& operator =(const StackTrace& stackTrace) = delete;
	};
}
