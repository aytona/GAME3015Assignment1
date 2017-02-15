#include "Camera.h"

const double Camera::TO_RADS = 3.14159 / 180.0;


Camera::Camera(float theWindowWidth, float theWindowHeight)
{
	initCamera();

	windowWidth = theWindowHeight;
	windowHeight = theWindowHeight;

	windowMidX = theWindowWidth / 2.0f;
	windowMidY = theWindowHeight / 2.0f;

	glutWarpPointer(windowMidX, windowMidY);
}

Camera::~Camera()
{
	//To be implemented
	//We need to free the possibly allocated memory
}

void Camera::handleMouseMove(int mouseX, int mouseY)
{
	double horizentalMovement = (mouseX - windowMidX + 1) * yawSensitivity;
	double verticalMovement = (mouseY - windowMidY + 1) * pitchSensitivity;

	std::cout << "Mid window values: " << windowMidX << "\t" << windowMidY << std::endl;
	std::cout << "Mouse values: " << mouseX << "\t" << mouseY << std::endl;
	std::cout << horizentalMovement << "\t" << verticalMovement << std::endl;

	//We have used rotation.x for up/down look and rotation.y for left/right look
	rotation.x += verticalMovement;
	rotation.y += horizentalMovement;

	//Take care of limits for up/down
	if (rotation.x < -90)
	{
		rotation.x = -90;
	}
	if (rotation.x > 90)
	{
		rotation.x = 90;
	}

	//take care of limits for left/right
	/*
	if (rotation.y < -90)
	{
		rotation.x = -90;
	}
	if (rotation.x > 90)
	{
		rotation.x = 90;
	}
	*/

	glutWarpPointer(windowMidX, windowMidY);
	

}


void Camera::initCamera()
{
	position = glm::vec3(0.0, 0.0, 0.0);
	rotation = glm::vec3(0.0, 0.0, 0.0);
	speed = glm::vec3(0.0, 0.0, 0.0);
	movementSpeedFactor = 100;
	pitchSensitivity = 0.2;
	yawSensitivity = 0.2;

	holdingForward = false;
	holdingBackward = false;
	holdingLeftStrafe = false;
	holdingRightStrafe = false;
}

//Function Implementations
const double Camera::toRads(const double & angleInDegrees) const
{
	return angleInDegrees * TO_RADS;
}

void Camera::move(double deltaTime)
{
	glm::vec3 movement;

	//We need to get the Sin and Cos of X and Y axes of rotation

	double sinXRot = sin(toRads(rotation.x));
	double cosXRot = cos(toRads(rotation.x));

	double sinYRot = sin(toRads(rotation.y));
	double cosYRot = cos(toRads(rotation.y));


	double pitchLimitFactor = cosXRot; //To prevent moving on the Z axis when looking up and down

	if (holdingForward)
	{
		movement.x += sinYRot * pitchLimitFactor;
		movement.y += -sinXRot;
		movement.z += -cosYRot * pitchLimitFactor;
	}
	if (holdingBackward)
	{
		movement.x += -sinYRot * pitchLimitFactor;
		movement.y += sinXRot;
		movement.z += cosYRot * pitchLimitFactor;
	}
	if (holdingLeftStrafe)
	{
		movement.x += -cosYRot;
		movement.z += -sinYRot;
	}
	if (holdingRightStrafe)
	{
		movement.x += cosYRot;
		movement.z += sinYRot;
	}

	movement = glm::normalize(movement);

	double framerateIndependentFactor = movementSpeedFactor * deltaTime;

	movement *= framerateIndependentFactor;

	position += movement;

}


