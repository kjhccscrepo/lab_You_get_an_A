#include "students.hpp"
int student::does_assignment_exist(const assignment &assignment_to_check) const {
    for (int i = 0; i < myAssignments.size(); i++) {
        if (myAssignments[i].getName() == assignment_to_check.getName()) {
            return i;
        }
    }
    return -1;
}
student::student(const std::string &name, const std::string &id) {
    this->myName = name;
    this->ID_num = id;

}
void student::newName(const std::string &newName) {
    this->myName = newName;
}
void student::newAssignment(const assignment &assignment_to_add) {
    int i = does_assignment_exist(assignment_to_add);
    if (i < 0) {
        myAssignments.push_back(assignment_to_add);
    } else {
        std::cerr << "ERROR\n" << "Could not add " << assignment_to_add.getName() << " to " << myName << "'s assignment list, as it was already present in it!\n";
    }
}
void student::setGradeForAssignment(const assignment& assignment_target, const int &grade) {
    int i = does_assignment_exist(assignment_target);
    if (i >= 0) {
        myAssignments[i].setScore(grade);
    } else {
        std::cerr << "ERROR\n" << assignment_target.getName() << " was not found in " << myName << "'s assignment list!\n";
    }
}
std::vector<assignment> student::getAssignments() const {
    return myAssignments;
}
std::string student::getStudentName() const {
    return myName;
}
std::string student::getID() const {
    return ID_num;
}
bool student::is_assigned(const assignment &assignment_to_check) const {
    if (does_assignment_exist(assignment_to_check) >= 0) {
        return true;
    }
    return false;
}
std::string student::getFirstName() const {
    std::stringstream temp;
    temp << myName;
    std::string firstname;
    std::getline(temp, firstname);
    return firstname;
}