#include <Windows.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define M_PI 3.14159265358979323846
const int filas = 21;
const int columnas = 21;

using namespace std;

// Definir la matriz del laberinto
int caraUno[filas][columnas] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1},
	{1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1},
	{1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
	{1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1},
	{1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1},
	{1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1},
	{1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1},
	{1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1},
	{1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
	{1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1},
	{0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int caraDos[filas][columnas] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

float cameraX = 6.5, cameraY = 10.0, cameraZ = 20.0;
float centerX = 6.5, centerY = 0.0, centerZ = 6.5;
float rotX = 0.0f, rotY = 0.0f, rotZ = 0.0f;

// Función para dibujar cubo con colores por cara
void dibujaCubo(float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    glBegin(GL_POLYGON); // Cara trasera
    //glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    glBegin(GL_POLYGON); // Derecha
    //glColor3f(0.1, 0.5, 0.7);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    glBegin(GL_POLYGON); // Izquierda
    //glColor3f(0.3, 0.6, 0.1);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    glBegin(GL_POLYGON); // Superior
    glColor3f(0.0, 0.8, 1.0);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    glBegin(GL_POLYGON); // Inferior
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
}

//  Dibujo
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cameraX, cameraY, cameraZ, centerX, centerY, centerZ, 0.0, 1.0, 0.0);

    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);
    glRotatef(rotZ, 0, 0, 1);

    for (int fila = 0; fila < filas; fila++) {
        for (int col = 0; col < columnas; col++) {
            if (caraUno[fila][col] == 1) {
                glPushMatrix();
                glTranslatef(col, 1.0f, fila);  // altura del muro
                glScalef(1.0f, 4.0f, 1.0f);     // muro alto
                dibujaCubo(0.2, 0.2, 0.2);
                glPopMatrix();
            }
        }
    }

    glutSwapBuffers();
}

//  Viewport
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

//  Movimiento con teclado
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': cameraZ -= 1.0f; break;
    case 's': cameraZ += 1.0f; break;
    case 'a': cameraX -= 1.0f; break;
    case 'd': cameraX += 1.0f; break;
    case 'q': cameraY += 1.0f; break;
    case 'e': cameraY -= 1.0f; break;
    case 'z': rotZ -= 5.0f; break;
    case 'x': rotZ += 5.0f; break;
    }
    glutPostRedisplay();
}

//  Inicialización
void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fondo gris oscuro
}

//  Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Laberinto");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}