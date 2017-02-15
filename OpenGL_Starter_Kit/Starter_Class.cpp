#include <math.h>
#include "Square.h"
#include "Triangle.h"
#include "Tank.h"
#include "GL\glut.h"
#include "Camera.h"




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
	
	
	Tank redTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0)), 0.1);
	redTank.setColor(1.0, 0.0, 0.0);
	redTank.render();

	Tank blueTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(-x, y, 0)), 0.1);
	blueTank.setColor(0.0, 0.0, 1.0);
	blueTank.render();

	Tank greenTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, -y, 0)), 0.1);
	greenTank.setColor(0.0, 1.0, 0.0);
	greenTank.render();

	Tank whiteTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(-x, -y, 0)), 0.1);
	whiteTank.setColor(1.0, 1.0, 1.0);
	whiteTank.render();


	Tank bigTank = Tank(glm::translate(glm::mat4(1.0f), glm::vec3(x, 0, 0)), 0.2);
	bigTank.setColor(1.0, 0.0, 1.0);
	bigTank.render();



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
	//rotation_angle += 0.01;
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