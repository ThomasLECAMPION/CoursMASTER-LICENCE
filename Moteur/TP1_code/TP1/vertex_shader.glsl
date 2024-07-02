#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertices_position_modelspace;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){

  TexCoord = aTexCoord;
  mat4 mvp = projection * view * model;
  gl_Position = mvp * vec4(vertices_position_modelspace, 1);
}
