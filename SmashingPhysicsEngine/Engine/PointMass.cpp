//
//  PointMass.cpp
//  SmashingPhysicsEngine
//

#include "PointMass.h"
#include <assert.h>

using namespace smashing;

void PointMass::integrate(real duration)
{
	assert(duration > 0.0); //duration has to be greater than 0
	
	//update position (p + dp/dt*t + (1/2)d^2p/d^2t*t^2) we will ingore accerleation for now as it is small
	position.addScaledVector(velocity, duration);
	// if short burst of acceleration happen add in the equation below
	//position.addScaledVector(acceleration, (duration*duration*0.5));
	
	//work out he acceleration from the force accum (f=ma aka a = 1/mf)
	Vector3 resultingAcc = acceleration;
	resultingAcc.addScaledVector(forceAccum, inverseMass);
	
	//update vecloity from acceleration (v = v + d^2p/d^2t *t)
	velocity.addScaledVector(resultingAcc, duration);
	
	//add drag due to numercial instability reasons
	velocity *= real_pow(damping,duration);
}
