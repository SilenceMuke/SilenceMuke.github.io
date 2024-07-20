#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream inputFile("../_mkdocs.yml");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    std::regex pattern(R"(copyright:)");
    std::string replacement = R"(# $&)";
    std::string replacedContent = std::regex_replace(content, pattern, replacement);
    inputFile.close();
    std::ofstream outputFile("../mkdocs.yml");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }
    outputFile << replacedContent;
    outputFile.close();
    std::cout << "Replacement2 completed successfully." << std::endl;
    return 0;
}
