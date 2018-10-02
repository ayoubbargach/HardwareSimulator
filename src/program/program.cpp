/**
    CS-11 Asn 2
    format.hpp
    Purpose: Library to format the input program file. The aim is to translate the file to a data structure so it can be manipulated esaier later.
    We also define here the Intruction structure. You will also find all the implementations of the OPCODES supported by the simulator.

    @author Ayoub Bargach
    @version 1.0
*/

#include "program.hpp"

// --- PROGRAM ---

Program::Program(std::string path, bool verbose)
    : myFile(path), pointer(0), maxPointer(0), verbose(verbose) {

    // All the work is done by the contructor, we generate here the list of operations
    
    std::string line;
    
    while ((line = myFile.getLine()) != "") {

       // We simple add the new instruction, emplace back creates the object internally

       instructions.emplace_back(line);
    }
}

/**
    Compute the current instruction
*/
double Program::compute() {
    if (verbose) {
        // We print only the instruction, the result will be manipulated at the return of the function (Not clean but more optimized)
        std::cout << instructions[pointer].input << std::endl;
    }
    return instructions[pointer].compute();
}

/**
    Increment the pointer
*/
void Program::increment() {
    pointer++;
}

/**
    Reset the pointer
*/

void Program::reset() {
    pointer = 0;
}

/**
    Return true if we are (or passed) the end of the list
*/

bool Program::end() {
    if (pointer >= instructions.size()) return true;
    else return false;
}

// --- INSTRUCTION ---
Instruction::Instruction(std::string input)
    : input(input) {
    
    // To split the string using the delimiter single space, we use another getline
    std::istringstream iss(input);
    std::string element;
    bool firstFlag = 1;

    while (getline( iss, element, ' ')) {

        //If the element if empty, we skip it
        if ( !element.empty()) {

            //We look for the opcode (first element)
            if (firstFlag) {
                if (element == "ADD") {
                    opcode = ADD;
                    op = opADD;
                }
                else if (element == "SUB") {
                    opcode = SUB;
                    op = opSUB;
                }
                else if (element == "MUL") {
                    opcode = MUL;
                    op = opMUL;
                }
                else if (element == "DIV") {
                    opcode = DIV;
                    op = opDIV;
                }
                else {
                    opcode = NOP;
                    op = opNOP;

                    // We add two doubles : TODO / Optimize this implementation.
                    operands.push_back(0);
                    operands.push_back(0);
                }

                firstFlag = 0;
            }
            else {
                // We add all the operands needed by converting them to 
                operands.push_back(stod(element));
            }
        }
    }
}

double Instruction::compute() {
    // We just need to compute and that it.
    return op(operands[0], operands[1]);
}




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

double opNOP(double i, double j) {
    return 0;
}
