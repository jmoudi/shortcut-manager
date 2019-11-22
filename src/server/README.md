
SHIFT_L

rg '#define VC_([\w+]\s*([0-9\w]+))' '../../lib/uiohook.h'
rg '#define VC_([\w+]\s*(0?[xX][0-9a-fA-F]+))' '../../lib/uiohook.h'
rg '#define VC_([\w+]\s*((?:0[xX]){0,3}[0-9a-fA-F]+))' '../../lib/uiohook.h'


yarn run 

(?:0[xX])?[0-9a-fA-F]+