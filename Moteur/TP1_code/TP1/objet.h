#ifndef OBJET_H
#define OBJET_H

#include "texture.h"

class objet {
    public:
        std::vector<unsigned short> indices;
        std::vector<glm::vec3> indexed_vertices;
        std::vector<glm::vec2> tex_coords;

        std::vector<objet> enfants;
        glm::vec3 translation;
        GLuint vertexbuffer, elementbuffer, texbuffer;
        texture tex;
};

#endif
