################################################################################
# Automatically-generated file. Do not edit!
################################################################################

C_FILES += "..\APP\src\AIS328DQ_REG.c"
OBJ_FILES += "APP\src\AIS328DQ_REG.o"
"APP\src\AIS328DQ_REG.o" : "..\APP\src\AIS328DQ_REG.c" "APP\src\.AIS328DQ_REG.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.AIS328DQ_REG.o.opt"

"APP\src\.AIS328DQ_REG.o.opt" : .refresh
	@argfile "APP\src\.AIS328DQ_REG.o.opt" -o "APP\src\AIS328DQ_REG.o" "..\APP\src\AIS328DQ_REG.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.AIS328DQ_REG.o.d" -Wc--make-target="APP\src\AIS328DQ_REG.o"
DEPENDENCY_FILES += "APP\src\.AIS328DQ_REG.o.d"

C_FILES += "..\APP\src\AsclinLinDemo.c"
OBJ_FILES += "APP\src\AsclinLinDemo.o"
"APP\src\AsclinLinDemo.o" : "..\APP\src\AsclinLinDemo.c" "APP\src\.AsclinLinDemo.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.AsclinLinDemo.o.opt"

"APP\src\.AsclinLinDemo.o.opt" : .refresh
	@argfile "APP\src\.AsclinLinDemo.o.opt" -o "APP\src\AsclinLinDemo.o" "..\APP\src\AsclinLinDemo.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.AsclinLinDemo.o.d" -Wc--make-target="APP\src\AsclinLinDemo.o"
DEPENDENCY_FILES += "APP\src\.AsclinLinDemo.o.d"

C_FILES += "..\APP\src\Ccan.c"
OBJ_FILES += "APP\src\Ccan.o"
"APP\src\Ccan.o" : "..\APP\src\Ccan.c" "APP\src\.Ccan.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.Ccan.o.opt"

"APP\src\.Ccan.o.opt" : .refresh
	@argfile "APP\src\.Ccan.o.opt" -o "APP\src\Ccan.o" "..\APP\src\Ccan.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.Ccan.o.d" -Wc--make-target="APP\src\Ccan.o"
DEPENDENCY_FILES += "APP\src\.Ccan.o.d"

C_FILES += "..\APP\src\FlashDemo.c"
OBJ_FILES += "APP\src\FlashDemo.o"
"APP\src\FlashDemo.o" : "..\APP\src\FlashDemo.c" "APP\src\.FlashDemo.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.FlashDemo.o.opt"

"APP\src\.FlashDemo.o.opt" : .refresh
	@argfile "APP\src\.FlashDemo.o.opt" -o "APP\src\FlashDemo.o" "..\APP\src\FlashDemo.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.FlashDemo.o.d" -Wc--make-target="APP\src\FlashDemo.o"
DEPENDENCY_FILES += "APP\src\.FlashDemo.o.d"

C_FILES += "..\APP\src\G_Sensor.c"
OBJ_FILES += "APP\src\G_Sensor.o"
"APP\src\G_Sensor.o" : "..\APP\src\G_Sensor.c" "APP\src\.G_Sensor.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.G_Sensor.o.opt"

"APP\src\.G_Sensor.o.opt" : .refresh
	@argfile "APP\src\.G_Sensor.o.opt" -o "APP\src\G_Sensor.o" "..\APP\src\G_Sensor.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.G_Sensor.o.d" -Wc--make-target="APP\src\G_Sensor.o"
DEPENDENCY_FILES += "APP\src\.G_Sensor.o.d"

C_FILES += "..\APP\src\Gtm.c"
OBJ_FILES += "APP\src\Gtm.o"
"APP\src\Gtm.o" : "..\APP\src\Gtm.c" "APP\src\.Gtm.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.Gtm.o.opt"

"APP\src\.Gtm.o.opt" : .refresh
	@argfile "APP\src\.Gtm.o.opt" -o "APP\src\Gtm.o" "..\APP\src\Gtm.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.Gtm.o.d" -Wc--make-target="APP\src\Gtm.o"
DEPENDENCY_FILES += "APP\src\.Gtm.o.d"

C_FILES += "..\APP\src\Init.c"
OBJ_FILES += "APP\src\Init.o"
"APP\src\Init.o" : "..\APP\src\Init.c" "APP\src\.Init.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.Init.o.opt"

"APP\src\.Init.o.opt" : .refresh
	@argfile "APP\src\.Init.o.opt" -o "APP\src\Init.o" "..\APP\src\Init.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.Init.o.d" -Wc--make-target="APP\src\Init.o"
DEPENDENCY_FILES += "APP\src\.Init.o.d"

C_FILES += "..\APP\src\Power_mode.c"
OBJ_FILES += "APP\src\Power_mode.o"
"APP\src\Power_mode.o" : "..\APP\src\Power_mode.c" "APP\src\.Power_mode.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.Power_mode.o.opt"

"APP\src\.Power_mode.o.opt" : .refresh
	@argfile "APP\src\.Power_mode.o.opt" -o "APP\src\Power_mode.o" "..\APP\src\Power_mode.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.Power_mode.o.d" -Wc--make-target="APP\src\Power_mode.o"
DEPENDENCY_FILES += "APP\src\.Power_mode.o.d"

C_FILES += "..\APP\src\Qspi_Dma.c"
OBJ_FILES += "APP\src\Qspi_Dma.o"
"APP\src\Qspi_Dma.o" : "..\APP\src\Qspi_Dma.c" "APP\src\.Qspi_Dma.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.Qspi_Dma.o.opt"

"APP\src\.Qspi_Dma.o.opt" : .refresh
	@argfile "APP\src\.Qspi_Dma.o.opt" -o "APP\src\Qspi_Dma.o" "..\APP\src\Qspi_Dma.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.Qspi_Dma.o.d" -Wc--make-target="APP\src\Qspi_Dma.o"
DEPENDENCY_FILES += "APP\src\.Qspi_Dma.o.d"

C_FILES += "..\APP\src\QspiCpuDemo.c"
OBJ_FILES += "APP\src\QspiCpuDemo.o"
"APP\src\QspiCpuDemo.o" : "..\APP\src\QspiCpuDemo.c" "APP\src\.QspiCpuDemo.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.QspiCpuDemo.o.opt"

"APP\src\.QspiCpuDemo.o.opt" : .refresh
	@argfile "APP\src\.QspiCpuDemo.o.opt" -o "APP\src\QspiCpuDemo.o" "..\APP\src\QspiCpuDemo.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.QspiCpuDemo.o.d" -Wc--make-target="APP\src\QspiCpuDemo.o"
DEPENDENCY_FILES += "APP\src\.QspiCpuDemo.o.d"

C_FILES += "..\APP\src\sched.c"
OBJ_FILES += "APP\src\sched.o"
"APP\src\sched.o" : "..\APP\src\sched.c" "APP\src\.sched.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.sched.o.opt"

"APP\src\.sched.o.opt" : .refresh
	@argfile "APP\src\.sched.o.opt" -o "APP\src\sched.o" "..\APP\src\sched.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.sched.o.d" -Wc--make-target="APP\src\sched.o"
DEPENDENCY_FILES += "APP\src\.sched.o.d"

C_FILES += "..\APP\src\ScuCcu.c"
OBJ_FILES += "APP\src\ScuCcu.o"
"APP\src\ScuCcu.o" : "..\APP\src\ScuCcu.c" "APP\src\.ScuCcu.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.ScuCcu.o.opt"

"APP\src\.ScuCcu.o.opt" : .refresh
	@argfile "APP\src\.ScuCcu.o.opt" -o "APP\src\ScuCcu.o" "..\APP\src\ScuCcu.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.ScuCcu.o.d" -Wc--make-target="APP\src\ScuCcu.o"
DEPENDENCY_FILES += "APP\src\.ScuCcu.o.d"

C_FILES += "..\APP\src\ScuEru.c"
OBJ_FILES += "APP\src\ScuEru.o"
"APP\src\ScuEru.o" : "..\APP\src\ScuEru.c" "APP\src\.ScuEru.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.ScuEru.o.opt"

"APP\src\.ScuEru.o.opt" : .refresh
	@argfile "APP\src\.ScuEru.o.opt" -o "APP\src\ScuEru.o" "..\APP\src\ScuEru.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.ScuEru.o.d" -Wc--make-target="APP\src\ScuEru.o"
DEPENDENCY_FILES += "APP\src\.ScuEru.o.d"

C_FILES += "..\APP\src\Spisoc.c"
OBJ_FILES += "APP\src\Spisoc.o"
"APP\src\Spisoc.o" : "..\APP\src\Spisoc.c" "APP\src\.Spisoc.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.Spisoc.o.opt"

"APP\src\.Spisoc.o.opt" : .refresh
	@argfile "APP\src\.Spisoc.o.opt" -o "APP\src\Spisoc.o" "..\APP\src\Spisoc.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.Spisoc.o.d" -Wc--make-target="APP\src\Spisoc.o"
DEPENDENCY_FILES += "APP\src\.Spisoc.o.d"

C_FILES += "..\APP\src\Sub_Bat_Ctl.c"
OBJ_FILES += "APP\src\Sub_Bat_Ctl.o"
"APP\src\Sub_Bat_Ctl.o" : "..\APP\src\Sub_Bat_Ctl.c" "APP\src\.Sub_Bat_Ctl.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.Sub_Bat_Ctl.o.opt"

"APP\src\.Sub_Bat_Ctl.o.opt" : .refresh
	@argfile "APP\src\.Sub_Bat_Ctl.o.opt" -o "APP\src\Sub_Bat_Ctl.o" "..\APP\src\Sub_Bat_Ctl.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.Sub_Bat_Ctl.o.d" -Wc--make-target="APP\src\Sub_Bat_Ctl.o"
DEPENDENCY_FILES += "APP\src\.Sub_Bat_Ctl.o.d"

C_FILES += "..\APP\src\util.c"
OBJ_FILES += "APP\src\util.o"
"APP\src\util.o" : "..\APP\src\util.c" "APP\src\.util.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.util.o.opt"

"APP\src\.util.o.opt" : .refresh
	@argfile "APP\src\.util.o.opt" -o "APP\src\util.o" "..\APP\src\util.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.util.o.d" -Wc--make-target="APP\src\util.o"
DEPENDENCY_FILES += "APP\src\.util.o.d"

C_FILES += "..\APP\src\Vadc.c"
OBJ_FILES += "APP\src\Vadc.o"
"APP\src\Vadc.o" : "..\APP\src\Vadc.c" "APP\src\.Vadc.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "APP\src\.Vadc.o.opt"

"APP\src\.Vadc.o.opt" : .refresh
	@argfile "APP\src\.Vadc.o.opt" -o "APP\src\Vadc.o" "..\APP\src\Vadc.c" -Ctc23x --lsl-core=vtc -t -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05" -Wa-H"sfr/regtc23x.def" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05\APP\inc" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=4 --compact-max-size=200 -g --error-limit=42 --source -D__SWPLATFORM__ -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Configuration" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Scu/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/Stm/Std/InitApi" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/TC23x/_Reg" -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_tc23x/src/ifx/SrvSw" -DIFX_CFG_USE_COMPILER_DEFAULT_LINKER -I"D:\00.Tasking_workspace\DVRS_INTEL\RGB_IR_INTEL_REV05/SoftwarePlatform/illd_common/ifx_cfg/include" -c --dep-file="APP\src\.Vadc.o.d" -Wc--make-target="APP\src\Vadc.o"
DEPENDENCY_FILES += "APP\src\.Vadc.o.d"


GENERATED_FILES += "APP\src\AIS328DQ_REG.o" "APP\src\.AIS328DQ_REG.o.opt" "APP\src\.AIS328DQ_REG.o.d" "APP\src\AIS328DQ_REG.src" "APP\src\AIS328DQ_REG.lst" "APP\src\AsclinLinDemo.o" "APP\src\.AsclinLinDemo.o.opt" "APP\src\.AsclinLinDemo.o.d" "APP\src\AsclinLinDemo.src" "APP\src\AsclinLinDemo.lst" "APP\src\Ccan.o" "APP\src\.Ccan.o.opt" "APP\src\.Ccan.o.d" "APP\src\Ccan.src" "APP\src\Ccan.lst" "APP\src\FlashDemo.o" "APP\src\.FlashDemo.o.opt" "APP\src\.FlashDemo.o.d" "APP\src\FlashDemo.src" "APP\src\FlashDemo.lst" "APP\src\G_Sensor.o" "APP\src\.G_Sensor.o.opt" "APP\src\.G_Sensor.o.d" "APP\src\G_Sensor.src" "APP\src\G_Sensor.lst" "APP\src\Gtm.o" "APP\src\.Gtm.o.opt" "APP\src\.Gtm.o.d" "APP\src\Gtm.src" "APP\src\Gtm.lst" "APP\src\Init.o" "APP\src\.Init.o.opt" "APP\src\.Init.o.d" "APP\src\Init.src" "APP\src\Init.lst" "APP\src\Power_mode.o" "APP\src\.Power_mode.o.opt" "APP\src\.Power_mode.o.d" "APP\src\Power_mode.src" "APP\src\Power_mode.lst" "APP\src\Qspi_Dma.o" "APP\src\.Qspi_Dma.o.opt" "APP\src\.Qspi_Dma.o.d" "APP\src\Qspi_Dma.src" "APP\src\Qspi_Dma.lst" "APP\src\QspiCpuDemo.o" "APP\src\.QspiCpuDemo.o.opt" "APP\src\.QspiCpuDemo.o.d" "APP\src\QspiCpuDemo.src" "APP\src\QspiCpuDemo.lst" "APP\src\sched.o" "APP\src\.sched.o.opt" "APP\src\.sched.o.d" "APP\src\sched.src" "APP\src\sched.lst" "APP\src\ScuCcu.o" "APP\src\.ScuCcu.o.opt" "APP\src\.ScuCcu.o.d" "APP\src\ScuCcu.src" "APP\src\ScuCcu.lst" "APP\src\ScuEru.o" "APP\src\.ScuEru.o.opt" "APP\src\.ScuEru.o.d" "APP\src\ScuEru.src" "APP\src\ScuEru.lst" "APP\src\Spisoc.o" "APP\src\.Spisoc.o.opt" "APP\src\.Spisoc.o.d" "APP\src\Spisoc.src" "APP\src\Spisoc.lst" "APP\src\Sub_Bat_Ctl.o" "APP\src\.Sub_Bat_Ctl.o.opt" "APP\src\.Sub_Bat_Ctl.o.d" "APP\src\Sub_Bat_Ctl.src" "APP\src\Sub_Bat_Ctl.lst" "APP\src\util.o" "APP\src\.util.o.opt" "APP\src\.util.o.d" "APP\src\util.src" "APP\src\util.lst" "APP\src\Vadc.o" "APP\src\.Vadc.o.opt" "APP\src\.Vadc.o.d" "APP\src\Vadc.src" "APP\src\Vadc.lst"
