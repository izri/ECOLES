


clc;
clear all;


n=5;
lambda=0.02;

T=zeros(1,n);
T(1)=-log(rand)/lambda;
for i = 2:n
    T(i)=T(i-1)-log(rand)/lambda
end 
%-log( -rand(n,m) + 1 ) / b;
