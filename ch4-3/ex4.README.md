# 실습과제 4 - Triangle 클래스 설명

## 클래스 구성
- `base`, `height`: 밑변과 높이 저장
- `생성자`: 값 초기화 + 생성 메시지 출력
- `소멸자`: 객체 삭제 시 소멸 메시지 출력
- `getArea()`: 삼각형 면적 계산

---

## 핵심 개념

- **객체 배열 동적 생성 및 초기화**
```cpp
Triangle* tri = new Triangle[3]{ ... };
```

- **배열 형태 접근**
```cpp
tri[i].getArea()
```

- **메모리 해제**
```cpp
delete[] tri;
```

## 결론
객체 배열을 동적으로 할당할 때 초기화 리스트(`{}`)를 활용하면 배열 생성과 동시에 원하는 값으로 객체를 설정할 수 있다.


## 실행 결과
<img width="1111" height="291" alt="image" src="https://github.com/user-attachments/assets/0b7273b9-8956-4bb4-b67c-138bc26ab911" />

<br>
