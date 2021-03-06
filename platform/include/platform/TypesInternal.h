/**
 * @file platform/TypesInternal.h
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

#include <core/Platform.h>

#if DE_ARCHITECTURE == DE_ARCHITECTURE_X86

using IntInternal  = Int32;
using UintInternal = Uint32;

#elif DE_ARCHITECTURE == DE_ARCHITECTURE_X64

using IntInternal  = Int64;
using UintInternal = Uint64;

#endif
