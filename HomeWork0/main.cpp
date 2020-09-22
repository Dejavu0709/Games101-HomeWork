#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

int main()
{
    Eigen::Vector3f p(2.0f,1.0f,1.0f);
    Eigen::Matrix3f rotateMatrix;
    rotateMatrix << cos(45.0/180.0 * acos(-1)), -sin(45.0/180.0 * acos(-1)), 0, sin(45.0/180.0 * acos(-1)), cos(45.0/180.0 * acos(-1)), 0, 0, 0, 1;
    Eigen::Matrix3f translateMatrix;
    translateMatrix << 1,0,1,0,1,2,0,0,1;
    Eigen::Vector3f res = translateMatrix * rotateMatrix * p;
    std::cout << "Result :\n" << res << std::endl;
    return 0;
}


// private void Transform()
// {
//     Vector3f p(1.0f,2.0f,1.0f);
//     matrix p;
//     p << 2,1,0;
//     matrix3f rotateMatrix;
//     rotateMatrix << cos(45.0), -sin(45.0), 0, sin(45.0), cos(45.0), 0, 0, 0, 1;
//     matrix3f translateMatrix;
//     translateMatrix << 1,0,1,0,1,2,0,0,1;
//     Vector3f res = translateMatrix * rotateMatrix * p;
//     std::cout << "Result :" << res;
// }