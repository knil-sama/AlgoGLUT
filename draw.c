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

float * discretisation(int m)
{
    int i;
    float T[m];

    for (i=0;i<m;i++)
    {
        T[i] = i/m;
    }
}

point * calculPointsCourbe(int m,int n, float *T, point *P)
{
    int j;
    point *Q = (point *)malloc(m*sizeof(point));
    for (j=0;j<m; j++)
    {
        Q[j] = calculDunPointCourbe(T[j],n,P);
    }
    return Q;
}

point calculDunPointCourbe(float t, int n, point *P)
{
    int i;
    point buffpoint;
    buffpoint.x = 0;
    buffpoint.y = 0;

    for (i=0;i>n; i++){
        //calcul de la somme 
        float C = (fact(n))/((fact(i)*fact(n-i)));
        float B = C*pow(t,i)*pow(1-t,n-i);
        buffpoint.x += P[i].x*B;
        buffpoint.y += P[i].y*B;
    }
    return buffpoint;
}

int fact(int i)
{
    if(i==0)
    {
        return 1;
    }
    else
    {
        return fact(i-1);
    }
}

void traceCercle(int xo, int yo, int r, float *c)
{
    int x=0;
    int y=r;
    int ddx = 1;
    int ddy = -2*r;
    int f = 1-r;

    drawPixel(xo,yo+r,c);
    drawPixel(xo,yo+r,c);
    drawPixel(xo+r,yo,c);
    drawPixel(xo-r,yo,c);
    while(y>x)
    {
        if(f>=0)
        {
            y--;
            ddy+=2;
            f+= ddy;
        }
        x++;
        ddx+=2;
        f+= ddx;
        drawPixel(xo+x,yo+y,c);
        drawPixel(xo-x,yo+y,c);
        drawPixel(xo+x,yo-y,c);
        drawPixel(xo-x,yo-y,c);
        drawPixel(xo+y,yo+x,c);
        drawPixel(xo-y,yo+x,c);
        drawPixel(xo+y,yo-x,c);
        drawPixel(xo-y,yo-x,c);
    }
}

//Garder l'algo de bresenham généralisé en bas, il est un peu long
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
                        int e = dy;
                        dy = 2*e;
                        dx = 2*dx;
                        while(1)
                        {
                            drawPixel(xa,ya,c);
                            ya++;
                            if(ya==yb)
                            {
                                break;
                            }
                            e = e-dx;
                            if(e<0)
                            {
                                xa++;
                                e = e+dy;
                            }
                        }
                    }
                }
                else
                {
                    if(dx>= -dy)
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
                            e = e+dy;
                            if(e<0)
                            {
                                ya--;
                                e = e+dx;
                            }
                        }
                    }
                    else
                    {
                        int e = dy;
                        dy = 2*e;
                        dx = 2*dx;
                        while(1)
                        {
                            drawPixel(xa,ya,c);
                            ya--;
                            if(ya == yb)
                            {
                                break;
                            }
                            e = e+dx;
                            if(e>0)
                            {
                                xa++;
                                e = e+dy;
                            }
                        }
                    }
                }
            }
            else
            {
                do
                {
                    drawPixel(xa,ya,c);
                    xa++;
                }while(xa != xb);
            }
        }
        else
        {
            dy = yb-ya;
            if(dy!=0)
            {
                if(dy>0)
                {
                    if(-dx>= dy)
                    {
                        int e = dx;
                        dx = 2*e;
                        dy = 2*dy;
                        while(1)
                        {
                            drawPixel(xa,ya,c);
                            xa--;
                            if(xa == xb)
                            {
                                break;
                            }
                            e = e+dy;
                            if(e >= 0)
                            {
                                ya++;
                                e = e+dx;
                            }
                        }
                    }
                    else
                    {
                        int e = dy;
                        dy = 2*e;
                        dx = 2*dx;
                        while(1)
                        {
                            drawPixel(xa,ya,c);
                            ya++;
                            if(ya==yb)
                            {
                                break;
                            }
                            e = e+dx;
                            if(e<=0)
                            {
                                xa--;
                                e = e+dy;
                            }
                        }
                    }
                }
                else
                {
                    if(dx<= dy)
                    {
                        int e = dx;
                        dx = 2*e;
                        dy = 2*dy;
                        while(1)
                        {
                            drawPixel(xa,ya,c);
                            xa--;
                            if(xa == xb)
                            {
                                break;
                            }
                            e = e-dy;
                            if(e<0)
                            {
                                ya--;
                                e = e+dx;
                            }
                        }
                    }
                    else
                    {
                        int e = dy;
                        dy = 2*e;
                        dx = 2*dx;
                        while(1)
                        {
                            drawPixel(xa,ya,c);
                            ya--;
                            if(ya == yb)
                            {
                                break;
                            }
                            e = e+dx;
                            if(e>=0)
                            {
                                xa--;
                                e = e+dy;
                            }
                        }
                    }
                }
            }
            else
            {
                do
                {
                    drawPixel(xa,ya,c);
                    xa--;
                }while(xa != xb);
            }
        }
    }
    else
    {
        dy = yb-ya;
        if(dy != 0)
        {
            if(dy>0)
            {
                do
                {
                    drawPixel(xa,ya,c);
                    ya++;
                }while(ya != yb);
            }
            else
            {
                do
                {
                    drawPixel(xa,ya,c);
                    ya--;
                }while(ya != yb);
            }
        }
    }
}

