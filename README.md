# 📘 C++ Modules 00–09 – 42 School Curriculum

This repository contains my completed exercises for the C++ modules 00 to 09 from the 42 school curriculum. Each module dives into fundamental and advanced C++ concepts, covering topics from basic object-oriented programming to advanced STL usage and algorithm design.

---

## 📑 Table of Contents

* [Project Structure](#-project-structure)
* [Build & Run](#-build--run)
* [Module Overview](#-module-overview)

  * [Module 00 – OOP Basics](#module-00--oop-basics)
  * [Module 01 – Memory, References & Pointers](#module-01--memory-references--pointers)
  * [Module 02 – Operator Overloading & Canonical Form](#module-02--operator-overloading--canonical-form)
  * [Module 03 – Inheritance](#module-03--inheritance)
  * [Module 04 – Polymorphism & Abstract Classes](#module-04--polymorphism--abstract-classes)
  * [Module 05 – Exception Handling](#module-05--exception-handling)
  * [Module 06 – C++ Casts](#module-06--c-casts)
  * [Module 07 – Templates](#module-07--templates)
  * [Module 08 – STL Containers & Algorithms](#module-08--stl-containers--algorithms)
  * [Module 09 – STL in Practice](#module-09--stl-in-practice)
* [Tools & Setup](#-tools--setup)

---

## 🗂️ Project Structure

```bash
CPP-Modules/
├── Module_00/
│   ├── ex00/
│   ├── ex01/
│   └── ...
├── Module_01/
│   ├── ex00/
│   ├── ex01/
│   └── ...
...
├── Module_09/
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
└── README.md
```

Each `Module_XX` folder contains all related exercises for that specific module.

---

## 🚀 Build & Run

To compile and run an exercise:

```bash
cd Module_XX/exYY
make
./executable_name
```

Replace `Module_XX` with the target module (e.g. `Module_00`) and `exYY` with the corresponding exercise (e.g. `ex00`). The executable name may vary depending on the task.

---

## 📚 Module Overview

### Module 00 – OOP Basics

* **Topics**: Classes, member functions, namespaces, streams, `const`, `static`.
* **Goal**: Understand core object-oriented programming concepts in C++.

### Module 01 – Memory, References & Pointers

* **Topics**: Dynamic allocation, references, pointers, switch statements.
* **Goal**: Master memory manipulation and object referencing.

### Module 02 – Operator Overloading & Canonical Form

* **Topics**: Operator overloading, constructors/destructors, canonical class form.
* **Goal**: Write robust, well-structured C++ classes.

### Module 03 – Inheritance

* **Topics**: Single inheritance, constructors/destructors, base/derived classes.
* **Goal**: Apply inheritance to model real-world relationships between classes.

### Module 04 – Polymorphism & Abstract Classes

* **Topics**: Abstract classes, virtual functions, interfaces.
* **Goal**: Use polymorphism to create flexible and reusable class hierarchies.

### Module 05 – Exception Handling

* **Topics**: `try`, `catch`, `throw`, error recovery.
* **Goal**: Handle runtime errors safely and clearly using exceptions.

### Module 06 – C++ Casts

* **Topics**: `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`.
* **Goal**: Understand and apply C++ casting mechanisms responsibly.

### Module 07 – Templates

* **Topics**: Function and class templates, generic programming.
* **Goal**: Write generic, reusable code using C++ templates.

### Module 08 – STL Containers & Algorithms

* **Topics**: `std::vector`, `std::list`, iterators, STL algorithms.
* **Goal**: Manipulate collections efficiently using the Standard Template Library.

### Module 09 – STL in Practice

* **ex00**: **Bitcoin Exchange**

  * **Goal**: Compute historical Bitcoin values based on input dates.
  * **Skills**: File parsing (CSV), use of `std::map`, error handling.

* **ex01**: **RPN Calculator**

  * **Goal**: Evaluate expressions written in Reverse Polish Notation.
  * **Skills**: Stack manipulation (`std::stack`), expression parsing.

* **ex02**: **PmergeMe**

  * **Goal**: Implement a hybrid merge-insertion sort algorithm.
  * **Skills**: Use of `std::vector` and `std::deque`, custom sorting logic.

---

## 🛠️ Tools & Setup

* **Language**: C++98
* **Build Tool**: `make`
* **Recommended IDE**: Visual Studio Code or any IDE with C++ support.