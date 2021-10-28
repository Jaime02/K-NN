start_time=$(date +%s)

echo 'Input number of data you want to convert:'
read line

for ((n = 0; n < 1000; n++)); do
  if (($n % 10 == 0)); then
    echo $(($n / 10))%
  fi
  ./magick -size 28x28 -depth 8 gray:img/bin/0-${n}.bin img/png/0-${n}.png
done

end_time=$(date +%s)
elapsed=$((end_time - start_time))
echo Elapsed: $elapsed seconds
