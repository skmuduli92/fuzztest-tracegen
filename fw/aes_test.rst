                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Apr  3 2018) (Linux)
                                      4 ; This file was generated Wed Jan 29 11:06:51 2020
                                      5 ;--------------------------------------------------------
                                      6 	.module aes_test
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _quit
                                     14 	.globl _TF2
                                     15 	.globl _EXF2
                                     16 	.globl _RCLK
                                     17 	.globl _TCLK
                                     18 	.globl _EXEN2
                                     19 	.globl _TR2
                                     20 	.globl _C_T2
                                     21 	.globl _CP_RL2
                                     22 	.globl _T2CON_7
                                     23 	.globl _T2CON_6
                                     24 	.globl _T2CON_5
                                     25 	.globl _T2CON_4
                                     26 	.globl _T2CON_3
                                     27 	.globl _T2CON_2
                                     28 	.globl _T2CON_1
                                     29 	.globl _T2CON_0
                                     30 	.globl _PT2
                                     31 	.globl _ET2
                                     32 	.globl _CY
                                     33 	.globl _AC
                                     34 	.globl _F0
                                     35 	.globl _RS1
                                     36 	.globl _RS0
                                     37 	.globl _OV
                                     38 	.globl _F1
                                     39 	.globl _P
                                     40 	.globl _PS
                                     41 	.globl _PT1
                                     42 	.globl _PX1
                                     43 	.globl _PT0
                                     44 	.globl _PX0
                                     45 	.globl _RD
                                     46 	.globl _WR
                                     47 	.globl _T1
                                     48 	.globl _T0
                                     49 	.globl _INT1
                                     50 	.globl _INT0
                                     51 	.globl _TXD
                                     52 	.globl _RXD
                                     53 	.globl _P3_7
                                     54 	.globl _P3_6
                                     55 	.globl _P3_5
                                     56 	.globl _P3_4
                                     57 	.globl _P3_3
                                     58 	.globl _P3_2
                                     59 	.globl _P3_1
                                     60 	.globl _P3_0
                                     61 	.globl _EA
                                     62 	.globl _ES
                                     63 	.globl _ET1
                                     64 	.globl _EX1
                                     65 	.globl _ET0
                                     66 	.globl _EX0
                                     67 	.globl _P2_7
                                     68 	.globl _P2_6
                                     69 	.globl _P2_5
                                     70 	.globl _P2_4
                                     71 	.globl _P2_3
                                     72 	.globl _P2_2
                                     73 	.globl _P2_1
                                     74 	.globl _P2_0
                                     75 	.globl _SM0
                                     76 	.globl _SM1
                                     77 	.globl _SM2
                                     78 	.globl _REN
                                     79 	.globl _TB8
                                     80 	.globl _RB8
                                     81 	.globl _TI
                                     82 	.globl _RI
                                     83 	.globl _P1_7
                                     84 	.globl _P1_6
                                     85 	.globl _P1_5
                                     86 	.globl _P1_4
                                     87 	.globl _P1_3
                                     88 	.globl _P1_2
                                     89 	.globl _P1_1
                                     90 	.globl _P1_0
                                     91 	.globl _TF1
                                     92 	.globl _TR1
                                     93 	.globl _TF0
                                     94 	.globl _TR0
                                     95 	.globl _IE1
                                     96 	.globl _IT1
                                     97 	.globl _IE0
                                     98 	.globl _IT0
                                     99 	.globl _P0_7
                                    100 	.globl _P0_6
                                    101 	.globl _P0_5
                                    102 	.globl _P0_4
                                    103 	.globl _P0_3
                                    104 	.globl _P0_2
                                    105 	.globl _P0_1
                                    106 	.globl _P0_0
                                    107 	.globl _TH2
                                    108 	.globl _TL2
                                    109 	.globl _RCAP2H
                                    110 	.globl _RCAP2L
                                    111 	.globl _T2CON
                                    112 	.globl _B
                                    113 	.globl _ACC
                                    114 	.globl _PSW
                                    115 	.globl _IP
                                    116 	.globl _P3
                                    117 	.globl _IE
                                    118 	.globl _P2
                                    119 	.globl _SBUF
                                    120 	.globl _SCON
                                    121 	.globl _P1
                                    122 	.globl _TH1
                                    123 	.globl _TH0
                                    124 	.globl _TL1
                                    125 	.globl _TL0
                                    126 	.globl _TMOD
                                    127 	.globl _TCON
                                    128 	.globl _PCON
                                    129 	.globl _DPH
                                    130 	.globl _DPL
                                    131 	.globl _SP
                                    132 	.globl _P0
                                    133 	.globl _debug_reg_data
                                    134 	.globl _debug_reg_addr
                                    135 	.globl _pt_rden
                                    136 	.globl _pt_wren
                                    137 	.globl _data
                                    138 	.globl _aes_reg_key1
                                    139 	.globl _aes_reg_key0
                                    140 	.globl _aes_reg_ctr
                                    141 	.globl _aes_reg_len
                                    142 	.globl _aes_reg_addr
                                    143 	.globl _aes_reg_state
                                    144 	.globl _aes_reg_start
                                    145 ;--------------------------------------------------------
                                    146 ; special function registers
                                    147 ;--------------------------------------------------------
                                    148 	.area RSEG    (ABS,DATA)
      000000                        149 	.org 0x0000
                           000080   150 _P0	=	0x0080
                           000081   151 _SP	=	0x0081
                           000082   152 _DPL	=	0x0082
                           000083   153 _DPH	=	0x0083
                           000087   154 _PCON	=	0x0087
                           000088   155 _TCON	=	0x0088
                           000089   156 _TMOD	=	0x0089
                           00008A   157 _TL0	=	0x008a
                           00008B   158 _TL1	=	0x008b
                           00008C   159 _TH0	=	0x008c
                           00008D   160 _TH1	=	0x008d
                           000090   161 _P1	=	0x0090
                           000098   162 _SCON	=	0x0098
                           000099   163 _SBUF	=	0x0099
                           0000A0   164 _P2	=	0x00a0
                           0000A8   165 _IE	=	0x00a8
                           0000B0   166 _P3	=	0x00b0
                           0000B8   167 _IP	=	0x00b8
                           0000D0   168 _PSW	=	0x00d0
                           0000E0   169 _ACC	=	0x00e0
                           0000F0   170 _B	=	0x00f0
                           0000C8   171 _T2CON	=	0x00c8
                           0000CA   172 _RCAP2L	=	0x00ca
                           0000CB   173 _RCAP2H	=	0x00cb
                           0000CC   174 _TL2	=	0x00cc
                           0000CD   175 _TH2	=	0x00cd
                                    176 ;--------------------------------------------------------
                                    177 ; special function bits
                                    178 ;--------------------------------------------------------
                                    179 	.area RSEG    (ABS,DATA)
      000000                        180 	.org 0x0000
                           000080   181 _P0_0	=	0x0080
                           000081   182 _P0_1	=	0x0081
                           000082   183 _P0_2	=	0x0082
                           000083   184 _P0_3	=	0x0083
                           000084   185 _P0_4	=	0x0084
                           000085   186 _P0_5	=	0x0085
                           000086   187 _P0_6	=	0x0086
                           000087   188 _P0_7	=	0x0087
                           000088   189 _IT0	=	0x0088
                           000089   190 _IE0	=	0x0089
                           00008A   191 _IT1	=	0x008a
                           00008B   192 _IE1	=	0x008b
                           00008C   193 _TR0	=	0x008c
                           00008D   194 _TF0	=	0x008d
                           00008E   195 _TR1	=	0x008e
                           00008F   196 _TF1	=	0x008f
                           000090   197 _P1_0	=	0x0090
                           000091   198 _P1_1	=	0x0091
                           000092   199 _P1_2	=	0x0092
                           000093   200 _P1_3	=	0x0093
                           000094   201 _P1_4	=	0x0094
                           000095   202 _P1_5	=	0x0095
                           000096   203 _P1_6	=	0x0096
                           000097   204 _P1_7	=	0x0097
                           000098   205 _RI	=	0x0098
                           000099   206 _TI	=	0x0099
                           00009A   207 _RB8	=	0x009a
                           00009B   208 _TB8	=	0x009b
                           00009C   209 _REN	=	0x009c
                           00009D   210 _SM2	=	0x009d
                           00009E   211 _SM1	=	0x009e
                           00009F   212 _SM0	=	0x009f
                           0000A0   213 _P2_0	=	0x00a0
                           0000A1   214 _P2_1	=	0x00a1
                           0000A2   215 _P2_2	=	0x00a2
                           0000A3   216 _P2_3	=	0x00a3
                           0000A4   217 _P2_4	=	0x00a4
                           0000A5   218 _P2_5	=	0x00a5
                           0000A6   219 _P2_6	=	0x00a6
                           0000A7   220 _P2_7	=	0x00a7
                           0000A8   221 _EX0	=	0x00a8
                           0000A9   222 _ET0	=	0x00a9
                           0000AA   223 _EX1	=	0x00aa
                           0000AB   224 _ET1	=	0x00ab
                           0000AC   225 _ES	=	0x00ac
                           0000AF   226 _EA	=	0x00af
                           0000B0   227 _P3_0	=	0x00b0
                           0000B1   228 _P3_1	=	0x00b1
                           0000B2   229 _P3_2	=	0x00b2
                           0000B3   230 _P3_3	=	0x00b3
                           0000B4   231 _P3_4	=	0x00b4
                           0000B5   232 _P3_5	=	0x00b5
                           0000B6   233 _P3_6	=	0x00b6
                           0000B7   234 _P3_7	=	0x00b7
                           0000B0   235 _RXD	=	0x00b0
                           0000B1   236 _TXD	=	0x00b1
                           0000B2   237 _INT0	=	0x00b2
                           0000B3   238 _INT1	=	0x00b3
                           0000B4   239 _T0	=	0x00b4
                           0000B5   240 _T1	=	0x00b5
                           0000B6   241 _WR	=	0x00b6
                           0000B7   242 _RD	=	0x00b7
                           0000B8   243 _PX0	=	0x00b8
                           0000B9   244 _PT0	=	0x00b9
                           0000BA   245 _PX1	=	0x00ba
                           0000BB   246 _PT1	=	0x00bb
                           0000BC   247 _PS	=	0x00bc
                           0000D0   248 _P	=	0x00d0
                           0000D1   249 _F1	=	0x00d1
                           0000D2   250 _OV	=	0x00d2
                           0000D3   251 _RS0	=	0x00d3
                           0000D4   252 _RS1	=	0x00d4
                           0000D5   253 _F0	=	0x00d5
                           0000D6   254 _AC	=	0x00d6
                           0000D7   255 _CY	=	0x00d7
                           0000AD   256 _ET2	=	0x00ad
                           0000BD   257 _PT2	=	0x00bd
                           0000C8   258 _T2CON_0	=	0x00c8
                           0000C9   259 _T2CON_1	=	0x00c9
                           0000CA   260 _T2CON_2	=	0x00ca
                           0000CB   261 _T2CON_3	=	0x00cb
                           0000CC   262 _T2CON_4	=	0x00cc
                           0000CD   263 _T2CON_5	=	0x00cd
                           0000CE   264 _T2CON_6	=	0x00ce
                           0000CF   265 _T2CON_7	=	0x00cf
                           0000C8   266 _CP_RL2	=	0x00c8
                           0000C9   267 _C_T2	=	0x00c9
                           0000CA   268 _TR2	=	0x00ca
                           0000CB   269 _EXEN2	=	0x00cb
                           0000CC   270 _TCLK	=	0x00cc
                           0000CD   271 _RCLK	=	0x00cd
                           0000CE   272 _EXF2	=	0x00ce
                           0000CF   273 _TF2	=	0x00cf
                                    274 ;--------------------------------------------------------
                                    275 ; overlayable register banks
                                    276 ;--------------------------------------------------------
                                    277 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        278 	.ds 8
                                    279 ;--------------------------------------------------------
                                    280 ; internal ram data
                                    281 ;--------------------------------------------------------
                                    282 	.area DSEG    (DATA)
                                    283 ;--------------------------------------------------------
                                    284 ; overlayable items in internal ram 
                                    285 ;--------------------------------------------------------
                                    286 ;--------------------------------------------------------
                                    287 ; Stack segment in internal ram 
                                    288 ;--------------------------------------------------------
                                    289 	.area	SSEG
      000008                        290 __start__stack:
      000008                        291 	.ds	1
                                    292 
                                    293 ;--------------------------------------------------------
                                    294 ; indirectly addressable internal ram data
                                    295 ;--------------------------------------------------------
                                    296 	.area ISEG    (DATA)
                                    297 ;--------------------------------------------------------
                                    298 ; absolute internal ram data
                                    299 ;--------------------------------------------------------
                                    300 	.area IABS    (ABS,DATA)
                                    301 	.area IABS    (ABS,DATA)
                                    302 ;--------------------------------------------------------
                                    303 ; bit data
                                    304 ;--------------------------------------------------------
                                    305 	.area BSEG    (BIT)
                                    306 ;--------------------------------------------------------
                                    307 ; paged external ram data
                                    308 ;--------------------------------------------------------
                                    309 	.area PSEG    (PAG,XDATA)
                                    310 ;--------------------------------------------------------
                                    311 ; external ram data
                                    312 ;--------------------------------------------------------
                                    313 	.area XSEG    (XDATA)
                           00FF00   314 _aes_reg_start	=	0xff00
                           00FF01   315 _aes_reg_state	=	0xff01
                           00FF02   316 _aes_reg_addr	=	0xff02
                           00FF04   317 _aes_reg_len	=	0xff04
                           00FF10   318 _aes_reg_ctr	=	0xff10
                           00FF20   319 _aes_reg_key0	=	0xff20
                           00FF30   320 _aes_reg_key1	=	0xff30
                           00E000   321 _data	=	0xe000
                           00FF80   322 _pt_wren	=	0xff80
                           00FFA0   323 _pt_rden	=	0xffa0
                           00EFFE   324 _debug_reg_addr	=	0xeffe
                           00EFFF   325 _debug_reg_data	=	0xefff
                                    326 ;--------------------------------------------------------
                                    327 ; absolute external ram data
                                    328 ;--------------------------------------------------------
                                    329 	.area XABS    (ABS,XDATA)
                                    330 ;--------------------------------------------------------
                                    331 ; external initialized ram data
                                    332 ;--------------------------------------------------------
                                    333 	.area XISEG   (XDATA)
                                    334 	.area HOME    (CODE)
                                    335 	.area GSINIT0 (CODE)
                                    336 	.area GSINIT1 (CODE)
                                    337 	.area GSINIT2 (CODE)
                                    338 	.area GSINIT3 (CODE)
                                    339 	.area GSINIT4 (CODE)
                                    340 	.area GSINIT5 (CODE)
                                    341 	.area GSINIT  (CODE)
                                    342 	.area GSFINAL (CODE)
                                    343 	.area CSEG    (CODE)
                                    344 ;--------------------------------------------------------
                                    345 ; interrupt vector 
                                    346 ;--------------------------------------------------------
                                    347 	.area HOME    (CODE)
      000000                        348 __interrupt_vect:
      000000 02 00 06         [24]  349 	ljmp	__sdcc_gsinit_startup
                                    350 ;--------------------------------------------------------
                                    351 ; global & static initialisations
                                    352 ;--------------------------------------------------------
                                    353 	.area HOME    (CODE)
                                    354 	.area GSINIT  (CODE)
                                    355 	.area GSFINAL (CODE)
                                    356 	.area GSINIT  (CODE)
                                    357 	.globl __sdcc_gsinit_startup
                                    358 	.globl __sdcc_program_startup
                                    359 	.globl __start__stack
                                    360 	.globl __mcs51_genXINIT
                                    361 	.globl __mcs51_genXRAMCLEAR
                                    362 	.globl __mcs51_genRAMCLEAR
                                    363 	.area GSFINAL (CODE)
      00005F 02 00 03         [24]  364 	ljmp	__sdcc_program_startup
                                    365 ;--------------------------------------------------------
                                    366 ; Home
                                    367 ;--------------------------------------------------------
                                    368 	.area HOME    (CODE)
                                    369 	.area HOME    (CODE)
      000003                        370 __sdcc_program_startup:
      000003 02 00 88         [24]  371 	ljmp	_main
                                    372 ;	return from main will return to caller
                                    373 ;--------------------------------------------------------
                                    374 ; code
                                    375 ;--------------------------------------------------------
                                    376 	.area CSEG    (CODE)
                                    377 ;------------------------------------------------------------
                                    378 ;Allocation info for local variables in function 'quit'
                                    379 ;------------------------------------------------------------
                                    380 ;	aes_test.c:18: void quit() {
                                    381 ;	-----------------------------------------
                                    382 ;	 function quit
                                    383 ;	-----------------------------------------
      000062                        384 _quit:
                           000007   385 	ar7 = 0x07
                           000006   386 	ar6 = 0x06
                           000005   387 	ar5 = 0x05
                           000004   388 	ar4 = 0x04
                           000003   389 	ar3 = 0x03
                           000002   390 	ar2 = 0x02
                           000001   391 	ar1 = 0x01
                           000000   392 	ar0 = 0x00
                                    393 ;	aes_test.c:19: P0 = P1 = P2 = P3 = 0xDE;
      000062 75 B0 DE         [24]  394 	mov	_P3,#0xDE
      000065 75 A0 DE         [24]  395 	mov	_P2,#0xDE
      000068 75 90 DE         [24]  396 	mov	_P1,#0xDE
      00006B 75 80 DE         [24]  397 	mov	_P0,#0xDE
                                    398 ;	aes_test.c:20: P0 = P1 = P2 = P3 = 0xAD;
      00006E 75 B0 AD         [24]  399 	mov	_P3,#0xAD
      000071 75 A0 AD         [24]  400 	mov	_P2,#0xAD
      000074 75 90 AD         [24]  401 	mov	_P1,#0xAD
      000077 75 80 AD         [24]  402 	mov	_P0,#0xAD
                                    403 ;	aes_test.c:21: P0 = P1 = P2 = P3 = 0x00;
      00007A 75 B0 00         [24]  404 	mov	_P3,#0x00
      00007D 75 A0 00         [24]  405 	mov	_P2,#0x00
      000080 75 90 00         [24]  406 	mov	_P1,#0x00
      000083 75 80 00         [24]  407 	mov	_P0,#0x00
                                    408 ;	aes_test.c:22: while(1);
      000086                        409 00102$:
      000086 80 FE            [24]  410 	sjmp	00102$
                                    411 ;------------------------------------------------------------
                                    412 ;Allocation info for local variables in function 'main'
                                    413 ;------------------------------------------------------------
                                    414 ;i                         Allocated to registers r4 r5 
                                    415 ;good                      Allocated to registers r6 r7 
                                    416 ;------------------------------------------------------------
                                    417 ;	aes_test.c:42: void main() {
                                    418 ;	-----------------------------------------
                                    419 ;	 function main
                                    420 ;	-----------------------------------------
      000088                        421 _main:
                                    422 ;	aes_test.c:45: int good=1;
      000088 7E 01            [12]  423 	mov	r6,#0x01
      00008A 7F 00            [12]  424 	mov	r7,#0x00
                                    425 ;	aes_test.c:48: for(i=0; i < 32; i++) {
      00008C 7C 00            [12]  426 	mov	r4,#0x00
      00008E 7D 00            [12]  427 	mov	r5,#0x00
      000090                        428 00115$:
                                    429 ;	aes_test.c:49: pt_wren[i] = 0xff;
      000090 EC               [12]  430 	mov	a,r4
      000091 24 80            [12]  431 	add	a,#_pt_wren
      000093 F5 82            [12]  432 	mov	dpl,a
      000095 ED               [12]  433 	mov	a,r5
      000096 34 FF            [12]  434 	addc	a,#(_pt_wren >> 8)
      000098 F5 83            [12]  435 	mov	dph,a
      00009A 74 FF            [12]  436 	mov	a,#0xFF
      00009C F0               [24]  437 	movx	@dptr,a
                                    438 ;	aes_test.c:50: pt_rden[i] = 0xff;
      00009D EC               [12]  439 	mov	a,r4
      00009E 24 A0            [12]  440 	add	a,#_pt_rden
      0000A0 F5 82            [12]  441 	mov	dpl,a
      0000A2 ED               [12]  442 	mov	a,r5
      0000A3 34 FF            [12]  443 	addc	a,#(_pt_rden >> 8)
      0000A5 F5 83            [12]  444 	mov	dph,a
      0000A7 74 FF            [12]  445 	mov	a,#0xFF
      0000A9 F0               [24]  446 	movx	@dptr,a
                                    447 ;	aes_test.c:48: for(i=0; i < 32; i++) {
      0000AA 0C               [12]  448 	inc	r4
      0000AB BC 00 01         [24]  449 	cjne	r4,#0x00,00182$
      0000AE 0D               [12]  450 	inc	r5
      0000AF                        451 00182$:
      0000AF C3               [12]  452 	clr	c
      0000B0 EC               [12]  453 	mov	a,r4
      0000B1 94 20            [12]  454 	subb	a,#0x20
      0000B3 ED               [12]  455 	mov	a,r5
      0000B4 64 80            [12]  456 	xrl	a,#0x80
      0000B6 94 80            [12]  457 	subb	a,#0x80
      0000B8 40 D6            [24]  458 	jc	00115$
                                    459 ;	aes_test.c:54: for(i=0; i < 32; i++) {
      0000BA 7C 00            [12]  460 	mov	r4,#0x00
      0000BC 7D 00            [12]  461 	mov	r5,#0x00
      0000BE                        462 00117$:
                                    463 ;	aes_test.c:55: data[i]=i;
      0000BE 8C 82            [24]  464 	mov	dpl,r4
      0000C0 74 E0            [12]  465 	mov	a,#(_data >> 8)
      0000C2 2D               [12]  466 	add	a,r5
      0000C3 F5 83            [12]  467 	mov	dph,a
      0000C5 8C 03            [24]  468 	mov	ar3,r4
      0000C7 EB               [12]  469 	mov	a,r3
      0000C8 F0               [24]  470 	movx	@dptr,a
                                    471 ;	aes_test.c:54: for(i=0; i < 32; i++) {
      0000C9 0C               [12]  472 	inc	r4
      0000CA BC 00 01         [24]  473 	cjne	r4,#0x00,00184$
      0000CD 0D               [12]  474 	inc	r5
      0000CE                        475 00184$:
      0000CE C3               [12]  476 	clr	c
      0000CF EC               [12]  477 	mov	a,r4
      0000D0 94 20            [12]  478 	subb	a,#0x20
      0000D2 ED               [12]  479 	mov	a,r5
      0000D3 64 80            [12]  480 	xrl	a,#0x80
      0000D5 94 80            [12]  481 	subb	a,#0x80
      0000D7 40 E5            [24]  482 	jc	00117$
                                    483 ;	aes_test.c:59: aes_reg_addr = 0xE000;
      0000D9 90 FF 02         [24]  484 	mov	dptr,#_aes_reg_addr
      0000DC E4               [12]  485 	clr	a
      0000DD F0               [24]  486 	movx	@dptr,a
      0000DE 74 E0            [12]  487 	mov	a,#0xE0
      0000E0 A3               [24]  488 	inc	dptr
      0000E1 F0               [24]  489 	movx	@dptr,a
                                    490 ;	aes_test.c:60: aes_reg_len = 32;
      0000E2 90 FF 04         [24]  491 	mov	dptr,#_aes_reg_len
      0000E5 74 20            [12]  492 	mov	a,#0x20
      0000E7 F0               [24]  493 	movx	@dptr,a
      0000E8 E4               [12]  494 	clr	a
      0000E9 A3               [24]  495 	inc	dptr
      0000EA F0               [24]  496 	movx	@dptr,a
                                    497 ;	aes_test.c:61: for(i=0; i < 16; i++) { aes_reg_ctr[i] = i*i*i; }
      0000EB 7C 00            [12]  498 	mov	r4,#0x00
      0000ED 7D 00            [12]  499 	mov	r5,#0x00
      0000EF                        500 00119$:
      0000EF EC               [12]  501 	mov	a,r4
      0000F0 24 10            [12]  502 	add	a,#_aes_reg_ctr
      0000F2 F5 82            [12]  503 	mov	dpl,a
      0000F4 ED               [12]  504 	mov	a,r5
      0000F5 34 FF            [12]  505 	addc	a,#(_aes_reg_ctr >> 8)
      0000F7 F5 83            [12]  506 	mov	dph,a
      0000F9 8C 03            [24]  507 	mov	ar3,r4
      0000FB EB               [12]  508 	mov	a,r3
      0000FC F5 F0            [12]  509 	mov	b,a
      0000FE A4               [48]  510 	mul	ab
      0000FF 8B F0            [24]  511 	mov	b,r3
      000101 A4               [48]  512 	mul	ab
      000102 FB               [12]  513 	mov	r3,a
      000103 F0               [24]  514 	movx	@dptr,a
      000104 0C               [12]  515 	inc	r4
      000105 BC 00 01         [24]  516 	cjne	r4,#0x00,00186$
      000108 0D               [12]  517 	inc	r5
      000109                        518 00186$:
      000109 C3               [12]  519 	clr	c
      00010A EC               [12]  520 	mov	a,r4
      00010B 94 10            [12]  521 	subb	a,#0x10
      00010D ED               [12]  522 	mov	a,r5
      00010E 64 80            [12]  523 	xrl	a,#0x80
      000110 94 80            [12]  524 	subb	a,#0x80
      000112 40 DB            [24]  525 	jc	00119$
                                    526 ;	aes_test.c:62: for(i=0; i < 16; i++) { aes_reg_key0[i] = i | (i << 4); }
      000114 7C 00            [12]  527 	mov	r4,#0x00
      000116 7D 00            [12]  528 	mov	r5,#0x00
      000118                        529 00121$:
      000118 EC               [12]  530 	mov	a,r4
      000119 24 20            [12]  531 	add	a,#_aes_reg_key0
      00011B F5 82            [12]  532 	mov	dpl,a
      00011D ED               [12]  533 	mov	a,r5
      00011E 34 FF            [12]  534 	addc	a,#(_aes_reg_key0 >> 8)
      000120 F5 83            [12]  535 	mov	dph,a
      000122 8C 03            [24]  536 	mov	ar3,r4
      000124 EB               [12]  537 	mov	a,r3
      000125 C4               [12]  538 	swap	a
      000126 54 F0            [12]  539 	anl	a,#0xF0
      000128 FB               [12]  540 	mov	r3,a
      000129 33               [12]  541 	rlc	a
      00012A 95 E0            [12]  542 	subb	a,acc
      00012C FA               [12]  543 	mov	r2,a
      00012D EC               [12]  544 	mov	a,r4
      00012E 42 03            [12]  545 	orl	ar3,a
      000130 ED               [12]  546 	mov	a,r5
      000131 42 02            [12]  547 	orl	ar2,a
      000133 EB               [12]  548 	mov	a,r3
      000134 F0               [24]  549 	movx	@dptr,a
      000135 0C               [12]  550 	inc	r4
      000136 BC 00 01         [24]  551 	cjne	r4,#0x00,00188$
      000139 0D               [12]  552 	inc	r5
      00013A                        553 00188$:
      00013A C3               [12]  554 	clr	c
      00013B EC               [12]  555 	mov	a,r4
      00013C 94 10            [12]  556 	subb	a,#0x10
      00013E ED               [12]  557 	mov	a,r5
      00013F 64 80            [12]  558 	xrl	a,#0x80
      000141 94 80            [12]  559 	subb	a,#0x80
      000143 40 D3            [24]  560 	jc	00121$
                                    561 ;	aes_test.c:65: aes_reg_start = 1;
      000145 90 FF 00         [24]  562 	mov	dptr,#_aes_reg_start
      000148 74 01            [12]  563 	mov	a,#0x01
      00014A F0               [24]  564 	movx	@dptr,a
                                    565 ;	aes_test.c:67: while(aes_reg_state != 0);
      00014B                        566 00105$:
      00014B 90 FF 01         [24]  567 	mov	dptr,#_aes_reg_state
      00014E E0               [24]  568 	movx	a,@dptr
      00014F E0               [24]  569 	movx	a,@dptr
                                    570 ;	aes_test.c:70: for(i=0; i < 32; i++) {
      000150 70 F9            [24]  571 	jnz	00105$
      000152 FC               [12]  572 	mov	r4,a
      000153 FD               [12]  573 	mov	r5,a
      000154                        574 00123$:
                                    575 ;	aes_test.c:71: P0 = data[i];
      000154 8C 82            [24]  576 	mov	dpl,r4
      000156 74 E0            [12]  577 	mov	a,#(_data >> 8)
      000158 2D               [12]  578 	add	a,r5
      000159 F5 83            [12]  579 	mov	dph,a
      00015B E0               [24]  580 	movx	a,@dptr
      00015C F5 80            [12]  581 	mov	_P0,a
                                    582 ;	aes_test.c:70: for(i=0; i < 32; i++) {
      00015E 0C               [12]  583 	inc	r4
      00015F BC 00 01         [24]  584 	cjne	r4,#0x00,00191$
      000162 0D               [12]  585 	inc	r5
      000163                        586 00191$:
      000163 C3               [12]  587 	clr	c
      000164 EC               [12]  588 	mov	a,r4
      000165 94 20            [12]  589 	subb	a,#0x20
      000167 ED               [12]  590 	mov	a,r5
      000168 64 80            [12]  591 	xrl	a,#0x80
      00016A 94 80            [12]  592 	subb	a,#0x80
      00016C 40 E6            [24]  593 	jc	00123$
                                    594 ;	aes_test.c:75: aes_reg_start = 1;
      00016E 90 FF 00         [24]  595 	mov	dptr,#_aes_reg_start
      000171 74 01            [12]  596 	mov	a,#0x01
      000173 F0               [24]  597 	movx	@dptr,a
                                    598 ;	aes_test.c:76: while(aes_reg_state != 0)  {
      000174                        599 00109$:
      000174 90 FF 01         [24]  600 	mov	dptr,#_aes_reg_state
      000177 E0               [24]  601 	movx	a,@dptr
      000178 E0               [24]  602 	movx	a,@dptr
      000179 60 1A            [24]  603 	jz	00144$
                                    604 ;	aes_test.c:102: __endasm;
                                    605 ;
      00017B 00               [12]  606 	nop;
      00017C 00               [12]  607 	nop;
      00017D 00               [12]  608 	nop;
      00017E 00               [12]  609 	nop;
      00017F 00               [12]  610 	nop;
      000180 00               [12]  611 	nop;
      000181 00               [12]  612 	nop;
      000182 00               [12]  613 	nop;
      000183 00               [12]  614 	nop;
      000184 00               [12]  615 	nop;
      000185 00               [12]  616 	nop;
      000186 00               [12]  617 	nop;
      000187 00               [12]  618 	nop;
      000188 00               [12]  619 	nop;
      000189 00               [12]  620 	nop;
      00018A 00               [12]  621 	nop;
      00018B 00               [12]  622 	nop;
      00018C 00               [12]  623 	nop;
      00018D 00               [12]  624 	nop;
      00018E 00               [12]  625 	nop;
      00018F 00               [12]  626 	nop;
      000190 00               [12]  627 	nop;
      000191 00               [12]  628 	nop;
      000192 00               [12]  629 	nop;
                                    630 ;	aes_test.c:105: for(i=0; i < 32; i++) {
      000193 80 DF            [24]  631 	sjmp	00109$
      000195                        632 00144$:
      000195 7C 00            [12]  633 	mov	r4,#0x00
      000197 7D 00            [12]  634 	mov	r5,#0x00
      000199                        635 00125$:
                                    636 ;	aes_test.c:106: if(data[i] != i) {
      000199 8C 82            [24]  637 	mov	dpl,r4
      00019B 74 E0            [12]  638 	mov	a,#(_data >> 8)
      00019D 2D               [12]  639 	add	a,r5
      00019E F5 83            [12]  640 	mov	dph,a
      0001A0 E0               [24]  641 	movx	a,@dptr
      0001A1 FB               [12]  642 	mov	r3,a
      0001A2 7A 00            [12]  643 	mov	r2,#0x00
      0001A4 B5 04 06         [24]  644 	cjne	a,ar4,00194$
      0001A7 EA               [12]  645 	mov	a,r2
      0001A8 B5 05 02         [24]  646 	cjne	a,ar5,00194$
      0001AB 80 06            [24]  647 	sjmp	00126$
      0001AD                        648 00194$:
                                    649 ;	aes_test.c:107: good = 2;
      0001AD 7E 02            [12]  650 	mov	r6,#0x02
      0001AF 7F 00            [12]  651 	mov	r7,#0x00
                                    652 ;	aes_test.c:108: break;
      0001B1 80 10            [24]  653 	sjmp	00114$
      0001B3                        654 00126$:
                                    655 ;	aes_test.c:105: for(i=0; i < 32; i++) {
      0001B3 0C               [12]  656 	inc	r4
      0001B4 BC 00 01         [24]  657 	cjne	r4,#0x00,00195$
      0001B7 0D               [12]  658 	inc	r5
      0001B8                        659 00195$:
      0001B8 C3               [12]  660 	clr	c
      0001B9 EC               [12]  661 	mov	a,r4
      0001BA 94 20            [12]  662 	subb	a,#0x20
      0001BC ED               [12]  663 	mov	a,r5
      0001BD 64 80            [12]  664 	xrl	a,#0x80
      0001BF 94 80            [12]  665 	subb	a,#0x80
      0001C1 40 D6            [24]  666 	jc	00125$
      0001C3                        667 00114$:
                                    668 ;	aes_test.c:112: P0 = good;
      0001C3 8E 80            [24]  669 	mov	_P0,r6
                                    670 ;	aes_test.c:113: debug_reg_addr = GOOD_ID;
      0001C5 90 EF FE         [24]  671 	mov	dptr,#_debug_reg_addr
      0001C8 74 12            [12]  672 	mov	a,#0x12
      0001CA F0               [24]  673 	movx	@dptr,a
                                    674 ;	aes_test.c:114: debug_reg_data = good;
      0001CB 90 EF FF         [24]  675 	mov	dptr,#_debug_reg_data
      0001CE EE               [12]  676 	mov	a,r6
      0001CF F0               [24]  677 	movx	@dptr,a
                                    678 ;	aes_test.c:116: quit();
      0001D0 02 00 62         [24]  679 	ljmp	_quit
                                    680 	.area CSEG    (CODE)
                                    681 	.area CONST   (CODE)
                                    682 	.area XINIT   (CODE)
                                    683 	.area CABS    (ABS,CODE)
