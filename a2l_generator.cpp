#include "a2l_generator.hpp"
#include <fstream>
#include <iostream>

A2LGenerator::A2LGenerator(const std::string& ecuName) : ecuName(ecuName) {}

void A2LGenerator::addVariable(const Variable& var) {
    variables.push_back(var);
}

void A2LGenerator::generate(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing.\n";
        return;
    }

    file << "/begin PROJECT " << ecuName << " \"Demo ECU\"\n";
    file << "  /begin MODULE " << ecuName << "_module \"Demo Module\"\n";

    for (const auto& var : variables) {
        file << "    /begin MEASUREMENT " << var.name << "\n";
        file << "      \"" << var.name << " variable\"\n";
        file << "      " << var.datatype << " "
             << var.minVal << " " << var.maxVal
             << " \"" << var.unit << "\"\n";
        file << "    /end MEASUREMENT\n";
    }

    file << "  /end MODULE\n";
    file << "/end PROJECT\n";
    file.close();

    std::cout << "Generated A2L file: " << filename << "\n";
}
