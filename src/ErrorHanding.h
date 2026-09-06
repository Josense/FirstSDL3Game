#pragma once
#include <iostream>
#include <ostream>
#include <string>

#include "SDL3/SDL_error.h"

#define ERROR_LOGGING

void CheckSDLError(const std::string& Action) {
#ifdef ERROR_LOGGING
    const char* Error { SDL_GetError() };
    if (*Error != '\0') {
        std::cout << Action << " Error: " << Error << std::endl;
        SDL_ClearError();
    }
#endif
}
