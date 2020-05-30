@.argc = common global i32 0
@a = common global double 0.0
@b = common global i32 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = add i32 0, 10
%.2 = load i8**, i8*** %args
%.3 = add i32 1 , %.1 
%.4 = getelementptr i8*, i8** %.2, i32 %.3
%.5 = load i8*, i8** %.4
%.6 = call i32 @atoi(i8* %.5)
%.7 = add i32 0, 1
%.8 = add i32 0, 5
%.10 = add i32 %.7, %.8
%.11 = load i8**, i8*** %args
%.12 = add i32 1 , %.10 
%.13 = getelementptr i8*, i8** %.11, i32 %.12
%.14 = load i8*, i8** %.13
%.15 = call i32 @atoi(i8* %.14)
%.16 = add i32 0, 2
%.17 = add i32 0, 2
%.19 = sdiv i32 %.16, %.17
%.20 = load i8**, i8*** %args
%.21 = add i32 1 , %.19 
%.22 = getelementptr i8*, i8** %.20, i32 %.21
%.23 = load i8*, i8** %.22
%.24 = call i32 @atoi(i8* %.23)
%.25 = add i32 0, 1
%.26 = add i32 0, 5
%.28 = mul i32 %.25, %.26
%.29 = load i8**, i8*** %args
%.30 = add i32 1 , %.28 
%.31 = getelementptr i8*, i8** %.29, i32 %.30
%.32 = load i8*, i8** %.31
%.33 = call i32 @atoi(i8* %.32)
store i32 %.33, i32* @b
 %.str.1 = alloca i8, i8 5
%.str.1.ind.0 = getelementptr i8, i8* %.str.1 , i8 0
 store i8    10  , i8* %.str.1.ind.0   
%.str.1.ind.1 = getelementptr i8, i8* %.str.1 , i8 1
 store i8  0  , i8* %.str.1.ind.1   
call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.argv, i32 0, i32 0), i8* %.str.1  )
%.35 = load double, double* @a
%.36 = add i32 0, 56
%.37 = sitofp i32 %.36 to double
%.38 = fadd double %.35, %.37
%.39 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.38)
 %.str.2 = alloca i8, i8 5
%.str.2.ind.0 = getelementptr i8, i8* %.str.2 , i8 0
 store i8    10  , i8* %.str.2.ind.0   
%.str.2.ind.1 = getelementptr i8, i8* %.str.2 , i8 1
 store i8  0  , i8* %.str.2.ind.1   
call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.argv, i32 0, i32 0), i8* %.str.2  )
%.41 = load i32, i32* @b
%.42 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.41)
 %.str.3 = alloca i8, i8 5
%.str.3.ind.0 = getelementptr i8, i8* %.str.3 , i8 0
 store i8    10  , i8* %.str.3.ind.0   
%.str.3.ind.1 = getelementptr i8, i8* %.str.3 , i8 1
 store i8  0  , i8* %.str.3.ind.1   
call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.argv, i32 0, i32 0), i8* %.str.3  )
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
