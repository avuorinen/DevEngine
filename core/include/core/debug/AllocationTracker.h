/**
 * @file core/debug/AllocationTracker.h
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

#include <core/ConfigInternal.h>

#if defined(DE_INTERNAL_CONFIG_TRACK_ALLOCATIONS)

#include <functional>
#include <memory>
#include <utility>
#include <core/Map.h>
#include <core/Singleton.h>
#include <core/Types.h>

namespace Debug
{
	class AllocationTracker final : public Core::Singleton<AllocationTracker>
	{
	public:

		AllocationTracker();

		AllocationTracker(const AllocationTracker& allocationTracker) = delete;
		AllocationTracker(AllocationTracker&& allocationTracker) = delete;

		~AllocationTracker() = default;

		void deinitialise();

		void deregisterAllocation(Void* pointer, const Uint size);

		void initialise();

		void registerAllocation(Void* pointer, const Uint size, const Char8* file, const Uint32 line,
			const Char8* function);

		AllocationTracker& operator =(const AllocationTracker& allocationTracker) = delete;
		AllocationTracker& operator =(AllocationTracker&& allocationTracker) = delete;

	private:

		struct AllocationRecord final
		{
			const Char8* file;
			const Char8* function;

			Uint size;
			Uint32 line;

			AllocationRecord(const Uint size, const Char8* file, const Uint32 line, const Char8* function)
				: file(file),
				  function(function),
				  size(size),
				  line(line) { }
		};

		using AllocationRecordMap =
			Core::Map<Void*, AllocationRecord, std::hash<Void*>, std::equal_to<Void*>,
				std::allocator<std::pair<Void* const, AllocationRecord>>>;

		AllocationRecordMap _allocationRecords;
		Bool _isInitialised;

		void checkForMemoryLeaks() const;

		static void logAllocationRecord(const Void* address, const AllocationRecord& allocationRecord);
	};
}

#endif
