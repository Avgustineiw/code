# Workshops 3, 4. Strings and Symbolic Data Types

## Introduction

You should know how to build simple C++ programs with loops and conditions.

The topic of these workshops is two types of strings:

1. C++ strings, `std::string`.
2. C-style strings, an array of `char`.

# Description

## Char

`char` is a single character, a foundation of the string types. Unlike Python, it's a different thing from multi-character things. `char` is closer to `int`.


```cpp
// Creating and initializing a variable of the type char
char c = 'A';
// Using a char literal ('y' in this case)
std::cin >> c;
if (c == 'y')
{
    // do something
}
```

Type casting between `char` and `int` works based on the code of the character, not a number it represents. For example, a `char` value `0` is `48` when converted to `int`.

## do..while

In addition to the `for` loop and the `while` loop C++ has a `do..while` loop that is similar to `while` but the condition is checked after the loop iteration. It is useful when you always have to make the first iteration before you know whether to stop or make a new iteration.

```cpp
char ans;
do {
    // problem
    cout << "Press y to repeat";
    cin >> ans;
} while (ans == 'y' || ans == 'Y');
```

## C-style strings

C-style strings are arrays of `char` values. If practice they should only be used as string literals - constant string values.

Here is an example of a context where a C-style string would be appropriate

```cpp
cout << "Hello";
```

The type of `"Hello"` in this example is an array of `char` values, so you can assign it to a variable that also has that type.

```cpp
char exampleString[] = "Hello";
```

This line of code means that an array exampleString is created and its length is inferred from the value assigned to it. The length of this array will be equal to the length of the string + 1. The reason for this is that C-style strings have a `0` character which represents the end of the string.

[](!img/string.png)

## std::string

If you want to work with real strings in your program, do not use C-style strings. Use the high-level data type std::string instead.

The std::string data type provides useful and convenient methods for working with strings. For example, if a variable called `hello` has a type
`std::string`, you can do the following:

1. Get the length of the string using `hello.length().`
2. Concatenate two strings using addition operator. `largeString = hello + shortString;`.
3. Compare two strings using regular logical operators. `if (hello < shortString)`.
4. Use the last two operators with string literals.
```cpp
largeString = hello + "World";`
if (hello < "World").
```
5. Copy strings using assignment.
`hello = shortString;`.

## Example

```cpp
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string exampleString = "Hello";
    string anotherString = "World";

    int exampleLength = exampleString.length();
    char firstLetter = exampleString[0];
    char lastLetter = exampleString[exampleLength ‐ 1];

    string fullString = exampleString + anotherString;

    cout << "The strings are:" << endl;
    cout << exampleString << endl;
    cout << anotherString << endl << endl;
    if (exampleString < anotherString)
    {
        cout << exampleString << " < " << anotherString << endl;
    }
    else if (exampleString > anotherString)
    {
        cout << exampleString << " > " << anotherString << endl;
    }
    else
    {
        cout << "The strings " << exampleString;
        cout << " and " << anotherString << " are equal" << endl;
    }
    cout << "The length of " << exampleString << " is " << ▼
    exampleLength << endl;
    cout << "The combined string is " << fullString << endl;
    cout << "The first letter in " << exampleString;
    cout << " is " << firstLetter << endl;

    cout << "The last letter in " << exampleString;
    cout << " is " << lastLetter << endl;
}
```

# Exercises

Also refer to code files themselves.

1. Create a program that takes two numbers as input `1 < m, n < 8`. Output a multiplication table `m ∗ n`, aligning output at tab positions.
2. Create a program that asks the name of the user and then outputs `"Hello, <user>"` where `<user>` is the name the user inputted into the program.
3. For independent study. Recreate the multiplication table task, allowing the user to rerun the program again after it prints the multiplication table. Use a new project for this task, do not erase the project containing the multiplication table program without reruns.
4. Count the length of a C-style string variable initialized with a string literal. Use index operator `[]` and a counter `i`.  
`char current = exampleString[i];`  
Stop counting when `current == '\0'`. At this point `(i ‐ 1)` equals string length. Print it in the following format:
`String <yourString>. Length is <stringLength>`  
`<yourString>` is the string you use for this task and `<stringLength>` is the computed length of that string.