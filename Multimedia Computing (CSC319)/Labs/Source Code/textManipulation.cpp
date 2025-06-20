#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set color and style
    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 2);

    // Display initial text
    outtextxy(100, 100, "Hello! My name is Arjun Mijar");

    // Wait for key press
    getch();

    // Clear screen
    cleardevice();

    // Change color and font
    setcolor(YELLOW);
    settextstyle(2, HORIZ_DIR, 4);
    outtextxy(200, 150, "Text Moved & Styled!");

    // Wait and close
    getch();
    closegraph();
    return 0;
}

