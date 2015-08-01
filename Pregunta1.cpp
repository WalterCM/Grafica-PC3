#include <iostream>
#include <winbgim.h>
#include <cmath>

using namespace std;

const int WIDTH  = 800;     // Ancho de la ventana
const int HEIGHT = 600;     // Alto de la ventana

const int COLOR  = 5;       // Color del circulo UDCA + 3
const int GROSOR = 4;       // Grosor del circulo UDCA + 2

void point (int, int, int, int);
void circle(int, int, int, int, int);

int main()
{
    initwindow(WIDTH, HEIGHT);
    circle(WIDTH / 2, HEIGHT / 2, 250, GROSOR, COLOR);
    getch();
	return 0;
}

// Funcion que dibuja un punto en las coordenadas dadas
void point(int x,int y,int g,int c)
{
    int a = g / 2;
    for (int i = x - a; i <= x + a; i++)
        for (int j = y - a; j <= y + a; j++)
            putpixel(i, j, c);
}

// La funcion recorre el rango de 'x' en un cuadrante y obtiene las respectivas 'y'
// Luego dibuja 4 puntos, uno por cada cuadrante
void circle(int x, int y, int radius, int width, int color)
{
    float epsilon = 0.01;
    for (float i = 0; i <= radius; i += epsilon) {
        // Condicional para optimizacion
        if (i > radius - 5 || i - (int)i < epsilon) {
            float h = (float)sqrt(radius * radius - i * i);
            point(x + i, y + h, width, color);
            point(x + i, y - h, width, color);
            point(x - i, y + h, width, color);
            point(x - i, y - h, width, color);
        }
    }
}
