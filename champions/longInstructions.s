.name "Sweepy v2"
.comment "Lightning speed sweep sweep sweep"

sti r1, %:cpy, %1
st  r2, -7

fork %:cpy
st r2, -2

p1:
    live %4222
    ld %262144, r2
    ld %190055429, r3
    ld %190056197, r4
    ld %507, r5
    fork %:p2
    ld %190056453, r7
    ld %134443010, r8
    ld %0, r6
    zjmp %:trampoline

p2:
    ld %134443010, r2
    ld %101253622, r3
    ld %101253622, r4
    ld %101253622, r7
    ld %262144, r8
    ld %4, r6
    ld %0, r12

trampoline:
    live %1
    sti r3, %383, r6
    zjmp %377

fill:
	lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0
    lfork %0


cpycode:
setup:
	live %1337
    add r4, r4, r4
	# Possible offsets: 32/64/128/256/512
    # (%X = X/4 processes)
    xor r4, %128, r7
    zjmp %:start
    fork %:child
    live %251658255 # trap: 0F 00 00 0F
    ld %0, r12		# zf
    zjmp %:setup

child:
    add r3, r4, r3
    ld %0, r12		# zf
    zjmp %:setup

start:
    st r1, 12
    ldi %0, r3, r14

code:
    live %1
    sti r14, %-511, r3
    zjmp %-511

cpy:
	live %1

ld -84, r2
ld -85, r3
ld -86, r4
ld -87, r5
ld -88, r6
ld -89, r7
ld -90, r8
ld -91, r9
ld -92, r10
ld -93, r11
ld -94, r12
ld -95, r13
ld -96, r14
ld -97, r15
ld -98, r16

st r2, 511
st r3, 510
st r4, 509
st r5, 508
st r6, 507
st r7, 506
st r8, 505
st r9, 504
st r10, 503
st r11, 502
st r12, 501
st r13, 500
st r14, 499
st r15, 498
st r16, 497

ld -174, r2
ld -175, r3
ld -176, r4
ld -177, r5
ld -178, r6

st r2, 471
st r3, 470
st r4, 469
st r5, 468
st r6, 467

ld %2, r4
ld %0, r3
st r1, 373
st r3, -5
zjmp %3
zjmp %3
zjmp %3
zjmp %353
