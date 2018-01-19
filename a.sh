#/bin/bash
./a.out
declare -i size_o size_o rate
printf "original file size(kb) \t current file size(kb) \t rate\n"
for filename in 10.txt 20.txt 30.txt 40.txt 50.txt 60.txt 70.txt 80.txt 90.txt
do
  size_o=$(stat --format=%s $filename)
  xz -z $filename
  size_n=$(stat --format=%s ${filename}.xz)
  rate=$[size_o/size_n]
  printf "$size_o \t $size_n \t $rate\n"
done
rm ./*.txt.xz
