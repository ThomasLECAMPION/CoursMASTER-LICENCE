#!/bin/sh
bindir=$(pwd)
cd /home/ectomic/Bureau/Codage_Compression/TP_BIANCA/TP1_code/TP1/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/ectomic/Bureau/Codage_Compression/TP_BIANCA/TP1_code/build/TP1 
	else
		"/home/ectomic/Bureau/Codage_Compression/TP_BIANCA/TP1_code/build/TP1"  
	fi
else
	"/home/ectomic/Bureau/Codage_Compression/TP_BIANCA/TP1_code/build/TP1"  
fi
