#include <stdio.h>

/* create a special data type named address */
typedef struct 
{
    char *name;
    char *num;
    int age;
}
address;


int main(void)
{
    address phonebook [2]; /* replace the traditional data type with the custom data type. */
    int i;

    phonebook[0].name = "Taofeek Ajibade";
    phonebook[0].num = "080-123-456-789";
    phonebook[0].age = 35;

    phonebook[1].name = "Abdulhayy Ajibade";
    phonebook[1].num = "080-987-0654-123";
    phonebook[1].age = 14;

    for (i = 0; i < 2; i++)
    {
        if (phonebook[i].name == "Taofeek Ajibade")
        {
            printf("Name found in phonebook\n");
            printf("Name is %s, phone number is %s and age is %d\n",
            phonebook[i].name, phonebook[i].num, phonebook[i].age );
            return (0);
        }
    }
    printf("Address not found in phonebook. Try a different name.\n");

    return (0);

}
