#include <iostream>
#include <string>

void check_mode(const std::string& s) {
    const void* obj_addr = static_cast<const void*>(&s);
    const void* data_addr = static_cast<const void*>(s.data());

    std::cout << "toxy: \"" << s << "\" (size: " << s.size() << ")\n";
    std::cout << " obyekti hasce:  " << obj_addr << "\n";
    std::cout << " tvyalneri hasce: " << data_addr << "\n\n";
}

int main() {
    std::string short_str = "Hello";
    std::string long_str = "C++ standard library string optimization (SSO) test string for heap allocation!";

    std::cout << "--- karch ---\n";
    check_mode(short_str);

    std::cout << "--- erkar ---\n";
    check_mode(long_str);

    return 0;
}
