################################################################################
# Automatically-generated file. Do not edit!
################################################################################

C_FILES += "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.c"
OBJ_FILES += "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.o"
"SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.o" : "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.c" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerDcc.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerDcc.o.opt"

"SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerDcc.o.opt" : .refresh
	@argfile "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerDcc.o.opt" -o "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.o" "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -DNDEBUG -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -Wc--no-warnings=542 -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerDcc.o.d" -Wc--make-target="SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.o"
DEPENDENCY_FILES += "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerDcc.o.d"

C_FILES += "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.c"
OBJ_FILES += "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.o"
"SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.o" : "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.c" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerGnuc.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerGnuc.o.opt"

"SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerGnuc.o.opt" : .refresh
	@argfile "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerGnuc.o.opt" -o "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.o" "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -DNDEBUG -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -Wc--no-warnings=542 -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerGnuc.o.d" -Wc--make-target="SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.o"
DEPENDENCY_FILES += "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerGnuc.o.d"

C_FILES += "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.c"
OBJ_FILES += "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.o"
"SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.o" : "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.c" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerTasking.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerTasking.o.opt"

"SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerTasking.o.opt" : .refresh
	@argfile "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerTasking.o.opt" -o "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.o" "..\SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -DNDEBUG -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -Wc--no-warnings=542 -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerTasking.o.d" -Wc--make-target="SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.o"
DEPENDENCY_FILES += "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerTasking.o.d"


GENERATED_FILES += "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.o" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerDcc.o.opt" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerDcc.o.d" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.src" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerDcc.lst" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.o" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerGnuc.o.opt" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerGnuc.o.d" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.src" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerGnuc.lst" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.o" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerTasking.o.opt" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\.CompilerTasking.o.d" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.src" "SoftwarePlatform\illd_tc23x\src\ifx\SrvSw\Tricore\Compilers\CompilerTasking.lst"