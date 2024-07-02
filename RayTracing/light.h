#ifndef LIGHT_H
#define LIGHT_H

#include "vec3.h"

class light {
    public:
        light() {}
        light(const point3& origin, const double& brightness)
            : orig(origin), bright(brightness)
        {}

        point3 origin() const  { return orig; }
        double brightness() const { return bright; }

    public:
        point3 orig;
        double bright;
};

#endif
