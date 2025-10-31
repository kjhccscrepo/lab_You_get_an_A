#ifndef STUDENTS_H
#define STUDENTS_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "assignments.hpp"
class student {
private:
    std::vector<assignment> myAssignments;
    std::string ID_num;
    std::string myName;
    [[nodiscard]] int does_assignment_exist(const assignment &assignment_to_check) const;
    [[nodiscard]] int does_assignment_exist(const std::string &assignment_to_check) const;
public:
    explicit student(const std::string& name, const std::string &id);
    void newName(const std::string& newName);
    void newAssignment(const assignment& assignment_to_add);
    void setGradeForAssignment(const assignment& assignment_target, const int &grade);
    [[nodiscard]] std::vector<assignment> getAssignments() const;
    [[nodiscard]] std::string getStudentName() const;
    [[nodiscard]] std::string getID() const;
    [[nodiscard]] bool is_assigned(const assignment &assignment_to_check) const;
    [[nodiscard]] bool is_assigned(const std::string &assignment_to_check) const;
    [[nodiscard]] std::string getFirstName() const;
};
#endif
