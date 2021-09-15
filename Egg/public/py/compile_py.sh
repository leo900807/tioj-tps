#!/bin/bash

problem=Egg

python3 -m compileall -b .
mv grader.pyc __main__.pyc
zip -r Egg.zip __main__.pyc Egg.pyc
mv Egg.zip Egg
rm __main__.pyc Egg.pyc
