#include "Renderer.h"

#include <iostream>
#include <string>

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

// print error codes to console
static bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::string errorString;
        switch (error) {
			case 1280:
                errorString = "GL_INVALID_ENUM";
                break;
            case 1281:
                errorString = "GL_INVALID_VALUE";
				break;
            case 1282:
                errorString = "GL_INVALID_OPERATION";
				break;
            case 1283:
                errorString = "GL_STACK_OVERFLOW";
                break;
            case 1284:
                errorString = "GL_STACK_UNDERFLOW";
                break;
            case 1285:
                errorString = "GL_OUT_OF_MEMORY";
                break;
            default:
                errorString = "UNEXPECTED_ERROR: " + std::to_string(error);
        }

        std::cout << "[OpenGL Error] (" << errorString << "): " << function << " " << file << ":" << std::endl;
        return false;
    }
    return true;
}