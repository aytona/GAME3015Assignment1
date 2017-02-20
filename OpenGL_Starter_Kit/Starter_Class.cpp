#include <math.h>
#include "Square.h"
#include "Triangle.h"
#include "Tank.h"
#include "GL\glut.h"
#include "Camera.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"



float rotation_angle = 0.0f;
float x, y=0;
Camera* cam;

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	glColor3f(1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	/*Tank redTank = Tank(glm::translate(glm::mat4(0.0), glm::vec3(x, y, 0)), 0.1);
	redTank.setColor(1.0, 0.0, 0.0);
	redTank.render();*/

    Cube testCube = Cube(glm::rotate(glm::mat4(1.0f), rotation_angle, glm::vec3(1, 1, 0)), 0.5);
    testCube.setColor(1.0, 0.0, 0.0);
    testCube.render();
	glFlush();
}

void mouseHandler(int button, int state, int x, int y)
{
	//Call the mousehandler of the camera
	//To be implemented.
	//We stopped here on Feb, 14, 2017
	//We will continue next week
}

void myIdleFunc()
{
	rotation_angle += 0.0001;
	x += 0.0001;
	y -= 0.0001;
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First Application");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myIdleFunc);
	glutMouseFunc(mouseHandler);


	glutMainLoop();
	return 0;
}