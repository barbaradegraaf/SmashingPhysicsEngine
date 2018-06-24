//
//  PointMass.h
//  SmashingPhysicsEngine
//
//

#ifndef PointMass_h
#define PointMass_h

namespace smashing {

	class PointMass{
	public:
		Vector3 position;
		Vector3 velocity;
		Vector3 acceleration;
		
		real damping;
		// We will be using the inverse mass as this is easier for intergation and it better to have infinite mass objects
		real inverseMass;
		
		void intergate(real duration);
	}
}

#endif /* PointMass_h */
