n=1;
while read line ;
do
    if [  $n -eq 10  ]; then
        echo "$line"
    fi
    n=$((n+1));
done < file.txt