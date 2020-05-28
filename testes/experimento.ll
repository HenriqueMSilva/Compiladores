@.argc = common global i32 0
@e1 = common global i32 0
@argument = common global i1 0
@.str.argv = constant [3 x i8] c"%s\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.minus = constant [2 x i8] c"-\00"
@.str.0 = constant [2 x i8] c" \00"
@.str.1 = constant [2 x i8] c"\0A\00"
@.str.2 = constant [7 x i8] c"\09\0D\0A\0C\5C\22\00"
@.str.3 = constant [2 x i8] c"\0A\00"
@.str.4 = constant [35 x i8] c"%%%%\09%%%%\0D%%%%\0A%%%%\0C%%%%\5C%%%%\22%%%%\00"
@.str.5 = constant [2 x i8] c"\0A\00"
@.str.6 = constant [4 x i8] c"121\00"
@.str.7 = constant [2 x i8] c"\09\00"
@.str.8 = constant [9 x i8] c"%%%%%%%%\00"
@.str.9 = constant [2 x i8] c"\0C\00"
@.str.10 = constant [15 x i8] c" %%%%%%%%\092213\00"
@.str.11 = constant [2 x i8] c"\5C\00"
@.str.12 = constant [59 x i8] c"ª*`=)(T%%%%D%%%%PK!JHG.,;_`^^~%%%%Djpcjksdojf872yyG%%%%|\22\00"
@.str.13 = constant [2 x i8] c"\0A\00"
@.str.14 = constant [2 x i8] c"\0A\00"
@.str.15 = constant [5 x i8] c"\0Aa:\0A\00"
@.str.16 = constant [11 x i8] c"Before if\0A\00"
@.str.17 = constant [11 x i8] c"After ifs\0A\00"
@.str.18 = constant [11 x i8] c"After ifs\0A\00"
@.str.19 = constant [2 x i8] c"\0A\00"
@.str.20 = constant [2 x i8] c"\0A\00"
@.str.21 = constant [14 x i8] c"Before while\0A\00"
@.str.22 = constant [2 x i8] c"\0A\00"
define void @main.nossa(i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%e = alloca double
%e2 = alloca double
%.1 = add i32 0, 11232
store i32 %.1, i32* @e1
%.2 = fadd  double 0.000000, 1.0000000000000000e+12
store double %.2, double* %e2
%.3 = load i32, i32* @e1
%.4 = fadd  double 0.000000, 1.0000000000000000e+00
%.5 = add i32 0, 2
%.6 = sitofp i32 %.5 to double
%.7 = fadd double %.4, %.6
store double %.7, double* %e2
%.8 = sitofp i32 %.3 to double
%.9 = fadd double %.8, %.7
store double %.9, double* %e
%.10 = load double, double* %e
%.11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.10)
%.12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
%.13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.1, i32 0, i32 0))
%.14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0))
%.15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.3, i32 0, i32 0))
%.16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([35 x i8], [35 x i8]* @.str.4, i32 0, i32 0))
%.17 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.5, i32 0, i32 0))
%.18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.6, i32 0, i32 0))
%.19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.7, i32 0, i32 0))
%.20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str.8, i32 0, i32 0))
%.21 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.9, i32 0, i32 0))
%.22 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @.str.10, i32 0, i32 0))
%.23 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.11, i32 0, i32 0))
%.24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.12, i32 0, i32 0))
%.25 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.13, i32 0, i32 0))
%.26 = add i32 0, 0
%.27 = load i8**, i8*** %args
%.28 = add i32 1 , %.26 
%.29 = getelementptr i8*, i8** %.27, i32 %.28
%.30 = load i8*, i8** %.29
%.31 = call i32 @atoi(i8* %.30)
%.32 = add i32 0, 5
%.34 = add i32 %.31, %.32
%.35 = add i32 0, 10
%.36 = icmp ne i32 %.34, %.35
br i1 %.36, label %thenaux16, label %else16
thenaux16:
%.37 = or i1 false, true
br label %then16
then16:
%.38 = add i1 0, %.37
br label %ifCont16
else16:
br label %ifCont16
ifCont16:
%.39 = phi i1 [  %.38, %then16 ], [ %.36, %else16 ]
store i1 %.39, i1* @argument
%.40 = load i1, i1* @argument
%.41 = alloca i1
br i1 %.40, label %then17, label %else17
then17:
store i1 false, i1* %.41
br label %ifCont17
else17:
store i1 true, i1* %.41
br label %ifCont17
ifCont17:
%.42 = load i1, i1* %.41
%.43 = alloca i1
br i1 %.42, label %then18, label %else18
then18:
store i1 false, i1* %.43
br label %ifCont18
else18:
store i1 true, i1* %.43
br label %ifCont18
ifCont18:
%.44 = load i1, i1* %.43
%.45 = alloca i1
br i1 %.44, label %then19, label %else19
then19:
store i1 false, i1* %.45
br label %ifCont19
else19:
store i1 true, i1* %.45
br label %ifCont19
ifCont19:
%.46 = load i1, i1* %.45
br i1 %.46, label %then20, label %elseaux20
then20:
br label %ifCont20
elseaux20:
%.47 = or i1 false, false
br label %else20
else20:
%.48 = add i1 0, %.47
br label %ifCont20
ifCont20:
%.49 = phi i1 [  %.46, %then20 ], [ %.48, %else20 ]
%.50 = alloca i1
br i1 %.49, label %then21, label %else21
then21:
store i1 false, i1* %.50
br label %ifCont21
else21:
store i1 true, i1* %.50
br label %ifCont21
ifCont21:
%.51 = load i1, i1* %.50
%.52 = alloca i1
br i1 %.51, label %then22, label %else22
then22:
store i1 false, i1* %.52
br label %ifCont22
else22:
store i1 true, i1* %.52
br label %ifCont22
ifCont22:
%.53 = load i1, i1* %.52
%.54 = alloca i1
br i1 %.53, label %then23, label %else23
then23:
store i1 false, i1* %.54
br label %ifCont23
else23:
store i1 true, i1* %.54
br label %ifCont23
ifCont23:
%.55 = load i1, i1* %.54
%.56 = or i1 false, true
%.57 = zext i1 %.55 to i32
%.58 = zext i1 %.56 to i32
%.59 = icmp eq i32 %.57, %.58
br i1 %.59, label %then24, label %else24
then24:
%.60 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont24
else24:
%.61 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont24
ifCont24:
%a = alloca double
%.62 = add i32 0, 0
%.63 = load i8**, i8*** %args
%.64 = add i32 1 , %.62 
%.65 = getelementptr i8*, i8** %.63, i32 %.64
%.66 = load i8*, i8** %.65
%.67 = call i32 @atoi(i8* %.66)
%.68 = add i32 0, 0
%.69 = load i8**, i8*** %args
%.70 = add i32 1 , %.68 
%.71 = getelementptr i8*, i8** %.69, i32 %.70
%.72 = load i8*, i8** %.71
%.73 = call i32 @atoi(i8* %.72)
%.75 = mul i32 %.67, %.73
%.76 = add i32 0, 0
%.77 = load i8**, i8*** %args
%.78 = add i32 1 , %.76 
%.79 = getelementptr i8*, i8** %.77, i32 %.78
%.80 = load i8*, i8** %.79
%.81 = call i32 @atoi(i8* %.80)
%.83 = mul i32 %.75, %.81
%.84 = add i32 0, 0
%.85 = load i8**, i8*** %args
%.86 = add i32 1 , %.84 
%.87 = getelementptr i8*, i8** %.85, i32 %.86
%.88 = load i8*, i8** %.87
%.89 = call i32 @atoi(i8* %.88)
%.90 = add i32 0, 0
%.91 = load i8**, i8*** %args
%.92 = add i32 1 , %.90 
%.93 = getelementptr i8*, i8** %.91, i32 %.92
%.94 = load i8*, i8** %.93
%.95 = call i32 @atoi(i8* %.94)
%.97 = sdiv i32 %.89, %.95
%.98 = add i32 0, 0
%.99 = load i8**, i8*** %args
%.100 = add i32 1 , %.98 
%.101 = getelementptr i8*, i8** %.99, i32 %.100
%.102 = load i8*, i8** %.101
%.103 = call i32 @atoi(i8* %.102)
%.105 = srem i32 %.97, %.103
%.107 = add i32 %.83, %.105
%.108 = sitofp i32 %.107 to double
store double %.108, double* %a
%.109 = add i32 0, 0
%.110 = load i8**, i8*** %args
%.111 = add i32 1 , %.109 
%.112 = getelementptr i8*, i8** %.110, i32 %.111
%.113 = load i8*, i8** %.112
%.114 = call i32 @atoi(i8* %.113)
%.115 = add i32 0, 11123
%.117 = add i32 %.114, %.115
%.118 = sitofp i32 %.117 to double
store double %.118, double* %a
%i3 = alloca i1
%i4 = alloca i1
%i5 = alloca i1
%.119 = add i32 0, 111132
%.120 = add i32 0, 0
%.121 = load i8**, i8*** %args
%.122 = add i32 1 , %.120 
%.123 = getelementptr i8*, i8** %.121, i32 %.122
%.124 = load i8*, i8** %.123
%.125 = call i32 @atoi(i8* %.124)
%.127 = add i32 %.119, %.125
%.128 = mul i32 -1, %.127
%.129 = add i32 0, 1312432
%.131 = mul i32 %.128, %.129
%.132 = add i32 0, 1
%.133 = icmp eq i32 %.131, %.132
store i1 %.133, i1* %i5
store i1 %.133, i1* %i4
store i1 %.133, i1* %i3
store i1 %.133, i1* @argument
%.134 = load i1, i1* @argument
br i1 %.134, label %then25, label %else25
then25:
%.135 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont25
else25:
%.136 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont25
ifCont25:
%.137 = load double, double* %a
%.138 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.137)
%.139 = or i1 false, false
%.140 = alloca i1
br i1 %.139, label %then27, label %else27
then27:
store i1 false, i1* %.140
br label %ifCont27
else27:
store i1 true, i1* %.140
br label %ifCont27
ifCont27:
%.141 = load i1, i1* %.140
br i1 %.141, label %then28, label %else28
then28:
%.142 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont28
else28:
%.143 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont28
ifCont28:
%.144 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.14, i32 0, i32 0))
%.145 = add i32 0, 2222222
%.146 = sitofp i32 %.145 to double
store double %.146, double* %a
%d = alloca double
%.147 = fadd  double 0.000000, 2.3232332000000000e+08
store double %.147, double* %d
%b = alloca i32
%.148 = add i32 0, 3
store i32 %.148, i32* %b
%.149 = load double, double* %a
%.150 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.149)
%b1 = alloca i1
%.151 = or i1 false, true
store i1 %.151, i1* %b1
%.152 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.15, i32 0, i32 0))
%.153 = load double, double* %a
%.154 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.153)
%.155 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.16, i32 0, i32 0))
%.156 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.17, i32 0, i32 0))
%.157 = load double, double* %d
%.158 = add i32 0, 2
%.159 = sitofp i32 %.158 to double
%.160 = fcmp oge double %.157, %.159
br i1 %.160, label %then35, label %else35
then35:
%.161 = load double, double* %d
%.162 = add i32 0, 2
%.163 = sitofp i32 %.162 to double
%.164 = fcmp ole double %.161, %.163
br i1 %.164, label %then36, label %else36
then36:
%.165 = add i32 0, 2
%.166 = load double, double* %d
%.167 = sitofp i32 %.165 to double
%.168 = fcmp oge double %.167, %.166
br i1 %.168, label %then37, label %else37
then37:
%.169 = add i32 0, 2
%.170 = load double, double* %d
%.171 = sitofp i32 %.169 to double
%.172 = fcmp ole double %.171, %.170
br i1 %.172, label %then38, label %else38
then38:
%.173 = load double, double* %d
%.174 = add i32 0, 2
%.175 = sitofp i32 %.174 to double
%.176 = fcmp oeq double %.173, %.175
br i1 %.176, label %then39, label %else39
then39:
%.177 = add i32 0, 2
%.178 = load double, double* %d
%.179 = sitofp i32 %.177 to double
%.180 = fcmp oeq double %.179, %.178
br i1 %.180, label %then40, label %else40
then40:
%.181 = load double, double* %d
%.182 = add i32 0, 2
%.183 = sitofp i32 %.182 to double
%.184 = fcmp ogt double %.181, %.183
br i1 %.184, label %then41, label %else41
then41:
%.185 = load double, double* %d
%.186 = add i32 0, 2
%.187 = sitofp i32 %.186 to double
%.188 = fcmp olt double %.185, %.187
br i1 %.188, label %then42, label %else42
then42:
%.189 = add i32 0, 2
%.190 = load double, double* %d
%.191 = sitofp i32 %.189 to double
%.192 = fcmp ogt double %.191, %.190
br i1 %.192, label %then43, label %else43
then43:
%.193 = add i32 0, 2
%.194 = load double, double* %d
%.195 = sitofp i32 %.193 to double
%.196 = fcmp olt double %.195, %.194
br i1 %.196, label %then44, label %else44
then44:
%.197 = load double, double* %d
%.198 = add i32 0, 2
%.199 = sitofp i32 %.198 to double
%.200 = fcmp one double %.197, %.199
br i1 %.200, label %then45, label %else45
then45:
%.201 = add i32 0, 2
%.202 = load double, double* %d
%.203 = sitofp i32 %.201 to double
%.204 = fcmp one double %.203, %.202
br i1 %.204, label %then46, label %else46
then46:
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
%.205 = load double, double* %d
%.206 = fadd  double 0.000000, 2.2000000000000002e+00
%.207 = fcmp oge double %.205, %.206
br i1 %.207, label %then47, label %else47
then47:
%.208 = load double, double* %d
%.209 = fadd  double 0.000000, 2.2000000000000002e+00
%.210 = fcmp ole double %.208, %.209
br i1 %.210, label %then48, label %else48
then48:
%.211 = fadd  double 0.000000, 2.2000000000000002e+00
%.212 = load double, double* %d
%.213 = fcmp oge double %.211, %.212
br i1 %.213, label %then49, label %else49
then49:
%.214 = fadd  double 0.000000, 2.2000000000000002e+00
%.215 = load double, double* %d
%.216 = fcmp ole double %.214, %.215
br i1 %.216, label %then50, label %else50
then50:
%.217 = load double, double* %d
%.218 = fadd  double 0.000000, 2.2000000000000002e+00
%.219 = fcmp oeq double %.217, %.218
br i1 %.219, label %then51, label %else51
then51:
%.220 = fadd  double 0.000000, 2.2000000000000002e+00
%.221 = load double, double* %d
%.222 = fcmp oeq double %.220, %.221
br i1 %.222, label %then52, label %else52
then52:
%.223 = load double, double* %d
%.224 = fadd  double 0.000000, 2.2000000000000002e+00
%.225 = fcmp ogt double %.223, %.224
br i1 %.225, label %then53, label %else53
then53:
%.226 = load double, double* %d
%.227 = fadd  double 0.000000, 2.2000000000000002e+00
%.228 = fcmp olt double %.226, %.227
br i1 %.228, label %then54, label %else54
then54:
%.229 = fadd  double 0.000000, 2.2000000000000002e+00
%.230 = load double, double* %d
%.231 = fcmp ogt double %.229, %.230
br i1 %.231, label %then55, label %else55
then55:
%.232 = fadd  double 0.000000, 2.2000000000000002e+00
%.233 = load double, double* %d
%.234 = fcmp olt double %.232, %.233
br i1 %.234, label %then56, label %else56
then56:
%.235 = load double, double* %d
%.236 = fadd  double 0.000000, 2.2000000000000002e+00
%.237 = fcmp one double %.235, %.236
br i1 %.237, label %then57, label %else57
then57:
%.238 = fadd  double 0.000000, 2.2000000000000002e+00
%.239 = load double, double* %d
%.240 = fcmp one double %.238, %.239
br i1 %.240, label %then58, label %else58
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
br label %ifCont54
else54:
br label %ifCont54
ifCont54:
br label %ifCont53
else53:
br label %ifCont53
ifCont53:
br label %ifCont52
else52:
br label %ifCont52
ifCont52:
br label %ifCont51
else51:
br label %ifCont51
ifCont51:
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
%.241 = load i1, i1* %b1
%.242 = or i1 false, true
%.243 = zext i1 %.241 to i32
%.244 = zext i1 %.242 to i32
%.245 = icmp eq i32 %.243, %.244
br i1 %.245, label %thenaux59, label %else59
thenaux59:
%.246 = load double, double* %d
%.247 = fadd  double 0.000000, 2.2000000000000002e+00
%.248 = fcmp oge double %.246, %.247
br label %then59
then59:
%.249 = add i1 0, %.248
br label %ifCont59
else59:
br label %ifCont59
ifCont59:
%.250 = phi i1 [  %.249, %then59 ], [ %.245, %else59 ]
br i1 %.250, label %thenaux60, label %else60
thenaux60:
%.251 = add i32 0, 2
%.252 = load double, double* %d
%.253 = sitofp i32 %.251 to double
%.254 = fcmp oge double %.253, %.252
br label %then60
then60:
%.255 = add i1 0, %.254
br label %ifCont60
else60:
br label %ifCont60
ifCont60:
%.256 = phi i1 [  %.255, %then60 ], [ %.250, %else60 ]
br i1 %.256, label %thenaux61, label %else61
thenaux61:
%.257 = fadd  double 0.000000, 2.2000000000000002e+00
%.258 = load double, double* %d
%.259 = fcmp ole double %.257, %.258
br label %then61
then61:
%.260 = add i1 0, %.259
br label %ifCont61
else61:
br label %ifCont61
ifCont61:
%.261 = phi i1 [  %.260, %then61 ], [ %.256, %else61 ]
br i1 %.261, label %then62, label %elseaux62
then62:
br label %ifCont62
elseaux62:
%.262 = fadd  double 0.000000, 2.2000000000000002e+00
%.263 = load double, double* %d
%.264 = fadd  double 0.000000, 2.2999999999999998e+00
%.265 = add i32 0, 2
%.266 = sitofp i32 %.265 to double
store double %.266, double* %a
%.268 = fadd double %.264, %.266
%.269 = add i32 0, 2
%.270 = sitofp i32 %.269 to double
store double %.270, double* %d
%.272 = fadd double %.268, %.270
store double %.272, double* %d
%.274 = fadd double %.263, %.272
%.275 = fcmp oeq double %.262, %.274
br label %else62
else62:
%.276 = add i1 0, %.275
br label %ifCont62
ifCont62:
%.277 = phi i1 [  %.261, %then62 ], [ %.276, %else62 ]
br i1 %.277, label %then63, label %else63
then63:
%.278 = or i1 false, true
%.279 = load i1, i1* %b1
%.280 = zext i1 %.278 to i32
%.281 = zext i1 %.279 to i32
%.282 = icmp eq i32 %.280, %.281
br i1 %.282, label %then64, label %else64
then64:
%.283 = load i1, i1* %b1
%.284 = or i1 false, true
%.285 = zext i1 %.283 to i32
%.286 = zext i1 %.284 to i32
%.287 = icmp ne i32 %.285, %.286
br i1 %.287, label %then65, label %else65
then65:
%.288 = or i1 false, true
%.289 = load i1, i1* %b1
%.290 = zext i1 %.288 to i32
%.291 = zext i1 %.289 to i32
%.292 = icmp ne i32 %.290, %.291
br i1 %.292, label %then66, label %else66
then66:
br label %ifCont66
else66:
br label %ifCont66
ifCont66:
br label %ifCont65
else65:
br label %ifCont65
ifCont65:
br label %ifCont64
else64:
br label %ifCont64
ifCont64:
br label %ifCont63
else63:
br label %ifCont63
ifCont63:
%.293 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.18, i32 0, i32 0))
%.294 = load double, double* %a
%.295 = load double, double* %d
%.296 = fmul double -1.0, %.295
%.298 = fmul double %.294, %.296
%.299 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.298)
%.300 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.19, i32 0, i32 0))
%.301 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.20, i32 0, i32 0))
%d1 = alloca double
%i = alloca i32
%.302 = add i32 0, 0
store i32 %.302, i32* %i
%j = alloca i32
%.303 = add i32 0, 0
store i32 %.303, i32* %j
%.304 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str.21, i32 0, i32 0))
%.305 = load i32, i32* %i
%.306 = add i32 0, 10
%.307 = icmp slt i32 %.305, %.306
br label %while1
while1:
%.308 = add i32 0, 10
%.309 = load i32, i32* %i
%.310 = icmp sgt i32 %.308, %.309
br label %while2
while2:
%.311 = add i32 0, 20
%.312 = load i32, i32* %j
%.313 = icmp sgt i32 %.311, %.312
br i1 %.313, label %thenaux72, label %else72
thenaux72:
%.314 = load i32, i32* %i
%.315 = add i32 0, 10
%.316 = icmp slt i32 %.314, %.315
br label %then72
then72:
%.317 = add i1 0, %.316
br label %ifCont72
else72:
br label %ifCont72
ifCont72:
%.318 = phi i1 [  %.317, %then72 ], [ %.313, %else72 ]
br label %while3
while3:
%.319 = load i32, i32* %i
%.320 = add i32 0, 1
%.322 = add i32 %.319, %.320
store i32 %.322, i32* %i
%.323 = load i32, i32* %j
%.324 = add i32 0, 1
%.326 = add i32 %.323, %.324
store i32 %.326, i32* %j
%.327 = load i32, i32* %i
%.328 = add i32 0, 10
%.329 = icmp eq i32 %.327, %.328
br i1 %.329, label %then73, label %else73
then73:
%.330 = load i32, i32* %j
%.331 = add i32 0, 9
%.332 = icmp eq i32 %.330, %.331
br i1 %.332, label %then74, label %else74
then74:
br label %ifCont74
else74:
br label %ifCont74
ifCont74:
br label %ifCont73
else73:
br label %ifCont73
ifCont73:
%.333 = add i32 0, 20
%.334 = load i32, i32* %j
%.335 = icmp sgt i32 %.333, %.334
br i1 %.335, label %thenaux75, label %else75
thenaux75:
%.336 = load i32, i32* %i
%.337 = add i32 0, 10
%.338 = icmp slt i32 %.336, %.337
br label %then75
then75:
%.339 = add i1 0, %.338
br label %ifCont75
else75:
br label %ifCont75
ifCont75:
%.340 = phi i1 [  %.339, %then75 ], [ %.335, %else75 ]
br i1 %.340, label %while3, label %whileCont3
whileCont3:
%.341 = add i32 0, 10
%.342 = load i32, i32* %i
%.343 = icmp sgt i32 %.341, %.342
br i1 %.343, label %while2, label %whileCont2
whileCont2:
%.344 = load i32, i32* %i
%.345 = add i32 0, 10
%.346 = icmp slt i32 %.344, %.345
br i1 %.346, label %while1, label %whileCont1
whileCont1:
%.347 = add i32 0, 0
%.348 = sitofp i32 %.347 to double
store double %.348, double* %a
%.349 = load double, double* %a
%.350 = add i32 0, 0
%.351 = sitofp i32 %.350 to double
%.352 = fcmp oeq double %.349, %.351
br i1 %.352, label %then76, label %else76
then76:
%.353 = load double, double* %a
%.354 = add i32 0, 10
%.355 = sitofp i32 %.354 to double
%.356 = fadd double %.353, %.355
store double %.356, double* %a
%.357 = load double, double* %a
%.358 = add i32 0, 10
%.359 = sitofp i32 %.358 to double
%.360 = fcmp oeq double %.357, %.359
br i1 %.360, label %then77, label %else77
then77:
%.361 = load double, double* %a
%.362 = add i32 0, 20
%.363 = sitofp i32 %.362 to double
%.364 = fcmp olt double %.361, %.363
br label %while4
while4:
%.365 = load double, double* %a
%.366 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.365)
%.367 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.22, i32 0, i32 0))
%.368 = load double, double* %a
%.369 = add i32 0, 2
%.370 = sitofp i32 %.369 to double
%.371 = fadd double %.368, %.370
store double %.371, double* %a
%.372 = load double, double* %a
%.373 = add i32 0, 20
%.374 = sitofp i32 %.373 to double
%.375 = fcmp olt double %.372, %.374
br i1 %.375, label %while4, label %whileCont4
whileCont4:
br label %ifCont77
else77:
br label %ifCont77
ifCont77:
br label %ifCont76
else76:
br label %ifCont76
ifCont76:
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
