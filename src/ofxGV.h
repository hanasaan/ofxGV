#pragma once

#include <opengv/types.hpp>

#include "ofBaseTypes.h"

namespace ofxGV
{
    using namespace opengv;
    using namespace Eigen;
    
    inline bearingVector_t toGV(ofVec3f v) {
        return bearingVector_t(v.x, v.y, v.z);
    }
    
    inline bearingVectors_t toGV(const vector<ofVec3f>& vs) {
        bearingVectors_t b;
        for (const auto& v : vs) { b.push_back(toGV(v)); }
        return b;
    }
    
    inline rotation_t toGV(ofQuaternion q) {
        Quaterniond eq(q.w(), q.x(), q.y(), q.z());
        return eq.matrix();
    }
    
    inline transformation_t toGV(ofMatrix4x4 m) {
        transformation_t em;
        em <<
        m._mat[0][0], m._mat[1][0], m._mat[2][0], m._mat[3][0],
        m._mat[0][1], m._mat[1][1], m._mat[2][1], m._mat[3][1],
        m._mat[0][2], m._mat[1][2], m._mat[2][2], m._mat[3][2];
        return em;
    }
    
    inline ofVec3f toOf(Vector3d p) {
        return ofVec3f(p.x(), p.y(), p.z());
    }
    
    inline ofMatrix4x4 toOf(rotation_t t) {
        return ofMatrix4x4(t(0,0), t(1,0), t(2,0), 0,
                           t(0,1), t(1,1), t(2,1), 0,
                           t(0,2), t(1,2), t(2,2), 0,
                           0, 0, 0, 1);
    }
    
    inline ofMatrix4x4 toOf(transformation_t t) {
        return  ofMatrix4x4(t(0,0), t(1,0), t(2,0), 0,
                            t(0,1), t(1,1), t(2,1), 0,
                            t(0,2), t(1,2), t(2,2), 0,
                            t(0,3), t(1,3), t(2,3), 1);
    }
}
