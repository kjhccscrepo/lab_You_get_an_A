#include "id_maker.hpp"

char ID_maker::intToAlphabet(const int &i) {
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i];
}
ID_maker::ID_maker() {
    srand(time(NULL));
}
std::string ID_maker::generateID() {
    std::stringstream ID;
    int L = ((rand() % 25) + 1);
    ID << intToAlphabet(L);
    int r = 0;
    for (int i = 0; i < 6; i++) {
        r = (rand() % 9);
        ID << std::to_string(r);
    }
    for (int i = 0; i < takenID.size(); i++) {
        if (ID.str() == takenID[i]) {
            return generateID();
        }
    }
    takenID.push_back(ID.str());
    return ID.str();
}
