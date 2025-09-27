# Python
- python is interpreted language that first came in 1991, for ref c came like in 1972
- means it executed line by line, no compilation needed.
- python takes up more space tho.

## Compared to C
- eleminates semicolon
- eleminates \n for new line

## libraries
- python has powerfull libraries (modules+packages).
- we import library using 'import cs50'
- types are automatically figure out what type will be

## positional parameters and named paramenters
- named paramenters can be override
- positional paramenters are just what come first. (like in orders)
- named paramentes are with name and value type stuff (we can override it anytime tho)

## data types python supports
- python usually automatically get what the type of variable is
- bool, float, int, str, ...
- no double, no long etc.

## data structure
- range, list, tuble, dict, set, ...

---

## the print function
`print(*objects, sep=' ', end='\n', file=None, flush=Flush)`

- simgle quote and double both works here.


## variable deceration:
- unlike c type specification not neeeded
- declare by initialization only
- counter = 0  <- it will find its type
- counter += 1 (valid)
- counter = counter + 1 (valid)
- counter++ or ++counter (invalid ⚠️)
- no character var tho, everything is string
- explicitly defining (casting) type 'int' otherwise it will treat it as string:
    - x = int(input("X: "))  # this will treat the input as int
    - x = input("X: ")  # this is treat input as a string
- for string both single quote and double quote allowed.
    - `cat = "meow"`
    - `cat = 'meow'

## conditionals
- if statements
    ```python
        if x < y:
            print("x is less than y")
    ```
- if-else
    ```python
        if x < y:
            print("X smol")
        else:
            print("Y smol")
    ```
- if-elif-else

- python is oops lang
- struct in c and objects in python
- methods can be chained here
- indentation
- comparision is done using:
    - AND operation - and
    - OR operation -  or
    - EQAILITY - equal
- Using a terinary operator:
    - in C :
        ```cpp
        bool alphabetic = isAlpha(var) ? true : false;
        ```
    - in py:
        ```python
        alphabetic = True if var.isalpha() else False
        ```

## loops
- for loop
    ```python
        # not a best tho
        for i int [0, 1, 2]:
            print("meow 😺")

        # so to fix the above prob
        for _ in range(3)     # underscore is here because we are not using i anywhere
            print("meow")

        # using a third parameter which work for steps
        for _ in range(1, 100, 2)
        # syntax: range(start, end, step)

    ```
- python doesnot have do-while loop
- techinacally python do no need main fucntion but we can do it tho kinda like one main master function
- print(f"{x} / {y} : {z:.50f}")  # foting point precision is still a thing tho
- integer overflow is not a problem here tho

## exceptions
- when something goes wrong python basically throws exceptions
- try except
- also dont wrap everything inside try (bad design)
    ```python
        try:
            ...
            ...
            ...
            ...
        except Error:
            ...
    ```
- we can also use else with loop
## List

- python has ~~Array~~ List
- pytohon can work with else with for loop
- declaration:
    ```python
    movies = []
    foods = [1, 2, 3, 4, 5]
    tree = [x for x in range(100)]  # similar to - tree = [0,1,...,99,100]
    money = list() # list with 0 mem initially
    money.append(100) # results in money = [100]
    foods.append(3, 70) # results in foods = [1, 2, 3, 70, 4, 5]
    foods[len(foods):] = [9] # results in foods = [1,2,3,4,5,9]
    ```
## Tuples
- ordered, immutable type of data type.
- good for associating a collection of data in sorted order.
- Example:
    ```python
    presidents = [
        ("George Washington", 1789),    # tuple 1
        ("John Adams", 1797),           # tuple 2
        ("Thomas Jefferson", 1801),     # tuble 3
        ("James Madison", 1809)         # tuple 4
    ]

    # Iterating :
    for prez, year in presidents:
        print("In {1}, {0} took office.".format(prez, year))

    ```
    Output:
    ```bash
        In 1789, George Washington took office.
        In 1797, John Adams took office.
        In 1801, Thomas Jefferson took office.
        In 1809, James Madison took office.
    ```

## dict
- yeah just usual key-value stuff
- key:value pair
- allows to specify list indices with phrases instead of integer.
- order in not gauranteed
- Example:
    ```python
    pizzas = {
        "cheese" : 9,
        "pepperoni": 10,
        "vegetable": 11,
        "buffalo chicken": 12
    }

    # changing values
    pizzas["cheese"] = 8
    # comparision
    if pizzas["pepperoni"] < 12 :
        # ... do smthg
    # adding key:vale pair
    pizzas["bacon"] = 20

    # iterating over dict
    # over keys only
    for ingredients in pizzas:
        print(ingredients)
    # over values only
    for items, qty in pizzas.items():  # this basically breaks into two ist
        print(qty)

    # over both both
    for items, qty in pizzas.items():
        print("Pizza has {} number of {}".format(qty, items))
    ```

## functions
- don't need to specify return type as it doesn't really matter nor the data types of the parameters
- function introduce using `def` keyword
- no need of main fuction as interpreter reads from top to bottom
- if you wanna main fucntion at the very END of the program add this:
  ```python

    ...
    ...
    ...
    ...
    # defining main
    if __name__ = "__main__"
        main()`
   ```
- defining a normal fuction:
    ```python
    # square fucntion
    def square(x):
        retunr x * x
    ```

## objects
- python is oops language os yeah! OBjects.



## sys
- command line inputs etc.
- argv
- exit status, you can check exit code returned by program by: `echo $?`

## pip to include extra libraries
- u can use pip to install extra helpfull package using pip

## Algo
- n number of problems
- time taken v/s space
- represented using big-O notation or you can say 'Order of'
    - O(n) - slow but space and space taken will be less.
    - O(n/2)
    - O(LogN) - utilizes more space but is faster as it is basically dividing the whole problem by half-and-half.

## Shorts Notes:

GitDocs
