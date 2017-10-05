in_x1=1
in_x2=1
x1=[0.8,0.4,0.3]
x2=[0.2,0.9,0.5]
x3=0.3
x4=0.5
x5=0.9
out=0
n=100
alpha = 0.5
outputG = []
yy=[1:n]
for i = 1:n
    h1=in_x1*x1(1) + in_x2*x2(1);
    h1=(1/(1+e^(-h1)));
    h2=in_x1*x1(2) + in_x2*x2(2);
    h2=(1/(1+e^(-h2)));
    h3=in_x1*x1(3) + in_x2*x2(3);
    h3=(1/(1+e^(-h3)));
    finalSigmo = x3*h1 + x4*h2 + x5*h3;
    summation = finalSigmo;
    finalSigmo = (1/(1+e^(-finalSigmo)));
    delta = out - finalSigmo;
    outputG = [outputG delta];
    x3 = x3 + alpha*delta*x3;
    x4 = x4 + alpha*delta*x4;
    x5 = x5 + alpha*delta*x5;
    finalSigmo
    delta
    disp('Iteraton Start')    
    disp(x3)
    disp(x4)
    disp(x5)
    disp('Iteraton End')
endfor
plot(yy,outputG)