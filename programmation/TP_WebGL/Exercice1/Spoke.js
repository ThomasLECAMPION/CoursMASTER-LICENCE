// Définition de la classe Triangle


class Spoke
{
    /** constructeur */
    constructor(scale, angleX, angleY, angleZ)
    {
        /** shader */
        this.scale = scale;
        this.angleX = angleX;
        this.angleY = angleY;
        this.angleZ = angleZ;

        let srcVertexShader = dedent
            `#version 300 es
            #define PI 3.1415926538
            in vec2 glVertex;
            float flip = 1.0;
            uniform float scale;
            uniform float angleX;
            uniform float angleY;
            uniform float angleZ;


            void main()
            {
                float id = float(gl_InstanceID);
                if(id>=6.0) {
                    flip = -1.0;
                    id -= 6.0;
                }
                float rotationX = PI*angleX;
                float rotationY = PI*angleY;
                float rotationZ = PI*angleZ;

                mat4 matX = mat4(-1.0, 0.0, 0.0, 0.0,
                                  0.0, cos(rotationX), sin(rotationX), 0.0,
                                  0.0, -sin(rotationX), cos(rotationX), 0.0,
                                  0.0, 0.0, 0.0, 1.0);
                mat4 matY = mat4(cos(rotationY), 0.0, -sin(rotationY), 0.0,
                                  0.0, 1.0, 0.0, 0.0,
                                  sin(rotationY), 0.0, cos(rotationY), 0.0,
                                  0.0, 0.0, 0.0, 1.0);
                mat4 matZ = mat4(cos(rotationZ), sin(rotationZ), 0.0, 0.0,
                                  -sin(rotationZ), cos(rotationZ), 0.0, 0.0,
                                  0.0, 0.0, 1.0, 0.0,
                                  0.0, 0.0, 0.0, 1.0);
                mat4 matFlake = mat4(cos(PI*id/3.0), sin(PI*id/3.0), 0.0, 0.0,
                                  -sin(PI*id/3.0), cos(PI*id/3.0), 0.0, 0.0,
                                  0.0, 0.0, 1.0, 0.0,
                                  0.0, 0.0, 0.0, 1.0);
                gl_Position = vec4(glVertex[0], glVertex[1] * flip, 0.0, scale) * matFlake * matX * matY * matZ;
            }`;

        let srcFragmentShader = dedent
            `#version 300 es
            precision mediump float;
            out vec4 glFragColor;
            void main()
            {
                glFragColor = vec4(0.9, 0.9, 0.9, 1.0);
            }`;

        // compiler le shader de dessin
        this.m_ShaderId = Utils.makeShaderProgram(srcVertexShader, srcFragmentShader, "Spoke");

        // déterminer où sont les variables attribute
        this.m_VertexLoc = gl.getAttribLocation(this.m_ShaderId, "glVertex");

        /** VBOs */

        // créer et remplir le buffer des coordonnées
        this.vertices = [
0.0, 0.0109,
0.2174, 0.0109,
0.2174, 0.0109,
0.2826, 0.1196,
0.2826, 0.1196,
0.2994, 0.1104,
0.2994, 0.1104,
0.2391, 0.0109,
0.2391, 0.0109,
0.3261, 0.0109,
0.3261, 0.0109,
0.3696, 0.0761,
0.3696, 0.0761,
0.386, 0.0667,
0.386, 0.0667,
0.3478, 0.0109,
0.3478, 0.0109,
0.4783, 0.0109,
0.4783, 0.0109,
0.5, 0.0
];
        this.m_VertexBufferId = Utils.makeFloatVBO(this.vertices, gl.ARRAY_BUFFER, gl.STATIC_DRAW);
    }


    /** dessiner l'objet */
    onDraw()
    {
        // activer le shader
        gl.useProgram(this.m_ShaderId);

        let u_scale = gl.getUniformLocation(this.m_ShaderId, "scale");
        gl.uniform1f(u_scale, this.scale);
        let u_angleX = gl.getUniformLocation(this.m_ShaderId, "angleX");
        gl.uniform1f(u_angleX, this.angleX);
        let u_angleY = gl.getUniformLocation(this.m_ShaderId, "angleY");
        gl.uniform1f(u_angleY, this.angleY);
        let u_angleZ = gl.getUniformLocation(this.m_ShaderId, "angleZ");
        gl.uniform1f(u_angleZ, this.angleZ);

        // activer et lier le buffer contenant les coordonnées
        gl.bindBuffer(gl.ARRAY_BUFFER, this.m_VertexBufferId);
        gl.enableVertexAttribArray(this.m_VertexLoc);
        gl.vertexAttribPointer(this.m_VertexLoc, Utils.VEC2, gl.FLOAT, gl.FALSE, 0, 0);

        // dessiner un triangle avec les trois vertices
        gl.drawArraysInstanced(gl.LINES, 0, this.vertices.length/2, 12);

        // désactiver le buffer
        gl.disableVertexAttribArray(this.m_VertexLoc);
        gl.bindBuffer(gl.ARRAY_BUFFER, null);

        // désactiver le shader
        gl.useProgram(null);
    }


    /** destructeur */
    destroy()
    {
        // supprimer le shader et le VBO
        Utils.deleteShaderProgram(this.m_ShaderId);
        Utils.deleteVBO(this.m_VertexBufferId);
    }
}
