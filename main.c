#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Calbacks.h"
#include "Globals.h"

int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  


  glutInitWindowSize(400,400);
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[0]);

  glShadeModel(GL_SMOOTH);
 
  game_time = 100;
  timer_id = 10;
  rot = 0;
  mod11 = 0,no_mod= 0, mod7 = 0, mod5 = 0, mod4 = 0, mod3 = 0;
  Cube_x=0, Cube_y=0;
  hours = 0.0, timer = 0, time = 10;
  Gx1 = 0.875, Gy1 = 0.875;
  Gx2 = -0.875, Gy2 = -0.875;
     
  glutKeyboardFunc(on_keyboard);
  glutReshapeFunc(on_reshape);
  glutDisplayFunc(on_display);
  glClearColor(0, 0, 0, 0);

  glLineWidth(1);
  glutMainLoop();


return 0;
}