SYSEXIT = 1
EXIT_SUCCESS = 0
# fpu - 8 rejestrow danych fpu
#st0-st7
#80 bit kazdy
#info float
.data
ujemna: .float -3.89898
zeros: .float 0.0
jedynka: .float 1.0

.text
.global _start
_start:

#initalize fpu
finit

#dodatnia przez 0 -> INF
fld jedynka
fdiv zeros #analogicznie

#jeden/INF->zero
fld jedynka
fdiv %st(1), %st(0) 

#ujemna przez zero -> -inf
fld ujemna
fdiv zeros

#jeden/-INF - > -0
fld jedynka
fdiv %st(1), %st(0)

#dzielenie 0 przez 0 ->NAN
fld zeros #laduje wartosc na stos
fdiv zeros #dzielenie st0 przez 0

brt2:
mov $SYSEXIT, %eax
mov $EXIT_SUCCESS, %ebx
int $0x80
