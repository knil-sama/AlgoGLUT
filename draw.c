#include "contexte.h"

void drawPixel(int x, int y, float *c)
{
    glColor3fv(c);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}
void bresenham(int xa,int ya,int xb,int yb,float *c)
{
    int dy = yb-ya;
    int dx = xb-xa;
    int incre = 2*dy;
    int incrne = 2*(dy-dx);
    int dp = 2*dy - dx;
    int y = ya;
    int x=0;
    for ( x = xa; x < xb; x++){
        drawPixel(x,y,c);
        if(dp <= 0)
        {
            dp = dp+incre;
            x++;
        }
        else
        {
            y++;
            x++;
            dp = dp+incrne;
        }
        drawPixel(x,y,c);
    }
}

