@.argc = common global i32 0
@overload = common global i32 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.minus = constant [2 x i8] c"-\00"
@.str.plus = constant [2 x i8] c"+\00"
@.str.0 = constant [20 x i8] c"I have two doubles\0A\00"
@.str.1 = constant [19 x i8] c"I have one double\0A\00"
@.str.2 = constant [16 x i8] c"I have one int\0A\00"
@.str.3 = constant [19 x i8] c"I'm the fake main\0A\00"
@.str.4 = constant [2 x i8] c"\0A\00"
@.str.5 = constant [5 x i8] c"\0Aa:\0A\00"
@.str.6 = constant [11 x i8] c"Before if\0A\00"
@.str.7 = constant [11 x i8] c"After ifs\0A\00"
@.str.8 = constant [11 x i8] c"After ifs\0A\00"
@.str.9 = constant [2 x i8] c"\0A\00"
@.str.10 = constant [2 x i8] c"\0A\00"
@.str.11 = constant [14 x i8] c"Before while\0A\00"
define i1 @method_overload_0(i1 %.n) {
%n = alloca i1
store i1 %.n, i1* %n
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @.str.0, i32 0, i32 0))
%.2 = or i1 false, false
ret i1 %.2
ret i1 0
}
define double @method_overload_1(double %.n) {
%n = alloca double
store double %.n, double* %n
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0))
%.2 = fadd  double 0.000000, 2.2000000000000002e+00
%.3 = add i32 0, 2
%.4 = sitofp  i32 %.3 to double
%.5 = fmul double %.2, %.4
%.6 = add i32 0, 2
%.7 = call i32 @method_main_4(i32 %.6)
%.8 = add i32 0, 5
%.10 = sdiv i32 %.7, %.8
%.11 = add i32 0, 6
%.13 = mul i32 %.10, %.11
%.14 = sitofp  i32 %.13 to double
%.15 = fadd double %.5, %.14
%.16 = add i32 0, 2
%.17 = add i32 0, 3
%.19 = mul i32 %.16, %.17
%.20 = sitofp  i32 %.19 to double
%.21 = fadd double %.15, %.20
%.22 = add i32 0, 3
%.23 = add i32 0, 4
%.25 = mul i32 %.22, %.23
%.26 = sitofp  i32 %.25 to double
%.27 = fadd double %.21, %.26
%.28 = add i32 0, 2
%.29 = add i32 0, 8
%.31 = mul i32 %.28, %.29
%.32 = sitofp  i32 %.31 to double
%.33 = fadd double %.27, %.32
%.34 = add i32 0, 5
%.35 = add i32 0, 9
%.37 = mul i32 %.34, %.35
%.38 = sitofp  i32 %.37 to double
%.39 = fadd double %.33, %.38
%.40 = add i32 0, 2
%.41 = add i32 0, 2
%.42 = call i32 @method_overload_3(i32 %.40, i32 %.41)
%.43 = sitofp  i32 %.42 to double
%.44 = fadd double %.39, %.43
ret double %.44
ret double 0.0
}
define i32 @method_overload_2(double %.b, double %.b1) {
%b = alloca double
store double %.b, double* %b
%b1 = alloca double
store double %.b1, double* %b1
%.1 = add i32 0, 2
%.2 = load i32, i32* @overload
%.4 = add i32 %.1, %.2
store i32 %.4, i32* @overload
%overload = alloca double
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.2, i32 0, i32 0))
%.6 = add i32 0, 5
ret i32 %.6
ret i32 0
}
define i32 @method_overload_3(i32 %.b, i32 %.b1) {
%b = alloca i32
store i32 %.b, i32* %b
%b1 = alloca i32
store i32 %.b1, i32* %b1
%.1 = add i32 0, 5
ret i32 %.1
ret i32 0
}
define i32 @method_main_4(i32 %.n) {
%n = alloca i32
store i32 %.n, i32* %n
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.3, i32 0, i32 0))
%.2 = add i32 0, 5
ret i32 %.2
ret i32 0
}
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = load i32, i32* @.argc
%.2 = sub i32 %.1, 1 
%.3 = add i32 0, 0
%.4 = icmp sgt i32 %.2, %.3
br i1 %.4, label %then5, label %else5
then5:
%.5 = add i32 0, 0
%.6 = load i8**, i8*** %args
%.7 = add i32 1 , %.5 
%.8 = getelementptr i8*, i8** %.6, i32 %.7
%.9 = load i8*, i8** %.8
%.10 = call i32 @atoi(i8* %.9)
%.11 = sitofp i32 %.10 to double
%.12 = call double @method_overload_1(double %.11)
br label %ifCont5
else5:
%.13 = add i32 0, 5
%.14 = sitofp i32 %.13 to double
%.15 = call double @method_overload_1(double %.14)
br label %ifCont5
ifCont5:
%.16 = or i1 false, false
%.17 = alloca i1
br i1 %.16, label %then6, label %else6
then6:
store i1 false, i1* %.17
br label %ifCont6
else6:
store i1 true, i1* %.17
br label %ifCont6
ifCont6:
%.18 = load i1, i1* %.17
br i1 %.18, label %then7, label %else7
then7:
%.19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont7
else7:
%.20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont7
ifCont7:
%.21 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i32 0, i32 0))
%a = alloca i32
%.22 = add i32 0, 2222222
store i32 %.22, i32* %a
%d = alloca double
%.23 = fadd  double 0.000000, 2.3232332000000000e+08
store double %.23, double* %d
%b = alloca i32
%.24 = add i32 0, 3
store i32 %.24, i32* %b
%.25 = load i32, i32* %a
%.26 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.25)
%b1 = alloca i1
%.27 = or i1 false, true
store i1 %.27, i1* %b1
%.28 = load i32, i32* %a
%.29 = load i32, i32* %a
%.31 = add i32 %.28, %.29
%.32 = load i32, i32* %a
%.34 = add i32 %.31, %.32
%.35 = add i32 0, 8
%.36 = add i32 0, 2
%.38 = srem i32 %.35, %.36
%.40 = add i32 %.34, %.38
%.41 = load double, double* %d
%.42 = add i32 0, 3
%.43 = sitofp  i32 %.42 to double
%.44 = fdiv double %.41, %.43
%.45 = sitofp  i32 %.40 to double
%.46 = fadd double %.45, %.44
%.47 = load i32, i32* %a
%.48 = load double, double* %d
%.49 = sitofp  i32 %.47 to double
%.50 = fmul double %.49, %.48
%.52 = fadd double %.46, %.50
%.53 = load double, double* %d
%.55 = fadd double %.52, %.53
%.56 = load i32, i32* %a
%.57 = sitofp  i32 %.56 to double
%.58 = fsub double %.55, %.57
%.59 = load i32, i32* %a
%.60 = load i32, i32* %b
%.62 = mul i32 %.59, %.60
%.63 = load double, double* %d
%.64 = fmul double 1.0, %.63
%.65 = sitofp  i32 %.62 to double
%.66 = fdiv double %.65, %.64
%.67 = load i32, i32* %a
%.68 = load i32, i32* %b
%.70 = mul i32 %.67, %.68
%.71 = load double, double* %d
%.72 = fmul double 1.0, %.71
%.73 = sitofp  i32 %.70 to double
%.74 = fdiv double %.73, %.72
%.76 = fmul double %.66, %.74
%.78 = fadd double %.58, %.76
%.79 = fadd  double 0.000000, 2.2000000000000002e+00
%.80 = call double @method_overload_1(double %.79)
%.82 = fadd double %.78, %.80
%.83 = add i32 0, 1
%.84 = add i32 0, 1
%.85 = call i32 @method_overload_3(i32 %.83, i32 %.84)
%.86 = sitofp i32 %.85 to double
store double %.86, double* %d
%.88 = fadd double %.82, %.86
%.89 = add i32 0, 5
%.90 = call i32 @method_main_4(i32 %.89)
%.91 = sitofp  i32 %.90 to double
%.92 = fadd double %.88, %.91
%.93 = load i32, i32* @.argc
%.94 = sub i32 %.93, 1 
%.95 = add i32 0, 1
%.97 = sub i32 %.94, %.95
%.98 = load i8**, i8*** %args
%.99 = add i32 1 , %.97 
%.100 = getelementptr i8*, i8** %.98, i32 %.99
%.101 = load i8*, i8** %.100
%.102 = call i32 @atoi(i8* %.101)
%.103 = sitofp  i32 %.102 to double
%.104 = fadd double %.92, %.103
%.105 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.104)
%.106 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.5, i32 0, i32 0))
%.107 = load i32, i32* %a
%.108 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.107)
%.109 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.6, i32 0, i32 0))
%.110 = load i32, i32* %a
%.111 = add i32 0, 2
%.112 = add i32 0, 2
%.114 = mul i32 %.111, %.112
%.115 = add i32 0, 3
%.116 = add i32 0, 5
%.118 = sdiv i32 %.115, %.116
%.120 = add i32 %.114, %.118
%.121 = add i32 0, 5
%.122 = call i32 @method_main_4(i32 %.121)
%.124 = add i32 %.120, %.122
%.125 = icmp sge i32 %.110, %.124
br i1 %.125, label %then14, label %else14
then14:
%.126 = load i32, i32* %a
%.127 = add i32 0, 2
%.128 = icmp sle i32 %.126, %.127
br i1 %.128, label %then15, label %else15
then15:
%.129 = add i32 0, 2
%.130 = load i32, i32* %a
%.131 = icmp sge i32 %.129, %.130
br i1 %.131, label %then16, label %else16
then16:
%.132 = add i32 0, 2
%.133 = load i32, i32* %a
%.134 = icmp sle i32 %.132, %.133
br i1 %.134, label %then17, label %else17
then17:
%.135 = load i32, i32* %a
%.136 = add i32 0, 2
%.137 = icmp eq i32 %.135, %.136
br i1 %.137, label %then18, label %else18
then18:
%.138 = add i32 0, 2
%.139 = load i32, i32* %a
%.140 = icmp eq i32 %.138, %.139
br i1 %.140, label %then19, label %else19
then19:
%.141 = load i32, i32* %a
%.142 = add i32 0, 2
%.143 = icmp sgt i32 %.141, %.142
br i1 %.143, label %then20, label %else20
then20:
%.144 = load i32, i32* %a
%.145 = add i32 0, 2
%.146 = icmp slt i32 %.144, %.145
br i1 %.146, label %then21, label %else21
then21:
%.147 = add i32 0, 2
%.148 = load i32, i32* %a
%.149 = icmp sgt i32 %.147, %.148
br i1 %.149, label %then22, label %else22
then22:
%.150 = add i32 0, 2
%.151 = load i32, i32* %a
%.152 = icmp slt i32 %.150, %.151
br i1 %.152, label %then23, label %else23
then23:
%.153 = load i32, i32* %a
%.154 = add i32 0, 2
%.155 = icmp ne i32 %.153, %.154
br i1 %.155, label %then24, label %else24
then24:
%.156 = add i32 0, 2
%.157 = load i32, i32* %a
%.158 = icmp ne i32 %.156, %.157
br i1 %.158, label %then25, label %else25
then25:
br label %ifCont25
else25:
br label %ifCont25
ifCont25:
br label %ifCont24
else24:
br label %ifCont24
ifCont24:
br label %ifCont23
else23:
br label %ifCont23
ifCont23:
br label %ifCont22
else22:
br label %ifCont22
ifCont22:
br label %ifCont21
else21:
br label %ifCont21
ifCont21:
br label %ifCont20
else20:
br label %ifCont20
ifCont20:
br label %ifCont19
else19:
br label %ifCont19
ifCont19:
br label %ifCont18
else18:
br label %ifCont18
ifCont18:
br label %ifCont17
else17:
br label %ifCont17
ifCont17:
br label %ifCont16
else16:
br label %ifCont16
ifCont16:
br label %ifCont15
else15:
br label %ifCont15
ifCont15:
br label %ifCont14
else14:
br label %ifCont14
ifCont14:
%.159 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.7, i32 0, i32 0))
%.160 = load double, double* %d
%.161 = add i32 0, 2
%.162 = sitofp i32 %.161 to double
%.163 = fcmp oge double %.160, %.162
br i1 %.163, label %then27, label %else27
then27:
%.164 = load double, double* %d
%.165 = add i32 0, 2
%.166 = sitofp i32 %.165 to double
%.167 = fcmp ole double %.164, %.166
br i1 %.167, label %then28, label %else28
then28:
%.168 = add i32 0, 2
%.169 = load double, double* %d
%.170 = sitofp i32 %.168 to double
%.171 = fcmp oge double %.170, %.169
br i1 %.171, label %then29, label %else29
then29:
%.172 = add i32 0, 2
%.173 = load double, double* %d
%.174 = sitofp i32 %.172 to double
%.175 = fcmp ole double %.174, %.173
br i1 %.175, label %then30, label %else30
then30:
%.176 = load double, double* %d
%.177 = add i32 0, 2
%.178 = sitofp i32 %.177 to double
%.179 = fcmp oeq double %.176, %.178
br i1 %.179, label %then31, label %else31
then31:
%.180 = add i32 0, 2
%.181 = load double, double* %d
%.182 = sitofp i32 %.180 to double
%.183 = fcmp oeq double %.182, %.181
br i1 %.183, label %then32, label %else32
then32:
%.184 = load double, double* %d
%.185 = add i32 0, 2
%.186 = sitofp i32 %.185 to double
%.187 = fcmp ogt double %.184, %.186
br i1 %.187, label %then33, label %else33
then33:
%.188 = load double, double* %d
%.189 = add i32 0, 2
%.190 = sitofp i32 %.189 to double
%.191 = fcmp olt double %.188, %.190
br i1 %.191, label %then34, label %else34
then34:
%.192 = add i32 0, 2
%.193 = load double, double* %d
%.194 = sitofp i32 %.192 to double
%.195 = fcmp ogt double %.194, %.193
br i1 %.195, label %then35, label %else35
then35:
%.196 = add i32 0, 2
%.197 = load double, double* %d
%.198 = sitofp i32 %.196 to double
%.199 = fcmp olt double %.198, %.197
br i1 %.199, label %then36, label %else36
then36:
%.200 = load double, double* %d
%.201 = add i32 0, 2
%.202 = sitofp i32 %.201 to double
%.203 = fcmp one double %.200, %.202
br i1 %.203, label %then37, label %else37
then37:
%.204 = add i32 0, 2
%.205 = load double, double* %d
%.206 = sitofp i32 %.204 to double
%.207 = fcmp one double %.206, %.205
br i1 %.207, label %then38, label %else38
then38:
br label %ifCont38
else38:
br label %ifCont38
ifCont38:
br label %ifCont37
else37:
br label %ifCont37
ifCont37:
br label %ifCont36
else36:
br label %ifCont36
ifCont36:
br label %ifCont35
else35:
br label %ifCont35
ifCont35:
br label %ifCont34
else34:
br label %ifCont34
ifCont34:
br label %ifCont33
else33:
br label %ifCont33
ifCont33:
br label %ifCont32
else32:
br label %ifCont32
ifCont32:
br label %ifCont31
else31:
br label %ifCont31
ifCont31:
br label %ifCont30
else30:
br label %ifCont30
ifCont30:
br label %ifCont29
else29:
br label %ifCont29
ifCont29:
br label %ifCont28
else28:
br label %ifCont28
ifCont28:
br label %ifCont27
else27:
br label %ifCont27
ifCont27:
%.208 = load double, double* %d
%.209 = fadd  double 0.000000, 2.2000000000000002e+00
%.210 = fcmp oge double %.208, %.209
br i1 %.210, label %then39, label %else39
then39:
%.211 = load double, double* %d
%.212 = fadd  double 0.000000, 2.2000000000000002e+00
%.213 = fcmp ole double %.211, %.212
br i1 %.213, label %then40, label %else40
then40:
%.214 = fadd  double 0.000000, 2.2000000000000002e+00
%.215 = load double, double* %d
%.216 = fcmp oge double %.214, %.215
br i1 %.216, label %then41, label %else41
then41:
%.217 = fadd  double 0.000000, 2.2000000000000002e+00
%.218 = load double, double* %d
%.219 = fcmp ole double %.217, %.218
br i1 %.219, label %then42, label %else42
then42:
%.220 = load double, double* %d
%.221 = fadd  double 0.000000, 2.2000000000000002e+00
%.222 = fcmp oeq double %.220, %.221
br i1 %.222, label %then43, label %else43
then43:
%.223 = fadd  double 0.000000, 2.2000000000000002e+00
%.224 = load double, double* %d
%.225 = fcmp oeq double %.223, %.224
br i1 %.225, label %then44, label %else44
then44:
%.226 = load double, double* %d
%.227 = fadd  double 0.000000, 2.2000000000000002e+00
%.228 = fcmp ogt double %.226, %.227
br i1 %.228, label %then45, label %else45
then45:
%.229 = load double, double* %d
%.230 = fadd  double 0.000000, 2.2000000000000002e+00
%.231 = fcmp olt double %.229, %.230
br i1 %.231, label %then46, label %else46
then46:
%.232 = fadd  double 0.000000, 2.2000000000000002e+00
%.233 = load double, double* %d
%.234 = fcmp ogt double %.232, %.233
br i1 %.234, label %then47, label %else47
then47:
%.235 = fadd  double 0.000000, 2.2000000000000002e+00
%.236 = load double, double* %d
%.237 = fcmp olt double %.235, %.236
br i1 %.237, label %then48, label %else48
then48:
%.238 = load double, double* %d
%.239 = fadd  double 0.000000, 2.2000000000000002e+00
%.240 = fcmp one double %.238, %.239
br i1 %.240, label %then49, label %else49
then49:
%.241 = fadd  double 0.000000, 2.2000000000000002e+00
%.242 = load double, double* %d
%.243 = fcmp one double %.241, %.242
br i1 %.243, label %then50, label %else50
then50:
br label %ifCont50
else50:
br label %ifCont50
ifCont50:
br label %ifCont49
else49:
br label %ifCont49
ifCont49:
br label %ifCont48
else48:
br label %ifCont48
ifCont48:
br label %ifCont47
else47:
br label %ifCont47
ifCont47:
br label %ifCont46
else46:
br label %ifCont46
ifCont46:
br label %ifCont45
else45:
br label %ifCont45
ifCont45:
br label %ifCont44
else44:
br label %ifCont44
ifCont44:
br label %ifCont43
else43:
br label %ifCont43
ifCont43:
br label %ifCont42
else42:
br label %ifCont42
ifCont42:
br label %ifCont41
else41:
br label %ifCont41
ifCont41:
br label %ifCont40
else40:
br label %ifCont40
ifCont40:
br label %ifCont39
else39:
br label %ifCont39
ifCont39:
%.244 = load i1, i1* %b1
%.245 = or i1 false, true
%.246 = zext i1 %.244 to i32
%.247 = zext i1 %.245 to i32
%.248 = icmp eq i32 %.246, %.247
br i1 %.248, label %thenaux51, label %else51
thenaux51:
%.249 = load double, double* %d
%.250 = fadd  double 0.000000, 2.2000000000000002e+00
%.251 = fcmp oge double %.249, %.250
br label %then51
then51:
%.252 = add i1 0, %.251
br label %ifCont51
else51:
br label %ifCont51
ifCont51:
%.253 = phi i1 [  %.252, %then51 ], [ %.248, %else51 ]
br i1 %.253, label %thenaux52, label %else52
thenaux52:
%.254 = add i32 0, 2
%.255 = load double, double* %d
%.256 = sitofp i32 %.254 to double
%.257 = fcmp oge double %.256, %.255
br label %then52
then52:
%.258 = add i1 0, %.257
br label %ifCont52
else52:
br label %ifCont52
ifCont52:
%.259 = phi i1 [  %.258, %then52 ], [ %.253, %else52 ]
br i1 %.259, label %thenaux53, label %else53
thenaux53:
%.260 = fadd  double 0.000000, 2.2000000000000002e+00
%.261 = load double, double* %d
%.262 = fcmp ole double %.260, %.261
br label %then53
then53:
%.263 = add i1 0, %.262
br label %ifCont53
else53:
br label %ifCont53
ifCont53:
%.264 = phi i1 [  %.263, %then53 ], [ %.259, %else53 ]
br i1 %.264, label %then54, label %elseaux54
then54:
br label %ifCont54
elseaux54:
%.265 = fadd  double 0.000000, 2.2000000000000002e+00
%.266 = load double, double* %d
%.267 = fadd  double 0.000000, 2.2999999999999998e+00
%.268 = add i32 0, 2
store i32 %.268, i32* %a
%.269 = sitofp  i32 %.268 to double
%.270 = fadd double %.267, %.269
%.271 = add i32 0, 2
%.272 = sitofp i32 %.271 to double
store double %.272, double* %d
%.274 = fadd double %.270, %.272
store double %.274, double* %d
%.276 = fadd double %.266, %.274
%.277 = fcmp oeq double %.265, %.276
br label %else54
else54:
%.278 = add i1 0, %.277
br label %ifCont54
ifCont54:
%.279 = phi i1 [  %.264, %then54 ], [ %.278, %else54 ]
br i1 %.279, label %then55, label %else55
then55:
%.280 = or i1 false, true
%.281 = load i1, i1* %b1
%.282 = zext i1 %.280 to i32
%.283 = zext i1 %.281 to i32
%.284 = icmp eq i32 %.282, %.283
br i1 %.284, label %then56, label %else56
then56:
%.285 = load i1, i1* %b1
%.286 = or i1 false, true
%.287 = zext i1 %.285 to i32
%.288 = zext i1 %.286 to i32
%.289 = icmp ne i32 %.287, %.288
br i1 %.289, label %then57, label %else57
then57:
%.290 = or i1 false, true
%.291 = load i1, i1* %b1
%.292 = zext i1 %.290 to i32
%.293 = zext i1 %.291 to i32
%.294 = icmp ne i32 %.292, %.293
br i1 %.294, label %then58, label %else58
then58:
br label %ifCont58
else58:
br label %ifCont58
ifCont58:
br label %ifCont57
else57:
br label %ifCont57
ifCont57:
br label %ifCont56
else56:
br label %ifCont56
ifCont56:
br label %ifCont55
else55:
br label %ifCont55
ifCont55:
%.295 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.8, i32 0, i32 0))
%.296 = load i32, i32* %a
%.297 = load double, double* %d
%.298 = fmul double -1.0, %.297
%.299 = sitofp  i32 %.296 to double
%.300 = fmul double %.299, %.298
%.301 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.300)
%.302 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.9, i32 0, i32 0))
%.303 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0))
%d1 = alloca double
%.304 = load i32, i32* @.argc
%.305 = sub i32 %.304, 1 
%.306 = fadd  double 0.000000, 1.1000000000000001e+00
%.307 = sitofp  i32 %.305 to double
%.308 = fadd double %.307, %.306
%.309 = add i32 0, 3
%.310 = sitofp i32 %.309 to double
%.311 = call double @method_overload_1(double %.310)
%.313 = fadd double %.308, %.310
%.314 = add i32 0, 3
%.315 = add i32 0, 3
%.317 = mul i32 %.314, %.315
%.318 = sitofp  i32 %.317 to double
%.319 = fadd double %.313, %.318
%.320 = add i32 0, 2
%.321 = sitofp  i32 %.320 to double
%.322 = fadd double %.319, %.321
%.323 = add i32 0, 2
%.324 = sitofp  i32 %.323 to double
%.325 = fadd double %.322, %.324
%.326 = add i32 0, 2
%.327 = mul i32 -1, %.326
%.328 = sitofp  i32 %.327 to double
%.329 = fadd double %.325, %.328
%.330 = add i32 0, 3
%.331 = add i32 0, 3
%.333 = sdiv i32 %.330, %.331
%.334 = sitofp  i32 %.333 to double
%.335 = fadd double %.329, %.334
store double %.335, double* %d1
%i = alloca i32
%.336 = add i32 0, 0
store i32 %.336, i32* %i
%j = alloca i32
%.337 = add i32 0, 0
store i32 %.337, i32* %j
%.338 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str.11, i32 0, i32 0))
%.339 = load i32, i32* %i
%.340 = add i32 0, 10
%.341 = icmp slt i32 %.339, %.340
br label %while1
while1:
%.342 = add i32 0, 10
%.343 = load i32, i32* %i
%.344 = icmp sgt i32 %.342, %.343
br label %while2
while2:
%.345 = add i32 0, 20
%.346 = load i32, i32* %j
%.347 = icmp sgt i32 %.345, %.346
br i1 %.347, label %thenaux64, label %else64
thenaux64:
%.348 = load i32, i32* %i
%.349 = add i32 0, 10
%.350 = icmp slt i32 %.348, %.349
br label %then64
then64:
%.351 = add i1 0, %.350
br label %ifCont64
else64:
br label %ifCont64
ifCont64:
%.352 = phi i1 [  %.351, %then64 ], [ %.347, %else64 ]
br label %while3
while3:
%.353 = load i32, i32* %i
%.354 = add i32 0, 1
%.356 = add i32 %.353, %.354
store i32 %.356, i32* %i
%.357 = load i32, i32* %j
%.358 = add i32 0, 1
%.360 = add i32 %.357, %.358
store i32 %.360, i32* %j
%.361 = load i32, i32* %i
%.362 = add i32 0, 10
%.363 = icmp eq i32 %.361, %.362
br i1 %.363, label %then65, label %else65
then65:
%.364 = load i32, i32* %j
%.365 = add i32 0, 9
%.366 = icmp eq i32 %.364, %.365
br i1 %.366, label %then66, label %else66
then66:
br label %ifCont66
else66:
br label %ifCont66
ifCont66:
br label %ifCont65
else65:
br label %ifCont65
ifCont65:
%.367 = add i32 0, 20
%.368 = load i32, i32* %j
%.369 = icmp sgt i32 %.367, %.368
br i1 %.369, label %thenaux67, label %else67
thenaux67:
%.370 = load i32, i32* %i
%.371 = add i32 0, 10
%.372 = icmp slt i32 %.370, %.371
br label %then67
then67:
%.373 = add i1 0, %.372
br label %ifCont67
else67:
br label %ifCont67
ifCont67:
%.374 = phi i1 [  %.373, %then67 ], [ %.369, %else67 ]
br i1 %.374, label %while3, label %whileCont3
whileCont3:
%.375 = add i32 0, 10
%.376 = load i32, i32* %i
%.377 = icmp sgt i32 %.375, %.376
br i1 %.377, label %while2, label %whileCont2
whileCont2:
%.378 = load i32, i32* %i
%.379 = add i32 0, 10
%.380 = icmp slt i32 %.378, %.379
br i1 %.380, label %while1, label %whileCont1
whileCont1:
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
