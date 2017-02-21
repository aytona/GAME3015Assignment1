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
#include "Car.h"

float rotation_angle = 0.0;
float x, y = 0;
float renderDelay = 0.0;
int renderIterator = 0;
Camera* cam;

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	glColor3f(1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    Cube testCube = Cube(glm::rotate(glm::mat4(1.0), rotation_angle, glm::vec3(1, 0.7, 0.3)), 0.5);
    if (renderIterator == 0) {
        testCube.setColor(0.0, 1.0, 0.0, 1.0);
        testCube.render();
    }

    Sphere testSphere = Sphere(glm::rotate(glm::mat4(1.0), rotation_angle, glm::vec3(1, 0.7, 0.3)), 1, 25, 25);
    if (renderIterator == 1) {
        testSphere.setColor(0.0, 1.0, 0.0, 1.0);
        testSphere.render();
    }

    Cylinder testCylinder = Cylinder(glm::rotate(glm::mat4(1.0), rotation_angle, glm::vec3(1, 0.7, 0.3)), 0.5);
    if (renderIterator == 2) {
        testCylinder.setColor(0.0, 1.0, 0.0, 1.0);
        testCylinder.render();
    }

    Cone testCone = Cone(glm::rotate(glm::mat4(1.0), rotation_angle, glm::vec3(1, 0.7, 0.3)), 0.5);
    if (renderIterator == 3) {
        testCone.setColor(0.0, 1.0, 0.0, 1.0);
        testCone.render();
    }

    Car testCar = Car(glm::rotate(glm::mat4(1.0), rotation_angle, glm::vec3(1, 0.7, 0.3)), 0.3);
    if (renderIterator == 4) {
        testCar.render();
    }

    if (renderIterator == 5) {
        glm::mat4 car1Transform = glm::mat4(1.0);
        car1Transform = glm::translate(car1Transform, glm::vec3(x, y, 0));
        car1Transform = glm::rotate(car1Transform, rotation_angle, glm::vec3(1, 0.7, 0.3));
        Car car1 = Car(car1Transform, 0.1);
        car1.render();
        glm::mat4 car2Transform = glm::mat4(1.0);
        car2Transform = glm::translate(car2Transform, glm::vec3(-x, y, 0));
        car2Transform = glm::rotate(car2Transform, rotation_angle, glm::vec3(0.7, 1, 0.3));
        Car car2 = Car(car2Transform, 0.2);
        car2.render();
        glm::mat4 car3Transform = glm::mat4(1.0);
        car3Transform = glm::translate(car3Transform, glm::vec3(x, -y, 0));
        car3Transform = glm::rotate(car3Transform, rotation_angle, glm::vec3(0.3, 0.7, 1));
        Car car3 = Car(car3Transform, 0.3);
        car3.render();
    }

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
    renderDelay += 0.0001;
    if (renderDelay > 2) {
        if (renderIterator < 5) {
            renderIterator++;
            x = 0;
            y = 0;
        }
        else {
            renderIterator = 0;
        }
        renderDelay = 0;
    }
    if (renderIterator >= 5) {
        x += 0.00003;
        y -= 0.00003;
    }
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