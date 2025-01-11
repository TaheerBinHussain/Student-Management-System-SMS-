#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdio.h>

// Global data storage
std::string s1[30][10];    // MS101
std::string s2[30][10];    // MS102
std::string s3[30][10];    // MS103
std::string s4[30][10];    // MS104
std::string s5[30][10];    // MS105
std::string cgpa[30][2];   // Roll number + CGPA

// Function declarations
bool validate(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8);
bool ischar(std::string s1);
bool checkFileforRemove();
bool checkFile();
bool adminVerify();
void dataRetrieval();
void cgpaRetrieval();
void calculateCGPPA();
void viewGrade(std::string roll);
void addteacher(std::string id, std::string name, std::string subject, std::string tpass);
void removeteacher(std::string id);
bool verify(std::string tuser, std::string tpass);
void addStudent();
void removestudent(std::string roll);
void passStudents();
void failStudents();
void ascend();
void descend();

int main()
{
    std::string student[20][10] = { " " }, tuser, tpass, subject, sub;
    int count = 0;
    std::string tname, tsubject, tid, roll, studentID, studentPASS, response, admin, teacher;
    bool flag = 1, bla = 1;

    system("COLOR 3F");
    // Main menu loop
    while (response != "4")
    {
        system("cls"); // Clear screen before displaying the menu
        std::cout << " SSSSSSS     M     M    SSSSSSS   \n";
        std::cout << " S           MM   MM    S          \n";
        std::cout << " SSSSSSS     M M M M    SSSSSSS     \n";
        std::cout << "       S     M  M  M          S       \n";
        std::cout << " SSSSSSS     M     M    SSSSSSS     \n";
        std::cout << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Welcome to the Student Management System" << std::endl;
        std::cout << "1. Admin                                " << std::endl;
        std::cout << "2. Teacher                              " << std::endl;
        std::cout << "3. Student                              " << std::endl;
        std::cout << "4. Exit                                 " << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cin.clear();
        std::getline(std::cin, response);

        if (response == "1")
        {
            // Admin login
            if (adminVerify())
            {
                system("cls"); // Clear screen after successful admin login
                std::cout << "Press 1 to Add Teacher and 2 to Delete Teacher and 0 for Nothing: ";
                std::getline(std::cin, admin);

                if (admin == "1")
                {
                    while (1)
                    {
                        system("cls");
                        std::cout << "Please enter the Teacher ID: ";
                        std::getline(std::cin, tid);
                        std::cout << "Please enter the Teacher Password: ";
                        std::getline(std::cin, tpass);
                        std::cout << "Please enter the Teacher Name: ";
                        std::getline(std::cin, tname);
                        std::cout << "Please enter the Teacher Subject: ";
                        std::getline(std::cin, tsubject);

                        if (tid.length() == 4 && tpass.length() == 4)
                        {
                            addteacher(tid, tname, tsubject, tpass);
                            break;
                        }
                        else
                        {
                            std::cout << "Please enter the username and password again!" << std::endl;
                        }
                    }
                }
                else if (admin == "2")
                {
                    system("cls");
                    std::cout << "Please enter the ID of the Teacher you want to remove: ";
                    std::cin >> tid;
                    removeteacher(tid);
                }
                std::cout << "Bye!" << std::endl;
            }
        }
        else if (response == "2")
        {
            // Teacher login
            system("cls");
            std::cout << "Enter your Username: ";
            std::getline(std::cin, tuser);
            std::cout << "Enter your Password: ";
            std::getline(std::cin, tpass);
            std::cout << "Enter your Subject: ";
            std::getline(std::cin, tsubject);

            if (verify(tuser, tpass))
            {
                system("cls");
                std::cout << "Press 1 to Add a Student, 2 to Remove a Student, and 0 for Nothing: ";
                std::getline(std::cin, teacher);

                if (teacher == "1")
                {
                    if (checkFile()) addStudent();
                }
                else if (teacher == "2")
                {
                    if (checkFileforRemove())
                    {
                        std::cout << "Please enter the Roll Number of the Student you want to remove: ";
                        std::getline(std::cin, roll);
                        removestudent(roll);
                    }
                }

                while (bla)
                {
                    system("cls");
                    std::cout << "1 - To Calculate CGPA" << std::endl;
                    std::cout << "2 - List of Passed Students" << std::endl;
                    std::cout << "3 - List of Failed Students" << std::endl;
                    std::cout << "4 - Students in Ascending Order of CGPA" << std::endl;
                    std::cout << "5 - Students in Descending Order of CGPA" << std::endl;
                    std::cout << "0 - Exit" << std::endl;
                    std::getline(std::cin, teacher);

                    if (teacher == "1")
                    {
                        calculateCGPPA();
                    }
                    else if (teacher == "2")
                    {
                        passStudents();
                    }
                    else if (teacher == "3")
                    {
                        failStudents();
                    }
                    else if (teacher == "4")
                    {
                        ascend();
                    }
                    else if (teacher == "5")
                    {
                        descend();
                    }
                    else if (teacher == "0")
                    {
                        std::cout << "Bye!" << std::endl;
                        bla = 0;
                    }
                    else
                    {
                        std::cout << "Not a valid response!" << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "Invalid Username or Password" << std::endl;
            }
        }
        else if (response == "3")
        {
            // Student login
            system("cls");
            std::cout << "Enter your Roll Number: ";
            std::getline(std::cin, studentID);
            dataRetrieval();
            count = 0;

            for (int x = 0; x < 30; ++x)
            {
                if (s1[x][0] == studentID)
                {
                    ++count;
                }
            }

            if (count == 1)
            {
                viewGrade(studentID);
            }
            else
            {
                std::cout << "You entered an invalid Roll Number!" << std::endl;
            }
        }
        else if (response == "4")
        {
            std::cout << "Thanks for using the Student Management System!" << std::endl;
        }
        else
        {
            std::cout << "Enter a valid response!" << std::endl;
        }
    }

    return 0;
}

void addteacher(std::string id, std::string name, std::string subject, std::string tpass)
{
    // Opens the file in append mode to add a new teacher
    std::ofstream fh;
    fh.open("admin.txt", std::ios::app);
    if (!fh.is_open())
        std::cout << "error opeing the file" << std::endl; // Checks if the file opened successfully
    fh << id << " " << tpass << " " << name << " " << subject; // Writes teacher details to the file
    fh << '\n';
    fh.close(); // Closes the file
    std::cout << "Teacher Successfully Added!" << std::endl;
}

void removeteacher(std::string id)
{
    // Removes a teacher based on their ID from the "admin.txt" file
    std::string line, ID = "";
    std::ifstream originalin;
    originalin.open("admin.txt"); // Opens the original file for reading

    std::ofstream tempout;
    tempout.open("temp.txt"); // Opens a temporary file for writing

    while ((std::getline(originalin, line)))
    {
        ID = ""; // Clears ID for every new line
        for (int x = 0; x < 4; ++x)
        { // Extracts the first 4 characters as ID
            ID = ID + line[x];
        }
        if (ID != id)
        { // If the ID doesn't match, write the line to temp file
            tempout << line << std::endl;
        }
    }
    tempout.close();
    originalin.close();

    // Copies the contents from the temporary file back to the original file
    std::ofstream originalout;
    originalout.open("admin.txt");
    std::ifstream tempin;
    tempin.open("temp.txt");
    while ((std::getline(tempin, line)))
    {
        originalout << line << std::endl;
    }
    tempin.close();
    originalout.close();
}

bool verify(std::string tuser, std::string tpass)
{
    // Verifies a teacher's credentials (username and password)
    std::string tempuser = "", temppass = "", line;
    std::ifstream in;
    in.open("admin.txt"); // Opens the admin file
    while (std::getline(in, line))
    {
        tempuser = ""; // Clears temporary username
        temppass = ""; // Clears temporary password
        for (int x = 0; x < 4; ++x)
        { // Extracts the first 4 characters as username
            tempuser = tempuser + line[x];
        }
        for (int x = 5; x < 9; ++x)
        { // Extracts the next 4 characters as password
            temppass = temppass + line[x];
        }
        if (tempuser == tuser && temppass == tpass)
        { // Checks if both match
            return 1; // Credentials are valid
        }
        else
        {
            return 0; // Credentials are invalid
        }

    }
}

void removestudent(std::string roll)
{
    std::string line, ID;

    // For subject 1
    std::ifstream in("s1.txt"); // Opens subject 1 file
    if (!in.is_open())
    {
        std::cerr << "Error: Unable to open s1.txt\n"; // Error if file not opened
        return;
    }
    std::ofstream out("temp1.txt"); // Temporary file for subject 1
    if (!out.is_open())
    {
        std::cerr << "Error: Unable to create temp1.txt\n"; // Error if temp file not created
        return;
    }
    while (std::getline(in, line))
    {
        ID = line.substr(0, 4); // Extract first 4 characters for ID
        if (ID != roll)
        { // Writes the line to temp file if ID doesn't match
            out << line << std::endl;
        }
    }
    in.close();
    out.close();

    // Copies the contents from the temporary file back to the original file for subject 1
    in.open("temp1.txt");
    out.open("s1.txt");
    while (std::getline(in, line))
    {
        out << line << std::endl;
    }
    in.close();
    out.close();

    // For subject 2
    in.open("s2.txt");
    if (!in.is_open())
    {
        std::cerr << "Error: Unable to open s2.txt\n";
        return;
    }
    out.open("temp2.txt");
    if (!out.is_open())
    {
        std::cerr << "Error: Unable to create temp2.txt\n";
        return;
    }
    while (std::getline(in, line))
    {
        ID = line.substr(0, 4); // Extract first 4 characters for ID
        if (ID != roll)
        {
            out << line << std::endl;
        }
    }
    in.close();
    out.close();

    in.open("temp2.txt");
    out.open("s2.txt");
    while (std::getline(in, line))
    {
        out << line << std::endl;
    }
    in.close();
    out.close();

    // For subject 3
    in.open("s3.txt");
    if (!in.is_open())
    {
        std::cerr << "Error: Unable to open s3.txt\n";
        return;
    }
    out.open("temp3.txt");
    if (!out.is_open())
    {
        std::cerr << "Error: Unable to create temp3.txt\n";
        return;
    }
    while (std::getline(in, line))
    {
        ID = line.substr(0, 4); // Extract first 4 characters for ID
        if (ID != roll)
        {
            out << line << std::endl;
        }
    }
    in.close();
    out.close();

    in.open("temp3.txt");
    out.open("s3.txt");
    while (std::getline(in, line))
    {
        out << line << std::endl;
    }
    in.close();
    out.close();

    // For subject 4
    in.open("s4.txt");
    if (!in.is_open())
    {
        std::cerr << "Error: Unable to open s4.txt\n";
        return;
    }
    out.open("temp4.txt");
    if (!out.is_open())
    {
        std::cerr << "Error: Unable to create temp4.txt\n";
        return;
    }
    while (std::getline(in, line))
    {
        ID = line.substr(0, 4); // Extract first 4 characters for ID
        if (ID != roll)
        {
            out << line << std::endl;
        }
    }
    in.close();
    out.close();

    in.open("temp4.txt");
    out.open("s4.txt");
    while (std::getline(in, line))
    {
        out << line << std::endl;
    }
    in.close();
    out.close();

    // For subject 5
    in.open("s5.txt");
    if (!in.is_open())
    {
        std::cerr << "Error: Unable to open s5.txt\n";
        return;
    }
    out.open("temp5.txt");
    if (!out.is_open())
    {
        std::cerr << "Error: Unable to create temp5.txt\n";
        return;
    }
    while (std::getline(in, line))
    {
        ID = line.substr(0, 4); // Extract first 4 characters for ID
        if (ID != roll)
        {
            out << line << std::endl;
        }
    }
    in.close();
    out.close();

    in.open("temp5.txt");
    out.open("s5.txt");
    while (std::getline(in, line))
    {
        out << line << std::endl;
    }
    in.close();
    out.close();
}

void addStudent()
{
    std::string roll, subject, name;

    // Open the file for the first subject to append data
    std::ofstream out;
    out.open("s1.txt", std::ios::app);
    while (1)
    {
        system("cls"); // Clear screen for better readability
        std::cout << "Enter the Roll number of the Student: ";
        std::getline(std::cin, roll);
        std::cout << "Enter the name of the Student: ";
        std::getline(std::cin, name);

        // Enter marks for the first subject
        std::cout << "Enter the Marks for Subject MS101 : " << std::endl;

        std::cout << "Enter marks for Quiz 1 : ";
        std::getline(std::cin, s1[0][1]);
        std::cout << "Enter marks for Quiz 2 : ";
        std::getline(std::cin, s1[0][2]);
        std::cout << "Enter marks for Assignment 1 : ";
        std::getline(std::cin, s1[0][3]);
        std::cout << "Enter marks for Assignment 2 : ";
        std::getline(std::cin, s1[0][4]);
        std::cout << "Enter marks for Class Participation : ";
        std::getline(std::cin, s1[0][5]);
        std::cout << "Enter marks for MID-I : ";
        std::getline(std::cin, s1[0][6]);
        std::cout << "Enter marks for MID-II : ";
        std::getline(std::cin, s1[0][7]);
        std::cout << "Enter marks for Finals : ";
        std::getline(std::cin, s1[0][8]);

        // Validate input and write to file if valid
        if (validate(s1[0][1], s1[0][2], s1[0][3], s1[0][4], s1[0][5], s1[0][6], s1[0][7], s1[0][8]) && roll.length() == 4)
        {
            out << roll << " " << name << " " << s1[0][1] << " " << s1[0][2] << " " << s1[0][3] << " " << s1[0][4] << " " << s1[0][5] << " " << s1[0][6] << " " << s1[0][7] << " " << s1[0][8] << std::endl;
            break;
        }
        else
        {
            // Display appropriate error message
            if (roll.length() != 4)
            {
                std::cout << "Please enter 4 digit roll number !!" << std::endl;
            }
            else
            {
                std::cout << "Error! You should enter only numbers in marks! Enter Again !!!!" << std::endl;
            }

        }
    }
    out.close(); // Close the file for the first subject

    // Repeat for the second subject
    out.open("s2.txt", std::ios::app);
    while (1)
    {
        system("cls"); // Clear screen for better readability

        std::cout << "Enter the Marks for Subject MS102 : " << std::endl;

        std::cout << "Enter marks for Quiz 1 : ";
        std::getline(std::cin, s1[0][1]);
        std::cout << "Enter marks for Quiz 2 : ";
        std::getline(std::cin, s1[0][2]);
        std::cout << "Enter marks for Assignment 1 : ";
        std::getline(std::cin, s1[0][3]);
        std::cout << "Enter marks for Assignment 2 : ";
        std::getline(std::cin, s1[0][4]);
        std::cout << "Enter marks for Class Participation : ";
        std::getline(std::cin, s1[0][5]);
        std::cout << "Enter marks for MID-I : ";
        std::getline(std::cin, s1[0][6]);
        std::cout << "Enter marks for MID-II : ";
        std::getline(std::cin, s1[0][7]);
        std::cout << "Enter marks for Finals : ";
        std::getline(std::cin, s1[0][8]);

        // Validate input and write to file if valid
        if (validate(s1[0][1], s1[0][2], s1[0][3], s1[0][4], s1[0][5], s1[0][6], s1[0][7], s1[0][8]) && roll.length() == 4)
        {
            out << roll << " " << name << " " << s1[0][1] << " " << s1[0][2] << " " << s1[0][3] << " " << s1[0][4] << " " << s1[0][5] << " " << s1[0][6] << " " << s1[0][7] << " " << s1[0][8] << std::endl;
            break;
        }
        else
        {
            std::cout << "Error! You should enter only numbers in marks! Enter Again !!!!" << std::endl;
        }
    }
    out.close(); // Close the file for the second subject

    // Repeat for the third subject
    out.open("s3.txt", std::ios::app);
    while (1)
    {
        system("cls"); // Clear screen for better readability

        std::cout << "Enter the Marks for Subject MS103 : " << std::endl;

        std::cout << "Enter marks for Quiz 1 : ";
        std::getline(std::cin, s1[0][1]);
        std::cout << "Enter marks for Quiz 2 : ";
        std::getline(std::cin, s1[0][2]);
        std::cout << "Enter marks for Assignment 1 : ";
        std::getline(std::cin, s1[0][3]);
        std::cout << "Enter marks for Assignment 2 : ";
        std::getline(std::cin, s1[0][4]);
        std::cout << "Enter marks for Class Participation : ";
        std::getline(std::cin, s1[0][5]);
        std::cout << "Enter marks for MID-I : ";
        std::getline(std::cin, s1[0][6]);
        std::cout << "Enter marks for MID-II : ";
        std::getline(std::cin, s1[0][7]);
        std::cout << "Enter marks for Finals : ";
        std::getline(std::cin, s1[0][8]);

        // Validate input and write to file if valid
        if (validate(s1[0][1], s1[0][2], s1[0][3], s1[0][4], s1[0][5], s1[0][6], s1[0][7], s1[0][8]) && roll.length() == 4)
        {
            out << roll << " " << name << " " << s1[0][1] << " " << s1[0][2] << " " << s1[0][3] << " " << s1[0][4] << " " << s1[0][5] << " " << s1[0][6] << " " << s1[0][7] << " " << s1[0][8] << std::endl;
            break;
        }
        else
        {
            std::cout << "Error! You should enter only numbers in marks! Enter Again !!!!" << std::endl;
        }
    }
    out.close(); // Close the file for the third subject

    // Repeat for the fourth subject
    out.open("s4.txt", std::ios::app);
    while (1)
    {
        system("cls"); // Clear screen for better readability

        std::cout << "Enter the Marks for Subject MS104 : " << std::endl;

        std::cout << "Enter marks for Quiz 1 : ";
        std::getline(std::cin, s1[0][1]);
        std::cout << "Enter marks for Quiz 2 : ";
        std::getline(std::cin, s1[0][2]);
        std::cout << "Enter marks for Assignment 1 : ";
        std::getline(std::cin, s1[0][3]);
        std::cout << "Enter marks for Assignment 2 : ";
        std::getline(std::cin, s1[0][4]);
        std::cout << "Enter marks for Class Participation : ";
        std::getline(std::cin, s1[0][5]);
        std::cout << "Enter marks for MID-I : ";
        std::getline(std::cin, s1[0][6]);
        std::cout << "Enter marks for MID-II : ";
        std::getline(std::cin, s1[0][7]);
        std::cout << "Enter marks for Finals : ";
        std::getline(std::cin, s1[0][8]);

        // Validate input and write to file if valid
        if (validate(s1[0][1], s1[0][2], s1[0][3], s1[0][4], s1[0][5], s1[0][6], s1[0][7], s1[0][8]) && roll.length() == 4)
        {
            out << roll << " " << name << " " << s1[0][1] << " " << s1[0][2] << " " << s1[0][3] << " " << s1[0][4] << " " << s1[0][5] << " " << s1[0][6] << " " << s1[0][7] << " " << s1[0][8] << std::endl;
            break;
        }
        else
        {
            std::cout << "Error! You should enter only numbers in marks! Enter Again !!!!" << std::endl;
        }
    }
    out.close(); // Close the file for the fourth subject

    // Repeat for the fifth subject
    out.open("s5.txt", std::ios::app);
    while (1)
    {
        system("cls"); // Clear screen for better readability

        std::cout << "Enter the Marks for Subject MS105 : " << std::endl;

        std::cout << "Enter marks for Quiz 1 : ";
        std::getline(std::cin, s1[0][1]);
        std::cout << "Enter marks for Quiz 2 : ";
        std::getline(std::cin, s1[0][2]);
        std::cout << "Enter marks for Assignment 1 : ";
        std::getline(std::cin, s1[0][3]);
        std::cout << "Enter marks for Assignment 2 : ";
        std::getline(std::cin, s1[0][4]);
        std::cout << "Enter marks for Class Participation : ";
        std::getline(std::cin, s1[0][5]);
        std::cout << "Enter marks for MID-I : ";
        std::getline(std::cin, s1[0][6]);
        std::cout << "Enter marks for MID-II : ";
        std::getline(std::cin, s1[0][7]);
        std::cout << "Enter marks for Finals : ";
        std::getline(std::cin, s1[0][8]);

        // Validate input and write to file if valid
        if (validate(s1[0][1], s1[0][2], s1[0][3], s1[0][4], s1[0][5], s1[0][6], s1[0][7], s1[0][8]) && roll.length() == 4)
        {
            out << roll << " " << name << " " << s1[0][1] << " " << s1[0][2] << " " << s1[0][3] << " " << s1[0][4] << " " << s1[0][5] << " " << s1[0][6] << " " << s1[0][7] << " " << s1[0][8] << std::endl;
            break;
        }
        else
        {
            std::cout << "Error! You should enter only numbers in marks! Enter Again !!!!" << std::endl;
        }
    }
    out.close(); // Close the file for the fifth subject
}

void dataRetrieval()
{
    int found, index, len;
    int row, col;
    std::string line, str;

    // Process file s1.txt
    row = 0; // Reset row for each file
    std::ifstream in("s1.txt");
    if (!in.is_open())
    {
        std::cout << "Error: Unable to open s1.txt\n";
    }
    else
    {
        while (std::getline(in, line))
        {
            len = line.length();
            found = 0;
            index = 0;
            col = 0; // Reset col for each row
            while (found < 9 && index < len)
            {
                if (!isalpha(line[index]) && !isspace(line[index]))
                { // Check for non-alpha and non-space characters
                    ++found;
                    str = "";
                    for (int x = index; x < len && !isspace(line[x]); ++x)
                    { // Extract continuous characters
                        str += line[x];
                        ++index;
                    }
                    s1[row][col] = str; // Assuming s1 is globally defined
                    ++col;
                }
                ++index;
            }
            ++row;
        }
    }
    in.close(); // Close the file after reading

    // Process file s2.txt
    row = 0;
    in.open("s2.txt");
    if (!in.is_open())
    {
        std::cout << "Error: Unable to open s2.txt\n";
        return;
    }
    while (std::getline(in, line))
    {
        len = line.length();
        found = 0;
        index = 0;
        col = 0;
        while (found < 9 && index < len)
        {
            if (!isalpha(line[index]) && !isspace(line[index]))
            { // Check for non-alpha and non-space characters
                ++found;
                str = "";
                for (int x = index; x < len && !isspace(line[x]); ++x)
                { // Extract continuous characters
                    str += line[x];
                    ++index;
                }
                s2[row][col] = str; // Assuming s2 is globally defined
                ++col;
            }
            ++index;
        }
        ++row;
    }
    in.close(); // Close the file after reading


    // Process file s3.txt
    row = 0;
    in.open("s3.txt");
    if (!in.is_open())
    {
        std::cout << "Error: Unable to open s3.txt\n";
        return;
    }
    while (std::getline(in, line))
    {
        len = line.length();
        found = 0;
        index = 0;
        col = 0;
        while (found < 9 && index < len)
        {
            if (!isalpha(line[index]) && !isspace(line[index]))
            { // Check for non-alpha and non-space characters
                ++found;
                str = "";
                for (int x = index; x < len && !isspace(line[x]); ++x)
                { // Extract continuous characters
                    str += line[x];
                    ++index;
                }
                s3[row][col] = str; // Assuming s3 is globally defined
                ++col;
            }
            ++index;
        }
        ++row;
    }
    in.close(); // Close the file after reading

    // Process file s4.txt
    row = 0;
    in.open("s4.txt");
    if (!in.is_open())
    {
        std::cout << "Error: Unable to open s4.txt\n";
        return;
    }
    while (std::getline(in, line))
    {
        len = line.length();
        found = 0;
        index = 0;
        col = 0;
        while (found < 9 && index < len)
        {
            if (!isalpha(line[index]) && !isspace(line[index]))
            { // Check for non-alpha and non-space characters
                ++found;
                str = "";
                for (int x = index; x < len && !isspace(line[x]); ++x)
                { // Extract continuous characters
                    str += line[x];
                    ++index;
                }
                s4[row][col] = str; // Assuming s4 is globally defined
                ++col;
            }
            ++index;
        }
        ++row;
    }
    in.close(); // Close the file after reading


    // Process file s5.txt
    row = 0;
    in.open("s5.txt");
    if (!in.is_open())
    {
        std::cout << "Error: Unable to open s5.txt\n";
        return;
    }
    while (std::getline(in, line))
    {
        len = line.length();
        found = 0;
        index = 0;
        col = 0;
        while (found < 9 && index < len)
        {
            if (!isalpha(line[index]) && !isspace(line[index]))
            { // Check for non-alpha and non-space characters
                ++found;
                str = "";
                for (int x = index; x < len && !isspace(line[x]); ++x)
                { // Extract continuous characters
                    str += line[x];
                    ++index;
                }
                s5[row][col] = str; // Assuming s5 is globally defined
                ++col;
            }
            ++index;
        }
        ++row;
    }
    in.close(); // Close the file after reading
}

void calculateCGPPA()
{
    std::ofstream out;
    out.open("cgpa.txt");
    double quiz, assign, cp, mid1, mid2, final, total;

    // Call dataRetrieval() to populate s1, s2, s3, s4, s5 arrays
    dataRetrieval();

    // Process for subject s1
    for (int x = 0; x < 30 && s1[x][1] != ""; ++x)
    {
        quiz = std::stod(s1[x][1]) + std::stod(s1[x][2]);
        assign = std::stod(s1[x][3]) + std::stod(s1[x][4]);
        cp = std::stod(s1[x][5]);
        mid1 = std::stod(s1[x][6]);
        mid2 = std::stod(s1[x][7]);
        final = std::stod(s1[x][8]);

        // Calculations for s1 subject
        quiz = (quiz / 10) * 10;
        assign = (assign / 10) * 5;
        cp = (cp / 10) * 5;
        mid1 = (mid1 / 50) * 15;
        mid2 = (mid2 / 10) * 15;
        final = (final / 100) * 50;

        total = quiz + assign + cp + mid1 + mid2 + final;

        // Assign CGPA to s1[x][9]
        if (total > 90)
        {
            s1[x][9] = "4.0";
        }
        else if (total > 80)
        {
            s1[x][9] = "3.5";
        }
        else if (total > 70)
        {
            s1[x][9] = "3.0";
        }
        else if (total > 60)
        {
            s1[x][9] = "2.5";
        }
        else if (total > 50)
        {
            s1[x][9] = "2.0";
        }
        else
        {
            s1[x][9] = "1.5";
        }
    }

    // Process for subject s2
    for (int x = 0; x < 30 && s2[x][1] != ""; ++x)
    {
        quiz = std::stod(s2[x][1]) + std::stod(s2[x][2]);
        assign = std::stod(s2[x][3]) + std::stod(s2[x][4]);
        cp = std::stod(s2[x][5]);
        mid1 = std::stod(s2[x][6]);
        mid2 = std::stod(s2[x][7]);
        final = std::stod(s2[x][8]);

        quiz = (quiz / 10) * 10;
        assign = (assign / 10) * 5;
        cp = (cp / 10) * 5;
        mid1 = (mid1 / 50) * 15;
        mid2 = (mid2 / 10) * 15;
        final = (final / 100) * 50;

        total = quiz + assign + cp + mid1 + mid2 + final;

        if (total > 90)
        {
            s2[x][9] = "4.0";
        }
        else if (total > 80)
        {
            s2[x][9] = "3.5";
        }
        else if (total > 70)
        {
            s2[x][9] = "3.0";
        }
        else if (total > 60)
        {
            s2[x][9] = "2.5";
        }
        else if (total > 50)
        {
            s2[x][9] = "2.0";
        }
        else
        {
            s2[x][9] = "1.5";
        }
    }


    // Process for subject s3
    for (int x = 0; x < 30 && s3[x][1] != ""; ++x)
    {
        quiz = std::stod(s3[x][1]) + std::stod(s3[x][2]);
        assign = std::stod(s3[x][3]) + std::stod(s3[x][4]);
        cp = std::stod(s3[x][5]);
        mid1 = std::stod(s3[x][6]);
        mid2 = std::stod(s3[x][7]);
        final = std::stod(s3[x][8]);

        quiz = (quiz / 10) * 10;
        assign = (assign / 10) * 5;
        cp = (cp / 10) * 5;
        mid1 = (mid1 / 50) * 15;
        mid2 = (mid2 / 10) * 15;
        final = (final / 100) * 50;

        total = quiz + assign + cp + mid1 + mid2 + final;

        if (total > 90)
        {
            s3[x][9] = "4.0";
        }
        else if (total > 80)
        {
            s3[x][9] = "3.5";
        }
        else if (total > 70)
        {
            s3[x][9] = "3.0";
        }
        else if (total > 60)
        {
            s3[x][9] = "2.5";
        }
        else if (total > 50)
        {
            s3[x][9] = "2.0";
        }
        else
        {
            s3[x][9] = "1.5";
        }
    }

    // Process for subject s4
    for (int x = 0; x < 30 && s4[x][1] != ""; ++x)
    {
        quiz = std::stod(s4[x][1]) + std::stod(s4[x][2]);
        assign = std::stod(s4[x][3]) + std::stod(s4[x][4]);
        cp = std::stod(s4[x][5]);
        mid1 = std::stod(s4[x][6]);
        mid2 = std::stod(s4[x][7]);
        final = std::stod(s4[x][8]);

        quiz = (quiz / 10) * 10;
        assign = (assign / 10) * 5;
        cp = (cp / 10) * 5;
        mid1 = (mid1 / 50) * 15;
        mid2 = (mid2 / 10) * 15;
        final = (final / 100) * 50;

        total = quiz + assign + cp + mid1 + mid2 + final;

        if (total > 90)
        {
            s4[x][9] = "4.0";
        }
        else if (total > 80)
        {
            s4[x][9] = "3.5";
        }
        else if (total > 70)
        {
            s4[x][9] = "3.0";
        }
        else if (total > 60)
        {
            s4[x][9] = "2.5";
        }
        else if (total > 50)
        {
            s4[x][9] = "2.0";
        }
        else
        {
            s4[x][9] = "1.5";
        }
    }


    // Process for subject s5
    for (int x = 0; x < 30 && s5[x][1] != ""; ++x)
    {
        quiz = std::stod(s5[x][1]) + std::stod(s5[x][2]);
        assign = std::stod(s5[x][3]) + std::stod(s5[x][4]);
        cp = std::stod(s5[x][5]);
        mid1 = std::stod(s5[x][6]);
        mid2 = std::stod(s5[x][7]);
        final = std::stod(s5[x][8]);

        quiz = (quiz / 10) * 10;
        assign = (assign / 10) * 5;
        cp = (cp / 10) * 5;
        mid1 = (mid1 / 50) * 15;
        mid2 = (mid2 / 10) * 15;
        final = (final / 100) * 50;

        total = quiz + assign + cp + mid1 + mid2 + final;

        if (total > 90)
        {
            s5[x][9] = "4.0";
        }
        else if (total > 80)
        {
            s5[x][9] = "3.5";
        }
        else if (total > 70)
        {
            s5[x][9] = "3.0";
        }
        else if (total > 60)
        {
            s5[x][9] = "2.5";
        }
        else if (total > 50)
        {
            s5[x][9] = "2.0";
        }
        else
        {
            s5[x][9] = "1.5";
        }
    }


    // Calculate CGPA based on the grades in each subject
    for (int x = 0; x < 30 && s1[x][1] != ""; ++x)
    {
        cgpa[x][0] = s1[x][0];  // Store roll number

        total = 0;
        total = std::stod(s1[x][9]) + std::stod(s2[x][9]) + std::stod(s3[x][9]) + std::stod(s4[x][9]) + std::stod(s5[x][9]);
        total = total / 5;
        cgpa[x][1] = std::to_string(total);  // Store calculated CGPA
    }

    // Write CGPA to file
    for (int x = 0; x < 30 && cgpa[x][0] != ""; ++x)
    {
        out << cgpa[x][0] << " " << cgpa[x][1] << std::endl;
    }

    out.close();
}

void cgpaRetrieval()
{
    // Calls calculateCGPPA() function to populate the cgpa array
    calculateCGPPA();
    int index, row = 0, col = 0;
    std::string line, temp;
    std::ifstream in("cgpa.txt");

    // Check if the file is open successfully
    if (!in.is_open())
    {
        std::cerr << "Error: Unable to open cgpa.txt for reading.\n";
        return;
    }

    // Read the contents of the cgpa.txt file line by line
    while (std::getline(in, line))
    {
        temp = "";
        index = 0;
        col = 0;

        // Read the first value (Roll number) until a space is encountered
        while (index < line.length() && !isspace(line[index]))
        {
            temp += line[index];
            ++index;
        }
        cgpa[row][col] = temp;  // Store Roll Number
        ++col;  // Move to the next column (for CGPA)

        // Skip any spaces between roll number and CGPA
        while (index < line.length() && isspace(line[index]))
        {
            ++index;
        }

        temp = "";  // Clear the temporary string for CGPA

        // Read the second value (CGPA) until the end of the line
        while (index < line.length())
        {
            temp += line[index];
            ++index;
        }
        cgpa[row][col] = temp;  // Store CGPA
        ++row;  // Move to the next row
    }

    in.close();  // Close the file

}

void passStudents()
{
    std::string pass[30][2];
    int row = 0;
    std::string roll;
    dataRetrieval();  // Retrieve student data
    cgpaRetrieval();  // Retrieve CGPA data

    // Loop through the students and check if their CGPA is greater than or equal to 2
    for (int x = 0; x < 30 && cgpa[x][0] != ""; ++x)
    {
        if (std::stod(cgpa[x][1]) >= 2)
        {
            pass[row][0] = cgpa[x][0];  // Store Roll Number
            pass[row][1] = cgpa[x][1];  // Store CGPA
            ++row;
        }
    }

    // Display the list of passed students
    std::cout << "List of Passed Students: " << std::endl;
    for (int x = 0; x < 30; ++x)
    {
        for (int y = 0; y < 2; ++y)
        {
            std::cout << pass[x][y] << " ";  // Print Roll Number and CGPA
        }
        std::cout << std::endl;
    }

}

void failStudents()
{
    std::string fail[30][2];
    int row = 0;
    std::string roll;
    dataRetrieval();  // Retrieve student data
    cgpaRetrieval();  // Retrieve CGPA data

    // Loop through the students and check if their CGPA is less than 2
    for (int x = 0; x < 30 && cgpa[x][0] != ""; ++x)
    {
        if (std::stod(cgpa[x][1]) < 2)
        {
            fail[row][0] = cgpa[x][0];  // Store Roll Number
            fail[row][1] = cgpa[x][1];  // Store CGPA
            ++row;
        }
    }

    // Display the list of failed students
    std::cout << "List of Failed Students: " << std::endl;
    for (int x = 0; x < 30; ++x)
    {
        for (int y = 0; y < 2; ++y)
        {
            std::cout << fail[x][y] << " ";  // Print Roll Number and CGPA
        }
        std::cout << std::endl;
    }

}

void ascend()
{
    cgpaRetrieval();  // Retrieve CGPA data
    dataRetrieval();  // Retrieve student data
    std::string tempROLL, tempGPA, name;

    // Sorting students in ascending order based on CGPA using bubble sort
    for (int repeat = 0; repeat < 30; ++repeat)
    {
        for (int x = 0; x < 30 && cgpa[x][0] != "" && cgpa[x + 1][0] != ""; ++x)
        {
            if (std::stod(cgpa[x][1]) > std::stod(cgpa[x + 1][1]))
            {
                tempGPA = cgpa[x + 1][1];
                tempROLL = cgpa[x + 1][0];
                cgpa[x + 1][1] = cgpa[x][1];
                cgpa[x + 1][0] = cgpa[x][0];
                cgpa[x][1] = tempGPA;
                cgpa[x][0] = tempROLL;
            }
        }
    }

    // Display the list of students sorted in ascending order according to CGPA
    std::cout << "List of Students in Ascending Order according to CGPA: " << std::endl;
    for (int x = 0; x < 30 && cgpa[x][0] != ""; ++x)
    {
        for (int y = 0; y < 2; ++y)
        {
            std::cout << cgpa[x][y] << " ";  // Print Roll Number and CGPA
        }
        std::cout << std::endl;
    }

}

void descend()
{
    cgpaRetrieval();  // Retrieve CGPA data
    dataRetrieval();  // Retrieve student data
    std::string tempROLL, tempGPA, name;

    // Sorting students in ascending order based on CGPA using bubble sort
    for (int repeat = 0; repeat < 30; ++repeat)
    {
        for (int x = 0; x < 30 && cgpa[x][0] != "" && cgpa[x + 1][0] != ""; ++x)
        {
            if (std::stod(cgpa[x][1]) > std::stod(cgpa[x + 1][1]))
            {
                tempGPA = cgpa[x + 1][1];
                tempROLL = cgpa[x + 1][0];
                cgpa[x + 1][1] = cgpa[x][1];
                cgpa[x + 1][0] = cgpa[x][0];
                cgpa[x][1] = tempGPA;
                cgpa[x][0] = tempROLL;
            }
        }
    }

    // Display the list of students sorted in descending order according to CGPA
    std::cout << "List of Students in Descending Order according to CGPA: " << std::endl;
    for (int x = 29; x >= 0; --x)
    {
        for (int y = 0; y < 2; ++y)
        {
            std::cout << cgpa[x][y] << " ";  // Print Roll Number and CGPA
        }
        std::cout << std::endl;
    }
}

void viewGrade(std::string roll)
{
    int index;
    double avg, min, max;
    std::string subject, response;
    dataRetrieval();  // Retrieve data
    cgpaRetrieval();  // Retrieve CGPA data
    std::cout << "Press 1 to view cgpa and 2 to view grades: ";
    std::getline(std::cin, response);
    if (response == "1")
    {
        // Display CGPA for the given roll number
        for (int x = 0; x < 30; ++x)
        {
            if (roll == cgpa[x][0])
            {
                std::cout << "Your CGPA is " << cgpa[x][1] << std::endl;
            }
        }
    }
    else if (response == "2")
    {
        // Get subject ID from user
        std::cout << "Please enter the Subject ID you want to see grades of : ";
        std::getline(std::cin, subject);
        if (subject == "MS101")
        {
            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (s1[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Quiz 1
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                avg += std::stod(s1[x][1]);
            }
            avg = avg / 30;
            min = std::stod(s1[0][1]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (min > std::stod(s1[x][1]))
                {
                    min = std::stod(s1[x][1]);
                }
            }
            max = std::stod(s1[0][1]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (max < std::stod(s1[x][1]))
                {
                    max = std::stod(s1[x][1]);
                }
            }

            // Display Quiz 1 results
            std::cout << "Quizzes : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s1[index][1] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;

            // Calculate average, min, max for Quiz 2
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                avg += std::stod(s1[x][2]);
            }
            avg = avg / 30;
            min = std::stod(s1[0][2]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (min > std::stod(s1[x][2]))
                {
                    min = std::stod(s1[x][2]);
                }
            }
            max = std::stod(s1[0][2]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (max < std::stod(s1[x][2]))
                {
                    max = std::stod(s1[x][2]);
                }
            }

            // Display Quiz 2 results
            std::cout << "2        " << s1[index][2] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;

            // Calculate average, min, max for Assignment 1
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                avg += std::stod(s1[x][3]);
            }
            avg = avg / 30;
            min = std::stod(s1[0][3]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (min > std::stod(s1[x][3]))
                {
                    min = std::stod(s1[x][3]);
                }
            }
            max = std::stod(s1[0][3]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (max < std::stod(s1[x][3]))
                {
                    max = std::stod(s1[x][3]);
                }
            }
            // Display Assignment 1 results
            std::cout << "Assignments : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s1[index][3] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for Assignment 2
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                avg += std::stod(s1[x][4]);
            }
            avg = avg / 30;
            min = std::stod(s1[0][4]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (min > std::stod(s1[x][4]))
                {
                    min = std::stod(s1[x][4]);
                }
            }
            max = std::stod(s1[0][4]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (max < std::stod(s1[x][4]))
                {
                    max = std::stod(s1[x][4]);
                }
            }
            // Display Assignment 2 results
            std::cout << "2        " << s1[index][4] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for Class Participation
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                avg += std::stod(s1[x][5]);
            }
            avg = avg / 30;
            min = std::stod(s1[0][5]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (min > std::stod(s1[x][5]))
                {
                    min = std::stod(s1[x][5]);
                }
            }
            max = std::stod(s1[0][5]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (max < std::stod(s1[x][5]))
                {
                    max = std::stod(s1[x][5]);
                }
            }
            // Display Class Participation results
            std::cout << "Class Participation : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s1[index][5] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for MID-I
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                avg += std::stod(s1[x][6]);
            }
            avg = avg / 30;
            min = std::stod(s1[0][6]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (min > std::stod(s1[x][6]))
                {
                    min = std::stod(s1[x][6]);
                }
            }
            max = std::stod(s1[0][6]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (max < std::stod(s1[x][6]))
                {
                    max = std::stod(s1[x][6]);
                }
            }
            // Display MID-I results
            std::cout << "MID-I : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s1[index][6] << "          " << avg << "          " << min << "          " << max << std::endl;


            avg = 0;
            // Calculate average, min, max for MID-II
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                avg += std::stod(s1[x][7]);
            }
            avg = avg / 30;
            min = std::stod(s1[0][7]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (min > std::stod(s1[x][7]))
                {
                    min = std::stod(s1[x][7]);
                }
            }
            max = std::stod(s1[0][7]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (max < std::stod(s1[x][7]))
                {
                    max = std::stod(s1[x][7]);
                }
            }
            // Display MID-II results
            std::cout << "MID-II : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s1[index][7] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for Final
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                avg += std::stod(s1[x][8]);
            }
            avg = avg / 30;
            min = std::stod(s1[0][8]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (min > std::stod(s1[x][8]))
                {
                    min = std::stod(s1[x][8]);
                }
            }
            max = std::stod(s1[0][7]);
            for (int x = 0; x < 30 && s1[x][0] != ""; ++x)
            {
                if (max < std::stod(s1[x][8]))
                {
                    max = std::stod(s1[x][8]);
                }
            }
            // Display Final results
            std::cout << "Final : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s1[index][8] << "          " << avg << "          " << min << "          " << max << std::endl;
        }

        else if (subject == "MS102")
        {
            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30; ++x)
            {
                if (s2[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Quiz 1
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                avg += std::stod(s2[x][1]);
            }
            avg = avg / 30;
            min = std::stod(s2[0][1]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (min > std::stod(s2[x][1]))
                {
                    min = std::stod(s2[x][1]);
                }
            }
            max = std::stod(s2[0][1]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (max < std::stod(s2[x][1]))
                {
                    max = std::stod(s2[x][1]);
                }
            }

            // Display Quiz 1 results
            std::cout << "Quizzes : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s2[index][1] << "          " << avg << "          " << min << "          " << max << std::endl;

            // Now applying to the rest of the subjects similarly

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (s2[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Quiz 2
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                avg += std::stod(s2[x][2]);
            }
            avg = avg / 30;
            min = std::stod(s2[0][2]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (min > std::stod(s2[x][2]))
                {
                    min = std::stod(s2[x][2]);
                }
            }
            max = std::stod(s2[0][2]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (max < std::stod(s2[x][2]))
                {
                    max = std::stod(s2[x][2]);
                }
            }
            // Display Quiz 2 results
            std::cout << "2        " << s2[index][2] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (s2[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, maxfor Assignment 1
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                avg += std::stod(s2[x][3]);
            }
            avg = avg / 30;
            min = std::stod(s2[0][3]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (min > std::stod(s2[x][3]))
                {
                    min = std::stod(s2[x][3]);
                }
            }
            max = std::stod(s2[0][3]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (max < std::stod(s2[x][3]))
                {
                    max = std::stod(s2[x][3]);
                }
            }
            // Display Assignment 1 results
            std::cout << "Assignments : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s2[index][3] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (s2[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Assignment 2
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                avg += std::stod(s2[x][4]);
            }
            avg = avg / 30;
            min = std::stod(s2[0][4]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (min > std::stod(s2[x][4]))
                {
                    min = std::stod(s2[x][4]);
                }
            }
            max = std::stod(s2[0][4]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (max < std::stod(s2[x][4]))
                {
                    max = std::stod(s2[x][4]);
                }
            }
            // Display Assignment 2 results
            std::cout << "2        " << s2[index][4] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (s2[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Class Participation
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                avg += std::stod(s2[x][5]);
            }
            avg = avg / 30;
            min = std::stod(s2[0][5]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (min > std::stod(s2[x][5]))
                {
                    min = std::stod(s2[x][5]);
                }
            }
            max = std::stod(s2[0][5]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (max < std::stod(s2[x][5]))
                {
                    max = std::stod(s2[x][5]);
                }
            }
            // Display Class Participation results
            std::cout << "Class Participation : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s2[index][5] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (s2[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for MID-I
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                avg += std::stod(s2[x][6]);
            }
            avg = avg / 30;
            min = std::stod(s2[0][6]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (min > std::stod(s2[x][6]))
                {
                    min = std::stod(s2[x][6]);
                }
            }
            max = std::stod(s2[0][6]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (max < std::stod(s2[x][6]))
                {
                    max = std::stod(s2[x][6]);
                }
            }
            // Display MID-I results
            std::cout << "MID-I : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s2[index][6] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (s2[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for MID-II
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                avg += std::stod(s2[x][7]);
            }
            avg = avg / 30;
            min = std::stod(s2[0][7]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (min > std::stod(s2[x][7]))
                {
                    min = std::stod(s2[x][7]);
                }
            }
            max = std::stod(s2[0][7]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (max < std::stod(s2[x][7]))
                {
                    max = std::stod(s2[x][7]);
                }
            }
            // Display MID-II results
            std::cout << "MID-II : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s2[index][7] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (s2[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Final
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                avg += std::stod(s2[x][8]);
            }
            avg = avg / 30;
            min = std::stod(s2[0][8]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (min > std::stod(s2[x][8]))
                {
                    min = std::stod(s2[x][8]);
                }
            }
            max = std::stod(s2[0][8]);
            for (int x = 0; x < 30 && s2[x][0] != ""; ++x)
            {
                if (max < std::stod(s2[x][8]))
                {
                    max = std::stod(s2[x][8]);
                }
            }
            // Display Final results
            std::cout << "Final : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s2[index][8] << "          " << avg << "          " << min << "          " << max << std::endl;
        }

        else if (subject == "MS103")
        {
            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (s3[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Quiz 1
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                avg += std::stod(s3[x][1]);
            }
            avg = avg / 30;
            min = std::stod(s3[0][1]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (min > std::stod(s3[x][1]))
                {
                    min = std::stod(s3[x][1]);
                }
            }
            max = std::stod(s3[0][1]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (max < std::stod(s3[x][1]))
                {
                    max = std::stod(s3[x][1]);
                }
            }

            // Display Quiz 1 results
            std::cout << "Quizzes : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s3[index][1] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (s3[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Quiz 2
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                avg += std::stod(s3[x][2]);
            }
            avg = avg / 30;
            min = std::stod(s3[0][2]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (min > std::stod(s3[x][2]))
                {
                    min = std::stod(s3[x][2]);
                }
            }
            max = std::stod(s3[0][2]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (max < std::stod(s3[x][2]))
                {
                    max = std::stod(s3[x][2]);
                }
            }
            // Display Quiz 2 results
            std::cout << "2        " << s3[index][2] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (s3[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Assignment 1
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                avg += std::stod(s3[x][3]);
            }
            avg = avg / 30;
            min = std::stod(s3[0][3]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (min > std::stod(s3[x][3]))
                {
                    min = std::stod(s3[x][3]);
                }
            }
            max = std::stod(s3[0][3]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (max < std::stod(s3[x][3]))
                {
                    max = std::stod(s3[x][3]);
                }
            }

            // Display Assignment 1 results
            std::cout << "Assignments : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s3[index][3] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (s3[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Assignment 2
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                avg += std::stod(s3[x][4]);
            }
            avg = avg / 30;
            min = std::stod(s3[0][4]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (min > std::stod(s3[x][4]))
                {
                    min = std::stod(s3[x][4]);
                }
            }
            max = std::stod(s3[0][4]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (max < std::stod(s3[x][4]))
                {
                    max = std::stod(s3[x][4]);
                }
            }
            // Display Assignment 2 results
            std::cout << "2        " << s3[index][4] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (s3[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Class Participation
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                avg += std::stod(s3[x][5]);
            }
            avg = avg / 30;
            min = std::stod(s3[0][5]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (min > std::stod(s3[x][5]))
                {
                    min = std::stod(s3[x][5]);
                }
            }
            max = std::stod(s3[0][5]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (max < std::stod(s3[x][5]))
                {
                    max = std::stod(s3[x][5]);
                }
            }
            // Display Class Participation results
            std::cout << "Class Participation : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s3[index][5] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (s3[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for MID-I
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                avg += std::stod(s3[x][6]);
            }
            avg = avg / 30;
            min = std::stod(s3[0][6]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (min > std::stod(s3[x][6]))
                {
                    min = std::stod(s3[x][6]);
                }
            }
            max = std::stod(s3[0][6]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (max < std::stod(s3[x][6]))
                {
                    max = std::stod(s3[x][6]);
                }
            }
            // Display MID-I results
            std::cout << "MID-I : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s3[index][6] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (s3[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for MID-II
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                avg += std::stod(s3[x][7]);
            }
            avg = avg / 30;
            min = std::stod(s3[0][7]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (min > std::stod(s3[x][7]))
                {
                    min = std::stod(s3[x][7]);
                }
            }
            max = std::stod(s3[0][7]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (max < std::stod(s3[x][7]))
                {
                    max = std::stod(s3[x][7]);
                }
            }
            // Display MID-II results
            std::cout << "MID-II : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s3[index][7] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (s3[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Final
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                avg += std::stod(s3[x][8]);
            }
            avg = avg / 30;
            min = std::stod(s3[0][8]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (min > std::stod(s3[x][8]))
                {
                    min = std::stod(s3[x][8]);
                }
            }
            max = std::stod(s3[0][8]);
            for (int x = 0; x < 30 && s3[x][0] != ""; ++x)
            {
                if (max < std::stod(s3[x][8]))
                {
                    max = std::stod(s3[x][8]);
                }
            }
            // Display Final results
            std::cout << "Final : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s3[index][8] << "          " << avg << "          " << min << "          " << max << std::endl;
        }

        else if (subject == "MS104")
        {
            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (s4[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Quiz 1
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                avg += std::stod(s4[x][1]);
            }
            avg = avg / 30;
            min = std::stod(s4[0][1]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (min > std::stod(s4[x][1]))
                {
                    min = std::stod(s4[x][1]);
                }
            }
            max = std::stod(s4[0][1]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (max < std::stod(s4[x][1]))
                {
                    max = std::stod(s4[x][1]);
                }
            }

            // Display Quiz 1 results
            std::cout << "Quizzes : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s4[index][1] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (s4[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Quiz 2
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                avg += std::stod(s4[x][2]);
            }
            avg = avg / 30;
            min = std::stod(s4[0][2]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (min > std::stod(s4[x][2]))
                {
                    min = std::stod(s4[x][2]);
                }
            }
            max = std::stod(s4[0][2]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (max < std::stod(s4[x][2]))
                {
                    max = std::stod(s4[x][2]);
                }
            }
            // Display Quiz 2 results
            std::cout << "2        " << s4[index][2] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (s4[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Assignment 1
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                avg += std::stod(s4[x][3]);
            }
            avg = avg / 30;
            min = std::stod(s4[0][3]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (min > std::stod(s4[x][3]))
                {
                    min = std::stod(s4[x][3]);
                }
            }
            max = std::stod(s4[0][3]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (max < std::stod(s4[x][3]))
                {
                    max = std::stod(s4[x][3]);
                }
            }

            // Display Assignment 1 results
            std::cout << "Assignments : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s4[index][3] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (s4[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Assignment 2
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                avg += std::stod(s4[x][4]);
            }
            avg = avg / 30;
            min = std::stod(s4[0][4]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (min > std::stod(s4[x][4]))
                {
                    min = std::stod(s4[x][4]);
                }
            }
            max = std::stod(s4[0][4]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (max < std::stod(s4[x][4]))
                {
                    max = std::stod(s4[x][4]);
                }
            }
            // Display Assignment 2 results
            std::cout << "2        " << s4[index][4] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (s4[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Class Participation
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                avg += std::stod(s4[x][5]);
            }
            avg = avg / 30;
            min = std::stod(s4[0][5]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (min > std::stod(s4[x][5]))
                {
                    min = std::stod(s4[x][5]);
                }
            }
            max = std::stod(s4[0][5]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (max < std::stod(s4[x][5]))
                {
                    max = std::stod(s4[x][5]);
                }
            }
            // Display Class Participation results
            std::cout << "Class Participation : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s4[index][5] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (s4[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for MID-I
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                avg += std::stod(s4[x][6]);
            }
            avg = avg / 30;
            min = std::stod(s4[0][6]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (min > std::stod(s4[x][6]))
                {
                    min = std::stod(s4[x][6]);
                }
            }
            max = std::stod(s4[0][6]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (max < std::stod(s4[x][6]))
                {
                    max = std::stod(s4[x][6]);
                }
            }
            // Display MID-I results
            std::cout << "MID-I : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s4[index][6] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (s4[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for MID-II
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                avg += std::stod(s4[x][7]);
            }
            avg = avg / 30;
            min = std::stod(s4[0][7]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (min > std::stod(s4[x][7]))
                {
                    min = std::stod(s4[x][7]);
                }
            }
            max = std::stod(s4[0][7]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (max < std::stod(s4[x][7]))
                {
                    max = std::stod(s4[x][7]);
                }
            }
            // Display MID-II results
            std::cout << "MID-II : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s4[index][7] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Find index of student in array
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (s4[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate average, min, max for Final
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                avg += std::stod(s4[x][8]);
            }
            avg = avg / 30;
            min = std::stod(s4[0][8]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (min > std::stod(s4[x][8]))
                {
                    min = std::stod(s4[x][8]);
                }
            }
            max = std::stod(s4[0][8]);
            for (int x = 0; x < 30 && s4[x][0] != ""; ++x)
            {
                if (max < std::stod(s4[x][8]))
                {
                    max = std::stod(s4[x][8]);
                }
            }
            // Display Final results
            std::cout << "Final : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s4[index][8] << "          " << avg << "          " << min << "          " << max << std::endl;
        }

        else if (subject == "MS105")
        {
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (s5[x][0] == roll)
                {
                    index = x;
                    break;
                }
            }

            // Calculate and display statistics for Quizzes
            avg = 0;
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                avg += std::stod(s5[x][1]);
            }
            avg = avg / 30;
            min = std::stod(s5[0][1]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (min > std::stod(s5[x][1]))
                {
                    min = std::stod(s5[x][1]);
                }
            }
            max = std::stod(s5[0][1]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (max < std::stod(s5[x][1]))
                {
                    max = std::stod(s5[x][1]);
                }
            }

            std::cout << "Quizzes : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s5[index][1] << "          " << avg << "          " << min << "          " << max << std::endl;

            // Add the following code after the Quiz 1 section for MS105 (s5 array):

            avg = 0;
            // Calculate average, min, max for Quiz 2
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                avg += std::stod(s5[x][2]);
            }
            avg = avg / 30;
            min = std::stod(s5[0][2]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (min > std::stod(s5[x][2]))
                {
                    min = std::stod(s5[x][2]);
                }
            }
            max = std::stod(s5[0][2]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (max < std::stod(s5[x][2]))
                {
                    max = std::stod(s5[x][2]);
                }
            }
            // Display Quiz 2 results
            std::cout << "2        " << s5[index][2] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for Assignment 1
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                avg += std::stod(s5[x][3]);
            }
            avg = avg / 30;
            min = std::stod(s5[0][3]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (min > std::stod(s5[x][3]))
                {
                    min = std::stod(s5[x][3]);
                }
            }
            max = std::stod(s5[0][3]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (max < std::stod(s5[x][3]))
                {
                    max = std::stod(s5[x][3]);
                }
            }
            // Display Assignment 1 results
            std::cout << "Assignments : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s5[index][3] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for Assignment 2
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                avg += std::stod(s5[x][4]);
            }
            avg = avg / 30;
            min = std::stod(s5[0][4]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (min > std::stod(s5[x][4]))
                {
                    min = std::stod(s5[x][4]);
                }
            }
            max = std::stod(s5[0][4]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (max < std::stod(s5[x][4]))
                {
                    max = std::stod(s5[x][4]);
                }
            }
            // Display Assignment 2 results
            std::cout << "2        " << s5[index][4] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for Class Participation
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                avg += std::stod(s5[x][5]);
            }
            avg = avg / 30;
            min = std::stod(s5[0][5]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (min > std::stod(s5[x][5]))
                {
                    min = std::stod(s5[x][5]);
                }
            }
            max = std::stod(s5[0][5]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (max < std::stod(s5[x][5]))
                {
                    max = std::stod(s5[x][5]);
                }
            }
            // Display Class Participation results
            std::cout << "Class Participation : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s5[index][5] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for MID-I
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                avg += std::stod(s5[x][6]);
            }
            avg = avg / 30;
            min = std::stod(s5[0][6]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (min > std::stod(s5[x][6]))
                {
                    min = std::stod(s5[x][6]);
                }
            }
            max = std::stod(s5[0][6]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (max < std::stod(s5[x][6]))
                {
                    max = std::stod(s5[x][6]);
                }
            }
            // Display MID-I results
            std::cout << "MID-I : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s5[index][6] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for MID-II
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                avg += std::stod(s5[x][7]);
            }
            avg = avg / 30;
            min = std::stod(s5[0][7]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (min > std::stod(s5[x][7]))
                {
                    min = std::stod(s5[x][7]);
                }
            }
            max = std::stod(s5[0][7]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (max < std::stod(s5[x][7]))
                {
                    max = std::stod(s5[x][7]);
                }
            }
            // Display MID-II results
            std::cout << "MID-II : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s5[index][7] << "          " << avg << "          " << min << "          " << max << std::endl;

            avg = 0;
            // Calculate average, min, max for Final
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                avg += std::stod(s5[x][8]);
            }
            avg = avg / 30;
            min = std::stod(s5[0][8]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (min > std::stod(s5[x][8]))
                {
                    min = std::stod(s5[x][8]);
                }
            }
            max = std::stod(s5[0][8]);
            for (int x = 0; x < 30 && s5[x][0] != ""; ++x)
            {
                if (max < std::stod(s5[x][8]))
                {
                    max = std::stod(s5[x][8]);
                }
            }
            // Display Final results
            std::cout << "Final : " << std::endl;
            std::cout << "#" << "     OBTAINED" << "   AVERAGE" << "    MINIMUM" << "    MAXIMUM" << std::endl;
            std::cout << "1        " << s5[index][8] << "          " << avg << "          " << min << "          " << max << std::endl;
        }
    }
}

bool adminVerify()
{
    std::string username, password, line, tempuser = "", temppass = "";
    bool found = 0;

    // Start of username and password input loop
    while (found == 0)
    {
        system("cls"); // Clears the screen before entering the credentials

        std::cout << "Enter your Username: ";
        std::getline(std::cin, username);

        // Username validation: Check if length is exactly 4
        if (username.length() > 4 || username.length() < 4)
        {
            std::cout << "Enter 4 digit username and in numbers!" << std::endl;
        }
        else
        {
            std::cout << "Enter your Password: ";
            std::getline(std::cin, password);

            // Password validation: Check if length is exactly 4
            if (password.length() > 4 || password.length() < 4)
            {
                std::cout << "Enter 4 digit password and in character" << std::endl;
            }
            if (username.length() == 4 && password.length() == 4)
            {
                found = 1; // Username and password valid, exit loop
            }
        }
    }

    std::ifstream in;
    in.open("adminVerify.txt"); // Open the file to verify credentials
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            // Extract username and password from the line
            for (int i = 0; i < 4; i++)
            {
                tempuser += line[i];
            }
            for (int i = 5; i < 9; i++)
            {
                temppass += line[i];
            }

            // Check if the username and password match
            if (tempuser == username && temppass == password)
            {
                std::cout << "Successfully Logged In!" << std::endl;
                return 1; // Credentials match, return success
            }
            else
            {
                std::cout << "Invalid Username or password!" << std::endl;
                return 0; // Invalid credentials, return failure
            }
        }
    }
    else
    {
        std::cout << "Error opening the file!" << std::endl;
    }
}

bool checkFile()
{
    int count = 0;
    std::ifstream in;
    std::string line;

    in.open("s1.txt"); // Open the file to check student count
    if (!in.is_open())
    {
        std::cout << "Error opening the file!" << std::endl;
    }
    else
    {
        while (std::getline(in, line))
        {
            ++count; // Count the lines (students)
        }

        // If there are more than 30 students, return error
        if (count > 29)
        {
            std::cout << "Students cannot exceed the 30 limit!" << std::endl;
            return 0;
        }
        else
        {
            return 1; // Student count is valid
        }
    }
    in.close();
}

bool checkFileforRemove()
{
    int count = 0;
    std::ifstream in;
    std::string line;

    in.open("s1.txt"); // Open the file to check if there are students to remove
    if (!in.is_open())
    {
        std::cout << "Error opening the file!" << std::endl;
    }
    else
    {
        while (std::getline(in, line))
        {
            ++count; // Count the lines (students)
        }

        // If there's only one student, we can't remove anyone
        if (count == 1)
        {
            std::cout << "There are no students available to delete!" << std::endl;
            return 0;
        }
        else
        {
            return 1; // There are students to remove
        }
    }
    in.close();
}

bool ischar(std::string s1)
{
    int count = 0;
    for (int x = 0; x < s1.length(); ++x)
    {
        // Check if the string contains only alphabetic characters
        if (isalpha(s1[x]))
        {
            return 1; // If it contains an alphabetic character, return true
            break;
        }
        else
        {
            ++count;
        }
        if (count == s1.length())
        {
            return 0; // If no alphabetic character is found, return false
        }
    }
}

bool validate(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8)
{
    // Validate if all strings are 3 or fewer characters long and none of them contain alphabetic characters
    if (s1.length() <= 3 && s2.length() <= 3 && s3.length() <= 3 && s4.length() <= 3 && s5.length() <= 3 && s6.length() <= 3 && s7.length() <= 3 && s8.length() <= 3)
    {
        if (!ischar(s1) && !ischar(s2) && !ischar(s3) && !ischar(s4) && !ischar(s5) && !ischar(s6) && !ischar(s7) && !ischar(s8))
        {
            return 1; // Valid if all conditions are met
        }
        else
        {
            return 0; // Invalid if any string contains alphabetic characters
        }
    }
    else
    {
        return 0; // Invalid if any string is longer than 3 characters
    }
}
