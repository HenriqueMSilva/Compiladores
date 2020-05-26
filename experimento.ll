@.argc = common global i32 0
@a = common global i32 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.0 = constant [2 x i8] c"\0A\00"
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = add i32 0, 1
%.2 = add i32 0, 0
%.3 = add i32 %.1, %.2
%.4 = add i32 0, 4
%.5 = sub i32 %.3, %.4
%.6 = add i32 0, 7
%.7 = add i32 %.5, %.6
%.8 = load i8**, i8*** %args
%.9 = add i32 %.7, 1 
%.10 = getelementptr i8*, i8** %.8, i32 %.9
%.11 = load i8*, i8** %.10
%.12 = call i32 @atoi(i8* %.11)
%.13 = add i32 0, 5
%.14 = add i32 %.12, %.13
store i32 %.14, i32* @a
%.15 = load i32, i32* @a
%.16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.15)
%.17 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
%.18 = add i32 0, 1
%.19 = load i8**, i8*** %args
%.20 = add i32 %.18, 1 
%.21 = getelementptr i8*, i8** %.19, i32 %.20
%.22 = load i8*, i8** %.21
%.23 = call i32 @atoi(i8* %.22)
%.24 = call i32 (i8*, ...) @printf(i8* getelementptr  ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.23)
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
