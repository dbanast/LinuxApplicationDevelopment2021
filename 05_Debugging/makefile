range: range.c
	gcc -O0 -g range.c -o range

test: range
	gdb --command=test_1.gdb ./range  | grep @@@ | sed s/[^0-9,',','-']//g > temp_res1.txt
	cmp temp_res1.txt answer_test_1.txt
	
	gdb --command=test_2.gdb ./range  | grep @@@ | sed s/[^0-9,',','-']//g > temp_res2.txt
	cmp temp_res2.txt answer_test_2.txt

clean:
	rm range temp_res1.txt temp_res2.txt gdb.txt
	
