%string []
% []
i32* %3
i32* %4
str.0 = " "
def @main() {
LAB 1:
	store i32 %3 10;
	%5 = 11 + 4;
	%6 = malloc(%5);
	store i32 %6 11;
	%7 = %6 + 4;
	store i32 %4 %7;
	%77 = 1;
	br lab9;
LAB 9:
	%15 = load i32 %3;
	%13 = %77 <= %15;
	br %13 lab10 lab12;
LAB 10:
	%16 = load i32 %4;
	%18 = %16 + %77;
	store i8 %18 1;
	br lab11;
LAB 11:
	%20 = %77 + 1;
	%77 = %20;
	br lab9;
LAB 12:
	%84 = 0;
	%82 = 0;
	%78 = 2;
	br lab21;
LAB 21:
	%27 = load i32 %3;
	%25 = %78 <= %27;
	br %25 lab22 lab24;
LAB 22:
	br lab28;
LAB 28:
	%31 = load i32 %4;
	%33 = %31 + %78;
	%34 = load i8 %33;
	br %34 lab30 lab85;
LAB 30:
	br lab36;
LAB 36:
	%44 = %78 > 3;
	br %44 lab41 lab86;
LAB 41:
	%46 = load i32 %4;
	%47 = %78 - 2;
	%49 = %46 + %47;
	%50 = load i8 %49;
	br %50 lab40 lab87;
LAB 40:
	%80 = 1;
	br lab43;
LAB 43:
	br %80 lab38 lab88;
LAB 38:
	%54 = %78 - 2;
	%56 = i32@toString(i32 %54);
	%53 = i32@string_strcat(i32 %56,i8 str.0);
	%58 = i32@toString(i32 %78);
	%52 = i32@string_strcat(i32 %53,i32 %58);
	void @println(i32 %52);
	br lab37;
LAB 37:
	%81 = 2;
	br lab59;
LAB 59:
	%63 = %78 * %81;
	%66 = load i32 %3;
	%62 = %63 <= %66;
	br %62 lab60 lab61;
LAB 60:
	%67 = load i32 %4;
	%68 = %78 * %81;
	%71 = %67 + %68;
	store i8 %71 0;
	%73 = %81 + 1;
	%81 = %73;
	br lab59;
LAB 61:
	%83 = %80;
	%79 = %81;
	br lab29;
LAB 29:
	br lab23;
LAB 23:
	%75 = %78 + 1;
	%84 = %83;
	%82 = %79;
	%78 = %75;
	br lab21;
LAB 42:
	%80 = 0;
	br lab43;
LAB 24:
	%76 = 0;
	br lab2;
LAB 2:
	ret i32 %76;
LAB 85:
	%83 = %84;
	%79 = %82;
	br lab29;
LAB 86:
	br lab42;
LAB 87:
	br lab42;
LAB 88:
	br lab37;
}
