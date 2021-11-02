#1267 핸드폰요금 Bronze III
#수학, 사칙연산
#map을 알아야 풀 수 있는 문제 (한 줄에 여러 수 입력받기)
#최소값 min함수를 알아도 문자를 출력해야 하므로 if문 필수
n=int(input())
a,b=0,0

k=list(map(int, input().split()))
for i in range(n):
    a+=(1+k[i]//30)*10
    b+=(1+k[i]//60)*15
if a==b:
    print("Y M ", end="")
elif a>b:
    print("M ", end="")
else:
    print("Y ", end="")
print(min(a,b))