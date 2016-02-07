/**
 * @file platform/TypesInternal.cpp
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

#include <core/Types.h>

#if DE_ARCHITECTURE == DE_ARCHITECTURE_X86

static_assert(sizeof(Int) == 4, "The size of Int is incorrect.");
static_assert(sizeof(Uint) == 4, "The size of Uint is incorrect.");
static_assert(sizeof(Void*) == 4, "The size of pointer (Void*) is incorrect.");

#elif DE_ARCHITECTURE == DE_ARCHITECTURE_X64

static_assert(sizeof(Int) == 8, "The size of Int is incorrect.");
static_assert(sizeof(Uint) == 8, "The size of Uint is incorrect.");
static_assert(sizeof(Void*) == 8, "The size of pointer (Void*) is incorrect.");

#endif