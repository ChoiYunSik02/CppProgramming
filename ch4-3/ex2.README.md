# 실습과제 2 - 코드 문제점 분석

## 문제점
해당 코드에서는 `new`를 사용하여 `Circle` 객체를 생성하지만, `delete`를 사용하지 않아 메모리 누수가 발생한다.

```cpp
Circle* p = new Circle(radius);
```
이 객체는 반복문이 돌 때마다 계속 생성되지만, 이전에 생성된 객체는 해제되지 않는다.

## 해결 방법
객체 사용 후 반드시 `delete`를 호출해야 한다.

```cpp
delete p;
```

## 결론
동적 할당을 사용할 경우, 반드시 메모리 해제를 해야 하며, 그렇지 않으면 메모리 누수가 발생한다.


## 수정 후 실행결과
<img width="1110" height="358" alt="image" src="https://github.com/user-attachments/assets/627540e0-ca29-4e48-a08d-2eb87523e0a0" />

<br>
