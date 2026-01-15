#include <iostream>
#include <string>
#include <GL/glut.h>
#include "Game.h"
#include "Coordinate.h"

using namespace std;

///////////////////// CONSTANTES ////////////////////////

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 300;
const int WINDOW_POSITION_Y = 100;
const char TITLE[] = "PARTE 2";

const GLclampf RED = 0.6f;
const GLclampf GREEN = 0.8f;
const GLclampf BLUE = 0.7f;
const GLclampf ALPHA = 1.0f;

bool fullScreenMode = false;

/////////////////////////////////////////////////////////////////

Game game;

/////////////////////////////////////////////////////////////////

///////////////////// FUNCIONES OPENGL //////////////////////////


void initGraphics()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RED, GREEN, BLUE, ALPHA);
    glEnable(GL_BLEND);  // Habilitar blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // Configurar blending

    game.Init();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    game.Render();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, aspectRatio, 1.0f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
}

void idle()
{
    // Calcular el tiempo transcurrido desde el último update
    static long long lastTime = 0;
    using namespace std::chrono;
    long long currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    float deltaTime = 0.0f;
    if (lastTime == 0) {
        lastTime = currentTime;
    }
    deltaTime = static_cast<float>(currentTime - lastTime) / 1000.0f; // deltaTime en segundos
    lastTime = currentTime;

    game.Update(deltaTime);
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int px, int py)
{
    game.ProcessKeyPressed(key,px,py);
    glutPostRedisplay();
}


void mouseClicked(int button, int state, int x, int y)
{
    game.ProcessMouseClicked(button, state, x, y);
    glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_F11:
        fullScreenMode = !fullScreenMode;
        if (fullScreenMode)
        {
            glutFullScreen();
        }
        else
        {
            glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
            glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
        }
        break;
    }
}

/////////////////////// MAIN ////////////////////////////////////

int main(int argc, char** argv)
{
    Coordinate coord1(3.2, 5.4);
    cout << "Coordinate 1: " << coord1 << endl;
    cout << "Hello world con OpenGL" << endl;

    cout << "Generando ventana..." << endl;
    glutInit(&argc, argv);                                          // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);      // doble buffer, modo RGBA, depth buffer
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);                // tamaño inicial de la ventana
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);   // posición inicial de la ventana
    glutCreateWindow(TITLE);                                        // crea una ventana con el título dado

    cout << "Registrando funciones de tratamiento de eventos..." << endl;
    glutReshapeFunc(reshape);                                       // tratamiento del evento de redimensionado de la ventana
    glutDisplayFunc(display);                                       // tratamiento del evento de repintado de la ventana
    glutKeyboardFunc(keyPressed);                                   // tratamiento del evento de tecla pulsada
    glutSpecialFunc(specialKey);                                    // tratamiento del evento de tecla especial pulsada
    glutMouseFunc(mouseClicked);                                    // tratamiento del evento de clic del ratón
    glutIdleFunc(idle);                                             // para cuando no hay eventos que tratar         

    cout << "Iniciando gráficos..." << endl;
    initGraphics();                                                 // Iniciamos OpenGL

    cout << "Iniciando bucle infinito..." << endl;
    cout << "Pulse F11 para activar/desactivar el modo de pantalla completa." << endl;
    glutMainLoop();

}

