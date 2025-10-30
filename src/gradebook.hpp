#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP
#include <vector>
#include <string>
#include <sstream>
#include "students.hpp"
#include "assignments.hpp"
class gradebook {
private:
    std::vector<student*> myStudents;
    std::vector<assignment> myAssignments;
    static std::string report_card_function(student *student_ptr);
    void update() const;
    void update_new_assignments() const;
    void update_new_student() const;
    static std::string makeLetterGrade(const float &grade) ;
public:
    void addStudent(student *new_student);
    static std::string generate_report_card(student *student_ptr);
    std::string generate_report_card(int vector_location) const;
    std::string generate_report_card(const std::string& name) const;
    void add_assignment(const assignment &new_assignment);
    void grade(const student *student_ptr, const assignment &target_assignment, const int &grade) const;
    void grade(const std::string &name, const assignment &target_assignment, const int &grade) const;
    void add_new_student(const std::string &name, const std::string &ID);
    ~gradebook();
};
#endif