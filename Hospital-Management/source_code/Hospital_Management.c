/*********************************************************************
*                                                                    *
*                       TEAM NAME: Shrek Bytes                       *
*                                                                    *
**********************************************************************/

/*--------------------------------------------------------------------
                          TEAM MEMBERS
--------------------------------------------------------------------*/
//    CSE (63_L)     Spring 2023     CSE135 (Data Structure LAB)

// 1. MD. WALID AHMED                |      0242220005101595
// 2. Tahmid Alam Tamim              |      0242220005101578
// 3. Md. Hasan                      |      0242220005101573
// 4. Wasif Khan Lodi                |      0242220005101584
// 5. Md. Akibur Rahman              |      0242220005101599

/*--------------------------------------------------------------------
                         PROJECT DETAILS
--------------------------------------------------------------------*/
// Project Name: Hospital Management

// Description: This hospital management application aims to
// simplify patient information management with an innovative and
// user-friendly interface, streamlining hospital processes for better efficiency.

// Version : 1.0
// Date : 18/05/2023
// Project Link: https://github.com/ShrekBytes/Varsity-Projects/tree/main/Hospital-Management

/*********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32 // Windows
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else // Linux and macOS
#define CLEAR_SCREEN "clear"
#endif

#define ARRAY_SIZE 99
#define MAX_LENGTH 20

// Global variable to keep track of the patient number
int countStart = 0;

// Definition of the patient structure
struct Patient
{
    int patientNum;
    char name[33];
    int age;
    char gender[9];
    char bloodGroup[9];
    int nidNumber;
    char address[33];
    char phone[15];
    char email[33];
    char nameEC[33];
    char relationWithEC[15];
    char phoneEC[15];
    char addressEC[33];
    char currentPhscn[33];
    char dateofAdmit[15];
    struct Patient *next;
} *head = NULL;



// Function prototypes
void ASCII_Artify();
void ClearAndLoad();
int login();
void Menu();
void PatientList();
void DisplayPatientInfo(int patientNumber);
void AddPatient();
void SearchPatient();
int levenshteinDistance(const char *str1, const char *str2);

// Main function
int main()
{
    int isLoggedIn;

    do
    {
        isLoggedIn = login();

        if (!isLoggedIn)
        {
            char choice;
            printf("\t\t\t\t  \xDA\xC4\xC4\xC4\xBF \xDA\xC4\xC4\xC4\xBF\n");
            printf("\tDo you want to try again? ");
            printf("\xB3 Y \xB3/\xB3 N \xB3\n");
            printf(" \t\t\t\t  \xC0\xC4\xC4\xC4\xD9 \xC0\xC4\xC4\xC4\xD9\n");
            printf("\t>>> ");
            scanf(" %c", &choice);

            if (choice != 'Y' && choice != 'y')
            {
                printf("\n\tWhy would you do that to me? Why Would you close me.\n\tI am sad. I am gonna complain to my mom.\n");
                return 0;
            }
        }
    }
    while (!isLoggedIn);

    Menu();

    return 0;
}

void ClearAndLoad()
{
    system(CLEAR_SCREEN);
    printf("\n\n\n\n\n\n\n\t\t\tLoading...\n\t\t\n\t\t");
    for (int i = 0; i < 15; i++)
    {
        printf("%c ", 254);
#ifdef _WIN32
        Sleep(50);
#else
        system("sleep 0.05");
#endif
    }
    system(CLEAR_SCREEN);
}


int login()
{
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char ch;
    int i = 0;
    int isLoggedIn = 0;

    ClearAndLoad();
    printf("     ============================================================\n");
    ASCII_Artify("Login Screen");
    printf("     ============================================================\n");

    printf("\n\t Username: ");
    scanf("%s", username);

    printf("\n\t Password: ");
    while (i < MAX_LENGTH - 1)
    {
        ch = getch();
        if (ch == '\r')  // Enter key
            break;
        if (ch == '\b')    // Backspace
        {
            if (i > 0)
            {
                printf("\b \b");
                i--;
            }
        }
        else
        {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';

    printf("\n");

    // Check username and password
    if (strcmp(username, "ShrekBytes") == 0 && strcmp(password, "asdf1234") == 0)
    {
        isLoggedIn = 1;
    }
    else if (strcmp(username, "shrekbytes") == 0 && strcmp(password, "asdf1234") == 0)
    {
        isLoggedIn = 1;
    }
    else if (strcmp(username, "Shrekbytes") == 0 && strcmp(password, "asdf1234") == 0)
    {
        isLoggedIn = 1;
    }

    if (isLoggedIn)
    {
        printf("Login Successful\n");
        ClearAndLoad();
        printf("  \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
        printf("  \xB3  Welcome, %s!              \xB3\n", username);
        printf("  \xB3                                    \xB3\n");
        printf("  \xB3  You have successfully logged in.  \xB3\n");
        printf("  \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

    }
    else
    {
        if (strcmp(username, "ShrekBytes") != 0 && strcmp(username, "shrekbytes") != 0 && strcmp(username, "Shrekbytes") != 0)
        {
            printf("\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
            printf("\t\xB3       Wrong Username!       \xB3\n");
            printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

        }
        else if (strcmp(username, "ShrekBytes") == 0)
        {
            printf("\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
            printf("\t\xB3       Wrong password for ShrekBytes      \xB3\n");
            printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

        }
        else if (strcmp(username, "shrekbytes") == 0)
        {
            printf("\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
            printf("\t\xB3       Wrong password for shrekbytes      \xB3\n");
            printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

        }
        else if (strcmp(username, "Shrekbytes") == 0)
        {
            printf("\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
            printf("\t\xB3       Wrong password for Shrekbytes      \xB3\n");
            printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

        }
        else
        {
            printf("Invalid username or password\n");
        }
    }

    return isLoggedIn;  // Return 1 if logged in, 0 if not logged in
}

void Menu()
{
    int choice;
    printf("     =============================================\n");
    ASCII_Artify("Main Menu");
    printf("     =============================================\n");
    printf("\t\xDA\xC4\xC4\xC4\xBF\n");
    printf("\t\xB3 1 \xB3 All Patients\n");
    printf("\t\xC0\xC4\xC4\xC4\xD9\n");

    printf("\t\xDA\xC4\xC4\xC4\xBF\n");
    printf("\t\xB3 2 \xB3 Add Patient\n");
    printf("\t\xC0\xC4\xC4\xC4\xD9\n");

    printf("\t\xDA\xC4\xC4\xC4\xBF\n");
    printf("\t\xB3 3 \xB3 Search Patient\n");
    printf("\t\xC0\xC4\xC4\xC4\xD9\n");

    printf("\n\t\t\t\t      [0] Log Out\n");
    printf("     ---------------------------------------------\n\n\t>> ");
    scanf("%d", &choice);

    if (choice == 1)
        PatientList();
    else if (choice == 2)
        AddPatient();
    else if (choice == 3)
        SearchPatient();
    else if (choice == 0)
        main();
}
// Function to add a new patient to the linked list
void AddPatient()
{
    ClearAndLoad();
    // Allocate memory for the new patient
    struct Patient *newPatient = (struct Patient *)malloc(sizeof(struct Patient));

    printf("     =====================================================\n");
    ASCII_Artify("Add Patient");
    printf("     =====================================================\n");
    // Assign the patient number and increment the counter
    newPatient->patientNum = ++countStart;

    printf("\t\t\t\t       \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\t\t\t\t       \xB3  Patient No. %d  \xB3\n",newPatient->patientNum);
    printf("\t\t\t\t       \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");


    printf("\t\376 Enter patient Name: ");
    getchar(); // Clear the input buffer
    fgets(newPatient->name, sizeof(newPatient->name), stdin);

    printf("\t\376 Enter patient age: ");
    scanf("%d", &newPatient->age);

    printf("\t\376 Patient Gender: \t 1.Male \t 2.Female \n\t\t\t\t >> ");
    int temp;
    scanf("%d", &temp);
    if (temp == 1)
        strcpy(newPatient->gender, "Male");
    else
        strcpy(newPatient->gender,"Female");
    printf("\t\376 Patient Blood Group: \t 1.A+\t2.B+\t3.AB+\t4.O+\n\t\t\t\t 5.A-\t6.B-\t7.AB-\t8.O-\n\t\t\t\t >> ");
    scanf("%d", &temp);
    if (temp == 1) strcpy(newPatient->bloodGroup, "A+");
    else if (temp == 2) strcpy(newPatient->bloodGroup, "B+");
    else if (temp == 3) strcpy(newPatient->bloodGroup, "AB+");
    else if (temp == 4) strcpy(newPatient->bloodGroup, "O+");
    else if (temp == 5) strcpy(newPatient->bloodGroup, "A-");
    else if (temp == 6) strcpy(newPatient->bloodGroup, "B-");
    else if (temp == 7) strcpy(newPatient->bloodGroup, "AB-");
    else if (temp == 8) strcpy(newPatient->bloodGroup, "O-");
    printf("\t\376 Patient NID Number: ");
    scanf("%d", &newPatient->nidNumber);
    getchar(); // discard newline character left in input buffer
    printf("\t\376 Patient Address: ");
    fgets(newPatient->address, 33, stdin);
    printf("\t\376 Patient Phone Number: ");
    fgets(newPatient->phone, 15, stdin);
    printf("\t\376 Patient Email: ");
    fgets(newPatient->email, 33, stdin);
    printf("\t\376 Emergency Contact Name: ");
    fgets(newPatient->nameEC, 33, stdin);
    printf("\t\376 Relation with Emergency Contact: ");
    fgets(newPatient->relationWithEC, 15, stdin);
    printf("\t\376 Emergency Contact Phone: ");
    fgets(newPatient->phoneEC, 15, stdin);
    printf("\t\376 Emergency Contact Address: ");
    fgets(newPatient->addressEC, 33, stdin);
    printf("\t\376 Current Physician: ");
    fgets(newPatient->currentPhscn, 33, stdin);
    printf("\t\376 Date of Admit: ");
    fgets(newPatient->dateofAdmit, 15, stdin);


    newPatient->next = NULL;

    // If the linked list is empty, set the head to the new patient
    if (head == NULL)
    {
        head = newPatient;
    }
    else
    {
        // Otherwise, traverse the linked list to find the last node
        struct Patient *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Append the new patient to the end of the linked list
        current->next = newPatient;
    }

    printf("\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\t\xB3  Patient Added Successfully!   \xB3\n");
    printf("\t\xB3                                \xB3\n");
    printf("\t\xB3  Press enter for Main Menu.    \xB3\n");
    printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
    printf("\t  >> ");
    getchar();  // jhamelaaaaaaaaaaaaaaaaaa ache akhaneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee input buffer er karone

    ClearAndLoad();
    // Call the Menu function after adding the patient
    Menu();
}

// Function to display only the names of patients as a list
void PatientList()
{
    ClearAndLoad();

    // If the linked list is empty, print a message and return
    if (head == NULL)
    {
        printf("\n\n\t  No patient informations were saved.\n");
        printf("\n\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
        printf("\t\xB3\t\t\t\t\t\xB3\n");
        printf("\t\xB3   Press any key to go to Main Menu!   \xB3\n");
        printf("\t\xB3\t\t\t\t\t\xB3\n");
        printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

        printf("\n\t\t>> ");
        getch();
        ClearAndLoad();
        Menu();
    }


    printf("     ============================================================\n");
    ASCII_Artify("All Patients");
    printf("     ============================================================\n\n");

    // Otherwise, traverse the linked list and print the patient names and numbers
    struct Patient *current = head;
    while (current != NULL)
    {
        printf("\t%d. %s\n", current->patientNum, current->name);
        current = current->next;
    }
    printf("\n\t\t\t\t\t\t     [0] Go Back\n");
    printf("     ------------------------------------------------------------\n");
    // Prompt the user to choose a patient for full information
    printf("\tEnter Patient Number: ");
    int whichPatient;
    scanf("%d", &whichPatient);

    if (whichPatient == 0)
    {
        ClearAndLoad();
        Menu();
    }

    // Call the DisplayPatientInfo function with the chosen patient number
    DisplayPatientInfo(whichPatient);
}

// Function to display the full information of a chosen patient
void DisplayPatientInfo(int patientNumber)
{
    ClearAndLoad();

    // If the linked list is empty, print a message and return
    if (head == NULL)
    {
        printf("No patients\n");
        return;
    }

    struct Patient *current = head;
    struct Patient *previous = NULL;
    while (current != NULL)
    {
        if (current->patientNum == patientNumber)
        {
            printf("\t\t\t\t       \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
            printf("\tInformation of");
            printf("\t\t       \xB3  Patient No. %d  \xB3\n",current->patientNum);
            printf("\t\t\t\t       \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
            ASCII_Artify(current->name);
            printf("     =============================================================\n");
            printf("\n\t\376 Patient age: %d\n", current->age);
            printf("\t\376 Gender: %s\n", current->gender);
            printf("\t\376 Blood Group: %s\n", current->bloodGroup);
            printf("\t\376 NID Number: %d\n", current->nidNumber);
            printf("\t\376 Address: %s", current->address);
            printf("\t\376 Phone Number: %s", current->phone);
            printf("\t\376 Email: %s", current->email);
            printf("\t\376 Emergency Contact Name: %s", current->nameEC);
            printf("\t\376 Relation with Emergency Contact: %s", current->relationWithEC);
            printf("\t\376 Emergency Contact Phone: %s", current->phoneEC);
            printf("\t\376 Emergency Contact Address: %s", current->addressEC);
            printf("\t\376 Current Physician: %s", current->currentPhscn);
            printf("\t\376 Date of Admission: %s", current->dateofAdmit);
            printf("     -------------------------------------------------------------\n");

            printf("\n");
            printf("\t(1) Delete Patient\n\t(2) Go Back\n\n\t >> ");
            int option;
            scanf("%d", &option);

            if (option == 1)
            {
                if (previous == NULL)
                {
                    // If the current patient is the head, update the head
                    head = current->next;
                }
                else
                {
                    // Otherwise, update the next pointer of the previous patient
                    previous->next = current->next;
                }

                free(current); // Free the memory of the current patient
                printf("\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
                printf("\t\xB3 Patient deleted successfully.     \xB3\n");
                printf("\t\xB3                                   \xB3\n");
                printf("\t\xB3 Press any key to go to Main Menu! \xB3\n");
                printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
                printf("\t >> ");

                getch();
                ClearAndLoad();
                Menu();
            }
            else if (option == 2)
            {
                ClearAndLoad();
                Menu();
            }

            return;
        }

        previous = current;
        current = current->next;
    }

    // If the patient number is not found, display an error message
    printf("\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\t\xB3 Patient not found                 \xB3\n");
    printf("\t\xB3                                   \xB3\n");
    printf("\t\xB3 Press any key to go to Main Menu! \xB3\n");
    printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
    printf("\t >> ");
    getch();
    ClearAndLoad();
    Menu();
}

void SearchPatient()
{
    char searchName[33];
    ClearAndLoad();
    printf("\n");
    ASCII_Artify("Search Patient");
    printf("     =====================================================================\n");
    printf("\n\n\tEnter the patient name to search: ");
    getchar(); // Clear the input buffer
    fgets(searchName, sizeof(searchName), stdin);

    if (head == NULL)
    {
        printf("\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
        printf("\t\xB3 No patients                       \xB3\n");
        printf("\t\xB3                                   \xB3\n");
        printf("\t\xB3 Press any key to go to Main Menu! \xB3\n");
        printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
        printf("\t >> ");
        getch();
        ClearAndLoad();
        Menu();
    }

    struct Patient *current = head;
    int found = 0;

    printf("\n\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 Matching patients: \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n");

    while (current != NULL)
    {
        char firstName[33];
        char lastName[33];
        if (sscanf(current->name, "%s %s", firstName, lastName) == 2)
        {
            int distance_first = levenshteinDistance(searchName, firstName);
            int distance_last = levenshteinDistance(searchName, lastName);
            if (distance_first <= 2 || distance_last <= 2) // Set an appropriate threshold for fuzzy matching
            {
                printf("\t%d. %s\n", current->patientNum, current->name);
                found = 1;
            }
        }
        else
        {
            int distance_first = levenshteinDistance(searchName, current->name);
            if (distance_first <= 2) // Set an appropriate threshold for fuzzy matching
            {
                printf("\t%d. %s\n", current->patientNum, current->name);
                found = 1;
            }
        }
        current = current->next;
    }

    if (!found)
    {
        printf("\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
        printf("\t\xB3 No matching patients found        \xB3\n");
        printf("\t\xB3                                   \xB3\n");
        printf("\t\xB3 Press any key to go to Main Menu! \xB3\n");
        printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
        printf("\t >> ");
        getch();
        ClearAndLoad();
        Menu();
    }
    printf("     -------------------------------------------------------------\n");
    // Prompt the user to choose a patient for full information
    printf("\tEnter the patient number to display information: ");
    int whichPatient;
    scanf("%d", &whichPatient);

    // Call the DisplayPatientInfo function with the chosen patient number
    DisplayPatientInfo(whichPatient);
}

// ASCII ART GENERATOR
void ASCII_Artify(char rawString[ARRAY_SIZE])
{
    printf("\t");
    for (int i = 0; i < strlen(rawString); i++)
    {
        if (rawString[i] == 'a' || rawString[i] == 'A') printf("____ ");
        else if (rawString[i] == 'b' || rawString[i] == 'B') printf("___  ");
        else if (rawString[i] == 'c' || rawString[i] == 'C') printf("____ ");
        else if (rawString[i] == 'd' || rawString[i] == 'D') printf("___  ");
        else if (rawString[i] == 'e' || rawString[i] == 'E') printf("____ ");
        else if (rawString[i] == 'f' || rawString[i] == 'F') printf("____ ");
        else if (rawString[i] == 'g' || rawString[i] == 'G') printf("____ ");
        else if (rawString[i] == 'h' || rawString[i] == 'H') printf("_  _ ");
        else if (rawString[i] == 'i' || rawString[i] == 'I') printf("_ ");
        else if (rawString[i] == 'j' || rawString[i] == 'J') printf(" _ ");
        else if (rawString[i] == 'k' || rawString[i] == 'K') printf("_  _ ");
        else if (rawString[i] == 'l' || rawString[i] == 'L') printf("_    ");
        else if (rawString[i] == 'm' || rawString[i] == 'M') printf("_  _ ");
        else if (rawString[i] == 'n' || rawString[i] == 'N') printf("_  _ ");
        else if (rawString[i] == 'o' || rawString[i] == 'O') printf("____ ");
        else if (rawString[i] == 'p' || rawString[i] == 'P') printf("___  ");
        else if (rawString[i] == 'q' || rawString[i] == 'Q') printf("____ ");
        else if (rawString[i] == 'r' || rawString[i] == 'R') printf("____ ");
        else if (rawString[i] == 's' || rawString[i] == 'S') printf("____ ");
        else if (rawString[i] == 't' || rawString[i] == 'T') printf("___ ");
        else if (rawString[i] == 'u' || rawString[i] == 'U') printf("_  _ ");
        else if (rawString[i] == 'v' || rawString[i] == 'V') printf("_  _ ");
        else if (rawString[i] == 'w' || rawString[i] == 'W') printf("_ _ _ ");
        else if (rawString[i] == 'x' || rawString[i] == 'X') printf("_  _ ");
        else if (rawString[i] == 'y' || rawString[i] == 'Y') printf("_   _ ");
        else if (rawString[i] == 'z' || rawString[i] == 'Z') printf("___  ");
        else if (rawString[i] == ' ') printf("   ");
        else if (rawString[i] == ':') printf(" ");
        else if (rawString[i] == '/') printf("  / ");
        else if (rawString[i] == '.') printf(" ");
        else if (rawString[i] == '-') printf("   ");
        else if (rawString[i] == '_') printf("    ");
    }
    printf("\n");


    printf("\t");
    for (int i = 0; i < strlen(rawString); i++)
    {
        if (rawString[i] == 'a' || rawString[i] == 'A') printf("|__| ");
        else if (rawString[i] == 'b' || rawString[i] == 'B') printf("|__] ");
        else if (rawString[i] == 'c' || rawString[i] == 'C') printf("|    ");
        else if (rawString[i] == 'd' || rawString[i] == 'D') printf("|  \\ ");
        else if (rawString[i] == 'e' || rawString[i] == 'E') printf("|___ ");
        else if (rawString[i] == 'f' || rawString[i] == 'F') printf("|___ ");
        else if (rawString[i] == 'g' || rawString[i] == 'G') printf("| __ ");
        else if (rawString[i] == 'h' || rawString[i] == 'H') printf("|__| ");
        else if (rawString[i] == 'i' || rawString[i] == 'I') printf("| ");
        else if (rawString[i] == 'j' || rawString[i] == 'J') printf(" | ");
        else if (rawString[i] == 'k' || rawString[i] == 'K') printf("|_/  ");
        else if (rawString[i] == 'l' || rawString[i] == 'L') printf("|    ");
        else if (rawString[i] == 'm' || rawString[i] == 'M') printf("|\\/| ");
        else if (rawString[i] == 'n' || rawString[i] == 'N') printf("|\\ | ");
        else if (rawString[i] == 'o' || rawString[i] == 'O') printf("|  | ");
        else if (rawString[i] == 'p' || rawString[i] == 'P') printf("|__] ");
        else if (rawString[i] == 'q' || rawString[i] == 'Q') printf("|  | ");
        else if (rawString[i] == 'r' || rawString[i] == 'R') printf("|__/ ");
        else if (rawString[i] == 's' || rawString[i] == 'S') printf("[__  ");
        else if (rawString[i] == 't' || rawString[i] == 'T') printf(" |  ");
        else if (rawString[i] == 'u' || rawString[i] == 'U') printf("|  | ");
        else if (rawString[i] == 'v' || rawString[i] == 'V') printf("|  | ");
        else if (rawString[i] == 'w' || rawString[i] == 'W') printf("| | | ");
        else if (rawString[i] == 'x' || rawString[i] == 'X') printf(" \\/  ");
        else if (rawString[i] == 'y' || rawString[i] == 'Y') printf(" \\_/  ");
        else if (rawString[i] == 'z' || rawString[i] == 'Z') printf("  /  ");
        else if (rawString[i] == ' ') printf("   ");
        else if (rawString[i] == ':') printf(".");
        else if (rawString[i] == '/') printf(" /  ");
        else if (rawString[i] == '.') printf(" ");
        else if (rawString[i] == '-') printf("__ ");
        else if (rawString[i] == '_') printf("    ");
    }
    printf("\n");


    printf("\t");
    for (int i = 0; i < strlen(rawString); i++)
    {
        if (rawString[i] == 'a' || rawString[i] == 'A') printf("|  | ");
        else if (rawString[i] == 'b' || rawString[i] == 'B') printf("|__] ");
        else if (rawString[i] == 'c' || rawString[i] == 'C') printf("|___ ");
        else if (rawString[i] == 'd' || rawString[i] == 'D') printf("|__/ ");
        else if (rawString[i] == 'e' || rawString[i] == 'E') printf("|___ ");
        else if (rawString[i] == 'f' || rawString[i] == 'F') printf("|    ");
        else if (rawString[i] == 'g' || rawString[i] == 'G') printf("|__] ");
        else if (rawString[i] == 'h' || rawString[i] == 'H') printf("|  | ");
        else if (rawString[i] == 'i' || rawString[i] == 'I') printf("| ");
        else if (rawString[i] == 'j' || rawString[i] == 'J') printf("_| ");
        else if (rawString[i] == 'k' || rawString[i] == 'K') printf("| \\_ ");
        else if (rawString[i] == 'l' || rawString[i] == 'L') printf("|___ ");
        else if (rawString[i] == 'm' || rawString[i] == 'M') printf("|  | ");
        else if (rawString[i] == 'n' || rawString[i] == 'N') printf("| \\| ");
        else if (rawString[i] == 'o' || rawString[i] == 'O') printf("|__| ");
        else if (rawString[i] == 'p' || rawString[i] == 'P') printf("|    ");
        else if (rawString[i] == 'q' || rawString[i] == 'Q') printf("|_\\| ");
        else if (rawString[i] == 'r' || rawString[i] == 'R') printf("|  \\ ");
        else if (rawString[i] == 's' || rawString[i] == 'S') printf("___] ");
        else if (rawString[i] == 't' || rawString[i] == 'T') printf(" |  ");
        else if (rawString[i] == 'u' || rawString[i] == 'U') printf("|__| ");
        else if (rawString[i] == 'v' || rawString[i] == 'V') printf(" \\/  ");
        else if (rawString[i] == 'w' || rawString[i] == 'W') printf("|_|_| ");
        else if (rawString[i] == 'x' || rawString[i] == 'X') printf("_/\\_ ");
        else if (rawString[i] == 'y' || rawString[i] == 'Y') printf("  |   ");
        else if (rawString[i] == 'z' || rawString[i] == 'Z') printf(" /__ ");
        else if (rawString[i] == ' ') printf("   ");
        else if (rawString[i] == ':') printf(".");
        else if (rawString[i] == '/') printf("/   ");
        else if (rawString[i] == '.') printf(".");
        else if (rawString[i] == '-') printf("   ");
        else if (rawString[i] == '_') printf("___ ");
    }
    printf("\n");

}


int levenshteinDistance(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        matrix[i][0] = i;

    for (int j = 0; j <= len2; j++)
        matrix[0][j] = j;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int cost = (str1[i - 1] != str2[j - 1]);
            int deletion = matrix[i - 1][j] + 1;
            int insertion = matrix[i][j - 1] + 1;
            int substitution = matrix[i - 1][j - 1] + cost;
            matrix[i][j] = fmin(fmin(deletion, insertion), substitution);
        }
    }

    return matrix[len1][len2];
}
