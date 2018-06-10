//
//  Vector3.h
//  SmashingPhysicsEngine
//
//

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
	void Vector::invert(){
		x = -x;
		y = -y;
		z = -z;
	}
}
	

#endif /* Vector_h */
