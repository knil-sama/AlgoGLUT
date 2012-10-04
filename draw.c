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

void bresenhamG(int xa,int ya,int xb,int yb,float *c)
{
    int dx = xb-xa;
    int dy = yb-ya;
    if(dx !=0)
    {
        if(dx>0)
        {
            if(dy!=0)
            {
                if(dy>0)
                {
                    if(dx>= dy)
                    {
                        int e = dx;
                        dx = 2*e;
                        dy = 2*dy;
                        while(1)
                        {
                            drawPixel(xa,ya,c);
                            xa++;
                            if(xa == xb)
                            {
                                break;
                            }
                            e = e-dy;
                            if(e <0)
                            {
                                ya++;
                                e = e+dx;
                            }
                        }
                    }
                    else
                    {
                        
                    }
                }
            }
        }
    }

}

