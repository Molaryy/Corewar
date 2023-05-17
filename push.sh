#!/bin/bash

# ARGS : [NAME_OF_FILE] [COMMENT BETWEEN BRACKETS] [COMMIT MESSAGE]

if [ $# -ne 3 ]; then

  echo "Usage: $0 [NAME_OF_FILE] [COMMENT BETWEEN BRACKETS] [COMMIT MESSAGE]"
  exit 1
fi
clear
echo -e "\e[32m[ADDING FILE...]\e[0m"
git add $1
echo -e "\n\n\e[32m[COMMITTING...]\e[0m"
git commit -m "$2: $3 -> ($1)-"
clear
git status