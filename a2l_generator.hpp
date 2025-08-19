#ifndef A2L_GENERATOR_HPP
#define A2L_GENERATOR_HPP

#include <string>
#include <vector>

struct Variable {
    std::string name;
    std::string datatype;
    double minVal;
    double maxVal;
    std::string unit;
};

class A2LGenerator {
public:
    A2LGenerator(const std::string& ecuName);
    void addVariable(const Variable& var);
    void generate(const std::string& filename) const;

private:
    std::string ecuName;
    std::vector<Variable> variables;
};

#endif
