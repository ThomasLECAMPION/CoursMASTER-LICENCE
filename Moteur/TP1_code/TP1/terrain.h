#ifndef TERRAIN_H
#define TERRAIN_H

class terrain : public objet{
    public:
        terrain(int taille, const char* tex_path, glm::vec3 trans) {
          tex.loadTexture(tex_path);
          translation = trans;

          int w, h, nbC;
          unsigned char *dataHeight = stbi_load("textures/heightmap-1024x1024.png", &w, &h, &nbC, 0);

          //génération du maillage d'un terrain plat
          for(float i=-1.f; i<1.f; i+=2.f/(float)taille) {
            for(float j=-1.f; j<1.f; j+=2.f/(float)taille) {
              int i2 = ((i+1.f)/2.f)*h;
              int j2 = ((j+1.f)/2.f)*w;
              float z = ((float)dataHeight[(i2*h) + j2]-128.f)/128.f;

              indexed_vertices.push_back(glm::vec3(i, j, z));
              tex_coords.push_back(glm::vec2(j,i));
            }
          }
          for(int i=0; i<taille-1; i++) {
            for(int j=0; j<taille-1; j++) {
              int v1 = j + i*taille;
              int v3 = j + (i+1)*taille;
              //triangle 1
              indices.push_back(v1);
              indices.push_back(v3);
              indices.push_back(v1+1);
              //triangle 2
              indices.push_back(v1+1);
              indices.push_back(v3);
              indices.push_back(v3+1);
            }
          }

          // Load it into a VBO
          glGenBuffers(1, &vertexbuffer);
          glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
          glBufferData(GL_ARRAY_BUFFER, indexed_vertices.size() * sizeof(glm::vec3), &indexed_vertices[0], GL_STATIC_DRAW);

          // Generate a buffer for the indices as well
          glGenBuffers(1, &elementbuffer);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
          glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0] , GL_STATIC_DRAW);

          // texture uv
          glGenBuffers(1, &texbuffer);
          glBindBuffer(GL_ARRAY_BUFFER, texbuffer);
          glBufferData(GL_ARRAY_BUFFER, tex_coords.size() * sizeof(glm::vec2), &tex_coords[0], GL_STATIC_DRAW);
        }
};

#endif
