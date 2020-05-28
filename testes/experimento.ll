@.argc = common global i32 0
@b1 = common global i1 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = or i1 false, true
store i1 %.1, i1* @b1
%.2 = or i1 false, false
%.3 = load i1, i1* @b1
%.4 = alloca i1
br i1 %.3, label %then1, label %else1
then1:
store i1 false, i1* %.4
br label %ifCont1
else1:
store i1 true, i1* %.4
br label %ifCont1
ifCont1:
%.5 = load i1, i1* %.4
%.6 = alloca i1
br i1 %.2, label %then2, label %else2
then2:
store i1 false, i1* %.6
br label %ifCont2
else2:
store i1 true, i1* %.6
br label %ifCont2
ifCont2:
%.7 = load i1, i1* %.6
%.8 = xor i1 %.7, %.5
br i1 %.8, label %then3, label %else3
then3:
%.9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont3
else3:
%.10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont3
ifCont3:
%.11 = load i1, i1* @b1
br i1 %.11, label %thenaux4, label %else4
thenaux4:
%.12 = or i1 false, true
br label %then4
then4:
%.13 = add i1 0, %.12
br label %ifCont4
else4:
br label %ifCont4
ifCont4:
%.14 = phi i1 [  %.13, %then4 ], [ %.11, %else4 ]
br i1 %.14, label %then5, label %elseaux5
then5:
br label %ifCont5
elseaux5:
%.15 = load i1, i1* @b1
br label %else5
else5:
%.16 = add i1 0, %.15
br label %ifCont5
ifCont5:
%.17 = phi i1 [  %.14, %then5 ], [ %.16, %else5 ]
br i1 %.17, label %then6, label %elseaux6
then6:
br label %ifCont6
elseaux6:
%.18 = or i1 false, true
br i1 %.18, label %thenaux6, label %else6
thenaux6:
%.19 = load i1, i1* @b1
%.20 = alloca i1
br i1 %.19, label %then6, label %else6
then6:
store i1 false, i1* %.20
br label %ifCont6
else6:
store i1 true, i1* %.20
br label %ifCont6
ifCont6:
%.21 = load i1, i1* %.20
%.22 = or i1 false, false
%.23 = alloca i1
br i1 %.21, label %then7, label %else7
then7:
store i1 false, i1* %.23
br label %ifCont7
else7:
store i1 true, i1* %.23
br label %ifCont7
ifCont7:
%.24 = load i1, i1* %.23
%.25 = xor i1 %.24, %.22
br label %then8
then8:
%.26 = add i1 0, %.25
br label %ifCont8
else8:
br label %ifCont8
ifCont8:
%.27 = phi i1 [  %.26, %then8 ], [ %.18, %else8 ]
br label %else9
else9:
%.28 = add i1 0, %.27
br label %ifCont9
ifCont9:
%.29 = phi i1 [  %.17, %then9 ], [ %.28, %else9 ]
br i1 %.29, label %then10, label %else10
then10:
%.30 = or i1 false, true
br i1 %.30, label %thenaux11, label %else11
thenaux11:
%.31 = load i1, i1* @b1
br label %then11
then11:
%.32 = add i1 0, %.31
br label %ifCont11
else11:
br label %ifCont11
ifCont11:
%.33 = phi i1 [  %.32, %then11 ], [ %.30, %else11 ]
br i1 %.33, label %then12, label %elseaux12
then12:
br label %ifCont12
elseaux12:
%.34 = or i1 false, true
br label %else12
else12:
%.35 = add i1 0, %.34
br label %ifCont12
ifCont12:
%.36 = phi i1 [  %.33, %then12 ], [ %.35, %else12 ]
br i1 %.36, label %then13, label %elseaux13
then13:
br label %ifCont13
elseaux13:
%.37 = load i1, i1* @b1
br i1 %.37, label %thenaux13, label %else13
thenaux13:
%.38 = or i1 false, false
%.39 = load i1, i1* @b1
%.40 = alloca i1
br i1 %.39, label %then13, label %else13
then13:
store i1 false, i1* %.40
br label %ifCont13
else13:
store i1 true, i1* %.40
br label %ifCont13
ifCont13:
%.41 = load i1, i1* %.40
%.42 = alloca i1
br i1 %.38, label %then14, label %else14
then14:
store i1 false, i1* %.42
br label %ifCont14
else14:
store i1 true, i1* %.42
br label %ifCont14
ifCont14:
%.43 = load i1, i1* %.42
%.44 = xor i1 %.43, %.41
br label %then15
then15:
%.45 = add i1 0, %.44
br label %ifCont15
else15:
br label %ifCont15
ifCont15:
%.46 = phi i1 [  %.45, %then15 ], [ %.37, %else15 ]
br label %else16
else16:
%.47 = add i1 0, %.46
br label %ifCont16
ifCont16:
%.48 = phi i1 [  %.36, %then16 ], [ %.47, %else16 ]
br i1 %.48, label %then17, label %else17
then17:
br label %ifCont17
else17:
br label %ifCont17
ifCont17:
br label %ifCont10
else10:
br label %ifCont10
ifCont10:
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
