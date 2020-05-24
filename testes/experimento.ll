@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.0 = constant [10 x i8] c"Is pair: \00"
@.str.1 = constant [3 x i8] c"|\0A\00"
define i32 @main.entry(i32 %.size.,i8** %.args) {
%size. = alloca i32
store i32 %.size., i32* %size.
%args = alloca i8**
store i8** %.args, i8*** %args
%k = alloca i32
%.1 = add i32 0, 0
store i32 %.1, i32* %k
%i = alloca i32
%g = alloca i32
%.2 = add i32 0, 0
store i32 %.2, i32* %i
%.3 = add i32 0, 0
store i32 %.3, i32* %g
%is_pair = alloca i32
%.4 = add i32 0, 0
store i32 %.4, i32* %is_pair
%input = alloca i32
%.5 = add i32 0, 40
store i32 %.5, i32* %input
br label %while1
while1:
%.6 = load i32, i32* %k
%.7 = add i32 0, 1
%.8 = icmp eq i32 %.6, %.7
br i1 %.8, label %then1, label %else1
then1:
%.9 = load i32, i32* %input
%.10 = add i32 0, 2
%.11 = sub i32 %.9, %.10
store i32 %.11, i32* %input
%.12 = add i32 0, 0
store i32 %.12, i32* %i
%.13 = add i32 0, 0
store i32 %.13, i32* %g
br label %while2
while2:
br label %while3
while3:
%.14 = load i32, i32* %input
%.15 = add i32 0, 2
%.16 = add i32 %.14, %.15
store i32 %.16, i32* %input
%.17 = load i32, i32* %g
%.18 = add i32 0, 2
%.19 = urem i32 %.17, %.18
%.20 = add i32 0, 0
%.21 = icmp eq i32 %.19, %.20
br i1 %.21, label %then2, label %else2
then2:
%.22 = load i32, i32* %is_pair
%.23 = add i32 0, 1
%.24 = add i32 %.22, %.23
store i32 %.24, i32* %is_pair
br label %ifCont2
else2:
br label %ifCont2
ifCont2:
%.25 = load i32, i32* %g
%.26 = add i32 0, 1
%.27 = add i32 %.25, %.26
store i32 %.27, i32* %g
%.28 = load i32, i32* %g
%.29 = add i32 0, 50
%.30 = icmp slt i32 %.28, %.29
br i1 %.30, label %while3, label %whileCont3
whileCont3:
%.31 = add i32 0, 0
store i32 %.31, i32* %g
%.32 = load i32, i32* %i
%.33 = add i32 0, 1
%.34 = add i32 %.32, %.33
store i32 %.34, i32* %i
%.35 = load i32, i32* %i
%.36 = add i32 0, 100
%.37 = icmp slt i32 %.35, %.36
br i1 %.37, label %while2, label %whileCont2
whileCont2:
br label %ifCont1
else1:
%.38 = load i32, i32* %k
%.39 = add i32 0, 2
%.40 = icmp eq i32 %.38, %.39
br i1 %.40, label %then3, label %else3
then3:
%.41 = load i32, i32* %input
%.42 = add i32 0, 3
%.43 = mul i32 %.41, %.42
store i32 %.43, i32* %input
br label %ifCont3
else3:
br label %ifCont3
ifCont3:
br label %ifCont1
ifCont1:
%.44 = load i32, i32* %k
%.45 = add i32 0, 1
%.46 = add i32 %.44, %.45
store i32 %.46, i32* %k
%.47 = load i32, i32* %k
%.48 = add i32 0, 5
%.49 = icmp slt i32 %.47, %.48
br i1 %.49, label %while1, label %whileCont1
whileCont1:
%.50 = call i32 (i8*, ...) @printf(i8* getelementptr  ([10 x i8], [10 x i8]* @.str.0, i32 0, i32 0))
%.51 = load i32, i32* %is_pair
%.52 = call i32 (i8*, ...) @printf(i8* getelementptr  ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.51)
%.53 = call i32 (i8*, ...) @printf(i8* getelementptr  ([3 x i8], [3 x i8]* @.str.1, i32 0, i32 0))
ret i32 0
}
define i32 @main(i32 %.size,i8** %.args){
call i32 @main.entry(i32 %.size, i8** %.args)
ret i32 0
}
declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
