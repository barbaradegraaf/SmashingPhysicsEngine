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
		void addScaledVector(const Vector3 &vector, real scale);
		Vector3 componentProduct(const Vector3 &vector) const;
		void componentProductSelf(const Vector3 &vector);
		real dotProduct(const Vector3 &vector) const;
		Vector3 crossProduct(const Vector3 &vector) const;
		
		void operator*=(const real value);
		Vector3 operator*(const real value) const;
		real operator*(const Vector3 &vector) const;
		void operator%=(const Vector3 &vector)
		Vector3 operator%(const Vector3 &vector) const;
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
	// This adds a given vector to this vector scaled by a certian amount, convient to have instead of doing two seperate function
	void Vector3::addScaledVector(const Vector3 &vector, real scale){
		x += vector.x * scale;
		y += vector.y * scale;
		z += vector.z * scale;
	}
	// Does a 'component' product which is not a algebraic function but instead a function of times each component of each vector to get a final vector
	// This one will use a given vector with the this vector and return the result
	Vector3 Vector3::componentProduct(const Vector3 &vector) const{
		return Vector3(x * vector.x, y * vector.y, z * vector.z);
	}
	// This is do the same 'component' product but will do it to the current this vector
	void Vector3::componentProductSelf(const Vector3 &vector){
		x *= vector.x;
		y *= vector.y;
		z *= vector.z;
	}
	// This does the dot product with the this value and returns the scalar value
	real Vector3::dotProduct(const Vector3 &vector){
		return x*vector.x + y*vector.y + z*vector.z;
	}
	// This does the cross product between this and the passed in vector returning a vector
	Vector3 Vector3::crossProduct(const Vector3 &vector){
		return Vector3(y*vector.z - z*vector.y,
					   z*vector.x - x*vector.z,
					   x*vector.y - y*vector.x);
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
	// Does the dot product of 'this' vector with the vector passed in
	real Vector3::operator*(const Vector3 &vector) const{
		return x*vector.x + y*vector.y + z*vector.z;
	}
	// Update the current vector to be the cross product between the passed in one and current one
	void Vector3::operator%=(const Vector3 &vector){
		*this = vectorProduct(vector);
	}
	// Does the cross product between pass in and current vector
	Vector3 Vector3::operator%(const Vector3 &vector) const{
		return Vector3(y*vector.z-z*vector.y,
					   z*vector.x-x*vector.z,
					   x*vector.y-y*vector.x);
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
