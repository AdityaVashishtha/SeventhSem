%Problem 1

a=10
b=2.5*10^23
c=2+3i
d=exp((j*2*pi )/3)

%Problem 2
aVec=[3.14 15 9 26]
bVec =[2.71;8;28;182]
cVec=[-5:0.2:5]
dVec=logspace(0,1,100)
eVec="Hello"

%Problem 3
aMat=ones(9)*2
bMat=diag([1 2 3 4 5 4 3 2 1])
cMat=reshape([1:100],10,10)
dMat=nan(3,4)
eMat=[13 -1 5; -22 10 -87]
fMat=floor(rand(5,3)*4)

%Problem 4
x=1/(1+exp(-(a-15)/6))
y=(sqrt(a)+nthroot(b,21))^pi
z=( log(real((c-d)*(c+d))*sin(a*pi/3))/(c*conj(c)))
xVec=(1/sqrt(2*pi*(2.5)^2))*exp(((cVec).^2)./(2*2.5^2))
yVec=sqrt(transpose(aVec).^2 + bVec.^2)
zVec=log10(dVec.^-1)

%Problem 6
xMat=(aVec*bVec)*(aMat)*(aMat)
yMat=(bVec*aVec)
zMat=det(cMat)*transpose(aMat*bMat)

%Problem 7
cSum=sum(cMat)
eMean=mean(eMat,2)
eMat([1],:)=[1 1 1]
cSub=cMat([2:9],[2:9])

lin=[1:1:20];
for i=lin
    lin(i)=lin(i)*((-1)^(i+1));
endfor
disp(lin);

r=rand(1,5);
disp(r);
r(find(!floor(2*r))) = 0;
disp(r);

%Problem 8
figure()
sample=[0:0.01:2*pi];
plot(sin(sample))
hold on
plot(cos(sample))