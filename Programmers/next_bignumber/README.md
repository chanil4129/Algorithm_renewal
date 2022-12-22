# 1

### n의 1 bit 몇개인지 세고, n에 1씩 증가하면서 1 bit 개수가 같을 때 리턴.

-------------------------------
# 다른 사람 풀이
# 2

### bitset 헤더와 bitset 클래스 사용. 알고리즘은 1.cpp과 같음

* bitset 헤더
```
bitset<6> bit("110011"); // 문자열 "110011"로 초기화
int num=bitset<20>(n).count(); //n의 1 bit 개수 세기
```

-------------------------------

https://school.programmers.co.kr/learn/courses/30/lessons/12911