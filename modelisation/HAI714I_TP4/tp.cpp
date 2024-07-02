// -------------------------------------------
// gMini : a minimal OpenGL/GLUT application
// for 3D graphics.
// Copyright (C) 2006-2008 Tamy Boubekeur
// All rights reserved.
// -------------------------------------------

// -------------------------------------------
// Disclaimer: this code is dirty in the
// meaning that there is no attention paid to
// proper class attribute access, memory
// management or optimisation of any kind. It
// is designed for quick-and-dirty testing
// purpose.
// -------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <GL/glut.h>
#include <float.h>
#include "src/Vec3.h"
#include "src/Camera.h"

// -------------------------------------------
// OpenGL/GLUT application code.
// -------------------------------------------

static GLint window;
static unsigned int SCREENWIDTH = 1600;
static unsigned int SCREENHEIGHT = 900;
static Camera camera;
static bool mouseRotatePressed = false;
static bool mouseMovePressed = false;
static bool mouseZoomPressed = false;
static int lastX=0, lastY=0, lastZoom=0;
static bool fullScreen = false;

// ------------------------------------

void initLight () {
    GLfloat light_position1[4] = {22.0f, 16.0f, 50.0f, 0.0f};
    GLfloat direction1[3] = {-52.0f,-16.0f,-50.0f};
    GLfloat color1[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat ambient[4] = {0.3f, 0.3f, 0.3f, 0.5f};

    glLightfv (GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv (GL_LIGHT1, GL_SPOT_DIRECTION, direction1);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, color1);
    glLightfv (GL_LIGHT1, GL_SPECULAR, color1);
    glLightModelfv (GL_LIGHT_MODEL_AMBIENT, ambient);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
}

void init () {
    camera.resize (SCREENWIDTH, SCREENHEIGHT);
    initLight ();
    glCullFace (GL_BACK);
    glEnable (GL_CULL_FACE);
    glDepthFunc (GL_LESS);
    glEnable (GL_DEPTH_TEST);
    glClearColor (0.2f, 0.2f, 0.3f, 1.0f);
    glEnable(GL_COLOR_MATERIAL);
}




// ------------------------------------
// rendering.
// ------------------------------------


void drawVector( Vec3 const & i_from, Vec3 const & i_to ) {

    glBegin(GL_LINES);
    glVertex3f( i_from[0] , i_from[1] , i_from[2] );
    glVertex3f( i_to[0] , i_to[1] , i_to[2] );
    glEnd();
}

void drawCurve(std::vector< Vec3 > & TabPointsOfCurve) {
    glBegin(GL_LINES);
    for(unsigned int i=0; i<TabPointsOfCurve.size()-1; i++) {
        glVertex3f( TabPointsOfCurve[i][0] , TabPointsOfCurve[i][1] , TabPointsOfCurve[i][2] );
        glVertex3f( TabPointsOfCurve[i+1][0] , TabPointsOfCurve[i+1][1] , TabPointsOfCurve[i+1][2] );
    }
    glEnd();
}

void drawSurface(std::vector< std::vector< Vec3 > > & surface) {
    for(unsigned int i=0; i<surface.size(); i++){
        drawCurve(surface[i]);
    }
}

std::vector< Vec3 > cubicHermiteCurve(Vec3 & p0, Vec3 & p1, Vec3 & v0, Vec3 & v1, long nbU) {
    std::vector< Vec3 > tabU;
    for(float t=0.0f; t<=1.0f; t+=1.0f/nbU) {
        Vec3 a = (2*powf(t,3) - 3*powf(t,2) + 1) * p0;
        Vec3 b = (powf(t,3) - 2*powf(t,2) + t) * v0;
        Vec3 c = (-2*powf(t,3) + 3*powf(t,2)) * p1;
        Vec3 d = (powf(t,3) - powf(t,2)) * v1;
        tabU.push_back( a+b+c+d );
    }
    return tabU;
}

int fact(int i) {
    if(i<=1) {
      return 1;
    }
    else {
      return i*fact(i-1);
    }
}

float bernstein(int i, int n, float t) {
    return (fact(n)/(fact(i)*fact(n-i)))*powf(t,i)*pow(1-t,n-i);
}

std::vector< Vec3 > bezierCurveByBernstein(std::vector< Vec3 > & TabControlPoint, int nbControlPoint, float nbU) {
    std::vector< Vec3 > tabU;
    for(float t=0.0f; t<=1.0f; t+=1.0f/nbU) {
        Vec3 point = Vec3( 0.0f, 0.0f, 0.0f );
        for(int i=0; i<=nbControlPoint; i++) {
            point += Vec3(bernstein(i, nbControlPoint, t) * TabControlPoint[i]);
        }
        tabU.push_back(point);
    }
    return tabU;
}

std::vector< std::vector< Vec3 > > surfaceCylindrique(std::vector< Vec3 > & TabControlPoint, Vec3 & droite, float nbU, float nbV) {
    std::vector< std::vector< Vec3 > > courbes;
    std::vector< Vec3 > bezier = bezierCurveByBernstein(TabControlPoint, TabControlPoint.size()-1, nbU);
        for(float v=0.0f; v<=1.0f; v+=1.0f/nbV) {
            std::vector< Vec3 > courbe;
            for(unsigned int i=0; i<bezier.size(); i++) {
                courbe.push_back( Vec3(bezier[i] + (v * droite)) );
            }
            courbes.push_back(courbe);
        }
    return courbes;
}

std::vector< std::vector< Vec3 > > surfaceReglee(std::vector< Vec3 > & TabControlPointA, std::vector< Vec3 > & TabControlPointB, float nbU, float nbV) {
    std::vector< std::vector< Vec3 > > courbes;
    std::vector< Vec3 > bezierA = bezierCurveByBernstein(TabControlPointA, TabControlPointA.size()-1, nbU);
    std::vector< Vec3 > bezierB = bezierCurveByBernstein(TabControlPointB, TabControlPointB.size()-1, nbU);
        for(float v=0.0f; v<=1.0f; v+=1.0f/nbV) {
            std::vector< Vec3 > courbe;
            for(unsigned int i=0; i<bezierA.size(); i++) {
                courbe.push_back( Vec3((1-v) * bezierA[i] + v * bezierB[i]) );
            }
            courbes.push_back(courbe);
        }
    return courbes;
}

std::vector< std::vector< Vec3 > > surfaceBernstein(std::vector< std::vector< Vec3 > > grilleControlPoint, int nbCU, int nbCV, float nbU, float nbV) {
    std::vector< std::vector< Vec3 > > courbes;
    for(float u=0.0f; u<1.0f; u+=1/nbU) {
        std::vector< Vec3 > courbe;
        for(float v=0.0f; v<1.0f; v+=1/nbV) {
            Vec3 point = Vec3 (0.0f, 0.0f, 0.0f);
            for(int i=0; i<=nbCU; i++) {
                for(int j=0; j<=nbCV; j++) {
                    point += Vec3( bernstein(i, nbCU, u) * bernstein(j, nbCV, v) * grilleControlPoint[i][j] );
                }
            }
            courbe.push_back(point);
        }
        courbes.push_back(courbe);
    }
    return courbes;
}

void draw () {
    //Parametres
    std::vector< Vec3 > TabPointsOfCurve;
    std::vector< std::vector < Vec3 > > surfaceParametrique;
    float nbU = 50.0f;
    float nbV = 50.0f;

    /*Affichage exercice 1
    Vec3 a = Vec3(-0.75f,-0.75f,0.0f);
    Vec3 b = Vec3(-0.50f,0.75f,0.0f);
    Vec3 c = Vec3(-0.25f,-0.75f,0.0f);
    Vec3 d = Vec3(0.0f,0.75f,0.0f);
    Vec3 e = Vec3(0.25f,-0.75f,0.0f);
    Vec3 f = Vec3(0.50f,0.75f,0.0f);
    Vec3 g = Vec3(0.75f,-0.75f,0.0f);


    std::vector< Vec3 > controlPoints{a,b,c,d,e,f,g};

    Vec3 droite = Vec3(0.0f, 0.0f, 1.0f);
    TabPointsOfCurve = bezierCurveByBernstein(controlPoints, controlPoints.size()-1, nbU);
    surfaceParametrique =  surfaceCylindrique(controlPoints, droite, nbU, nbV);
    //courbe de base
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCurve(TabPointsOfCurve);
    //points de contructions
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCurve(controlPoints);
    //surface donnee par la courbe et une droite
    glColor3f(0.0f, 0.0f, 1.0f);
    drawSurface(surfaceParametrique);
    */

    /*Affichage exercice 2
    Vec3 a0 = Vec3(-1.75f,-1.75f,1.0f);
    Vec3 b0 = Vec3(-1.50f,1.75f,1.0f);
    Vec3 c0 = Vec3(-1.25f,-1.75f,1.0f);
    Vec3 d0 = Vec3(1.0f,1.75f,1.0f);
    Vec3 e0 = Vec3(1.25f,-1.75f,1.0f);
    Vec3 f0 = Vec3(1.50f,1.75f,1.0f);
    Vec3 g0 = Vec3(1.75f,-1.75f,1.0f);

    std::vector< Vec3 > controlPoints0{a0,b0,c0,d0,e0,f0,g0};
    surfaceParametrique = surfaceReglee(controlPoints, controlPoints0, nbU, nbV);
    glColor3f(0.0f, 0.0f, 1.0f);
    drawSurface(surfaceParametrique);
    */

    //Affichage exercice 3
    Vec3 s00 = Vec3(0.0f,0.0f,0.0f);
    Vec3 s01 = Vec3(1.0f,1.0f,0.0f);
    Vec3 s02 = Vec3(2.0f,1.0f,0.0f);
    Vec3 s03 = Vec3(3.0f,0.0f,0.0f);
    std::vector< Vec3 > v0;
    v0.push_back(s00);
    v0.push_back(s01);
    v0.push_back(s02);
    v0.push_back(s03);

    Vec3 s10 = Vec3(0.0f,1.0f,1.0f);
    Vec3 s11 = Vec3(1.0f,2.0f,1.0f);
    Vec3 s12 = Vec3(2.0f,2.0f,1.0f);
    Vec3 s13 = Vec3(3.0f,1.0f,1.0f);
    std::vector< Vec3 > v1;
    v1.push_back(s10);
    v1.push_back(s11);
    v1.push_back(s12);
    v1.push_back(s13);

    Vec3 s20 = Vec3(0.0f,1.0f,2.0f);
    Vec3 s21 = Vec3(1.0f,2.0f,2.0f);
    Vec3 s22 = Vec3(2.0f,2.0f,2.0f);
    Vec3 s23 = Vec3(3.0f,1.0f,2.0f);
    std::vector< Vec3 > v2;
    v2.push_back(s20);
    v2.push_back(s21);
    v2.push_back(s22);
    v2.push_back(s23);

    Vec3 s30 = Vec3(0.0f,0.0f,3.0f);
    Vec3 s31 = Vec3(1.0f,1.0f,3.0f);
    Vec3 s32 = Vec3(2.0f,1.0f,3.0f);
    Vec3 s33 = Vec3(3.0f,0.0f,3.0f);
    std::vector< Vec3 > v3;
    v3.push_back(s30);
    v3.push_back(s31);
    v3.push_back(s32);
    v3.push_back(s33);

    std::vector< std::vector< Vec3 > > grilleControlPoint;
    grilleControlPoint.push_back(v0);
    grilleControlPoint.push_back(v1);
    grilleControlPoint.push_back(v2);
    grilleControlPoint.push_back(v3);

    surfaceParametrique = surfaceBernstein(grilleControlPoint, grilleControlPoint.size()-1, grilleControlPoint[0].size()-1, nbU, nbV);
    glColor3f(0.0f, 1.0f, 0.0f);
    drawSurface(surfaceParametrique);
}


void display () {
    glLoadIdentity ();
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera.apply ();
    draw ();
    glFlush ();
    glutSwapBuffers ();
}

void idle () {
    glutPostRedisplay ();
}

void key (unsigned char keyPressed, int x, int y) {
    switch (keyPressed) {
    case 'f':
        if (fullScreen == true) {
            glutReshapeWindow (SCREENWIDTH, SCREENHEIGHT);
            fullScreen = false;
        } else {
            glutFullScreen ();
            fullScreen = true;
        }
        break;

    default:
        break;
    }
    idle ();
}

void mouse (int button, int state, int x, int y) {
    if (state == GLUT_UP) {
        mouseMovePressed = false;
        mouseRotatePressed = false;
        mouseZoomPressed = false;
    } else {
        if (button == GLUT_LEFT_BUTTON) {
            camera.beginRotate (x, y);
            mouseMovePressed = false;
            mouseRotatePressed = true;
            mouseZoomPressed = false;
        } else if (button == GLUT_RIGHT_BUTTON) {
            lastX = x;
            lastY = y;
            mouseMovePressed = true;
            mouseRotatePressed = false;
            mouseZoomPressed = false;
        } else if (button == GLUT_MIDDLE_BUTTON) {
            if (mouseZoomPressed == false) {
                lastZoom = y;
                mouseMovePressed = false;
                mouseRotatePressed = false;
                mouseZoomPressed = true;
            }
        }
    }
    idle ();
}

void motion (int x, int y) {
    if (mouseRotatePressed == true) {
        camera.rotate (x, y);
    }
    else if (mouseMovePressed == true) {
        camera.move ((x-lastX)/static_cast<float>(SCREENWIDTH), (lastY-y)/static_cast<float>(SCREENHEIGHT), 0.0);
        lastX = x;
        lastY = y;
    }
    else if (mouseZoomPressed == true) {
        camera.zoom (float (y-lastZoom)/SCREENHEIGHT);
        lastZoom = y;
    }
}


void reshape(int w, int h) {
    camera.resize (w, h);
}



int main (int argc, char ** argv) {
    if (argc > 2) {
        exit (EXIT_FAILURE);
    }
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize (SCREENWIDTH, SCREENHEIGHT);
    window = glutCreateWindow ("TP HAI714I");

    init ();
    glutIdleFunc (idle);
    glutDisplayFunc (display);
    glutKeyboardFunc (key);
    glutReshapeFunc (reshape);
    glutMotionFunc (motion);
    glutMouseFunc (mouse);
    key ('?', 0, 0);

    glutMainLoop ();
    return EXIT_SUCCESS;
}
