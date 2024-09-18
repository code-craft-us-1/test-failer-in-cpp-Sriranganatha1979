#include <assert.h>
#include <iostream>
#include <string>


const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);


std::string formatColorMap(int colorCode, const char* majorColor, const char* minorColor) {
        std::string combinedColors = 
            std::to_string(colorCode) + " | " + majorColor + " | " + minorColor + "\n";
        return combinedColors;
}

int GetPairNumberFromColor(int majorIndex, int minorIndex) {
    return majorIndex * 5 + minorIndex;
}

int printColorMap() {
    char combinedColors[100];
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int pairNumber = GetPairNumberFromColor(i, j);
            std::cout << formatColorMap(pairNumber, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(formatColorMap(1, "Red", "Blue")[3] == '|');
    assert(GetPairNumberFromColor(0, 0) == 1);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
