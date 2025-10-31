#include <iostream>
#include "src/assignments.hpp"
#include "src/students.hpp"
#include "src/gradebook.hpp"
#include "src/id_maker.hpp"
using std::cout;
using std::endl;

int main() {
    ID_maker ID_gen;
    gradebook my_gradebook;
    my_gradebook.add_new_student("John Smith", ID_gen.generateID());
    my_gradebook.add_new_student("Brian Williams", ID_gen.generateID());
    my_gradebook.add_new_student("Jackie Tyler", ID_gen.generateID());
    my_gradebook.add_assignment("Worksheet 1", 10);
    my_gradebook.add_assignment("Worksheet 2", 15);
    my_gradebook.add_assignment("Worksheet 3", 10);
    cout << "\n" << my_gradebook.student_list() << endl;
    cout << my_gradebook.assignment_list() << endl;

    /*
        my_gradebook.grade("John", "Worksheet 1", 10);
        my_gradebook.grade("John", "Worksheet 2", 13);
        my_gradebook.grade("John", "Worksheet 3", 9);
        my_gradebook.grade("Brian", "Worksheet 1", 10);
        my_gradebook.grade("Brian", "Worksheet 2", 14);
        my_gradebook.grade("Brian", "Worksheet 3", 10);
        my_gradebook.grade("Jackie", "Worksheet 1", 8);
        my_gradebook.grade("Jackie", "Worksheet 2", 12);
        my_gradebook.grade("Jackie", "Worksheet 3", 7);
        assignment quiz_1("Unit 1 Quiz", 70);
        my_gradebook.add_assignment(quiz_1);
        my_gradebook.grade("John", quiz_1, 58);
        my_gradebook.grade("Brian", quiz_1, 62);
        my_gradebook.grade("Jackie", quiz_1, 70);
    */
    cout << my_gradebook.generate_report_card("John") << endl;
    cout << my_gradebook.generate_report_card("Brian") << endl;
    cout << my_gradebook.generate_report_card("Jackie") << endl;
    return 0;
}
