#!/bin/bash

case $1 in
        "1")
		echo -e ""
                (set -x;./main test.txt -o testCompresse.txt -c)
		echo -e ""
		(set -x;./main testCompresse.txt -o testDecompresse.txt -d)
		echo -e "\n/////////////////////////////////////////////////////////"
		if diff test.txt testDecompresse.txt;
		then
    			echo -e "Compression/Decompression LZW effectuees avec succes"
		else
    			echo -e "Echec de la compression/decompression"

		fi
		echo -e "/////////////////////////////////////////////////////////\n"
                ;;
        "2")
                echo -e ""
                (set -x;./main test.txt -o testCompresse.txt -c)
                echo -e ""
                (set -x;./main testCompresse.txt -o testDecompresse.txt -d)
                echo -e "\n/////////////////////////////////////////////////////////"
                if diff test.txt testDecompresse.txt;
                then
                        echo -e "Compression/Decompression LZW effectuees avec succes"
                else
                        echo -e "Echec de la compression/decompression"

                fi
                echo -e "/////////////////////////////////////////////////////////\n"
                ;;

	"3")
                echo -e ""
                (set -x;./main test.txt -o testCompresse.txt -c)
                echo -e ""
                (set -x;./main testCompresse.txt -o testDecompresse.txt -d)
                echo -e "\n/////////////////////////////////////////////////////////"
                if diff test.txt testDecompresse.txt;
                then
                        echo -e "Compression/Decompression LZW effectuees avec succes"
                else
                        echo -e "Echec de la compression/decompression"

                fi
                echo -e "/////////////////////////////////////////////////////////\n"
                ;;

	"4")
                echo -e ""
                (set -x;./main test.txt -o testCompresse.txt -c)
                echo -e ""
                (set -x;./main testCompresse.txt -o testDecompresse.txt -d)
                echo -e "\n/////////////////////////////////////////////////////////"
                if diff test.txt testDecompresse.txt;
                then
                        echo -e "Compression/Decompression LZW effectuees avec succes"
                else
                        echo -e "Echec de la compression/decompression"

                fi
                echo -e "/////////////////////////////////////////////////////////\n"
                ;;

esac

exit 0;
