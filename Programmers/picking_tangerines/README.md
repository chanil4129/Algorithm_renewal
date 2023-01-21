# 1

### unordered_map과 value 순서로 정렬하기 위해 vector를 써서 풀이.

### map->vector
```
unordered_map<int, int> m;
// 중간 코드
vector<pair<int,int>> v(m.begin(),m.end());
```

---------------------------

https://school.programmers.co.kr/learn/courses/30/lessons/138476?language=cpp