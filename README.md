# Monty ByteCode Interpreter 🚀

Monty 0.98 is a scripting language that compiles into Monty byte codes, similar to Python. It operates with a unique stack and specific instructions for stack manipulation. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty Byte Code Files 📄

Files containing Monty byte codes usually have the `.m` extension. Each line in these files contains one instruction. There can be spaces before or after the opcode and its argument.

## LIFO and FIFO Principle 🔄

- **LIFO (Last In, First Out) Principle:** This describes a stack, where the last element added is the first to be removed. 📥📤
- **FIFO (First In, First Out) Principle:** This defines a queue, where the first element added is the first to be removed. 🚶‍♀️🚶‍♂️

## Common Implementations 🔧

Common implementations of stacks and queues can be done using arrays or linked lists. 📚

## Use Cases 📊

**Stacks:**
- Function call management (call stack) ⚙️
- Expression evaluation 🧮
- Undo/Redo functionality ↩️↪️
- Depth-first search in graphs 🌐

**Queues:**
- Task scheduling 📅
- Breadth-first search in graphs 🌐
- Print job management 🖨️
- Simulating real-world queues 🚶‍♀️🚶‍♂️

## Follow the provided guidelines for proper execution.

# Execution 🏃‍♀️🏃‍♂️
The Monty program runs Monty byte codes line by line until:

All lines are executed successfully.
An error is encountered in the file.
An error occurs during execution.

# Memory Management 🧠
The program uses malloc and free for memory management. If memory allocation fails, an error message is displayed, and the program exits.

# Get Started 🚀
Clone this repository.
Compile the Monty program.
Run Monty with your Monty byte code files.
Happy Monty coding! 😎🎉

## Usage 🛠️

To use the Monty program, run the following command:

```shell
$ ./monty file
