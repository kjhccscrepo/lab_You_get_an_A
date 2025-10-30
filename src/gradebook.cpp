#include "gradebook.hpp"

int gradebook::has_student(const student *student_in_question) const {
    for (int s = 0; s < myStudents.size(); s++) {
        if (myStudents[s] == student_in_question) {
            return s;
        }
    }
    return -1;
}
int gradebook::has_student(const std::string &student_in_question_name) const {
    for (int n = 0; n < myStudents.size(); n++) {
        if (myStudents[n]->getStudentName() == student_in_question_name || myStudents[n]->getFirstName() == "student_in_question_name") {
            return n;
        }
    }
    return -2;
}

int gradebook::has_assignment(const assignment *assignment_in_question) const {
    for (int a = 0; a < myAssignments.size(); a++) {
        if (myAssignments[a].getName() == assignment_in_question->getName()) {
            return a;
        }
    }
    return -1;
}

int gradebook::has_assignment(const std::string &assignment_in_question_name) const {
    for (int b = 0; b < myAssignments.size(); b++) {
        if (myAssignments[b].getName() == assignment_in_question_name) {
            return b;
        }
    }
    return -2;
}


std::string gradebook::report_card_function(student *student_ptr) {
    std::vector<assignment> vector_of_asingnments = student_ptr->getAssignments();
    std::stringstream header;
    header << "ID: " << student_ptr->getID();
    header << "\t\t| Name: " << student_ptr->getStudentName();
    header << "\n";
    std::stringstream breaker;
    for (int i = 0; i < (header.str().size() / 4 * 3); i++) {
        breaker << "- ";
    }
    std::stringstream assignments;
    for (int i = 0; i < vector_of_asingnments.size(); i++) {
        assignments << "\n";
        assignments << vector_of_asingnments[i].getName();
        assignments << "\tscore: " << vector_of_asingnments[i].score() << "%";
    }
    float total_possible = 0;
    float total_score = 0;
    for (int i = 0; i < vector_of_asingnments.size(); i++) {
        total_possible = total_possible + vector_of_asingnments[i].value();
        total_score = total_score + vector_of_asingnments[i].score_raw();
    }
    total_score = total_score * 100;;
    float tots = (total_score / total_possible);
    std::stringstream report;
    report << "\n";
    report << breaker.str() << "\n";
    report << header.str();
    report << breaker.str();
    report << assignments.str();
    report << "\n" << breaker.str();
    report << "\nTotal grade: " << tots << "%";
    report << "\t| Letter Grade: " << makeLetterGrade(tots);
    report << "\n" << breaker.str() << "\n\n";
    return report.str();
}
void gradebook::update() const {
    for (int s = 0; s < myStudents.size(); s++) {
        for (int a = 0; a < myAssignments.size(); a++) {
            if (!(myStudents[s]->is_assigned(myAssignments[a]))) {
                myStudents[s]->newAssignment(myAssignments[a]);
            }
        }
    }
}
void gradebook::update_new_assignments() const {
    for (int s = 0; s < myStudents.size(); s++) {
        if (!(myStudents[s]->is_assigned(myAssignments.back()))) {
            myStudents[s]->newAssignment(myAssignments.back());
        }
    }
}
void gradebook::update_new_student() const {
    for (int a = 0; a < myAssignments.size(); a++) {
        myStudents.back()->newAssignment(myAssignments[a]);
    }
}
std::string gradebook::makeLetterGrade(const float &grade) {
    if (grade <= 59) {
        return "F";
    } else if (grade <= 62.49) {
        return "D-";
    } else if (grade <= 66.49) {
        return "D";
    } else if (grade <= 69.49) {
        return "D+";
    } else if (grade <= 72.49) {
        return "C-";
    } else if (grade <= 76.49) {
        return "C";
    } else if (grade <= 79.49) {
        return "C+";
    } else if (grade <= 82.49) {
        return "B-";
    } else if (grade <= 86.49) {
        return "B";
    } else if (grade <= 89.49) {
        return "B+";
    } else if (grade <= 93.49) {
        return "A-";
    } else if (grade <= 96.49) {
        return "A";
    } else {
        return "A+";
    }
}

void gradebook::addStudent(student *new_student) {
    myStudents.push_back(new_student);
    update_new_student();
}
std::string gradebook::generate_report_card(student *student_ptr) {
    return report_card_function(student_ptr);
}
std::string gradebook::generate_report_card(const int vector_location) const {
    if (vector_location >= 0 && vector_location < myStudents.size()) {
        return report_card_function(myStudents[vector_location]);
    }
    return "";
}

std::string gradebook::generate_report_card(const std::string& name) const {
    for (int i = 0; i < myStudents.size(); i++) {
        if (myStudents[i]->getStudentName() == name) {
            return report_card_function(myStudents[i]);
        }
    }
    return "";
}

void gradebook::add_assignment(const assignment &new_assignment) {
    myAssignments.push_back(new_assignment);
    update_new_assignments();
}
void gradebook::add_assignment(const std::string name_of_assignment, const int max_points) {
    assignment new_assignment_ptr = assignment(name_of_assignment, max_points);
    add_assignment(new_assignment_ptr);
}

void gradebook::grade(student *student_ptr, const assignment &target_assignment, const int &student_score) const {
    try {
        if (!(has_assignment(&target_assignment))) {
            throw ("Assignment (" + target_assignment.getName() + "), does not exist in gradebook");
        }
        if (!(has_student(student_ptr))) {
            throw ("Student (" + student_ptr->getStudentName() + "), does not exist in gradebook.");
        }
        if (!(student_ptr->is_assigned(target_assignment))) {
            throw ("Student (" + student_ptr->getStudentName() + "), was not assigned " + target_assignment.getName() + ".");
        }
        // then everything is good
        student_ptr->setGradeForAssignment(target_assignment, student_score);
    }
    catch (std::string error_string) {
        std::cerr << error_string << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error." << std::endl;
    }
}
void gradebook::grade(const std::string &F_name, const assignment &target_assignment, const int &grade) const {
    for (int s = 0; s < myStudents.size(); s++) {
        if (myStudents[s]->getFirstName() == F_name || myStudents[s]->getStudentName() == F_name) {
            if (myStudents[s]->is_assigned(target_assignment)) {
                myStudents[s]->setGradeForAssignment(target_assignment, grade);
            } else {
                std::cerr << "\nERROR 3\n";
                std::cerr << "Student, " << F_name << " was not assigned " << target_assignment.getName() << ".\n";
            }
            if (s == myStudents.size() - 1) {
                std::cerr << "\nERROR 4\n";
                std::cerr << "Student, " << F_name << " does not exist in gradebook.";
            }
        }
    }

}

void gradebook::grade(const std::string &name_student, const std::string &assign_name, const int &grade_score) const {
    for (int a = 0; a < myAssignments.size(); a++) {
        if (myAssignments[a].getName() == assign_name) {
            for (int s = 0; s < myStudents.size(); s++) {
                if (myStudents[s]->getStudentName() == name_student || myStudents[s]->getFirstName() == assign_name) {
                    grade(name_student, myAssignments[a], grade_score);
                }
                if (s == myStudents.size() - 1) {
                    std::cerr << "\nERROR 5\n";
                    std::cerr << "Student, " << name_student << " does not exist in gradebook.";
                }
            }
        }
        if (a == myAssignments.size() - 1) {
            std::cerr << "\nERROR 6\n";
            std::cerr << "Assignment, " << assign_name << " does not exist in gradebook.";
        }
    }
}

void gradebook::add_new_student(const std::string &name, const std::string &ID) {
    auto new_student = new student(name, ID);
    myStudents.push_back(new_student);
}

std::string gradebook::student_list() const {
    std::stringstream list_studs;
    list_studs << "Students: ";
    for (int i = 0; i < myStudents.size(); i++) {
        list_studs << myStudents[i]->getStudentName() << ", ";
    }
    list_studs << "\n";
    return list_studs.str();
}

std::string gradebook::assignment_list() const {
    std::stringstream list_asin;
    list_asin << "Assignments: ";
    for (int i = 0; i < myAssignments.size(); i++) {
        list_asin << myAssignments[i].getName() << ", ";
    }
    list_asin << "\n";
    return list_asin.str();
}

gradebook::~gradebook() {
    for (int i = 0; i < myStudents.size(); ++i) {
        delete myStudents[i];
    }
}
