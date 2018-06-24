//
//  PointMass.h
//  SmashingPhysicsEngine
//
//

#ifndef PointMass_h
#define PointMass_h

#include "../Core/Vector3.h"

namespace smashing {

	class PointMass{
	public:
		Vector3 position;
		Vector3 velocity;
		Vector3 acceleration;
		Vector3 forceAccum; // what the accu force to be applied on next intergation step is
		
		real damping;
		real inverseMass; // We will be using the inverse mass as this is easier for intergation and it better to have infinite mass objects
		
		void integrate(real duration);
	};
}

#endif /* PointMass_h */
