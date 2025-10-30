#ifndef ASSIGNMENTS_HPP
#define ASSIGNMENTS_HPP
#include <string>
class assignment {
private:
    std::string myName;
    int myPerfectScore;
    int studentScore;
public:
    explicit assignment (const std::string& name, const int &score);
    void setScore(const int &newScore);
    std::string getName() const;
    float score() const;
    int value();
    int score_raw();
};
#endif