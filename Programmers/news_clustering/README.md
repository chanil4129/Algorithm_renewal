# 1
### 소문자 변환, 집합 생성, 교집합과 합집합 구하기 순서로 진행.

### string 헤더
- tolower로 소문자로 바꾸기
```
string str;
for(char &c:str){
    c=tolower(c);
}
```
- transform 사용 방법도 있다(algorithm 헤더)
```
transform(str.begin(), str.end(), str.begin(), ::tolower);
```

### vector 헤더
- i번째 벡터 원소 지우기
```
v.erase(v.begin()+i);
```
- v1벡터 뒤에 v2벡터 이어붙이기
```
vector<string>::iterator it=v1.insert(v1.end(),v2.begin(),v2.end());
```
---------------------------------
# 다른 사람 풀이
## 2
### 26*26+26=676으로 26을 곱하는 이유는 "ab"와 "ba"를 구분하기 위함이라보면 된다. 원소들의 개수들을 세주고, 그것을 이용해 교집합/합집합을 구한다.

## 3
### 2.cpp을 좀 더 효율적으로 적은 코드

---------------------------------

https://school.programmers.co.kr/learn/courses/30/lessons/17677?language=cpp