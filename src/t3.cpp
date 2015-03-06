//============================================================================
// Name        : best_cpu.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <map>
#include <stdlib.h>

#include "best_cpu.h"



void loadProgram(){
	string token;
	*PC = 20;
	int opCount = 0;
	while(input.compare("end") && input.compare("END")){
		istringstream isPrgm(input);
		isPrgm >> token;
		while(isPrgm){
			//codeSegment[*PC] = token;
			if(opCount == 0 || instrMap[token] > 0){
				mem[*PC] = instrMap[token];//++
			}
			else if(instrMap[token] == 0)
				mem[*PC] = stoi(token);
			(*PC)++;
			opCount++;
			isPrgm >> token;
		}
		opCount = 0;
		getline(cin, input);
	}
	//codeSegment[*PC] = "end";
	mem[*PC] = instrMap["end"];//++
	(*PC)++;
}

void startExecution(){

	int i = 0, src, des;
	string op1, op2, instr, temp;
	string array[] = {instr, op1, op2};
	int instrCode = 0;
	*PC = 20;

	while(mem[*PC] != instrMap["end"]){
		i = 0;
		instrCode = mem[*PC];
		(*PC)++;
		cout << "instrCode = " << instrCode;
		switch(instrCode){
	//MOV
		case 55: //register to register
			//Source
			mem[instrMap["MDR"]] = mem[mem[*PC]];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[*PC]] = mem[mem[instrMap["MAR"]]];
			break;

		case 56: //Constant to a register
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[*PC]] = mem[mem[instrMap["MAR"]]];
			break;

		case 57: //Contant to address referenced by reg
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = mem[mem[instrMap["MAR"]]];
			break;

		case 58: //Referenced by register to referenced by register
			//Source
			mem[instrMap["MAR"]] = mem[mem[mem[*PC]]];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = mem[mem[instrMap["MAR"]]];
			break;

	//ADD
		case 65: //register to register
			//Source
			mem[instrMap["MDR"]] = mem[mem[*PC]];
			mem[instrMap["MAR"]] = mem[instrMap["MDR"]];
			(*PC)++;

			//Add and save the result at Destination
			mem[mem[*PC]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 66: //Constant to a register
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			cout << mem[mem[instrMap["MAR"]]] << "  " <<mem[mem[*PC]] ;
			mem[mem[*PC]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 67:
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;

		case 68:
			//Source
			mem[instrMap["MAR"]] = mem[mem[mem[*PC]]];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;

	//SUBTRACT
		case 75: //register to register
			//Source
			mem[instrMap["MDR"]] = mem[mem[*PC]];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Add and save the result at Destination
			mem[mem[*PC]] = SUB(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 76: //Constant to a register
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[*PC]] = SUB(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 77:
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = SUB(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;

		case 78:
			//Source
			mem[instrMap["MAR"]] = mem[mem[mem[*PC]]];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = SUB(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;

	//DIVIDE
		case 85: //register to register
			//Source
			mem[instrMap["MDR"]] = mem[mem[*PC]];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Add and save the result at Destination
			mem[mem[*PC]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 86: //Constant to a register
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[*PC]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 87:
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;

		case 88:
			//Source
			mem[instrMap["MAR"]] = mem[mem[mem[*PC]]];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;
	//MUL
		case 95: //register to register
			//Source
			mem[instrMap["MDR"]] = mem[mem[*PC]];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Add and save the result at Destination
			mem[mem[*PC]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 96: //Constant to a register
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[*PC]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 97:
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;

		case 98:
			//Source
			mem[instrMap["MAR"]] = mem[mem[mem[*PC]]];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;
	//MOD
		case 105: //register to register
			//Source
			mem[instrMap["MDR"]] = mem[mem[*PC]];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Add and save the result at Destination
			mem[mem[*PC]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 106: //Constant to a register
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[*PC]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[*PC]]);
			break;

		case 107:
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;

		case 108:
			//Source
			mem[instrMap["MAR"]] = mem[mem[mem[*PC]]];
			(*PC)++;

			//Destination
			mem[mem[mem[*PC]]] = ADD(mem[mem[instrMap["MAR"]]], mem[mem[mem[*PC]]]);
			break;
	//PUSH
		case 115: //register to stack
			//Source
			mem[instrMap["MDR"]] = mem[mem[*PC]];
			mem[instrMap["MAR"]] = instrMap["MDR"];

			//Push value to stack
			PUSH(mem[mem[instrMap["MAR"]]]);
			break;

		case 116: //Constant to a register
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];

			//Push value to stack
			PUSH(mem[mem[instrMap["MAR"]]]);
			break;

		case 117:
			//Source
			mem[instrMap["MDR"]] = mem[*PC];
			mem[instrMap["MAR"]] = instrMap["MDR"];

			//Push value to stack
			PUSH(mem[mem[instrMap["MAR"]]]);
			break;
	//POP
		case 125:
			POP();
			break;
		}
		(*PC)++;
		cout << "\nPCend =" << (*PC);
		displayCPUState();
	}

}



void displayCPUState(){

    printf("eax: %d ",mem[instrMap["%eax"]]);

    printf(" ecx: %d ",mem[instrMap["%ecx"]]);
    printf(" ebx: %d ",mem[instrMap["%ebx"]]);
    printf(" edx: %d ",mem[instrMap["%edx"]]);
    printf(" esi: %d ",mem[instrMap["%esi"]]);
    printf(" edi: %d ",mem[instrMap["%edi"]]);

    printf("\nMAR: %d ",mem[instrMap["MAR"]]);

    printf("MDR: %d ",mem[instrMap["MDR"]]);

    printf("PC: %d ",*PC);

    printf("FLAG: %d \n",flag);



}

void init(){
	instrMap["end"] = 0;
	instrMap["END"] = 0;

	instrMap["MOV"] = 55;//From reg to reg
	instrMap["MOVC"] = 56;//Constant to a reg
	instrMap["MOVCR"] = 57;//Contant to address referenced by reg
	instrMap["MOVR"] = 58;//Move value at location referenced by a reg to location referenced by reg

	instrMap["ADD"] = 65;//From reg to reg
	instrMap["ADDC"] = 66;//Constant to a reg
	instrMap["ADDCR"] = 67;//Contant to address referenced by reg
	instrMap["ADDR"] = 68;//Move value at location referenced by a reg to location referenced by reg

	instrMap["SUB"] = 75;//From reg to reg
	instrMap["SUBC"] = 76;//Constant to a reg
	instrMap["SUBCR"] = 77;//Contant to address referenced by reg
	instrMap["SUBR"] = 78;//Move value at location referenced by a reg to location referenced by reg

	instrMap["MUL"] = 85;//From reg to reg
	instrMap["MULC"] = 86;//Constant to a reg
	instrMap["MULCR"] = 87;//Contant to address referenced by reg
	instrMap["MULR"] = 88;//Move value at location referenced by a reg to location referenced by reg

	instrMap["DIV"] = 95;//From reg to reg
	instrMap["DIVC"] = 96;//Constant to a reg
	instrMap["DIVCR"] = 97;//Contant to address referenced by reg
	instrMap["DIVR"] = 98;//Move value at location referenced by a reg to location referenced by reg

	instrMap["MOD"] = 105;//From reg to reg
	instrMap["MODVC"] = 106;//Constant to a reg
	instrMap["MODCR"] = 107;//Contant to address referenced by reg
	instrMap["MODR"] = 108;//Move value at location referenced by a reg to location referenced by reg

	instrMap["PUSH"] = 115; // Register value to stack
	instrMap["PUSHC"] = 116; // Constant value to stack
	instrMap["PUSHR"] = 117; // Value referenced by register to stack

	instrMap["POP"] = 125;// Pop value to MDR

	instrMap["%ecx"] = 1;
	instrMap["%edx"] = 2;
	instrMap["%ebx"] = 3;
	instrMap["%esi"] = 4;
	instrMap["%edi"] = 5;
	instrMap["%esp"] = 6;
	instrMap["%ebp"] = 7;
	instrMap["%eax"] = 8;
	instrMap["PC"] = 9;
	instrMap["MAR"] = 10;
	instrMap["MDR"] = 11;

	//For referrenced reg values
	instrMap["(%ecx)"] = 1;
	instrMap["(%edx)"] = 2;
	instrMap["(%ebx)"] = 3;
	instrMap["(%esi)"] = 4;
	instrMap["(%edi)"] = 5;
	instrMap["(%esp)"] = 6;
	instrMap["(%ebp)"] = 7;
	instrMap["(%eax)"] = 8;
//	instrMap["(%PC)"]  = 9;// not implemented usually
	instrMap["(%MAR)"] = 10;
	instrMap["(%MDR)"] = 11;

	PC = &mem[instrMap["PC"]];//to be used


}
//Bitwise Multiplication
unsigned int multiplication(unsigned int TempA, unsigned int TempB)
{
	unsigned int mask, TempC = 0;

	while(TempB != 0)
    {
		mask = 1;
		mask = mask & TempB;

		if(mask)
			TempC = add(TempA + TempC);

		TempA = TempA << 1;
        TempB = TempB >> 1;
    }

	return TempC;
}
int ADD(int x, int y)
{
	cout << "Adding x= " << x << " y = " << y;
  do
  {
    x=x^y;
    y=(x^y)&y;
    y=y<<1;
  } while(y);
  cout << "\nResult :" << x;
   return(x);
}

int SUB(int x, int y)
{
  return ADD(x, -y);
}

int MUL(int x, int y)
{
  int n = x;
  while (n)
  {
    x = ADD(x, y);
    n = SUB(n, 1);
  }
  return y;
}

int DIV(int x, int y)
{
  int n = 0;
  while (x > y)
  {
    x = SUB(x, y);
    n = ADD(n, 1);
  }
  return n;
}

int MOD(int x, int y)
{
	//Compute modulus division by 1 << s without a division operator

	unsigned int n;          // numerator
	unsigned int s;
	const unsigned int d = 1U << s; // So d will be one of: 1, 2, 4, 8, 16, 32, ...
	unsigned int m;                // m will be n % d
	m = n & (d - 1);
	return m;
}

void PUSH(int value){

	mem[stack_pointer] = value;
	stack_pointer--;
}

void POP(){
	if(stack_pointer >= 1023){
		stack_pointer = 1023;
		return;
	}
	stack_pointer++;
	mem[instrMap["MDR"]] = mem[stack_pointer];
}


int main() {
	init();
	displayCPUState();
	cout << "\nEnter instructions..." << endl;
	getline(cin, input);
	loadProgram();
	startExecution();
	displayCPUState();

    printf("Memory: ");

    for(int i=0; i<10; i++)
	{
		if(i%3 == 0)
			cout << "\n";
		cout << codeSegment[i] << " ";
	}

	for(int i=0; i<50; i++)
	{
			cout << "\nLoc " << i << " = " << mem[i] ;
	}
	for(int i=1015; i<1024; i++)
	{
			cout << "\nLoc " << i << " = " << mem[i] ;
	}
	cout << "\n********Terminated*********";
	return 0;
}
