@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
define i1 @method_bool_0() {
%i = alloca i1
%.1 = or i1 0, true
store i1 %.1, i1* %i
%.2 = load i1, i1* %i
%.3 = load i1, i1* %i
ret i1 %.3
ret i1 0
}
define i32 @method_integer_1() {
%i = alloca i32
%.1 = add i32 0, 1
store i32 %.1, i32* %i
%.2 = load i32, i32* %i
%.3 = load i32, i32* %i
ret i32 %.3
ret i32 0
}
define double @method_real_2() {
%i = alloca double
%.1 = add double 0, 1.0
store double %.1, double* %i
%.2 = load double, double* %i
%.3 = load double, double* %i
ret double %.3
ret double 0.0
}
define (null) @main.entry(i32 %.size.,i8** %.args) {
%size. = alloca i32
store i32 %.size., i32* %size.
%args = alloca i8**
store i8** %.args, i8*** %args
ret void
}
declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
