#include <stdio.h>

struct employee_add
{
     int street;
     char *state;
     char *city;
     char *country;
};

struct employee_data
{
    int work_id;
    int work_age;
    char *work_name;
    struct employee_add employeeAdd;
};

int main(void) {
    /* Declare a variable of type struct employee_data */
    struct employee_data employee;

    /* Assign values to the struct members */
    employee.work_id = 123;
    employee.work_age = 30;

    /* Allocate memory for string members */
    employee.work_name = (char *)malloc(50 * sizeof(char)); /* Adjust size as needed*/
    employee.employeeAdd.state = (char *)malloc(50 * sizeof(char));
    employee.employeeAdd.city = (char *)malloc(50 * sizeof(char));
    employee.employeeAdd.country = (char *)malloc(50 * sizeof(char));

    /* Check if memory allocation was successful */
    if (employee.work_name == NULL || employee.employeeAdd.state == NULL ||
        employee.employeeAdd.city == NULL || employee.employeeAdd.country == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    /* Copy values to string members */
    strcpy(employee.work_name, "Julien Barbier");
    strcpy(employee.employeeAdd.state, "Lagos Mainland");
    strcpy(employee.employeeAdd.city, "Lagos State");
    strcpy(employee.employeeAdd.country, "Nigeria");

    /* Print the values of struct members */
    printf("Work ID: %d\n", employee.work_id);
    printf("Work Age: %d\n", employee.work_age);
    printf("Work Name: %s\n", employee.work_name);
    printf("State: %s\n", employee.employeeAdd.state);
    printf("City: %s\n", employee.employeeAdd.city);
    printf("Country: %s\n", employee.employeeAdd.country);

    /* Free allocated memory */
    free(employee.work_name);
    free(employee.employeeAdd.state);
    free(employee.employeeAdd.city);
    free(employee.employeeAdd.country);

    return (0);
}
