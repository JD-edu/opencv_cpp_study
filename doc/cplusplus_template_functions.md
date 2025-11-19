Declaring and defining a template function in C++ is straightforward. Here’s a guide to help you create your own template function, for example, `sub()`, which performs subtraction.

---

### Step-by-Step: Declare a Template Function

1. **Use the `template` Keyword**:
   - Start the function declaration with `template` followed by a placeholder for the data type (e.g., `typename T` or `class T`).
   - `T` is the placeholder that represents the type.

2. **Define the Function**:
   - Write the function using `T` as the type for parameters or return values.

3. **Call the Function**:
   - When calling the function, specify the type explicitly (e.g., `sub<int>(a, b)`) or let the compiler deduce the type automatically.

---

### Example: Template Function `sub()`

#### Declaration and Definition
```cpp
#include <iostream>

// Template declaration
template <typename T>
T sub(T a, T b) {
    return a - b;
}
```

#### Usage
```cpp
int main() {
    // Using the template with integers
    int x = 10, y = 3;
    std::cout << "sub<int>: " << sub<int>(x, y) << std::endl;

    // Using the template with floating-point numbers
    float a = 5.5f, b = 2.2f;
    std::cout << "sub<float>: " << sub<float>(a, b) << std::endl;

    // Using automatic type deduction
    std::cout << "Auto deduction (double): " << sub(7.0, 2.0) << std::endl;

    return 0;
}
```

#### Output:
```
sub<int>: 7
sub<float>: 3.3
Auto deduction (double): 5
```

---

### Explanation

1. **Template Declaration**:
   ```cpp
   template <typename T>
   ```
   - This declares a template with `T` as the placeholder for the data type. The type `T` will be replaced by the type used when calling the function (e.g., `int`, `float`, etc.).

2. **Function Definition**:
   ```cpp
   T sub(T a, T b) {
       return a - b;
   }
   ```
   - The parameters `a` and `b`, as well as the return value, are of type `T`. This makes the function work with any type that supports the subtraction operator (`-`).

3. **Calling the Function**:
   - **Explicitly specify the type**: `sub<int>(x, y)`
   - **Let the compiler deduce the type**: `sub(7.0, 2.0)` (here, the compiler infers `T` as `double`).

---

### Advanced Example: Multiple Types

You can use multiple template parameters if needed. For example, a function that subtracts two different types and returns a third type:

```cpp
template <typename T1, typename T2, typename R>
R sub(T1 a, T2 b) {
    return static_cast<R>(a - b);
}
```

#### Usage:
```cpp
int main() {
    int x = 10;
    double y = 2.5;

    // Explicitly specify all types
    std::cout << "sub<int, double, float>: " << sub<int, double, float>(x, y) << std::endl;

    return 0;
}
```

---

### Template Function Benefits
1. **Reusability**: The same function works for different types without needing to write multiple versions.
2. **Type Safety**: Ensures the types used are consistent and valid for the operations in the function.
3. **Flexibility**: Supports both primitive types (e.g., `int`, `float`) and user-defined types (e.g., custom classes).

Let me know if you’d like more examples or explanations! 😊