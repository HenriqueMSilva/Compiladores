@.argc = common global i32 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%a = alloca i32
%i = alloca i32
%.1 = add i32 0, 1
store i32 %.1, i32* %i
br label %entrada1
entrada1:
%.2 = load i32, i32* %i
%.3 = add i32 0, 10
%.4 = icmp sle i32 %.2, %.3
br i1 %.4, label %thenaux1, label %else1
thenaux1:
%.5 = load i32, i32* %i
%.6 = add i32 0, 1
%.7 = icmp sgt i32 %.5, %.6
br label %then1
then1:
%.8 = add i1 0, %.7
br label %ifCont1
else1:
br label %ifCont1
ifCont1:
%.9 = phi i1 [  %.8, %then1 ], [ %.4, %else1 ]
br i1 %.9, label %whiletrue1, label %saida1
whiletrue1:
%.10 = load i32, i32* %i
%.11 = add i32 0, 1
%.13 = add i32 %.10, %.11
store i32 %.13, i32* %i
%.14 = load i32, i32* %i
%.15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.14)
br label %entrada1
saida1:
ret void
}
define i32 @main(i32 %.argc, i8** %.argv){
%.argc_1 = alloca i32
store i32 %.argc, i32* %.argc_1
%.1 = load i32, i32* %.argc_1
store i32 %.1, i32* @.argc
call void @main.nossa(i8** %.argv)
ret i32 0
}
declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
