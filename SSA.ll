%string []
% []
def @qpow(i32 %3) {
LAB 1:
	%9 = %3 / 2;
	store i32 %3 %9;
	%10 = %3;
	br lab2;
LAB 2:
	ret i32 %10;
}
def @main() {
LAB 4:
	%6 = i32@qpow(i32 10);
	%7 = i32@toString(i32 %6);
	void @println(i8 %7);
	%8 = 0;
	br lab5;
LAB 5:
	ret i32 %8;
}
