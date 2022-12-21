# 1

### string과 char[]을 잘 구분해야함. 
### 관리하기 힘들면 string의 c_str 메소드를 이용.

## cstring 헤더
* strcpy : 문자열 복사.
* strtok : 문자열 토큰 분리.
- 예시 => 
```
char *ptr=strtok(s," ");
while(ptr!=NULL){
    printf("%s\n",ptr);
    ptr=strtok(NULL," ");
}
```

## vector 헤더
* max_element, min_element : 벡터 값의 주소를 리턴.
- 예시 => 
```
int max = *max_element(v.begin(),v.end());
```
- index도 알 수 있다. 예시 =>  
```
int max_index = max_element(v.begin(), v.end()) - v.begin();
```

---------------------------------------


# 다른 풀이 참고
## 1

### string에 append 메소드 말고 +=으로 문자열 추가할 수 있음. 
### vector를 sort하고 v.front()와 v.back()으로 최댓값, 최솟값 구할 수 있음.

## string 클래스
* stoi : string을 int로
* clear : 문자열 비워주기

## string 헤더
* to_string : 문자열로 바꿔주기
- 예시 => 
```
to_string(v.front()) + " " + to_string(v.back());
```

---------------------------------------

## 2

### istringstream과 getline 활용

## sstream 헤더
* istringstream : 공백을 기준으로 문자열을 파싱하여 변수의 형식에 맞게 변환.
- 예시 => 
```
string token;
istringstream iss(s);
while(getline(iss, token, ' ')){
    v.push_back(stoi(token));
}
```

## string 헤더
* getline : 원하는 구분자(delimiter)를 만날 때 까지 모든 문자열을 입력 받아 하나의 string 객체에 저장
- 참고 : https://kyu9341.github.io/C-C/2020/01/17/C++getline()/

---------------------------------------

## 3

### find와 substr 활용

## string 클래스
* find : 문자열에서 원하는 문자열의 위치를 찾기
* substr : 문자열의 일부를 리턴
- 두개의 메소드 예시 => 
```
int pos = s.find(" ");
string ans = s.substr(0, pos);
```

---------------------------------------

https://school.programmers.co.kr/learn/courses/30/lessons/12939