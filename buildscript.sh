#!/bin/bash

# Dhruv Chokshi, McMaster University, 2024
# A simple script to add all changes, tag the commit, and commit with a message.

if [[ "$1" = "" ]]
then
	echo "Add commit message"
fi
if [[ "$2" = "" ]]
then
	echo "Add the tag"
fi

git add .
git commit -m "$1"
git tag "$2"
git push
git push --tags

echo "Success, changes have been added, committed and tagged!"

