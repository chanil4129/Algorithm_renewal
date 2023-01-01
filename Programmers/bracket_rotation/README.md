# 1

### 문자열 회전은 substr을 통해 넘겨주고, s[0]를 뒤에 붙여줬다. 올바른 괄호인지는 stack을 통해 해결

## string 클래스
- substr 메소드 : 문자열 중 원하는 부분을 잘라서 넘겨준다
```
string b;
string s="abcde";
b=s.substr(1); // b = "bcde"
```

# 다른 사람 풀이
## 2

### rotate 함수 이용

## algorithm 헤더
- rotate : 지정된 횟수만큼오른쪽으로 회전시키거나, 왼쪽으로 회전. 인자는 (시작 반복자, 첫 위치로 올 forward 반복자, 종료 반복자).
```
rotate(s.begin(),s.begin()+1,s.end()); //왼쪽으로 한칸
```

-------------------------------

https://school.programmers.co.kr/learn/courses/30/lessons/76502?language=cpp