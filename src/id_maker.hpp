#ifndef ID_MAKER_HPP
#define ID_MAKER_HPP
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <sstream>
class ID_maker {
private:
    std::vector<std::string> takenID;
    static char intToAlphabet(const int &i);
public:
    explicit ID_maker();
    std::string generateID();
};
#endif