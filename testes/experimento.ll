@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.0 = constant [2 x i8] c"\0A\00"
@.str.1 = constant [10 x i8] c"Is pair: \00"
@.str.2 = constant [3 x i8] c"|\0A\00"
define void @main.entry(i32 %.size.,i8** %.args) {
%size. = alloca i32
store i32 %.size., i32* %size.
%args = alloca i8**
store i8** %.args, i8*** %args
%i = alloca i32
%.1 = add i32 0, 2
store i32 %.1, i32* %i
%.2 = load i32, i32* %i
%.3 = add i32 0, 1
%.4 = add i32 %.2, %.3
store i32 %.4, i32* %i
%.5 = load i32, i32* %i
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr  ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.5)
%.7 = call i32 (i8*, ...) @printf(i8* getelementptr  ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
%.8 = call i32 (i8*, ...) @printf(i8* getelementptr  ([10 x i8], [10 x i8]* @.str.1, i32 0, i32 0))
%.9 = call i32 (i8*, ...) @printf(i8* getelementptr  ([3 x i8], [3 x i8]* @.str.2, i32 0, i32 0))
ret void
}
define i32 @main(i32 %.size,i8** %.args){
call void @main.entry(i32 %.size, i8** %.args)
ret i32 0
}
declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
