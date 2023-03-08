# C Review

1. write program -> text editor

2. compile -> compiler(source file -> object file)

3. link -> linker(object file -> executable file)

4. execute -> runner 

switch는 까먹으니까 한번 적어놓고 가자

```C
switch(expression)
  {
  case constatnt-1 : statement
                     ..
                     statement

  case constatnt-2 : statement
                     ..
                     statement

  case constatnt-3 : statement
                     ..
                     statement

  dafault          : statement
                     ..
                     statement
  }
```


Function 
- declare
- call
- definition
function을 call 할 때 jump가 일어난다. 

함수가 main에서 함수를 호출하는 그 부분을 caller라고 하고 main밖에서 호출을 받는 친구를 callee라고 한다. 
당연히 call하는 순간 caller-> callee로 parameter를 전달하고 다시 callee가 실행한 이후 return value를 줄 때 callee-> caller로 방향이 바뀐다. 

그런데 서로가 상호간에 전달과 교류가 일어나려면 pointer가 필요하다. 

swap이라는 함수를 만들어보자

```C
//calling function
int main()
{
  int a = 10, b = 20;
  //...
  Excahnge(a,b);
  //...
}

//called function
void Exchange(int x, int y)
{
  int hold = 0;
  hold = x;
  x = y;
  y = hold;
}
```
자, 이렇게 됐을 때 메모리와 관련해서 설명해보자.
a,b가 있는 메모리가 있을 것이고 callee의 메모리가 또 따로 할당이 되어 있다. 
callee에서 int x와 int y 는 a,b와는 다른 곳의 또 다른 메모리에 x,y가 할당되어 있다. 
parameter전달을 통해 x는 a의 값을, y는 b의 값을 카피한다. 
x는 10, y는 20이라는 말. 그러나 callee안에서 제아무리 x,y,hold를 바꾸고 난리를 쳐도 a,b는 다른 메모리에 있는 값들이기에 전혀 바뀌지 않는다. 그냥 x,y라는 녀석들만 서로 바꾸는 것.
따라서 a,b자체의 값을 바꾸기 위해서는 a,b의 **주소값**이 필요하다.

그렇기에 코드가 이렇게 바뀐다. 

```C
//calling function
int main()
{
  int a = 10, b = 20;
  //...
  Excahnge(&a,&b);
  //...
}

//called function
void Exchange(int * x, int * y)
{
  int hold = 0;
  hold = *x;
  *x = *y;
  *y = hold;
}
```
이미 a,b의 주소값을 넘겨주고, 그러면 int * x는 x가 무언가를 포인팅하는 중이라는 말이니까, a의 주소값을 가리키고 있다고 이해된다. 
int * x는 지금 그 값이 &a이다. 따라서 a의 주소가 아니라 a의 값을 포인팅하려면 그냥 x가 아니라 x의 내용인 (\*x)라고 표현된다. 

#include <stdio.h>에서 stdio.h는 system library이다. 따라서 이 시스템 자체에서 제공하는 header파일이라는 의미이다.
만약 내가 만든 header파일을 참조하고 싶다면 
뭐, app.h라는 헤더파일을 내가 만들었다고 하자. 그러면 꺽새가 아니라 ""로 include 해야 한다. 
#include ""이런 식으

따라서 header파일이 여러개가 될 수도 있다. 때문에 프로그램은 단일 파일이 아니라 여러개의 파일들이 함께 존재한다. 
각각의 source file들이 각각 compiling되면 각각 0과 1로 이뤄진 object파일들이 생긴다. 
그것들과 library module들을 모두 linker가 link 해서 executable파일로 만들어 실행시킨다. 

# recursion
function call to itself : 스스로가 계속 스스로를 부르는 함수


# file Access
1. declare pointer of a stream;
Ex) FILE * spData = NULL;
2. Open a file : Associate stream to a file
EX) spData = fopen("myfile.txt","r");
3. Access file : read or write file through stream
EX) fscanf(spData, "%d", &value);
4. Close a file : breaks association between stream and file
EX) fclose(spData);

# array
int a[10]
a = &a[0];

# string
End of string is denoted by null character('\0)

# structure
일반 배열과 다르게 다른 타입들을 함께 묶은 파워풀한 툴이 되어준다.








