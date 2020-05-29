@.argc = common global i32 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
define i32 @method_overload_0(i32 %.ii, double %.dd) {
%ii = alloca i32
store i32 %.ii, i32* %ii
%dd = alloca double
store double %.dd, double* %dd
%.1 = add i32 0, 1
%.2 = add i32 0, 1
%.4 = add i32 %.1, %.2
ret i32 %.4
ret i32 0
}
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%b = alloca double
%.1 = add i32 0, 2
%.2 = add i32 0, 1
%.3 = sitofp i32 %.2 to double
%.4 = call i32 @method_overload_0(i32 %.1, double %.3)
%.5 = sitofp i32 %.4 to double
store double %.5, double* %b
%.6 = load double, double* %b
%.7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.6)
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
