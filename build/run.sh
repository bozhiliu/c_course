./tempfilter ../testfiles/testfile1.txt out1.txt
./tempfilter ../testfiles/testfile2.txt out2.txt
./tempfilter ../testfiles/testfile3.txt out3.txt
./tempfilter ../testfiles/testfile4.txt out4.txt
./tempfilter ../testfiles/testfile5.txt out5.txt
./tempfilter ../testfiles/testfile6.txt out6.txt
tar -cf out.tar out1.txt out2.txt out3.txt out4.txt out5.txt out6.txt