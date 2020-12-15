// Copyright (c) 2020 Ryan Chung Kam Chung All rights reserved
//
// Created by Ryan Chung Kam Chung
// Created in December 20ew20
// Final version of magicNumber

#include <iostream>
#include <random>
#include <string>


int main() {
    //  this function sees if the user inputed the magic number

    std::string magic_number_string;
    int random_number;
    int magic_number;

    std::cout << "Guess the magic number (0-9)!" << std::endl;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    random_number = idist(rgen);

    while (true) {
        // Input
        std::cout << "Please enter your guess: ";
        std::cin >> magic_number_string;

        // Process
        try {
            magic_number = std::stoi(magic_number_string);

            if (magic_number == random_number) {
                // Output
                std::cout << "Nice! Your answer is right!" << std::endl;
                break;
            } else if (magic_number > random_number) {
                // Output
                std::cout << "Oops! Your guess is too high!" << std::endl;
            } else {
                // Output
                std::cout << "Oops! Your guess is too low!" << std::endl;
            }
        } catch (std::invalid_argument) {
            // Output
            std::cout << "This isn't an integer" << std::endl;
        }
    }
}
