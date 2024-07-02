#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <stdio.h>
#include <stdlib.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

class transform {
    public:
        transform() {}
        transform(const glm::vec4& matrix) : m(matrix){}

        void applyTo(glm::vec3 v);

    public:
        glm::vec3 m;

};

#endif
