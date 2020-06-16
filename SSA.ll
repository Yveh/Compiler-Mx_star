%string []
% []
%vector [i32]
str.0 = "vector x: "
str.1 = "excited!"
str.2 = "vector y: "
str.3 = "x + y: "
str.4 = "x * y: "
str.5 = "(1 << 3) * y: "
str.6 = "( "
str.7 = ", "
str.8 = " )"
def @main() {
LAB 1:
	%42 = malloc(4);
	%44 = 10 * 4;
	%45 = %44 + 4;
	%46 = malloc(%45);
	store i32 %46 10;
	%47 = %46 + 4;
	%341 = 0;
	br lab49;
LAB 49:
	%53 = %341 < 10;
	br %53 lab50 lab52;
LAB 50:
	%57 = %341 * 4;
	%58 = %47 + %57;
	%59 = 9 - %341;
	store i32 %58 %59;
	br lab51;
LAB 51:
	%62 = %341 + 1;
	%341 = %62;
	br lab49;
LAB 52:
	void @vector_init(i32 %42,i32 %47);
	void @print(i8 str.0);
	%66 = i32@vector_tostring(i32 %42);
	void @println(i32 %66);
	%68 = malloc(4);
	%71 = i8@vector_copy(i32 %68,i32 %42);
	br lab72;
LAB 72:
	%76 = i8@vector_set(i32 %68,i32 3,i32 817);
	br %76 lab74 lab358;
LAB 74:
	void @println(i8 str.1);
	br lab73;
LAB 73:
	void @print(i8 str.2);
	%78 = i32@vector_tostring(i32 %68);
	void @println(i32 %78);
	void @print(i8 str.3);
	%81 = i32@vector_add(i32 %42,i32 %68);
	%82 = i32@vector_tostring(i32 %81);
	void @println(i32 %82);
	void @print(i8 str.4);
	%85 = i32@vector_dot(i32 %42,i32 %68);
	%86 = i32@toString(i32 %85);
	void @println(i32 %86);
	void @print(i8 str.5);
	%88 = 1 << 3;
	%89 = i32@vector_scalarInPlaceMultiply(i32 %68,i32 %88);
	%90 = i32@vector_tostring(i32 %89);
	void @println(i32 %90);
	%91 = 0;
	br lab2;
LAB 2:
	ret i32 %91;
LAB 358:
	br lab73;
}
def @vector_init(i32 %5, i32 %6) {
LAB 3:
	br lab92;
LAB 92:
	%95 = %6 == 0;
	br %95 lab94 lab93;
LAB 94:
	ret void 0;
	%342 = 0;
	br lab4;
LAB 4:
	ret void 0;
LAB 93:
	%97 = %5 + 0;
	%99 = i32@_size(i32 %6);
	%100 = %99 * 4;
	%101 = %100 + 4;
	%102 = malloc(%101);
	store i32 %102 %99;
	%103 = %102 + 4;
	store i32 %97 %103;
	%343 = 0;
	br lab105;
LAB 105:
	%112 = i32@_size(i32 %6);
	%109 = %343 < %112;
	br %109 lab106 lab108;
LAB 106:
	%113 = %5 + 0;
	%114 = load i32 %113;
	%116 = %343 * 4;
	%117 = %114 + %116;
	%120 = %343 * 4;
	%121 = %6 + %120;
	%122 = load i32 %121;
	store i32 %117 %122;
	br lab107;
LAB 107:
	%124 = %343 + 1;
	%343 = %124;
	br lab105;
LAB 108:
	%342 = %343;
	br lab4;
}
def @vector_getDim(i32 %10) {
LAB 8:
	br lab125;
LAB 125:
	%129 = %10 + 0;
	%130 = load i32 %129;
	%128 = %130 == 0;
	br %128 lab127 lab126;
LAB 127:
	%134 = 0;
	br lab9;
LAB 9:
	ret i32 %134;
LAB 126:
	%131 = %10 + 0;
	%132 = load i32 %131;
	%133 = i32@_size(i32 %132);
	%134 = %133;
	br lab9;
}
def @vector_dot(i32 %13, i32 %14) {
LAB 11:
	%345 = 0;
	%344 = 0;
	br lab137;
LAB 137:
	%142 = i32@malloc();
	%140 = %344 < %142;
	br %140 lab138 lab139;
LAB 138:
	%144 = %13 + 0;
	%145 = load i32 %144;
	%147 = %344 * 4;
	%148 = %145 + %147;
	%149 = load i32 %148;
	%151 = %14 + 0;
	%152 = load i32 %151;
	%154 = %344 * 4;
	%155 = %152 + %154;
	%156 = load i32 %155;
	%143 = %149 * %156;
	%158 = %344 + 1;
	%345 = %143;
	%344 = %158;
	br lab137;
LAB 139:
	%160 = %345;
	br lab12;
LAB 12:
	ret i32 %160;
}
def @vector_scalarInPlaceMultiply(i32 %18, i32 %19) {
LAB 16:
	br lab161;
LAB 161:
	%165 = %18 + 0;
	%166 = load i32 %165;
	%164 = %166 == 0;
	br %164 lab163 lab162;
LAB 163:
	%346 = 0;
	%190 = 0;
	br lab17;
LAB 17:
	ret i32 %190;
LAB 162:
	%347 = 0;
	br lab168;
LAB 168:
	%174 = i32@malloc();
	%172 = %347 < %174;
	br %172 lab169 lab171;
LAB 169:
	%175 = %18 + 0;
	%176 = load i32 %175;
	%178 = %347 * 4;
	%179 = %176 + %178;
	%182 = %18 + 0;
	%183 = load i32 %182;
	%185 = %347 * 4;
	%186 = %183 + %185;
	%187 = load i32 %186;
	%180 = %19 * %187;
	store i32 %179 %180;
	br lab170;
LAB 170:
	%189 = %347 + 1;
	%347 = %189;
	br lab168;
LAB 171:
	%346 = %347;
	%190 = %18;
	br lab17;
}
def @vector_add(i32 %23, i32 %24) {
LAB 21:
	br lab191;
LAB 191:
	%200 = i32@malloc();
	%202 = i32@vector_getDim(i32 %24);
	%199 = %200 != %202;
	br %199 lab359 lab196;
LAB 195:
	%350 = 1;
	br lab198;
LAB 198:
	br %350 lab193 lab192;
LAB 193:
	%349 = 0;
	%348 = 0;
	%246 = 0;
	br lab22;
LAB 22:
	ret i32 %246;
LAB 192:
	%207 = malloc(4);
	%210 = %207 + 0;
	%211 = i32@malloc();
	%212 = %211 * 4;
	%213 = %212 + 4;
	%214 = malloc(%213);
	store i32 %214 %211;
	%215 = %214 + 4;
	store i32 %210 %215;
	%351 = 0;
	br lab216;
LAB 216:
	%222 = i32@malloc();
	%220 = %351 < %222;
	br %220 lab217 lab219;
LAB 217:
	%224 = %207 + 0;
	%225 = load i32 %224;
	%227 = %351 * 4;
	%228 = %225 + %227;
	%230 = %23 + 0;
	%231 = load i32 %230;
	%233 = %351 * 4;
	%234 = %231 + %233;
	%235 = load i32 %234;
	%237 = %24 + 0;
	%238 = load i32 %237;
	%240 = %351 * 4;
	%241 = %238 + %240;
	%242 = load i32 %241;
	%229 = %235 + %242;
	store i32 %228 %229;
	br lab218;
LAB 218:
	%244 = %351 + 1;
	%351 = %244;
	br lab216;
LAB 219:
	%349 = %351;
	%348 = %207;
	%246 = %207;
	br lab22;
LAB 196:
	%204 = i32@malloc();
	%203 = %204 == 0;
	br %203 lab360 lab197;
LAB 197:
	%350 = 0;
	br lab198;
LAB 359:
	br lab195;
LAB 360:
	br lab195;
}
def @vector_set(i32 %28, i32 %29, i32 %31) {
LAB 26:
	br lab247;
LAB 247:
	%251 = i32@malloc();
	%250 = %251 < %29;
	br %250 lab249 lab248;
LAB 249:
	%259 = 0;
	br lab27;
LAB 27:
	ret i8 %259;
LAB 248:
	%253 = %28 + 0;
	%254 = load i32 %253;
	%256 = %29 * 4;
	%257 = %254 + %256;
	store i32 %257 %31;
	%259 = 1;
	br lab27;
}
def @vector_tostring(i32 %35) {
LAB 33:
	br lab261;
LAB 261:
	%265 = i32@malloc();
	%264 = %265 > 0;
	br %264 lab263 lab361;
LAB 263:
	%268 = %35 + 0;
	%269 = load i32 %268;
	%270 = 0 * 4;
	%271 = %269 + %270;
	%272 = load i32 %271;
	%273 = i32@toString(i32 %272);
	%266 = i32@string_strcat(i8 str.6,i32 %273);
	%352 = %266;
	br lab262;
LAB 262:
	%354 = 1;
	%353 = %352;
	br lab275;
LAB 275:
	%281 = i32@malloc();
	%279 = %354 < %281;
	br %279 lab276 lab278;
LAB 276:
	%283 = i32@string_strcat(i32 %353,i8 str.7);
	%285 = %35 + 0;
	%286 = load i32 %285;
	%288 = %354 * 4;
	%289 = %286 + %288;
	%290 = load i32 %289;
	%291 = i32@toString(i32 %290);
	%282 = i32@string_strcat(i32 %283,i32 %291);
	br lab277;
LAB 277:
	%293 = %354 + 1;
	%354 = %293;
	%353 = %282;
	br lab275;
LAB 278:
	%294 = i32@string_strcat(i32 %353,i8 str.8);
	%297 = %294;
	br lab34;
LAB 34:
	ret i32 %297;
LAB 361:
	%352 = str.6;
	br lab262;
}
def @vector_copy(i32 %38, i32 %39) {
LAB 36:
	br lab298;
LAB 298:
	%301 = %39 == 0;
	br %301 lab300 lab299;
LAB 300:
	%357 = 0;
	%340 = 0;
	br lab37;
LAB 37:
	ret i8 %340;
LAB 299:
	br lab303;
LAB 303:
	%309 = i32@vector_getDim(i32 %39);
	%307 = %309 == 0;
	br %307 lab305 lab306;
LAB 305:
	%310 = %38 + 0;
	store i32 %310 0;
	%355 = 0;
	br lab304;
LAB 304:
	%357 = %355;
	%340 = 1;
	br lab37;
LAB 306:
	%311 = %38 + 0;
	%313 = i32@vector_getDim(i32 %39);
	%314 = %313 * 4;
	%315 = %314 + 4;
	%316 = malloc(%315);
	store i32 %316 %313;
	%317 = %316 + 4;
	store i32 %311 %317;
	%356 = 0;
	br lab319;
LAB 319:
	%325 = i32@malloc();
	%323 = %356 < %325;
	br %323 lab320 lab322;
LAB 320:
	%326 = %38 + 0;
	%327 = load i32 %326;
	%329 = %356 * 4;
	%330 = %327 + %329;
	%332 = %39 + 0;
	%333 = load i32 %332;
	%335 = %356 * 4;
	%336 = %333 + %335;
	%337 = load i32 %336;
	store i32 %330 %337;
	br lab321;
LAB 321:
	%339 = %356 + 1;
	%356 = %339;
	br lab319;
LAB 322:
	%355 = %356;
	br lab304;
}
