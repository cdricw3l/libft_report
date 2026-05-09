#!/bin/bash


for i in {190010..1000000}; do
    NAME=${i}_subject.pdf
    wget -O $NAME  https://cdn.intra.42.fr/pdf/pdf/${i}/en.subject.pdf 2> /dev/null
    if [ $? != 0 ]; then
        echo error remove file ${NAME}
        rm -f ${NAME}
    fi
done
