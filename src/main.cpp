#include <quickfix/DataDictionary.h>

int main() try {
  FIX::DataDictionary dictionary(std::cin);
  return 0;
} catch (const std::exception& ex) {
  std::cerr << ex.what() << std::endl;
  if (std::string(ex.what()).find("Could not parse data dictionary stream") != std::string::npos) {
    std::cerr << "To see more details, run: xmllint --noout <document>.xml  # part of docbook-xml package" << std::endl;
  }
  return 1;
}
