#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "tvp.hpp"
#include <cstdio>

//TODO implement this functions for part 2
glm::mat4 myLookAt(const glm::vec3 eye, const glm::vec3 center, const glm::vec3 up)
{
    //TODO:your look at definition
    glm::vec3 cameraPos = eye;
    glm::vec3 cameraTarget = center;
    glm::vec3 up_sample = up;
    glm::vec3 z = glm::normalize(cameraPos - cameraTarget);
    glm::vec3 x = glm::normalize(glm::cross(up_sample,z));
    glm::vec3 y = glm::normalize(glm::cross(z,x));

    glm::mat4 result;

    glm::vec4 cx4 = glm::vec4(x.x,y.x,z.x,0.0f);
    glm::vec4 cy4 = glm::vec4(x.y,y.y,z.y,0.0f);
    glm::vec4 cz4 = glm::vec4(x.z,y.z,z.z,0.0f);
    glm::vec4 cw4 = glm::vec4(0.0f,0.0f,0.0f,1.0f);

    glm::mat4 translation;
    translation[3][0] = -eye.x;
    translation[3][1] = -eye.y;
    translation[3][2] = -eye.z;

    result[0] = cx4;
    result[1] = cy4;
    result[2] = cz4;
    result[3] = cw4;

    return result * translation;
}

glm::mat4 getViewMatrix(){

    //TODO call your lookAt function here

    //Camera at (0, 0, 100) looking down the negative Z-axis in a right handed coordinate system
//    printf("hey");
    glm::mat4 r = myLookAt(glm::vec3(100.0f,100.0f,100.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0, 1.0, 0.0));
//    glm::mat4 r =  glm::lookAt(glm::vec3(0.0,0.0,100.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            printf("%f ",r[i][j]);
        printf("\n");
    }

    return  r;

}

//TODO change projection matrix here
glm::mat4 getProjectionMatrix(float aspect, float height, float width) {
    float view_height = 100.0f;
//    glm::mat4 projection = glm::ortho(-view_height*aspect/2.0f, view_height*aspect/2.0f, -view_height/2.0f, view_height/2.0f, 0.1f, 1000.0f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 1000.0f);
//    projection = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 1000.0f);
    return projection;
}
