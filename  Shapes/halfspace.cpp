//
// Created by Derek on 1/25/2020.
//

#include "../constants.h"
#include "halfspace.h"
template<class T>
Intersection<T>& Halfspace<T>::firstIntersectionBetween(Ray<T> &ray, T &tMin, T &tMax) {
    Ray& targetRay = ray.transform(this->sceneToTargetTransform());
    auto eqnAt0 = targetRay.origin.z;
    auto dDotN = - (this->getNormal().Dot(targetRay.direction));
    if abs(dDotN) < EPSILON { // ray is nearly perpendicular to the plane
        if abs(eqnAt0) >= EPSILON {
            return &Intersection<T>(tMin, tMax, 0);
        }
    } else {
        targetRay.distance = eqnAt0 / dDotN;
    }
    targetRay.origin = targetRay.position(targetT);
    auto p = targetP.transform(halspace.targetToSceneTransform);
    auto t = (p - ray.origin).Magnitude();
    if (t < tMin || t > tMax) {
        return &Intersection<T>(tMin, tMax, None); // intersection is too far away
    }

    tMax = t; // closer than previous tMax
    return &Intersection<T>(tMinx, tMax, Intersection(halfspace, p));
}

template<class T>
Vector3<T>& Halfspace<T>::getNormal(Point3<T> &point) {
    // Should return the 3rd column target-to-scene transform (normalized)
    Vector3 vec = Vector3<T>&(this->targetToSceneTransform());
    return vec.Orthonormal()
}