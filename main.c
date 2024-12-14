#include "draw.h"
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Position;

// Ball structure
typedef struct {
    Position pos;      // Current position
    Color color;       // Current color
    char fill_char;
} Ball;


void draw_hline(int x, int y, int length, char c, Color color) {
    for (int i = 0; i < length; i++) {
        draw_char(x + i, y, c, color);
    }
}


void draw_vline(int x, int y, int length, char c, Color color) {
    for (int i = 0; i < length; i++) {
        draw_char(x, y + i, c, color);
    }
}


void drawBall(Ball *ball) {
    int center_x = ball->pos.x;
    int center_y = ball->pos.y;
    char c = ball->fill_char;
    Color color = ball->color;


    draw_char(center_x - 1, center_y - 1, c, color);
    draw_char(center_x, center_y - 1, c, color);
    draw_char(center_x + 1, center_y - 1, c, color);


    draw_char(center_x - 2, center_y, c, color);
    draw_char(center_x - 1, center_y, c, color);
    draw_char(center_x, center_y, c, color);
    draw_char(center_x + 1, center_y, c, color);
    draw_char(center_x + 2, center_y, c, color);


    draw_char(center_x - 1, center_y + 1, c, color);
    draw_char(center_x, center_y + 1, c, color);
    draw_char(center_x + 1, center_y + 1, c, color);
}


Color getNextColor(Color color) {
    int next_color = ((color - BLACK) + 1) % NUM_COLORS;
    return (Color)(BLACK + next_color);
}


char getNextFillChar(char c) {
    return (c == 'O') ? 'X' : 'O';
}

bool isCollidingX(Ball *ball, int screenWidth) {
    // Ball extends 2 units to the left and right from the center
    if ((ball->pos.x - 2 <= 1) || (ball->pos.x + 2 >= screenWidth - 2)) {
        return true;
    }
    return false;
}


bool isCollidingY(Ball *ball, int screenHeight) {
    // Ball extends 1 unit above and below from the center
    if ((ball->pos.y - 1 <= 1) || (ball->pos.y + 1 >= screenHeight - 2)) {
        return true;
    }
    return false;
}


void drawBorder(int screenWidth, int screenHeight) {
    // Draw top horizontal border
    draw_hline(0, 0, screenWidth, '-', BLUE);

    // Draw bottom horizontal border
    draw_hline(0, screenHeight - 1, screenWidth, '-', BLUE);

    // Draw left vertical border
    draw_vline(0, 0, screenHeight, '|', BLUE);

    // Draw right vertical border
    draw_vline(screenWidth - 1, 0, screenHeight, '|', BLUE);
}

int main(void)
{
    int screenWidth, screenHeight;
    get_screen_size(&screenWidth, &screenHeight);

    // ball structure values
    Ball ball;
    ball.pos.x = screenWidth / 2;
    ball.pos.y = screenHeight / 2;
    ball.color = RED;
    ball.fill_char = 'O';


    int dx = 1; // move right
    int dy = 1; // move left

    while (1)
    {
        clear_screen();


        drawBorder(screenWidth, screenHeight);

        // ball at its current position
        drawBall(&ball);


        // Updating ball position
        ball.pos.x += dx;
        ball.pos.y += dy;


        if (isCollidingX(&ball, screenWidth)) {
            dx = -dx; // Reverse horizontal direction
            ball.color = getNextColor(ball.color); // Change to next color
        }


        if (isCollidingY(&ball, screenHeight)) {
            dy = -dy; // Reverse vertical direction
            ball.fill_char = getNextFillChar(ball.fill_char); // Toggle fill character
        }


        sleep_ms(100);
    }

    return 0;
}
