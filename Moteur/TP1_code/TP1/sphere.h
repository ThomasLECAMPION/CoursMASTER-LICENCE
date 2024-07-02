#ifndef SPHERE_H
#define SPHERE_H

class sphere : public objet{
    public:
        sphere(int nX, int nY, const char* tex_path, glm::vec3 trans) {
          tex.loadTexture(tex_path);
          translation = trans;

          float a,b;
          float x,y,z,u,v;
          for(int i=0; i<=nX; i++) {
              a = (M_PI/2) - i*(M_PI/nX);
              for(int j=0; j<=nY; j++) {
                  b = (2*M_PI/nY) * j;

                  x = cosf(b) * cosf(a);
                  y = sinf(b) * cosf(a);
                  z = sinf(a);

                  u = atan2(x, z) / (2*M_PI) + 0.5;
                  v = y * 0.5 + 0.5;

                  indexed_vertices.push_back( glm::vec3(x,y,z) );
                  tex_coords.push_back( glm::vec2(u, v) );
              }
          }

          int v1, v3;
          for(int i=0; i<nX; i++) {
              for(int j=0; j<nY; j++) {
                  v1 = i*(nY+1) + j;
                  v3 = v1 + (nY+1);
                  if(i!=0) {
                    indices.push_back( v1 );
                    indices.push_back( v3 );
                    indices.push_back( v1+1 );
                  }
                  if(i!=(nX-1)) {
                    indices.push_back( v1+1 );
                    indices.push_back( v3 );
                    indices.push_back( v3+1 );
                  }
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
