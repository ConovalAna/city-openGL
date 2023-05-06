#include "HelperFunctions.h"
#include "Objects.h"
#include "Texture.h"

#define DEFAULT_TIMER 20 // time in ms between each frame
#define CAMERA_ROTATION_SPEED 5

//Colors
GLfloat WHITE[4] = { 1, 1, 1, 1 };
GLfloat BLACK[4] = { 0, 0, 0, 1 };
GLfloat RED[4] = { 1, 0, 0, 1 };
GLfloat GREEN[4] = { 0, 1, 0, 1 };
GLfloat DARK_GREEN[4] = { 0, 0.5f, 0, 0.5f };
GLfloat BLUE[4] = { 0, 0, 1, 1 };
GLfloat LIGHT_BLUE[4] = { 0, 0.5f, 1, 1 };
GLfloat MAGENTA[4] = { 1, 0, 1, 1 };
GLfloat ORANGE[4] = { 1, 0.5f, 0, 1 };
GLfloat YELLOW[4] = { 1, 1, 0, 1 };

//Declare the Scene Object
Scene scene(0, 0, 0, 20);

//CREATE House Layout
int editScene = 0;
int selectObject = 1;
int xObject=0;
int yObject=0;
BuildingModel1 building1(xObject, yObject, -30);
BuildingModel2 building2(xObject, yObject, -30);
BuildingModel3 building3(xObject, yObject, -30);
BuildingModel4 building4(xObject, yObject, -30);
BuildingModel5 building5(xObject, yObject, -30);
BuildingModel6 building6(xObject, yObject, -30);
TreeModel1 tree1(xObject, yObject, -30);
TreeModel2 tree2(xObject, yObject, -30);
TreeModel3 tree3(xObject, yObject, -30);
TreeModel4 tree4(xObject, yObject, -30);


//Camera initial setup
double cameraRotationX = -40;
double cameraRotationZ = 0;
double cameraXAxis = 0;
double cameraYAxis = 15;
double cameraZAxis = -28;
double cameraRotationXInit = cameraRotationX;
double cameraRotationZInit = cameraRotationZ;
double cameraXAxisInit = cameraXAxis;
double cameraYAxisInit = cameraYAxis;
double cameraZAxisInit = cameraZAxis;
void display()
{
    //OpenGL Frame setup
    static int last = glutGet(GLUT_ELAPSED_TIME);
    int cur = glutGet(GLUT_ELAPSED_TIME);
    double dt = (cur - last) / 1000.0f;
    last = cur;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(60, w / h, 0.1, 100);

    //Set the camera initial position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(cameraXAxis, cameraYAxis, cameraZAxis);
    glRotatef(cameraRotationX, 1.0, 0.0, 0.0);
    glRotatef(cameraRotationZ, 0.0, 0.0, 1.0);
    
    //Display the scene
    scene.Display();

    //Edit the scene
    if (editScene == 1) {
        switch (selectObject) {
        case 1:
            building1.x = xObject;
            building1.y = yObject;
            building1.Display();
            break;
        case 2:
            building2.x = xObject;
            building2.y = yObject;
            building2.Display();
            break;
        case 3:
            building3.x = xObject;
            building3.y = yObject;
            building3.Display();
            break;
        case 4:
            building4.x = xObject;
            building4.y = yObject;
            building4.Display();
            break;
        case 5:
            building5.x = xObject;
            building5.y = yObject;
            building5.Display();
            break;
        case 6:
            building6.x = xObject;
            building6.y = yObject;
            building6.Display();
            break;
        case 7:
            tree1.x = xObject;
            tree1.y = yObject;
            tree1.Display();
            break;
        case 8:
            tree2.x = xObject;
            tree2.y = yObject;
            tree2.Display();
            break;
        case 9:
            tree3.x = xObject;
            tree3.y = yObject;
            tree3.Display();
            break;
        case 10:
            tree4.x = xObject;
            tree4.y = yObject;
            tree4.Display();
            break;
        }
    }

    //Create a light
    GLfloat light_position[] = {0, 0, 19, 0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    DisplaySphere(YELLOW, 0,0,28, 3, 10);
    
    //Clear
    glutSwapBuffers();
}

//Control camera
void cameraInputControl(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_RIGHT:
        if(editScene == 0)
            cameraRotationZ -= CAMERA_ROTATION_SPEED;
        else
            xObject += 1;
        break;
    case GLUT_KEY_LEFT:
        if (editScene == 0)
            cameraRotationZ += CAMERA_ROTATION_SPEED;
        else
            xObject -= 1;
        break;
    case GLUT_KEY_UP:
        if (editScene == 0)
            cameraRotationX += CAMERA_ROTATION_SPEED;
        else
            yObject += 1;
        break;
    case GLUT_KEY_DOWN:
        if (editScene == 0)
            cameraRotationX -= CAMERA_ROTATION_SPEED;
        else
            yObject -= 1;
        break;
    case GLUT_KEY_HOME:
        //zoom in
        cameraXAxis += 1;
        break;
    case GLUT_KEY_END:
        //zoom out
        cameraXAxis -= 1;
        break;
    case GLUT_KEY_PAGE_UP:
        //zoom in
        cameraYAxis -= 1;
        break;
    case GLUT_KEY_PAGE_DOWN:
        //zoom out
        cameraYAxis += 1;
        break;
    case GLUT_KEY_INSERT:
        //restore camera initial position
        cameraRotationX = cameraRotationXInit;
        cameraRotationZ = cameraRotationZInit;
        cameraXAxis = cameraXAxisInit;
        cameraYAxis = cameraYAxisInit;
        cameraZAxis = cameraZAxisInit;
        break;
    case GLUT_KEY_F1:
        //zoom in
        cameraZAxis += 1;
        break;
    case GLUT_KEY_F2:
        //zoom out
        cameraZAxis -= 1;
        break;
    case GLUT_KEY_F3:
        //DISPLAY INFO
        std::cout << " - Camera Position - "<< cameraRotationX <<" "<< cameraRotationZ <<" "<< cameraXAxis << " "<< cameraYAxis <<" "<< cameraZAxis <<std::endl;
        scene.DisplayObjectsInfo();
        break;
    case GLUT_KEY_F7:
        //Activate/deactivate editing the scene
        if (editScene == 0)
            editScene = 1;
        else
            editScene = 0;
        break;
    case GLUT_KEY_F8:
        //decrease the select variable
        selectObject -= 1;
        if (selectObject < 1)
            selectObject = 10;
        break;
    case GLUT_KEY_F9:
        //increase the select variable
        selectObject += 1;
        if (selectObject > 10)
            selectObject = 1;
        break;
    case GLUT_KEY_F10:
        //Add the new element to the scene
        if(editScene == 1)
            scene.AddNewObject(selectObject, xObject, yObject);
        break;
    case GLUT_KEY_F11:
        //Delete the elements from the scene
        if (editScene == 1) {
            scene.DeleteLastEntry(selectObject);
        }
        else {
            editScene = 1;
            scene.Clear();
        }
        break;
    }
}

//Timer for running the display function
void timer(int extra)
{
    // run display() every DEFAULT_TIMER ms
    glutTimerFunc(DEFAULT_TIMER, timer, 0);
    glutPostRedisplay();
}

//Main Function
int main(int argc, char* argv[])
{
    //init random seed
    srand((unsigned)time(0));
    //Display user controls
    CmdDisplay();

    //Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Init OpenGl
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 900);
    glutCreateWindow("City Scene");
    glEnable(GL_DEPTH_TEST);

    //Set functions
    glutDisplayFunc(display);
    glutSpecialFunc(cameraInputControl);
    glutTimerFunc(0, timer, 0);

    //Start main loop
    glutMainLoop();
    return 0;
}