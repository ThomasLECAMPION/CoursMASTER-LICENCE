#ifndef TEXTURE_H
#define TEXTURE_H

class texture {
    public:
        unsigned int index;

        texture(const char* path) {
          glGenTextures(1, &index);
          glBindTexture(GL_TEXTURE_2D, index); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
          // set the texture wrapping parameters
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
          // set texture filtering parameters
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
          // load image, create texture and generate mipmaps
          int width, height, nrChannels;
          unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
          if (data)
          {
              glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
              glGenerateMipmap(GL_TEXTURE_2D);
          }
          else
          {
              std::cout << "Failed to load texture" << std::endl;
          }
          stbi_image_free(data);
        }
};

#endif
