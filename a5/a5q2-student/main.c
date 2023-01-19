#include <assert.h>
#include "student.h"

// this is a very basic test client
// you should test your code more thoroughly

int main(void) {
  struct student s = {.id = 12345};
  initialize_new_student(&s);
  print_status(&s);
  print_student(&s);
  assert(student_equals(&s, &s));
  take_course(&s, 70, true);
  take_course(&s, 72, false);
  adjust_grade(&s, 72, 73, false);
  assert(cs_average(&s) == 70);
  assert(cav(&s) == 71);
  assert(!can_graduate(&s));
}