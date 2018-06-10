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
		// Attributes
		real x;
		real y;
		real z;
		
		// Methods
		Vector3();
		Vector3(real x, real y, real z);
		Vector3(const Vector3& vector) //copy ctor
		Vector3& operator= (const Vector3& vector) //copy assignment
		~Vector3(); //dtor
		
		void invert();
		real magnitude() const;
		real squaredMagnitude() const;
		void normalize();
		
		void operator*=(const real value);
		Vector3 operator*(const real value) const;
		void operator/=(const real value);
		Vector3 operator/(const real value) const;
		void operator+=(const Vector3& vector);
		Vector3 operator+(const Vector3& vector) const;
		void operator-=(const Vector3& vector);
		Vector3 operator-(const Vector3& vector) const;
		
	};
	
	// Ctors and Dtor
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
	
	// Functions
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
	
	// Operators
	// *
	// Multiplies this vector by the given scalar.
	void Vector3::operator*=(const real value){
		x *= value;
		y *= value;
		z *= value;
	}
	// Returns a copy of this vector scaled the given value.
	Vector3 Vector3::operator*(const real value) const{
		return Vector3(x*value, y*value, z*value);
	}
	
	// /
	// Divides this vector by the given scalar.
	void Vector3::operator/=(const real value){
		x /= value;
		y /= value;
		z /= value;
	}
	// Returns a copy of this vector divided (1/value) the given value.
	Vector3 Vector3::operator/(const real value) const{
		return Vector3(x/value, y/value, z/value);
	}
	
	// +
	// Adds the given vector to this.
	void Vector3::operator+=(const Vector3& vector){
		x += vector.x;
		y += vector.y;
		z += vector.z;
	}
	// Returns the value of the given vector added to this.
	Vector3 Vector3::operator+(const Vector3& vector) const{
		return Vector3(x+vector.x, y+vector.y, z+vector.z)
	}
	
	// -
	// Subtracts the given vector from this.
	void Vector3::operator-=(const Vector3& vector){
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
	}
	// Returns the value of the given vector subtracted from this.
	Vector3 Vector3::operator-(const Vector3& vector) const{
		return Vector3(x-vector.x, y-vector.y, z-vector.z)
	}
}

#endif /* Vector_h */
