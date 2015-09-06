/**
 * @file core/LogManager.cpp
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

#include <new>
#include <core/Array.h>
#include <core/Log.h>
#include <core/LogManager.h>
#include <core/Types.h>

using namespace Core;

// External

static Array<Byte, sizeof(Log)> defaultLogMemory;


// Core

Log& Core::defaultLog = *reinterpret_cast<Log*>(defaultLogMemory.data());


// Some members are defined in platform/*/*LogManager.cpp

// Public

void LogManager::deinitialise() const
{
	defaultLog.~Log();
	defaultLog << LogLevel::Debug << "LogManager deinitialised." << Log::Flush();
}

void LogManager::initialise() const
{
	initialisePlatform();
	new (defaultLogMemory.data()) Log();
	defaultLog << LogLevel::Debug << "LogManager initialised." << Log::Flush();
}