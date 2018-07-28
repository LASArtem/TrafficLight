#include <stdio.h> //printf

#include "MainUnit/TrafficLight/Headers/TrafficLight.hpp"

int main()
{
    printf("\n\nmain: start:\n\n");
    TrafficLight tl;
    tl.execute();//

    printf("\n\nmain: end:\n\n");

    return 0;
}
