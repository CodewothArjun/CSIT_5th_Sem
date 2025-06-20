#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a line
    line(100, 50, 300, 50);

    // Draw a rectangle
    rectangle(100, 100, 300, 200);

    // Draw a circle
    circle(200, 300, 50);

    // Draw an ellipse
    ellipse(200, 400, 0, 360, 100, 50);

    // Draw an arc
    arc(200, 500, 0, 180, 50);

    // Set text
    outtextxy(150, 20, "Basic Graphics Primitives (Arjun Mijar)");

    // Hold screen
    getch();
    closegraph();
    return 0;
}

