#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawCar(int x, int y) {
    // Car body
    rectangle(x, y, x + 100, y + 20);
    rectangle(x + 20, y - 20, x + 80, y);
    
    // Wheels
    circle(x + 25, y + 25, 10);
    circle(x + 75, y + 25, 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    outtextxy(100, 100, "By Arjun Mijar");

    for (int i = 0; i < getmaxx(); i += 5) {
        cleardevice();
        drawCar(i, 200);
        delay(100);  // Small delay for animation effect
    }

    getch();
    closegraph();
    return 0;
}

