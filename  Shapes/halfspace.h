//
// Created by Derek on 1/26/2020.
//

#ifndef RAYTRACER_HALFSPACE_H
#define RAYTRACER_HALFSPACE_H

#include "../target.h"
#include "../constants.h"

template<class T>
class Halfspace: public Target<T> {
    Intersection<T> firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const override;
    Vector3<T> getNormal(const Vector3<T> &point) const override;
};


template<class T>
Intersection<T> Halfspace<T>::firstIntersectionBetween(const Ray<T> &ray, const T &tMin, const T &tMax) const {
    Ray<T>& targetRay = ray.transform(this->sceneToTargetTransform());
    auto eqnAt0 = targetRay.origin.z;
    auto dDotN = - (this->getNormal().Dot(targetRay.direction));
    /*
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
     */
    return Intersection<T>();
}

template<class T>
Vector3<T> Halfspace<T>::getNormal(const Vector3<T> &point) const {
    // Should return the 3rd column target-to-scene transform (normalized)
    Vector3<T> vec = Vector3<T>(this->targetToSceneTransform());
    return vec.Orthonormal()
}

#endif //RAYTRACER_HALFSPACE_H
