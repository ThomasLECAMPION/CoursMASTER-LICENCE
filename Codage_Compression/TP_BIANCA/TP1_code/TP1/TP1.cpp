#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>
#include <common/objloader.hpp>
#include <common/vboindexer.hpp>

//Quantification de draco sur chaque sommet du maillage
std::vector<glm::vec3> quantification(std::vector<glm::vec3> vertices, int qp, glm::vec3 BB_min, float range) {
  std::cout<<"quantification"<<std::endl;
  for(unsigned int i=0; i<vertices.size(); i++) {
    glm::vec3 tmp = (vertices[i]-BB_min);
    tmp[0] = round(tmp[0] * (pow(2,qp)/range));
    tmp[1] = round(tmp[1] * (pow(2,qp)/range));
    tmp[2] = round(tmp[2] * (pow(2,qp)/range));
    vertices[i] = tmp;
  }
  return vertices;
}

//De-quantification de draco sur chaque sommet du maillage
std::vector<glm::vec3> dequantification(std::vector<glm::vec3> vertices, int qp, glm::vec3 BB_min, float range) {
  std::cout<<"dequantification"<<std::endl;
  for(unsigned int i=0; i<vertices.size(); i++) {
    for(int j=0; j<3; j++) { //x, y, z
      vertices[i][j] = vertices[i][j] * (range/(pow(2,qp) * BB_min[j]));
    }
  }
  return vertices;
}

glm::vec3 rmse(std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &vertices2) {
  glm::vec3 rmse = glm::vec3(0.f, 0.f, 0.f);
  for(unsigned int i=0; i<vertices.size(); i++) {
    rmse += (vertices[i]-vertices2[i]) * (vertices[i]-vertices2[i]);
  }
  rmse[0] = sqrtf(rmse[0]/vertices.size());
  rmse[1] = sqrtf(rmse[1]/vertices.size());
  rmse[2] = sqrtf(rmse[2]/vertices.size());
  return rmse;
}

int main( void )
{
    std::vector<unsigned short> indices; //Triangles concaténés dans une liste
    std::vector<std::vector<unsigned short> > triangles;
    std::vector<glm::vec3> vertices;

    //Chargement du fichier de maillage
    std::string filename("bunny.off");
    loadOFF(filename, vertices, indices, triangles );

    //Bounding Box
    glm::vec3 BB_min = glm::vec3(999.f, 999.f, 999.f);
    glm::vec3 BB_max = glm::vec3(-999.f, -999.f, -999.f);

    for(unsigned int i=0; i<vertices.size(); i++) {
      for(int j=0; j<3; j++) { //x, y, z
        BB_min[j] = min(vertices[i][j], BB_min[j]);
        BB_max[j] = max(vertices[i][j], BB_max[j]);
      }
    }

    float range = max(max(BB_max[0], BB_max[1]), BB_max[2]);
    int qp = 5;

    std::cout<<"x="<<BB_min[0]<<" y="<<BB_min[1]<<" z="<<BB_min[2]<<std::endl;
    std::cout<<"range="<<range<<std::endl;

    std::cout<<vertices[50][0]<<std::endl;

    std::vector<glm::vec3> res1 = quantification(vertices, qp, BB_min, range);
    std::cout<<res1[50][0]<<std::endl;

    std::vector<glm::vec3> res2 = dequantification(vertices, qp, BB_min, range);
    std::cout<<res2[50][0]<<std::endl;

    glm::vec3 rmse = rmse(vertices, res1);
    std::cout<<"rmse_x="<<rmse[0]<<"rmse_y="<<rmse[1]<<"rmse_z="<<rmse[2]<<std::endl;
    return 0;
}
