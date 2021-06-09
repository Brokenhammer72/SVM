#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Stack_Size 512

int ip = 0;//instruction Pointer
int sp = -1; //stack pointer

int stack[Stack_Size];

bool running = true;

enum{
  PSH,  //pushes the given value 
  POP,  //pops the value 
  ADD,  //add the top two terms
  SUB,  //substract the first term with second term
  MUL,  //multiple top two terms
  DIV,  //divide top two terms
  HLT   //terminate the program
} InstructionSet;

//example program
int program[] = {
  PSH, 15, 
  PSH, 3,
  DIV,
  HLT,
};


int fetch(){
  return program[ip];
}

//evaluates the instrcution
void eval(int instr){
  switch(instr){
    case HLT:{
        running = false;
        break;
    }
    case PSH: {
        sp++;
        ip++;
        stack[sp] = program[ip];
        break;
    }
    case ADD: {
        int a = stack[sp];
        int b = stack[--sp];
        int result = a+b;
        sp++;
        stack[sp]=result;
        break;
    }
    case POP: {
        sp--;
        break;
    }
    case SUB: {
        int a = stack[sp];
        int b = stack[--sp];
        int result = a-b;
        sp++;
        stack[sp]=result;
        break;
    }
    case MUL: {
        int a = stack[sp];
        int b = stack[--sp];
        int result = a*b;
        sp++;
        stack[sp]=result;
        break;
    }
    case DIV: {
        int a = stack[sp];
        int b = stack[--sp];
        int result = b/a;
        sp++;
        stack[sp]=result;
        break;
    }

  }  
}

void printstack(){
  for(int i=0;i<6;i++){
    printf("%d ",stack[i]);
  }
  printf("stack \n");
  printf("stack Pointer: %d\n",sp);
}

int main(){
  while(running){
    printstack();
    eval(fetch());
    ip++;
  }
}
