/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// ERROR_NO_INTEGRITY_STATEMENT
//
// Name: ERROR_NO_NAME
// login ID: ERROR_NO_LOGIN
//////////////////////////////////////////////////////////////////////////////////////////

// student.c [IMPLEMENTATION]
  
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "student.h"



// initialize_new_student(s) assigns initial values to the student s
//   but leaves the s->id field unchanged
// effects: modifies s
void initialize_new_student(struct student *s) {
    assert(s);
    s->total_grade = 0;
    s->fails= 0;
    s->total_courses = 0;
    s->cs_courses = 0;
    s->total_cs = 0;
    s->cs_passes=0;
}

// take_course(&s, grade, cs) updates the student s to reflect that they took
//   a course with the specified grade.  cs determines if it was a cs course.
// effects: modifies s
void take_course(struct student *s, int grade, bool cs) {
    assert(s);
    assert(0<=grade && grade <=100);
     if (cs == true) {
         s->cs_courses++;
         if(grade >= 50) {
             s->cs_passes++;
         } 
         
         s->total_cs+= grade;
        
     }
     
     if (grade<50 ){
         s->fails++;
     }
     s->total_grade+=grade;
     s->total_courses++;
     
}

// adjust_grade(s, original_grade, new_grade, cs) updates the student s 
//   to reflect that a previous original_grade has been adjusted (changed)
//   to now be new_grade.  cs determines if it was a cs course.
// requires: a course was previously taken with original_grade
//           note: you should not (and cannot) enforce this requirement
// effects: modifies s
void adjust_grade(struct student *s, int original_grade, int new_grade, bool cs) {
    assert(s);
    assert(s->total_courses > 0);
    assert(0<=original_grade && original_grade <=100);
    assert(0<=new_grade && new_grade <=100);
    
    
    if (original_grade < 50 && new_grade >= 50) {
        s->fails-=1;
    }
    
    if (original_grade >= 50 && new_grade < 50) {
        s->fails+=1;
    }
    
    if(cs == true) {
        if (original_grade < 50 && new_grade >= 50) {
            s->cs_passes+=1;
        }
    
        if (original_grade >= 50 && new_grade < 50) {
            s->cs_passes-=1;
        }
        
        s->total_cs = (s->total_cs - original_grade) + new_grade;
    }
    
    s->total_grade = (s->total_grade - original_grade) + new_grade;
}

// cs_average(s) determines the average of all CS courses taken by s
//   (or 0 if none taken)
int cs_average(const struct student *s) {
    assert(s);
    if (s->cs_courses == 0) {
        return 0;
    }
    int cs_avg = s->total_cs/s->cs_courses;
    return cs_avg;
}


// cav(s) determines the Cumulative AVerage (CAV) of all courses taken by s
//  (or 0 if none taken)
int cav(const struct student *s) {
    assert(s);
    if (s->total_courses == 0) {
        return 0;
    }
    int cav = s->total_grade/s->total_courses;
    return cav;
}


// print_status(s) prints out the status code of student s, followed by \n
//   The status code is a 3 or 4 letter code in capital letters.
//   Note: this is an oversimplified view of the real UW MATH codes
//   If multiple codes apply, the one highest in the following list is used:
//     NONE: number of courses = 0          [no status]
//     FRW:  number of failed courses > 4   [required to withdraw]
//     FRW:  # of fails > # of passes       [required to withdraw]
//     NOCS: number of cs courses = 0       [no cs status]
//     FLPP: CS_AVG < 60 and CAV < 60       [must leave plan]
//     PRBO: CAV < 60                       [probation]
//     CNDP: CS_AVG < 60                    [conditional standing]
//     GOOD: 60 <= CAV < 80                 [good]
//     EXCL: CAV >= 80                      [excellent]
// effects: displays a message
void print_status (const struct student *s) {
    if (s->total_courses == 0) {
        printf("NONE");
    } else if (s->fails > 4 || s->fails > (s->total_courses - s->fails)) {
        printf("FRW");
    } else if (s->cs_courses == 0) {
        printf("NOCS");
    } else if (cs_average(s) < 60 && cav(s) < 60) {
        printf("FLPP");
    } else if (cav(s) < 60) {
        printf("PRBO");
    } else if (cs_average(s) < 60) {
        printf("CNDP");
    } else if (60<=cav(s) && cav(s)< 80) {
        printf("GOOD");
    } else if (80<=cav(s)) {
        printf("EXCL");
    }
    
    printf("\n");
}

// print_student(&s) prints the details of student s formatted exactly as 
//   illustrated by the following example:
//   "Student: 12345, CAV: 66, CS_AVG: 55, Failures: 1, Status: CNDP\n"
// effects: displays a message
void print_student(const struct student *s) {
    assert(s);
    printf("Student: ");
    printf("%d, ", s->id);
    printf("CAV: ");
    printf("%d, ", cav(s));
    printf("CS_AVG: ");
    printf("%d, ", cs_average(s));
    printf("Failures: ");
    printf("%d, ", s->fails);
    printf("Status: ");
    print_status(s);
}


// student_equals(&s1, &s2) determines if the two student records are
//   identical 
bool student_equals(const struct student *s1, const struct student *s2) {
    assert(s1);
    assert(s2);
    if (s1->total_cs == s2->total_cs && s1->fails == s2->fails && s1->cs_courses== s2->cs_courses && s1->total_courses == s2->total_courses && s1->cs_passes == s2->cs_passes && s1->total_grade == s2->total_grade) {
        return true;
    } else {
        return false;
    }
}
// Motivation: C does not provide a function to check whether two instances of
//   of a user-defined type are equal. Therefore, we must implement our own. 
//   Checking for equality does not mean checking whether the pointers
//   point to the same instance, but rather checking the contents of each
//   field for equality.  (checking just the id is also not sufficient)


// can_graduate(&s) determines if student s is eligible for graduation.
//   To graduate, a student must:
//     * have passed at least 40 courses, at least 15 of which must be CS
//     * have a status of GOOD or EXCL (see above)
bool can_graduate(const struct student *s) {
    assert(s);
    int total_passes = s->total_courses - s->fails;
    if (total_passes >= 40 && s->cs_passes >= 15 && cav(s) >=60 && cs_average(s) >=60 && s->fails > (s->total_courses - s->fails)) {
        return true;
    } else {
        return false;
    }
    
}





