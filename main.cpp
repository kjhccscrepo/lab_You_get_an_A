#include <iostream>
#include "src/assignments.hpp"
#include "src/students.hpp"
#include "src/gradebook.hpp"
#include "src/id_maker.hpp"
int main() {
    ID_maker ID_gen;
    gradebook my_gradebook;
    my_gradebook.add_new_student("John Smith", ID_gen.generateID());
    my_gradebook.add_new_student("Brian Williams", ID_gen.generateID());
    my_gradebook.add_new_student("Jackie Tyler", ID_gen.generateID());
    assignment wrkst_1("Worksheet 1", 10);
    assignment wrkst_2("Worksheet 2", 15);
    assignment wrkst_3("Worksheet 3", 10);
    my_gradebook.add_assignment(wrkst_1);
    my_gradebook.add_assignment(wrkst_2);
    my_gradebook.add_assignment(wrkst_3);
    my_gradebook.grade("John", wrkst_1, 10);
    my_gradebook.grade("John", wrkst_2, 13);
    my_gradebook.grade("John", wrkst_3, 9);
    my_gradebook.grade("Brian", wrkst_1, 10);
    my_gradebook.grade("Brian", wrkst_2, 14);
    my_gradebook.grade("Brian", wrkst_3, 10);
    my_gradebook.grade("Jackie", wrkst_1, 8);
    my_gradebook.grade("Jackie", wrkst_2, 12);
    my_gradebook.grade("Jackie", wrkst_3, 7);
    assignment quiz_1("Unit 1 Quiz", 70);
    my_gradebook.add_assignment(quiz_1);
    my_gradebook.grade("John", quiz_1, 58);
    my_gradebook.grade("Brian", quiz_1, 62);
    my_gradebook.grade("Jackie", quiz_1, 70);
    std::cout << my_gradebook.generate_report_card("John") << std::endl;
    std::cout << my_gradebook.generate_report_card("Brian") << std::endl;
    std::cout << my_gradebook.generate_report_card("Jackie") << std::endl;
    return 0;
}
