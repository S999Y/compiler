# Coding Standards in Software Engineering

## 📘 Overview

Coding standards are a set of guidelines and best practices that define how code should be written, organized, and formatted in a software project.

They ensures :

- **Consistency** across the codebase
- **Improved readability** for developers
- **Better maintainability** over time
- **Reduced errors and technical debt**
- **Efficient team collaboration**

---

## 🧩 Key Coding Standards

- [**Limited use of Globals**](#limited-use-of-globals)
- [**Commonized headers from common modules.**](#commonized-headers-from-common-modules)
- [**Naming conventions (`local variables, global variables, constants and functions`) .**](#️-naming-conventions)
- [**Indentation management.**](#-indentation-management)
- [**Try-Catch Block.**](#️-exception-handling-try-catch-block)

---

## 🔒 Limited use of Globals

- Avoid excessive use of global variables to reduce **unexpected side effects** and improve code modularity.
- Prefer **local scope**, **function parameters**, or **dependency injection** where possible.
- Use global constants only when necessary and clearly distinguish them.

### 📌 Example

```c
#define PI 3.1416   // Global constant (acceptable if used widely)

int speed = 100;   // Global variable (should be avoided if possible)

int main() {
    // Use local variables instead when possible
    int localSpeed = speed;

    return 0;
}
```

## Commonized headers from common modules

- Use **shared or common header files/modules** for reusable components.
- Prevent duplication and ensure **centralized updates**.
- Promote **consistency** across different parts of the project.
- Simplify **maintenance** by updating headers in one place.

### 📌 Example

```
project-root/
│
├── src/
│ ├── main.c          # Entry point of the program
│ ├── app.c           # Application logic implementation
│ └── app.h           # Header file for app.c
│
├── utils/
│ ├── math_utils.c    # Math utility functions
│ ├── math_utils.h    # Header for math utilities
│ ├── string_utils.c  # String utility functions
│ └── string_utils.h  # Header for string utilities
│
├── common/
│ ├── constants.h     # Shared constants across modules
│ └── config.h        # Centralized configuration settings
│
└── include/
└── all_utils.h    # Aggregated header including all utilities
```

---

## 🏷️ Naming Conventions

- Follow consistent naming rules to improve **readability** and **maintainability**.
- Use **meaningful names** that clearly describe the purpose of variables, functions, and constants.
- Apply **appropriate naming styles** for different elements (variables, constants, functions, classes).
- Avoid unclear or project-specific abbreviations.

---

### 🔤 Common Naming Conventions

Different naming styles are used depending on the programming language and coding standards:

- **camelCase**
  - First word lowercase, subsequent words capitalized
  - Commonly used for variables and functions
  - Example: `studentCount`, `calculateAverage()`

- **PascalCase**
  - Every word starts with a capital letter
  - Commonly used for class names
  - Example: `StudentManager`, `UserProfile`

- **snake_case**
  - Words separated by underscores, all lowercase
  - Common in C, Python, and some APIs
  - Example: `student_count`, `calculate_average`

- **UPPER_CASE (SNAKE_CASE)**
  - All letters uppercase with underscores
  - Used for constants and macros
  - Example: `MAX_USERS`, `PI_VALUE`

- **kebab-case**
  - Words separated by hyphens
  - Used in URLs, file names, and web development
  - Example: `user-profile`, `main-style.css`

---

### 📌 Recommendation

- Stick to **one consistent style** within a project.
- Follow **language-specific conventions** (e.g., Java → camelCase, C → snake_case/UPPER_CASE).
- Maintain consistency across the entire codebase.

---

### 📌 Example

```c
// ✅ Good practice

#define MAX_USERS 100      // Constant (UPPER_CASE)

int globalCounter = 0;     // Global variable (minimize usage)

int main() {
    int studentCount = 50;   // Local variable (camelCase)
    return 0;
}

void calculateAverage() {    // Function name (verb + noun)
    // Function logic here
}


// ❌ Bad practice

int sc;        // Unclear abbreviation
int x1;        // Non-descriptive name
void func();   // Generic function name
```

---

## 📏 Indentation Management

- Maintain consistent indentation to improve **readability** and code structure.
- Use a fixed number of spaces (commonly **2 or 4 spaces**) or tabs consistently throughout the project.
- Proper indentation helps visualize **code blocks**, **loops**, and **conditional statements**.
- Avoid mixing tabs and spaces.

---

### 🔤 Common Practices

- **Consistent Indentation**
  - Use the same indentation style across the entire codebase
  - Example: 4 spaces per indentation level

- **Block Alignment**
  - Align code inside loops, conditionals, and functions properly
  - Improves readability and debugging

- **Line Length & Spacing**
  - Keep lines reasonably short (e.g., 80–120 characters)
  - Add spacing between logical sections of code

---

### 📌 Recommendation

- Follow a **standard style guide** (e.g., language-specific conventions).
- Configure your **IDE/editor** to auto-format code.
- Use tools like formatters or linters to enforce consistency.

---

### 📌 Example

```c
// ✅ Good practice

int main() {
    int i;

    for (i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            printf("Even: %d\n", i);
        } else {
            printf("Odd: %d\n", i);
        }
    }

    return 0;
}


// ❌ Bad practice

int main(){
int i;
for(i=0;i<5;i++){
if(i%2==0){
printf("Even: %d\n",i);
}else{
printf("Odd: %d\n",i);
}
}
return 0;
}
```

---

## ⚠️ Exception Handling (Try-Catch Block)

- Use `try-catch` blocks to handle runtime errors gracefully.
- Prevent application crashes by managing exceptions properly.
- Avoid exposing sensitive error details to users.
- Log errors for debugging and monitoring purposes.

---

### 🔤 Common Practices

- **Specific Exception Handling**
  - Catch specific exceptions instead of using a generic catch block

- **Meaningful Error Messages**
  - Provide clear and useful error messages for debugging

- **Avoid Empty Catch Blocks**
  - Always handle or log the exception

- **Use Finally Block (if applicable)**
  - Ensure important cleanup code runs (e.g., closing resources)

---

### 📌 Recommendation

- Do not overuse `try-catch`; use it only where exceptions are expected.
- Keep `try` blocks small and focused.
- Follow language-specific best practices (e.g., Java, C++, Python).

---

### 📌 Example

```java
// ✅ Good practice

try {
    int result = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("Error: Cannot divide by zero");
} finally {
    System.out.println("Execution completed");
}


// ❌ Bad practice

try {
    int result = 10 / 0;
} catch (Exception e) {
    // Empty catch block (bad practice)
}
```
