// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	// YOUR CODE FOR HW1 HERE
    float rad = glm::radians(degrees);
    float cosine = cos(rad);
    float sine = sin(rad);
    mat3 Id = mat3(1.0f);
    vec3 a = glm::normalize(axis);
    float x = a.x, y = a.y, z = a.z;
    
    mat3 aat = mat3(x*x, x*y, x*z,
               x*y, y*y, y*z,
               x*z, y*z, z*z);
    
    mat3 Astar = mat3(0, -z, y,
                      z, 0, -x,
                      -y, x, 0);
    
    mat3 rotationMatrix = cosine*Id + (1-cosine)*aat + sine*Astar;

	// You will change this return call
	return rotationMatrix;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE
    mat3 rotMat = Transform::rotate(degrees, -up);
    eye = rotMat * eye;
    
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE
    vec3 axis = glm::cross(eye,up);
    mat3 rotMat = Transform::rotate(degrees, axis);
    eye = rotMat * eye;
    up = rotMat * up;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	// YOUR CODE FOR HW1 HERE
    vec3 u = glm::normalize(glm::cross(up, eye));
    vec3 v = glm::normalize(up);
    vec3 w = glm::normalize(eye);
    
    mat4 viewMat(u.x, u.y, u.z, glm::dot(u,-eye),
                v.x, v.y, v.z, glm::dot(v,-eye),
                w.x, w.y, w.z, glm::dot(w,-eye),
                0, 0, 0, 1);

	// You will change this return call
	return glm::transpose(viewMat);
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
