@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
define void @method_a_0(i32 %.input) {
%input = alloca i32
store i32 %.input, i32* %input
%out = alloca i1
define void @main(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
ret void
}
