#include "assignments.hpp"
assignment::assignment(const std::string &name, const int &score) {
    this->myName = name;
    this->myPerfectScore = score;
    this->studentScore = 0;
}
void assignment::setScore(const int &newScore) {
    this->studentScore = newScore;
}
std::string assignment::getName() const {
    return this->myName;
}
float assignment::score() const {
    float n = studentScore;
    float d = myPerfectScore;
    return (n / d) * 100;
}

int assignment::value() {
    return this->myPerfectScore;
}

int assignment::score_raw() {
    return this->studentScore;
}
