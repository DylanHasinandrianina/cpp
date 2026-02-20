# EXCEPTION:

## KEY WORDS: try, throw, catch

## SYNTAXE:

        ```cpp
        try{
            //some code that may throw an exception(error)
            throw(<error code>);
        }
        catch(int errorCode){
            std::cout << "Error occured : " << errorCode;
        }
        ```

##  EXPLANATION:

- The try block defines a section of code where an exception may be thrown.
- If an exception is thrown inside the try block (or by a function called from it), the program looks for a matching catch block.
- The catch block receives the object thrown by throw and can use it to handle the error.
- If no exception is thrown, all catch blocks are ignored and execution continues normally.

## NOTE:
    for this exercise, u will also have two classes : GradeTooHighException and GradeTooLowException that both will inherit from std::exception