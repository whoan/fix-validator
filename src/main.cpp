#include <quickfix/DataDictionary.h>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) try {
  if (argc > 1) {
    std::ifstream schema(argv[1], std::ios::binary);
    if (!schema.is_open()) {
      throw std::runtime_error("Error opening file: " + std::string(argv[1]));
    }
    FIX::DataDictionary dictionary(schema);
  } else {
    FIX::DataDictionary dictionary(std::cin);
  }
  return 0;
} catch (const std::exception& ex) {
  std::cerr << ex.what() << std::endl;
  if (std::string(ex.what()).find("Could not parse data dictionary stream") != std::string::npos) {
    std::cerr << "To see more details, run: xmllint --noout <document>.xml  # part of docbook-xml or libxml2-utils package" << std::endl;
  }
  return 1;
}
