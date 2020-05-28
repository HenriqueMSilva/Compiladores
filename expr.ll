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
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%dd = alloca double
%.1 = add i32 0, 1
%.2 = load i8**, i8*** %args
%.3 = add i32 1 , %.1 
%.4 = getelementptr i8*, i8** %.2, i32 %.3
%.5 = load i8*, i8** %.4
%.6 = call i32 @atoi(i8* %.5)
store i32 %.6, i32* @a
%.7 = call double @method_ddble_1()
%.8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
ret void
}
define double @method_ddble_1() {
%e = alloca double
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0))
%.2 = fadd  double 0.000000, 1.0000000000000000e+00
%.3 = load i32, i32* @a
%.4 = sitofp  i32 %.3 to double
%.5 = fadd double %.2, %.4
store double %.5, double* %e
%.6 = load double, double* %e
ret double %.6
ret double 0.0
}
define void @method_ddble_2(double %.e) {
%e = alloca double
store double %.e, double* %e
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.2, i32 0, i32 0))
%.2 = load double, double* %e
%.3 = add i32 0, 5
%.4 = sitofp  i32 %.3 to double
%.5 = fsub double %.2, %.4
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.5)
%.7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.3, i32 0, i32 0))
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
