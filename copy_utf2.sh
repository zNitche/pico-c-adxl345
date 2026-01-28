#!/bin/bash

source_path=$1
target_path=$2

echo "source: $source_path"
echo "target: $target_path"

copied=false

if [ ! -n "$source_path" ] || [ ! -n "$target_path" ]; then
    echo "source_path or/and target_path is undefined"
    exit 1
fi

while true
do
    if [ -d $target_path ] && [ $copied == false ]; then
        echo "copying $source_path to $target_path..."

        cp $source_path $target_path
        echo "done."

        copied=true
    else
        copied=false
    fi

    sleep 2
done
