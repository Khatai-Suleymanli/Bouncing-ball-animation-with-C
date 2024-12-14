Bouncing Ball Animation in Terminal

**Description**

A simple terminal-based bouncing ball animation implemented in C. The ball moves within the terminal window, bouncing off the blue borders while changing color and toggling its fill character upon collisions.

**Features**

Dynamic Movement: Ball starts at the center and moves diagonally, reversing direction upon hitting borders.
Visual Effects: Changes color on horizontal collisions and toggles between 'O' and 'X' on vertical collisions.
Terminal Borders: Blue-colored borders drawn using horizontal (-) and vertical (|) lines.

**Files**

terminal_draw.h
Provides terminal manipulation functions such as drawing characters, clearing the screen, getting screen size, and sleeping.
bouncing_ball.c
Contains the implementation of the bouncing ball animation, including structures, drawing functions, state changes, and collision detection.

**Compilation**

Ensure both bouncing_ball.c and terminal_draw.h are in the same directory. Use the GCC compiler to compile the program.
gcc -o bouncing_ball bouncing_ball.c

**Usage
**
Run the compiled program from the terminal:

bash
Copy code
./bouncing_ball
Exit: Press Ctrl + C to terminate the animation.

**Requirements**

C Compiler: GCC or any compatible C compiler.
Terminal: Supports ANSI escape codes for proper color rendering.
How It Works

**Initialization:**

The ball is placed at the center of the terminal.
Initial color is set to RED, and the fill character is 'O'.
Movement is set to one position right (dx = 1) and one position down (dy = 1) per frame.

**Main Loop:**

Clears the screen and draws blue borders.
Renders the ball at its current position.
Updates the ball's position based on its velocity.
Detects collisions with borders:
Horizontal Collisions: Reverse horizontal direction and change color.
Vertical Collisions: Reverse vertical direction and toggle fill character.
Controls animation speed with a sleep interval.

**Notes**
Terminal Size: Ensure your terminal window is large enough to accommodate the ball's movement and borders.
Customization: Adjust the sleep_ms duration in bouncing_ball.c to modify animation speed.
License

This project is open-source and available for educational purposes.


Select the entire text block above (from Bouncing Ball Animation in Terminal to the end) and copy it.
Paste into the Text Editor:

Paste the copied content into your text editor.
Save the File:

Save the file with the name README.txt in your project directory.
