struct Point { float x, y; };

void func(struct Point *p, float *x, int *i, char *c)
{
    p->x = 0;
    p->y = 0;
    *x = 0.0;
    *i = 0;
    *c = 0;
}
