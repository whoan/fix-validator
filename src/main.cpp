#include <quickfix/DataDictionary.h>

int main() try {
  FIX::DataDictionary dictionary(std::cin);
  return 0;
} catch (const std::exception& ex) {
  std::cerr << ex.what() << std::endl;
  return 1;
}
