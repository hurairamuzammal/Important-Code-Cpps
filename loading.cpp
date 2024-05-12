#include <iostream>
#include <chrono>
#include <thread>

int main() {
    int animationDelay = 100; // Delay between each frame in milliseconds
    int numFrames = 10; // Number of frames in the animation

    for (int i = 0; i <= numFrames; i++) {
        // Clear the screen
        system("cls");

        // Display the loading text
        std::cout << "Loading...\n";

        // Display the loading animation
        std::cout << "[";
        for (int j = 0; j < i; j++) {
            std::cout << "=";
        }
        std::cout << ">";

        for (int j = i; j < numFrames; j++) {
            std::cout << "-";
        }
        std::cout << "]\n";

        // Display the percentage
        int percentage = (i * 100) / numFrames;
        std::cout << percentage << "%\n";

        // Sleep for the specified delay
        std::this_thread::sleep_for(std::chrono::milliseconds(animationDelay));
    }

    // Clear the screen after the animation is complete
    system("cls");

    // Display a completion message
    std::cout << "Loading complete!" << std::endl;

    return 0;
}