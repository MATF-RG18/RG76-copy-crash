#include <GL/glut.h>
#include "Draw_elements.h"

/*iscrtavanje polja na kome se kasnije crta mreza*/
void field(){
  
  glPushMatrix();
    glBegin(GL_POLYGON);
      glShadeModel(GL_SMOOTH);
      glColor3f(0.90, 0.8, 0);
      glVertex3f(-1,1,0);
      glVertex3f(-1,-1,0);
      glVertex3f(1,-1,0);
      glVertex3f(1,1,0);
    glEnd();
  glPopMatrix();
  
}
/*Iscrtavanje mreze polja po kojima se igraci krecu*/
void field_separated(){

  glShadeModel(GL_SMOOTH);
  glPushMatrix();
    glBegin(GL_LINES);
      int i;
      float j=-1;
      
      for(i=0;i<16;i++){
	if(i< 8){
	  glColor3f(0,0,0);
	    glVertex3f(j,-1,0);
	    glVertex3f(j,1,0);
	  j = j+0.25;   
	}
	else{
	  glColor3f(0,0,0);
	    glVertex3f(-1,j,0);
	    glVertex3f(1,j,0);
	  j = j-0.25;   	
	}
    }
    glEnd();
  glPopMatrix();
}

/* funkcija koja na ekran iscrtava nekoliko igraca koji su slicni ogracima 1 i 2 */
void Confuse_rand(float px, float py, int k){
  px = px+0.125;
  py = py+0.125;
  if(k == 0 || k == 4 || k == 8){
    glPushMatrix();
      glShadeModel(GL_SMOOTH);
      glColor3f(0.9,0,0);
      glTranslatef(-px,-py,0);
      glutSolidCone(0.12,0.4,10,1);
      glTranslatef(0,0,0.4);
      glColor3f(0.8,0,0);
      glShadeModel(GL_FLAT);
      glutSolidSphere(0.10,10,10);
      glTranslatef(0,0,-0.4);
      glTranslatef(px,py,0);
    glPopMatrix();    
  }else if(k == 2 || k == 6){
    glPushMatrix();
      glShadeModel(GL_SMOOTH);
      glColor3f(0, 0.9,0);
      glTranslatef(-px,-py,0);
      glutSolidCone(0.12,0.4,10,1);
      glTranslatef(0,0,0.4);
      glColor3f(0,0.8,0);
      glShadeModel(GL_FLAT);
      glutSolidSphere(0.10,10,10);
      glTranslatef(0,0,-0.4);
      glTranslatef(px,py,0);
    glPopMatrix();    
  }  
}

/* funkcija koja iscrtava kupu */
void Cone_rand(float px, float py){
  px = px+0.12;
  py= py+0.12;
  glTranslatef(px, py, 0);	
    glRotatef(90,1,0,0);
    glPushMatrix();
    glColor3f(0,0,1);
    glutSolidCone(0.12,0.4,10,1);
    glPopMatrix();
    glRotatef(-90,1,0,0);
  glTranslatef(-px, -py, 0);
}

/*iscrtavanje kocke koja se random pojavljuje*/
void Cube_rand(float px, float py){
  px = px+0.125;
  glTranslatef(px,py,0);  
    glPushMatrix();
      glColor3f(0.25,0.25,0);
     /* glRotatef(45,1,1,1);
     */ glutSolidCube(0.2);
     /* glRotatef(-45,1,1,1);
    */glPopMatrix();
  glTranslatef(-px,-py,0);
}

/*iscrtavanje strelice*/
void Arrow_rand(float px, float py){
  glTranslatef(px,py,0);
    if(mod7 == 1){
      glPushMatrix();
	glPushMatrix();
	  glBegin(GL_POLYGON);
	    glColor3f(0.25,0.2,0.3);
	    glVertex3f(0.145, 0,0);
	    glVertex3f(0.145,0.150,0);
	    glVertex3f(0.105,0.150,0);
	    glVertex3f(0.105,0,0);
	  glEnd();
	glPopMatrix();
      
	glPushMatrix();
	  glBegin(GL_TRIANGLES);
	    glColor3f(0.25,0.2,0.3);
	    glVertex3f(0.125,0.25,0);
	    glVertex3f(0.2,0.150,0);
	    glVertex3f(0.05,0.150,0);
	  glEnd();
	glPopMatrix();
      
      glPopMatrix();
    }
    else if(mod4 == 1){
      glPushMatrix();
	glPushMatrix();
	  glBegin(GL_POLYGON);
	    glColor3f(0.25,0.2,0.3);
	    glVertex3f(0,0.145,0);
	    glVertex3f(0.150,0.145,0);
	    glVertex3f(0.150,0.105,0);
	    glVertex3f(0,0.105,0);
	  glEnd();
	glPopMatrix();
      
	glPushMatrix();
	  glBegin(GL_TRIANGLES);
	    glColor3f(0.2,0.25,0.3);
	    glVertex3f(0.25,0.125,0);
	    glVertex3f(0.150,0.2,0);
	    glVertex3f(0.150,0.05,0);
	  glEnd();
	glPopMatrix();    
      glPopMatrix();
    }
  glTranslatef(-px,-py,0);
}

/*iscrtavanje X koje ce blokirati obrisati uzete poene igracima*/
void X_rand(float px, float py){
  glTranslatef(px,py,0);   
    glPushMatrix();
    glLineWidth(5);
    glBegin(GL_LINES);

      glColor3f(0,0,0);
      glVertex3f(0.25, 0.25,0);
      glVertex3f(0,0,0);
      glVertex3f(0.25,0,0);
      glVertex3f(0,0.25,0);
    glEnd();
    glPopMatrix();  
    glLineWidth(1);

  glTranslatef(-px,-py,0);
}


/*crta se crveni kvadrat ispod igraca 1*/
void RedCube(float Gx1, float Gy1){
  red_num = 0;
  int pom = 0;
  i=0;
  while(niz_r[i+1]!='\0'){
    if(niz_r[i] == Gx1 && niz_r[i+1] == Gy1){
      pom=1;
    }
    i=i+2;
  }
  
  if(pom==0){
   niz_r[i] = Gx1;
   niz_r[i+1] = Gy1;
   j=0;
    while(niz_g[j+1]!= '\0'){
	if(niz_g[j] == Gx1 && niz_g[j+1] == Gy1){
	  niz_g[j] = niz_g[j+2];
	  niz_g[j+1] = niz_g[j+3];
	  j=j+2;
	  while(niz_g[j+3]!='\0'){
	    niz_g[j] = niz_g[j+2];
	    niz_g[j+1] = niz_g[j+3];
	    j=j+2;
	  }
	  niz_g[j] = '\0';
	  niz_g[j+1] = '\0';	
	} 

      j=j+2;
    }
  }
  
  for(j=0; niz_r[j+1]!='\0'; j=j+2){
    glPopMatrix();
      glBegin(GL_POLYGON);
	glColor3f(0.75,0,0);
	glVertex3f(niz_r[j]+0.123,niz_r[j+1]+0.123,0);
	glVertex3f(niz_r[j]-0.123,niz_r[j+1]+0.123,0);
	glVertex3f(niz_r[j]-0.123,niz_r[j+1]-0.123,0);
	glVertex3f(niz_r[j]+0.123,niz_r[j+1]-0.123,0);
      glEnd();
    glPopMatrix();  
    red_num++;
  }
}

/*igrac broj 1 -crvena sfera, napravljen u koorinatnom 
 *pocetku i zatim transliran na pocetnu poziciju*/
void Gamer1(){


    GLfloat light_position1[] = { -0.3, -0.3, 0, 0 };
    GLfloat light_ambient1[] = { 0.6, 0.0, 0.0, 1 };
    GLfloat light_diffuse1[] = { 0.2, 0.8, 0.15, 1 };
    GLfloat light_specular1[] = { 0.9, 0.2, 0.6, 1 };

    GLfloat model_ambient1[] = { 0.8, 0.3, 0.4, 0.2 };
    GLfloat model_diffuse1[] = { 0.5, 0.5, 0.6, 0.4 };
    GLfloat model_specular1[] = { 0.75, 0, 0.9, 1 };
    //GLfloat model_shininess1 = 20;

    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient1);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse1);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular1);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position1);
      
    glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient1);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,model_diffuse1);
    glMaterialfv(GL_FRONT,GL_SPECULAR,model_specular1);
    //glMaterialf(GL_FRONT,GL_SHININESS,model_shininess1);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  float rot1 = rot * 360 / 24;
  
  glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glColor3f(1,0,0);
    glTranslatef(-Gx1,-Gy1,0);
    glutSolidCone(0.12,0.4,10,1);
    glTranslatef(0,0,0.4);
    glRotatef(rot1, 0, 1, 0);
    glColor3f(0.8,0,0);
    glShadeModel(GL_SMOOTH);
    glutSolidSphere(0.10,10,10);
    glTranslatef(0,0,-0.4);
    glTranslatef(Gx1,Gy1,0);
  glPopMatrix();
  
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHTING);
}

/*crta se zeleni kvadrat ispod igraca 2*/
void GreenCube(float Gx2, float Gy2){
  green_num = 0;
  int pom = 0;
  i=0;
  while(niz_g[i+1]!='\0'){
    if(niz_g[i] == -Gx2 && niz_g[i+1] == -Gy2){
      pom=1;
    }
    i=i+2;
  }
  if(pom==0){
   niz_g[i] = -Gx2;
   niz_g[i+1] = -Gy2;
   j=0;
    while(niz_r[j+1]!= '\0'){
	if(niz_r[j] == -Gx2 && niz_r[j+1] == -Gy2){
	  niz_r[j] = niz_r[j+2];
	  niz_r[j+1] = niz_r[j+3];
	  j=j+2;
	  while(niz_r[j+3]!='\0'){
	    niz_r[j] = niz_r[j+2];
	    niz_r[j+1] = niz_r[j+3];
	    j=j+2;
	  }
	  niz_r[j] = '\0';
	  niz_r[j+1] = '\0';	
	} 

      j=j+2;
    }
  }
  
  for(j=0; niz_g[j+1]!='\0'; j=j+2){
    glPopMatrix();
      glBegin(GL_POLYGON);
	glColor3f(0,0.75,0);
	glVertex3f(niz_g[j]+0.123,niz_g[j+1]+0.123,0);
	glVertex3f(niz_g[j]-0.123,niz_g[j+1]+0.123,0);
	glVertex3f(niz_g[j]-0.123,niz_g[j+1]-0.123,0);
	glVertex3f(niz_g[j]+0.123,niz_g[j+1]-0.123,0);
      glEnd();
    glPopMatrix();
    green_num++;
  }
}

/*igrac broj 2 -zelena sfera, napravljen u koorinatnom 
 *pocetku i zatim transliran na pocetnu poziciju*/
void Gamer2(){
  
  GLfloat light_ambient[] = {0.6,0.5,0.1,0,0};
  GLfloat light_diffuse[] = {0.4,0.2,0.8,0};
  GLfloat light_specular[] = {0.8,1,0,0.5};
  GLfloat light_position[] = {-0.3,-0.3,0,0};

  GLfloat model_ambient[] = {0.2,0.9, 0.4, 0.2};
  GLfloat model_diffuse[] = {0.1,0.2,0.8,0.4};
  GLfloat model_specular[] = {0.75,0.6,0,1};
  //GLfloat model_shininess = 20;

   glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
   glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
   glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
   glLightfv(GL_LIGHT0,GL_POSITION,light_position);
      
   glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
   glMaterialfv(GL_FRONT,GL_DIFFUSE,model_diffuse);
   glMaterialfv(GL_FRONT,GL_SPECULAR,model_specular);
  // glMaterialf(GL_FRONT,GL_SHININESS,model_shininess);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  
  float rot2 = rot * 360 /24;

  glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glColor3f(0,1,0);
    glTranslatef(-Gx2,-Gy2,0);
    glutSolidCone(0.12,0.4,10,1);
    glTranslatef(0,0,0.4);
    glColor3f(0,0.8,0);
    glRotatef(rot2, 1, 0, 0);
    glShadeModel(GL_SMOOTH);
    glutSolidSphere(0.10,10,10);
    glTranslatef(0,0,-0.4);
    glTranslatef(Gx2,Gy2,0);
  glPopMatrix();  
  
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHTING);
  
}