#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    char department[20];
    char designation[20];
    float salary;
    int joinDay;    // new
    int joinMonth;  // new
    int joinYear;
    char phone[20];
    char email[50];
};

struct Employee emp[MAX];
int empCount = 0;

/* 
 * Returns total months of experience (rounded down).
 * If join date is in the future, returns 0.
 */
int totalMonthsExperience(int joinDay, int joinMonth, int joinYear) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int curDay = tm.tm_mday;
    int curMonth = tm.tm_mon + 1;    // tm_mon: 0-11
    int curYear = tm.tm_year + 1900;

    int yearsDiff = curYear - joinYear;
    int monthsDiff = curMonth - joinMonth;
    int totalMonths = yearsDiff * 12 + monthsDiff;

    // If current day is earlier than join day, subtract one month
    if (curDay < joinDay) {
        totalMonths -= 1;
    }

    if (totalMonths < 0) totalMonths = 0;
    return totalMonths;
}

/* Fill years and months from total months */
void calculateExperience(int joinDay, int joinMonth, int joinYear, int *outYears, int *outMonths) {
    int totalMonths = totalMonthsExperience(joinDay, joinMonth, joinYear);
    *outYears = totalMonths / 12;
    *outMonths = totalMonths % 12;
}

/* Add employee (asks for day & month) */
void addEmployee() {
    struct Employee e;

    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Name (no spaces): ");
    scanf("%s", e.name);

    printf("Enter Department (IT/HR/Finance/Marketing/Operations): ");
    scanf("%s", e.department);

    printf("Enter Designation (Intern/Junior/Senior/Manager/Director): ");
    scanf("%s", e.designation);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    printf("Enter Joining Day (1-31): ");
    scanf("%d", &e.joinDay);

    printf("Enter Joining Month (1-12): ");
    scanf("%d", &e.joinMonth);

    printf("Enter Joining Year (YYYY): ");
    scanf("%d", &e.joinYear);

    printf("Enter Phone: ");
    scanf("%s", e.phone);

    printf("Enter Email: ");
    scanf("%s", e.email);

    emp[empCount++] = e;
    printf("\nEmployee Added Successfully!\n\n");
}

/* Display all employees with experience in years + months */
void displayAll() {
    int i;

    if (empCount == 0) {
        printf("\nNo employees found.\n");
        return;
    }

    printf("\n----- Employee List -----\n");
    for (i = 0; i < empCount; i++) {
        int yrs, mons;
        calculateExperience(emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear, &yrs, &mons);

        printf("\nID: %d\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %.2f\n",
               emp[i].id, emp[i].name, emp[i].department, emp[i].designation, emp[i].salary);
        printf("Joining Date: %02d-%02d-%04d\nPhone: %s\nEmail: %s\nExperience: %d years, %d months\n",
               emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear, emp[i].phone, emp[i].email, yrs, mons);
    }
}

/* Department salary stats */
void departmentSalaryStats() {
    char dept[20];
    float total = 0;
    int count = 0;
    int i;

    printf("Enter Department: ");
    scanf("%s", dept);

    for (i = 0; i < empCount; i++) {
        if (strcmp(emp[i].department, dept) == 0) {
            total += emp[i].salary;
            count++;
        }
    }

    if (count == 0) {
        printf("No employees in this department.\n");
        return;
    }

    printf("\nDepartment: %s\nTotal Salary = %.2f\nAverage Salary = %.2f\n\n",
           dept, total, total / count);
}

/* Apply appraisal */
void applyAppraisal() {
    int id, i;
    float percent;

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    printf("Enter Increment (5–15%%): ");
    scanf("%f", &percent);

    if (percent < 5.0f || percent > 15.0f) {
        printf("Invalid increment range.\n");
        return;
    }

    for (i = 0; i < empCount; i++) {
        if (emp[i].id == id) {
            emp[i].salary += emp[i].salary * (percent / 100.0f);
            printf("New Salary = %.2f\n", emp[i].salary);
            return;
        }
    }

    printf("Employee not found.\n");
}

/* Search employees:
   - by department
   - by designation
   - by minimum experience (years & months) */
void searchEmployee() {
    int choice, i;
    char str[20];
    int minYears, minMonths;

    printf("\n1. Search by Department\n2. Search by Designation\n3. Search by Minimum Experience\nChoose: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Department: ");
        scanf("%s", str);

        for (i = 0; i < empCount; i++) {
            if (strcmp(emp[i].department, str) == 0) {
                printf("Found: %s — %s (Joined %02d-%02d-%04d)\n",
                       emp[i].name, emp[i].designation, emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear);
            }
        }
    } 
    else if (choice == 2) {
        printf("Enter Designation: ");
        scanf("%s", str);

        for (i = 0; i < empCount; i++) {
            if (strcmp(emp[i].designation, str) == 0) {
                printf("Found: %s — %s (Joined %02d-%02d-%04d)\n",
                       emp[i].name, emp[i].department, emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear);
            }
        }
    } 
    else if (choice == 3) {
        printf("Enter minimum years: ");
        scanf("%d", &minYears);
        printf("Enter additional minimum months (0-11): ");
        scanf("%d", &minMonths);
        if (minMonths < 0) minMonths = 0;
        if (minMonths > 11) minMonths = 11;

        int minTotalMonths = minYears * 12 + minMonths;

        for (i = 0; i < empCount; i++) {
            int tMonths = totalMonthsExperience(emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear);
            if (tMonths >= minTotalMonths) {
                int y,m;
                calculateExperience(emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear, &y, &m);
                printf("Found: %s — %d years, %d months (Joined %02d-%02d-%04d)\n",
                       emp[i].name, y, m, emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear);
            }
        }
    } else {
        printf("Invalid choice.\n");
    }
}

/* Promotion eligibility (> 3 years in current role) */
void promotionEligibility() {
    int i;
    printf("\nEmployees Eligible for Promotion (>3 years in current role):\n");

    for (i = 0; i < empCount; i++) {
        int totalMonths = totalMonthsExperience(emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear);
        if (totalMonths >= 3 * 12) {
            int y, m;
            calculateExperience(emp[i].joinDay, emp[i].joinMonth, emp[i].joinYear, &y, &m);
            printf("%s — %s : %d years, %d months\n", emp[i].name, emp[i].designation, y, m);
        }
    }
}

/* Main menu */
int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n2. Display All Employees\n3. Department Salary Stats\n");
        printf("4. Apply Appraisal\n5. Search Employee\n6. Promotion Eligibility\n7. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: departmentSalaryStats(); break;
            case 4: applyAppraisal(); break;
            case 5: searchEmployee(); break;
            case 6: promotionEligibility(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

