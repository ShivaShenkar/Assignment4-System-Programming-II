# MyContainer Project

## Overview

This project implements a generic container class, `MyContainer`, in C++. The container supports storing elements of any type and provides several custom iterator classes for traversing the elements in different orders (ascending, descending, side-cross, reverse, etc.). The project demonstrates the use of C++ templates, custom iterators, and operator overloading.

---

## File Structure

```
.
├── include/
│   ├── MyContainer.hpp      # Declaration and implementation of the MyContainer class
│   └── Iterators.hpp        # Declaration and implementation of custom iterator classes
├── src/
│   └── Demo.cpp             # Example usage and test cases for MyContainer and iterators
├── Makefile                 # Build instructions
└── README.md                # Project documentation
```

---

## Classes Involved

- **MyContainer<T>**
  - A generic container class that stores elements of type `T` using a `std::vector`.
  - Provides methods to add, remove, and access elements.
  - Supports multiple custom iterators for different traversal orders.

- **Iterator Classes**
  - `AscendingOrder<T>`: Iterates elements in ascending order.
  - `DescendingOrder<T>`: Iterates elements in descending order.
  - `SideCrossOrder<T>`: Iterates elements in a side-cross pattern.
  - `ReverseOrder<T>`: Iterates elements in reverse order.
  - `Order<T>`: Default order iterator.
  - `MiddleOutOrder<T>`: Iterates from the middle outwards.
  - All iterators are templated and work with any type that supports the required comparison operators.

- **Person**
  - Example class used for testing with custom comparison operators.

---

## How to Run

1. **Build the Project**
   - Make sure you have a Clang++ compiler installed.
   - Run the following command in the project root directory:
     ```
     make all
     ```

2. **Run the Programs**
   - After building, execute the main and tests programs:
     ```
     ./bin/main
     ./bin/test
     ```

---