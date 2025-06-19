# Object-Oriented Programming (OOP) in C++

# 1. Definition
Object-oriented programming is a paradigm based on the concept of #objects, which contain #data (attributes) and #functions (methods).

# 2. Core Concepts (Pillars of OOP)
# Encapsulation:
- Wrapping data and functions into a single unit (class). Keeps data safe from outside interference.
# Abstraction:
- Hiding internal implementation details and showing only necessary features.
    - `Abstract Classes` - "abstract" Keyword
            - Cannot be used to make objects 
            - Used as a blueprint for other classes. (Inheritance ONLY.)

# Inheritance:
- One class can inherit properties and methods from another. Promotes code reusability. 
# Polymorphism:
- Same function name behaves differently in different contexts.
- each object have the option to behave differently based on parameters/context. 
 `Compile Time Polymorphism` 
    - Function overloading - difference is in parameters
    - Constructor overloading 
    - operator overloading - allows custom re-definition of operators.
    - Templates 

 `Run Time Polymorphism`
    - Function Overriding- Dependant on inheritance 
            - Function name and parameters are same but internal logic is different
            - It prioritizes the function implementation of child over parent class
            - one way to solve ambiguity to see whether the object belongs to the parent or the child. 

    - Virtual functions – enable late binding and override resolution at run-time
    - Virtual destructors – ensure correct object cleanup via base class pointer
    - Pure virtual functions – make a class abstract, enforce overriding
    - Base class pointer/reference to derived object – triggers dynamic dispatch



# 3. Class vs Object
- #Class: Blueprint or template for creating objects.
- #Object: Instance of a class (real-world entity with state and behavior).

# 4. Constructor
- Special function automatically called when an object is created.
- Used to initialize data members.

# 5. Destructor
- Special function called when an object is destroyed.
- Used to release resources or memory.

# 6. Access Specifiers
- `public`: Accessible in the class and main function. accessible in derived class
- `private`: Accessible only within the class.
- `protected`: Accessible within the class and the derived class.

# 7. Types of Inheritance
- `Single Inheritance`: One derived class inherits from one base class.
- `Multiple Inheritance`: One derived class inherits from more than one base class.
- `Multilevel Inheritance`: A class is derived from a derived class (grandparent → parent → child).
- `Hierarchical Inheritance`: Multiple derived classes inherit from a single base class.
- `Hybrid Inheritance`: A combination of two or more types of inheritance in a single program.

# 8. Function Overloading (Compile-time Polymorphism)
- Same function name with different parameter lists.

# 9. Function Overriding (Run-time Polymorphism)
- Redefining base class function in the derived class using the same signature.

# 10. this Pointer
- Refers to the current object’s address.
- Used to resolve name conflicts and return the object itself.

# 11. Constructor Overloading
- Multiple constructors with different parameter lists.

### 12. Copy Constructor
- Special constructor used to create a new object as a copy of an existing one.
- default does shallow copy. 

  - **Shallow Copy:**
    - Copies only the pointer; both objects refer to the same memory location.
    - Example:
     `this->rating = obj.rating;`
    - Modifying data through one object affects the other. Also risks multiple deletions of the same memory.

  - **Deep Copy:**
    - Allocates new memory and duplicates the actual data.
    - Example:
      `this->rating = new float;`
      `*(this->rating) = *(obj.rating);`
    - Each object holds an independent copy; changes in one do not affect the other, ensuring data remains consistent within its own object.

# 13. Virtual Functions
- Member functions declared with the `virtual` keyword in base class.
- Enables runtime polymorphism via pointers/references to base class.

# 14. Pure Virtual Functions
- Syntax: `virtual void func() = 0;`
- No definition in base class; forces derived class to implement.
- Makes the class abstract (cannot be instantiated).

# 15. Abstract Class
- Any class with at least one pure virtual function.
- Acts as a blueprint for derived classes.

# 16. Friend Function
- Declared using the `friend` keyword.
- Not a member, but has access to the class's private/protected members.
- Useful for operator overloading or bridging two classes.

# 17. Operator Overloading
- Redefining the behavior of operators (like `+`, `==`, `<<`) for user-defined types.
- Example: `Complex operator+(Complex c1, Complex c2)`

# 18. Static Members
- Static variable: Shared across all objects of a class.
- Static function: Can be called without an object, only accesses static members.

# 19. Const Keyword in Classes
- `const` member functions cannot modify object data.
- `const` objects can only call `const` methods.

# 20. Initialization List in Constructors
- Efficient way to initialize class members before constructor body.
- Especially important for const and reference members.

# 21. Templates (Generic Programming)
- Define functions/classes with generic types.
- Syntax: `template<typename T> class MyClass { ... };`
- Useful for code reuse with different data types.

# 22. Dynamic Binding
- Deciding which function to call at runtime using virtual functions and base class pointers.

# 23. Polymorphic Base Class Destructor
- Always declare destructors in base class as `virtual` when using inheritance.
- Prevents undefined behavior during object destruction via base pointer.

# 24. Miscellaneous
- Mutable keyword: Allows a member to be modified even in a `const` object.
- `typeid` operator: For runtime type identification in polymorphic classes.
- `dynamic_cast`: Safely casts pointers/references between class types in inheritance hierarchy.
- `this` pointer with return: Enables method chaining, e.g., `obj.setA(1).setB(2);`


