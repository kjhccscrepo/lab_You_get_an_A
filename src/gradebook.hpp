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
    int has_student(const student *student_in_question) const;
    [[nodiscard]] int has_student(const std::string &student_in_question_name) const;
    int has_assignment(const assignment *assignment_in_question) const;
    [[nodiscard]] int has_assignment(const std::string &assignment_in_question_name) const;
    static std::string report_card_function(student *student_ptr);
    void update() const;
    void update_new_assignments() const;
    void update_new_student() const;
    static std::string makeLetterGrade(const float &grade) ;
public:
    void addStudent(student *new_student);
    static std::string generate_report_card(student *student_ptr);
    [[nodiscard]] std::string generate_report_card(int vector_location) const;
    [[nodiscard]] std::string generate_report_card(const std::string& name) const;
    void add_assignment(const assignment &new_assignment);
    void add_assignment(const std::string& name_of_assignment, int max_points);
    void grade(student *student_ptr, const assignment &target_assignment, const int &student_score) const;
    void grade(const std::string &name, const assignment &target_assignment, const int &student_score) const;
    void grade(const std::string &name_student, const std::string &target_assignment_name, const int &student_score) const;
    void add_new_student(const std::string &name, const std::string &ID);
    [[nodiscard]] std::string student_list() const;
    [[nodiscard]] std::string assignment_list() const;
    ~gradebook();
};
#endif