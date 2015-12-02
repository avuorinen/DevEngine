/**
 * @file platform/windows/inline/WindowsGraphicsAdapter.inl
 *
 * DevEngine
 * Copyright 2015 Eetu 'Devenec' Oinasmaa
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

// Public

const DisplayMode& GraphicsAdapter::Implementation::currentDisplayMode() const
{
	return _supportedDisplayModes[_currentDisplayModeIndex];
}

Core::String8 GraphicsAdapter::Implementation::name() const
{
	return Core::toString8(_name);
}

const DisplayModeList& GraphicsAdapter::Implementation::supportedDisplayModes() const
{
	return _supportedDisplayModes;
}
