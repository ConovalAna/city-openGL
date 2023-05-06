#include <glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <string>
#include <windows.h>
#include <vector>
#include <Eigen/Core>

//Primitive Objects
void DisplayQuad(GLfloat* color, float x1, float y1, float z1, float x2, float y2, float z2);
void DisplayCube(GLfloat* color, float x, float y, float z, float size);
void DisplaySphere(GLfloat* color, float x, float y, float z, float size, int details);
void DisplayCone(GLfloat* color, float x, float y, float z, float size, float height, int details, int xRotation);

//Evolved Objects

class TreeModel1 {
public:
    double x, y, z;
    GLfloat color_leafs[4] = { 0, 0.7f, 0, 1 };
    GLfloat color_wood[4] = { 0.3f, 0.2f, 0, 1 };
    TreeModel1(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplaySphere(color_leafs, x,y, z+3, 1.5f, 10);
        DisplayCube(color_wood, x, y, z + 0.3f, 0.6f);
        DisplayCube(color_wood, x, y, z + 0.9f, 0.6f);
        DisplayCube(color_wood, x, y, z + 1.5f, 0.6f);
        DisplayCube(color_wood, x, y, z + 2.1f, 0.6f);
    }
};

class TreeModel2 {
public:
    double x, y, z;
    GLfloat color_leafs[4] = { 0, 0.6f, 0, 1 };
    GLfloat color_wood[4] = { 0.3f, 0.15f, 0, 1 };
    TreeModel2(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplaySphere(color_leafs, x, y, z + 3.5f, 1.5f, 10);
        DisplaySphere(color_leafs, x, y, z + 3.9f, 1.5f, 10);
        DisplayCube(color_wood, x, y, z + 0.3f, 0.6f);
        DisplayCube(color_wood, x, y, z + 0.9f, 0.6f);
        DisplayCube(color_wood, x, y, z + 1.5f, 0.6f);
        DisplayCube(color_wood, x, y, z + 2.1f, 0.6f);
    }
};

class TreeModel3 {
public:
    double x, y, z;
    GLfloat color_leafs[4] = { 0, 0.5f, 0, 1 };
    GLfloat color_wood[4] = { 0.2f, 0.15f, 0, 1 };
    TreeModel3(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplaySphere(color_leafs, x, y, z + 3.1f, 1, 10);
        DisplaySphere(color_leafs, x, y, z + 3.5f, 1, 10);
        DisplaySphere(color_leafs, x, y, z + 3.9f, 1, 10);
        DisplaySphere(color_leafs, x, y, z + 4.4f, 1, 10);
        DisplaySphere(color_leafs, x, y, z + 4.8f, 1, 10);
        DisplaySphere(color_leafs, x, y, z + 5.2f, 1, 10);
        DisplaySphere(color_leafs, x, y, z + 5.6f, 1, 10);
        DisplayCube(color_wood, x, y, z + 0.3f, 0.6f);
        DisplayCube(color_wood, x, y, z + 0.9f, 0.6f);
        DisplayCube(color_wood, x, y, z + 1.5f, 0.6f);
        DisplayCube(color_wood, x, y, z + 2.1f, 0.6f);
    }
};


class TreeModel4 {
public:
    double x, y, z;
    GLfloat color_leafs[4] = { 0, 0.5f, 0, 1 };
    GLfloat color_wood[4] = { 0.15f, 0.15f, 0, 1 };
    TreeModel4(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplayCone(color_leafs, x, y, z + 1.2f, 1.4f, 1.2f, 10, 45);
        DisplayCone(color_leafs, x, y, z + 2, 1.4f, 1.2f, 10, 45);
        DisplayCone(color_leafs, x, y, z + 2.8f, 1.4f, 1.2f, 10, 45);
        DisplayCone(color_leafs, x, y, z + 3.6f, 1.4f, 1.2f, 10, 45);
        DisplayCone(color_leafs, x, y, z + 4.4f, 1.4f, 1.2f, 10, 45);
        DisplayCone(color_leafs, x, y, z + 5.2f, 1.4f, 1.2f, 10, 45);
        DisplayCone(color_leafs, x, y, z + 6, 1.4f, 1.2f, 10, 45);
        DisplayCube(color_wood, x, y, z + 0.3f, 0.6f);
        DisplayCube(color_wood, x, y, z + 0.9f, 0.6f);
    }
};

class BuildingModel1 {
public:
    double x, y, z;
    GLfloat color_roof[4] = { 0.5f, 0.1f, 0.1f, 1 };
    GLfloat color_wall[4] = { 0.3f, 0.3f, 0.4f, 1 };
    BuildingModel1(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplayCone(color_roof, x, y, z + 2.4f, 2, 1.8f, 4, 45);
        DisplayCube(color_wall, x, y, z + 1.2f, 2.4f);
    }
};

class BuildingModel2 {
public:
    double x, y, z;
    GLfloat color_roof[4] = { 0.6f, 0.2f, 0.3f, 1 };
    GLfloat color_wall[4] = { 0.3f, 0.3f, 0.3f, 1 };
    BuildingModel2(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplayCone(color_roof, x, y, z + 1.5f, 2, 1.5f, 4, 45);
        DisplayCube(color_wall, x, y, z + 0.4f, 2.4f);
    }
};

class BuildingModel3 {
public:
    double x, y, z;
    GLfloat color_roof[4] = { 0.5f, 0.2f, 0.2f, 1 };
    GLfloat color_wall[4] = { 0.2f, 0.2f, 0.3f, 1 };
    BuildingModel3(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplayCone(color_roof, x, y, z + 4.8f, 2, 3, 4, 45);
        DisplayCone(color_roof, x-2.4f, y, z + 2.4f, 2, 1.5f, 4, 45);
        DisplayCone(color_roof, x, y-2.4f, z + 2.4f, 2, 1.5f, 4, 45);
        DisplayCube(color_wall, x-2.4f, y, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x, y-2.4f, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x, y, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x, y, z + 3.6f, 2.4f);
    }
};

class BuildingModel4 {
public:
    double x, y, z;
    GLfloat color_roof[4] = { 0.7f, 0.2f, 0.2f, 1 };
    GLfloat color_wall[4] = { 0.2f, 0.3f, 0.4f, 1 };
    BuildingModel4(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplayCone(color_roof, x, y, z + 8.6f, 2, 4, 4, 45);
        DisplayCube(color_wall, x, y, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x, y, z + 3.6f, 2.4f);
        DisplayCube(color_wall, x, y, z + 5, 2.4f);
        DisplayCube(color_wall, x, y, z + 7.4f, 2.4f);
    }
};

class BuildingModel5 {
public:
    double x, y, z;
    GLfloat color_roof[4] = { 0.4f, 0.1f, 0.1f, 1 };
    GLfloat color_wall[4] = { 0.3f, 0.3f, 0.4f, 1 };
    BuildingModel5(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplayCone(color_roof, x, y, z + 15.8f, 2, 5, 4, 45);
        DisplayCube(color_wall, x, y, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x, y, z + 3.6f, 2.4f);
        DisplayCube(color_wall, x, y, z + 5, 2.4f);
        DisplayCube(color_wall, x, y, z + 7.4f, 2.4f);
        DisplayCube(color_wall, x, y, z + 9.8f, 2.4f);
        DisplayCube(color_wall, x, y, z + 12.2f, 2.4f);
        DisplayCube(color_wall, x, y, z + 14.6f, 2.4f);
        DisplayCube(color_wall, x-2.4f, y, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x - 2.4f, y, z + 3.6f, 2.4f);
        DisplayCube(color_wall, x - 2.4f, y, z + 5, 2.4f);
        DisplayCube(color_wall, x - 2.4f, y, z + 7.4f, 2.4f);
        DisplayCube(color_wall, x - 2.4f, y, z + 9.8f, 2.4f);
        DisplayCube(color_wall, x, y-2.4f, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x, y - 2.4f, z + 3.6f, 2.4f);
        DisplayCube(color_wall, x, y - 2.4f, z + 5, 2.4f);
        DisplayCube(color_wall, x, y - 2.4f, z + 7.4f, 2.4f);
    }
};

class BuildingModel6 {
public:
    double x, y, z;
    GLfloat color_roof[4] = { 0.5f, 0.1f, 0.1f, 1 };
    GLfloat color_wall[4] = { 0.2f, 0.3f, 0.3f, 1 };
    BuildingModel6(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { }
    void Display() {
        DisplayCone(color_roof, x, y, z + 2.4f, 2, 1.5f, 4, 45);
        DisplayCone(color_roof, x-2.4f, y, z + 4.8f, 2, 2.5f, 4, 45);
        DisplayCone(color_roof, x+2.4f, y, z + 4.8f, 2, 2.5f, 4, 45);
        DisplayCube(color_wall, x, y, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x + 2.4f , y, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x - 2.4f, y, z + 1.2f, 2.4f);
        DisplayCube(color_wall, x + 2.4f, y, z + 3.6f, 2.4f);
        DisplayCube(color_wall, x - 2.4f, y, z + 3.6f, 2.4f);
    }
};



class TreeGeneral {
public:
    double x, y, z;
    TreeGeneral(double X, double Y, double Z)
        : x(X)
        , y(Y)
        , z(Z)
    { 

    }

    void Display() {
        
    }
};

class BuildingGeneral {
public:
    std::vector<BuildingModel1> building1;
    std::vector<BuildingModel2> building2;
    std::vector<BuildingModel3> building3;
    std::vector<BuildingModel4> building4;
    std::vector<BuildingModel5> building5;
    std::vector<BuildingModel6> building6;

    BuildingGeneral() { }

    void Display() {
        for (int i = 0; i < building1.size(); i++) {
            building1[i].Display();
        }
        for (int i = 0; i < building2.size(); i++) {
            building2[i].Display();
        }
        for (int i = 0; i < building3.size(); i++) {
            building3[i].Display();
        }
        for (int i = 0; i < building4.size(); i++) {
            building4[i].Display();
        }
        for (int i = 0; i < building5.size(); i++) {
            building5[i].Display();
        }
        for (int i = 0; i < building6.size(); i++) {
            building6[i].Display();
        }
    }
};




//The Scene

class Scene {
public:
    double x, y, z, size;

    GLfloat color_ground[4] = { 0, 0.4f, 0, 0.5f };
    GLfloat color_backgroud[4] = { 0, 0.3f, 0, 0.5f };
    GLfloat color_road[4] = { 0.2f, 0.2f, 0.2f, 1 };
    GLfloat color_sky[4] = { 0, 0.5f, 1, 1 };

    std::vector<TreeModel1> tree1;
    std::vector<TreeModel2> tree2;
    std::vector<TreeModel3> tree3;
    std::vector<TreeModel4> tree4;

    std::vector<BuildingModel1> building1;
    std::vector<BuildingModel2> building2;
    std::vector<BuildingModel3> building3;
    std::vector<BuildingModel4> building4;
    std::vector<BuildingModel5> building5;
    std::vector<BuildingModel6> building6;

    Scene(double X, double Y, double Z, double S)
        : x(X)
        , y(Y)
        , z(Z)
        , size(S)
    {
        //Add the objects to the scene
        //Trees
        tree1.push_back(TreeModel1(-15, -18, -30));
        tree1.push_back(TreeModel1(-15, -15, -30));
        tree1.push_back(TreeModel1(-15, -12, -30));
        tree1.push_back(TreeModel1(3, 22, -30));
        tree1.push_back(TreeModel1(3, 25, -30));
        tree1.push_back(TreeModel1(3, 28, -30));
        tree1.push_back(TreeModel1(6, 28, -30));
        tree1.push_back(TreeModel1(9, 28, -30));
        tree1.push_back(TreeModel1(12, 28, -30));
        tree1.push_back(TreeModel1(15, 28, -30));
        tree1.push_back(TreeModel1(18, 28, -30));
        tree1.push_back(TreeModel1(21, 28, -30));
        tree1.push_back(TreeModel1(21, 25, -30));
        tree1.push_back(TreeModel1(18, 25, -30));
        tree1.push_back(TreeModel1(15, 25, -30));
        tree1.push_back(TreeModel1(12, 25, -30));
        tree1.push_back(TreeModel1(9, 25, -30));
        tree1.push_back(TreeModel1(6, 25, -30));
        tree1.push_back(TreeModel1(25, -23, -30));
        tree1.push_back(TreeModel1(25, -19, -30));
        tree1.push_back(TreeModel1(25, -15, -30));
        tree1.push_back(TreeModel1(25, -11, -30));
        tree1.push_back(TreeModel1(25, -7, -30));
        tree2.push_back(TreeModel2(-15, -1, -30));
        tree2.push_back(TreeModel2(10, 6, -30));
        tree2.push_back(TreeModel2(6, 4, -30));
        tree2.push_back(TreeModel2(3, 4, -30));
        tree2.push_back(TreeModel2(4, 2, -30));
        tree2.push_back(TreeModel2(-15, -8, -30));
        tree2.push_back(TreeModel2(-12, -8, -30));
        tree2.push_back(TreeModel2(-15, 22, -30));
        tree2.push_back(TreeModel2(-15, 25, -30));
        tree2.push_back(TreeModel2(-15, 28, -30));
        tree2.push_back(TreeModel2(-3, 22, -30));
        tree2.push_back(TreeModel2(-3, 25, -30));
        tree2.push_back(TreeModel2(-3, 28, -30));
        tree2.push_back(TreeModel2(-24, -2, -30));
        tree2.push_back(TreeModel2(-27, -2, -30));
        tree2.push_back(TreeModel2(-27, -6, -30));
        tree2.push_back(TreeModel2(-24, -6, -30));
        tree2.push_back(TreeModel2(-24, -10, -30));
        tree2.push_back(TreeModel2(-27, -10, -30));
        tree3.push_back(TreeModel3(-5, 2, -30));
        tree3.push_back(TreeModel3(-8, 2, -30));
        tree3.push_back(TreeModel3(-11, 2, -30));
        tree3.push_back(TreeModel3(-14, 2, -30));
        tree3.push_back(TreeModel3(-17, 2, -30));
        tree3.push_back(TreeModel3(-17, 5, -30));
        tree3.push_back(TreeModel3(-14, 5, -30));
        tree3.push_back(TreeModel3(-11, 5, -30));
        tree3.push_back(TreeModel3(-8, 5, -30));
        tree3.push_back(TreeModel3(-7, -8, -30));
        tree3.push_back(TreeModel3(-7, -11, -30));
        tree3.push_back(TreeModel3(-7, -14, -30));
        tree3.push_back(TreeModel3(-5, -12, -30));
        tree3.push_back(TreeModel3(-5, -15, -30));
        tree3.push_back(TreeModel3(-5, -18, -30));
        tree3.push_back(TreeModel3(-7, -17, -30));
        tree3.push_back(TreeModel3(-21, -13, -30));
        tree3.push_back(TreeModel3(2, -19, -30));
        tree3.push_back(TreeModel3(2, -16, -30));
        tree3.push_back(TreeModel3(5, -16, -30));
        tree3.push_back(TreeModel3(8, -16, -30));
        tree3.push_back(TreeModel3(11, -16, -30));
        tree3.push_back(TreeModel3(11, -13, -30));
        tree3.push_back(TreeModel3(14, -13, -30));
        tree3.push_back(TreeModel3(17, -13, -30));
        tree3.push_back(TreeModel3(2, 13, -30));
        tree3.push_back(TreeModel3(8, 15, -30));
        tree3.push_back(TreeModel3(8, 17, -30));
        tree3.push_back(TreeModel3(10, 10, -30));
        tree3.push_back(TreeModel3(10, 8, -30));
        tree3.push_back(TreeModel3(12, 8, -30));
        tree3.push_back(TreeModel3(14, 8, -30));
        tree3.push_back(TreeModel3(16, 8, -30));
        tree3.push_back(TreeModel3(8, 7, -30));
        tree3.push_back(TreeModel3(6, 7, -30));
        tree3.push_back(TreeModel3(4, 7, -30));
        tree3.push_back(TreeModel3(2, 7, -30));
        tree3.push_back(TreeModel3(8, -10, -30));
        tree3.push_back(TreeModel3(8, -7, -30));
        tree3.push_back(TreeModel3(11, -7, -30));
        tree3.push_back(TreeModel3(14, -7, -30));
        tree3.push_back(TreeModel3(17, -7, -30));
        tree3.push_back(TreeModel3(16, -4, -30));
        tree3.push_back(TreeModel3(-2, -13, -30));
        tree3.push_back(TreeModel3(-9, -16, -30));
        tree3.push_back(TreeModel3(-9, -13, -30));
        tree3.push_back(TreeModel3(-9, -9, -30));
        tree3.push_back(TreeModel3(-13, -16, -30));
        tree3.push_back(TreeModel3(-8, -19, -30));
        tree3.push_back(TreeModel3(-6, -20, -30));
        tree3.push_back(TreeModel3(-13, -19, -30));
        tree3.push_back(TreeModel3(-13, -10, -30));
        tree3.push_back(TreeModel3(2, -10, -30));
        tree3.push_back(TreeModel3(2, -4, -30));
        tree3.push_back(TreeModel3(-4, -1, -30));
        tree3.push_back(TreeModel3(-17, 8, -30));
        tree3.push_back(TreeModel3(-17, 11, -30));
        tree3.push_back(TreeModel3(-17, 14, -30));
        tree3.push_back(TreeModel3(-17, 17, -30));
        tree3.push_back(TreeModel3(-15, 17, -30));
        tree3.push_back(TreeModel3(-13, 17, -30));
        tree3.push_back(TreeModel3(-11, 17, -30));
        tree3.push_back(TreeModel3(-9, 17, -30));
        tree3.push_back(TreeModel3(-7, 17, -30));
        tree3.push_back(TreeModel3(-5, 17, -30));
        tree3.push_back(TreeModel3(-3, 17, -30));
        tree3.push_back(TreeModel3(-1, 17, -30));
        tree3.push_back(TreeModel3(-11, 11, -30));
        tree3.push_back(TreeModel3(-9, 11, -30));
        tree3.push_back(TreeModel3(-7, 11, -30));
        tree3.push_back(TreeModel3(-5, 11, -30));
        tree3.push_back(TreeModel3(-3, 11, -30));
        tree3.push_back(TreeModel3(-1, 11, -30));
        tree3.push_back(TreeModel3(-12, 29, -30));
        tree3.push_back(TreeModel3(-10, 29, -30));
        tree3.push_back(TreeModel3(-8, 29, -30));
        tree3.push_back(TreeModel3(-6, 29, -30));
        tree3.push_back(TreeModel3(-6, 27, -30));
        tree3.push_back(TreeModel3(-6, 25, -30));
        tree3.push_back(TreeModel3(-12, 25, -30));
        tree3.push_back(TreeModel3(-12, 27, -30));
        tree3.push_back(TreeModel3(-25, 22, -30));
        tree3.push_back(TreeModel3(-25, 25, -30));
        tree3.push_back(TreeModel3(-27, -13, -30));
        tree3.push_back(TreeModel3(-24, -13, -30));
        tree3.push_back(TreeModel3(-26, -20, -30));
        tree3.push_back(TreeModel3(-28, -19, -30));
        tree3.push_back(TreeModel3(-28, -22, -30));
        tree3.push_back(TreeModel3(-28, -25, -30));
        tree3.push_back(TreeModel3(-28, -28, -30));
        tree3.push_back(TreeModel3(-26, -28, -30));
        tree3.push_back(TreeModel3(-26, -25, -30));
        tree3.push_back(TreeModel3(-24, -23, -30));
        tree3.push_back(TreeModel3(-24, -26, -30));
        tree3.push_back(TreeModel3(-21, -26, -30));
        tree3.push_back(TreeModel3(-23, -28, -30));
        tree3.push_back(TreeModel3(-19, -28, -30));
        tree4.push_back(TreeModel4(-11, -11, -30));
        tree4.push_back(TreeModel4(-11, -14, -30));
        tree4.push_back(TreeModel4(-11, -18, -30));
        tree4.push_back(TreeModel4(-9, 26, -30));
        tree4.push_back(TreeModel4(-19, 28, -30));
        tree4.push_back(TreeModel4(-22, 28, -30));
        tree4.push_back(TreeModel4(-25, 28, -30));
        tree4.push_back(TreeModel4(-28, 28, -30));
        tree4.push_back(TreeModel4(-28, 25, -30));
        tree4.push_back(TreeModel4(-28, 22, -30));
        tree4.push_back(TreeModel4(-28, 19, -30));
        tree4.push_back(TreeModel4(-28, 16, -30));
        tree4.push_back(TreeModel4(-28, 13, -30));
        tree4.push_back(TreeModel4(-28, 10, -30));
        tree4.push_back(TreeModel4(-28, 7, -30));
        tree4.push_back(TreeModel4(-28, 4, -30));
        tree4.push_back(TreeModel4(-24, 16, -30));
        tree4.push_back(TreeModel4(-24, 19, -30));
        tree4.push_back(TreeModel4(25, 6, -30));
        tree4.push_back(TreeModel4(28, 6, -30));
        tree4.push_back(TreeModel4(28, 2, -30));
        tree4.push_back(TreeModel4(28, 10, -30));
        tree4.push_back(TreeModel4(28, 14, -30));
        tree4.push_back(TreeModel4(28, 18, -30));
        tree4.push_back(TreeModel4(28, 22, -30));
        tree4.push_back(TreeModel4(28, 26, -30));
        tree4.push_back(TreeModel4(25, 26, -30));
        tree4.push_back(TreeModel4(25, 22, -30));
        tree4.push_back(TreeModel4(25, 18, -30));
        tree4.push_back(TreeModel4(25, 14, -30));
        tree4.push_back(TreeModel4(25, 10, -30));
        tree4.push_back(TreeModel4(28, -3, -30));
        tree4.push_back(TreeModel4(28, -7, -30));
        tree4.push_back(TreeModel4(28, -11, -30));
        tree4.push_back(TreeModel4(28, -15, -30));
        tree4.push_back(TreeModel4(28, -19, -30));
        tree4.push_back(TreeModel4(28, -23, -30));
        tree4.push_back(TreeModel4(28, -27, -30));
        tree4.push_back(TreeModel4(25, -27, -30));
        tree4.push_back(TreeModel4(22, -27, -30));
        tree4.push_back(TreeModel4(19, -27, -30));
        tree4.push_back(TreeModel4(16, -27, -30));
        tree4.push_back(TreeModel4(13, -27, -30));
        tree4.push_back(TreeModel4(-16, -28, -30));
        tree4.push_back(TreeModel4(-13, -28, -30));
        tree4.push_back(TreeModel4(-10, -28, -30));
        tree4.push_back(TreeModel4(-6, -28, -30));
        tree4.push_back(TreeModel4(-2, -28, -30));
        tree4.push_back(TreeModel4(2, -28, -30));
        tree4.push_back(TreeModel4(6, -28, -30));
        
        //Buildings
        building1.push_back(BuildingModel1(-2, -16, -30));
        building1.push_back(BuildingModel1(-21, -2, -30));
        building1.push_back(BuildingModel1(-21, -10, -30));
        building1.push_back(BuildingModel1(-13, -24, -30));
        building1.push_back(BuildingModel1(-5, -24, -30));
        building1.push_back(BuildingModel1(13, -24, -30));
        building1.push_back(BuildingModel1(17, -24, -30));
        building1.push_back(BuildingModel1(21, -20, -30));
        building1.push_back(BuildingModel1(21, -12, -30));
        building1.push_back(BuildingModel1(12, 1, -30));
        building1.push_back(BuildingModel1(9, -1, -30));
        building1.push_back(BuildingModel1(9, 3, -30));
        building1.push_back(BuildingModel1(-2, 8, -30));
        building1.push_back(BuildingModel1(-5, 8, -30));
        building1.push_back(BuildingModel1(-8, 8, -30));
        building1.push_back(BuildingModel1(-11, 8, -30));
        building1.push_back(BuildingModel1(-14, 8, -30));
        building1.push_back(BuildingModel1(-21, 16, -30));
        building1.push_back(BuildingModel1(-21, 20, -30));
        building1.push_back(BuildingModel1(21, 16, -30));
        building1.push_back(BuildingModel1(21, 13, -30));
        building1.push_back(BuildingModel1(21, 10, -30));
        building2.push_back(BuildingModel2(-21, -6, -30));
        building2.push_back(BuildingModel2(-17, -24, -30));
        building2.push_back(BuildingModel2(-9, -24, -30));
        building2.push_back(BuildingModel2(21, -24, -30));
        building2.push_back(BuildingModel2(21, -16, -30));
        building2.push_back(BuildingModel2(21, -8, -30));
        building2.push_back(BuildingModel2(21, -6, -30));
        building2.push_back(BuildingModel2(-2, 15, -30));
        building2.push_back(BuildingModel2(-5, 15, -30));
        building2.push_back(BuildingModel2(-8, 15, -30));
        building2.push_back(BuildingModel2(-11, 15, -30));
        building2.push_back(BuildingModel2(-14, 15, -30));
        building2.push_back(BuildingModel2(-19, 24, -30));
        building2.push_back(BuildingModel2(-23, 24, -30));
        building2.push_back(BuildingModel2(0, 22, -30));
        building2.push_back(BuildingModel2(0, 25, -30));
        building2.push_back(BuildingModel2(0, 28, -30));
        building3.push_back(BuildingModel3(-21, -20, -30));
        building3.push_back(BuildingModel3(9, -24, -30));
        building3.push_back(BuildingModel3(16, -16, -30));
        building3.push_back(BuildingModel3(16, 17, -30));
        building3.push_back(BuildingModel3(12, 13, -30));
        building3.push_back(BuildingModel3(16, 5, -30));
        building3.push_back(BuildingModel3(-21, 6, -30));
        building3.push_back(BuildingModel3(-21, 12, -30));
        building3.push_back(BuildingModel3(21, 22, -30));
        building4.push_back(BuildingModel4(-2, -1, -30));
        building4.push_back(BuildingModel4(-2, -20, -30));
        building4.push_back(BuildingModel4(13, -19, -30));
        building4.push_back(BuildingModel4(21, 6, -30));
        building4.push_back(BuildingModel4(15, 11, -30));
        building4.push_back(BuildingModel4(10, 17, -30));
        building4.push_back(BuildingModel4(15, -1, -30));
        building4.push_back(BuildingModel4(-14, 11, -30));
        building4.push_back(BuildingModel4(-24, 9, -30));
        building4.push_back(BuildingModel4(-24, 3, -30));
        building4.push_back(BuildingModel4(15, 22, -30));
        building5.push_back(BuildingModel5(-2, 5, -30));
        building5.push_back(BuildingModel5(-2, -8, -30));
        building5.push_back(BuildingModel5(5, -1, -30));
        building5.push_back(BuildingModel5(5, 16, -30));
        building5.push_back(BuildingModel5(5, -7, -30));
        building6.push_back(BuildingModel6(-4, -5, -30));
        building6.push_back(BuildingModel6(-9, -1, -30));
        building6.push_back(BuildingModel6(-13, -5, -30));
        building6.push_back(BuildingModel6(-23, -16, -30));
        building6.push_back(BuildingModel6(1, -24, -30));
        building6.push_back(BuildingModel6(7, -19, -30));
        building6.push_back(BuildingModel6(23, -3, -30));
        building6.push_back(BuildingModel6(23, 2, -30));
        building6.push_back(BuildingModel6(5, 10, -30));
        building6.push_back(BuildingModel6(6, -13, -30));
        building6.push_back(BuildingModel6(13, -10, -30));
        building6.push_back(BuildingModel6(11, -4, -30));
        building6.push_back(BuildingModel6(-9, 22, -30));

    }

    void Display() {
        //the roads
        DisplayQuad(color_road, -30, 1, -30 + 0.02f, -18, 0, -30 + 0.02f);
        DisplayQuad(color_road, -19, -22, -30 + 0.02f, -18, 20, -30 + 0.02f);
        DisplayQuad(color_road, -19, -22, -30 + 0.02f, 19, -21, -30 + 0.02f);
        DisplayQuad(color_road, 18, -22, -30 + 0.02f, 19, 20, -30 + 0.02f);
        DisplayQuad(color_road, -19, 19, -30 + 0.02f, 19, 20, -30 + 0.02f);
        DisplayQuad(color_road, 18, -1, -30 + 0.02f, 30, 0, -30 + 0.02f);
        DisplayQuad(color_road, 0, -22, -30 + 0.02f, 1, 20, -30 + 0.02f);

        //general landscape
        DisplayCone(color_backgroud, -30 + 0.01f, 10, 0 - 30, 30, 20, 2, 0);
        DisplayCone(color_backgroud, -30 + 0.01f, -20, 0 - 30, 30, 15, 2, 0);
        DisplayCone(color_backgroud, -15, -30 + 0.01f, 0 - 30, 30, 20, 2, 90);
        DisplayCone(color_backgroud, 15, -30 + 0.01f, 0 - 30, 30, 15, 2, 90);
        DisplayCone(color_backgroud, 30 - 0.01f, -11, 0 - 30, 30, 20, 2, 0);
        DisplayCone(color_backgroud, 30 - 0.01f, 15, 0 - 30, 30, 15, 2, 0);
        DisplayCone(color_backgroud, -10, 30 - 0.01f, 0 - 30, 30, 20, 2, 90);
        DisplayCone(color_backgroud, 15, 30 - 0.01f, 0 - 30, 30, 15, 2, 90);
        DisplayQuad(color_ground, -30, -30, -30 + 0.01f, 30, 30, -30 + 0.01f);
        DisplayCube(color_sky, 0, 0, 0, 60);

        //trees
        for (int i = 0; i < tree1.size(); i++) {
            tree1[i].Display();
        }
        for (int i = 0; i < tree2.size(); i++) {
            tree2[i].Display();
        }
        for (int i = 0; i < tree3.size(); i++) {
            tree3[i].Display();
        }
        for (int i = 0; i < tree4.size(); i++) {
            tree4[i].Display();
        }
        
        //buildings
        for (int i = 0; i < building1.size(); i++) {
            building1[i].Display();
        }
        for (int i = 0; i < building2.size(); i++) {
            building2[i].Display();
        }
        for (int i = 0; i < building3.size(); i++) {
            building3[i].Display();
        }
        for (int i = 0; i < building4.size(); i++) {
            building4[i].Display();
        }
        for (int i = 0; i < building5.size(); i++) {
            building5[i].Display();
        }
        for (int i = 0; i < building6.size(); i++) {
            building6[i].Display();
        }
    }

    void Clear() {
        building1.clear();
        building2.clear();
        building3.clear();
        building4.clear();
        building5.clear();
        building6.clear();

        tree1.clear();
        tree2.clear();
        tree3.clear();
        tree4.clear();
    }

    void AddNewObject(int selectObject, int xObject, int yObject) {
        switch (selectObject) {
        case 1:
            building1.push_back(BuildingModel1(xObject, yObject, -30));
            break;
        case 2:
            building2.push_back(BuildingModel2(xObject, yObject, -30));
            break;
        case 3:
            building3.push_back(BuildingModel3(xObject, yObject, -30));
            break;
        case 4:
            building4.push_back(BuildingModel4(xObject, yObject, -30));
            break;
        case 5:
            building5.push_back(BuildingModel5(xObject, yObject, -30));
            break;
        case 6:
            building6.push_back(BuildingModel6(xObject, yObject, -30));
            break;
        case 7:
            tree1.push_back(TreeModel1(xObject, yObject, -30));
            break;
        case 8:
            tree2.push_back(TreeModel2(xObject, yObject, -30));
            break;
        case 9:
            tree3.push_back(TreeModel3(xObject, yObject, -30));
            break;
        case 10:
            tree4.push_back(TreeModel4(xObject, yObject, -30));
            break;
        }
    }

    void DisplayObjectsInfo() {
        //trees
        std::cout << " - TREES - #" << tree1.size() + tree2.size() + tree3.size() + tree4.size() << std::endl;
        for (int i = 0; i < tree1.size(); i++) {
            std::cout << " - Tree 1 - #" << i+1 << " -> " << tree1[i].x << " " << tree1[i].y << std::endl;
        }
        for (int i = 0; i < tree2.size(); i++) {
            std::cout << " - Tree 2 - #" << i+1 << " -> " << tree2[i].x << " " << tree2[i].y << std::endl;
        }
        for (int i = 0; i < tree3.size(); i++) {
            std::cout << " - Tree 3 - #" << i+1 << " -> " << tree3[i].x << " " << tree3[i].y << std::endl;
        }
        for (int i = 0; i < tree4.size(); i++) {
            std::cout << " - Tree 4 - #" << i+1 << " -> " << tree4[i].x << " " << tree4[i].y << std::endl;
        }

        //buildings
        std::cout << " - BUILDINGS - #" << building1.size() + building2.size() + building3.size() + building4.size() + building5.size() + building6.size() << std::endl;
        for (int i = 0; i < building1.size(); i++) {
            std::cout << " - Building 1 - #" << i+1 << " -> " << building1[i].x << " " << building1[i].y << std::endl;
        }
        for (int i = 0; i < building2.size(); i++) {
            std::cout << " - Building 2 - #" << i+1 << " -> " << building2[i].x << " " << building2[i].y << std::endl;
        }
        for (int i = 0; i < building3.size(); i++) {
            std::cout << " - Building 3 - #" << i+1 << " -> " << building3[i].x << " " << building3[i].y << std::endl;
        }
        for (int i = 0; i < building4.size(); i++) {
            std::cout << " - Building 4 - #" << i+1 << " -> " << building4[i].x << " " << building4[i].y << std::endl;
        }
        for (int i = 0; i < building5.size(); i++) {
            std::cout << " - Building 5 - #" << i+1 << " -> " << building5[i].x << " " << building5[i].y << std::endl;
        }
        for (int i = 0; i < building6.size(); i++) {
            std::cout << " - Building 6 - #" << i+1 << " -> " << building6[i].x << " " << building6[i].y << std::endl;
        }
    }

    void DeleteLastEntry(int selectObject) {
        switch (selectObject) {
        case 1:
            building1.pop_back();
            break;
        case 2:
            building2.pop_back();
            break;
        case 3:
            building3.pop_back();
            break;
        case 4:
            building4.pop_back();
            break;
        case 5:
            building5.pop_back();
            break;
        case 6:
            building6.pop_back();
            break;
        case 7:
            tree1.pop_back();
            break;
        case 8:
            tree2.pop_back();
            break;
        case 9:
            tree3.pop_back();
            break;
        case 10:
            tree4.pop_back();
            break;
        }
    }
};