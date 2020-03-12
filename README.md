# Ardboy Sprite Frames Examples
Some simple examples of using sprite frames on Arduboy

## Important! - Licensing

Please note that the `.ino` files all use the BSD 3-clause licence,
whilst the images used are under the Apache 2.0 licence.

This means you can replace the images without any issue,
but if you edit the images or the image files you must provide sufficient notice that they have been modified.

## Contents

### Sprite Cycling Example:
Demonstrate cycling through frames using button presses.

### Sprite Cycling Animation Example:
Demonstrates simple framerate-dependant frame animation.

Note that this technique doesn't scale well because `everyXFrames` counts _all_ frames drawn.
This means that if you wanted to add (for example) a pause mechanism you must think carefully about how to pause the animation (assuming that's your intent).
