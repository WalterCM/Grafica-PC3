#include <winbgim.h>
#include <cmath>

const int WIDTH = 600;
const int HEIGHT = 600;

const float PI = 3.141592;      // Para transformar a radianes
const int COLOR0 = 4;           // UDCA + 2
const int COLOR1 = 5;           // UDCA + 3
const int COLOR2 = 6;           // UDCA + 4
const int COLOR_LINEA = 0;

void point(int, int, int, int);
void line(int, int, int, int, int, int);
void cube(int, int, int, float);

int main(){
    initwindow(WIDTH, HEIGHT);
    
    cube(300, 150, 399, 45);
    
    getch();            
    return 0;
}

void point(int x, int y, int width, int color)
{
    int half = width / 2;
    for (int i = x - half; i <= x + half; i++)
        for (int j = y - half; j <= y + half; j++)
            putpixel(i, j, color);
}

void line(int x0, int y0, int x1, int y1, int width, int color)
{
     int y;
     
     float dy = y1 - y0;        // Diferencia en y
     float dx = x1 - x0;        // Diferencia en x
     float m = dy / dx;         // Pendiente
     
     if (x0 == x1)
       for (int j = 0; j < dy; j++)
          point(x0, y0 + j, width, color);
     
     if (x0 < x1) {
        for (int i = x0; i <= x1; i++) {
            y = int(m * (i - x0) + y0);
            point(i, y, width, color);
        }
     } else {
        for (int i = x1; i <= x0; i++) {
            y = int(m * (i - x0) + y0);
            point(i, y, width, color);
         }          
     }
}

void cube(int x, int y, int diagonal, float angle)
{
    // Se transforma angulos a radianes
    angle = angle * PI / 180;
    
    // Cada cara inferion se dibujara en cada mitad
    // Por eso se obtiene el radio de la circunferencia circunscrita
    int circ = diagonal / 2;
    
    // Distancia de la vertical de las caras inferiores
    float d =  diagonal * sqrt(2) / 2;
    int k = circ * tan(angle);
    
    // Dibuja los 3 colores de las caras
    for (float i = 0; i <= circ; i++) {
        float h = i * tan(angle);

        // Caras inferiores
        line(x - circ + i, y + h, x - circ + i,  y + h + d, 1, COLOR0);
        line(x + circ - i, y + h, x + circ - i,  y + h + d, 1, COLOR1);

        // Cara superior usando el mismo angulo
        line(x - circ + i , y + i * tan(angle), x + i, y - k + i * tan(angle), 2, COLOR2);
    }

    // Pintan las lineas de la cara superior y las verticales de las inferiores
    for (int i = 0; i <= circ; i += circ / 3) {
        float h = i * tan(angle);
        
        line(x - circ + i, y + h, x - circ + i,  y + h + d, 2, COLOR_LINEA);
        line(x + circ - i, y + h, x + circ - i,  y + h + d, 2, COLOR_LINEA);
        line(x - circ + i , y + i * tan(angle), x + i, y - k + i * tan(angle), 2, COLOR_LINEA);
        line(x + circ - i , y + i * tan(angle), x - i, y - k + i * tan(angle), 2, COLOR_LINEA);
    }

    // Se dibujan las horizontales de las inferiores
    for (float i = d / 3; i < d; i += d / 3) {
        line(x - circ, y + i, x, y + k + i, 2, 0);
        line(x + circ, y + i, x, y + k + i, 2, 0);
        
    }
}
