#include "HelperFunctions.h"
#include <glut.h>
#include <GL/gl.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <string>
#include <windows.h>
#include <Eigen/Core>

using namespace Eigen;

float getRandomInRange(int lower, int upper) {
    return lower + rand() % (upper - lower) + (float)rand() / RAND_MAX;
}

void CmdDisplay() {
    std::cout << std::endl << "\t==== Made By Barby Mircea-Alexandru ====" << std::endl;
    std::cout << std::endl << "\t==== GPS Exam Project ====" << std::endl<<std::endl;

    std::cout << std::endl << " ==== Controls ===="<<std::endl;
    std::cout << "\t- Left Arrow - Rotate Left / Move Object Left"<<std::endl;
    std::cout << "\t- Right Arrow - Rotate Right / Move Object Right" << std::endl;
    std::cout << "\t- Up Arrow - Rotate Upwards / Move Object Up" << std::endl;
    std::cout << "\t- Down Arrow - Rotate Downwards / Move Object Down" << std::endl;

    std::cout << "\t- Page Up - Move Up" << std::endl;
    std::cout << "\t- Page Down - Move Down" << std::endl;

    std::cout << "\t- Home - Move Left" << std::endl;
    std::cout << "\t- End - Move Right" << std::endl;

    std::cout << "\t- F1 - Zoom In" << std::endl;
    std::cout << "\t- F2 - Zoom Out" << std::endl;

    std::cout << "\t- Insert - Restore Camera Initial Position" << std::endl;

    std::cout << "\t- F3 - Show Info" << std::endl;
    std::cout << "\t- F7 - Activate/Deactivate Edit Mode" << std::endl;

    std::cout << "\t- F8 - Rotate Previous Object" << std::endl;
    std::cout << "\t- F9 - Rotate Next Object" << std::endl;

    std::cout << "\t- F10 - Place the Object" << std::endl;
    std::cout << "\t- F11 - Delete All Objects / Only the previous selected object when edit is on" << std::endl;
}