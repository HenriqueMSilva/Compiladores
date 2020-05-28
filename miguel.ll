@.argc = common global i32 0
@a = common global i32 0
@b = common global i32 0
@c = common global i32 0
@d = common global i32 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.0 = constant [2 x i8] c"\0A\00"
@.str.1 = constant [2 x i8] c"\0A\00"
@.str.2 = constant [2 x i8] c"\0A\00"
@.str.3 = constant [24 x i8] c"Teste\09de \0Cstring\5C\22\0D%%%%\00"
@.str.4 = constant [2 x i8] c"\0A\00"
@.str.5 = constant [2 x i8] c"\0A\00"
@.str.6 = constant [2 x i8] c"\0A\00"
@.str.7 = constant [2 x i8] c"\0A\00"
@.str.8 = constant [2 x i8] c"\0A\00"
@.str.9 = constant [2 x i8] c"\0A\00"
@.str.10 = constant [2 x i8] c"\0A\00"
@.str.11 = constant [2 x i8] c"\0A\00"
define void @main.nossa(i8** %.args) {
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
%.15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @.str.3, i32 0, i32 0))
%.16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i32 0, i32 0))
%.17 = load i32, i32* %a
%.18 = add i32 0, 1
%.19 = add i32 %.17, %.18
store i32 %.19, i32* %a
%.20 = add i32 0, 0
%.21 = icmp sgt i32 %.19, %.20
br i1 %.21, label %then9, label %elseaux9
then9:
br label %ifCont9
elseaux9:
%.22 = load i32, i32* %a
%.23 = add i32 0, 3
%.24 = add i32 %.22, %.23
store i32 %.24, i32* %a
%.25 = add i32 0, 0
%.26 = icmp sgt i32 %.24, %.25
br label %else9
else9:
%.27 = add i1 0, %.26
br label %ifCont9
ifCont9:
%.28 = phi i1 [  %.21, %then9 ], [ %.27, %else9 ]
br i1 %.28, label %then10, label %else10
then10:
%.29 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont10
else10:
%.30 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont10
ifCont10:
%.31 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.5, i32 0, i32 0))
%.32 = load i32, i32* %a
%.33 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.32)
%.34 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.6, i32 0, i32 0))
%.35 = load i32, i32* %a
%.36 = add i32 0, 1
%.37 = add i32 %.35, %.36
store i32 %.37, i32* %a
%.38 = add i32 0, 0
%.39 = icmp slt i32 %.37, %.38
br i1 %.39, label %thenaux14, label %else14
thenaux14:
%.40 = load i32, i32* %a
%.41 = add i32 0, 3
%.42 = add i32 %.40, %.41
store i32 %.42, i32* %a
%.43 = add i32 0, 0
%.44 = icmp slt i32 %.42, %.43
br label %then14
then14:
%.45 = add i1 0, %.44
br label %ifCont14
else14:
br label %ifCont14
ifCont14:
%.46 = phi i1 [  %.45, %then14 ], [ %.39, %else14 ]
br i1 %.46, label %then15, label %else15
then15:
%.47 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont15
else15:
%.48 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont15
ifCont15:
%.49 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.7, i32 0, i32 0))
%.50 = load i32, i32* %a
%.51 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.50)
%.52 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.8, i32 0, i32 0))
%.53 = fadd  double 0.000000, 1.2299999999999999e-08
store double %.53, double* %d
%.54 = load double, double* %d
%.55 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.54)
%.56 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.9, i32 0, i32 0))
%.57 = fadd  double 0.000000, 0.0000000000000000e+00
store double %.57, double* %d
%.58 = load double, double* %d
%.59 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.58)
%.60 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0))
%.61 = fadd  double 0.000000, 1.0000000000000000e+01
store double %.61, double* %d
%.62 = load double, double* %d
%.63 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.62)
%.64 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.11, i32 0, i32 0))
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
