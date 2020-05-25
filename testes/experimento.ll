@..length = common global i32 0
@a = common global i32 0
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.0 = constant [2 x i8] c"\0A\00"
@.str.1 = constant [2 x i8] c"\0A\00"
@.str.2 = constant [2 x i8] c"\0A\00"
@.str.3 = constant [28 x i8] c"Teste\tde \fstring\\\\r%%%%\00"
@.str.4 = constant [2 x i8] c"\0A\00"
define void @main.StringArray.(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = add i32 0, 2
store i32 %.1, i32* @a
%.2 = load i32, i32* @a
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.2)
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
%i = alloca i32
%a = alloca i32
%i1 = alloca i32
%i2 = alloca i32
%i3 = alloca i32
%d = alloca double
%.5 = add i32 0, 0
%.6 = add i32 0, 3
%.7 = add i32 %.5, %.6
store i32 %.7, i32* %a
%.8 = sitofp i32 %.7 to double
store double %.8, double* %d
%.9 = load i32, i32* %a
%.10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.9)
%.11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.1, i32 0, i32 0))
%.12 = load double, double* %d
%.13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.12)
%.14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i32 0, i32 0))
%.15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @.str.3, i32 0, i32 0))
%.16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i32 0, i32 0))
ret void
}
define i32 @main(i32 %...args, i8** %.args){
%..args = alloca i32
store i32 %...args, i32* %..args
%.1 = load i32, i32* %..args
store i32 %.1, i32* @..length
call void @main.StringArray.(i8** %.args)
ret i32 0
}
declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
