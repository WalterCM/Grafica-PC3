
#include <winbgim.h>

const int WIDTH = 350;      // Ancho de la ventana
const int HEIGHT = 380;     // Alto de la ventana

const int COLOR_FILL = 5;   // UDCA + 3
const int COLOT_LINE = 0;   // Color de las lineas

void point(int, int, int, int);
void line(int, int, int, int, int, int);

void edges();
void fillDode(int);

void dodecahedron(int);


int main()
{
    initwindow(WIDTH, HEIGHT); 
    dodecahedron(COLOR_FILL);

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

void edges()
{
    // Lineas superficiales
    line(20, 80, 120, 10, 2, COLOT_LINE);
    line(120, 10, 210, 20, 2, COLOT_LINE);
    line(210, 20, 310, 80, 2, COLOT_LINE);    
    line(310, 80, 330, 190, 6, COLOT_LINE);   
    line(330, 190, 310, 280, 4,COLOT_LINE); 
    line(310, 280, 210, 350, 2, COLOT_LINE);  
    line(210, 350, 120, 333, 2, COLOT_LINE);     
    line(120, 333, 20, 280, 2, COLOT_LINE);     
    line(120, 333, 20, 280, 1, COLOT_LINE);    
    line(20, 280, 0, 170, 6, COLOT_LINE);     
    line(0, 170, 20, 80, 4, COLOT_LINE);    
      
    // Lineas internas
    line(20, 80, 50, 120, 2, COLOT_LINE);
    line(50, 120, 50, 270, 2, COLOT_LINE);
    line(50, 120, 180, 111,2, COLOT_LINE);      
    line(50, 270, 20, 280, 2 , COLOT_LINE);      
    line(50, 270, 170, 310, 2, COLOT_LINE);      
    line(170, 310, 210, 350, 2, COLOT_LINE);         
    line(170, 310, 250, 210, 2, COLOT_LINE);               
    line(250, 210, 180, 111, 2, COLOT_LINE);                     
    line(250, 210, 333, 190, 2, COLOT_LINE);                           
    line(180, 111, 210, 20, 2, COLOT_LINE);                           
      
}

void fillDode(int color)
{
    int v=0;
    for (int y = 10; y <= 170; y++)                 { v+=1; line(20, 80 + v, 120, 10 + v, 2, color); }

    v = 0; for (int y = 10; y <= 170; y++)          { v+=1; line(120, 10 + v, 210, 20 + v, 2, color); }

    v = 0; for (int y = 80; y <= 280; y++)          { v+=1; line(210, 20 + v, 310, 80 + v, 2, color); }
    v = 0; for (int y = 330; y >= 310; y--)         { v+=1; line(310 - v, 80, 330 - v, 190, 6, color); }
    v = 0; for (int y = 330; y >= 310; y--)         { v+=1; line(330 - v, 190, 310 - v, 280, 4, color); }
    v = 0; for (int y = 350; y >= 190; y--)         { v+=1; line(310, 280 - v, 210, 350 - v, 1, color); }  
    v = 0; for (int y = 350; y >= 170; y--)         { v+=1; line(210, 350 - v, 120, 333 - v, 1, color); }   
    v = 0; for (int y = 333; y >= 170; y--)         { v+=1; line(120, 333 - v, 20, 280 - v, 1, color); }   
    v = 0; for (int y = 0; y <= (170 - 150); y++)   { v+=1; line(20 + v, 280, 0 + v, 170, 6, color); } 
    v = 0; for (int y = 0; y <= (170 - 150); y++)   { v+=1; line(0 + v, 170, 20 + v, 80, 4, color); }
}

void dodecahedron(int color)
{
    // Primero rellena y forma la figura
    fillDode(color);
    // Dibuja los lados
    edges();
}
