#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

#define TIMER_ID 0
#define TIMER_INTERVAL 100
#define MAX 129
#define PI 3.14

float game_time;

float timer_id;

int red_num, green_num;

int i, j, rot, i_rand;

int mod11,no_mod, mod7, mod5, mod4, mod3;

float Cube_x, Cube_y;

float hours, timer, time;

float Gx1, Gy1;

float Gx2, Gy2;

float niz_r[MAX], niz_g[MAX], niz_rand[MAX];
