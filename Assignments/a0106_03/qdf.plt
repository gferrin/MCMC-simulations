set noyzeroaxis
set yrange [0:0.525]
plot "qdf01.d" using 1:3 with line lt 1,\
	 "qdf02.d" using 1:3 with line lt 2,\
	 "qdf03.d" using 1:3 with line lt 3,\
	 "qdf04.d" using 1:3 with line lt 4
pause -1
