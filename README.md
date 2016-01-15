# exercises
Exercises.

Instructions for pulling and compiling, with exercise1 as an example:
- clone the repo
- open exercise1.qpf in quartus
- add exercise1.vhd to the project in quartus
- open nios_system.qsys in qsys
- generate in qsys
- add nios_system/synthesis/nios_system.qip to the project in quartus
- change the device from cyclone iv to the right cyclone ii version
- import pin assignments
- set exercise1 as top-level entity
- compile in quartus
- program your DE2 with the sof file
- import both software/exercise1 and software/exercise1_bsp in eclipse-nios2
- generate BSP with exercise1_bsp
- run exercise1 on nios II hardware