////============================================================================
//// Name        : best_cpu.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include <iostream>
//using namespace std;
//#include <string.h>
//#include <stdio.h>
//#include <sstream>
//#include <map>
//#include <stdlib.h>
//
//#include "best_cpu.h"
//
//
//
//void loadProgram(){
//	string token;
//	mem[instrMap["PC"]] = 0;
//	while(input.compare("end")){
//		istringstream isPrgm(input);
//		isPrgm >> token;
//		while(isPrgm){
//			codeSegment[mem[instrMap["PC"]]] = token;
//			mem[instrMap["PC"]]++;
//			isPrgm >> token;
//		}
//
//		getline(cin, input);
//	}
//	codeSegment[mem[instrMap["PC"]]] = "end";
//	mem[instrMap["PC"]]++;
//}
//
//void startExecution(){
//
//	int i = 0, src, des;
//	string op1, op2, instr, temp;
//	string array[] = {instr, op1, op2};
//	mem[instrMap["PC"]] = 0;
//	int *pc = &mem[instrMap["PC"]];//to be used
//
//	while(codeSegment[mem[instrMap["PC"]]].compare("end")){
//		i = 0;
//		switch(instrMap[codeSegment[mem[instrMap["PC"]]]]){
//		// Case 55 for MOV instruction
//		case 55:
//			mem[instrMap["PC"]]++;
//
//			//Src
//			if(instrMap[codeSegment[mem[instrMap["PC"]]]] > 0){
//				switch(instrMap[codeSegment[mem[instrMap["PC"]]]]){
//					// Cases for reg to reg transfers
//					case 1:
//					case 2:
//					case 3:
//					case 4:
//					case 5:
//					case 6:
//					case 7:
//					case 8:
//						mem[instrMap["MAR"]] = instrMap[codeSegment[mem[instrMap["PC"]]]];
//						break;
//
//					//Cases for referenced reg address
//					case 50001:
//					case 50002:
//					case 50003:
//					case 50004:
//					case 50005:
//					case 50006:
//					case 50007:
//					case 50008:
//						mem[instrMap["MAR"]] = mem[instrMap[codeSegment[mem[instrMap["PC"]]]]%10000];
//						break;
//				}
//
//			}else{
//				// For absolute values
//				mem[instrMap["MDR"]] = stoi(codeSegment[mem[instrMap["PC"]]]);
//				mem[instrMap["MAR"]] = instrMap["MDR"];
//			}
//			mem[instrMap["PC"]]++;
//
//			//Dest
//			if(instrMap[codeSegment[mem[instrMap["PC"]]]] > 0){
//				switch(instrMap[codeSegment[mem[instrMap["PC"]]]]){
//				// Cases for reg to reg transfers
//					case 1:
//					case 2:
//					case 3:
//					case 4:
//					case 5:
//					case 6:
//					case 7:
//					case 8:
//						mem[instrMap[codeSegment[mem[instrMap["PC"]]]]] = mem[mem[instrMap["MAR"]]];
//						break;
//					//Cases for referenced reg address
//					case 50001:
//					case 50002:
//					case 50003:
//					case 50004:
//					case 50005:
//					case 50006:
//					case 50007:
//					case 50008:
//						mem[mem[instrMap[codeSegment[mem[instrMap["PC"]]]]%10000]] = mem[mem[instrMap["MAR"]]];
//						break;
//				}
//
//			}else{
//				// For absolute values
//				mem[stoi(codeSegment[mem[instrMap["PC"]]])] = mem[mem[instrMap["MAR"]]];
//				cout << "\n-------ERROR-------";
//			}
//			mem[instrMap["PC"]]++;
//			break;
//		}
//		displayCPUState();
//	}
//
//}
//
//
//
//void displayCPUState(){
//
//    printf("eax: %d ",mem[instrMap["%eax"]]);
//
//    printf(" ecx: %d ",mem[instrMap["%ecx"]]);
//    printf(" ebx: %d ",mem[instrMap["%ebx"]]);
//    printf(" edx: %d ",mem[instrMap["%edx"]]);
//    printf(" esi: %d ",mem[instrMap["%esi"]]);
//    printf(" edi: %d ",mem[instrMap["%edi"]]);
//
//
//    printf("PC: %d ",mem[instrMap["PC"]]);
//
////    printf("(per eax: %d \n",mem[mem[instrMap["(%eax)"]%10000]]);
//
////    printf("(perecx: %d ",mem[mem[instrMap["(%ecx)"]%10000]]);
//
//    printf("\nMAR: %d ",mem[instrMap["MAR"]]);
//
//    printf("MDR: %d ",mem[instrMap["MDR"]]);
//
//    printf("PC: %d ",mem[instrMap["PC"]]);
//
//    printf("FLAG: %d \n",flag);
//
////    printf("Memory: ");
////
////    for(int i=0; i<10; i++)
////	{
////		if(i%3 == 0)
////			cout << "\n";
////		cout << codeSegment[i] << " ";
////	}
////
////	for(int i=0; i<50; i++)
////	{
////			cout << "\nLoc " << i << " = " << mem[i] ;
////	}
//
//}
//
//void init(){
//
//	instrMap["MOV"] = 55;
//
//	instrMap["%ecx"] = 1;
//	instrMap["%edx"] = 2;
//	instrMap["%ebx"] = 3;
//	instrMap["%esi"] = 4;
//	instrMap["%edi"] = 5;
//	instrMap["%esp"] = 6;
//	instrMap["%ebp"] = 7;
//	instrMap["%eax"] = 8;
//	instrMap["PC"] = 9;
//	instrMap["MAR"] = 10;
//	instrMap["MDR"] = 11;
//
//	//For referrenced reg values
//	instrMap["(%ecx)"] = 50001;
//	instrMap["(%edx)"] = 50002;
//	instrMap["(%ebx)"] = 50003;
//	instrMap["(%esi)"] = 50004;
//	instrMap["(%edi)"] = 50005;
//	instrMap["(%esp)"] = 50006;
//	instrMap["(%ebp)"] = 50007;
//	instrMap["(%eax)"] = 50008;
////	instrMap["%PC"]  = 50008;// not implemented usually
//	instrMap["(%MAR)"] = 50010;
//	instrMap["(%MDR)"] = 50011;
//
//
//
//
//}
//int main() {
//	init();
//	displayCPUState();
//	cout << "\nEnter instructions..." << endl;
//	getline(cin, input);
//	loadProgram();
//	startExecution();
//	displayCPUState();
//
//    printf("Memory: ");
//
//    for(int i=0; i<10; i++)
//	{
//		if(i%3 == 0)
//			cout << "\n";
//		cout << codeSegment[i] << " ";
//	}
//
//	for(int i=0; i<50; i++)
//	{
//			cout << "\nLoc " << i << " = " << mem[i] ;
//	}
//
//	cout << "\n********Terminated*********";
//	return 0;
//}
