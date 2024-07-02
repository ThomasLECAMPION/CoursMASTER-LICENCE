#ifndef SQUARE_H
#define SQUARE_H
#include "Vec3.h"
#include <vector>
#include "Mesh.h"
#include <cmath>

struct RaySquareIntersection{
  bool intersectionExists;
  float t;
  float u,v;
  Vec3 intersection;
  Vec3 normal;
};


class Square : public Mesh {
public:
    Vec3 m_center;
    float m_radius;

    Square() : Mesh() {}
    Square(Vec3 c , float r) : Mesh() , m_center(c) , m_radius(r) {}

    void setQuad( Vec3 const & bottomLeft , Vec3 rightVector , Vec3 upVector , float width=1. , float height=1. ,
                  float uMin = 0.f , float uMax = 1.f , float vMin = 0.f , float vMax = 1.f) {
        Vec3 normal = Vec3::cross(rightVector , upVector);
        normal.normalize();
        rightVector.normalize();
        rightVector.normalize();
        vertices.clear();
        vertices.resize(4);
        vertices[0].position = bottomLeft;                                           vertices[0].u = uMin; vertices[0].v = vMin;
        vertices[1].position = bottomLeft + width * rightVector;                     vertices[1].u = uMax; vertices[1].v = vMin;
        vertices[2].position = bottomLeft + width * rightVector + height * upVector; vertices[2].u = uMax; vertices[2].v = vMax;
        vertices[3].position = bottomLeft + height * upVector;                       vertices[3].u = uMin; vertices[3].v = vMax;
        vertices[0].normal = vertices[1].normal = vertices[2].normal = vertices[3].normal = normal;
        triangles.clear();
        triangles.resize(2);
        triangles[0][0] = 0;
        triangles[0][1] = 1;
        triangles[0][2] = 2;
        triangles[1][0] = 0;
        triangles[1][1] = 2;
        triangles[1][2] = 3;
    }

    RaySquareIntersection intersect(const Ray &ray) const {
        RaySquareIntersection intersection;

        //TODO calculer l'intersection rayon triangle

        return intersection;
    }
};
#endif // SQUARE_H
