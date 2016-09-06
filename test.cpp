#include <iostream>
#include "speech_kit.cpp"

int main()
{
    system("python record.py output.wav");
    handling("./output.wav");
    return 0;
}
