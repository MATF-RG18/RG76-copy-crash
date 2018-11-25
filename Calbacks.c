#include "Calbacks.h"

void on_timer(int value){
  if(value!=TIMER_ID)
    return;
  if(game_time > 0){
    game_time -= 0.2;
    rot +=1;
    if(hours < 2.5){
      hours+=0.1;
    }
    else{
      check_random();
      draw_rand_elements();
	hours = 0;
      }
    if(timer){
      glutTimerFunc(TIMER_INTERVAL,on_timer,TIMER_ID);
    }
    glutPostRedisplay();
  }
  else{
    timer = 0;
    game_time = 0;
    /*printf("Kraj igre! \nRED: %d\nGREEN: %d\n", red_num, green_num);
    if(red_num > green_num){
      printf("Crveni igrac je pobedio i osvojio %d bonus poena!\n", bonusR);
      exit(0);
    }else if(green_num > red_num){
      printf("Zeleni igrac je pobedio i osvojio %d bonus poena!\n", bonusG);
      exit(0);
    } else{
      printf("Nereseno je!\n");
      exit(0);
    }*/
  }
}

void on_reshape(int width, int height){

  glViewport(0,0,width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60,(float)width/height,1,50);

}

/*funkcija on_display koja izcrtava mrezu rotiranu do
 * zeljenog polozaja i izcrtava igrace na zeljene polozaje*/
void on_display(void){

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glShadeModel(GL_SMOOTH);
  
    glRotatef(90,1,0,0);
    glRotatef(180,0,1,0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      gluLookAt(0, 2.5, 2.5, 0, 5, 0, 0, 1, 0);
       
      check_position();    
      field();
      RedCube(-Gx1,-Gy1);
      GreenCube(Gx2,Gy2);
      glShadeModel(GL_SMOOTH);
      field_separated();
     
      if(game_time == 100){
	startGame();
      }else{
	if(game_time > 0){
	  Score();
	}else{
	  finalScore();
	}
      }
      if(mod11 == 1){
	for(i=0; i!=i_rand*2;i=i+2){
	  glEnable(GL_DEPTH_TEST);
	X_rand(niz_rand[i], niz_rand[i+1]);	  
 	  glDisable(GL_DEPTH_TEST);
	}  
      } else if (mod7 == 1){
	for(i=0; niz_rand[i+1]!='\0';i=i+2){
	  glEnable(GL_DEPTH_TEST);
	  Arrow_rand(niz_rand[i], niz_rand[i+1]);
 	  glDisable(GL_DEPTH_TEST);	 
	}
      } else if (mod5 == 1){
	for(i=0; niz_rand[i+1]!='\0';i=i+2){
	glEnable(GL_DEPTH_TEST);  
	Cube_rand(niz_rand[i], niz_rand[i+1]);
	glDisable(GL_DEPTH_TEST);
	}
      } else if (mod4 == 1){
	for(i=0; niz_rand[i+1]!='\0';i=i+2){
	  glEnable(GL_DEPTH_TEST);
	  Arrow_rand(niz_rand[i], niz_rand[i+1]);
	  glDisable(GL_DEPTH_TEST);
	}
      } else if (mod3 == 1){
	for(i=0; niz_rand[i+1]!='\0';i=i+2){
	  glEnable(GL_DEPTH_TEST);
	  Cone_rand(niz_rand[i], niz_rand[i+1]);
  	  glDisable(GL_DEPTH_TEST);
	}      
      }else if (no_mod == 1){
	for(i=0; niz_rand[i+1]!='\0';i=i+2){
	  glEnable(GL_DEPTH_TEST);
	  Confuse_rand(niz_rand[i], niz_rand[i+1], i);
	  glDisable(GL_DEPTH_TEST);
	}	
      }

    glEnable(GL_DEPTH_TEST);
      Gamer1();
      Gamer2();
    glDisable(GL_DEPTH_TEST);

    glRotatef(180,0,1,0);
    glRotatef(-90,1,0,0);
  glutSwapBuffers();
}

/* funkcija on keyboard koja pokrece igricu pritiskom na G i izlazi iz nje pritiskom na esc. 
 * Takodje odredjuje pomeranje igraca i njihove koordinate proverava */
void on_keyboard(unsigned char key, int x, int y){
    
    switch(key) { 
      case 27:
      exit(0);
      case 'g':
	printf("Pritisnuto je dugne G, mozete poceti sa igrom.\n");
	if(!timer){
	  glutTimerFunc(10, on_timer, 0);
	  timer = 1;
	}
	break;
      case 'e':
	printf("Pritisnuto je dugne E,kraj igre. izaci sa ECS.\n");
      break;
      /*Tasteri za kretanje igraca 1(crveni) - 4(levo)6(desno)8(gore)5(dole)*/
      case '6':
	Gx1 = Gx1 + 0.25;
	if(Gx1 > 0.875 || (Gx1 == Gx2 && Gy1 == Gy2) || (Gx1 == Cube_x && Gy1 == Cube_y)){
	  Gx1 = Gx1 - 0.25;
	}
	else{
      	  glutPostRedisplay();
	}
	
	break;
      case '4':
	Gx1 = Gx1 - 0.25;
	if(Gx1 < -0.875 || (Gx1 == Gx2 && Gy1 == Gy2) || (Gx1 == Cube_x && Gy1 == Cube_y)){
	  Gx1 = Gx1 + 0.25;
	} 
	else{
      	  glutPostRedisplay();
	}
	break;
      case '8':
	Gy1 = Gy1 + 0.25;
	if(Gy1 > 0.875 || (Gx1 == Gx2 && Gy1 == Gy2) || (Gx1 == Cube_x && Gy1 == Cube_y)){
	  Gy1 = Gy1 - 0.25;
	}
	else{
	  glutPostRedisplay();
	}
	break;
      case '5':
	Gy1 = Gy1 - 0.25;
	if(Gy1 < -0.875 || (Gx1 == Gx2 && Gy1 == Gy2) || (Gx1 == Cube_x && Gy1 == Cube_y)){
	  Gy1 = Gy1 + 0.25;
	}
	else{
	  glutPostRedisplay();
	}
      break;
      
/*Tasteri za kretanje igraca 2(zeleni) - a(levo)d(desno)w(gore)s(dole)*/
      case 'd':
	Gx2 = Gx2 + 0.25;
	if(Gx2 > 0.875 || (Gx1 == Gx2 && Gy1 == Gy2) || (Gx2 == Cube_x && Gy2 == Cube_y)){
	  Gx2 = Gx2 - 0.25;
	}
	else{
	  glutPostRedisplay();
	}
      break;
      case 'a':
	Gx2 = Gx2 - 0.25;
	if(Gx2 < -0.875 || (Gx1 == Gx2 && Gy1 == Gy2) || (Gx2 == Cube_x && Gy2 == Cube_y)){
	  Gx2 = Gx2 + 0.25;
	}
	else{
	  glutPostRedisplay();
	}
	break;
      case 'w':
	  Gy2 = Gy2 + 0.25;
	if(Gy2 > 0.875 || (Gx1 == Gx2 && Gy1 == Gy2) || (Gx2 == Cube_x && Gy2 == Cube_y)){
	  Gy2 = Gy2 - 0.25;
	}
	else{
	  glutPostRedisplay();
	}
	break;
      case 's':
	Gy2 = Gy2 - 0.25;
	if(Gy2 < -0.875 || (Gx1 == Gx2 && Gy1 == Gy2) || (Gx2 == Cube_x && Gy2 == Cube_y)){ 
	  Gy2 = Gy2 + 0.25;
	}
	else{
	  glutPostRedisplay();
	}
	break;
  }
}