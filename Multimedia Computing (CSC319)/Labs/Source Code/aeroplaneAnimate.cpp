#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Function to draw a simple aeroplane
void drawAeroplane(int x, int y) {
    // Plane body
    rectangle(x, y, x + 100, y + 20);
    
    // Tail
    line(x, y, x - 10, y - 10);
    line(x - 10, y - 10, x, y + 10);
    
    // Wing
    line(x + 40, y, x + 20, y - 20);
    line(x + 60, y, x + 80, y - 20);

    // Front curve (nose)
    arc(x + 100, y + 10, 270, 90, 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for (int i = 0; i < getmaxx(); i += 5) {
        cleardevice();
        drawAeroplane(i, 200);
        delay(200);
    }

    getch();
    closegraph();
    return 0;
}

