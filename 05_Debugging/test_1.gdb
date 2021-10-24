set pagination off
set logging on

break 29 if i % 5 == 0
	command 1
	printf "@@@ Start = %d, end = %d, step = %d,  current member of progression = %d\n", n, m, s, i
	continue
end

run 1 12 > /dev/null

set logging off
quit
