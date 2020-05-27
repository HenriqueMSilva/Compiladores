@.argc = common global i32 0
@i3 = common global i32 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%d = alloca double
%.1 = add i32 0, 0
%.2 = load i8**, i8*** %args
%.3 = add i32 1 , %.1 
%.4 = getelementptr i8*, i8** %.2, i32 %.3
%.5 = load i8*, i8** %.4
%.6 = call i32 @atoi(i8* %.5)
%.7 = add i32 0, 1
%.9 = add i32 %.6, %.7
%.10 = sitofp i32 %.9 to double
store double %.10, double* %d
%a = alloca i32
%i1 = alloca i32
%i3 = alloca i32
%.11 = add i32 0, 111
store i32 %.11, i32* %i3
%.12 = load i32, i32* %i3
%.13 = add i32 0, 1
%.15 = add i32 %.12, %.13
store i32 %.15, i32* %i1
store i32 %.15, i32* %a
%.16 = sitofp i32 %.15 to double
store double %.16, double* %d
%.17 = load double, double* %d
%.18 = add i32 0, 111
%.19 = add i32 0, 1
%.21 = mul i32 %.18, %.19
%.22 = add i32 0, 1
%.24 = add i32 %.21, %.22
%.25 = add i32 0, 0
%.26 = load i8**, i8*** %args
%.27 = add i32 1 , %.25 
%.28 = getelementptr i8*, i8** %.26, i32 %.27
%.29 = load i8*, i8** %.28
%.30 = call i32 @atoi(i8* %.29)
%.32 = add i32 %.24, %.30
%.33 = sitofp i32 %.32 to double
%.34 = fcmp oge double %.17, %.33
br i1 %.34, label %then1, label %else1
then1:
%.35 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont1
else1:
%.36 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont1
ifCont1:
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
