#include "a2l_generator.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Demo ECU starting...\n";

    // Define some ECU variables
    double rpm = 1000.0;
    double throttle = 20.5;
    double ignition_timing = 5.0;

    // Generate A2L
    A2LGenerator generator("SampleECU");
    generator.addVariable({"rpm", "UWORD", 0, 8000, "rpm"});
    generator.addVariable({"throttle", "UWORD", 0, 100, "%"});
    generator.addVariable({"ignition_timing", "SWORD", -20, 40, "deg"});
    generator.generate("sample_cpp_demo.a2l");

    std::cout << "ECU running. Use CANape/INCA with sample_cpp_demo.a2l to connect.\n";

    // Simulate ECU loop
    for (int i = 0; i < 10; i++) {
        rpm += 100;
        throttle += 1.0;
        ignition_timing += 0.5;

        std::cout << "[ECU] rpm=" << rpm
                  << " throttle=" << throttle
                  << " ignition_timing=" << ignition_timing << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Demo ECU stopped.\n";
    return 0;
}
