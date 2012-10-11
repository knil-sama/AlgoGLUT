#ifndef DEF_DRAW
#define DEF_DRAW

typedef struct point{int x; int y;}point;

void drawPixel(int x, int y, float *c);
void bresenhamG(int xa,int ya,int xb,int yb,float *c);
void bresenham(int xa,int ya,int xb,int yb,float *c);
void traceCercle(int xo, int yo, int r, float *c);
float * discretisation(int m);
point * calculPointsCourbe(int m,int n, float *T, point *P);
point calculDunPointCourbe(float t, int n, point *P);

#endif