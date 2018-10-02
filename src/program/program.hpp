/**
    CS-11 Asn 2
    format.hpp
    Purpose: Library to format the input program file. The aim is to translate the file to a data structure so it can be manipulated esaier later.
    We also define here the Intruction structure. You will also find all the implementations of the OPCODES supported by the simulator.

    @author Ayoub Bargach
    @version 1.0
*/

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <string>
#include <vector>
#include "format.hpp"

/**
    Decodes a program.

    @param A input to decode.
*/

class Program {
private:
    bool verbose;
    FileManipulator myFile;
    int maxPointer;
    int pointer;
    std::vector<Instruction> instructions;

public:
    Program(std::string path, bool verbose); // Here we generate all the private fields
    double compute(); // Compute current Instruction and increment the pointer
    void increment(); // Increment the pointer
    void reset(); // Put pointer to 0
    bool end(); // Return 1 if all the instructions have been executed
};

/**
    Decodes an instruction.

    @param A input to decode.
*/

class Instruction {
private:
    op_t opcode;
    std::vector<double> operands;
    double (*op) (double, double); // A pointer on a function to call when needed to simulate the operation

public:
    std::string input;
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

double opADD (double i, double j);
double opSUB (double i, double j);
double opMUL (double i, double j);
double opDIV (double i, double j);
double opNOP (double i, double j);


#endif