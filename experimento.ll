@.argc = common global i32 0
@a = common global i32 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.0 = constant [2 x i8] c"\0A\00"
@.str.1 = constant [4 x i8] c"we\0A\00"
@.str.2 = constant [11 x i8] c"wDoubleEe\0A\00"
@.str.3 = constant [2 x i8] c"\0A\00"
@.str.4 = constant [6 x i8] c"Inte\0A\00"
@.str.5 = constant [2 x i8] c"\0A\00"
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%dd = alloca double
%.1 = fadd  double 0.000000, 4.0000000000000000e+00
store double %.1, double* %dd
%.2 = load double, double* %dd
call void @method_ddble_2(double %.2)
%.3 = add i32 0, 6
%.4 = call i32 @method_ddble_3(i32 %.3)
store i32 %.4, i32* @a
%.5 = add i32 0, 1
%.6 = load i8**, i8*** %args
%.7 = add i32 1 , %.5 
%.8 = getelementptr i8*, i8** %.6, i32 %.7
%.9 = load i8*, i8** %.8
%.10 = call i32 @atoi(i8* %.9)
%.11 = call i32 @method_ddble_3(i32 %.10)
%.12 = load i32, i32* @.argc
%.13 = sub i32 %.12, 1 
%.14 = call i32 @method_ddble_3(i32 %.13)
%.15 = load i32, i32* @a
%.16 = add i32 0, 149
%.18 = add i32 %.15, %.16
%.19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.18)
%.20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
ret void
}
define i32 @method_ddble_1() {
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0))
%.2 = add i32 0, 1
ret i32 %.2
ret i32 0
}
define void @method_ddble_2(double %.e) {
%e = alloca double
store double %.e, double* %e
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.2, i32 0, i32 0))
%.2 = load double, double* %e
%.3 = add i32 0, 5
%.4 = sitofp i32 %.3 to double
%.5 = fsub double %.2, %.4
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.5)
%.7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.3, i32 0, i32 0))
ret void
}
define i32 @method_ddble_3(i32 %.e) {
%e = alloca i32
store i32 %.e, i32* %e
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.4, i32 0, i32 0))
%.2 = load i32, i32* %e
%.3 = add i32 0, 4
%.5 = add i32 %.2, %.3
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.5)
%.7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.5, i32 0, i32 0))
%.8 = load i32, i32* %e
%.9 = add i32 0, 5
%.11 = add i32 %.8, %.9
ret i32 %.11
ret i32 0
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
