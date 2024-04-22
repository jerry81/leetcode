#!/bin/bash

# Get the starting number from user input
read -p "Enter the starting number: " start_number # input

# Loop to create 25 folders
for ((i=$start_number; i<=$((start_number+24)); i++)) # bash loop, very similar to hlpl
do # remeniscent of ruby
    folder_name="$i" # no need for declaration
    mkdir "$folder_name" # actual bash
    echo "Created folder: $folder_name"
done