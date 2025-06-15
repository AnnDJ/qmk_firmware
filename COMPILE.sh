if [[ $# -eq 0 ]]
then
    echo "Use 'L' for left, 'R' for right or 'LR' for both"
	exit 1
fi

STARTTIME=$(date +%s)

if [[ $1 =~ ^L(R)?$ ]]
then

	echo -e "STARTING FIRST HALF\n"

	qmk compile -kb splitkb/halcyon/elora/rev2 -km custom -e HLC_ENCODER=1
	
	if [[ $? -ne 0 ]]
	then
		echo -e "\n\n   \e[101m   ERROR DURING COMPILING   \e[0m\n\n"
		exit 1
	fi

	echo -e "\nFirst half compiled"

	mv splitkb_halcyon_elora_rev2_custom.uf2 splitkb_halcyon_elora_rev2_custom_encoder.uf2

	echo -e "First half moved\n"

fi

if [[ $1 =~ ^(L)?R$ ]]
then

	echo -e "STARTING SECOND HALF\n"

	qmk compile -kb splitkb/halcyon/elora/rev2 -km custom -e HLC_CIRQUE_TRACKPAD=1

	if [[ $? -ne 0 ]]
	then
		echo -e "\n\n   \e[101m   ERROR DURING COMPILING   \e[0m\n\n"
		exit 1
	fi

	echo -e "\nSecond half compiled"

	mv splitkb_halcyon_elora_rev2_custom.uf2 splitkb_halcyon_elora_rev2_custom_trackpad.uf2

	echo "Second half moved\n"

fi

ENDTIME=$(date +%s)

echo -e "Time taken: $((($ENDTIME - $STARTTIME)/60))min"

# https://misc.flogisoft.com/bash/tip_colors_and_formatting
echo -e "\n\n   \e[42m   SUCCESSFULLY FINISHED   \e[0m\n\n"
