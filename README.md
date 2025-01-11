# Student Management System (SMS)

Welcome to the **Student Management System** (SMS)! This project was developed as part of the **Programming Fundamentals Semester Project** during my freshman year at university. The SMS is a console-based application built in **C++**, aiming to simplify student and teacher data management tasks.

---

## **Features**

### **Admin Module**
- **Add Teachers**: Enables adding new teachers with their credentials and subject details.
- **Remove Teachers**: Facilitates the removal of teacher records by their ID.

### **Teacher Module**
- **Add Students**: Allows teachers to input student data, including subject-specific grades.
- **Remove Students**: Provides functionality to delete student records by their roll number.
- **Student Performance**:
  - Calculate CGPA for students across multiple subjects.
  - View lists of **passed** or **failed** students.
  - Sort student data by CGPA in **ascending** or **descending** order.

### **Student Module**
- **View Grades and CGPA**: Students can log in to view their grades for individual subjects and their overall CGPA.

---

## **Getting Started**

### **Prerequisites**
- A C++ compiler (e.g., GCC or MSVC).
- Basic understanding of file handling in C++ for data storage.

### **Setup Instructions**
1. Clone this repository:  
   ```bash
   git clone https://github.com/your-username/Student-Management-System.git
   ```
2. Navigate to the project directory:  
   ```bash
   cd Student-Management-System
   ```
3. Compile the project using your C++ compiler. For example:  
   ```bash
   g++ -o sms main.cpp
   ```
4. Run the compiled program:  
   ```bash
   ./sms
   ```

---

## **How It Works**

### **Data Storage**
- All records are stored in text files:
  - `s1.txt`, `s2.txt`, `s3.txt`, `s4.txt`, `s5.txt`: Subject-specific student data.
  - `admin.txt`: Teacher records.
  - `cgpa.txt`: Computed CGPA for students.

### **Core Functionalities**
- **Validation**: Ensures that all inputs are valid (e.g., roll numbers must be 4 digits).
- **CGPA Calculation**: Computes CGPA based on quizzes, assignments, participation, and exams.

---

## **Lessons Learned**
Through this project, I enhanced my skills in:
- **File Handling**: Reading and writing structured data to/from files.
- **Modular Programming**: Organizing code into reusable functions.
- **Control Structures**: Using loops and conditionals for robust logic.

---

## **Future Enhancements**
1. Integrate a graphical user interface (GUI) for better usability.
2. Expand the grading system for more subjects.
3. Add a single login system for centralized access.

---

## **Acknowledgements**
This project represents my journey into the world of programming and software development. Special thanks to my instructors and peers who guided and inspired me throughout.

---

If you have any feedback or suggestions, feel free to open an issue or contact me. 😊

---
