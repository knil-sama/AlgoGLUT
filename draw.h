#ifndef DEF_DRAW
#define DEF_DRAW

void drawPixel(int x, int y, float *c);
void bresenhamG(int xa,int ya,int xb,int yb,float *c);
void bresenham(int xa,int ya,int xb,int yb,float *c);
void traceCercle(int xo, int yo, int r, float *c);


#endif