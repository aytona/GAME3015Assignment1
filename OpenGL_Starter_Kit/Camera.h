#ifndef CAMERA_H
#define CAMERA_H

#pragma once
#include "glm\glm.hpp"
#include <iostream>
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include "math.h"
#include "GL\glut.h"



class  Camera
{
	protected:
		//Camera Position
		glm::vec3 position;

		//Camera Rotation
		glm::vec3 rotation;

		//Camera motion speed
		glm::vec3 speed;

		double movementSpeedFactor;	//How fast the camera moves
		double pitchSensitivity; //Controls how sensitive mouse movements affect looking up and down
		double yawSensitivity; //Controls how sensitive mouse movements affect looking left and right

		//Window size in pixels and where the midpoint falls
		int windowWidth;
		int windowHeight;
		int windowMidX;
		int windowMidY;

		// Set up initial values for the camera
		void initCamera();


	public:
		static const double TO_RADS;	// The value of 1 degree in radians

		//Take care of WASD keys
		bool holdingForward;
		bool holdingBackward;
		bool holdingLeftStrafe;
		bool holdingRightStrafe;

		//Constructor
		Camera(float windowWidth, float windowHeight);

		//Destructor
		~Camera();

		//Mouse movement handler to look around
		void handleMouseMove(int mouseX, int mouseY);

		//Convert angle to radian
		const double toRads(const double &angleInDegrees) const;

		//Method to move camera based on current direction
		void move(double deltaTime);

		//Setters and getters
		float getPitchSensitivity() { return pitchSensitivity; }
		float setPitchSensitivity(float val) { pitchSensitivity = val; }
		float getYawSensitivity() { return yawSensitivity; }
		float setYawSensitivity(float val) { yawSensitivity = val; }

		//Position getters
		glm::vec3 getPosition() const { return position; }
		double getXPos() const { return position.x; }
		double getYPos() const { return position.y; }
		double getZPos() const { return position.z; }

		//Rotation getters
		glm::vec3 getRotation() const { return rotation; }
		double getXRot() const { return rotation.x; }
		double getYRot() const { return rotation.y; }
		double getZRot() const { return rotation.z; }

};

#endif //CAMERA_H