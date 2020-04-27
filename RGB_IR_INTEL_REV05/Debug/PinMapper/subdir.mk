################################################################################
# Automatically-generated file. Do not edit!
################################################################################

C_FILES += "..\PinMapper\aurix_pin_mappings.c"
OBJ_FILES += "PinMapper\aurix_pin_mappings.o"
"PinMapper\aurix_pin_mappings.o" : "..\PinMapper\aurix_pin_mappings.c" "PinMapper\.aurix_pin_mappings.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "PinMapper\.aurix_pin_mappings.o.opt"

"PinMapper\.aurix_pin_mappings.o.opt" : .refresh
	@argfile "PinMapper\.aurix_pin_mappings.o.opt" -o "PinMapper\aurix_pin_mappings.o" "..\PinMapper\aurix_pin_mappings.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="PinMapper\.aurix_pin_mappings.o.d" -Wc--make-target="PinMapper\aurix_pin_mappings.o"
DEPENDENCY_FILES += "PinMapper\.aurix_pin_mappings.o.d"


GENERATED_FILES += "PinMapper\aurix_pin_mappings.o" "PinMapper\.aurix_pin_mappings.o.opt" "PinMapper\.aurix_pin_mappings.o.d" "PinMapper\aurix_pin_mappings.src" "PinMapper\aurix_pin_mappings.lst"
