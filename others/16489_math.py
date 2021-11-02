from decimal import Decimal #정밀한 수 연산
a,b,c=map(Decimal, map(int, input().split()))
# 헤론의 공식
s=(a+b+c)/2
S=((s*(s-a)*(s-b)*(s-c))).sqrt()
# 사인 법칙
R=a*b*c/(4*S)
# feat. 중딩
r=2*S/(a+b+c)
# 오일러 정리 (R-2r에 R을 곱하면 외심 내심 사이거리)
d=(abs(R*(R-2*r))).sqrt()
# 카르노 정리 (외심에서 수선 내리면?)
k=R+r
# C++로 하다가 암이 걸리는줄 알았습니다...
print(S)
print(R)
print(r)
print(d)
print(k)
