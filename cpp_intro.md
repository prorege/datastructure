# INTRODUCTION
```cpp
#include <iostream>
  
  int main(){
    //C였다면 printf("Hello World!");
  std::cout << "Hello world!";
  
  return 0;
}
```

- std에 있는 cout을 통해 Hello world를 출력하라는 것.
- Hello world라는 문자열을 cout이라는 객체에게 보내라는 의미의 꺾새 <<
- 그런데 자꾸 std::를 쓰기가 불편하니 아래와 같이 쓸 수 있다. 

```cpp
#include <iostream>
using namespace std;

int main(){
  cout << "Hello world!" << endl;
  
  return 0;
}
  ```
  
 - namespace가 뭔가 하면, 우리 대학의 김요한이 있지만 다른 대학에도 김요한이 존재한다. 그럼 둘은 같은 존재? 아니다. 이럴 경우 namespace가 다르다고 한다.
 - 우리는 std라는 namespace의 cout이라는 객체를 사용한다는 것.
 - 위의 두 줄은 무조건 적고 작성하면 된다. 
 - endl는 C의 \n과 같은 역할 개행문자이다. 


- scanf역할은 cin이 한다. 

간단한 예제 코드를 짜보자

```cpp
#include <iostream>
using namespace std;

int main(){
  int i, j;
  cout << "Enter two integers: ";
  cin >> i >> j;
  int sum = i + j;
  cout << "Sum of " << i << " and " << j << " is " << sum << endl;
  
  return 0;
}
  ```
  위 파일을 test.cpp라고 가정하자. g++ test.cpp -o sum이라고 치면 sum.exe라는 실행파일을 만들어준다. ./sum.exe를 치면 실행된다. 

한번 더 연습해보자. 두 정수를 입력받고 큰 수를 알려주는 프로그램

```cpp
#include <iostream>
using namespace std;

int main(){
  int i, j;
  cout << "Enter two integers: ";
  cin >> i >> j;
  int large, small;
  if(j > i) {
    large = j;
    small = i;
  }
  else if(j < i) {
    large = i;
    small = j;
  }
  else {
    large = j;
    small = i;
  }
  cout << large << " is larger than " << small << "." << endl;
  
  return 0;
}
  ```
  
  - setw
```cpp
#include<iostream> 
#include<iomanip> 
 
using namespace std; 
int main() 
{
    cout << setw(5) << "a" << endl;
}

//결과값은 아래처럼 다섯 칸의 공백 이후 a를 여섯번째에 출력한다. 
//     a
```

### initialization & bool type
int i = 0 이 C style이고 
Int i(0);이 CPP style

bool found(true);
cout << found << endl;
을 하면 1이 출력된다. 
 
### namespace

```cpp
#include<iostream> 
 
namespace Space_A {
  int num = 20;
}
namespace Space_B {
  int num = 30;
}
using namespace std;

int main() 
{
  int num 10;
  cout << "main: " << num << endl;
  cout << "Space_A: " << Sapce_A :: num << endl;
  cout << "Space_B: " << Space_B :: num << endl;
  // cout << "std: " << std :: num << endl;  이 구문은 에러남 정의되어있지 않기에. 그런데 잘 이해는 안돼
}

```

```cpp
#include<iostream> 
 
namespace Space_A {
  int num = 20;
}
namespace Space_B {
  int num = 30;
}
using namespace std;
using namespace Space_A;
//using namespace Space_B; 만약 이 구문을 쓰면 num을 뭘로 써야 할지 몰라 error가 난다.

int main() 
{
  // int num 10;
  // cout << "main: " << num << endl;
  cout << "Space_A: " << num << endl; //현재 정의되고 사용되는 num은 Space_A의 num밖에 없다. 
  cout << "Space_B: " << Space_B :: num << endl;
}

```
```cpp

#include<iostream> 
 
namespace Space_A {
  int num = 20;
  int get_num(int n){
    return n+1;
  }
}
using namespace std;
using namespace Space_A;

int num(30);

int main() 
{
  int num 10;
  cout << "main: " << num << endl;
  cout << "Global: " << :: num << endl;
  cout << "Space_A: " << Space_A :: get_num(100) << endl;
}
//결과는 10,30,101이 차례로 나온다. 
```


### Random Number
- #include <cstdlib>를 쓰면 srand(111)와 같이 랜덤을 사용할 수 있다.
- #include <ctime>을 쓰면 srand((unsigned) time(NULL));을 사용할 수 있다. 
  
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int num;

    srand(123);
    num = rand();
    cout << "num: " << num << endl;

    srand((unsigned)time(NULL));
    num = rand();
    cout << "num: " << num << endl;
// 첫번째 랜덤은 123으로 seed number을 고정시켰지만 두번째 랜덤은 현시각으로 계속 변한다.

    return 0;
}
```

### Range based For

```cpp
#include <iostream>

using namespace std;

int main(){
    int arr[10] = {0,1,2,3,4,5};

    for(int item: arr){
        cout << item << "\n";
    }
    cout << endl << endl;

    for(auto item: arr){
        cout << item << "\t";
    }
    cout << endl << endl;
}
```


### Reference Avriable(alias)
  int num = 100, m = 20;
  int &num1 = n;
  int &num2 = num1;
  num1 = m; // same as n = m;
- 이는 포인터의 개념과는 다르다. 
   - 그런데 잘 모르겠음. 질문해야겠음
  


