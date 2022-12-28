#include "TimeManager.h"

TimeManager& TimeManager::getInstance()
{

    static TimeManager instance;
    return instance;
}

void TimeManager::NextFrame()
{
    frameCount++;
    //el tiempo que ha transcurrido
    auto elapsedTime = std::chrono::high_resolution_clock::now() - start;

    deltaTime = (float)std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count();
    //me aparezca por segundo y no en milisegundos
    deltaTime /= 1000.0f;

    time += deltaTime;

    start = std::chrono::high_resolution_clock::now();

}


