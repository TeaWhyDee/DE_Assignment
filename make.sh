#!/usr/bin/bash

qmake -project;
echo "
QT += widgets
QT += charts " >> DE_CP1.pro
qmake; make; ./DE_CP1
