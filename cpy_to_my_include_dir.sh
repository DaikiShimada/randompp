#/bin/sh

incdir="/usr/local/include/randompp"

if [ ! -e ${incdir} ]; then
	sudo mkdir ${incdir}
fi

sudo cp ./*.{h,hpp} ${incdir}
