#include <glad/glad.h>
#include <vector>
#include <glm/gtc/constants.hpp>
#include <algorithm>

#define PI 3.14

//TODO:create and draw torus here
//refer cube.cpp for example
void createTorusObject(GLuint &torusVAO){

    int maxn= 1000; // max precision
    int n=20;
    n=std::min(n,maxn-1);
    int N=20;
    N=std::min(N,maxn-1);
    int r = 1.0f;
    int R = 2.5f;
    float rr=1.5f*r;
    double dv=2*PI/n;
    double dw=2*PI/N;
    double v=0.0f;
    double w=0.0f;
// outer loop
    float torus[int(dv)][3];

    while(w<2*PI+dw)
    {
        v=0.0f;

        // inner loop
//        while(v<2*PI+dv)
//        {
//           torus[]     (
//                    (R+rr*std::cos(v))*std::cos(w)-(R+r*std::cos(v))*std::cos(w),
//                    (R+rr*std::cos(v))*std::sin(w)-(R+r*std::cos(v))*std::sin(w),
//                    (rr*std::sin(v)-r*std::sin(v)));
//            gl.glVertex3d((R+r*std::cos(v))*std::cos(w),
//                          (R+r*std::cos(v))*std::sin(w),
//                          r*std::sin(v));
//            gl.glNormal3d(
//                    (R+rr*std::cos(v+dv))*std::cos(w+dw)-(R+r*std::cos(v+dv))*std::cos(w+dw),
//                    (R+rr*std::cos(v+dv))*std::sin(w+dw)-(R+r*std::cos(v+dv))*std::sin(w+dw),
//                    rr*std::sin(v+dv)-r*std::sin(v+dv));
//            gl.glVertex3d((R+r*std::cos(v+dv))*std::cos(w+dw),
//                          (R+r*std::cos(v+dv))*std::sin(w+dw),
//                          r*std::sin(v+dv));
//            v+=dv;
//        } // inner loop
        w+=dw;
    } //outer

}

void drawTorus(GLuint &torusVAO,GLuint program){


}
