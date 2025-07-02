# ChaveMestre: User Management System in C

The `ChaveMestre Registration and Login System` is the main product of the fictitious company ChaveMestre, created by the students of Information Systems 2025/1 at UFG. A robust system for user and administrator registration and login, developed entirely in C. The project was built with a focus on security, modularity and a clean and interactive terminal interface. It serves as a complete solution for profile management, with distinct functionalities for standard users and system administrators.

## 🎯 Project Objective

The main objective of the system is to provide a secure and well-structured codebase for an authentication system. It was designed to demonstrate defensive programming practices in C, secure file handling, interaction with external APIs (for sending emails) and the creation of a functional user interface in the console environment.

---

## ✨ Functionalities

The system is divided into two main modules: one for users and one for administrators.

### **For Users:**
* **Secure Registration:** Creation of new user accounts with data validation.
* **Login:** Access to the account with name and password verification.
* **Password Recovery:** Recovery mechanism through a secret question and answer.
* **Email Notifications:** Receiving emails to confirm registration, login and password changes.

### **For Administrators:**
* **Restricted Access:** Secure login for administrators.
* **User Management:**
* **Complete List:** View all registered users and administrators.
* **User Location:** Search for specific profiles by name.
* **User Deletion:** Removal of user accounts from the system.
* **Email Notifications:** Alerts about activities in the administrator account.

---

## 🛠️ Technical Details

* **Data Storage:** Information is stored in binary files (`usuarios_cadastrados.bin` and `adms_cadastrados.bin`), ensuring efficient reading and writing of data.
* **Data Security:** Passwords and secret answers are obfuscated using a **Caesar Cipher** before being saved, adding a basic layer of protection. Password input is masked on the screen.
* **Terminal Interface (ADK):** The project uses a proprietary development kit created by the students, the **ANSIstyle Dev Kit (ADK)**, to create a rich terminal interface, with borders, colors and cursor positioning, which works on both Windows and Linux. * **Defensive Programming:** An intelligent buffer allocation technique is used to read text inputs, preventing common buffer errors and ensuring that the newline character (`\n`) is handled correctly.

* **Sending Emails:** The **libcurl** library is used to communicate with the Gmail SMTP server, allowing the sending of notifications via SMTPS (secure SMTP over SSL).

---

## 🚀 How to Download and Use

To compile and run the project on your machine (Windows), you will need the MSYS2 environment. Follow the steps below.

### **1. Prerequisites and Installation**

First, install MSYS2 and the necessary tools for compilation.

1. **Download and install MSYS2:**
* Go to the official website and download: [https://www.msys2.org/](https://www.msys2.org/)

2. **Open the MSYS2 MinGW 64-bit terminal.**

3. **Update MSYS2 packages:**
* Run the command below and close the terminal if prompted. Then, open it again and run the second command.
```bash
pacman -Syu
pacman -Su
```

4. **Install the build tools and libcurl library:**
* This command will install the `gcc` compiler, the `make` tool, and the `curl` library required for sending emails. ```bash
pacman -S make mingw-w64-x86_64-gcc mingw-w64-x86_64-curl
``

### **2. Compilation and Execution**

After setting the prerequisites, you can compile and run the project.

1. **Navigate to the project directory:**
* Use the `cd` command in the MSYS2 terminal. For example, if your project is on the Desktop:
```bash
cd /c/Users/YourUser/Desktop/MasterKey
```

2. **Compile the project:**
* The project already contains a `Makefile` that automates the compilation. Just use the command:
```bash
make
```
* This will compile all the `.c` files and generate an executable called `program`.

3. **Run the program:**
* To start the system, run the generated file:
```bash
./program
```

Now the `MasterKey Registration and Login System` will be running in your terminal! 🎉
