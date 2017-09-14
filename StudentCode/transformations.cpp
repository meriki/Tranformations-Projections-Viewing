
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//TODO implement these functions for part 1
glm::mat4 rotateAroundZ(glm::mat4 model){

    glm::mat4 rotatez = glm::rotate(model, glm::radians(15.0f), glm::vec3(0.0f,0.0f,1.0f));
    return rotatez;

}
glm::mat4 scaleAlongY(glm::mat4 model){

    glm::mat4 scaley = glm::scale(model,glm::vec3(1.0f,2.0f,1.0f));
    return scaley;

}
glm::mat4 translateAlongXY(glm::mat4 model){

    glm::mat4 translatexy = glm::translate(model,glm::vec3(20.0f,10.0f,0.0f));
    return translatexy;

}

glm::mat4 composeOrder1(glm::mat4 model){
    model = rotateAroundZ(model);
    model = scaleAlongY(model);
    model = translateAlongXY(model);
    return model;

}
glm::mat4 composeOrder2(glm::mat4 model){
    model = translateAlongXY(model);
    model = scaleAlongY(model);
    model = rotateAroundZ(model);
    return model;

}


glm::mat4 getModelMatrix(float angle,glm::vec3 axis)
{
    //Modelling transformations (Model -> World coordinates)
    glm::mat4 model = glm::mat4(1.0);
    model = glm::rotate(model,angle,glm::vec3(axis[0],axis[1],axis[2]));
    //    TODO: use the above functions here
    //    model = rotateAroundZ(model);
    //    model = scaleAlongY(model);
    //    model = translateAlongXY(model);
    //    model = composeOrder1();
    //    model = composeOrder2();

    return model;

}
