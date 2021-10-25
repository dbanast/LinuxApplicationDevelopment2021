set pagination off
set logging on

break 30 if i >= m + 27 * s && i <= m + 34 * s
	command 1
	printf "@@@ Start = %d, end = %d, step = %d,  current member of progression = %d\n", m, n, s, i
	continue
end

run -100 100 3 > /dev/null

set logging off
quit
