#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.h"
#include "vec3.h"

class triangle : public hittable {
    public:
        triangle() {}
        triangle(point3 a, point3 b, point3 c, shared_ptr<material> m) : a(a), b(b), c(c), mat_ptr(m) {};

        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;

    public:
        point3 a;
        point3 b;
        point3 c;
        shared_ptr<material> mat_ptr;
};

bool triangle::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    //Algorithme Möller–Trumbore
    const float EPSILON = 0.0000001;
    vec3 edge1 = b-a;
    vec3 edge2 = c-a;

    vec3 h = cross(r.direction(), edge2);
    double det = dot(edge1,h);
    if(det > -EPSILON && det < EPSILON)
        return false;

    vec3 s = r.origin() - a;
    double baryU = dot(s, h) / det;
    if (baryU < 0.0 || baryU > 1.0)
        return false;

    vec3 q = cross(s, edge1);
    double baryV = dot(r.direction(), q) / det;
    if (baryV < 0.0 || baryU + baryV > 1.0)
        return false;

    rec.t = dot(edge2, q) / det;
    if (rec.t < t_min || t_max < rec.t)
        return false;

    if (rec.t > EPSILON)
    {
        rec.p = r.at(rec.t);
        rec.set_face_normal(r, unit_vector(cross(edge1, edge2)));
        rec.mat_ptr = mat_ptr;
        return true;
    }
    else
        return false;
}

#endif
