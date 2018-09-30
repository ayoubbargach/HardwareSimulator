/**
    CS-11 Asn 2
    format.hpp
    Purpose: Library to format the input program file. The aim is to translate the file to a data structure so it can be manipulated esaier later.
    We also define here the Intruction structure. You will also find all the implementations of the OPCODES supported by the simulator.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <string>
#include <list>
#include <vector>

/**
    Decodes a program.

    @param A input to decode.
*/

class Program {
private:
    std::string input;
    int pointer;
    std::list<Instruction> instructions;

public:
    Program(); // We also declare a default contructor that return a simple program with NOP instruction (Useful for test simulation purposes)
    Program(std::string input); // Here we generate all the private fields
    double compute(); // Compute current Instruction and increment the pointer
};

/**
    Decodes an instruction.

    @param A input to decode.
*/

class Instruction {
private:
    std::string input;
    op_t opcode;
    std::vector<double> operands;
    void * op; // A pointer on a function to call when needed to simulate the operation

public:
    Instruction(); // We also declare a default contructor. When we call this object without any param, it means that we skip the current Instruction (or NOP in assembly)
    Instruction(std::string input); // Here we generate all the private fields
    double compute(); // Compute the operation
};

/**
    Enum of all operations
*/
enum op_t { NOP, ADD, SUB, MUL, DIV};

/**
    Basic functions that implement this operations
*/

double opADD (double i, double j) {
    return i+j;
}

double opSUB (double i, double j) {
    return i-j;
}

double opMUL (double i, double j) {
    return i*j;
}

double opDIV (double i, double j) {
    return i/j;
}

#endif