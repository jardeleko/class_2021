// método forward e backward

clc
clear 
ch = input("1 para interpolar com Forward e 2 para interpolar com Backward");

if(ch==1) then 
	n = input("Enter the no of values");
	y = zeros(n,n);

	for i = 1:n
		x(i)=input("Insira o elemento x");
		y(i, 1)=input("Insira o elemento y");
	end
	for i=2:n
		for j=1:n-i+1
			y(j,i)=y(j+1, i-1)-y(j,i-1);
		end
	end
	mprintf("X\tY\t");
	for i=1:n-1
		mprintf("%c %dy\t", char(30), i);
	end
	disp("");
	for i=1:n
		mprintf("%d\t", x(i));
		for j=1: n-i+1;
			mprintf("%d\t", y(i, j));
		end
		disp("");
	end 
else 
	n = input("Enter the no of values");
	y = zeros(n, n);

	for i = 1:n
		x(i)=input("Insira o elemento x");
		y(i, 1)=input("Insira o elemento y");
	end
	for i=2:n
		for j=1:n-i+1
			y(j,i)=y(j+1, i-1)-y(j,i-1);
		end
	end
	mprintf("X\tY\t");
	for i=1:n-1
		mprintf("%c %dy\t", char(31), i);
	end
	disp("");
	for i=1:n
		mprintf("%d\t", x(i))
		for j=1:n-i+1
			mprintf("%d\t", y(i, j));
		end
		disp("");
	end
ends