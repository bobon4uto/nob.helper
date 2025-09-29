#!/bin/bash

NOB_TEMPLATE_DIR="/usr/local/share/nobh"
init=false
project_folder="$(pwd)"

usage() {
    echo "Usage: $0 init_dir [-i]"
    echo "Options:"
		echo "  init_dir          specify directory for new project (default: current)"
    echo "  -i                initialize"
    echo "  Anything else     Display this help message"
    exit 1
}


while [[ "$#" -gt 0 ]]; do
    case $1 in
        -i) init=true ;;
				-*) usage ;;
        *)
					  if [[ -z "$input_file" ]]; then
                init=true
								project_folder="$1"  
            fi
            ;;
    esac
    shift 
done

initialize() {
working_dir=$1
mkdir -p "$working_dir"
cd "$working_dir"
cp "$NOB_TEMPLATE_DIR/nob.c" ./
cp "$NOB_TEMPLATE_DIR/nob.h" ./
cc nob.c -o nob && ./nob
}

if $init; then
	initialize "$project_folder"
else
	usage
fi
