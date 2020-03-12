//
//  BSD 3-Clause License
//
//  Copyright (c) 2020, Pharap (@Pharap)
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this
//     list of conditions and the following disclaimer.
//
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//  3. Neither the name of the copyright holder nor the names of its
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include <Arduboy2.h>

// NOTE: 'Rabbits.h' is under the Apache 2.0 licence, not BSD 3-Clause
#include "Rabbits.h"

// Arduboy2 library object
Arduboy2 arduboy;

// Called once at startup
void setup()
{
	// Initialise the Arduboy system
	arduboy.begin();
}

// The number of frames in the image
constexpr uint8_t frameCount = 4;

// The first frame index (always 0)
constexpr uint8_t firstFrame = 0;

// The last frame index (one less than the number of frames)
constexpr uint8_t lastFrame = (frameCount - 1);

// The current frame being drawn
uint8_t currentFrame = firstFrame;

// Called continuously
void loop()
{
	// Limit the frame rate (default 60fps)
	if(!arduboy.nextFrame())
		return;
		
	// Update the button state;
	arduboy.pollButtons();
	
	// If 15 frames have passed (at 60fps that's around 1/4 of a second)
	if(arduboy.everyXFrames(15))
	{
		// If the current frame is less than the last frame
		if(currentFrame < lastFrame)
		{
			// Increment the current frame
			++currentFrame;
		}
		// Otherwise
		else
		{
			// Cycle back to the start
			currentFrame = firstFrame;
		}
	}
	
	// Clear the frame buffer
	arduboy.clear();
	
	// x, y, spriteSheet, spriteIndex
	Sprites::drawOverwrite(32, 32, smallRabbitImages, currentFrame);
	
	// Draw the frame buffer onto the screen
	arduboy.display();
}