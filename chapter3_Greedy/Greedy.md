# GREEDY
당장 좋은 것만 선택하는 알고리즘

## Greedy 알고리즘
현재 상황에서 지금 당장 좋은 것만 고르는 방법. <br>
최적해를 구하는 데에 사용되는 근사적인 방법이다. <br>

따라서 지역적으로는 최적해이지만, 전역적으로 봤을 때 최적해가 아닐 수 있음에 유의해야 한다. 따라서 greedy 알고리즘을 적용할 때에는 다음의 조건이 부합하는지 확인해야 한다.

## Greedy 알고리즘을 적용할 수 있는 문제 조건
### 1. Greedy Choice Property (탐욕적 선택 조건)
앞의 선택이 뒤의 선택에 영향을 주지 않는 것.
즉 지역 최적해가 전역 최적해가 된다는 것이다.

### 2. Optimal Substructure (최적 부분 구조)
문제에 대한 최적해가 부분문제에 대해서도 역시 최적해인 경우.
부분 문제에 대한 해가 최종해가 되는 경우이다.

특별한 구조가 있는 경우는 greedy 알고리즘이 항상 최적해를 보장한다. 이때의 구조를 <strong>매트로이드</strong> 라고 한다.

## Greedy 연습 문제
[백준 11047: 동전 0](https://www.acmicpc.net/problem/11047) <br>
[백준 4013: ATM](https://www.acmicpc.net/problem/4013)

## Greedy 알고리즘 예시
- Activity Selection Problem
- Fractional knapsack problem
- Kruskal's Algorithm
- Dijkstra Algorithm

## 참고 자료
https://ko.wikipedia.org/wiki/탐욕_알고리즘
https://hanamon.kr/알고리즘-탐욕알고리즘-greedy-algorithm/
<이것이 코딩 테스트다 with python>
