#pragma once

//
//  Copyright (C) 2020 Pharap (@Pharap)
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

// For uint8_t
#include <stdint.h>

constexpr uint8_t smallRabbitImageWidth = 8;
constexpr uint8_t smallRabbitImageHeight = 8;

constexpr uint8_t smallRabbitImages[] PROGMEM
{
	// Dimensions
	smallRabbitImageWidth, smallRabbitImageHeight,
	
	// Frame 0 (North)
	0x00, 0x78, 0x7E, 0x78, 0x78, 0x7E, 0x78, 0x00,
	
	// Frame 1 (East)
	0x00, 0x00, 0x78, 0x7E, 0x48, 0x78, 0x00, 0x00,
	
	// Frame 2 (South)
	0x00, 0x78, 0x4E, 0x78, 0x78, 0x4E, 0x78, 0x00,
	
	// Frame 3 (West)
	0x00, 0x00, 0x78, 0x48, 0x7E, 0x78, 0x00, 0x00,
};