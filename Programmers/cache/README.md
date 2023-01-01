# 1

### cities를 로딩하는 반복문을 통해 모두 소문자로 변환하고, cacheSize가 0일 경우는 모두 miss이므로 5를 누적합해준다. 그외 캐시에 들어있는 도시가 꽉찬 경우와 그렇지 않은 경우에서 hit, miss를 각각 처리

---------------------------------

# 다른 사람 풀이

# 2

### transform, find를 활용한 풀이

## algorithm 헤더
- transform : 특정 함수를 써서 값을 변경할 때 유용한 함수
- tolower : 소문자 변환 함수
```
transform(s.begin(),s.end(),s.begin(),::tolower);
```
- find : 범위 안에 원하는 값을 찾으면 해당 iterator를 리턴. 못 찾으면 last를 리턴
```
auto city=find(cachePage.begin(),cachePage.end(),s);
if(city != cachePage.end()){
    /// 찾은 경우
}
```

---------------------------------

https://school.programmers.co.kr/learn/courses/30/lessons/17680