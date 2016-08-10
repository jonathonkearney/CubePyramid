#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>      // (or others, depending on the system in use)

// utility functions

GLenum errorCheck ()
{
    GLenum code = glGetError ();
    if (code != GL_NO_ERROR)
        fprintf(stderr, "OpenGL error %d: %s\n", code, gluErrorString (code) );
    return code;
}

void createCenterWindow(const int sizeX, const int sizeY, const char* title)
{
    glutInitWindowPosition(
        (glutGet(GLUT_SCREEN_WIDTH) - sizeX) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - sizeY) / 2
    );
    glutInitWindowSize (sizeX, sizeY);
    glutCreateWindow (title);
}

// cube data type
struct cube
{
    GLfloat pos[3];
    GLfloat angle;    
};
typedef struct cube CUBE;

// initial cube data - TODO
#define MAX_CUBE 6
CUBE cubes[MAX_CUBE] = {
    {{3,0,0}, 0},
    {{0,0,3}, 20},
    {{-3,0,0}, 40},
    {{0,0,-3}, 140},
    {{2,0,2}, 350},
    {{-2,0,-2}, 250}
	
	//{{0,0,0}, 0},
    //{{1.2,0,0}, 0},
    //{{-1.2,0,0}, 0},
    //{{0.6,1.2,0}, 0},
    //{{-0.6,1.2,0}, 0},
    //{{0,2.4,0}, 0}
};

// draw a single cube
void drawCube(CUBE *cube)
{
    // set color
    GLfloat cubeColor[] = { 1, 1, 1, 1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cubeColor);
    
    // adjust for position and angle - TODO
	glPushMatrix();
	glTranslatef(cube->pos[0],cube->pos[1],cube->pos[2]);
	glRotatef(cube->angle, cube->pos[0],cube->pos[1],cube->pos[2]);
	glutSolidCube(1);
	glPopMatrix();

}

void drawFloor()
{
    // set floor color
    GLfloat floorColor[] = { 0.5, 0.5, 1, 1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, floorColor);

    // draw polygon showing floor - TODO
	glBegin(GL_POLYGON);
		glVertex3f(-8.0, -0.5, 0.0);
		glVertex3f(0.0, -0.5, 8.0);
		glVertex3f(8.0, -0.5, 0.0);
		glVertex3f(0.0, -0.5, -8.0);
	glEnd();
}

// draw all objects (cubes & plane)
void draw ()
{
    int i;
    
    // clear the screen
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    // draw all cubes
    for (i = 0; i < MAX_CUBE; i++)
        drawCube( &cubes[i] );
    // draw floor
    drawFloor();

    // draw the scene
    glFlush ();
    // change to new buffer (double buffering)
    glutSwapBuffers();
    // debug
    errorCheck();    
}

void update ()
{
    // update the positions & angles of cubes to get animation - TODO
	
			cubes[0].angle += 0.2;
			if(cubes[0].pos[0] > 0){
				cubes[0].pos[0] -= 0.001;}
			if(cubes[0].pos[1] > 0){
				cubes[0].pos[1] -= 0.001;}
			if(cubes[0].pos[2] > 0){
				cubes[0].pos[2] -= 0.001;}
			else{cubes[0].angle = 0;}
		
			cubes[1].angle += 0.2;
			if(cubes[1].pos[0] < 1.2){
				cubes[1].pos[0] += 0.001;}
			if(cubes[1].pos[1] > 0){
				cubes[1].pos[1] -= 0.001;}
			if(cubes[1].pos[2] > 0){
				cubes[1].pos[2] -= 0.001;}
			else{cubes[1].angle = 0;}
		
			cubes[2].angle += 0.2;
			if(cubes[2].pos[0] < -1.2){
				cubes[2].pos[0] += 0.001;}
			if(cubes[2].pos[1] > 0){
				cubes[2].pos[1] -= 0.001;}
			if(cubes[2].pos[2] > 0){
				cubes[2].pos[2] -= 0.001;}
			else{cubes[2].angle = 0;}
			
			cubes[3].angle += 0.2;
			if(cubes[3].pos[0] < 0.6){
				cubes[3].pos[0] += 0.001;}
			if(cubes[3].pos[1] < 1.2){
				cubes[3].pos[1] += 0.001;}
			if(cubes[3].pos[2] < 0){
				cubes[3].pos[2] += 0.001;}
			else{cubes[3].angle = 0;}
				
			cubes[4].angle += 0.2;
			if(cubes[4].pos[0] > -0.6){
				cubes[4].pos[0] -= 0.001;}
			if(cubes[4].pos[1] < 1.2){
				cubes[4].pos[1] += 0.001;}
			if(cubes[4].pos[2] > 0){
				cubes[4].pos[2] -= 0.001;}
			else{cubes[4].angle = 0;}

			cubes[5].angle += 0.2;
			if(cubes[5].pos[0] < 0){
				cubes[5].pos[0] += 0.001;}
			if(cubes[5].pos[1] < 2.4){
				cubes[5].pos[1] += 0.001;}
			if(cubes[5].pos[2] < 0){
				cubes[5].pos[2] += 0.001;}
			else{cubes[5].angle = 0;}
				
		
		
    // redraw
    glutPostRedisplay();
}

int main (int argc, char** argv)
{
    // create window
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    createCenterWindow(800, 600, "Pyramid Building 101");
    
    // version info - only accessible after window has been created
    printf("OpenGL version: %s\n", glGetString(GL_VERSION));

    // enable culling, depth-testing and lighting
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

	
    // set the view perspective - TODO
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(100.0, 1.2, 3.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0, 4.0, 3.0,
			  0.0, 0.0, 0.0,
			  0.0, 1.0, 0.0);
	
    
    // light source
    GLfloat lightPos[] = { 1, 2, 0, 0 };
    GLfloat lightColor[] = { 1, 1, 1, 1 };    
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor);
    glEnable(GL_LIGHT1);    
      
    // setup for animation
    glutDisplayFunc(draw);    
    glutIdleFunc(update);
    glutMainLoop( );
}
