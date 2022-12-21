# 1

### stringstream과 getline으로 토큰 분리 후, 토큰을 JadenCase로 바꾸기. 공백도 전부 출력해야하기 때문에 몇몇 조건들 추가.

## sstream 헤더
* stringstream : 공백을 기준으로 문자열을 파싱하여 변수의 형식에 맞게 변환.
- 예시 => 
```
string token;
istringstream ss(s);
while(getline(ss, token, ' ')){
    cout<<token<<"\n"
}
```
## string 헤더
* getline : 원하는 구분자(delimiter)를 만날 때 까지 모든 문자열을 입력 받아 하나의 string 객체에 저장
- 참고 : https://kyu9341.github.io/C-C/2020/01/17/C++getline()/
* tolower : 소문자로 바꾸는 함수
- 예시 =>
```
for(int i=0;i<s.size();i++){
    result+=tolower(s[i]);
}
```
## stirng 클래스
* back : 가장 뒤 문자 반환
* pop_back : 가장 뒤 문자 빼기

---------------------------------------

# 2

### find와 substr을 이용한 풀이

## string 클래스
* find : 문자열에서 원하는 문자열의 위치를 찾기
* substr : 문자열의 일부를 리턴
- 두개의 메소드 예시 => 
```
int pos = s.find(" ");
string ans = s.substr(0, pos);
```

---------------------------------------

# 다른 풀이 참고
## 1

### 앞에 공백인 경우에만 대문자로 바꾸고 평소에는 소문자로 바꾸는 방식
```
string answer = "";

answer += toupper(s[0]);
for (int i = 1; i < s.size(); i++)
    s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

return answer;
```
---------------------------------------

https://school.programmers.co.kr/learn/courses/30/lessons/12951