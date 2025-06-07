#include <Windows.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define M_PI 3.14159265358979323846
using namespace std;

double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
float scale = 1.0f;

bool bx = true;
bool by = true;
bool bz = true;

// Matrices del laberinto
const int filas = 21;
const int columnas = 21;

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
    {1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1},
    {1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1},
    {0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1},
    {1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1}
};

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void ArrowKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT: X += 1.0; break;
    case GLUT_KEY_LEFT: X -= 1.0; break;
    case GLUT_KEY_UP: Y += 1.0; break;
    case GLUT_KEY_DOWN: Y -= 1.0; break;
    case GLUT_KEY_HOME: scale += 0.5; break;
    case GLUT_KEY_END: scale -= 0.5; break;
    }
    glutPostRedisplay();
}

// Función para dibujar un pequeño cubo para cada celda del laberinto
void dibujarCeldaLaberinto(float x, float y, float z, float tamaño) {
    float t = tamaño / 2.0f;

    glBegin(GL_QUADS);

    // Cara frontal
    glColor3f(0.7, 0.7, 0.9);
    glVertex3f(x - t, y - t, z + t);
    glVertex3f(x + t, y - t, z + t);
    glVertex3f(x + t, y + t, z + t);
    glVertex3f(x - t, y + t, z + t);

    // Cara trasera
    glColor3f(0.5, 0.5, 0.7);
    glVertex3f(x - t, y - t, z - t);
    glVertex3f(x - t, y + t, z - t);
    glVertex3f(x + t, y + t, z - t);
    glVertex3f(x + t, y - t, z - t);

    // Cara derecha
    glColor3f(0.6, 0.6, 0.8);
    glVertex3f(x + t, y - t, z - t);
    glVertex3f(x + t, y + t, z - t);
    glVertex3f(x + t, y + t, z + t);
    glVertex3f(x + t, y - t, z + t);

    // Cara izquierda
    glColor3f(0.6, 0.6, 0.8);
    glVertex3f(x - t, y - t, z - t);
    glVertex3f(x - t, y - t, z + t);
    glVertex3f(x - t, y + t, z + t);
    glVertex3f(x - t, y + t, z - t);

    // Cara superior
    glColor3f(0.8, 0.8, 1.0);
    glVertex3f(x - t, y + t, z - t);
    glVertex3f(x - t, y + t, z + t);
    glVertex3f(x + t, y + t, z + t);
    glVertex3f(x + t, y + t, z - t);

    // Cara inferior
    glColor3f(0.4, 0.4, 0.6);
    glVertex3f(x - t, y - t, z - t);
    glVertex3f(x + t, y - t, z - t);
    glVertex3f(x + t, y - t, z + t);
    glVertex3f(x - t, y - t, z + t);

    glEnd();
}

void dibujaCubo() {
    float tamañoCelda = 0.05f; // Tamaño de cada celda del laberinto
    float offsetCara = 0.5f;   // Distancia de cada cara del centro

    // CARA FRONTAL (Z = +0.5) - usar caraUno
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (caraUno[i][j] == 1) {
                float x = (j - columnas / 2.0f) * tamañoCelda;
                float y = -(i - filas / 2.0f) * tamañoCelda;
                dibujarCeldaLaberinto(x, y, offsetCara, tamañoCelda);
            }
        }
    }

    // CARA TRASERA (Z = -0.5) - usar caraDos
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (caraDos[i][j] == 1) {
                float x = (j - columnas / 2.0f) * tamañoCelda;
                float y = -(i - filas / 2.0f) * tamañoCelda;
                dibujarCeldaLaberinto(x, y, -offsetCara, tamañoCelda);
            }
        }
    }

    // CARA DERECHA (X = +0.5) - usar caraDos
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (caraDos[i][j] == 1) {
                float y = -(i - filas / 2.0f) * tamañoCelda;
                float z = (j - columnas / 2.0f) * tamañoCelda;
                dibujarCeldaLaberinto(offsetCara, y, z, tamañoCelda);
            }
        }
    }

    // CARA IZQUIERDA (X = -0.5) - usar caraUno
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (caraUno[i][j] == 1) {
                float y = -(i - filas / 2.0f) * tamañoCelda;
                float z = -(j - columnas / 2.0f) * tamañoCelda; // Invertir Z para orientación correcta
                dibujarCeldaLaberinto(-offsetCara, y, z, tamañoCelda);
            }
        }
    }

    // CARA SUPERIOR (Y = +0.5) - usar caraUno
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (caraUno[i][j] == 1) {
                float x = (j - columnas / 2.0f) * tamañoCelda;
                float z = -(i - filas / 2.0f) * tamañoCelda;
                dibujarCeldaLaberinto(x, offsetCara, z, tamañoCelda);
            }
        }
    }

    // CARA INFERIOR (Y = -0.5) - usar caraDos
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (caraDos[i][j] == 1) {
                float x = (j - columnas / 2.0f) * tamañoCelda;
                float z = (i - filas / 2.0f) * tamañoCelda;
                dibujarCeldaLaberinto(x, -offsetCara, z, tamañoCelda);
            }
        }
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0 - X, 0.0 - Y, 4.5 - Z, 0.0 - X, 0.0 - Y, 0.0 - Z, 0.0, 1.0, 0.0);
    glPushMatrix();
    if (bx == true) {
        rotate_x += .02;
    }
    if (by == true) {
        rotate_y += .02;
    }
    if (bz == true) {
        rotate_z += .02;
    }

    glScalef(scale, scale, scale);
    glTranslatef(0, -0.5, 0);

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    dibujaCubo(); // Ahora dibuja el cubo con laberintos
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.00, 1.0, 0.1, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 43: Z += 1.0; break;
    case 45: Z -= 1.0; break;
    case 120: // letra x
        if (by == false) {
            by = true;
        }
        else {
            by = false;
        }
        break;
    case 121: // letra y
        if (bx == false) {
            bx = true;
        }
        else {
            bx = false;
        }
        break;
    case 122: // letra z
        if (bz == false) {
            bz = true;
        }
        else {
            bz = false;
        }
        break;
    case 27: exit(0); break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cubo Laberinto 3D");

    glEnable(GL_DEPTH_TEST);
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(ArrowKey);
    glutMainLoop();
    return 0;
}
