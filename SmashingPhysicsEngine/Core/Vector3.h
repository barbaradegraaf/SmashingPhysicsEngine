//
//  Vector3.h
//  SmashingPhysicsEngine
//
//
#include <math.h>

#ifndef Vector_h
#define Vector_h

#include "precision.h"

namespace smashing {
	
	class Vector3 {
	public:
		// attributes
		real x;
		real y;
		real z;
		
		//methods
		Vector3();
		Vector3(real x, real y, real z);
		Vector3(const Vector3& vector) //copy ctor
		Vector3& operator= (const Vector3& vector) //copy assignment
		~Vector3(); //dtor
		void invert();
		real magnitude() const;
		real squaredMagnitude() const;
		void normalize();
	};
	
	Vector3::Vector3() : x(0), y(0), z(0) {
		
	}
	Vector3::Vector3(real x, real y, real z) : x(x), y(y), z(z) {
		
	}
	Vector3::Vector3(const Vector3& vector) : x(vector.x), y(vector.y), z(vector.z){
		
	}
	Vector3& Vector3::operator= (const Vector3& vector){
		if (&vector == this)
		{
			return *this;
		}
		x = vector.x;
		y = vector.y;
		z = vector.z;
		return *this;
	}
	Vector3::~Vector3(){
		
	}
	void Vector3::invert(){
		x = -x;
		y = -y;
		z = -z;
	}
	real Vector3::magnitude() const{
		return real_sqrt(x*x + y*y + z*z);
	}
	real Vector3::squaredMagnitude() const{
		return (x*x + y*y + z*z);
	}
	void Vector3::normalize(){
		real len = magnitude();
		if (len > 0)
		{
			(*this) *= ((real)1)/len;
		}
	}
}
	

#endif /* Vector_h */
