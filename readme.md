<h2>simple stack based Virtual machine</h2>
<h3>build </h3>
clone the repo and fire the make command
<h3>changing the program </h3>
to change the program edit the<br> 
<b>Note</b> the program is array so dont forget to put , after every instructions<br>

```c
int program[] = {
PSH, 15,
PSH, 3,
DIV,
HLT,
//the stack pointer must pointing to value 5 
};
```
<h3>instruction set </h3>

Operation | Description
------ | ------ 
PSH   | pushes the value to the top of the stack
POP   | pops the value , now the stack pointer points to the previous value
ADD   | Adds the the top two values and pushes them
SUB   | substracts the the second value from the previous
MUL   | multiples top two values on the stack
Div   | divides the top value by the first second top value
HLT   | Marks the end of the program 
